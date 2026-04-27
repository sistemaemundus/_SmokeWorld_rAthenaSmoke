// Criado por Alek Emundus
// Torre das Ilusões - Instanciada
//============================================================
/*prontera,167,176,4	script	Anfitrião Smoke	405,{
	.@instance$ = "Arena Smoke";

	if (instance_live_info(ILI_NAME, instance_id(IM_PARTY)) == .@instance$) {
		mes "[Anfitrião Smoke]";
		mes "Você já faz parte de uma instância!";
		next;
		switch(select("Entrar.:Cancelar.:Fechar instância.")) {
		case 1:
			break;
		case 2:
			mes "[Anfitrião Smoke]";
			mes "Não quer tentar novamente?";
			emotion ET_CRY;
			close;
		case 3:
			clear;
			mes "[Anfitrião Smoke]";
			mes "Deseja mesmo fechar a instância?";
			switch(select("Sim.:Não.")){
				case 1:
					instance_destroy instance_id(IM_PARTY);
					clear;
					mes "[Anfitrião Smoke]";
					mes "Instância fechada!";
					close;
				case 2:
					clear;
					mes "[Anfitrião Smoke]";
					mes "Ok, até mais!";
					close;
			}
		}
	}
	else if (instance_id(IM_PARTY)) {	// another instance is running
		mes "[Anfitrião Smoke]";
		mes "Você já faz parte de uma instância " + instance_live_info(ILI_NAME, instance_id(IM_PARTY)) + ".";
		close;
	}
	else {
		mes "[Anfitrião Smoke]";
		mes "Gostaria de entrar em Arena Smoke?";
		next;
		switch(select("Sim.:Informações.:Cancelar.")) {
		case 1:
			.@create = instance_create(.@instance$);
			if (.@create < 0) {
				mes "[Anfitrião Smoke]";
				switch (.@create) {
					case -1: mes "ERROR: Tipo inválido."; break;
					case -2: mes "ERROR: Grupo não encontrado."; break;
					case -3: mes "ERROR: Instância já existe."; break;
					case -4: mes "ERROR: Sem instâncias livres."; break;
				}
				mes " ";
				mes "Criação da instância ^FF0000falhou^000000.";
				emotion ET_HUK;
				close;
			}
			mes "[Anfitrião Smoke]";
			mes "Instância criada.";
			mes " ";
			mes "Vou lhe enviar para lá...";
			next;
			break;
		case 2:
			mes "[Anfitrião Smoke]";
			mes "A Arena Smoke foi tomado por forças incontroláveis.";
			mes "A fumaça encobre um poder que não deveria existir.";
			mes "O verdadeiro desafio o aguarda no final!";
			close;
		case 3:
			mes "[Anfitrião Smoke]";
			mes "Ok, talvez da próxima!";
			close;
		}
	}
	.@enter = instance_enter(.@instance$);
	if (.@enter != 0) {
		mes "[Anfitrião Smoke]";
		switch (.@enter) {
			case 1: mes "ERROR: Grupo não encontrado."; break;
			case 2: mes "ERROR: Grupo não possui uma instância."; break;
			case 3: mes "ERROR: Erro desconhecido.."; break;
		}
		mes " ";
		mes "^FF0000Falha^000000 ao entrar na instância.";
		emotion ET_HUK;
		close;
	}
	close;
}

// Instance Scripts
//============================================================
pvp_arena,49,51,6	script	Anfitrião Smoke#start	405,{
	mes "[Anfitrião Smoke]";
	mes "Você está pronto para começar?";
	next;
	switch(select("Sim.:Não.")) {
	case 1:
		mes "[Anfitrião Smoke]";
		mes "Boa sorte!";
		close2;
		donpcevent instance_npcname("#ins_pvp_arena_mobs")+"::OnEnable";
		delwaitingroom;
		disablenpc instance_npcname(strnpcinfo(0));
		end;
	case 2:
		mes "[Anfitrião Smoke]";
		mes "Fique à vontade.";
		close;
	}
	end;

OnInit:  // hide the NPC on the normal map
	disablenpc strnpcinfo(0);
	end;
OnInstanceInit:  // initialize the NPC when the instance is created
	//disablenpc instance_npcname("abysslakedunwarp004");  // disable original warp portal (currently buggy)
	waitingroom "Clique aqui para iniciar!",0;
	end;
}

pvp_arena,0,0,0	script	#ins_pvp_arena_mobs	-1,{
	end;
OnEnable:
	initnpctimer;
	end;
OnTimer1000:  //strnpcinfo(4) will retrieve the instanced map name
	mapannounce strnpcinfo(4),"Anfitrião Smoke: A Instância Arena Smoke começou.",bc_all;
	end;
OnTimer4000:
	mapannounce strnpcinfo(4),"Anfitrião Smoke: Eles estão vindo, acabe com eles!",bc_all;
	end;
OnTimer5000:
	stopnpctimer;

	.@map$ = strnpcinfo(4);

	// Estado
	set .@mob_count, 20; // Quantidade de Mob Normal
	setd(".mob_count_"+.@map$), .@mob_count;
	setd(".stage_"+.@map$), 1; // 1 = mobs vivos

	.@label$ = instance_npcname(strnpcinfo(0))+"::OnMobDead";

	monster .@map$,0,0,"Caminhante da Vida",30003,.@mob_count,.@label$;

	end;
OnMobDead:
	.@map$ = strnpcinfo(4);

	if (getd(".stage_"+.@map$) != 1)
		end;

	setd(".mob_count_"+.@map$), getd(".mob_count_"+.@map$) - 1;

	if (getd(".mob_count_"+.@map$) <= 0) {

		setd(".stage_"+.@map$), 2;

		mapannounce .@map$,"Anfitrião Smoke: A Caixa Smoke surgiu!",bc_all;

		.@label_caixa$ = instance_npcname(strnpcinfo(0))+"::OnCaixaDead";
		monster .@map$,50,55,"Caixa Smoke",30002,1,.@label_caixa$;
	}
	end;
OnCaixaDead:
	.@map$ = strnpcinfo(4);

	if (getd(".stage_"+.@map$) != 2)
		end;

	setd(".stage_"+.@map$), 3;

	mapannounce .@map$,"Anfitrião Smoke: O Sentinela da Vida surgiu!",bc_all;

	.@label$ = instance_npcname(strnpcinfo(0))+"::OnMyOnMiniBossDead";
	monster .@map$,0,0,"Sentinela da Vida",30004,5,.@label$;

	end;
OnMyOnMiniBossDead:
	.@map$ = strnpcinfo(4);

	if (getd(".stage_"+.@map$) != 3)
		end;

	setd(".stage_"+.@map$), 4;

	mapannounce .@map$,"Anfitrião Smoke: O Protetor da Vida finalmente apareceu!",bc_all;

	.@label$ = instance_npcname(strnpcinfo(0))+"::OnMyBossDead";
	monster .@map$,50,55,"Protetor da Vida",30005,1,.@label$;

	end;
OnMyBossDead:
	.@map$ = strnpcinfo(4);

	if (getd(".stage_"+.@map$) != 4)
		end;

	setd(".stage_"+.@map$), 5;

	killmonster .@map$,"All";

	mapannounce .@map$,"Anfitrião Smoke: Arena concluída!",bc_all;

	donpcevent instance_npcname("Anfitrião Smoke#finish")+"::OnEnable";

	end;
}

pvp_arena,49,51,4	script	Anfitrião Smoke#finish	405,{
	mes "[Anfitrião Smoke]";
	mes "Parabéns, você conseguiu finalizar a instância!";
	mes "Vou te enviar de volta para a cidade.";
	emotion ET_BEST;
	close2;
	warp "prontera",156,191;
	instance_destroy();
	end;

OnInit:
	disablenpc strnpcinfo(0);
	end;
OnInstanceInit:
	disablenpc instance_npcname(strnpcinfo(0));
	end;
OnEnable:
	enablenpc instance_npcname(strnpcinfo(0));
	//specialeffect EF_HIDING;
	end;
}

pvp_arena,33,29,0	script	#ins_pvp_arena_warp	45,5,5,{
	end;
OnTouch:
	mes "Tem certeza de que deseja ir embora?";
	mes "A instância será fechada...";
	next;
	switch(select("Sair.:Ficar.")) {
	case 1:
		warp "prontera",156,191;
		instance_destroy();
		break;
	case 2:
		warp strnpcinfo(4),160,155;
		break;
	}
	close;
OnInit:
	disablenpc strnpcinfo(0);
	end;
}
*/
prontera,167,176,4	script	Anfitrião Smoke	405,{
	.@iid = instance_id(IM_PARTY);
	if (.@iid > 0) { // só destrói se for válido {
    mes "[Anfitrião Smoke]";
    mes "Você já possui uma instância ativa!";
    next;
    switch(select("Entrar.:Cancelar.:Fechar instância.")) {
        case 1:  // Entrar na instância atual
            .@enter = instance_enter(.@instance$);
			if (.@enter != 0) {
				mes "[Anfitrião Smoke]";
				switch (.@enter) {
					case 1: mes "ERROR: Grupo não encontrado."; break;
					case 2: mes "ERROR: Grupo não possui uma instância."; break;
					case 3: mes "ERROR: Erro desconhecido.."; break;
				}
				mes " ";
				mes "^FF0000Falha^000000 ao entrar na instância.";
				emotion ET_HUK;
				close;
			}
			close;
            break;

        case 2:  // Apenas cancelar
			clear;
            mes "[Anfitrião Smoke]";
            mes "Ok, não faremos nada.";
            close;

        case 3:  // Fechar instância atual
            //instance_destroy(instance_id(IM_PARTY));
			mes "[Anfitrião Smoke]";
			mes "Deseja mesmo fechar a instância?";
			switch(select("Sim.:Não.")){
				case 1:
					instance_destroy instance_id(IM_PARTY);
					clear;
					mes "[Anfitrião Smoke]";
					mes "Instância fechada!";
					close;
				case 2:
					clear;
					mes "[Anfitrião Smoke]";
					mes "Ok, até mais!";
					close;
			}
    }
}

	mes "[Anfitrião Smoke]";
	mes "Olá, "+strcharinfo(0)+".";
	mes "Escolha o andar que deseja desafiar, junto com o seu grupo.";
	next;

	switch(select(
		"Andar I - Vida",
		"Andar II - Fogo",
		"Andar III - Gelo",
		"Andar IV - Morte",
		"Andar V - Divino",
		"Cancelar")) {

		case 1: .@instance$ = "Arena Smoke 1"; break;
		case 2: .@instance$ = "Arena Smoke 2"; break;
		case 3: .@instance$ = "Arena Smoke 3"; break;
		case 4: .@instance$ = "Arena Smoke 4"; break;
		case 5: .@instance$ = "Arena Smoke 5"; break;
		case 6: close;
		default: close;
	}

	.@iid = instance_create(.@instance$);

	if (.@create < 0) {
				mes "[Anfitrião Smoke]";
				switch (.@create) {
					case -1: mes "ERROR: Tipo inválido."; break;
					case -2: mes "ERROR: Grupo não encontrado."; break;
					case -3: mes "ERROR: Instância já existe."; break;
					case -4: mes "ERROR: Sem instâncias livres."; break;
				}
				mes " ";
				mes "Criação da instância ^FF0000falhou^000000.";
				emotion ET_HUK;
				close;
			}
		.@enter = instance_enter(.@instance$);
			if (.@enter != 0) {
				mes "[Anfitrião Smoke]";
				switch (.@enter) {
					case 1: mes "ERROR: Grupo não encontrado."; break;
					case 2: mes "ERROR: Grupo não possui uma instância."; break;
					case 3: mes "ERROR: Erro desconhecido.."; break;
				}
				mes " ";
				mes "^FF0000Falha^000000 ao entrar na instância.";
				emotion ET_HUK;
				close;
			}
			close;
}
pvp_arena,49,51,6	script	Anfitrião Smoke#start	405,{
	mes "[Anfitrião Smoke]";
	mes "Você está pronto para começar?";
	next;
	switch(select("Sim.:Não.")) {
	case 1:
		mes "[Anfitrião Smoke]";
		mes "Boa sorte!";
		close2;
		donpcevent instance_npcname("#ins_pvp_arena_mobs")+"::OnEnable";
		delwaitingroom;
		disablenpc instance_npcname(strnpcinfo(0));
		end;
	case 2:
		mes "[Anfitrião Smoke]";
		mes "Fique à vontade.";
		close;
	}
	end;

