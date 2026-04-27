//===Criado por Emundus
//= dispbottom dos conjuntos ativos no personagem.
-	script	checkSet	-1,{
	OnInit:
		bindatcmd "checkset",strnpcinfo(0) + "::OnAtcommand";
		end;
	OnAtcommand:
		.@ativo = 0;

		// =========================
		// GODLIKE
		// =========================

		if (isequipped(840055) && isequipped(840056) && isequipped(840057)) {
			dispbottom "| GodLike - Tier I |",0xFFFF00;
			dispbottom "ATK +15% | MATK +15%",0xFFFF00;
			dispbottom "Dano em Boss +8%",0xFFFF00;
			.@ativo = 1;
		}
		else if (isequipped(840071) && isequipped(840073) && isequipped(840075)) {
			dispbottom "| GodLike - Tier II |",0xFFFF00;
			dispbottom "ATK +25% | MATK +25%",0xFFFF00;
			dispbottom "Dano em Boss +12%",0xFFFF00;
			.@ativo = 1;
		}
		else if (isequipped(840072) && isequipped(840074) && isequipped(840076)) {
			dispbottom "| GodLike - Tier III |",0xFFFF00;
			dispbottom "ATK +35% | MATK +35%",0xFFFF00;
			dispbottom "Dano em Boss +18%",0xFFFF00;
			.@ativo = 1;
		}

		// =========================
		// PHOENIX
		// =========================

		if (isequipped(840058) && isequipped(840059) && isequipped(840060)) {
			dispbottom "| Phoenix - Tier I |",0xFF3300;
			dispbottom "ATK +35% | MATK +35%",0xFF3300;
			dispbottom "Dano em Boss +15%",0xFF3300;
			.@ativo = 1;
		}
		else if (isequipped(840077) && isequipped(840078) && isequipped(840079)) {
			dispbottom "| Phoenix - Tier II |",0xFF3300;
			dispbottom "ATK +50% | MATK +50%",0xFF3300;
			dispbottom "Dano em Boss +22%",0xFF3300;
			.@ativo = 1;
		}
		else if (isequipped(840080) && isequipped(840081) && isequipped(840082)) {
			dispbottom "| Phoenix - Tier III |",0xFF3300;
			dispbottom "ATK +65% | MATK +65%",0xFF3300;
			dispbottom "Dano em Boss +28%",0xFF3300;
			.@ativo = 1;
		}

		// =========================
		// AZUR
		// =========================

		if (isequipped(840061) && isequipped(840062) && isequipped(840063)) {
			dispbottom "| Azur - Tier I |",0x3399FF;
			dispbottom "ATK +70% | MATK +70%",0x3399FF;
			dispbottom "Dano em Boss +25%",0x3399FF;
			.@ativo = 1;
		}
		else if (isequipped(840083) && isequipped(840084) && isequipped(840085)) {
			dispbottom "| Azur - Tier II |",0x3399FF;
			dispbottom "ATK +70% | MATK +70%",0x3399FF;
			dispbottom "Dano em Boss +25%",0x3399FF;
			.@ativo = 1;
		}
		else if (isequipped(840086) && isequipped(840087) && isequipped(840088)) {
			dispbottom "| Azur - Tier III |",0x3399FF;
			dispbottom "ATK +105% | MATK +105%",0x3399FF;
			dispbottom "Dano em Boss +38%",0x3399FF;
			.@ativo = 1;
		}

		// =========================
		// ASCENSION
		// =========================

		if (isequipped(840064) && isequipped(840065) && isequipped(840066)) {
			dispbottom "| Ascension - Tier I |",0x9900FF;
			dispbottom "ATK +90% | MATK +90%",0x9900FF;
			dispbottom "Dano em Boss +35%",0x9900FF;
			.@ativo = 1;
		}
		else if (isequipped(840089) && isequipped(840090) && isequipped(840091)) {
			dispbottom "| Ascension - Tier II |",0x9900FF;
			dispbottom "ATK +120% | MATK +120%",0x9900FF;
			dispbottom "Dano em Boss +48%",0x9900FF;
			.@ativo = 1;
		}
		else if (isequipped(840092) && isequipped(840093) && isequipped(840094)) {
			dispbottom "| Ascension - Tier III |",0x9900FF;
			dispbottom "ATK +140% | MATK +140%",0x9900FF;
			dispbottom "Dano em Boss +55%",0x9900FF;
			.@ativo = 1;
		}

		// =========================
		// ASCENDED
		// =========================

		if (isequipped(smk_ascended_armor) && isequipped(smk_ascended_garment) && isequipped(smk_ascended_shoes)) {

			.@armor_card   = getequipcardid(EQI_ARMOR, 3);
			.@garment_card = getequipcardid(EQI_GARMENT, 3);
			.@boots_card   = getequipcardid(EQI_SHOES, 3);

			// Validação completa
			if (.@armor_card > 0 && .@garment_card > 0 && .@boots_card > 0 &&
				.@armor_card == .@garment_card && .@armor_card == .@boots_card) {

				dispbottom "| Ascended Set |",0x00FF99;

				// PHYSICAL
				if (.@armor_card == 840209) {
					dispbottom "Essência: Destruição Física",0x00FF99;
					dispbottom "ATK +200%",0x00FF99;
					dispbottom "Dano em Boss +20%",0x00FF99;
				}

				// RANGED
				else if (.@armor_card == 840210) {
					dispbottom "Essência: Tiro Preciso",0x00FF99;
					dispbottom "Dano à Distância +25%",0x00FF99;
					dispbottom "Precisão +50",0x00FF99;
				}

				// MAGIC
				else if (.@armor_card == 840211) {
					dispbottom "Essência: Arcana",0x00FF99;
					dispbottom "MATK +200%",0x00FF99;
					dispbottom "Dano em Boss +20%",0x00FF99;
				}

				// SUPPORT
				else if (.@armor_card == 840212) {
					dispbottom "Essência: Divina",0x00FF99;
					dispbottom "Cura +30%",0x00FF99;
					dispbottom "Pós-conjuração -15%",0x00FF99;
				}

				// HYBRID
				else if (.@armor_card == 840213) {
					dispbottom "Essência: Caos",0x00FF99;
					dispbottom "ATK +120% | MATK +120%",0x00FF99;
					dispbottom "ASPD +10%",0x00FF99;
				}

				// ELEMENTAL
				else if (.@armor_card == 840214) {
					dispbottom "Essência: Elemental Suprema",0x00FF99;
					dispbottom "Dano Elemental +20%",0x00FF99;
				}

				// =========================
				// REFINE BONUS
				// =========================

				.@total_refine = getequiprefinerycnt(EQI_ARMOR)
							+ getequiprefinerycnt(EQI_GARMENT)
							+ getequiprefinerycnt(EQI_SHOES);

				if (.@total_refine >= 60) {
					dispbottom "[Refino Total 60] +20 ALL STATS / +20 ALL TRAITS",0xFFD700;
				}
				else if (.@total_refine >= 45) {
					dispbottom "[Refino Total 45] +10 ALL STATS / +10 ALL TRAITS",0xFFD700;
				}
				else if (.@total_refine >= 30) {
					dispbottom "[Refino Total 30] +5 ALL STATS / +5 ALL TRAITS",0xFFD700;
				}

				.@ativo = 1;
			}
		}

		if (!.@ativo)
			dispbottom "Sem conjuntos Smoke ativos.",0xAAAAAA;

		end;
}