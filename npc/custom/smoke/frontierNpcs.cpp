// Questline Frontier
// Criado por Emundus SmokeWorld
// Variáveis relacionadas: #FrontierWeapPoints, #FrontierCrownPoints, questFrontier, tioFrontierA, tioFrontierB, tiaFrontierA, tiaFrontierB

// Nelson Frontier - Pai
mall01,72,107,5	script	Nelson Frontier	932,{
	if (BaseLevel < 250) {
		mes "[Nelson Frontier]";
		mes "Olá?";
		close;
	} else {
		if (questFrontier == 0) {
			mes "[Nelson Frontier]";
			mes "Ah... um aventureiro.";
			mes "Talvez você seja exatamente";
			mes "o tipo de pessoa que eu preciso.";
			next;
			clear;
			mes "[Nelson Frontier]";
			mes "Meu nome é Nelson Frontier.";
			mes "Minha família dedicou gerações";
			mes "ao estudo de relíquias antigas.";
			next;
			clear;
			mes "[Nelson Frontier]";
			mes "Eu tive dois filhos.";
			mes "Kael... e Lyra.";
			mes "Ambos eram brilhantes";
			mes "à sua própria maneira.";
			next;
			clear;
			mes "[Nelson Frontier]";
			mes "Kael sempre acreditou";
			mes "que o verdadeiro poder";
			mes "deveria pertencer aos guerreiros.";
			next;
			clear;
			mes "[Nelson Frontier]";
			mes "Lyra, por outro lado,";
			mes "acreditava que poder";
			mes "sem controle leva à destruição.";
			next;
			clear;
			mes "[Nelson Frontier]";
			mes "A discussão entre eles";
			mes "cresceu com o tempo.";
			mes "Até que um dia...";
			mes "ambos desapareceram.";
			next;
			clear;
			mes "[Nelson Frontier]";
			mes "Eles levaram consigo";
			mes "fragmentos das relíquias";
			mes "que eu havia descoberto.";
			next;
			clear;
			mes "[Nelson Frontier]";
			mes "Meus irmãos tentaram";
			mes "investigar o desaparecimento.";
			mes "Eles encontraram pistas...";
			mes "coordenadas espalhadas";
			mes "pelo deserto.";
			next;
			clear;
			mes "[Nelson Frontier]";
			mes "Se quiser me ajudar,";
			mes "procure meus irmãos.";
			mes "Eles ainda guardam";
			mes "essas informações.";
			next;
			clear;
			mes "[Nelson Frontier]";
			mes "Leve isto.";
			mes "Esse selo mostrará";
			mes "que você veio até eles";
			mes "em meu nome.";
			set tioFrontierA, 1;
			set tioFrontierB, 1;
			set tiaFrontierA, 1;
			set tiaFrontierB, 1;
			set questFrontier, 1;
			achievementadd 600001;
			message strcharinfo(0),"Comando @frontier liberado!";
			close;
		} else if (questFrontier == 1) {
			mes "[Nelson Frontier]";
			mes "E aí, encontrou algo?";
			close;
		} 
	}
	
	if (questFrontier == 5) {
		mes "[Nelson Frontier]";
		mes "Então você encontrou";
		mes "meus irmãos...";
		next;
		clear;
		mes "[Nelson Frontier]";
		mes "Deixe-me ver";
		mes "essas coordenadas...";
		next;
		clear;
		mes "[Nelson Frontier]";
		mes "Sim...";
		mes "isso confirma";
		mes "o que eu suspeitava.";
		next;
		clear;
		mes "[Nelson Frontier]";
		mes "Essas coordenadas";
		mes "apontam para o mesmo lugar.";
		mes "As antigas ruínas de...";
		mes "Temple Akhet.";
		next;
		clear;
		mes "[Nelson Frontier]";
		mes "Se Kael e Lyra";
		mes "realmente estão lá...";
		mes "então ambos descobriram";
		mes "algo dentro do templo.";
		next;
		clear;
		mes "[Nelson Frontier]";
		mes "Algo que talvez";
		mes "nem mesmo eu compreenda.";
		next;
		clear;
		mes "[Nelson Frontier]";
		mes "Se pretende continuar,";
		mes "procure meu primo, Arden,";
		mes "no deserto de Morroc.";
		next;
		clear;
		mes "[Nelson Frontier]";
		mes "Ele saberá como levá-lo";
		mes "até o antigo templo.";
		mes "E aventureiro...";
		mes "tenha cuidado.";
		mes "Meus filhos";
		mes "não são mais os mesmos.";
		set questFrontier, questFrontier + 1;
		close;
	} else if (questFrontier == 6) {
		mes "[Nelson Frontier]";
		mes "E então, já achou Arden?";
		close;
	} else if (questFrontier <= 4) {
		mes "[Nelson Frontier]";
		mes "Está faltando algo...";
		close;
	}
	
	if (questFrontier == 7) {
		if (filhoFrontier == 1 && filhaFrontier == 0) {
			mes "[Nelson Frontier]";
			mes "Vejo que encontrou meu filho, ele está bem?";
			mes "E minha filha, onde ela está?";
			close;
		} else if (filhoFrontier == 0 && filhaFrontier == 1) {
			mes "[Nelson Frontier]";
			mes "Percebo que encontrou minha filha, como ela está?";
			mes "E meu filho, ainda está o procurando?";
			close;
		} else if (filhoFrontier == 1 && filhaFrontier == 1) {
			mes "[Nelson Frontier]";
			mes "Como é bom saber que ambos estão bem!";
			close;
		}
	}
	
	if (questFrontier == 9) {
		mes "[Nelson Frontier]";
		mes "Você já carrega o legado da nossa família.";
		close;
	}
}