OnInit:  // hide the NPC on the normal map
	disablenpc strnpcinfo(0);
	end;
OnInstanceInit:  // initialize the NPC when the instance is created
	//disablenpc instance_npcname("abysslakedunwarp004");  // disable original warp portal (currently buggy)
	waitingroom "Clique aqui para iniciar!",0;
	.@name$ = instance_live_info(ILI_NAME, instance_id());
	.@map$  = strnpcinfo(4);

	// ==========================
	// DEFINIÇÃO DOS MOBS
	// ==========================

	if (.@name$ == "Arena Smoke 1") {
		.@mob_id = 30003;
		.@mob_amount = 10;
		.@miniboss_id = 30004;
		.@miniboss_amount = 3;
		.@miniboss_label$ = strnpcinfo(0)+"::OnMiniBossDead";
		.@boss_id = 30005;
		.@boss_amount = 1;
		.@boss_label$ = strnpcinfo(0)+"::OnBossDead";
		.@boss_name$ = "Protetor da Vida";
		.@miniboss_name$ = "Sentinela da Vida";
		.@mob_name$ = "Caminhante da Vida" ;
	}
	else if (.@name$ == "Arena Smoke 2") {
		.@mob_id = 30006;
		.@mob_amount = 10;
		.@miniboss_id = 30007;
		.@miniboss_amount = 3;
		.@miniboss_label$ = strnpcinfo(0)+"::OnMiniBossDead";
		.@boss_id = 30008;
		.@boss_amount = 1;
		.@boss_label$ = strnpcinfo(0)+"::OnBossDead";
		.@boss_name$ = "Protetor do Fogo";
		.@miniboss_name$ = "Sentinela do Fogo";
		.@mob_name$ = "Caminhante do Fogo" ;
	}
	else if (.@name$ == "Arena Smoke 3") {
		.@mob_id = 30009;
		.@mob_amount = 10;
		.@miniboss_id = 30010;
		.@miniboss_amount = 3;
		.@miniboss_label$ = strnpcinfo(0)+"::OnMiniBossDead";
		.@boss_id = 30011;
		.@boss_amount = 1;
		.@boss_label$ = strnpcinfo(0)+"::OnBossDead";
		.@boss_name$ = "Protetor do Gelo";
		.@miniboss_name$ = "Sentinela do Gelo";
		.@mob_name$ = "Caminhante do Gelo" ;
	}
	else if (.@name$ == "Arena Smoke 4") {
		.@mob_id = 30012;
		.@mob_amount = 10;
		.@miniboss_id = 30013;
		.@miniboss_amount = 3;
		.@miniboss_label$ = strnpcinfo(0)+"::OnMiniBossDead";
		.@boss_id = 30014;
		.@boss_amount = 1;
		.@boss_label$ = strnpcinfo(0)+"::OnBossDead";
		.@boss_name$ = "Protetor da Morte";
		.@miniboss_name$ = "Sentinela da Morte";
		.@mob_name$ = "Caminhante da Morte" ;
	}
	else if (.@name$ == "Arena Smoke 5") {
		.@mob_id = 30018;
		.@mob_amount = 10;
		.@miniboss_id = 30019;
		.@miniboss_amount = 3;
		.@miniboss_label$ = strnpcinfo(0)+"::OnMiniBossDead";
		.@boss_id = 30020;
		.@boss_amount = 1;
		.@boss_label$ = strnpcinfo(0)+"::OnBossDead";
		.@boss_name$ = "Protetor Divino";
		.@miniboss_name$ = "Sentinela Divino";
		.@mob_name$ = "Caminhante Divino" ;
	}
}
pvp_arena,0,0,0	script	#ins_pvp_arena_mobs	-1,{
	end;
