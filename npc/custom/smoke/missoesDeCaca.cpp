//===== rAthena Script =======================================
//= Hunting Missions
//===== By: ==================================================
//= Euphy
//===== Current Version: =====================================
//= 1.4
//===== Compatible With: ===================================== 
//= rAthena Project
//===== Description: =========================================
//= Random hunting missions.
//= Rewards are based on quest difficulty.
//= 
//= NOTE: Requires SQL mob database.
//===== Additional Comments: =================================
//= 1.0 Initial script.
//= 1.1 Small improvements and fixes.
//= 1.2 Added party support and replaced blacklists with an
//=     SQL query, both thanks to AnnieRuru.
//= 1.3 Re-added a blacklist adapted for the SQL query.
//= 1.3a Added mission reset options.
//= 1.3b Function updates.
//= 1.4 Check for deleted characters, thanks to AnnieRuru.
//=     Syntax updates and style cleaning.
//============================================================
//= Traduzido por Emundus SmokeWorld

//prontera,152,187,6	script	Hunting Missions	4_F_EDEN_MASTER,{
prontera,164,172,4	script	Missões de Caça	4_F_EDEN_MASTER,{	
function Chk;
	mes "[Missões de Caça]";
	mes "Olá, " + strcharinfo(0) + "!";
	if (!#Mission_Delay) {
		next;
		mes "[Missões de Caça]";
		mes "Não consigo encontrar nenhum registro...";
		mes "Você deve ser novo aqui!";
		emotion ET_HUK;
		next;
		callsub Mission_Info;
		emotion ET_GO;
		#Mission_Delay = 1;
		close;
	}
	mes F_Rand("Trabalhando duro, como sempre...", "Sem folga, espero...");
	mes "Há algo que eu possa ajudar";
	mes "você?";
	mes " ";
	mes "^777777~ Você completou " + F_InsertPlural(Mission_Total,"missões",0,"^0055FF%d^777777") + ". ~^000000";
	next;
	switch(select(
		((!Mission0) ? "~ Nova Missão::" : ": ~ Status da Missão: ~ Abandonar Missão") +
		": ~ Informações: ~ Loja de missões: ~ Ver os melhores caçadores: ~ ^777777Cancelar^000000"
	)) {
	case 1:
		mes "[Missões de Caça]";
		if (#Mission_Count) {
			mes "Você iniciou uma missão";
			mes "em outro personagem.";
			if (!@hm_char_del_check) {  // check for deleted character
				query_sql("SELECT 1 FROM `char_reg_num` WHERE `key` = 'Mission0' AND `char_id` IN(SELECT `char_id` FROM `char` WHERE `account_id` = " + getcharid(3) + ")", .@i);
				if (!.@i) {
					next;
					mes "[Missões de Caça]";
					mes "Não consigo encontrar nenhum registro";
					mes "para esse personagem, entretanto...";
					mes "Um momento, por favor.";
					emotion ET_SCRATCH;
					#Mission_Count = 0;
				}
				@hm_char_del_check = true;
			}
			close;
		}
		if (#Mission_Delay > gettimetick(2) && .Delay) {
			mes "Temo que você terá que esperar" + Time2Str(#Mission_Delay) + " antes de assumir outra missão.";
			close;
		}
		mes "Você deve caçar:";
		query_sql("SELECT ID FROM `" + .mob_db$ + "` WHERE left(name_aegis, 4) != 'meta' AND left(name_aegis, 2) != 'E_' AND base_exp > 0 AND job_exp > 0 AND (class != 'boss' OR class is null) AND (drop3_item like '%_card' OR drop4_item like '%_card' OR drop5_item like '%_card' OR drop6_item like '%_card' OR drop7_item like '%_card' OR drop8_item like '%_card' OR drop9_item like '%_card' OR drop10_item like '%_card') AND ID < 2000 AND instr('"+.Blacklist$+"',ID) = 0 ORDER BY rand() LIMIT " + .Quests, .@mob);
		
		for (.@i = 0; .@i < .Quests; .@i++) {
			setd "Missão" + .@i, .@mob[.@i];
			setd "Missão" + .@i +"_", 0;
		}
		#Mission_Count = rand(.Count[0], .Count[1]);
		callsub Mission_Status;
		next;
		mes "[Missões de Caça]";
		mes "Relate quando";
		mes "você terminar.";
		mes "Boa sorte!";
		close;
	case 2:
		mes "[Missões de Caça]";
		mes "Status da missão:";
		callsub Mission_Status;
		close;
	case 3:
		mes "[Missões de Caça]";
		mes "Você realmente quer";
		mes "abandonar sua missão?";
		if (.Reset < 0 && .Delay)
			mes "Seu tempo de atraso não será redefinido.";
		else if (.Reset > 0)
			mes "Isso custará" + F_InsertComma(.Reset) + " Zeny.";
		next;
		switch(select(" ~ Abandonar...: ~ ^777777Cancelar^000000")) {
		case 1:
			if (.Reset > 0) {
				if (Zeny < .Reset) {
					mes "[Missões de Caça]";
					mes "Você não tem o suficiente de";
					mes "Zeny para abandonar esta missão.";
					emotion ET_SORRY;
					close;
				}
				Zeny -= .Reset;
				emotion ET_MONEY;
			}
			mes "[Missões de Caça]";
			mes "Tudo bem, eu cancelei";
			mes "sua missão atual.";
			specialeffect2 EF_STORMKICK4;
			for (.@i = 0; .@i < .Quests; .@i++) {
				setd "Missão"+.@i, 0;
				setd "Missão"+.@i+"_", 0;
			}
			#Mission_Count = 0;
			if (.Reset < 0 && .Delay)
				#Mission_Delay = gettimetick(2) + (.Delay * 3600);
			close;
		case 2:
			mes "[Missões de Caça]";
			mes "Eu sabia que você estava brincando!";
			mes "Continue com o bom trabalho.";
			emotion ET_SMILE;
			close;
		}
	case 4:
		callsub Mission_Info;
		close;
	case 5:
		mes "[Missões de Caça]";
		mes "Você tem ^0055FF" + #Mission_Points + "^000000 Pontos de Missão.";
		mes "Use-os bem!";
		callshop "mission_shop",1;
		npcshopattach "mission_shop";
		end;
	case 6:
		mes "[Missões de Caça]";
		mes "Os melhores caçadores são:";
		query_sql("SELECT char_id AS id, (SELECT `name` FROM `char` WHERE char_id = id),`value` FROM `char_reg_num` WHERE `key` = 'Mission_Total' ORDER BY CAST(`value` AS SIGNED) DESC LIMIT 5", .@id, .@name$, .@val);
		for (.@i = 0; .@i < 5; .@i++)
			mes " [Classificação " + (.@i+1) + "]  " + ((.@name$[.@i] == "") ? "^777777nenhum" : "^0055FF" + .@name$[.@i]+"^000000 : ^FF0000" + .@val[.@i] + " pt.") + "^000000";
		close;
	case 7:
		mes "[Missões de Caça]";
		mes "Nada? Ok...";
		emotion ET_SCRATCH;
		close;
	}
	end;

Mission_Status:
	@f = false;
	deletearray .@j[0], getarraysize(.@j);
	for (.@i = 0; .@i < .Quests; .@i++) {
		.@j[.@i] = getd("Missão" + .@i);
		.@j[.Quests] = .@j[.Quests] + getmonsterinfo(.@j[.@i], MOB_LV);
		.@j[.Quests+1] = .@j[.Quests+1] + (getmonsterinfo(.@j[.@i], MOB_BASEEXP) / (getbattleflag("base_exp_rate") / 100) * .Modifier[0]);
		.@j[.Quests+2] = .@j[.Quests+2] + (getmonsterinfo(.@j[.@i], MOB_JOBEXP) / (getbattleflag("job_exp_rate") / 100) * .Modifier[1]);
		mes " > "+Chk(getd("Missão"+.@i+"_"),#Mission_Count) + getmonsterinfo(.@j[.@i], MOB_NAME) + " (" + getd("Missão"+.@i+"_") + "/" + #Mission_Count + ")^000000";
	}

	// Reward formulas:
	.@Mission_Points = 3 + (.@j[.Quests] / .Quests / 6);
	.@Base_Exp = #Mission_Count * .@j[.Quests+1] / 5;
	.@Job_Exp = #Mission_Count * .@j[.Quests+2] / 5;
	.@Zeny = #Mission_Count * .Quests * .@j[.@i] * .Modifier[2];

	next;
	mes "[Missões de Caça]";
	mes "Recompensas da missão:";
	mes " > Pontos de Missão: ^0055FF" + .@Mission_Points + "^000000";
	mes " > Experiência Básica: ^0055FF" + F_InsertComma(.@Base_Exp) + "^000000";
	mes " > Experiência Classe: ^0055FF" + F_InsertComma(.@Job_Exp) + "^000000";
	mes " > Zeny: ^0055FF" + F_InsertComma(.@Zeny) + "^000000";
	if (@f) {
		@f = false;
		return;
	}
	next;
	mes "[Missões de Caça]";
	mes "Oh, você terminou!";
	mes "Bom trabalho.";
	mes "Aqui está sua recompensa.";
	emotion ET_BEST;
	specialeffect2 EF_ANGEL;
	specialeffect2 EF_TRUESIGHT;
	#Mission_Points += .@Mission_Points;
	BaseExp += .@Base_Exp;
	JobExp += .@Job_Exp;
	Zeny += .@Zeny;
	for (.@i = 0; .@i < .Quests; .@i++) {
		setd "Missão" + .@i, 0;
		setd "Missão" + .@i+"_", 0;
	}
	#Mission_Count = 0;
	if (.Delay)
		#Mission_Delay = gettimetick(2) + (.Delay * 3600);
	Mission_Total++;
	if (Mission_Total == 1)
		query_sql("INSERT INTO `char_reg_num` (`char_id`,`key`,`index`,`value`) VALUES (" + getcharid(0) + ",'Mission_Total','0',1)");
	else
		query_sql("UPDATE `char_reg_num` SET `value` = " + Mission_Total + " WHERE `char_id` = " + getcharid(0) + " AND `key` = 'Mission_Total'");
	close;

Mission_Info:
	mes "[Missões de Caça]";
	mes "Se você quiser, eu posso atribuir";
	mes "uma missão de caça aleatória.";
	mes "Alguns são mais fáceis que outros, mas";
	mes "as recompensas aumentam com dificuldade.";
	next;
	mes "[Missões de Caça]";
	mes "Pontos de missão são compartilhados";
	mes "entre todos os seus personagens.";
	if (.Delay)
		mes "O tempo de atraso também.";
	mes "Você não pode realizar missões";
	mes "vários personagens ao mesmo tempo.";
	next;
	mes "[Missões de Caça]";
	mes "Você pode começar uma missão";
	mes (.Delay ? "a cada " + ((.Delay == 1) ? "hora." : .Delay + " horas.") : "sempre que você quiser.");
	mes "Isso é tudo~";
	return;

function Chk {
	if (getarg(0) < getarg(1)) {
		@f = true;
		return "^FF0000";
	} else
		return "^00FF00";
}

OnBuyItem:
	.@size = getarraysize(@bought_nameid);
	for (.@i = 0; .@i < .@size; .@i++) {
		.@j = inarray(.Shop, @bought_nameid[.@i]);
		.@cost += (.Shop[.@j+1] * @bought_quantity[.@i]);
	}
	mes "[Missões de Caça]";
	if (.@cost > #Mission_Points)
		mes "Você não tem Pontos de Missão suficientes.";
	else {
		for (.@i = 0; .@i < .@size; .@i++) {
			getitem @bought_nameid[.@i], @bought_quantity[.@i];
			dispbottom "Comprado " + @bought_quantity[.@i] + "x " + getitemname(@bought_nameid[.@i]) + ".";
		}
		#Mission_Points -= .@cost;
		mes "Negócio concluído.";
		emotion ET_MONEY;
	}
	deletearray @bought_nameid[0], .@size;
	deletearray @bought_quantity[0], .@size;
	close;

OnNPCKillEvent:
	if (!getcharid(1) || !.Party) {
		if (!#Mission_Count || !Mission0) end;
		for (.@i = 0; .@i < .Quests; .@i++) {
			if (getmonsterinfo(killedrid, MOB_NAME) == getmonsterinfo(getd("Missão" + .@i), MOB_NAME)) {
				if (getd("Missão" + .@i + "_") < #Mission_Count) {
					dispbottom "[Missão de Caça] Morto " + (set(getd("Missão" + .@i + "_"),getd("Missão" + .@i + "_") + 1)) +
					           " of " + #Mission_Count + " " + getmonsterinfo(killedrid, MOB_NAME) + ".";
					end;
				}
			}
		}
	} else if (.Party) {
		.@mob = killedrid;
		getmapxy(.@map1$,.@x1,.@y1);
		getpartymember getcharid(1),1;
		getpartymember getcharid(1),2;
		for (.@i = 0; .@i < $@partymembercount; .@i++) {
			if (isloggedin($@partymemberaid[.@i], $@partymembercid[.@i])) {
				set .@Mission_Count, getvar(#Mission_Count, $@partymembercid[.@i]);
				set .@Mission0, getvar(Mission0, $@partymembercid[.@i]);
				set .@HP, readparam(HP, $@partymembercid[.@i]);

				if (.@Mission_Count && .@Mission0 && .@HP > 0) {
					getmapxy(.@map2$,.@x2,.@y2,BL_PC,rid2name($@partymemberaid[.@i]));
					if ((.@map1$ == .@map2$ || .Party == 1) && (distance(.@x1,.@y1,.@x2,.@y2) <= 30 || .Party < 3)) {
						for (.@j = 0; .@j < .Quests; .@j++) {
							.@my_mob_id = getvar( getd("Missão"+.@j),$@partymembercid[.@i] );
							.@my_count = getvar( getd("Missão"+.@j+"_"), $@partymembercid[.@i] );
							if (getmonsterinfo(.@mob, MOB_NAME) == getmonsterinfo(.@my_mob_id, MOB_NAME)) {
								if (.@my_count < .@Mission_Count) {
									setd "Missão"+.@j+"_", (.@my_count+1), $@partymembercid[.@i];
									dispbottom "[Missão de Caça] Morto " + (.@my_count+1) + " of " + .@Mission_Count + " " + getmonsterinfo(.@mob, MOB_NAME) + ".", 0x777777, $@partymembercid[.@i];
									break;
								}
							}
						}
					}
				}
			}
		}
	}
	end;

OnInit:
	.Delay = 0;            // Quest delay, in hours (0 to disable).
	.Quests = 4;            // Number of subquests per mission (increases rewards).
	.Party = 2;             // Party options: 0 (exclude party kills), 1 (include party kills), 2 (same map only), 3 (screen area only)
	.Reset = -1;            // Reset options: -1 (abandoning mission sets delay time), 0 (no delay time), [Zeny] (cost to abandon mission, no delay time)
	setarray .Count[0],     // Min and max monsters per subquest (increases rewards).
		40,70;
	setarray .Modifier[0],  // Multipliers for Base Exp, Job Exp, and Zeny rewards.
		getbattleflag("base_exp_rate")/100,getbattleflag("job_exp_rate")/100,60;
	.mob_db$ =              // Table name of SQL mob database
		(checkre(0))?"mob_db_re":"mob_db";
	setarray .Shop[0],      // Reward items: <ID>,<point cost> (about 10~20 points per hunt).
		512,1,513,1,514,1,538,5,539,5,558,10,561,10;
	.Blacklist$ =           // Blacklisted mob IDs.
		"1062,1088,1183,1186,1200,1212,1220,1221,1234,1235,"+
		"1244,1245,1250,1268,1290,1293,1294,1296,1298,1299,"+
		"1300,1301,1303,1304,1305,1306,1308,1309,1311,1313,"+
		"1515,1588,1618,1676,1677,1678,1679,1796,1797,1974,"+
		"1975,1976,1977,1978,1979";

	npcshopdelitem "mission_shop",512;
	for (.@i = 0; .@i < getarraysize(.Shop); .@i += 2)
		npcshopadditem "mission_shop", .Shop[.@i], .Shop[.@i+1];
	end;
}
-	shop	mission_shop	-1,512:-1
