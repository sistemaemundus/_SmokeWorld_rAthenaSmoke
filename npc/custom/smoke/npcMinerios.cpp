//===== rAthena Script =======================================
//= Sistema de Minérios
//===== Descrição: =========================================
//= 1. Leva para Área de de Farm de Minérios
//= 2. Recicla Minérios por #MineiroCoins
//= 3. Troca #MineiroCoins por Benção do Ferreiro
//============================================================

// Pointshop do MineiroCoins
-	shop	MineiroLoja	-1,6635:200

prontera,142,170,4	script	Minerador Jorge	848,{
	disable_items;
	
	mes "[Minerador Jorge]";
	mes "Bem-vindo ao programa de mineração";
	mes " ";
	mes "Posso te enviar para uma área exclusiva para farmar Minérios,";
	mes "trocar minérios que você não deseja por MineiroCoins,";
    mes "e também trocar MineiroCoins por alguns itens que podem te ajudar!";
	next;
	
	switch(select("Farmar Minéiros.:Reciclar Minérios.:Consultar meus pontos.:Trocar meus pontos.:Sair")) {
	case 1:
		clear;
        mes "[Minerador Jorge]";
        mes "Ok, vou te enviar para lá!";
        close2;
        warp "bossnia_02",138,119;
		end;
	case 2:
        clear;
        mes "[Minerador Jorge]";
        mes "Quais minérios eu reciclo? Segue a lista:";
        mes " ";
        mes "^00FF00Raridade 1 (1 ponto):^000000";
        mes mesitemicon(984) + " " + mesitemicon(6240) + " " + mesitemicon(6241) + " " + mesitemicon(7620) + " " + mesitemicon(7619) + " " + mesitemicon(985);
        mes " ";
        mes "^00FF00Raridade 2 (2 pontos):^000000";
        mes mesitemicon(6225) + " " + mesitemicon(6226) + " " + mesitemicon(6223) + " " + mesitemicon(6224);
        mes " ";
        mes "^00FF00Raridade 3 (3 pontos):^000000";
        mes mesitemicon(1000335) + " " + mesitemicon(1000336) + " " + mesitemicon(1000371) + " " + mesitemicon(1000369);
        mes mesitemicon(1000331) + " " + mesitemicon(1000332) + " " + mesitemicon(1000370) + " " + mesitemicon(1000368);
        mes mesitemicon(1000333) + " " + mesitemicon(1000334);
        next;
        mes "[Minerador Jorge]";
        mes "E aí, qual vai ser?";
        if(select("Vamos reciclar!", "Ops, me enganei") == 1) {
		    callsub S_RecycleMinerios;
		    break;
        } else {
            clear;
            mes "[Minerador Jorge]";
            mes "Tudo bem, me avise se mudar de ideia!";
            close;
        }
	case 3:
		callsub S_CheckMineiroCoins;
		break;
	case 4:
        clear;
		mes "[Minerador Jorge]";
		mes "Claro, aqui está!";
		close2;
        callshop "MineiroLoja",1;
	    npcshopattach "MineiroLoja";
        end;
    case 5:
		mes "[Minerador Jorge]";
		mes "Volte sempre que precisar!";
		close;
	}
	end;

OnBuyItem:
	for (.@i = 0; .@i < getarraysize(@bought_nameid); .@i++) {

		.@item = @bought_nameid[.@i];
		.@qtd  = @bought_quantity[.@i];

		// preço do item (define manualmente)
		switch (.@item) {
			case 6635: .@price = 200; break;
			default: .@price = 999999; break;
		}

		.@total = .@price * .@qtd;

		if (#MineiroCoins < .@total) {
			dispbottom "Pontos insuficientes!";
			end;
		}

		#MineiroCoins -= .@total;
		getitem .@item, .@qtd;
	}

	deletearray @bought_nameid;
	deletearray @bought_quantity;
	end;

S_RecycleMinerios:

	// Array de itens recicláveis
	setarray .@items[0],
		984,6240,6241,7620,7619,985,
		6225,6226,6223,6224,
		1000335,1000336,1000371,1000369,
		1000331,1000332,1000370,1000368,
		1000333,1000334;

	// Pontos por item (mesma ordem)
	setarray .@points[0],
		1,1,1,1,1,1,
		2,2,2,2,
		3,3,3,3,
		3,3,3,3,
		3,3;

	.@total_items = 20;

	mes "[Minerador Jorge]";
	mes "Quais minérios você quer reciclar?";
	mes "Cada minério gera pontos baseado na raridade.";
	mes " ";
	mes "^00FF00Raridade 1 = 1 ponto^000000";
	mes "^00FF00Raridade 2 = 2 pontos^000000";
	mes "^00FF00Raridade 3 = 3 pontos^000000";
	next;

	// Monta menu
	.@total_count = 0;
	.@menu$ = "";

	for(.@i = 0; .@i < .@total_items; .@i++) {
		.@count = countitem(.@items[.@i]);
		if(.@count > 0) {
			.@total_count++;
			.@menu$ += .@count + "x " + getitemname(.@items[.@i]) + ":";
		}
	}

	if(.@total_count == 0) {
		mes "[Minerador Jorge]";
		mes "Você não tem itens recicláveis.";
		close;
	}

	.@menu$ += "Reciclar TODOS os itens";

	.@option = select(.@menu$) - 1;

	// ================================
	// ?? RECICLAR TODOS
	// ================================
	if(.@option == .@total_count) {

		mes "[Minerador Jorge]";
		mes "Você vai reciclar:";
		mes " ";

		.@total_points = 0;

		for(.@i = 0; .@i < .@total_items; .@i++) {
			.@count = countitem(.@items[.@i]);
			if(.@count > 0) {
				.@p = .@points[.@i];
				mes .@count + "x " + getitemname(.@items[.@i]) + " (" + .@p + " pts)";
				.@total_points += (.@count * .@p);
			}
		}

		mes " ";
		mes "Total: ^FF0000" + .@total_points + " pontos^000000";
		next;

		if(select("Confirmar reciclagem", "Cancelar") == 1) {

			.@total_points = 0;

			for(.@i = 0; .@i < .@total_items; .@i++) {
				.@count = countitem(.@items[.@i]);
				if(.@count > 0) {
					delitem .@items[.@i], .@count;
					.@total_points += (.@count * .@points[.@i]);
				}
			}

			if(.@total_points > 0) {

				set #MineiroCoins, #MineiroCoins + .@total_points;

				dispbottom "=========================================";
				dispbottom "Reciclagem concluída!";
				dispbottom "Pontos ganhos: " + .@total_points;
				dispbottom "Total de pontos: " + #MineiroCoins;
				dispbottom "=========================================";

				mes "[Minerador Jorge]";
				mes "Você ganhou ^FF0000" + .@total_points + "^000000 pontos!";
				mes "Total atual: ^FF0000" + #MineiroCoins + "^000000.";
				close;
			}
		}

		mes "[Minerador Jorge]";
		mes "Reciclagem cancelada.";
		close;
	}

	// ================================
	// ?? ITEM INDIVIDUAL
	// ================================
	else {

		.@current_index = 0;

		for(.@i = 0; .@i < .@total_items; .@i++) {
			.@count = countitem(.@items[.@i]);
			if(.@count > 0) {
				if(.@current_index == .@option) {
					.@item_id = .@items[.@i];
					.@item_name$ = getitemname(.@item_id);
					.@item_points = .@points[.@i];
					break;
				}
				.@current_index++;
			}
		}

		.@count = countitem(.@item_id);

		mes "[Minerador Jorge]";
		mes "Quantos deseja reciclar?";
		mes "Você tem: " + .@count;
		mes "Valor: " + .@item_points + " ponto(s) cada.";
		next;

		input .@amount;

		if(.@amount > 0 && .@amount <= .@count) {

			.@total_points = (.@amount * .@item_points);

			mes "[Minerador Jorge]";
			mes "Confirmar:";
			mes "^FF0000" + .@amount + "x " + .@item_name$ + "^000000";
			mes "Total: ^FF0000" + .@total_points + " pontos^000000";
			next;

			if(select("Confirmar reciclagem", "Cancelar") == 1) {

				delitem .@item_id, .@amount;

				set #MineiroCoins, #MineiroCoins + .@total_points;

				dispbottom "=========================================";
				dispbottom "Reciclagem concluída!";
				dispbottom "Pontos ganhos: " + .@total_points;
				dispbottom "Total de pontos: " + #MineiroCoins;
				dispbottom "=========================================";

				mes "[Minerador Jorge]";
				mes "Você ganhou ^FF0000" + .@total_points + "^000000 pontos!";
				mes "Total atual: ^FF0000" + #MineiroCoins + "^000000.";
				close;
			}
		}
	}

	mes "[Minerador Jorge]";
	mes "Operação cancelada.";
	close;
	
S_CheckMineiroCoins:
	mes "[Minerador Jorge]";
	mes "Aqui está seu saldo atual:";
	mes " ";
	mes "^FF0000Mineiro Coins:^000000 " + #MineiroCoins;
	mes " ";
	mes "Continue reciclando para acumular";
	mes "mais pontos!";
	close;
}
-	script	Minerio	-1,{
	OnThisMobDeath:

		// Itens
		setarray .@items,
			984,6240,6241,7620,7619,985,
			6225,6226,6223,6224,
			1000335,1000336,1000371,1000369,
			1000331,1000332,1000370,1000368,
			1000333,1000334;

		// Pesos (raridade)
		setarray .@weight,
			1,1,1,1,1,1,
			2,2,2,2,
			3,3,3,3,
			3,3,3,3,
			3,3;

		.@total = 20;

		// Soma total dos pesos
		.@max = 0;
		for(.@i = 0; .@i < .@total; .@i++) {
			.@max += .@weight[.@i];
		}

		// Sorteio
		.@rand = rand(.@max);

			.@sum = 0;
			for(.@i = 0; .@i < .@total; .@i++) {
				.@sum += .@weight[.@i];
				if(.@rand < .@sum) {
					// Escolha do item
					if (checkweight(.@items[.@i], 1) == 0) {
						// Se não tiver espaço ou peso suficiente
						dispbottom "Você não tem espaço ou peso suficiente para receber o item!";
						break;
					} else {
						getitem .@items[.@i], 1;
						//monster bossnia_02,0,0,"Mineral",1614,1,"Minerio::OnThisMobDeath";
						break;
					}
				}
			}
	end;

}
// Mobs da Área de Minérios
bossnia_02,0,0	monster	Mineral	1614,100,1000,1000,"Minerio::OnThisMobDeath"

// MapFlags da Farm de Minérios
bossnia_02	mapflag	noloot	on
bossnia_02	mapflag	noteleport	on
bossnia_02	mapflag	nosave	on
bossnia_02	mapflag	nomemo	on