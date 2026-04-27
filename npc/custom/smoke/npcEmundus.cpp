//= Criado por Emundus - SmokeWorld
vip_lounge,138,123,6	script	Emundus	405,{
	.@nome$ = "[Emundus"];
	mes .@nome$;
	mes "Escolha uma opção:";
	switch(select("Reforma de Item.:Upgrade de Lapina.")){
		case 1:
			clear;
			mes .@nome$;
			mes "Divirta-se!";
			item_reform();
			close;
		case 2:
			clear;
			mes .@nome$;
			mes "Ainda não faço isso.";
			//laphine_upgrade();
			close;
	}
}