//= Criado por Alek Emundus
//= Função para a caixaBeta & caixaStreamer

function	script	caixasEspeciais	{
    if(BaseLevel <= 98){
        mes "^FF0000===[Escolha sabiamente!]===^000000";
        mes "Gostaria de ir para o nível 99?";
		mes "^FF0000===[Escolha sabiamente!]===^000000";
        if(select("- Sim!:- Não...") == 2) {
            close;
        } else {
			clear;
			mes "^FF0000===[Escolha sabiamente!]===^000000";
        	mes "Tem certeza disso?";
			mes "^FF0000===[Escolha sabiamente!]===^000000";
            if(select("- Sim!:- Não...") == 2) {
				close;
			} else {
				BaseLevel = 99;
            	close;
			}
        }
    }
}

function	script	caixasBooster	{
	mes "^FF0000===[Escolha sabiamente!]===^000000";
    mes "Qual caixa BOOSTER você gostaria de obter?";
	mes mesitemicon(100046) + ", " + mesitemicon(100047) + ", " + mesitemicon(100048) + ", " + mesitemicon(100049);
	mes "^FF0000Uma vez escolhido não poderá voltar atrás!^000000";
	switch(select("- Caixa Attacker.:- Caixa Ranged.:- Caixa Elemental.:- Caixa Defender.")){
		case 1:
			getitem 100046,1;
			close2;
			break;
		case 2:
			getitem 100047,1;
			close2;
			break;
		case 3:
			getitem 100048,1;
			close2;
			break;
		case 4:
			getitem 100049,1;
			close2;
			break;
	}
}