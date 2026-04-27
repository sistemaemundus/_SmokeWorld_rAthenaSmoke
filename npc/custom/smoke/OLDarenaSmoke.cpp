// Criado por Alek Emundus
// Torre das Ilusões - Instanciada em 5 Andares
//============================================================
prontera,167,176,4	script	Anfitrião Smoke	405,{
    // Verifica se o jogador já está em uma instância
    if (instance_id(IM_PARTY)) {
        .@instance_id = instance_id(IM_PARTY);
        .@instance_name$ = instance_live_info(ILI_NAME, .@instance_id);
        
        mes "[Anfitrião Smoke]";
        mes "Você já faz parte de uma instância:";
        mes "^FF0000" + .@instance_name$ + "^000000";
        next;
        
        switch(select("Entrar na instância.:Cancelar.:Fechar instância.")) {
            case 1:
                if (instance_enter(.@instance_name$) != 0) {
                    mes "[Anfitrião Smoke]";
                    mes "^FF0000Falha^000000 ao entrar na instância.";
                    emotion ET_HUK;
                    close;
                }
                end;
                
            case 2:
                mes "[Anfitrião Smoke]";
                mes "Não quer tentar novamente?";
                emotion ET_CRY;
                close;
                
            case 3:
                mes "[Anfitrião Smoke]";
                mes "Deseja mesmo fechar a instância?";
                next;
                switch(select("Sim.:Não.")) {
                    case 1:
                        instance_destroy(.@instance_id);
                        mes "[Anfitrião Smoke]";
                        mes "Instância fechada!";
                        close;
                    case 2:
                        mes "[Anfitrião Smoke]";
                        mes "Ok, até mais!";
                        close;
                }
        }
    }
    
    // Se não está em nenhuma instância, oferece para criar uma nova
    mes "[Anfitrião Smoke]";
    mes "Gostaria de entrar em uma Arena Smoke?";
    next;
    
    switch(select("Sim.:Informações.:Cancelar.")) {
        case 1:
            next;
			clear;
			mes "[Anfitrião Smoke]";
			mes "Qual andar gostaria de desafiar?";
			next;
            switch(select("1. Vida.:2. Fogo.:3. Gelo.:4. Morte.:5. Ancestral.:6. Divino.:Cancelar")) {
                case 1:
                    .@instance_name$ = "Smoke I - Vida";
                    .@create = instance_create(.@instance_name$);
					if (.@create > 0) {
                        mes "[Anfitrião Smoke]";
                        mes "Instância criada com sucesso!";
                        mes " ";
                        mes "Vou lhe enviar para lá...";
                        close2;
                        
                        sleep2 500;
                        
                        if (instance_enter(.@instance_name$) != 0) {
                            mes "[Anfitrião Smoke]";
                            mes "^FF0000Falha^000000 ao entrar na instância.";
                            emotion ET_HUK;
                            close;
                        }
                    } else {
                        callsub S_ErroCriacao, .@create;
                    }
                    end;
                    
                case 2:
                    .@instance_name$ = "Smoke II - Fogo";
                    .@create = instance_create(.@instance_name$);
					if (.@create > 0) {
                        mes "[Anfitrião Smoke]";
                        mes "Instância criada com sucesso!";
                        mes " ";
                        mes "Vou lhe enviar para lá...";
                        close2;
                        
                        sleep2 500;
                        
                        if (instance_enter(.@instance_name$) != 0) {
                            mes "[Anfitrião Smoke]";
                            mes "^FF0000Falha^000000 ao entrar na instância.";
                            emotion ET_HUK;
                            close;
                        }
                    } else {
                        callsub S_ErroCriacao, .@create;
                    }
                    end;
                    
                case 3:
                    .@instance_name$ = "Smoke III - Gelo";
                    .@create = instance_create(.@instance_name$);
					if (.@create > 0) {
                        mes "[Anfitrião Smoke]";
                        mes "Instância criada com sucesso!";
                        mes " ";
                        mes "Vou lhe enviar para lá...";
                        close2;
                        
                        sleep2 500;
                        
                        if (instance_enter(.@instance_name$) != 0) {
                            mes "[Anfitrião Smoke]";
                            mes "^FF0000Falha^000000 ao entrar na instância.";
                            emotion ET_HUK;
                            close;
                        }
                    } else {
                        callsub S_ErroCriacao, .@create;
                    }
                    end;
                    
                case 4:
                    .@instance_name$ = "Smoke IV - Morte";
                    .@create = instance_create(.@instance_name$);
					if (.@create > 0) {
                        mes "[Anfitrião Smoke]";
                        mes "Instância criada com sucesso!";
                        mes " ";
                        mes "Vou lhe enviar para lá...";
                        close2;
                        
                        sleep2 500;
                        
                        if (instance_enter(.@instance_name$) != 0) {
                            mes "[Anfitrião Smoke]";
                            mes "^FF0000Falha^000000 ao entrar na instância.";
                            emotion ET_HUK;
                            close;
                        }
                    } else {
                        callsub S_ErroCriacao, .@create;
                    }
                    end;
                    
                case 5:
                    .@instance_name$ = "Smoke V - Ancestral";
                    .@create = instance_create(.@instance_name$);
					if (.@create > 0) {
                        mes "[Anfitrião Smoke]";
                        mes "Instância criada com sucesso!";
                        mes " ";
                        mes "Vou lhe enviar para lá...";
                        close2;
                        
                        sleep2 500;
                        
                        if (instance_enter(.@instance_name$) != 0) {
                            mes "[Anfitrião Smoke]";
                            mes "^FF0000Falha^000000 ao entrar na instância.";
                            emotion ET_HUK;
                            close;
                        }
                    } else {
                        callsub S_ErroCriacao, .@create;
                    }
                    end;
                    
                case 6:
                    .@instance_name$ = "Smoke VI - Divino";
                    .@create = instance_create(.@instance_name$);
					if (.@create > 0) {
                        mes "[Anfitrião Smoke]";
                        mes "Instância criada com sucesso!";
                        mes " ";
                        mes "Vou lhe enviar para lá...";
                        close2;
                        
                        sleep2 500;
                        
                        if (instance_enter(.@instance_name$) != 0) {
                            mes "[Anfitrião Smoke]";
                            mes "^FF0000Falha^000000 ao entrar na instância.";
                            emotion ET_HUK;
                            close;
                        }
                    } else {
                        callsub S_ErroCriacao, .@create;
                    }
                    end;
                    
                case 7:
                    mes "[Anfitrião Smoke]";
                    mes "Até mais!";
                    close;
            }
            
        case 2:
            mes "[Anfitrião Smoke]";
            mes "A Arena Smoke foi tomado por forças incontroláveis.";
            mes "A fumaça encobre um poder que não deveria existir.";
            mes "Possuindo atualmente ao todo 6 andares.";
            mes "O verdadeiro desafio o aguarda no final de cada um deles!";
            close;
            
        case 3:
            mes "[Anfitrião Smoke]";
            mes "Ok, talvez da próxima!";
            close;
    }
    close;
    
// Subfunção para mostrar erro de criação
S_ErroCriacao:
    .@erro = getarg(0);
    
    mes "[Anfitrião Smoke]";
    switch (.@erro) {
        case -1: mes "ERROR: Tipo inválido."; break;
        case -2: mes "ERROR: Grupo não encontrado."; break;
        case -3: mes "ERROR: Instância já existe."; break;
        case -4: mes "ERROR: Sem instâncias livres."; break;
        default: mes "ERROR: Erro desconhecido. Código: " + .@erro; break;
    }
    mes " ";
    mes "Criação da instância ^FF0000falhou^000000.";
    emotion ET_HUK;
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

OnInit:
	disablenpc strnpcinfo(0);
	end;
	
OnInstanceInit:
	// APENAS configura a waiting room, sem definir mobs
	waitingroom "Clique aqui para iniciar!",0;
	end;
}