OnEnable:
	initnpctimer;
	end;
OnTimer1000:  //strnpcinfo(4) will retrieve the instanced map name
	mapannounce strnpcinfo(4),"Anfitrião Smoke: A Instância Arena Smoke começou.",bc_all;
	end;
OnTimer4000:
	mapannounce strnpcinfo(4),"Anfitrião Smoke: Eles estão vindo, acabe com eles!",bc_all;
	end;
OnTimer5000:
	stopnpctimer;
    .@map$ = strnpcinfo(4);
    // ==========================
    // Spawn dos mobs normais
    // ==========================
    setd(".mob_count_normal_"+.@map$), .@mob_amount; // contador inicial
    setd(".stage_"+.@map$), 1;                        // stage 1 = mobs normais
    // Spawn dos mobs normais
    monster .@map$,0,0,"[Torre Smoke] Caminhante",.@mob_id,.@mob_amount,strnpcinfo(0)+"::OnMobNormalDead";
end;
	// Spawn e evento dos mobs normais
OnMobNormalDead:
    .@map$ = strnpcinfo(4);

    // Reduz o contador de mobs normais
    setd(".mob_count_normal_"+.@map$), getd(".mob_count_normal_"+.@map$) - 1;

    // Se todos os mobs normais morreram, spawn dos minibosses
    if (getd(".mob_count_normal_"+.@map$) <= 0) {
        setd(".stage_"+.@map$), 2;
        setd(".mob_count_miniboss_"+.@map$), .@miniboss_amount;

        // Spawn minibosses usando ID (nome será do mob_db)
        monster .@map$,0,0,"[Torre Smoke] Sentinela",.@miniboss_id,.@miniboss_amount,.@miniboss_label$;
        mapannounce .@map$, "Anfitrião Smoke: Os Sentinelas apareceram!", bc_all;
    }