// Kael Frontier - Filho
moc_akhet,324,317,5	script	Kael Frontier	686,{
	if (filhoFrontier == 0 && tioFrontierA >= 1 && tioFrontierB >= 1) {
		mes "[Kael Frontier]";
		mes "...";
		mes "Então alguém conseguiu";
		mes "chegar até aqui.";
		next;
		clear;
		mes "[Kael Frontier]";
		mes "Esse selo...";
		mes "Você veio falar com";
		mes "meu pai, não foi?";
		next;
		clear;
		mes "[Kael Frontier]";
		mes "Hmph.";
		mes "Nelson ainda acredita";
		mes "que pode controlar tudo.";
		next;
		clear;
		mes "[Kael Frontier]";
		mes "Mas ele nunca entendeu";
		mes "o verdadeiro propósito";
		mes "das relíquias Frontier.";
		next;
		clear;
		mes "[Kael Frontier]";
		mes "Essas runas não foram feitas";
		mes "para ficar guardadas";
		mes "em bibliotecas poeirentas.";
		next;
		clear;
		mes "[Kael Frontier]";
		mes "Elas foram feitas";
		mes "para serem usadas";
		mes "em combate.";
		next;
		clear;
		mes "[Kael Frontier]";
		mes "Minha irmã Lyra?";
		mes "Ela sempre foi assim...";
		mes "arrogante.";
		next;
		clear;
		mes "[Kael Frontier]";
		mes "Ela acredita que apenas";
		mes "mentes brilhantes";
		mes "podem controlar";
		mes "o poder das relíquias.";
		next;
		clear;
		mes "[Kael Frontier]";
		mes "Mas o verdadeiro poder";
		mes "pertence àqueles";
		mes "que têm coragem";
		mes "de empunhá-lo.";
		next;
		clear;
		mes "[Kael Frontier]";
		mes "Durante minha pesquisa";
		mes "neste templo...";
		mes "descobri fragmentos";
		mes "das antigas Runas de Arma.";
		next;
		clear;
		mes "[Kael Frontier]";
		mes "Mas para reconstruí-las,";
		mes "preciso de alguns catalisadores.";
		next;
		clear;
		mes "[Kael Frontier]";
		mes "Você vai precisar falar com meus tios";
		mes "sobre isso...";
		next;
		clear;
		mes "[Kael Frontier]";
		mes "Relíquias carregadas";
		mes "com energia de MVPs.";
		next;
		clear;
		mes "[Kael Frontier]";
		mes "Se trouxer esses materiais,";
		mes "posso condensar o poder";
		mes "em uma caixa.";
		next;
		clear;
		mes "[Kael Frontier]";
		mes "Ao abrir essa caixa,";
		mes "você poderá obter";
		mes "uma Caixa de Runas de Arma.";
		next;
		clear;
		RequisitosFilho:
		mes "[Kael Frontier]";
		mes "Traga-me";
		mes "Fragmentos de Armas Frontier,";
		mes "ou os 4 Catalisadores Frontier.";
		next;
		clear;
		mes "[Kael Frontier]";
		mes "E eu criarei para você";
		mes "algo de valor inestimável.";
		if (filhoFrontier == 0) {
			set filhoFrontier, 1;
			set questFrontier, questFrontier + 1;
			close;
		}
		close;
	} else if (filhoFrontier == 1 && #FrontierWeapPoints <= 0 && questFrontier < 9) {
	switch(select("Do que você precisa mesmo?:Cancelar")) {
		case 1:
			goto RequisitosFilho;
		case 2:
			clear;
			mes "[Kael Frontier]";
			mes "Tudo bem, volte caso mudar de ideia!";
			close;
		}
	}
	if (questFrontier == 9) {
		mes "[Kael Frontier]";
		mes "Seja breve!";
		if(select("Runas.:Armas?") == 1) {
				clear;
				mes "[Kael Frontier]";
				mes "Tenho algo a oferecer pelos Fragmentos de Armas, quer ver?";
				if(select("Não, obrigado...:Sim, gostaria!") == 1) {
					clear;
					mes "[Kael Frontier]";
					mes "Tudo bem, volte caso mudar de ideia!";
					close;
				} else {
					clear;
					mes "[Kael Frontier]";
					mes "Ok, dê uma olhada!";
					close2;
					callshop "pointFilhoFrontier",1;
					end;
				}
		} else {
				clear;
				mes "[Kael Frontier]";
				mes "Ei, onde você conseguiu isso?";
				next;
				clear;
				mes "[Kael Frontier]";
				mes "Ok, não importa!";
				mes "Me dê todos eles e eu lhe recompensarei!";
				close2;
				callshop "filhoFrontier",1;
				end;
		}
	} else {
		mes "[Kael Frontier]";
		mes "Quem é você?";
		close;
	}
}

