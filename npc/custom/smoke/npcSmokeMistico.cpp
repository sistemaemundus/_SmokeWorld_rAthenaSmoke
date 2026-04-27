//====================================================
// NPC: Transformador de Itens de Cura para Aluguel
// Requer: Ticket Smoke Místico (ID: 840194)
//====================================================
mall01,83,107,5	script	Alugador de Poções	621,{

	disable_items;

	// Variáveis
	.menu$ = "";
	.selected_item = 0;
	.selected_item_id = 0;
	.selected_item_name$ = "";
	.selected_item_amount = 0;
	.ticket_id = 840194;

	// Cabeçalho
	mes "[Alugador de Poções]";
	mes "Olá, aventureiro!";
	mes "Posso transformar seus ^3355FFitens de cura^000000 em uma versão alugada por 1 dia.";
	mes "";
	mes "Para isso, você precisará de um";
	mes "^32CD32Ticket Smoke Místico^000000 ("+mesitemicon(.ticket_id)+").";
	mes "^DC143CObservação: Você transformará TODAS as unidades do item em apenas 1 unidade do item como alugado.^000000";
	next;

	// Verificar se possui o ticket
	if (countitem(.ticket_id) < 1) {
		mes "[Alugador de Poções]";
		mes "Você não possui o ticket necessário!";
		mes "Volte quando tiver um ^32CD32Ticket Smoke Místico^000000.";
		close;
	}

	// Listar itens de cura
	callsub L_ListarItensCura;

	// Se não houver itens
	if (.menu$ == "") {
		mes "[Alugador de Poções]";
		mes "Você não possui nenhum item de cura no inventário.";
		mes "Itens de cura incluem: poções, comidas curativas, frutas, etc.";
		close;
	}

	// Menu
	mes "[Alugador de Poções]";
	mes "Escolha qual item de cura deseja transformar em aluguel:";
	mes "--------------------------------";

	.menu$ += "Cancelar";

	.selected = select(.menu$);

	if (.selected > getarraysize(.item_list)) {
		mes "[Alugador de Poções]";
		mes "Entendo. Se mudar de ideia, estarei aqui!";
		close;
	}

	.selected--;

	.selected_item_id = .item_list[.selected];
	.selected_item_name$ = .item_name$[.selected];
	.selected_item_amount = .item_amount[.selected];
	
	// verificar se já tem alugado
	if (callsub(L_TemItemAlugado, .selected_item_id)) {
		next;
		mes "[Alugador de Poções]";
		mes "Você já possui uma versão ^FF0000alugada^000000 deste item.";
		mes "Espere ela expirar antes de criar outra.";
		close;
	}
	
	// Confirmação
	next;
	mes "[Alugador de Poções]";
	mes "Item selecionado: ^3355FF" + .selected_item_name$ + "^000000";
	mes "Quantidade total que você possui: ^FF0000" + .selected_item_amount + "^000000";
	mes "";
	mes "ATENÇÃO: Todas as " + .selected_item_amount + " unidades";
	mes "serão REMOVIDAS do seu inventário!";
	mes "";
	mes "Em troca, você receberá:";
	mes "^3355FF1x " + .selected_item_name$ + " (Alugado por 1 dia)^000000";
	mes "";
	mes "1x Ticket Smoke Místico será consumido.";
	next;

	switch(select("Sim, quero transformar TUDO: Não, cancelar")) {

	case 1:

		if (countitem(.ticket_id) < 1) {
			mes "[Alugador de Poções]";
			mes "Você não possui mais o ticket necessário!";
			close;
		}

		.current_amount = countitem(.selected_item_id);

		if (.current_amount <= 0) {
			mes "[Alugador de Poções]";
			mes "Você não possui mais este item!";
			close;
		}

		if (.current_amount < .selected_item_amount) {

			mes "[Alugador de Poções]";
			mes "A quantidade deste item mudou desde sua última consulta.";
			mes "Quantidade atual: " + .current_amount;
			next;

			if (select("Sim, transformar tudo: Não, cancelar") == 2) {
				mes "[Alugador de Poções]";
				mes "Operação cancelada.";
				close;
			}
		}

		// Consumir ticket
		delitem .ticket_id, 1;

		// Remover itens
		delitem .selected_item_id, .current_amount;

		// Dar item alugado (24h)
		rentitem .selected_item_id, 86400;

		mes "[Alugador de Poções]";
		mes "Transformação concluída com sucesso!";
		mes "";
		mes "Itens removidos: ^FF0000" + .current_amount + "x^000000 " + .selected_item_name$;
		mes "Item recebido: ^3355FF1x " + .selected_item_name$ + " (Alugado)^000000";
		mes "Ticket consumido: ^32CD321x Ticket Smoke Místico^000000";
		mes "";
		mes "O item alugado durará 1 dia (24 horas).";
		mes "Use /rentitem para verificar o tempo restante.";
		break;

	case 2:

		mes "[Alugador de Poções]";
		mes "Sem problemas. Escolha outro item quando quiser!";
		break;
	}

	close;


	//====================================================
	// Subrotina: Listar itens de cura
	//====================================================
	L_ListarItensCura:

	deletearray .item_list;
	deletearray .item_name$;
	deletearray .item_amount;

	.count = 0;

	getinventorylist;

	for (.@i = 0; .@i < @inventorylist_count; .@i++) {

		.@item_id = @inventorylist_id[.@i];
		.@amount  = @inventorylist_amount[.@i];
		.@type    = getiteminfo(.@item_id, ITEMINFO_TYPE);

		// Ignorar itens alugados ou bound
		if (@inventorylist_expire[.@i] > 0 || @inventorylist_expiretime[.@i] > 0 || @inventorylist_bound[.@i])
			continue;
		
		// Apenas itens de cura
		if (.@type == IT_HEALING) {

			.item_list[.count]   = .@item_id;
			.item_name$[.count]  = getitemname(.@item_id);
			.item_amount[.count] = .@amount;

			.count++;
		}
	}

	if (.count == 0) {
		.menu$ = "";
		return;
	}

	.menu$ = "";

	for (.@i = 0; .@i < .count; .@i++) {
		.menu$ += .item_name$[.@i] + " (" + .item_amount[.@i] + "):";
	}

	return;
	
	//====================================================
	// Verificar se já possui versão alugada do item
	//====================================================
	L_TemItemAlugado:

	getinventorylist;

	for (.@i = 0; .@i < @inventorylist_count; .@i++) {

		if (@inventorylist_id[.@i] == getarg(0)) {

			if (@inventorylist_expire[.@i] > 0 || @inventorylist_expiretime[.@i] > 0 || @inventorylist_bound[.@i]) {
				return 1;
			}
		}
	}

	return 0;
}