pvp_arena,0,0,0	script	#ins_pvp_arena_mobs	-1,{
	end;
	
OnEnable:
	initnpctimer;
	end;
	
OnTimer1000:
	mapannounce strnpcinfo(4),"Anfitrião Smoke: A Instância Smoke começou.",bc_all;
	end;
	
OnTimer4000:
	mapannounce strnpcinfo(4),"Anfitrião Smoke: Eles estão vindo, acabe com eles!",bc_all;
	end;
	
OnTimer5000:
	stopnpctimer;

	.@map$ = strnpcinfo(4);
	.@instance_name$ = instance_live_info(ILI_NAME, instance_id());

	// ==========================
	// DEFINIÇÃO DOS MOBS - AGORA AQUI NO OnTimer5000
	// ==========================

	if (.@instance_name$ == "Smoke I - Vida") {
		.@mob_id = 30003;
		.@mob_amount = 20;
		.@miniboss_id = 30004;
		.@miniboss_amount = 5;
		.@boss_id = 30005;
		.@boss_amount = 1;
	}
	else if (.@instance_name$ == "Smoke II - Fogo") {
		.@mob_id = 30006;
		.@mob_amount = 20;
		.@miniboss_id = 30007;
		.@miniboss_amount = 5;
		.@boss_id = 30008;
		.@boss_amount = 1;
	}
	else if (.@instance_name$ == "Smoke III - Gelo") {
		.@mob_id = 30009;
		.@mob_amount = 20;
		.@miniboss_id = 30010;
		.@miniboss_amount = 5;
		.@boss_id = 30011;
		.@boss_amount = 1;
	}
	else if (.@instance_name$ == "Smoke IV - Morte") {
		.@mob_id = 30012;
		.@mob_amount = 20;
		.@miniboss_id = 30013;
		.@miniboss_amount = 5;
		.@boss_id = 30014;
		.@boss_amount = 1;
	}
	else if (.@instance_name$ == "Smoke V - Ancestral") {
		.@mob_id = 30015;
		.@mob_amount = 20;
		.@miniboss_id = 30016;
		.@miniboss_amount = 5;
		.@boss_id = 30017;
		.@boss_amount = 1;
	}
	else if (.@instance_name$ == "Smoke VI - Divino") {
		.@mob_id = 30018;
		.@mob_amount = 20;
		.@miniboss_id = 30019;
		.@miniboss_amount = 5;
		.@boss_id = 30020;
		.@boss_amount = 1;
	}
	else {
		mapannounce .@map$,"Erro: Instância desconhecida - "+.@instance_name$,bc_all;
		end;
	}

	// Debug
	//mapannounce .@map$,"Debug: Instância: "+.@instance_name$,bc_all;
	//mapannounce .@map$,"Debug: Mob ID: "+.@mob_id,bc_all;
	//mapannounce .@map$,"Debug: Mob Amount: "+.@mob_amount,bc_all;

	// Estado
	setd(".mob_count_"+.@map$, .@mob_amount);
	setd(".stage_"+.@map$, 1);

	.@label$ = instance_npcname(strnpcinfo(0))+"::OnMobDead";

	areamonster .@map$,31,68,67,32,"Caminhante",.@mob_id,.@mob_amount,.@label$;

	end;
	