// Lyra Frontier - Filha
moc_akhet,80,176,5	script	Lyra Frontier	482,{
	if (filhafrontier == 0 && tiaFrontierA >= 1 && tiaFrontierB >= 1) {
		mes "[Lyra Frontier]";
		mes "Interessante...";
		mes "Alguém conseguiu";
		mes "chegar tão longe.";
		next;
		clear;
		mes "[Lyra Frontier]";
		mes "Esse selo...";
		mes "Então você encontrou";
		mes "meu pai.";
		next;
		clear;
		mes "[Lyra Frontier]";
		mes "Nelson sempre acreditou";
		mes "que poderia controlar";
		mes "o destino da nossa família.";
		next;
		clear;
		mes "[Lyra Frontier]";
		mes "Mas ele nunca compreendeu";
		mes "o verdadeiro potencial";
		mes "das relíquias Frontier.";
		next;
		clear;
		mes "[Lyra Frontier]";
		mes "Meu irmão Kael?";
		mes "Ele sempre foi previsível.";
		next;
		clear;
		mes "[Lyra Frontier]";
		mes "Para ele,";
		mes "tudo se resume";
		mes "a força bruta.";
		next;
		clear;
		mes "[Lyra Frontier]";
		mes "Mas poder sem controle";
		mes "não passa";
		mes "de destruição.";
		next;
		clear;
		mes "[Lyra Frontier]";
		mes "As relíquias das Coroas";
		mes "são diferentes.";
		next;
		clear;
		mes "[Lyra Frontier]";
		mes "Elas amplificam";
		mes "a mente";
		mes "de quem as usa.";
		next;
		clear;
		mes "[Lyra Frontier]";
		mes "Neste templo encontrei";
		mes "fragmentos das antigas";
		mes "Runas de Coroa.";
		next;
		clear;
		mes "[Lyra Frontier]";
		mes "Mas reconstruí-las";
		mes "exige catalisadores raros.";
		next;
		clear;
		mes "[Lyra Frontier]";
		mes "Acredito que minhas tias";
		mes "sabem algo sobre!";
		next;
		clear;
		mes "[Lyra Frontier]";
		mes "Energias residuais";
		mes "de armaduras";
		mes "carregadas por MVPs.";
		next;
		clear;
		RequisitosFilha:
		mes "[Lyra Frontier]";
		mes "Traga-me";
		mes "Fragmentos de Coroas Frontier,";
		mes "ou os 4 Catalisadores de Coroa Frontier.";
		next;
		clear;
		mes "[Lyra Frontier]";
		mes "E eu criarei para você";
		mes "algo inimaginável!";
		if (filhaFrontier == 0) {
			set filhaFrontier, 1;
			set questFrontier, questFrontier + 1;
			close;
		}
		close;
	} else if (filhaFrontier == 1 && #FrontierCrownPoints <= 0 && questFrontier < 9) {
	switch(select("Pode me lembrar o que precisa?:Cancelar")) {
		case 1:
			goto RequisitosFilha;
		case 2:
			clear;
			mes "[Lyra Frontier]";
			mes "Certo, até mais!";
			close;
		}
	}
	if(questFrontier == 9) {
		mes "[Lyra Frontier]";
		mes "Oi meu bem, como posso te ajudar?";
		if(select("Runas.:Coroa?") == 1){
				clear;
				mes "[Lyra Frontier]";
				mes "Vamos negociar alguns Fragmentos de Coroas?";
				if(select("Não, obrigado.:Sim, gostaria!") == 1) {
					clear;
					mes "[Lyra Frontier]";
					mes "Tá bom, você pode voltar caso mudar de ideia!";
					close;
				} else {
					clear;
					mes "[Lyra Frontier]";
					mes "Ok, dê uma olhada!";
					close2;
					callshop "pointFilhaFrontier",1;
					end;
				}
		} else {
				clear;
				mes "[Lyra Frontier]";
				mes "Uooooo, onde conseguiu esses catalisadores?";
				next;
				clear;
				mes "[Lyra Frontier]";
				mes "Certo, posso lhe oferecer algo por eles.";
				mes "Me dê todos eles e eu vou te recompensar!";
				close2;
				callshop "filhaFrontier",1;
				end;
		}
	} else {
		mes "[Lyra Frontier]";
		mes "Oii!";
		close;
		}
}

