//=============================
//=Criado por Emundus
//=============================
//=Jobs: Monk, Wizard, Gunslinger/Rebellion, Ninja/KagerouOboro, Alchemist, Blacksmith, Novice/SuperNovice, Hunter, BardDancer, Knight, Crusader, Sage, Summoner/Spirit_handler, Assassin, Priest, Rogue

prontera,142,181,5	script	Aventureira Mestre	638,{

	set .@gear_ticket, 25427;
	set .@refine_ticket, 25428;

	mes "[Aventureira Mestre]";
	mes "Olá, "+strcharinfo(0);
	mes "Em que posso ajudar?";
	next;

	switch(select("- Trocar Ticket de Equipamentos:- Trocar Ticket de Refino:- Trocar Tickets Booster:- Cancelar")) {

		// ===================================
		// OPÇÃO 1 – EQUIPAMENTOS POR JOB BASE
		// ===================================
		case 1:

			if (countitem(.@gear_ticket) < 1) {
				mes "[Aventureira Mestre]";
				mes "Ah, vejo que você não tem um "+mesitemlink(.@gear_ticket)+" em mãos.";
				mes "Volte quando tiver um para trocar por equipamentos de acordo com sua classe base!";
				close;
			}

			.@job = BaseClass;

			// Distribuição das 16 armas por classe base
			if (.@job == Job_Acolyte) {
				getitem "Rebeginer_AB_Bible",1;      // 28616 - Priest
			}
			else if (.@job == Job_Mage) {
				getitem "Rebeginer_WL_Staff",1;       // 2046 - Wizard
			}
			else if (.@job == Job_Archer) {
				getitem "Rebeginer_RN_Bow",1;         // 18165 - Hunter
			}
			else if (.@job == Job_Swordman) {
				getitem "Rebeginer_RK_T_Sword",1;     // 21037 - Knight
			}
			else if (.@job == Job_Merchant) {
				getitem "Rebeginer_NC_Mace",1;        // 16075 - Blacksmith
			}
			else if (.@job == Job_Thief) {
				// Precisa decidir: Assassin ou Rogue?
				// Vou colocar ambos como opção, você escolhe:
				getitem "Rebeginer_GC_Katar",1;       // 28027 - Assassin
				getitem "Rebeginer_SC_Dagger",1;      // 28740 - Rogue (opção alternativa)
			}
			else if (.@job == Job_Gunslinger) {
				getitem "Rebeginer_RL_Gun",1;         // 13144 - Gunslinger/Rebellion
			}
			else if (.@job == Job_Ninja) {
				getitem "Rebeginer_KO_Humma",1;       // 13341 - Ninja/KagerouOboro
			}
			else if (.@job == Job_Summoner) {
				getitem "Rebeginer_DO_Rod",1;         // 26120 - Summoner/Spirit Handler
			}
			else if (.@job == Job_Bard || .@job == Job_Dancer) {
				getitem "Rebeginer_WM_Bow",1;         // 18166 - Bard/Dancer
			}
			else if (.@job == Job_Monk) {
				getitem "Rebeginer_SR_Nuckle",1;      // 1848 - Monk
			}
			else if (.@job == Job_Sage) {
				getitem "Rebeginer_SO_Rod",1;         // 26119 - Sage
			}
			else if (.@job == Job_Alchemist) {
				getitem "Rebeginer_GN_Sword",1;       // 13483 - Alchemist
			}
			else if (.@job == Job_Rogue) {
				getitem "Rebeginer_SC_Dagger",1;      // 28740 - Rogue
			}
			else if (.@job == Job_Crusader) {
				getitem "Rebeginer_LG_Lance",1;       // 26015 - Crusader
			}
			else if (.@job == Job_Novice || .@job == Job_SuperNovice) {
				getitem "Rebeginer_N2_Mace",1;        // 16076 - Novice/SuperNovice
			}
			else {
				mes "Sua classe não possui conjunto configurado.";
				close;
			}

			// Itens comuns (se quiser)
			// getitem "Rebeginer_Suits",1;
			// getitem "Rebeginer_Cap",1;
			// getitem "Rebeginer_Manteau",1;
			// getitem "Rebeginer_Boots",1;
			// getitem "Rebeginer_Ring",2;

			delitem .@gear_ticket,1;
			mes "Equipamentos entregues com sucesso!";
			close;


		// ===================================
		// OPÇÃO 2 – TICKET DE REFINE
		// ===================================
		case 2:

			if (countitem(.@refine_ticket) < 1) {
				mes "[Aventureira Mestre]";
				mes "Ah, vejo que você não tem um "+mesitemlink(.@refine_ticket)+" em mãos.";
				mes "Volte quando tiver um para poder trocar comigo!";
				close;
			}

			delitem .@refine_ticket,1;
			getitem 6230,1;

			mes "Você recebeu um "+mesitemlink(6230);
			close;
		
		// ===================================
		// OPÇÃO 3 – TICKETS BOOSTER (BARTER)
		// ===================================			
		case 3:
			
			clear;
			mes "[Aventureira Mestre]";
			mes "Caixas Boosters, hein?!";
			mes "Escolha sabiamente, pois uma vez escolhido não poderá voltar atrás!";
			switch(select("- Armas Booster.:- Armaduras Booster.:- Cancelar")) {
				case 1:
					clear;
					mes "[Aventureira Mestre]";
					mes "Escolheu as Armas Booster, uau, boa escolha...";
					mes "Escolha com calma, ok?";
					close2;
					callshop "boosterWeapons",1;
					end;
				case 2:
					clear;
					mes "[Aventureira Mestre]";
					mes "Escolheu as Armaduras Booster, excelente escolha...";
					mes "Aqui está, escolha com calma ok?!";
					close2;
					callshop "boosterArmors",1;
					end;
				case 3:
					clear;
					mes "[Aventureira Mestre]";
					mes "Decidiu cancelar, tudo bem!";
					close;
			}
		
		case 4:
			close;
	}
}