OnMobDead:
	.@map$ = strnpcinfo(4);

	if (getd(".stage_"+.@map$) != 1)
		end;

	setd(".mob_count_"+.@map$), getd(".mob_count_"+.@map$) - 1;

	if (getd(".mob_count_"+.@map$) <= 0) {

		setd(".stage_"+.@map$), 2;

		mapannounce .@map$,"Anfitrião Smoke: Uma Caixa Smoke?!",bc_all;

		.@label_caixa$ = instance_npcname(strnpcinfo(0))+"::OnCaixaDead";
		monster .@map$,50,55,"Caixa Smoke",30002,1,.@label_caixa$;
	}
	end;
	
OnCaixaDead:
	.@map$ = strnpcinfo(4);

	.@miniboss_id = getd(".miniboss_id_"+.@map$);
	.@miniboss_amount = getd(".miniboss_amount_"+.@map$);
	setd(".miniboss_count_"+.@map$, .@miniboss_amount);
	
	// 20% de chance de drop
	if (rand(100) < 20) {
		makeitem 840134,1,.@map$,.@x,.@y;
		mapannounce .@map$,"Anfitrião Smoke: Parece que caiu algo da caixa... Pegue!",bc_map;
	}
	
	// Se não encontrou, tenta pegar da instância
	if (.@miniboss_id == 0) {
		.@instance_name$ = instance_live_info(ILI_NAME, instance_id());
		if (.@instance_name$ == "Smoke I - Vida") { .@miniboss_id = 30004; .@miniboss_amount = 3; }
		else if (.@instance_name$ == "Smoke II - Fogo") { .@miniboss_id = 30007; .@miniboss_amount = 3; }
		else if (.@instance_name$ == "Smoke III - Gelo") { .@miniboss_id = 30010; .@miniboss_amount = 3; }
		else if (.@instance_name$ == "Smoke IV - Morte") { .@miniboss_id = 30013; .@miniboss_amount = 3; }
		else if (.@instance_name$ == "Smoke V - Ancestral") { .@miniboss_id = 30016; .@miniboss_amount = 3; }
		else if (.@instance_name$ == "Smoke VI - Divino") { .@miniboss_id = 30019; .@miniboss_amount = 3; }
	}

	if (getd(".stage_"+.@map$) != 2)
		end;

	setd(".stage_"+.@map$), 3;

	mapannounce .@map$,"Anfitrião Smoke: Os Sentinelas surgiram!",bc_all;

	.@label$ = instance_npcname(strnpcinfo(0))+"::OnMyMiniBossDead";
	areamonster .@map$,42,57,57,42,"Sentinela",.@miniboss_id,.@miniboss_amount,.@label$;

	end;
	