// Edric Frontier - Tio A
alberta,61,221,5	script	Edric Frontier	995,{
	if (tioFrontierA == 1) {
	mes "[Edric Frontier]";
	mes "Hm?";
	mes "Esse selo...";
	mes "Então Nelson";
	mes "ainda está procurando";
	mes "pelos filhos.";
	next;
	clear;
	mes "[Edric Frontier]";
	mes "Kael sempre foi";
	mes "o mais impulsivo da família.";
	mes "Desde pequeno";
	mes "preferia treinar com espadas";
	mes "do que estudar pergaminhos.";
	next;
	clear;
	mes "[Edric Frontier]";
	mes "Quando Nelson descobriu";
	mes "as Runas de Arma...";
	mes "Kael ficou obcecado";
	mes "por aquele poder.";
	next;
	clear;
	mes "[Edric Frontier]";
	mes "Durante minhas expedições";
	mes "pelo deserto de Morroc,";
	mes "encontrei vestígios";
	mes "da energia dessas runas.";
	next;
	clear;
	mes "[Edric Frontier]";
	mes "Uma das coordenadas";
	mes "que encontrei foi:";
	mes "^DC143C324^000000";
	next;
	clear;
	mes "[Edric Frontier]";
	mes "Se Kael realmente";
	mes "foi para aquelas ruínas...";
	mes "essa pista pode ajudar";
	mes "a encontrá-lo.";
	set tioFrontierA, 2;
	set questFrontier, questFrontier + 1;
	close;
	} else if (tioFrontierA == 2 && filhoFrontier == 0) {
		mes "[Edric Frontier]";
		mes "E aí, encontrou algo?";
		mes "Não se esqueça:";
		mes "a coordenada é ^DC143C324^000000";
		close;
	}
	if (filhoFrontier == 1) {
		mes "[Edric Frontier]";
		mes "Posso te ajudar a barganhar com Kael...";
		if (select("Agora não.:Dar uma olhada.") == 1) {
			clear;
			mes "[Edric Frontier]";
			mes "Você quem sabe...";
			close;
		} else {
			clear;
			mes "[Edric Frontier]";
			mes "Dê uma olhadinha...";
			close2;
			callshop "tioFrontierA",1;
			end;
		}
	} else {
		mes "[Edric Frontier]";
		mes "Hum?";
		close;
	}
}

