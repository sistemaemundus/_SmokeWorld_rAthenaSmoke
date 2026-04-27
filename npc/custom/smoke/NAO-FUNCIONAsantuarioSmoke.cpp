//====================================================
// Santuario Smoke
// Criador para SmokeWorld by Emundus
//====================================================

// BLOCO 1 — NPC DE ENTRADA + CONFIGURAÇÕES + INICIALIZAÇÃO DA INSTÂNCIA
prontera,167,176,4	script	Santuario Smoke	588,{
	if (instance_id(IM_PARTY)) {
        .@instance_id = instance_id(IM_PARTY);
        .@instance_name$ = instance_live_info(ILI_NAME,.@instance_id);
        
        mes "[Santuario Smoke]";
        mes "Você já faz parte de uma instância:";
        mes "^FF0000" + .@instance_name$ + "^000000.";
        next;
        
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
	mes "Bem-vindo ao Santuario Smoke!";
	next;

	// MENU
	set .@menu,select("Sobre o Santuario Smoke:Entrar no Santuário:Cancelar");

	if (.@menu == 1) {
		// Informações
		clear;
		mes "[Santuario Smoke]";
		mes "No Santuario Smoke você enfrentará espécimes de todo continente.";
		mes "Serão espécimes aleatórias, então você pode enfrentar qualquer monstro existente!";
		next;
		clear;
		mes "[Santuario Smoke]";
		mes "No Santuario Smoke você irá adquirir experiência normalmente, mas não haverá loot dos espécimes.";
		mes "Ao invés do loot normal você receberá Pontos do Santuário, que são usados no NPC respectivo na área de ^32CD32Quests/Trocas Smoke^000000.";
		next;
		clear;
		mes "[Santuario Smoke]";
		mes "Observação: você não enfrentará os monstros normais, serão versões escaneadas pelo Alto Conselho.";
		mes "Portanto, fique o aviso: não tenha piedade deles, pois eles não terão de você!";
		close;
	}

	if (.@menu == 2) {
		//--------------------------------------------------
		// EXIGIR PARTY
		//--------------------------------------------------
		if (!getcharid(1)) {
			mes "[Santuario Smoke]";
			mes "Você precisa estar em uma party.";
			close;
		}

		if (getpartyleader(getcharid(1),2) != getcharid(0)) {
			mes "[Santuario Smoke]";
			mes "Apenas o líder da party pode iniciar.";
			close;
		}

		getpartymember getcharid(1),1;

		if ($@partymembercount < .MinParty) {
			mes "[Santuario Smoke]";
			mes "São necessários pelo menos "+.MinParty+" jogadores.";
			close;
		}

		//--------------------------------------------------
		// VERIFICAR SE TODOS OS MEMBROS ESTÃO ONLINE
		//--------------------------------------------------
		// Pega seu Account ID
		.@my_aid = getcharid(3);
		.@total_members = $@partymembercount;

		// Se for party solo (só você)
		if (.@total_members == 1) {
			// Não precisa verificar ninguém
			mes "[Santuario Smoke]";
			mes "Modo solo detectado!";
			mes "Deseja iniciar o desafio?";
			next;
			
			if (select("Sim:Não") == 2) {
				close;
			}
			
			// Continua para criar a instância...
			
			// ANTES de criar a instância, salve o líder e party em variáveis globais
			// .@party_id = getcharid(1);
			// .@leader_cid = getcharid(0);

			// Salva em variáveis globais para o controlador acessar depois
			// Salva no jogador
			
			//--------------------------------------------------
			// CRIAR INSTANCIA (agora com segurança)
			//--------------------------------------------------
			.@instance_name$ = "Santuario Smoke";
			.@create = instance_create(.@instance_name$);
			.@party_id = getcharid(1);
			getpartymember getcharid(1), 1;
			setinstancevar ('PartySize, $@partymembercount, .@create);
			setinstancevar ('PartyID, getcharid(1), .@create);

			if (.@create < 0) {
				mes "[Santuario Smoke]";
				mes "Não foi possível criar a instância.";
				mes "Contate a administração.";
				close;
			}

			// Salva o líder e party para usar no controlador
			// .@party_id = getcharid(1);
			// .@leader_cid = getcharid(0);
			// setd(".santuario_leader_" + .@party_id, .@leader_cid);
			// setd(".santuario_party_" + .@party_id, .@party_id);

			mes "[Santuario Smoke]";
			mes "Instância criada! Teleportando todos...";
			close2;

			// Líder entra primeiro
			if (instance_enter(.@instance_name$) != 0) {
				// Se falhar, tenta limpar
				instance_destroy(.@instance_id);
				end;
			}

			// Teleporta os outros membros
			sleep2 500;
			// for (.@i = 0; .@i < $@partymembercount; .@i++) {
				// if ($@partymemberaid[.@i] != getcharid(3)) { // Ignora o líder
					// attachrid $@partymemberaid[.@i];
					// instance_enter .@instance_name$;
					// sleep2 200;
				// }
			// }
			
		} else {
			// Party com múltiplos membros - verifica os outros
			.@offline_found = 0;
			.@online_count = 1; // Você conta como online
			
			for (.@i = 0; .@i < .@total_members; .@i++) {
				// Pula você mesmo
				if ($@partymemberaid[.@i] == .@my_aid)
					continue;
				
				if (isloggedin($@partymemberaid[.@i], $@partymembercid[.@i])) {
					.@online_count++;
				} else {
					.@offline_found = 1;
					break;
				}
			}
			
			if (.@offline_found) {
				mes "[Santuario Smoke]";
				mes "Nem todos os membros estão online!";
				mes "Online: " + .@online_count + "/" + .@total_members;
				close;
			}
			
			// Todos os outros membros estão online
			mes "[Santuario Smoke]";
			mes "Todos os " + .@total_members + " membros estão online!";
			mes "Deseja teleportar todos agora?";
			next;
			
			if (select("Sim:Não") == 2) {
				close;
			} else {
				// ANTES de criar a instância, salve o líder e party em variáveis globais
				// .@party_id = getcharid(1);
				// .@leader_cid = getcharid(0);

				// Salva em variáveis globais para o controlador acessar depois
				// Salva no jogador
				// setd(".santuario_leader", getcharid(0));
				// setd(".santuario_party", getcharid(1));
				//--------------------------------------------------
				// CRIAR INSTANCIA (agora com segurança)
				//--------------------------------------------------
				.@instance_name$ = "Santuario Smoke";
				.@create = instance_create(.@instance_name$);
				.@party_id = getcharid(1);
				getpartymember .@party_id, 1;  // type 1 = AID
				setinstancevar ('PartySize, $@partymembercount, .@create);
				setinstancevar ('PartyID, getcharid(1), .@create);

				if (.@create < 0) {
					mes "[Santuario Smoke]";
					mes "Não foi possível criar a instância.";
					mes "Contate a administração.";
					close;
				}

				// Salva o líder e party para usar no controlador
				// .@party_id = getcharid(1);
				// .@leader_cid = getcharid(0);
				// setd(".santuario_leader_" + .@party_id, .@leader_cid);
				// setd(".santuario_party_" + .@party_id, .@party_id);

				mes "[Santuario Smoke]";
				mes "Instância criada! Teleportando todos...";
				close2;

				// Líder entra primeiro
				if (instance_enter(.@instance_name$) != 0) {
					// Se falhar, tenta limpar
					instance_destroy(.@instance_id);
					end;
				}

				// Teleporta os outros membros
				sleep2 500;
				// for (.@i = 0; .@i < $@partymembercount; .@i++) {
					// if ($@partymemberaid[.@i] != getcharid(3)) { // Ignora o líder
						// attachrid $@partymemberaid[.@i];
						// instance_enter .@instance_name$;
						// sleep2 200;
					// }
				// }
			}
		}
	}

	if (.@menu == 3) {
		// Cancelar
		mes "Tudo bem, volte quando estiver pronto para o desafio!";
		close;
	}
	
OnInit:

	//--------------------------------------------------
	// CONFIGURAÇÃO GERAL
	//--------------------------------------------------

	.InstanceName$ = "Santuario Smoke";

	.BaseMap$ = "pvp_arena";

	.InstanceTime = 7200;

	//--------------------------------------------------
	// PARTY
	//--------------------------------------------------

	//.RequireParty = true;

	.MinParty = 1;

	//--------------------------------------------------
	// POSIÇÃO DE SPAWN DOS PLAYERS
	//--------------------------------------------------

	.SpawnX = 50;
	.SpawnY = 35;

	//--------------------------------------------------
	// ÁREA DE SPAWN DOS MOBS
	//--------------------------------------------------

	.SpawnX1 = 32;
	.SpawnY1 = 67;

	.SpawnX2 = 67;
	.SpawnY2 = 32;

	//--------------------------------------------------
	// FASES
	//--------------------------------------------------

	.InitialMaxStage = 10;

	.HardStageLimit = 100;

	.StageTime = 60;

	.ChatroomTime = 30;

	//--------------------------------------------------
	// MOBS
	//--------------------------------------------------

	.MobID = -1; // ID do mob spawnado = -1, sendo qualquer mob normal aleatório

	.BaseMobCount = 10; // Quantidade Base de Mobs
	
	.MobPerPlayer = 5; // Quantidade de Mobs Extras por Player
	
	.MaxMobCount = 100; // Limite Máxima de Mobs

	//--------------------------------------------------
	// RECOMPENSAS
	//--------------------------------------------------

	.CoinVar$ = "#SantuarioCoin";

	.CoinPerMob = 1;

	.CoinPerKillBonus = 1;

	.CoinPerStage = 10;

	end;
}
// NPC dentro da instância
pvp_arena,49,51,6	script	Santuario Smoke#start	588,{
    mes "[Santuario Smoke]";
    mes "Deseja iniciar o desafio agora?";
	next;
	switch(select("Sim.:Não.")) {
	case 1:
		if (getpartyleader(getcharid(1), 2) != getcharid(0)) {
			mes "[Santuario Smoke]";
			mes "Somente o líder da instância pode iniciar o desafio.";
			close;
		}
		
		// Inicia o desafio
		mes "[Santuario Smoke]";
		mes "Iniciando o desafio...";
		close2;
		
		// donpcevent instance_npcname("#SantuarioSmoke_Controller") + "::OnEnable";
		//enablenpc instance_npcname("#SantuarioSmoke_Controller");
		enablenpc instance_npcname("#SantuarioSmoke_Controller");
		donpcevent instance_npcname("#SantuarioSmoke_Controller") + "::OnEnable";
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
	.@instance_id = instance_id();
    .@instance_name$ = instance_live_info(ILI_NAME, .@instance_id);
    
    // SÓ ATIVA SE FOR A INSTÂNCIA DO SANTUÁRIO
    if (.@instance_name$ == "Santuario Smoke") {
		waitingroom "Clique aqui para iniciar!",0;
        enablenpc instance_npcname(strnpcinfo(0));
        //debugmes "Santuário ATIVADO: " + .@instance_name$;
    } else {
        // Se for da Arena, mantém desativado
        disablenpc instance_npcname(strnpcinfo(0));
        //debugmes "Santuário DESATIVADO (instância da Arena): " + .@instance_name$;
    }
    end;
}

// BLOCO 2 — CONTROLADOR DA INSTÂNCIA + CONFIGURAÇÕES INSTÂNCIADAS
//====================================================
// CONTROLADOR DA INSTÂNCIA
//====================================================
pvp_arena,0,0,0	script	#SantuarioSmoke_Controller	-1,{
//--------------------------------------------------
// INICIALIZAÇÃO DA INSTÂNCIA
//--------------------------------------------------
// Inicializações do Controlador da Instância
OnInit:
	.@instance_id = instance_id();
	// mapflags da instância
	.@map$ = strnpcinfo(4);

	setmapflag .@map$, mf_noreturn;
	setmapflag .@map$, mf_noteleport;
	setmapflag .@map$, mf_nowarp;
	setmapflag .@map$, mf_nowarpto;
	setmapflag .@map$, mf_nomemo;
	setmapflag .@map$, mf_noloot;
	setmapflag .@map$, mf_nobranch;
	setmapflag .@map$, mf_nopenalty;
	setmapflag .@map$, mf_partylock;
	setmapflag .@map$, mf_monster_noteleport;
	setmapflag .@map$, mf_loadevent;
	
    end;

OnInstanceInit:
	if (instance_id() <= 0){
		end;
	}
	.@instance_name$ = instance_live_info(ILI_NAME, instance_id());
    if (.@instance_name$ != "Santuario Smoke") {
		end;
	}
	// initnpctimer;
    // startnpctimer;
	end;

// Evento que o NPC Start chama
OnEnable:
	stopnpctimer;  // limpa qualquer timer antigo
    debugmes "[DEBUG] OnEnable: limpando timers antigos e iniciando fluxo.";
    initnpctimer;
    startnpctimer;  // ou addtimer se preferir
	end;

// OnTimer1000:
	// mapannounce strnpcinfo(4),"[Santuario Smoke] Desafio iniciado pelo líder!",bc_all;
	// end;

OnTimer5000:
	stopnpctimer;
	mapannounce strnpcinfo(4),"[Santuario Smoke] Desafio iniciado pelo líder!",bc_all;
    // Agora chama o OnStartStage
    donpcevent instance_npcname("#SantuarioSmoke_Controller") + "::OnStartStage";
	//donpcevent strnpcinfo(0) + "::OnStartStage";
    end;

//--------------------------------------------------
// INÍCIO DE UMA FASE
//--------------------------------------------------

OnStartStage:
    stopnpctimer;                                   // limpa qualquer timer antigo
    .@instance_id = instance_id();
    if (.@instance_id <= 0) {
        debugmes "[CRÍTICO] OnStartStage chamado fora da instância!";
        end;
    }
	
	debugmes "[DEBUG] OnStartStage iniciado - ID: " + .@instance_id;
	
    // PROTEÇÃO ANTI-LOOP
    if (getinstancevar('PhaseRunning, .@instance_id) == 1) {
        debugmes "[DEBUG] Fase já rodando - ignorando chamada duplicada";
        end;
    }
    setinstancevar ('PhaseRunning, 1, .@instance_id);

    debugmes "[DEBUG] OnStartStage OK - Instance ID: " + .@instance_id;

    // === SEU CÓDIGO ORIGINAL (mantido) ===
    .@stage = getinstancevar('Stage, .@instance_id);
    if (.@stage < 1) {
        setinstancevar ('Stage, 1, .@instance_id);
        setinstancevar ('MaxStage, getvariableofnpc(.InitialMaxStage, "Santuario Smoke"), .@instance_id);
        setinstancevar ('TotalKills, 0, .@instance_id);
        setinstancevar ('TotalCoins, 0, .@instance_id);
        setinstancevar ('TopKillerAID, 0, .@instance_id);
        setinstancevar ('TopKills, 0, .@instance_id);
        setinstancevar ('WorstKillerAID, 0, .@instance_id);
        setinstancevar ('WorstKills, 999999, .@instance_id);
        setinstancevar ('Ending, 0, .@instance_id);
    }

    .@stage = getinstancevar('Stage, .@instance_id);
    .@map$ = strnpcinfo(4);
    mapannounce .@map$, "[Santuario Smoke] Fase "+.@stage+" começou!", bc_all;

    // tamanho da party
    .@players = getinstancevar('PartySize, .@instance_id);
    if (.@players < 1) .@players = 1;

    // cálculo de mobs
    .@mobcount = getvariableofnpc(.BaseMobCount,"Santuario Smoke")
               + (.@players * getvariableofnpc(.MobPerPlayer,"Santuario Smoke"))
               + (.@stage * 2);
    if (.@mobcount > getvariableofnpc(.MaxMobCount,"Santuario Smoke"))
        .@mobcount = getvariableofnpc(.MaxMobCount,"Santuario Smoke");

    setinstancevar ('MobTarget, .@mobcount, .@instance_id);
    setinstancevar ('StageKills, 0, .@instance_id);

    // spawn
    donpcevent strnpcinfo(0) + "::OnSpawnStageMobs";

    // INICIA O TIMER DA FASE (60 segundos)
    initnpctimer;
    startnpctimer;
	
	debugmes "[DEBUG] OnStartStage finalizado - timer iniciado.";
end;


//--------------------------------------------------
// AVISO FINAL DA FASE
//--------------------------------------------------

//OnStageTimeWarning:
OnTimer60000:
    stopnpctimer;
    .@instance_id = instance_id();
    if (.@instance_id <= 0) end;

    donpcevent strnpcinfo(0) + "::OnEndStage";
end;


//--------------------------------------------------
// FINAL DA FASE
//--------------------------------------------------

OnEndStage:
    .@instance_id = instance_id();
    if (.@instance_id <= 0) end;

    .@map$ = strnpcinfo(4);
    killmonsterall .@map$;
    mapannounce .@map$, "[Santuario Smoke] Fase concluída!", bc_all;

    // recompensa de fase (seu código original)
    .@party_id = getinstancevar('PartyID, .@instance_id);
    if (.@party_id > 0) {
        getpartymember .@party_id, 1;
        for (.@i = 0; .@i < $@partymembercount; .@i++) {
            if (isloggedin($@partymemberaid[.@i], $@partymembercid[.@i])) {
                attachrid $@partymemberaid[.@i];
                if (!isdead()) {
                    setd getvariableofnpc(.CoinVar$,"Santuario Smoke"),
                         getd(getvariableofnpc(.CoinVar$,"Santuario Smoke")) + getvariableofnpc(.CoinPerStage,"Santuario Smoke");
                }
            }
        }
    }

    // avança fase
    .@stage = getinstancevar('Stage, .@instance_id) + 1;
    setinstancevar ('Stage, .@stage, .@instance_id);
    setinstancevar ('PhaseRunning, 0, .@instance_id);   // libera para próxima fase

    donpcevent strnpcinfo(0) + "::OnNextStageCheck";
end;


//--------------------------------------------------
// CHECAR SE CONTINUA
//--------------------------------------------------

OnNextStageCheck:
    .@instance_id = instance_id();
    if (.@instance_id <= 0) end;

    .@stage = getinstancevar('Stage, .@instance_id);
    .@max   = getinstancevar('MaxStage, .@instance_id);
    .@hard  = getvariableofnpc(.HardStageLimit,"Santuario Smoke");

    if (.@stage > .@hard) {
        donpcevent strnpcinfo(0) + "::OnEndInstance";
        end;
    }

    if (.@stage > .@max) {
        setinstancevar ('MaxStage, .@max + 10, .@instance_id);
        mapannounce strnpcinfo(4), "[Santuario Smoke] O desafio continua! Novas fases liberadas!", bc_all;
    }

    sleep 2000;  // 2 segundos - ajustável, mas essencial

    donpcevent strnpcinfo(0) + "::OnStartStage";
end;



// BLOCO 3 — SISTEMA DE SPAWN E MORTE DOS MOBS
//--------------------------------------------------
// SPAWN DOS MOBS DA FASE
//--------------------------------------------------

OnSpawnStageMobs:
	//.@instance_id = getarg(0);
	.@map$ = strnpcinfo(4);
	.@instance_id = instance_id();
	.@target = getinstancevar('MobTarget,.@instance_id);
	.@stage = getinstancevar('Stage,.@instance_id);
	
	areamonster .@map$, getvariableofnpc(.SpawnX1,"Santuario Smoke"), getvariableofnpc(.SpawnY1,"Santuario Smoke"), getvariableofnpc(.SpawnX2,"Santuario Smoke"), getvariableofnpc(.SpawnY2,"Santuario Smoke"), "Variante Smoke F"+.@stage, getvariableofnpc(.MobID,"Santuario Smoke"), .@target, strnpcinfo(0) + "::OnMobDead";

	end;



//--------------------------------------------------
// MOB MORTO
//--------------------------------------------------

OnMobDead:
	//.@instance_id = getarg(0);
	.@instance_id = instance_id();
	//--------------------------------------------------
	// CONTADORES
	//--------------------------------------------------
	.@StageKills = getinstancevar('StageKills, .@instance_id);
	
	setinstancevar('StageKills, .@StageKills + 1, .@instance_id);
	
	.@TotalKills = getinstancevar('TotalKills, .@instance_id);
	setinstancevar('TotalKills, .@TotalKills + 1, .@instance_id);


	//--------------------------------------------------
	// RESPAWN AUTOMÁTICO (SPAWN INTELIGENTE)
	//--------------------------------------------------

	.@map$ = strnpcinfo(4);

	.@x = rand(getvariableofnpc(.SpawnX1,"Santuario Smoke"),getvariableofnpc(.SpawnX2,"Santuario Smoke"));
	.@y = rand(getvariableofnpc(.SpawnY2,"Santuario Smoke"),getvariableofnpc(.SpawnY1,"Santuario Smoke"));

	monster .@map$, .@x,.@y, "Variante Smoke F"+getinstancevar("Stage", .@instance_id), getvariableofnpc(.MobID,"Santuario Smoke"), 1, strnpcinfo(0) + "::OnMobDead";


	//--------------------------------------------------
	// RECOMPENSA PARA PARTY
	//--------------------------------------------------

	.@party_id = getinstancevar('PartyID, .@instance_id);
	if (.@party_id > 0) {
		getpartymember .@party_id, 1;
		for (.@i = 0; .@i < $@partymembercount; .@i++) {

			if (isloggedin($@partymemberaid[.@i],$@partymembercid[.@i])) {

				attachrid $@partymemberaid[.@i];

				// apenas jogadores vivos recebem
				if (!isdead($@partymemberaid[.@i])) {

					setd getvariableofnpc(.CoinVar$,"Santuario Smoke"),
					getd(getvariableofnpc(.CoinVar$,"Santuario Smoke"))
					+ getvariableofnpc(.CoinPerMob,"Santuario Smoke");

				}
			}
		}
	}


	//--------------------------------------------------
	// BONUS PARA QUEM MATOU
	//--------------------------------------------------

	if (playerattached()) {

        if (!isdead(getcharid(3))) {

            setd getvariableofnpc(.CoinVar$,"Santuario Smoke"),
            getd(getvariableofnpc(.CoinVar$,"Santuario Smoke"))
            + getvariableofnpc(.CoinPerKillBonus,"Santuario Smoke");

        }

        //--------------------------------------------------
        // RANKING DE KILLS
        //--------------------------------------------------

        .@kills = getd("SantuarioKills");

        setd "SantuarioKills", .@kills + 1;

    }

	end;

// BLOCO 4 — CHATROOM OBRIGATÓRIA + RANKING
//--------------------------------------------------
// NPC DE PROGRESSÃO ENTRE FASES
//--------------------------------------------------

OnSpawnNextStageNPC:
	//.@instance_id = getarg(0);
	.@map$ = strnpcinfo(4);
	
	mapannounce strnpcinfo(4),"[Santuario Smoke] Procure a Caixa Smoke e a destrúa para prosseguir para a próxima fase!",bc_all;
	
	.@label_caixa$ = instance_npcname(strnpcinfo(0)) + "::OnStageNPC";
	monster .@map$,50,55,"Caixa Smoke",30002,1,.@label_caixa$;

	end;


//--------------------------------------------------
// NPC COM CHATROOM
//--------------------------------------------------

OnStageNPC:
	//.@instance_id = getarg(0);
	// TAMANHO DA PARTY
	.@players = getinstancevar('PartySize, instance_id());
	
	mes "[Guardião do Santuário]";
	mes "Reúnam-se para prosseguir.";
	close2;

	waitingroom "Próxima Fase", .@players, strnpcinfo(0) + "::OnChatJoin";

	end;


//--------------------------------------------------
// JOGADOR ENTROU NA CHATROOM
//--------------------------------------------------

OnChatJoin:

	// nada acontece aqui
	end;


//--------------------------------------------------
// VERIFICAR SE TODOS ENTRARAM
//--------------------------------------------------

OnCheckPartyChat:
	//.@instance_id = getarg(0);
	.@players = getinstancevar('PartySize, instance_id());

	.@required = $@partymembercount;

	.@entered = getwaitingroomusers(strnpcinfo(0));

	if (.@entered < .@required) {

		.@map$ = strnpcinfo(4);

		mapannounce strnpcinfo(4),"[Santuario Smoke] Nem todos entraram na sala. A instância falhou!",bc_all;

		donpcevent strnpcinfo(0) + "::OnEndInstance";

		end;
	}

	donpcevent strnpcinfo(0) + "::OnStartStage";

	end;


//--------------------------------------------------
// ATUALIZAR RANKING
//--------------------------------------------------

OnUpdateRanking:
	//.@instance_id = getarg(0);
	.@players = getinstancevar('PartySize, instance_id());
	
	.@instance_id = instance_id();
	
	.@topkills = 0;
	.@worstkills = 999999;

	.@top$ = "";
	.@worst$ = "";

	for (.@i = 0; .@i < $@partymembercount; .@i++) {

		if (isloggedin($@partymemberaid[.@i],$@partymembercid[.@i])) {

			attachrid $@partymemberaid[.@i];

			.@kills = getd("SantuarioKills");

			if (.@kills > .@topkills) {

				.@topkills = .@kills;
				.@top$ = strcharinfo(0);

			}

			if (.@kills < .@worstkills) {

				.@worstkills = .@kills;
				.@worst$ = strcharinfo(0);

			}
		}
	}

	setinstancevar('TopPlayer$,.@top$,.@instance_id);
	setinstancevar('TopKills,.@topkills,.@instance_id);

	setinstancevar('WorstPlayer$,.@worst$,.@instance_id);
	setinstancevar('WorstKills,.@worstkills,.@instance_id);

	end;

// BLOCO 5 — FINALIZAÇÃO DA INSTÂNCIA E RESUMO
//--------------------------------------------------
// FINALIZAR INSTÂNCIA
//--------------------------------------------------

OnEndInstance:
	//.@instance_id = getarg(0);
	.@instance_id = instance_id();
	
	if (getinstancevar('Ending, .@instance_id))
		end;

	setinstancevar('Ending,1,.@instance_id);

	.@map$ = strnpcinfo(4);

	//--------------------------------
	// atualizar ranking
	//--------------------------------

	donpcevent strnpcinfo(0) + "::OnUpdateRanking";


	//--------------------------------
	// coletar dados
	//--------------------------------

	.@kills = getinstancevar('TotalKills,.@instance_id);
	.@stage = getinstancevar('Stage,.@instance_id);

	.@top$ = getinstancevar('TopPlayer$,.@instance_id);
	.@topkills = getinstancevar('TopKills,.@instance_id);

	.@worst$ = getinstancevar('WorstPlayer$,.@instance_id);
	.@worstkills = getinstancevar('WorstKills,.@instance_id);


	//--------------------------------
	// anunciar encerramento
	//--------------------------------

	mapannounce strnpcinfo(4),"[Santuario Smoke] A instância será encerrada.",bc_all;


	//--------------------------------
	// enviar resultados
	//--------------------------------

	.@players = getinstancevar('PartySize, instance_id());

	for (.@i = 0; .@i < $@partymembercount; .@i++) {

		if (isloggedin($@partymemberaid[.@i],$@partymembercid[.@i])) {

			attachrid $@partymemberaid[.@i];

			.@coins =
			getd(getvariableofnpc(.CoinVar$,"Santuario Smoke"));

			dispbottom "===== Santuario Smoke =====";
			dispbottom "Fases concluídas: "+(.@stage-1);
			dispbottom "Mobs eliminados: "+.@kills;
			dispbottom "Coins obtidas: "+.@coins;
			dispbottom " ";
			dispbottom "Maior Caçador: "+.@top$+" ("+.@topkills+" kills)";
			dispbottom "Menor Caçador: "+.@worst$+" ("+.@worstkills+" kills)";
			dispbottom "============================";

			set SantuarioKills,0;
		}
	}


	//--------------------------------
	// delay para garantir envio
	//--------------------------------

	sleep2 2000;


	//--------------------------------
	// teleportar todos
	//--------------------------------

	instance_warpall "prontera",156,191,.@instance_id;


	//--------------------------------
	// delay para garantir warp
	//--------------------------------

	sleep2 2000;


	//--------------------------------
	// destruir instância
	//--------------------------------

	instance_destroy;

	end;

//--------------------------------------------------
// PROTEÇÕES DA INSTÂNCIA
//--------------------------------------------------

OnPCLoadMapEvent:
	//.@instance_id = getarg(0);
	.@instance_id = instance_id();
	if (!.@instance_id)
		end;

	// VERIFICA SE É A INSTÂNCIA DO SANTUÁRIO
	.@instance_name$ = instance_live_info(ILI_NAME, .@instance_id);
	if (.@instance_name$ != "Santuario Smoke") {
		end;
	}

	// VERIFICA SE TEM JOGADOR ANEXADO
	if (!playerattached()) {
		end;
	}

	.@map$ = strnpcinfo(4);
	.@instance_id = instance_id();

	// GM pode entrar
	if (getgroupid() >= 99)
		end;

	//--------------------------------
	// player entrou na instância
	//--------------------------------

	if (strcharinfo(3) == .@map$) {

		// não pertence à party
		if (getcharid(1) != getinstancevar('PartyID, .@instance_id)) {

			dispbottom "Você não pertence a esta instância.";
			warp "prontera",156,191;
			end;
		}

		end;
	}

	//--------------------------------
	// líder saiu da instância
	//--------------------------------
	.@owner = instance_live_info(ILI_OWNER, instance_id(IM_PARTY));
	if (getcharid(0) == .@owner
	&& strcharinfo(3) != .@map$) {

		mapannounce strnpcinfo(4),"[Santuario Smoke] O líder saiu da instância. O desafio será encerrado.",bc_all;

		sleep2 3000;
		donpcevent strnpcinfo(0) + "::OnEndInstance";
	}

	end;

OnPCLogoutEvent:
	.@instance_id = instance_id();
	//.@instance_id = getarg(0);
	if (!.@instance_id)
		end;

	// VERIFICA SE É A INSTÂNCIA DO SANTUÁRIO
	.@instance_name$ = instance_live_info(ILI_NAME, .@instance_id);
	if (.@instance_name$ != "Santuario Smoke") {
		end;
	}

	// VERIFICA SE TEM JOGADOR ANEXADO
	if (!playerattached()) {
		end;
	}

	.@instance_id = instance_id();
	.@map$ = strnpcinfo(4);

	// líder
	.@owner = instance_live_info(ILI_OWNER, instance_id(IM_PARTY));
	if (getcharid(0) == .@owner) {

		mapannounce strnpcinfo(4),"[Santuario Smoke] O líder desconectou! Instância encerrada.",bc_all;

		sleep2 3000;
		donpcevent strnpcinfo(0) + "::OnEndInstance";
		end;
	}

	// players comuns
	warp "prontera",156,191;
	end;

OnPCDieEvent:
	.@instance_id = instance_id();
	//.@instance_id = getarg(0);
	if (!.@instance_id)
		end;

	// VERIFICA SE É A INSTÂNCIA DO SANTUÁRIO
	.@instance_name$ = instance_live_info(ILI_NAME, .@instance_id);
	if (.@instance_name$ != "Santuario Smoke") {
		end;
	}

	// VERIFICA SE TEM JOGADOR ANEXADO
	if (!playerattached()) {
		end;
	}

	.@map$ = strnpcinfo(4);
	
	.@owner = instance_live_info(ILI_OWNER, instance_id(IM_PARTY));
	if (getcharid(0) == .@owner) {

		mapannounce strnpcinfo(4),"[Santuario Smoke] O líder morreu! O desafio falhou.",bc_all;

		sleep2 3000;
		donpcevent strnpcinfo(0) + "::OnEndInstance";
	}

	end;	
}