//= Criado por Alek Emundus - @sistemaemundus
//= Troca de Black Gemstone (840051) por itens Dark GodLike
//= Também te levará para Ayothaya Field (ayo_fild02 49, 62)
//= Para farmar Essência de Dark GodLike (840051)
mall01,66,105,5	script	Shine GodLike	494,{	
	mes "[Shine GodLike]";
	mes "Gostaria de dar uma olhada no que tenho à propor?";
	switch(select("- Sim.:- Por agora não...:- O quê você faz mesmo?:- Como conseguir o material?")){
		case 1:
			clear;
			mes "[Shine GodLike]";
			mes "Pois bem, aqui está!";
			close2;
			callshop "itensDarkGodLike";
			end;
		case 2:
			clear;
			mes "[Shine GodLike]";
			mes "Ok, até a próxima, aventureiro!";
			close2;
			end;
		case 3:
			clear;
			mes "[Shine GodLike]";
			mes "Boas vindas, meu nome é Shine GodLike, e eu estou aqui para lhe ajudar!";
			mes "Posso lhe fornecer alguns equipamentos, desde que você me traga o necessário...";
			mes "Posso trocar " +mesitemlink(840051)+ ", que contém um poder imenso e obscuro...";
			mes "Trocarei-os por equipamentos de mesma magnitude, onde aumentará sua força e sabedoria..";
			mes "O quê você acha?";
			close2;
			end;
		case 4:
			clear;
			mes "[Shine GodLike]";
			mes "Muito simples, basta dizer que você quer ir e eu te levo ao local!";
			switch(select("- Ok, vamos lá!:- Vou pensar...")){
				case 1:
					warp "ayo_fild02",49,62;
					end;
				case 2:
					clear;
					mes "[Shine GodLike]";
					mes "Até a próxima!";
					close2;
					end;
			}
	}
}