// Alaric Frontier - Tio B
brasilis,218,243,5	script	Alaric Frontier	901,{
	if (tioFrontierB == 1) {
		mes "[Alaric Frontier]";
		mes "Ah...";
		mes "Você veio falar";
		mes "sobre Kael, não é?";
		next;
		clear;
		mes "[Alaric Frontier]";
		mes "Aquele garoto sempre teve";
		mes "mais coragem";
		mes "do que juízo.";
		next;
		clear;
		mes "[Alaric Frontier]";
		mes "Se existe algum poder";
		mes "escondido nas ruínas...";
		mes "Kael certamente";
		mes "iria atrás dele.";
		next;
		clear;
		mes "[Alaric Frontier]";
		mes "Enquanto investigava";
		mes "as ruínas próximas";
		mes "ao Temple Akhet...";
		mes "descobri outra pista.";
		next;
		clear;
		mes "[Alaric Frontier]";
		mes "A coordenada que encontrei foi:";
		mes "^DC143C317^000000";
		next;
		clear;
		mes "[Alaric Frontier]";
		mes "Combine essa informação";
		mes "com outras pistas...";
		mes "e talvez consiga";
		mes "localizar meu sobrinho.";
		set tioFrontierB, 2;
		set questFrontier, questFrontier + 1;
		close;
	} else if (tioFrontierB == 2 && filhoFrontier == 0) {
		mes "[Alaric Frontier]";
		mes "Opa, alguma novidade?";
		mes "Você se lembra, né?:";
		mes "A coordenada é ^DC143C317^000000";
		close;
	}
	if (filhoFrontier == 1) {
		mes "[Alaric Frontier]";
		mes "Humm...";
		mes "Quer cooperar com Kael?";
		mes "Eu posso te ajudar...";
		if (select("Agora não.:Como?") == 1) {
			clear;
			mes "[Alaric Frontier]";
			mes "Você quem sabe...";
			close;
		} else {
			clear;
			mes "[Alaric Frontier]";
			mes "Olhe só isso...";
			close2;
			callshop "tioFrontierB",1;
			end;
		}
	} else {
		mes "[Alaric Frontier]";
		mes "Hum?";
		close;
	}
}

// Helena Frontier - Tia A
amatsu,187,132,5	script	Helena Frontier	918,{
	if (tiaFrontierA == 1) {
		mes "[Helena Frontier]";
		mes "Você veio falar";
		mes "sobre Lyra?";
		mes "Ah... aquela menina";
		mes "sempre foi especial.";
		next;
		clear;
		mes "[Helena Frontier]";
		mes "Enquanto Kael buscava força,";
		mes "Lyra buscava entendimento.";
		next;
		clear;
		mes "[Helena Frontier]";
		mes "Quando Nelson descobriu";
		mes "as relíquias das Coroas...";
		mes "Lyra foi a única";
		mes "que conseguiu compreender";
		mes "o funcionamento delas.";
		next;
		clear;
		mes "[Helena Frontier]";
		mes "Essas coroas não são";
		mes "meros adornos.";
		mes "Elas amplificam";
		mes "a mente de quem as usa.";
		next;
		clear;
		mes "[Helena Frontier]";
		mes "Durante minhas pesquisas";
		mes "no deserto...";
		mes "encontrei uma pista";
		mes "ligada a ela.";
		next;
		clear;
		mes "[Helena Frontier]";
		mes "A coordenada era:";
		mes "^DC143C80^000000";
		next;
		clear;
		mes "[Helena Frontier]";
		mes "Se Lyra realmente";
		mes "se escondeu nas ruínas...";
		mes "isso pode levar você";
		mes "até ela.";
		set tiaFrontierA, 2;
		set questFrontier, questFrontier + 1;
		close;
	} else if (tiaFrontierA == 2 && filhaFrontier == 0) {
		mes "[Helena Frontier]";
		mes "Oi, conseguiu algo?";
		mes "Lembre-se:";
		mes "a coordenada é ^DC143C80^000000";
		close;
	}
	if (filhaFrontier == 1) {
		mes "[Helena Frontier]";
		mes "Se você cooperar posso te ajudar à negociar com Lyra...";
		if (select("Agora não.:Me conte mais.") == 1) {
			clear;
			mes "[Helena Frontier]";
			mes "Você quem sabe...";
			close;
		} else {
			clear;
			mes "[Helena Frontier]";
			mes "Olhe só isto.";
			close2;
			callshop "tiaFrontierA",1;
			end;
		}
	} else {
		mes "[Helena Frontier]";
		mes "Olá...";
		close;
	}
}

