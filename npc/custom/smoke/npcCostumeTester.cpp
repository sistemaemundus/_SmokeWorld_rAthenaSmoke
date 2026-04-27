// Script: Sistema de Teste de Itens com Duração
// Localização: npc/custom/experiment_shop.txt

-	script	NPC_Teste_Itens	-1,{
OnInit:
	// Definição das arrays de itens para cada opção do menu
	// Array[0] = número total de itens, seguido pelos IDs dos itens
	setarray .menu_itens$[0], 16; // Total de 16 opções
	
	// Opção 1: Poções e consumíveis
	setarray .itens_opcao_1[0], 4, 501, 502, 503, 504; // 4 itens: Poção Vermelha, Poção Laranja, Poção Amarela, Poção Branca
	
	// Opção 2: Equipamentos para novatos
	setarray .itens_opcao_2[0], 3, 1201, 2301, 2101; // 3 itens: Adaga, Camisa, Capacete de Couro
	
	// Opção 3: Armas intermediárias
	setarray .itens_opcao_3[0], 5, 1301, 1401, 1501, 1601, 1701; // Espadas e armas diversas
	
	// Opção 4: Armaduras
	setarray .itens_opcao_4[0], 4, 2302, 2401, 2501, 2528; // Armaduras variadas
	
	// Opção 5: Acessórios
	setarray .itens_opcao_5[0], 3, 2601, 2602, 2603; // Brincos e anéis
	
	// Opção 6: Capas e escudos
	setarray .itens_opcao_6[0], 3, 2102, 2103, 2104; // Escudos
	
	// Opção 7: Poções especiais
	setarray .itens_opcao_7[0], 4, 505, 506, 507, 508; // Poções Azuis e afins
	
	// Opção 8: Comida
	setarray .itens_opcao_8[0], 4, 531, 532, 533, 534; // Maçã, Banana, Uva, Laranja
	
	// Opção 9: Flechas
	setarray .itens_opcao_9[0], 4, 1750, 1751, 1752, 1753; // Flechas variadas
	
	// Opção 10: Pedras preciosas
	setarray .itens_opcao_10[0], 3, 711, 712, 713; // Esmeralda, Ametista, Safira
	
	// Opção 11: Itens de evento
	setarray .itens_opcao_11[0], 4, 601, 602, 603, 604; // Asas e itens especiais
	
	// Opção 12: Poções de cura avançadas
	setarray .itens_opcao_12[0], 4, 509, 510, 511, 512; // Poções Brancas, Poções Azuis
	
	// Opção 13: Livros de habilidade
	setarray .itens_opcao_13[0], 3, 2749, 2750, 2751; // Livros
	
	// Opção 14: Pergaminhos
	setarray .itens_opcao_14[0], 3, 602, 603, 604; // Pergaminhos
	
	// Opção 15: Elmos especiais
	setarray .itens_opcao_15[0], 3, 2201, 2202, 2203; // Elmos
	
	// Opção 16: Botas
	setarray .itens_opcao_16[0], 3, 2401, 2402, 2403; // Botas
	
	end;

OnPCLoadMapEvent:
	// Se quiser que o NPC apareça em mapas específicos, configure aqui
	end;
}
// Função para verificar e debitar #NOSSACOIN da conta
function	script	VerificarMoedas	{
	.@total_itens = getarg(0);
	.@custo_total = 0;
	
	// Calcular custo total (1 moeda por item)
	for (.@i = 0; .@i < .@total_itens; .@i++) {
		.@item_id = getarg(.@i * 2 + 1);
		.@quantidade = getarg(.@i * 2 + 2);
		.@custo_total += .@quantidade;
	}
	
	// #NOSSACOIN é uma variável de conta
	// Por padrão, variáveis de conta usam o prefixo #
	.@saldo_atual = #NOSSACOIN;
	
	// Verificar se tem moedas suficientes
	if (.@saldo_atual < .@custo_total) {
		mes "Você não tem NossaCoins o suficiente!";
		mes "Necessário: " + .@custo_total + " NossaCoins";
		mes "Seu saldo: " + .@saldo_atual + " NossaCoins";
		close;
	}
	
	// Debitar as moedas da conta
	set #NOSSACOIN, .@saldo_atual - .@custo_total;
	
	mes "^FF0000 -" + .@custo_total + " NossaCoins^000000";
	mes "Seu novo saldo: " + #NOSSACOIN + " NossaCoins";
	
	// Retornar o custo total para uso posterior
	return .@custo_total;
}

