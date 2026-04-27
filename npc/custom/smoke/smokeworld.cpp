// Warps Custom - Smoke World
prontera,144,153,0	warp	costumeShop	1,1,06guild_02,50,50
06guild_02,50,44,5	script	Auxiliar Atemporal	10307,{
	warp "prontera"	,156,191;
	end;
}
// Mobs Custom - vip_lounge (Área GM)
vip_lounge,160,121,6	script	Remover Buffs	405,{
	sc_end SC_ALL;
	end;
}
// Comando @removebuffs
-	script	removeBuffs	-1,{

	OnInit:
		bindatcmd "removebuffs",strnpcinfo(0) + "::OnAtcommand";
		end;

	OnAtcommand:
		message strcharinfo(0),"Buffs removidos com sucesso!";
		sc_end SC_ALL;
		end;
}
// Exemplo de NPC para checar
/*-	script	CheckSmoke	-1,{
    OnInit:
        bindatcmd "checksmoke",strnpcinfo(0)+"::OnAtcommand";
        end;
		
	// OnPCLoginEvent:
	// set SmokeGearProg,666;
	// dispbottom "Forçado para "+SmokeGearProg+" no login";
	// end;
	
    OnAtcommand:
        dispbottom "[Smoke Status]";
        dispbottom "Seu Smoke Gear Prog: " + SmokeGearProg;
        if (SmokeGearProg == 1) dispbottom "Set: Godlike";
        else if (SmokeGearProg == 2) dispbottom "Set: Phoenix";
		else if (SmokeGearProg == 3) dispbottom "Set: Azur";
		else if (SmokeGearProg == 4) dispbottom "Set: Ascension";
		else if (SmokeGearProg == 0) dispbottom "Valor não setado!";
		else dispbottom "Algo de errado? Valor acima de 4, talvez...";
		end;
}*/

// Comando para checar combos (feito por Emundus la na filha da puta da source)
-	script	combosAtivos	-1,{
	OnInit:
		bindatcmd "combos",strnpcinfo(0)+"::OnAtcommand";
		end;
		
	OnAtcommand:
		.@total = getcombos();
		
		if (.@total > 0) {
			dispbottom "Você possui "+.@total+" combos ativos!";
			end;
		} else {
			dispbottom "Você não possui combos ativos!";
			end;
		}
}
// Comando para dropar item (GM apenas)
-	script	droparItem	-1,{
	OnInit:
		bindatcmd "dropar",strnpcinfo(0)+"::OnAtcommand",99,99;
		end;
		
	OnAtcommand:
		if (.@atcmd_numparameters < 1) {
		message strcharinfo(0),"Uso: @dropar <itemid> <quantidade>";
		end;
		}
		
		.@itemid = atoi(.@atcmd_parameters$[0]);

		if (.@atcmd_numparameters >= 2)
			.@amount = atoi(.@atcmd_parameters$[1]);
		else
			.@amount = 1;

		if (.@amount <= 0)
			.@amount = 1;

		// verifica se item existe
		if (getitemname(.@itemid) == "null") {
			message strcharinfo(0),"Item ID inválido.";
			end;
		}
		getmapxy(.@map$, .@x, .@y, BL_PC);

		makeitem .@itemid, .@amount, .@map$, .@x, .@y,true;

		message strcharinfo(0),"Você dropou "+.@amount+"x "+getitemname(.@itemid)+" no chão.";

		end;
}

// Painel de administração de Achievements (GM)
-	script	AchievementAdmin	-1,{

	OnInit:
		bindatcmd "achadmin",strnpcinfo(0)+"::OnAtcommand",99,99;
		end;

	OnAtcommand:

		mes "[Painel de Achievements]";
		mes "Escolha uma função:";
		next;

		switch(select(
		"Adicionar Achievement",
		"Remover Achievement",
		"Completar Achievement",
		"Verificar Achievement no Player",
		"Informações do Achievement",
		"Atualizar Progresso",
		"Consultar Achievement no DB")) {

		case 1: .@mode = 1; break;
		case 2: .@mode = 2; break;
		case 3: .@mode = 3; break;
		case 4: .@mode = 4; break;
		case 5: .@mode = 5; break;
		case 6: .@mode = 6; break;
		case 7: .@mode = 7; break;
		}

		mes "[Painel de Achievements]";
		mes "Informe o ID do Achievement:";
		next;

		input .@ach_id;

		// if (!achievementexists(.@ach_id)) {
			// mes "Achievement inexistente.";
			// close;
		// }
		
		.@test = achievementinfo(.@ach_id,ACHIEVEINFO_LEVEL);

		if (.@test == -1) {
			mes "Achievement não existe no banco.";
			close;
		}

		mes "[Painel]";
		mes "Digite o nome do jogador:";
		mes "(nomes com espaço são aceitos)";
		next;

		input .@name$;

		.@char_id = getcharid(0,.@name$);

		// se não estiver online, procura no banco
		if (.@char_id == 0) {
			query_sql "SELECT char_id FROM `char` WHERE name='"+escape_sql(.@name$)+"' LIMIT 1", .@char_id;
		}

		if (.@char_id == 0) {
			mes "Jogador não encontrado.";
			close;
		}

		query_sql "SELECT name FROM `char` WHERE char_id="+.@char_id+" LIMIT 1", .@confirm$;

		mes "Jogador encontrado: "+.@confirm$;

		switch(.@mode) {

		case 1:
			if (achievementadd(.@ach_id,.@char_id))
				mes "Achievement adicionado.";
			else
				mes "Falha ao adicionar.";
			break;

		case 2:
			if (achievementremove(.@ach_id,.@char_id))
				mes "Achievement removido.";
			else
				mes "Falha ao remover.";
			break;

		case 3:
			if (achievementcomplete(.@ach_id,.@char_id))
				mes "Achievement completado.";
			else
				mes "Falha ao completar.";
			break;

		case 4:
			if (achievementexists(.@ach_id,.@char_id))
				mes "O jogador possui este achievement.";
			else
				mes "O jogador não possui este achievement.";
			break;

		case 5:
			.@complete = achievementinfo(.@ach_id,ACHIEVEINFO_COMPLETE,.@char_id);
			.@reward = achievementinfo(.@ach_id,ACHIEVEINFO_GOTREWARD,.@char_id);

			mes "Completo: "+.@complete;
			mes "Recompensa recebida: "+.@reward;
			break;

		case 6:
			mes "Escolha o tipo de progresso:";
			next;

			switch(select(
			"COUNT1","COUNT2","COUNT3","COUNT4","COUNT5")) {

			case 1: .@type = ACHIEVEINFO_COUNT1; break;
			case 2: .@type = ACHIEVEINFO_COUNT2; break;
			case 3: .@type = ACHIEVEINFO_COUNT3; break;
			case 4: .@type = ACHIEVEINFO_COUNT4; break;
			case 5: .@type = ACHIEVEINFO_COUNT5; break;
			}

			mes "Valor:";
			next;

			input .@value;

			if (achievementupdate(.@ach_id,.@type,.@value,.@char_id))
				mes "Progresso atualizado.";
			else
				mes "Falha ao atualizar.";
			break;
		case 7:
			.@check = achievementinfo(.@ach_id,ACHIEVEINFO_LEVEL);

			if (.@check == -1) {
				mes "[Painel]";
				mes "Achievement "+.@ach_id+" NÃO existe no DB.";
			} else {
				mes "[Painel]";
				mes "Achievement "+.@ach_id+" existe no DB.";
				mes "Nível do Achievement: "+.@check;
			}

			break;
		}

		close;
}