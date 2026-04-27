//==================================================
// Santuario Smoke V2.5
// Instância dinâmica de EXP
//==================================================

prontera,167,176,4	script	Santuario Smoke	588,{
    if (instance_id(IM_CHAR)) {
        .@instance_id = instance_id(IM_CHAR);
        .@instance_name$ = instance_live_info(ILI_NAME, .@instance_id);

        switch(select("Entrar na instância.:Cancelar.:Fechar instância.")) {
            case 1:
                if (instance_enter(.@instance_name$) != 0) {
                    mes "[Santuario Smoke]";
                    mes "^FF0000Falha^000000 ao entrar na instância.";
                    emotion ET_HUK;
                    close;
                }
                end;
                
            case 2:
                mes "[Santuario Smoke]";
                mes "Não quer tentar novamente?";
                emotion ET_CRY;
                close;
                
            case 3:
                mes "[Santuario Smoke]";
                mes "Deseja mesmo fechar a instância?";
                next;
                switch(select("Sim.:Não.")) {
                    case 1:
                        instance_destroy(.@instance_id);
                        mes "[Santuario Smoke]";
                        mes "Instância fechada!";
                        close;
                    case 2:
                        mes "[Santuario Smoke]";
                        mes "Ok, até mais!";
                        close;
                }
        }
    }

	mes "[Santuario Smoke]";
	mes "Deseja iniciar o experimento?";
    switch( select( "- Informações:- Participar" )){
    Case 1:
        clear;
        mes "[Santuario Smoke]";
        mes "O Santuario Smoke...";
        mes "Você poderá subir de nível nesta sala, mas não receberá loot dos mobs.";
        next;
        mes "Mas há algumas condições..";
        mes "Você só poderá entrar abaixo do level máximo.";
        mes "E você só poderá entrar SOZINHO!";
        close;

    Case 2:
        if (BaseLevel >= 275) {
            clear;
            mes "[Santuario Smoke]";
            mes "Você já atingiu o nível máximo.";
            close;
        }

        if (instance_id(IM_CHAR)) {
            clear;
            mes "[Santuario Smoke]";
            mes "Você já possui uma instância ativa.";
            close;
        }

        .@iid = instance_create("Santuario Smoke", IM_CHAR);

        if (.@iid < 0) {
            clear;
            mes "[Santuario Smoke]";
            mes "Erro ao criar instância.";
            close;
        }

        warp instance_mapname("pvp_arena", .@iid),50,35;

        close;
    }
}

//==================================================
// CONTROLADOR DA INSTÂNCIA
//==================================================
pvp_arena,49,51,6	script	Santuario Smoke#start	588,{
	mes "[Santuario Smoke]";
	mes "Você está pronto para começar?";
	next;
	switch(select("Sim.:Não.")) {
	case 1:
		mes "[Santuario Smoke]";
		mes "Boa sorte!";
		close2;
		donpcevent instance_npcname("SantuarioSmoke_Controller")+"::OnEnable";
		delwaitingroom;
		disablenpc instance_npcname(strnpcinfo(0));
		end;
	case 2:
		mes "[Santuario Smoke]";
		mes "Fique à vontade.";
		close;
	}
	end;

OnInit:
	disablenpc strnpcinfo(0);
	end;
	
OnInstanceInit:
	// PEGA O NOME DA INSTÂNCIA ATUAL
    .@instance_name$ = instance_live_info(ILI_NAME, instance_id());
	
	 // VERIFICA SE É UMA INSTÂNCIA DA ARENA USANDO compare
    if (compare(.@instance_name$, "Santuario Smoke")) {
        // É do Santuario Smoke - configura a waiting room
        waitingroom "Clique aqui para iniciar!",0;
        enablenpc instance_npcname(strnpcinfo(0));
        //debugmes "Arena ATIVADA: " + .@instance_name$;
        
    } else {
        // É da Arena - mantém desativado
        disablenpc instance_npcname(strnpcinfo(0));
        //debugmes "Arena DESATIVADA (instância do Santuário): " + .@instance_name$;
    }
    end;
}

