//===== rAthena Script =======================================
//= Frontier Recycling System
//===== Description: =========================================
//= Recicla armas e armaduras por pontos especiais
//= Armas > #FrontierWeapPoints
//= Armaduras > #FrontierCrownPoints
//============================================================

mall01,74,109,5	script	Reciclador Frontier	564,{
	disable_items;
	
	mes "[Reciclador Frontier]";
	mes "Bem-vindo ao programa de reciclagem";
	mes "Frontier!";
	mes " ";
	mes "Posso reciclar suas armas e armaduras";
	mes "antigas em troca de pontos especiais.";
	next;
	
	switch(select("Reciclar Armas.:Reciclar Armaduras.:Consultar meus pontos.:Sair")) {
	case 1:
		callsub S_RecycleWeapons;
		break;
	case 2:
		callsub S_RecycleArmors;
		break;
	case 3:
		callsub S_CheckPoints;
		break;
	case 4:
		mes "[Reciclador Frontier]";
		mes "Volte sempre que tiver mais";
		mes "itens para reciclar!";
		close;
	}
	end;

S_RecycleWeapons:
	// Array de armas recicláveis
	setarray .@weapons[0],
		1175,1466,1371,13046,1720,2004,1531,1716,1168,16001,
		1366,1189,1648,13047,1468,1131,1141,1474,13315,1415,
		1233,1138,1528,1241,1167;
	.@total_weapons = 25; // Total de armas na lista
	
	mes "[Reciclador Frontier]";
	mes "Quais armas você quer reciclar?";
	mes "Cada arma vale ^FF00001 ponto^000000.";
	mes " ";
	mes "Posso reciclar várias de uma vez!";
	next;
	
	// Verifica quantas armas o player tem
	.@total_count = 0;
	.@menu$ = ""; // LIMPA O MENU ANTES DE MONTAR
	
	for(.@i = 0; .@i < .@total_weapons; .@i++) {
		.@count = countitem(.@weapons[.@i]);
		if(.@count > 0) {
			.@total_count++;
			.@menu$ = .@menu$ + .@count + "x " + getitemname(.@weapons[.@i]) + ":";
		}
	}
	
	if(.@total_count == 0) {
		mes "[Reciclador Frontier]";
		mes "Você não tem nenhuma arma";
		mes "que possa ser reciclada.";
		close;
	}
	
	// Adiciona a opção de reciclar todas
	.@menu$ = .@menu$ + "Reciclar TODAS as armas";
	
	.@option = select(.@menu$) - 1;
	
	// Verifica se escolheu "Reciclar TODAS" (última opção)
	if(.@option == .@total_count) {
		// Reciclar todas - Primeiro mostra quais itens serão reciclados
		mes "[Reciclador Frontier]";
		mes "Você está prestes a reciclar TODAS";
		mes "as seguintes armas:";
		mes " ";
		
		.@total_points = 0;
		for(.@i = 0; .@i < .@total_weapons; .@i++) {
			.@count = countitem(.@weapons[.@i]);
			if(.@count > 0) {
				mes .@count + "x " + getitemname(.@weapons[.@i]);
				.@total_points += .@count;
			}
		}
		
		mes " ";
		mes "Total a receber: ^FF0000" + .@total_points + " pontos^000000";
		next;
		
		if(select("Confirmar reciclagem", "Cancelar") == 1) {
			// Confirmação - Agora recicla de verdade
			.@total_points = 0;
			for(.@i = 0; .@i < .@total_weapons; .@i++) {
				.@count = countitem(.@weapons[.@i]);
				if(.@count > 0) {
					delitem .@weapons[.@i], .@count;
					.@total_points += .@count;
				}
			}
			
			if(.@total_points > 0) {
				// Atualiza a variável de pontos
				set #FrontierWeapPoints, #FrontierWeapPoints + .@total_points;
				
				// Mostra resultado
				dispbottom "=========================================";
				dispbottom "Reciclagem concluída!";
				dispbottom "Pontos ganhos: " + .@total_points;
				dispbottom "Total de Fragmentos de Armas: " + #FrontierWeapPoints;
				dispbottom "=========================================";
				
				mes "[Reciclador Frontier]";
				mes "Reciclagem concluída! Você ganhou";
				mes "^FF0000" + .@total_points + " pontos^000000 para Fragmentos de Armas.";
				mes " ";
				mes "Agora você tem um total de";
				mes "^FF0000" + #FrontierWeapPoints + " pontos^000000.";
				close;
			}
		} else {
			mes "[Reciclador Frontier]";
			mes "Reciclagem cancelada.";
			close;
		}
	} else {
		// Reciclar apenas o item selecionado
		.@current_index = 0;
		for(.@i = 0; .@i < .@total_weapons; .@i++) {
			.@count = countitem(.@weapons[.@i]);
			if(.@count > 0) {
				if(.@current_index == .@option) {
					.@item_name$ = getitemname(.@weapons[.@i]);
					.@item_id = .@weapons[.@i];
					break;
				}
				.@current_index++;
			}
		}
		
		mes "[Reciclador Frontier]";
		mes "Quantas " + .@item_name$ + " você quer reciclar?";
		mes "Você tem: " + .@count;
		next;
		
		input .@amount;
		
		if(.@amount > 0 && .@amount <= .@count) {
			// Mostra confirmação
			mes "[Reciclador Frontier]";
			mes "Confirmar reciclagem de:";
			mes "^FF0000" + .@amount + "x " + .@item_name$ + "^000000";
			mes " ";
			mes "Pontos a receber: ^FF0000" + .@amount + "^000000";
			next;
			
			if(select("Confirmar reciclagem", "Cancelar") == 1) {
				delitem .@item_id, .@amount;
				.@total_points = .@amount;
				
				// Atualiza a variável de pontos
				set #FrontierWeapPoints, #FrontierWeapPoints + .@total_points;
				
				// Mostra resultado
				dispbottom "=========================================";
				dispbottom "Reciclagem concluída!";
				dispbottom "Pontos ganhos: " + .@total_points;
				dispbottom "Total de Fragmentos de Armas: " + #FrontierWeapPoints;
				dispbottom "=========================================";
				
				mes "[Reciclador Frontier]";
				mes "Reciclagem concluída! Você ganhou";
				mes "^FF0000" + .@total_points + " pontos^000000 para Fragmentos de Armas.";
				mes " ";
				mes "Agora você tem um total de";
				mes "^FF0000" + #FrontierWeapPoints + " pontos^000000.";
				close;
			}
		}
	}
	
	// Se chegou aqui, algo deu errado ou cancelou
	mes "[Reciclador Frontier]";
	mes "Operação cancelada.";
	close;
	
S_RecycleArmors:
	// Array de armaduras recicláveis
	setarray .@armors[0],
		2235,2423,2246,2234,2327,2507,5053,2231,2700,2659,
		2660,2661,2662,2515,2650,2651,2357,2524,2421,2509,
		2345,5123;
	.@total_armors = 22; // Total de armaduras na lista
	
	mes "[Reciclador Frontier]";
	mes "Quais armaduras você quer reciclar?";
	mes "Cada armadura vale ^FF00001 ponto^000000.";
	mes " ";
	mes "Posso reciclar várias de uma vez!";
	next;
	
	// Verifica quantas armaduras o player tem
	.@total_count = 0;
	.@menu$ = ""; // LIMPA O MENU ANTES DE MONTAR
	
	for(.@i = 0; .@i < .@total_armors; .@i++) {
		.@count = countitem(.@armors[.@i]);
		if(.@count > 0) {
			.@total_count++;
			.@menu$ = .@menu$ + .@count + "x " + getitemname(.@armors[.@i]) + ":";
		}
	}
	
	if(.@total_count == 0) {
		mes "[Reciclador Frontier]";
		mes "Você não tem nenhuma armadura";
		mes "que possa ser reciclada.";
		close;
	}
	
	// Adiciona a opção de reciclar todas
	.@menu$ = .@menu$ + "Reciclar TODAS as armaduras";
	
	.@option = select(.@menu$) - 1;
	
	// Verifica se escolheu "Reciclar TODAS" (última opção)
	if(.@option == .@total_count) {
		// Reciclar todas - Primeiro mostra quais itens serão reciclados
		mes "[Reciclador Frontier]";
		mes "Você está prestes a reciclar TODAS";
		mes "as seguintes armaduras:";
		mes " ";
		
		.@total_points = 0;
		for(.@i = 0; .@i < .@total_armors; .@i++) {
			.@count = countitem(.@armors[.@i]);
			if(.@count > 0) {
				mes .@count + "x " + getitemname(.@armors[.@i]);
				.@total_points += .@count;
			}
		}
		
		mes " ";
		mes "Total a receber: ^FF0000" + .@total_points + " pontos^000000";
		next;
		
		if(select("Confirmar reciclagem", "Cancelar") == 1) {
			// Confirmação - Agora recicla de verdade
			.@total_points = 0;
			for(.@i = 0; .@i < .@total_armors; .@i++) {
				.@count = countitem(.@armors[.@i]);
				if(.@count > 0) {
					delitem .@armors[.@i], .@count;
					.@total_points += .@count;
				}
			}
			
			if(.@total_points > 0) {
				// Atualiza a variável de pontos
				set #FrontierCrownPoints, #FrontierCrownPoints + .@total_points;
				
				// Mostra resultado
				dispbottom "=========================================";
				dispbottom "Reciclagem concluída!";
				dispbottom "Pontos ganhos: " + .@total_points;
				dispbottom "Total de Fragmentos de Coroas: " + #FrontierCrownPoints;
				dispbottom "=========================================";
				
				mes "[Reciclador Frontier]";
				mes "Reciclagem concluída! Você ganhou";
				mes "^FF0000" + .@total_points + " pontos^000000 para Fragmentos de Coroas.";
				mes " ";
				mes "Agora você tem um total de";
				mes "^FF0000" + #FrontierCrownPoints + " pontos^000000.";
				close;
			}
		} else {
			mes "[Reciclador Frontier]";
			mes "Reciclagem cancelada.";
			close;
		}
	} else {
		// Reciclar apenas o item selecionado
		.@current_index = 0;
		for(.@i = 0; .@i < .@total_armors; .@i++) {
			.@count = countitem(.@armors[.@i]);
			if(.@count > 0) {
				if(.@current_index == .@option) {
					.@item_name$ = getitemname(.@armors[.@i]);
					.@item_id = .@armors[.@i];
					break;
				}
				.@current_index++;
			}
		}
		
		mes "[Reciclador Frontier]";
		mes "Quantas " + .@item_name$ + " você quer reciclar?";
		mes "Você tem: " + .@count;
		next;
		
		input .@amount;
		
		if(.@amount > 0 && .@amount <= .@count) {
			// Mostra confirmação
			mes "[Reciclador Frontier]";
			mes "Confirmar reciclagem de:";
			mes "^FF0000" + .@amount + "x " + .@item_name$ + "^000000";
			mes " ";
			mes "Pontos a receber: ^FF0000" + .@amount + "^000000";
			next;
			
			if(select("Confirmar reciclagem", "Cancelar") == 1) {
				delitem .@item_id, .@amount;
				.@total_points = .@amount;
				
				// Atualiza a variável de pontos
				set #FrontierCrownPoints, #FrontierCrownPoints + .@total_points;
				
				// Mostra resultado
				dispbottom "=========================================";
				dispbottom "Reciclagem concluída!";
				dispbottom "Pontos ganhos: " + .@total_points;
				dispbottom "Total de Fragmentos de Coroas: " + #FrontierCrownPoints;
				dispbottom "=========================================";
				
				mes "[Reciclador Frontier]";
				mes "Reciclagem concluída! Você ganhou";
				mes "^FF0000" + .@total_points + " pontos^000000 para Fragmentos de Coroas.";
				mes " ";
				mes "Agora você tem um total de";
				mes "^FF0000" + #FrontierCrownPoints + " pontos^000000.";
				close;
			}
		}
	}
	
	// Se chegou aqui, algo deu errado ou cancelou
	mes "[Reciclador Frontier]";
	mes "Operação cancelada.";
	close;
	
S_CheckPoints:
	mes "[Reciclador Frontier]";
	mes "Aqui está seu saldo atual:";
	mes " ";
	mes "^FF0000Fragmentos de Armas:^000000 " + #FrontierWeapPoints;
	mes "^FF0000Fragmentos de Coroas:^000000 " + #FrontierCrownPoints;
	mes " ";
	mes "Continue reciclando para acumular";
	mes "mais pontos!";
	close;
}