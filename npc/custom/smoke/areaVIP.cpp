//= Criado por Alek Emundus
//= Scripts da Área Vip (vip_lounge)
-	script	areaVIP	-1,{
	dispbottom "Bem vindo(a) à Área VIP!";
	OnPCLogoutEvent:
	getmapxy .@map$,.@x,.@y;
	if (.@map$ == "vip_lounge")
	{
		warp "prontera",156,191;
		end;
	} else {
		end;
	}
}	
//= Removedora de Cartas VIP
vip_lounge,72,146,5	script	A Senhora das Cartas-VIP	78,{

	set .zenycost,0;    // base cost of the card remover services (in Zeny)
	set .percardcost,0;  // cost per card of the card remover services (in Zeny)
	set .faildestroy,0;      // should the card remover have a chance of failure that destroys items? (1=yes, 0=no)

	disable_items;
	mes "[A Senhora das Cartas-VIP]";
	mes "Bom dia jovem. Eu tenho o poder de remover cartas que você colocou em seu equipamento. O que você acha?";
	next;
	switch(select("- Sim, seria legal!:- O que você cobra?:- Não, obrigado!")) {
	case 1:
		mes "[A Senhora das Cartas-VIP]";
		mes "Muito bem. Qual item eu deveria examinar pra você?";
		next;

		setarray .@indices[1], EQI_HEAD_TOP, EQI_ARMOR, EQI_HAND_L, EQI_HAND_R, EQI_GARMENT, EQI_SHOES, EQI_ACC_L, EQI_ACC_R, EQI_HEAD_MID, EQI_HEAD_LOW;
		for( set .@i,1; .@i <= 10; set .@i,.@i+1 ) {
			if( getequipisequiped(.@indices[.@i]) )
				set .@menu$, .@menu$ + F_getpositionname(.@indices[.@i]) + "-[" + getequipname(.@indices[.@i]) + "]";
			set .@menu$, .@menu$ + ":";
		}
		set .@part, .@indices[ select(.@menu$) ];
		if(!getequipisequiped(.@part)) {
			mes "[A Senhora das Cartas-VIP]";
			mes "Jovem... você não está usando nada que eu possa remover cartas.";
			close;
		}
		if(getequipcardcnt(.@part) == 0) {
			mes "[A Senhora das Cartas-VIP]";
			mes "Jovem... Não tem cartas neste item. Não posso fazer nada quanto a isso, sinto muito.";
			close;
		}
		set .@cardcount,getequipcardcnt(.@part);
		if (!checkweight(1202,(.@cardcount+1))) { 
			mes "^3355FFSó um minuto!";
			mes "Eu não posso fornecer os meus servicos pra você";
			mes "porque você esta carregando muito peso...";
			mes "Coloque seus itens extras no seu @Storage";
			mes "E retorne pra falar comigo de novo!";
			close;
		}
		mes "[A Senhora das Cartas-VIP]";
		mes "Este item tem " + .@cardcount + " cartas nele.";
		next;
		if(select("- Muito bom, pode fazer!:- Deixa pra depois...") == 2) {
			mes "[A Senhora das Cartas-VIP]";
			mes "Tudo bem! Volte quando precisar dos meus serviços.";
			close;
		}
		mes "[A Senhora das Cartas-VIP]";
		mes "Muito bem, eu vou começar.";
		next;
		successremovecards .@part;
		mes "[A Senhora das Cartas-VIP]";
		mes "O processo foi um sucesso! Aqui está suas cartas e seu item.";
		close;
	case 2:
		mes "[A Senhora das Cartas-VIP]";
		mes "Você é VIP, meu anjo, não cobro nada!";
		close;
	case 3:
		mes "[A Senhora das Cartas-VIP]";
		mes "Tudo bem, volte quando precisar dos meus serviços.";
		close;
	}
}

// Gold Room - VIP
/*-	script	GoldRoom	-1,{
	OnThisMobDeath:
		getitem 969,1;
	end;
}
vip_lounge,143,140,3	script	Gold Room	2248,{
	mes "^C9CB1B[Gold Room]^000000";
	mes "Bem vindo, gostaria de ir para Gold Room?";
	switch(select("- Bora!:- Deixa pra depois..."))
	{
		case 1:
			clear;
			mes "^C9CB1B[Gold Room]^000000";
			mes "Aproveite!";
			next;
			warp "1@def01",49,50;
			end;
		case 2:
			clear;
			mes "^C9CB1B[Gold Room]^000000";
			mes "Tudo bem, até mais!";
			close;
	}
	
	OnPCLogoutEvent:
	getmapxy .@map$,.@x,.@y;
	if (.@map$ == "1@def01")
	{
		warp "prontera",156,191;
		end;
	} else {
		end;
	}
}
// Gold Room
1@def01,0,0	monster	Poring de Ouro	1002,100,1000,1000,"GoldRoom::OnThisMobDeath"*/

// Mapflags
vip_lounge	mapflag	noloot	on
vip_lounge	mapflag	noteleport	on
vip_lounge	mapflag	nosave	on
vip_lounge	mapflag	nomemo	on
vip_lounge	mapflag	nowarpto	on

// Gold Room
/*1@def01	mapflag	noloot	on
1@def01	mapflag	noteleport	on
1@def01	mapflag	nosave	on
1@def01	mapflag	nomemo	on
1@def01	mapflag	nowarpto	on*/