// Menu principal
function	script	MenuPrincipal	{
	.@menu$ = "";
	.@menu_options$[0] = "Costumes Upper"; // Nome da opção 1
	.@menu_options$[1] = "Costumes Upper 1"; // Nome da opção 2
	.@menu_options$[2] = "Costumes Upper 2"; // Nome da opção 3
	.@menu_options$[3] = "Costumes Upper 3"; // Nome da opção 4
	.@menu_options$[4] = "Costumes Upper 4"; // Nome da opção 5
	.@menu_options$[5] = "Costumes Upper 5"; // Nome da opção 6
	.@menu_options$[6] = "Costumes Upper 6"; // Nome da opção 7
	.@menu_options$[7] = "Costumes Upper 7"; // Nome da opção 8
	.@menu_options$[8] = "Costumes Middle"; // Nome da opção 9
	.@menu_options$[9] = "Costumes Middle 1"; // Nome da opção 10
	.@menu_options$[10] = "Costumes Middle 2"; // Nome da opção 11
	.@menu_options$[11] = "Costumes Lower"; // Nome da opção 12
	.@menu_options$[12] = "Costumes Lower 1"; // Nome da opção 13
	.@menu_options$[13] = "Costumes Lower 2"; // Nome da opção 14
	.@menu_options$[14] = "Costumes Lower 3"; // Nome da opção 15
	.@menu_options$[15] = "Costumes Garment"; // Nome da opção 16
	
	// Mostrar saldo atual antes do menu
	mes "Seu saldo: " + #NOSSACOIN + " NossaCoins";
	next;
	
	// Construir menu
	for(.@i = 0; .@i < 16; .@i++) {
		.@menu$ = .@menu$ + .@menu_options$[.@i] + ":";
	}
	
	// Mostrar menu e obter escolha
	.@escolha = select(.@menu$) - 1;
	
	// Determinar qual array de itens usar baseado na escolha
	switch(.@escolha) {
		case 0: copyarray .@itens_temporarios[0], .itens_opcao_1[0], .itens_opcao_1[0] + 1; break;
		case 1: copyarray .@itens_temporarios[0], .itens_opcao_2[0], .itens_opcao_2[0] + 1; break;
		case 2: copyarray .@itens_temporarios[0], .itens_opcao_3[0], .itens_opcao_3[0] + 1; break;
		case 3: copyarray .@itens_temporarios[0], .itens_opcao_4[0], .itens_opcao_4[0] + 1; break;
		case 4: copyarray .@itens_temporarios[0], .itens_opcao_5[0], .itens_opcao_5[0] + 1; break;
		case 5: copyarray .@itens_temporarios[0], .itens_opcao_6[0], .itens_opcao_6[0] + 1; break;
		case 6: copyarray .@itens_temporarios[0], .itens_opcao_7[0], .itens_opcao_7[0] + 1; break;
		case 7: copyarray .@itens_temporarios[0], .itens_opcao_8[0], .itens_opcao_8[0] + 1; break;
		case 8: copyarray .@itens_temporarios[0], .itens_opcao_9[0], .itens_opcao_9[0] + 1; break;
		case 9: copyarray .@itens_temporarios[0], .itens_opcao_10[0], .itens_opcao_10[0] + 1; break;
		case 10: copyarray .@itens_temporarios[0], .itens_opcao_11[0], .itens_opcao_11[0] + 1; break;
		case 11: copyarray .@itens_temporarios[0], .itens_opcao_12[0], .itens_opcao_12[0] + 1; break;
		case 12: copyarray .@itens_temporarios[0], .itens_opcao_13[0], .itens_opcao_13[0] + 1; break;
		case 13: copyarray .@itens_temporarios[0], .itens_opcao_14[0], .itens_opcao_14[0] + 1; break;
		case 14: copyarray .@itens_temporarios[0], .itens_opcao_15[0], .itens_opcao_15[0] + 1; break;
		case 15: copyarray .@itens_temporarios[0], .itens_opcao_16[0], .itens_opcao_16[0] + 1; break;
	}
	
	// Criar shop temporário baseado nos itens da opção escolhida
	.@total_itens = .@itens_temporarios[0];
	for(.@i = 1; .@i <= .@total_itens; .@i++) {
		.@shoplist[.@i*2 - 2] = .@itens_temporarios[.@i];
		.@shoplist[.@i*2 - 1] = 1; // Preço 1 #NOSSACOIN (será verificado pela variável de conta)
	}
	
	// Armazenar a lista de itens para uso no callback
	setarray .shop_itens_temp[0], .@itens_temporarios[0];
	for(.@i = 1; .@i <= .@total_itens; .@i++) {
		.shop_itens_temp[.@i] = .@itens_temporarios[.@i];
	}
	
	// Chamar o shop
	callshop "shop_temporario", 1;
	end;
}

