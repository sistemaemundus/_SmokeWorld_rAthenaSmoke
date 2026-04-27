prontera,147,171,5	script	Aleph	1_M_WIZARD,{
	mes "[Aleph]";
	mes "Bom dia!";
	switch(select("Juntar itens.:Cancelar.")){
		case 1:
			switch(select("Juntar todos possíveis!:Quero selecionar...")){
				case 1:
					mergeitem2;
					clear;
					mes "[Aleph]";
					mes "Prontinho, até mais!";
					close;
				case 2:
					mergeitem;
					clear;
					mes "[Aleph]";
					mes "Fique à vontade, selecione e depois clique em OK!";
					close;
			}
		case 2:
			clear;
			mes "[Aleph]";
			mes "Ok, até mais!";
			close;
	}
}