pvp_arena,0,0,0	script	SantuarioSmoke_Controller	-1,{
    end;

OnInit:

	// densidade máxima
	.MaxMobs = 120;

	// spawn quando cair abaixo
	.MinMobs = 90;

	// anti afk
	.MinKills = 5;

	// mapflags
	.@map$ = strnpcinfo(4);

	setmapflag .@map$, mf_noreturn;
	setmapflag .@map$, mf_noteleport;
	setmapflag .@map$, mf_nowarp;
	setmapflag .@map$, mf_nowarpto;
	setmapflag .@map$, mf_nomemo;
	setmapflag .@map$, mf_nobranch;
	setmapflag .@map$, mf_nopenalty;
	setmapflag .@map$, mf_partylock;
	setmapflag .@map$, mf_monster_noteleport;
	setmapflag .@map$, mf_nomobloot;
	end;

//==================================================
// INICIO DA INSTÂNCIA
//==================================================
OnEnable:
	initnpctimer;
	end;

OnTimer1000:

    .@instance_id = instance_id(IM_CHAR);

    .@map$ = strnpcinfo(4);
    getmapunits(BL_PC, .@map$, .@players);
    attachrid(.@players[0]);
    .@level = BaseLevel;
    detachrid;
    
    // define mobs
    if (.@level < 100)
        setarray .MobList[0],1031,1113,1178;
    else if (.@level < 180)
        setarray .MobList[0],1785,1788,1715;
    else if (.@level < 230)
        setarray .MobList[0],2068,2072,2087;
    else
        setarray .MobList[0],21386,21387,21388;

    callsub OnSpawnMobs,.MaxMobs;

    stopnpctimer;

    end;

//==================================================
// SPAWN CONTROLADO
//==================================================

OnSpawnMobs:

    .@instance_id = instance_id(IM_CHAR);

	.@amount = getarg(0);

	for (.@i = 0; .@i < .@amount; .@i++) {

		.@mob = .MobList[rand(getarraysize(.MobList))];

		.@map$ = strnpcinfo(4);
        monster .@map$,0,0,"Espécime",.@mob,1,strnpcinfo(0)+"::OnMobDead";
	}

	end;

//==================================================
// MORTE DE MOB
//==================================================

OnMobDead:
    .@instance_id = instance_id(IM_CHAR);

	if (isloggedin(killedrid,getcharid(3))) {
		attachrid killedrid;
		@afk_kills++;
		detachrid;
	}

    if (BaseLevel >= 275 && .@instance_id) {

		dispbottom "[Santuario Smoke] Você atingiu o nível máximo.";
		instance_destroy(.@instance_id);
        warp "prontera",156,191;

	}
    .@mob = .MobList[rand(getarraysize(.MobList))];

	.@map$ = strnpcinfo(4);
    monster .@map$,0,0,"Espécime",.@mob,1,strnpcinfo(0)+"::OnMobDead";

	end;

//==================================================
// TIMER PRINCIPAL
//==================================================

OnTimer10000:

    .@instance_id = instance_id(IM_CHAR);

	.@map$ = strnpcinfo(4);

	// conta mobs vivos
	getmapunits(BL_MOB, .@map$, .@mobs);

	if (getarraysize(.@mobs) < .MinMobs) {

		.@spawn = .MaxMobs - getarraysize(.@mobs);

		callsub OnSpawnMobs,.@spawn;
	}

	stopnpctimer;

	end;

//==================================================
// ANTI AFK
//==================================================

OnTimer60000:

    .@instance_id = instance_id(IM_CHAR);

    .@map$ = strnpcinfo(4);

	getmapunits (BL_PC, .@map$, .@players);

	for (.@i = 0; .@i < getarraysize(.@players); .@i++) {

		attachrid .@players[.@i];

		if (@afk_kills < .MinKills) {

			dispbottom "[Santuario Smoke] Removido por inatividade.";
			warp "prontera",156,191;

		}

		@afk_kills = 0;

		detachrid;
	}

	end;

}