OnMyMiniBossDead:
	.@map$ = strnpcinfo(4);

	.@boss_id = getd(".boss_id_"+.@map$);
	.@boss_amount = getd(".boss_amount_"+.@map$);
	
	if (getd(".stage_"+.@map$) != 3)
	end;
	
	setd(".miniboss_count_"+.@map$), getd(".miniboss_count_"+.@map$) - 1;

	if (getd(".miniboss_count_"+.@map$) <= 0) {
		// Se não encontrou, tenta pegar da instância
		if (.@boss_id == 0) {
			.@instance_name$ = instance_live_info(ILI_NAME, instance_id());
			if (.@instance_name$ == "Smoke I - Vida") { .@boss_id = 30005; .@boss_amount = 1; }
			else if (.@instance_name$ == "Smoke II - Fogo") { .@boss_id = 30008; .@boss_amount = 1; }
			else if (.@instance_name$ == "Smoke III - Gelo") { .@boss_id = 30011; .@boss_amount = 1; }
			else if (.@instance_name$ == "Smoke IV - Morte") { .@boss_id = 30014; .@boss_amount = 1; }
			else if (.@instance_name$ == "Smoke V - Ancestral") { .@boss_id = 30017; .@boss_amount = 1; }
			else if (.@instance_name$ == "Smoke VI - Divino") { .@boss_id = 30020; .@boss_amount = 1; }
		}

		setd(".stage_"+.@map$), 4;

		mapannounce .@map$,"Anfitrião Smoke: Essa não, o Protetor foi despertado!",bc_all;

		.@label$ = instance_npcname(strnpcinfo(0))+"::OnMyBossDead";
		.@boss_mobid = monster (.@map$,50,55,"Protetor",.@boss_id,.@boss_amount,.@label$);
		setd(".boss_mobid_"+.@map$, .@boss_mobid);
	}

	end;
	
OnMyBossDead:
	.@map$ = strnpcinfo(4);

	if (getd(".stage_"+.@map$) != 4)
		end;

	setd(".stage_"+.@map$), 5;

	killmonster .@map$,"All";

	mapannounce .@map$,"Anfitrião Smoke: Minha nossa!",bc_all;
	// pega posição do boss morto
	.@boss_mobid = getd(".boss_mobid_"+.@map$);
	getmapxy(.@map$, .@x, .@y, BL_NPC, Protetor);

	// 10% de chance de drop
	if (rand(100) < 10) {
		makeitem 840134,1,.@map$,.@x,.@y;
		mapannounce .@map$,"Anfitrião Smoke: Parece que caiu algo do boss... Pegue rápido!",bc_map;
	}

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
	end;
}