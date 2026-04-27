// npc: GM Account Points Manager - Alterar pontos de conta pelo nome do char (somente positivo)
vip_lounge,142,121,5	script	Gerente de Pontos	405,{

	// Solicita o nome do jogador
	mes "Digite o nome do jogador para gerenciar pontos:";
	input .@char_name$;

	if(.@char_name$ == "" || .@char_name$ == "0") {
		mes "Operação cancelada.";
		close;
	}

	// Pega account_id do char
	query_sql("SELECT `account_id` FROM `char` WHERE `name` = '"+.@char_name$+"'", .@accid);

	if(.@accid == 0) {
		mes "Jogador não encontrado! Operação cancelada.";
		close;
	}

	mes "Encontrado jogador '"+.@char_name$+"' com account_id: "+.@accid;
	set .@choice, select("Cancelar\Confirmar");
	if(.@choice == 1) {
		mes "Operação cancelada.";
		close;
	}

	// Lista pontos
	set .@i,0;
	set .@points_list$, "";
	query_sql("SELECT `key`, `index`, `value` FROM `acc_reg_num` WHERE `account_id` = '"+.@accid+"' ORDER BY `index` ASC", .@key$, .@idx$, .@value$);
	while(.@i < getarraysize(.@key$)) {
		set .@points_list$, .@points_list$ + .@i + ": Key: "+.@key$[.@i]+" | Index: "+.@idx$[.@i]+" | Valor: "+.@value$[.@i]+"\n";
		set .@i,.@i+1;
	}

	mes "Pontos da conta do jogador '"+.@char_name$+"':";
	mes .@points_list$;

	// Escolha do ponto
	mes "Escolha o index do ponto que deseja alterar:";
	input .@point_index,0,getarraysize(.@key$)-1;

	set .@curr_value, .@value$[.@point_index];
	set .@selected_key$, .@key$[.@point_index];
	set .@selected_idx$, .@idx$[.@point_index];

	mes "Ponto selecionado: Key: "+.@selected_key$+" | Index: "+.@selected_idx$+" | Valor atual: "+.@curr_value;

	// Delta positivo
	mes "Digite o valor a aumentar (+X, 0 para cancelar):";
	input .@delta$;

	if(.@delta$ == "0" || .@delta$ == "+0") {
		mes "Alteração cancelada.";
		close;
	}

	set .@delta, atoi(.@delta$);

	if(.@delta < 0) {
		mes "Negativo não permitido. Operação cancelada.";
		close;
	}

	set .@new_value, .@curr_value + .@delta;

	// Confirmação
	mes "Confirma alteração do ponto da conta?";
	mes "Key: "+.@selected_key$+" | Index: "+.@selected_idx$+" | Valor atual: "+.@curr_value+" | Novo valor: "+.@new_value;

	set .@choice, select("Cancelar\Confirmar");
	if(.@choice == 2) {
		query_sql("UPDATE `acc_reg_num` SET `value` = "+.@new_value+" WHERE `account_id` = '"+.@accid+"' AND `key` = '"+.@selected_key$+"' AND `index` = "+.@selected_idx$);
		mes "Valor atualizado com sucesso!";
	} else {
		mes "Alteração cancelada.";
	}

	close;
}