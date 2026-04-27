// * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ *
// * ~~~~~~~~  Euphy's MVP Ladder v1.3  ~~~~~~~~ *
// * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ *
//= Modificado por Alek Emundus
//= Adicionado comando para checar quantos MVPs Points o player tem.
-	script	mvpPoints	-1,{
	OnInit:
		bindatcmd "mvp",strnpcinfo(0) + "::OnAtcommand";
		end;
	OnAtcommand:
		dispbottom "Você tem " + MVP_Rank + " Pontos de MVP!";
		end;
}

mall01,79,107,3	script	MVP Ladder	4_m_bosscat,{
	mes "[Rank MVP]";
	mes "Olá.";
	mes "O que você está procurando?";
	next;
	switch(select("- Checar o Ranking.:- Meus pontos.:- Trocar pontos.:- Nada...")) {
		case 1:
			mes "[Rank MVP]";
			query_sql("SELECT char_id, CAST(`value` AS SIGNED) FROM `char_reg_num` WHERE `key` = 'MVP_Rank' ORDER BY CAST(`value` AS SIGNED) DESC LIMIT 20",.@cid,.@value);
			for(set .@i,0; .@i<getarraysize(.@cid); set .@i,.@i+1) {
				query_sql("SELECT `name` FROM `char` WHERE char_id = "+.@cid[.@i]+";",.@j$);
				set .@name$[.@i], .@j$;
			}
			if (!getarraysize(.@cid))
				mes "O ranking está Vazio.";
			else for(set .@i,0; .@i<getarraysize(.@cid); set .@i,.@i+1)
			mes "["+(.@i+1)+"] "+.@name$[.@i]+" ~ "+.@value[.@i]+" kills";
			close;
			
		case 2:
			mes "[Rank MVP]";
			mes "Você matou "+((MVP_Rank)?"^0055FF"+MVP_Rank:"no")+"^000000 MVP"+((MVP_Rank == 1)?".":"s.");
			close;
		case 3:
			goto H_menu;
			//Item Menu ================================================
			H_menu:
				menu
				"Elunium",R_elu,
				"Oridecon",R_ori,
				"(Costume)There is Somthing (7days)",R_rtis,
				"(Costume)There is Somthing",R_tis,
				"(Costume)Red Wind Hat (7days)",R_rwh,
				"(Costume)Red Wind Hat",R_wh,
				"(Costume)12th Anniversary Fairy Ears (7days)",R_r12,
				"(Costume)12th Anniversary Fairy Ears",R_12,
				"(Costume)Ninja Scroll (7days)",R_rns,
				"(Costume)Ninja Scroll",R_ns,
				"(Costume)Gang Scarf (7days)",R_rgs,
				"(Costume)Gang Scarf",R_gs,
				"(Costume)Holy Mom Love (7days)",R_rhm,
				"(Costume)Holy Mom Love",R_hm,
				"(Costume)Bread Bag (7days)",R_rbb,
				"(Costume)Bread Bag",R_bb,
				"(Costume)Diadem (7days)",R_rdia,
				"(Costume)Diadem",R_dia,
				"(Costume)Ascension Black Dragon (7days)",R_rasc,
				"(Costume)Ascension Black Dragon",R_asc,
				"(Costume)Marcher Hat (7days)",R_rmh,
				"(Costume)Marcher Hat",R_mh,
				"Cancel",H_cancel;
			//Required =================================================
			R_elu:
				next;
				mes "1x Nossa Coin";
				menu "- Fazer",M_elu,"- Retornar para o Menu",H_menu;
			R_ori:
				next;
				mes "1x Nossa Coin";
				menu "- Fazer",M_ori,"- Retornar para o Menu",H_menu;
			R_rtis:
				next;
				mes "15x Nossa Coin";
				menu "- Fazer",M_rtis,"- Retornar para o Menu",H_menu;
			R_tis:
				next;
				mes "60x Nossa Coin";
				menu "- Fazer",M_tis,"- Retornar para o Menu",H_menu;
			R_rwh:
				next;
				mes "5x Nossa Coin";
				menu "- Fazer",M_rwh,"- Retornar para o Menu",H_menu;
			R_wh:
				next;
				mes "30x Nossa Coin";
				menu "- Fazer",M_wh,"- Retornar para o Menu",H_menu;
			R_r12:
				next;
				mes "15x Nossa Coin";
				menu "- Fazer",M_r12,"- Retornar para o Menu",H_menu;
			R_12:
				next;
				mes "50x Nossa Coin";
				menu "- Fazer",M_12,"- Retornar para o Menu",H_menu;
			R_rns:
				next;
				mes "9x Nossa Coin";
				menu "- Fazer",M_rns,"- Retornar para o Menu",H_menu;
			R_ns:
				next;
				mes "35x Nossa Coin";
				menu "- Fazer",M_ns,"- Retornar para o Menu",H_menu;
			R_rgs:
				next;
				mes "10x Nossa Coin";
				menu "- Fazer",M_rgs,"- Retornar para o Menu",H_menu;
			R_gs:	
				next;
				mes "35x Nossa Coin";
				menu "- Fazer",M_gs,"- Retornar para o Menu",H_menu;
			R_rhm:	
				next;
				mes "5x Nossa Coin";
				menu "- Fazer",M_rhm,"- Retornar para o Menu",H_menu;
			R_hm:
				next;
				mes "30x Nossa Coin";
				menu "- Fazer",M_hm,"- Retornar para o Menu",H_menu;
			R_rbb:
				next;
				mes "5x Nossa Coin";
				menu "- Fazer",M_rbb,"- Retornar para o Menu",H_menu;
			R_bb:
				next;
				mes "30x Nossa Coin";
				menu "- Fazer",M_bb,"- Retornar para o Menu",H_menu;
			R_rdia:
				next;
				mes "5x Nossa Coin";
				menu "- Fazer",M_rdia,"- Retornar para o Menu",H_menu;
			R_dia:
				next;
				mes "30x Nossa Coin";
				menu "- Fazer",M_dia,"- Retornar para o Menu",H_menu;
			R_rasc:
				next;
				mes "5x Nossa Coin";
				menu "- Fazer",M_rasc,"- Retornar para o Menu",H_menu;
			R_asc:
				next;
				mes "30x Nossa Coin";
				menu "- Fazer",M_asc,"- Retornar para o Menu",H_menu;
			R_rmh:
				next;
				mes "5x Nossa Coin";
				menu "- Fazer",M_rmh,"- Retornar para o Menu",H_menu;
			R_mh:
				next;
				mes "30x Nossa Coin";
				menu "- Fazer",M_mh,"- Retornar para o Menu",H_menu;
				
			//- Fazer Item ================================================
			M_elu:
				if(countitem(840095)<1 )
				goto M_insufficient;
				delitem 840095,1;
				getitem 985,1;
			close;
			M_ori:
				if(countitem(840095)<1 )
				goto M_insufficient;
				delitem 840095,1;
				getitem 984,1;
			close;
			M_rtis:
				if(countitem(840095)<15 )
				goto M_insufficient;
				delitem 840095,15;
				rentitem 20183,604800;
			close;
			M_tis:
				if(countitem(840095)<60 )
				goto M_insufficient;
				delitem 840095,60;
				getitem 20183,1;
			close;
			M_rwh:
				if(countitem(840095)<5 )
				goto M_insufficient;
				delitem 840095,5;
				rentitem 19579,604800;
			close;
			M_wh:
				if(countitem(840095)<30 )
				goto M_insufficient;
				delitem 840095,30;
				getitem 19579,1;
			close;
			M_r12:
				if(countitem(840095)<15 )
				goto M_insufficient;
				delitem 840095,15;
				rentitem 20136,604800;
			close;
			M_12:
				if(countitem(840095)<50 )
				goto M_insufficient;
				delitem 840095,50;
				getitem 20136,1;
			close;
			M_rns:
				if(countitem(840095)<9 )
				goto M_insufficient;
				delitem 840095,9;
				rentitem 19606,604800;
			close;
			M_ns:
				if(countitem(840095)<35 )
				goto M_insufficient;
				delitem 840095,35;
				getitem 19606,1;
			close;
			M_rgs:
				if(countitem(840095)<10 )
				goto M_insufficient;
				delitem 840095,10;
				rentitem 19605,604800;
			close;
			M_gs:
				if(countitem(840095)<35 )
				goto M_insufficient;
				delitem 840095,35;
				getitem 19605,1;
			close;
			M_rhm:
				if(countitem(840095)<5 )
				goto M_insufficient;
				delitem 840095,5;
				rentitem 19756,604800;
			close;
			M_hm:
				if(countitem(840095)<30 )
				goto M_insufficient;
				delitem 840095,30;
				getitem 19756,1;
			close;
			M_rbb:
				if(countitem(840095)<5 )
				goto M_insufficient;
				delitem 840095,5;
				rentitem 19725,604800;
			close;
			M_bb:
				if(countitem(840095)<30 )
				goto M_insufficient;
				delitem 840095,30;
				getitem 19725,1;
			close;		
			M_rdia:
				if(countitem(840095)<5 )
				goto M_insufficient;
				delitem 840095,5;
				rentitem 19748,604800;
			close;
			M_dia:
				if(countitem(840095)<30 )
				goto M_insufficient;
				delitem 840095,30;
				getitem 19748,1;
			close;
			M_rasc:
				if(countitem(840095)<5 )
				goto M_insufficient;
				delitem 840095,5;
				rentitem 19575,604800;
			close;	
			M_asc:	
				if(countitem(840095)<30 )
				goto M_insufficient;
				delitem 840095,30;
				getitem 19575,1;
			close;
			M_rmh:
				if(countitem(840095)<5 )
				goto M_insufficient;
				delitem 840095,5;
				rentitem 19653,604800;
			close;
			M_mh:	
				if(countitem(840095)<30 )
				goto M_insufficient;
				delitem 840095,30;
				getitem 19653,1;
			close;
				
			//Insufficient Coin ========================================
			M_insufficient:
			next;
			mes "Você não tem a quantidade necessária de moedas.";
			mes "Por favor, volte novamente quando tiver...";
			menu "- Retornar para o Menu",H_menu,"- Sair",H_cancel;
			close;
			//Cancel ===================================================
			H_cancel:
			close;
				
		case 4:
			close;
	}
 
OnNPCKillEvent:
	getmapxy .@map$,.@x,.@y;
	if (.@map$ == "bossnia_01")
	{
		end;
	} else if(.@map$ == "bossnia_02")
	{
		end;
	} else if(.@map$ == "bossnia_03")
	{
		end;
	} else if(.@map$ == "bossnia_04")
	{
		end;
	} else if(.@map$ == "mall01")
	{
		end;
	} else {
		.@mob_id = killedrid;
		// IDs dos mobs
		setarray .@mvps[0], 1038,1039,1046,1059,1086,1087,1112,1115,1147,1150,1157,1159,1190,1251,1252,1272,1312,1373,1389,1399,1418,1492,1502,1511,1518,1583,1623,1630,1646,1647,1648,1649,1650,1651,1658,1685,1688,1708,1719,1734,1751,1768,1779,1785,1813,1817,1832,1871,1874,1876,1885,1917,1980,2022,2068,2087,2094,2095,2096,2097,2098,2099,2100,2101,2102,2103,2104,2105,2106,2107,2108,2109,2110,2111,2112,2113,2131,2156,2165,2186,2194,2202,2235,2236,2237,2238,2239,2240,2241,2249,2251,2253,2255,2319,2341,2352,2362,2443,2444,2445,2446,2447,2448,2449,2475,2476,2483,2529,2532,2533,2534,2535,2996,3000,3074,3220,3221,3222,3223,3224,3225,3240,3241,3242,3243,3244,3245,3246,3426,3427,3428,3429,3430,3450,3473,3505,3621,3628,3633,3658,3659,3741,3757,3758,3796,3810,20381,20934,20943,20648,20601;

    // Verifica se o monstro tem o modo BOSS
    //if (.@mob_id == .@mvps[0]) {
		// Verifica se o monstro morto é um MVP da lista acima
		for (.@i = 0; .@i < getarraysize(.@mvps); .@i++) {
				if(.@mob_id == .@mvps[.@i]){
					set MVP_Rank, MVP_Rank+1;
					if (MVP_Rank == 1){
					query_sql("INSERT INTO `char_reg_num` (`char_id`,`key`,`index`,`value`) VALUES ("+getcharid(0)+",'MVP_Rank','0',1)");
					dispbottom "- Você matou seu primeiro MVP! "+MVP_Rank+" MVPs Abatidos"+((MVP_Rank == 1)?"":"s")+". ~";
					dispbottom "Você ganhou 1 ponto de MVP";
					getitem 840095,1; //<<< THIS IS THE COIN REWARD FOR MVP ONLY<<<<<<<<<<<<
					specialeffect2 313;
				} else {
					query_sql("UPDATE `char_reg_num` SET `value` = '"+MVP_Rank+"' WHERE char_id = "+getcharid(0)+" AND `key` ='MVP_Rank'");
					dispbottom "- Você matou "+MVP_Rank+" MVP"+((MVP_Rank == 1)?"":"s")+". ~";
					//dispbottom " ~ Reward: Cash +15 ~ ";
					//set #CASHPOINTS, #CASHPOINTS + 15;
					dispbottom "Você ganhou 1 ponto de MVP";
					getitem 840095,1; //<<< THIS IS THE COIN REWARD FOR MVP ONLY<<<<<<<<<<<<
					specialeffect2 313;
				}
					break; // Sai do loop quando encontra o mvp
				}
		}
	}
	end;
}