//= Criado por Alek Emundus - @sistemaemundus
//= Guia para teleportar o jogador para locais custom
-	script	GuiasSmokeRO	-1,{
	OnInit:
		bindatcmd "guia",strnpcinfo(0) + "::OnAtcommand";
		end;
	OnAtcommand:
		mes "[Guia]";
		mes "Olá, " + strcharinfo(0) + " serei seu guia para sua aventura!";
		mes "Escolha para onde deseja ir:";

		.@menu$ = "- Quests/Trocas.:- Local de Treino.";

		if (getgroupid() >= 99) {
			.@menu$ += ":- Área GM.";
		}

		.@menu$ += ":- Cancelar";

		switch(select(.@menu$)){

			case 1:
				warp "mall01",99,83;
				end;

			case 2:
				warp "prontera",233,80;
				end;

			case 3:
				if (getgroupid() >= 99) {
					warp "vip_lounge",150,131;
					end;
				}
				// se não for GM, case 3 vira Cancelar
				clear;
				mes "[Guia]";
				mes "Até mais!";
				close2;
				end;

			case 4:
				clear;
				mes "[Guia]";
				mes "Até mais!";
				close2;
				end;
		}
}
//= Warps Guias
mall01,99,76,0	warp	guia_w1	1,1,prontera,156,191
prontera,170,168,0	warp	guia_w2	1,1,mall01,99,83

//= NPC Guias SmokeRO
prontera,154,187,5	script	Guia	619,{
	mes "[Guia]";
	mes "Olá, " + strcharinfo(0) + " serei seu guia para sua aventura!";
	mes "Escolha para onde deseja ir:";

	.@menu$ = "- Quests/Trocas.:- Local de Treino.";

	if (getgroupid() >= 99) {
		.@menu$ += ":- Área GM.";
	}

	.@menu$ += ":- Cancelar";

	switch(select(.@menu$)){

		case 1:
			warp "mall01",99,83;
			end;

		case 2:
			warp "prontera",233,80;
			end;

		case 3:
			if (getgroupid() >= 99) {
				warp "vip_lounge",150,131;
				end;
			}
			// se não for GM, case 3 vira Cancelar
			clear;
			mes "[Guia]";
			mes "Até mais!";
			close2;
			end;

		case 4:
			clear;
			mes "[Guia]";
			mes "Até mais!";
			close2;
			end;
	}
}