// Função de callback do shop
function	script	ProcessarCompra	{
	.@total_itens_selecionados = getarraysize(@bought_nameid);
	
	if (.@total_itens_selecionados == 0) {
		mes "Você não selecionou nenhum item para experimentar.";
		close;
	}
	
	// Calcular custo total (1 #NOSSACOIN por item)
	.@custo_total = 0;
	for (.@i = 0; .@i < .@total_itens_selecionados; .@i++) {
		.@custo_total += @bought_quantity[.@i];
	}
	
	// Verificar saldo de #NOSSACOIN
	if (#NOSSACOIN < .@custo_total) {
		mes "Saldo insuficiente de NossaCoins!";
		mes "Necessário: " + .@custo_total + " NossaCoins";
		mes "Seu saldo: " + #NOSSACOIN + " NossaCoins";
		close;
	}
	
	// Debitar #NOSSACOIN da conta
	set #NOSSACOIN, #NOSSACOIN - .@custo_total;
	
	mes "Processando itens para experimentação...";
	mes "^FF0000 -" + .@custo_total + " NossaCoins^000000";
	mes " ";
	mes "Itens selecionados (60 segundos):";
	
	for (.@i = 0; .@i < .@total_itens_selecionados; .@i++) {
		.@item_id = @bought_nameid[.@i];
		.@quantidade = @bought_quantity[.@i];
		
		// Adicionar cada item com duração de 60 segundos
		for (.@j = 0; .@j < .@quantidade; .@j++) {
			rentitem .@item_id, 60;
		}
		
		mes "- " + getitemname(.@item_id) + " x" + .@quantidade;
	}
	
	mes " ";
	mes "Seu novo saldo: " + #NOSSACOIN + " NossaCoins";
	mes "Aproveite para testá-los!";
	close;
}

// Shop temporário
-	shop	shop_temporario	-1,{
	// O shop será preenchido dinamicamente via callshop
	callfunc "ProcessarCompra";
	end;
}

// NPC principal
06guild_02,47,52,5	script	Testador de Costumes	50,{
	mes "[Testador de Costumes]";
	mes "Olá! Eu posso te ajudar a testar";
	mes "diferentes itens por 60 segundos.";
	mes "Cada item custa 1 NossaCoin.";
	mes " ";
	mes "^FF0000Seu saldo: " + #NOSSACOIN + " NossaCoins^000000";
	next;
	
	// Chamar função do menu principal
	callfunc "MenuPrincipal";
	
	// Se chegou aqui, o usuário cancelou ou algo deu errado
	close;
}