mall01,99,135,4	script	Divindade	618,{

	// ============================
	// CONFIGURAÇÃO
	// ============================

	// GODLIKE
	.@g_armor  = 840055;
	.@g_mantle = 840056;
	.@g_boots  = 840057;

	// PHOENIX
	.@p_armor  = 840065;
	.@p_mantle = 840066;
	.@p_boots  = 840067;

	// AZUR
	.@a_armor  = 840075;
	.@a_mantle = 840076;
	.@a_boots  = 840077;

	// ASCENSION
	.@s_armor  = 840085;
	.@s_mantle = 840086;
	.@s_boots  = 840087;

	// ============================
	// CHECAR SE ESTÃO EQUIPADOS
	// ============================

	if (!getequipisequiped(EQI_ARMOR) ||
	    !getequipisequiped(EQI_GARMENT) ||
	    !getequipisequiped(EQI_SHOES)) {
		mes "Você precisa estar usando o set completo.";
		close;
	}

	.@idA = getequipid(EQI_ARMOR);
	.@idM = getequipid(EQI_GARMENT);
	.@idB = getequipid(EQI_SHOES);

	.@rA = getequiprefinerycnt(EQI_ARMOR);
	.@rM = getequiprefinerycnt(EQI_GARMENT);
	.@rB = getequiprefinerycnt(EQI_SHOES);

	// ============================
	// GODLIKE > PHOENIX
	// ============================

	if (.@idA == .@g_armor && .@idM == .@g_mantle && .@idB == .@g_boots) {

		if (.@rA != 5 || .@rM != 5 || .@rB != 5) {
			mes "Todas as peças GodLike precisam estar exatamente +5.";
			close;
		}

		.@nextA = .@p_armor;
		.@nextM = .@p_mantle;
		.@nextB = .@p_boots;
		.@zeny = 5000000;
	}

	// ============================
	// PHOENIX > AZUR
	// ============================

	else if (.@idA == .@p_armor && .@idM == .@p_mantle && .@idB == .@p_boots) {

		if (.@rA != 10 || .@rM != 10 || .@rB != 10) {
			mes "Todas as peças Phoenix precisam estar exatamente +10.";
			close;
		}

		.@nextA = .@a_armor;
		.@nextM = .@a_mantle;
		.@nextB = .@a_boots;
		.@zeny = 10000000;
	}

	// ============================
	// AZUR > ASCENSION
	// ============================

	else if (.@idA == .@a_armor && .@idM == .@a_mantle && .@idB == .@a_boots) {

		if (.@rA != 15 || .@rM != 15 || .@rB != 15) {
			mes "Todas as peças Azur precisam estar exatamente +15.";
			close;
		}

		.@nextA = .@s_armor;
		.@nextM = .@s_mantle;
		.@nextB = .@s_boots;
		.@zeny = 20000000;
	}

	else {
		mes "Você não está usando um set válido para evolução.";
		close;
	}

	// ============================
	// CHECAGEM DE RECURSOS
	// ============================

	if (countitem(840114) < 1) {
		mes "Você precisa de uma "+mesitemicon(840114);
		close;
	}

	if (Zeny < .@zeny) {
		mes "Você precisa de "+.@zeny+" zeny.";
		close;
	}

	if (checkweight(.@nextA,1) == 0 ||
	    checkweight(.@nextM,1) == 0 ||
	    checkweight(.@nextB,1) == 0) {
		mes "Você está com peso excessivo.";
		close;
	}

	mes "O poder divino consumirá seu set atual e o elevará ao próximo estágio.";
	mes "Deseja continuar?";
	next;

	if (select("Sim:Não") == 2) close;

	delitem 840114,1;
	Zeny -= .@zeny;

	item_reform(EQI_ARMOR,  .@nextA);
	item_reform(EQI_GARMENT,.@nextM);
	item_reform(EQI_SHOES,  .@nextB);

	mes "Seu set evoluiu com sucesso!";
	close;
}