end;

// Evento dos minibosses
OnMiniBossDead:
    .@map$ = strnpcinfo(4);

    // Reduz contador de minibosses
    setd(".mob_count_miniboss_"+.@map$), getd(".mob_count_miniboss_"+.@map$) - 1;

    // Se todos os minibosses morreram, spawn do boss final
    if (getd(".mob_count_miniboss_"+.@map$) <= 0) {
        setd(".stage_"+.@map$), 3;
        setd(".mob_count_boss_"+.@map$), .@boss_amount;

        // Spawn do boss usando ID (nome do mob_db)
        monster .@map$,0,0,"[Torre Smoke] Protetor",.@boss_id,.@boss_amount,.@boss_label$;
        mapannounce .@map$, "Anfitrião Smoke: O Protetor apareceu! Prepare-se!", bc_all;
    }
end;

// Evento do boss final
OnBossDead:
    .@map$ = strnpcinfo(4);

    // Reduz contador de boss
    setd(".mob_count_boss_"+.@map$), getd(".mob_count_boss_"+.@map$) - 1;

    // Se o boss morreu, termina a arena
    if (getd(".mob_count_boss_"+.@map$) <= 0) {
        mapannounce .@map$, "Anfitrião Smoke: Arena concluída!", bc_all;

        // Chama NPC de finish para recompensas/warp
        donpcevent instance_npcname("Anfitrião Smoke#finish")+"::OnEnable";
    }
end;
}

// NPC #finish permanece igual
pvp_arena,49,51,4	script	Anfitrião Smoke#finish	405,{
	mes "[Anfitrião Smoke]";
	mes "Parabéns, você conseguiu finalizar a instância!";
	mes "Vou te enviar de volta para a cidade.";
	emotion ET_BEST;
	close2;
	warp "prontera",156,191;
	instance_destroy();
	end;

OnInit:
	disablenpc strnpcinfo(0);
	end;

OnInstanceInit:
	disablenpc instance_npcname(strnpcinfo(0));
	end;

OnEnable:
	enablenpc instance_npcname(strnpcinfo(0));
	end;
}