// Cassandra Frontier - Tia B
hugel,119,153,5	script	Cassandra Frontier	863,{
	if (tiaFrontierB == 1) {
		mes "[Cassandra Frontier]";
		mes "Lyra...";
		mes "Sempre admirei";
		mes "a inteligência dela.";
		next;
		clear;
		mes "[Cassandra Frontier]";
		mes "Mas inteligência";
		mes "sem limites";
		mes "pode ser perigosa.";
		next;
		clear;
		mes "[Cassandra Frontier]";
		mes "Quando Kael e Lyra";
		mes "começaram a discutir";
		mes "sobre as relíquias...";
		mes "ficou claro";
		mes "que ambos queriam provar";
		mes "que estavam certos.";
		next;
		clear;
		mes "[Cassandra Frontier]";
		mes "Durante minha investigação";
		mes "perto do Temple Akhet...";
		mes "descobri outra coordenada.";
		next;
		clear;
		mes "[Cassandra Frontier]";
		mes "Anote isso:";
		mes "^DC143C176^000000";
		next;
		clear;
		mes "[Cassandra Frontier]";
		mes "Se juntar as duas pistas...";
		mes "talvez consiga";
		mes "encontrar Lyra.";
		set tiaFrontierB, 2;
		set questFrontier, questFrontier + 1;
		close;
	} else if (tiaFrontierB == 2 && filhaFrontier == 0) {
		mes "[Cassandra Frontier]";
		mes "A coordenada é";
		mes "^DC143C176^000000";
		close;
	} 
	if (filhaFrontier == 1) {
		mes "[Cassandra Frontier]";
		mes "Se quiser extrair algo de Lyra,";
		mes "precisará da minha ajuda!";
		if (select("Agora não.:Como assim?") == 1) {
			clear;
			mes "[Cassandra Frontier]";
			mes "Você quem sabe...";
			close;
		} else {
			clear;
			mes "[Cassandra Frontier]";
			mes "Se liga nisso.";
			close2;
			callshop "tiaFrontierB",1;
			end;
		}
	} else {
		mes "[Cassandra Frontier]";
		mes "Hum...";
		close;
	}
}

// Arden Frontier - Guarda
moc_fild11,192,211,5	script	Arden Frontier	653,{
	if (questFrontier == 6 && BaseLevel >= 250) {
		mes "[Arden Frontier]";
		mes "Vejo que você conheceu a família Frontier...";
		mes "E então, como posso ajudar?";
		set questFrontier, questFrontier + 1;
		close;
	} else if (questFrontier == 7 && baseLevel >= 250) {
		mes "[Arden Frontier]";
		mes "Bom, posso te levar para Ancient Temple Akhet, gostaria de ir agora?";
		if(select("Agora não...:Vamos!") == 1) {
		mes "[Arden Frontier]";
		mes "Tudo bem, retorne quando quiser!";
		close;
		} else {
			clear;
			mes "[Arden Frontier]";
			mes "Vou te enviar para lá, então.";
			mes "Até mais!";
			close2;
			warp "moc_akhet",190,53;
		}
	} else {
		clear;
		mes "[Arden Frontier]";
		mes "Mantenha distância!";
		close;
	}
}

// Comando para verificar fragmentos frontier
-	script	frontierQuest	-1,{
	OnInit:
		bindatcmd "frontier",strnpcinfo(0) + "::OnAtcommand";
		end;
	OnAtcommand:
		if (questFrontier <= 0) {
			message strcharinfo(0),"Comando Inválido!";
			message strcharinfo(0),"Complete a missão da Frontier para usar este comando!";
		} else if (questFrontier < 9) {
			message strcharinfo(0),"Seu progresso: Quest Frontier "+questFrontier+"/9";
			end;
		} else {
			message strcharinfo(0),"Você possui "+#FrontierWeapPoints+" Fragmentos de Armas Frontier e "+#FrontierCrownPoints+" Fragmentos de Coroas Frontier.";
			end;
		}
}