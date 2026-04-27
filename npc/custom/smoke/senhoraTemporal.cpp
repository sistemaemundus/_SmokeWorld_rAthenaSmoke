//= Criado por Alek Emundus
//= Troca itens de Old Glast Heim por Manto Temporal
//= Versão 2:
//= Convertido em Barter

mall01,76,107,5	script	Senhora Temporal	633,{
	mes "[Senhora Temporal]";
	mes "Olá, posso trocar itens de instâncias por Mantos Temporais, cada manto vai lhe custar:";
	mes mesitemicon(6608)+" x50 | "+mesitemicon(6755)+" x15 | "+mesitemicon(6607)+" x15"; // Polluted_Spell, Coagulated_Spell, Temporal_Crystal
	mes "O quê você me diz?";
	next;
	switch(select("- Quero dar uma olhada!:- Agora não...")){
		case 1:
			clear;
			mes "[Senhora Temporal]";
			mes "Aqui está!";
			close2;
			callshop "senhoraTemporal",1;
			end;
		case 2:
			clear;
			mes "[Senhora Temporal]";
			mes "Tudo bem, até logo!";
			close2;
			end;
	}
}