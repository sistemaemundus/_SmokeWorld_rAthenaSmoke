// =======================================================
// Smoke Runes & Containers System
// Criador: Alek Emundus
// GodLike agora é dado via Renascimento/Rebirth
// =======================================================
function	script	smoke_runes	{
    .@tipo = getarg(0); // 0 = Vida, 1 = Fogo, 2 = Gelo, 3 = Morte, 4 = Ancestral, 5 = Divina
    .@falha$ = "Você não possui a quantidade necessária de fragmentos!";
    .@sucesso$ = "Você conseguiu criar a runa!";
    .@erro$ = "Algo deu errado!";

    if(.@tipo == 0) { // Vida
        if(countitem(840103) < 50) {
            message strcharinfo(0), .@falha$;
            //getitem 840103,1;
            close2;
			end;
        } else {
            delitem 840103,50;
			delitem 840115,1;
            getitem 840109,1;
            message strcharinfo(0), .@sucesso$;
            close2;
			end;
        }
    }
    else if(.@tipo == 1) { // Fogo
        if(countitem(840104) < 50) {
            message strcharinfo(0), .@falha$;
            //getitem 840104,1;
            close2;
			end;
        } else {
            delitem 840104,50;
			delitem 840116,1;
            getitem 840110,1;
            message strcharinfo(0), .@sucesso$;
            close2;
			end;
        }
    }
    else if(.@tipo == 2) { // Gelo
        if(countitem(840105) < 50) {
            message strcharinfo(0), .@falha$;
            //getitem 1001140,1;
            close2;
			end;
        } else {
            delitem 840105,50;
			delitem 840117,1;
            getitem 840111,1;
            message strcharinfo(0), .@sucesso$;
            close2;
			end;
        }
    }
    else if(.@tipo == 3) { // Morte
        if(countitem(840106) < 50) {
            message strcharinfo(0), .@falha$;
            //getitem 1001141,1;
            close2;
			end;
        } else {
            delitem 840106,50;
			delitem 840118,1;
            getitem 840112,1;
            message strcharinfo(0), .@sucesso$;
            close2;
			end;
        }
    }
    else if(.@tipo == 4) { // Ancestral
        if(countitem(840107) < 50) {
            message strcharinfo(0), .@falha$;
            //getitem 1001141,1;
            close2;
			end;
        } else {
            delitem 840107,50;
			delitem 840119,1;
            getitem 840113,1;
            message strcharinfo(0), .@sucesso$;
            close2;
			end;
        }
	}
    else if(.@tipo == 5) { // Divina
        if(countitem(840108) < 50) {
            message strcharinfo(0), .@falha$;
            //getitem 1001141,1;
            close2;
			end;
        } else {
            delitem 840108,50;
			delitem 840120,1;
            getitem 840114,1;
            message strcharinfo(0), .@sucesso$;
            close2;
			end;
        }
	}
    else {
        message strcharinfo(0), .@erro$;
        close2;
		end;
    }
}

// =======================================================
// Smoke Anvil NPC
// =======================================================
prontera,142,173,5	script	Blatt Divina	2363,{
	if (countitem(840100) < 1 || countitem(840099) < 1) { 
	//mes "Você precisa possuir a Fornalha Divina e o Martelo dos Deuses para falar comigo!";
	mes "Você precisa possuir "+mesitemlink(840100)+mesitemicon(840100)+" e "+mesitemlink(840099)+mesitemicon(840099)+" para falar comigo!";
	close2;
	end;
	}
	mes "[Blatt Divina]";
	mes "O que temos aqui, hein?!";
	next;
	switch(select("- Elevar o poder!:- Upgrade de Tier!:- Cancelar")) {
		case 1:
		    switch(select("Elevar para Phoenix!:Elevar para Azur!:Elevar para Ascension!:Cancelar")) {
			case 1:
				close2;
				callfunc "smoke_containers",0;
				end;
				break;
			break;
			case 2:
				close2;
				callfunc "smoke_containers",1;
				end;
				break;
			break;
			case 3:
				close2;
				callfunc "smoke_containers",2;
				end;
				break;
			break;
			case 4:
				close;
				end;
				break;
			}
		case 2:
			clear;
			mes "[Blatt Divina]";
			mes "Tem certeza que gostaria de dar o Upgrade de Tier?";
			mes "Uma vez escolhido, nada poderá ser desfeito!";
			mes "Mas, não se preocupe:";
			mes "Caso seu item possua cartas, elas serão mantidas!";
			next;
			switch(select("Sim:Não")){
			case 1:
				close2;
				callfunc "smoke_upgrade";
				end;
				break;
			break;
			case 2:
				close;
				end;
				break;
			break;
			}
		case 3:
			close;
			end;
			break;
	}
}

function	script	smoke_upgrade	{

	//.@RUNA = 840113;

	/*if (countitem(.@RUNA) < 1) {
		dispbottom "Você precisa de uma "+mesitemlink(.@RUNA)+" para o upgrade!";
		close2;
		return;
	}*/

	// ==============================
	// GODLIKE
	// ==============================

	// T1 -> T2
	if (isequipped(840055) && isequipped(840056) && isequipped(840057)) {
		callfunc "smoke_upgrade_set",840055,840071,EQI_ARMOR,
		                  840056,840073,EQI_GARMENT,
		                  840057,840075,EQI_SHOES;
		return;
	}

	// T2 -> T3
	if (isequipped(840071) && isequipped(840073) && isequipped(840075)) {
		callfunc "smoke_upgrade_set",840071,840072,EQI_ARMOR,
		                  840073,840074,EQI_GARMENT,
		                  840075,840076,EQI_SHOES;
		return;
	}

	// ==============================
	// PHOENIX
	// ==============================

	if (isequipped(840058) && isequipped(840059) && isequipped(840060)) {
		callfunc "smoke_upgrade_set",840058,840077,EQI_ARMOR,
		                  840059,840078,EQI_GARMENT,
		                  840060,840079,EQI_SHOES;
		return;
	}

	if (isequipped(840077) && isequipped(840078) && isequipped(840079)) {
		callfunc "smoke_upgrade_set",840077,840080,EQI_ARMOR,
		                  840078,840081,EQI_GARMENT,
		                  840079,840082,EQI_SHOES;
		return;
	}

	// ==============================
	// AZUR
	// ==============================

	if (isequipped(840061) && isequipped(840062) && isequipped(840063)) {
		callfunc "smoke_upgrade_set",840061,840083,EQI_ARMOR,
		                  840062,840084,EQI_GARMENT,
		                  840063,840085,EQI_SHOES;
		return;
	}

	if (isequipped(840083) && isequipped(840084) && isequipped(840085)) {
		callfunc "smoke_upgrade_set",840083,840086,EQI_ARMOR,
		                  840084,840087,EQI_GARMENT,
		                  840085,840088,EQI_SHOES;
		return;
	}

	// ==============================
	// ASCENSION
	// ==============================

	if (isequipped(840064) && isequipped(840065) && isequipped(840066)) {
		callfunc "smoke_upgrade_set",840064,840089,EQI_ARMOR,
		                  840065,840090,EQI_GARMENT,
		                  840066,840091,EQI_SHOES;
		return;
	}

	if (isequipped(840089) && isequipped(840090) && isequipped(840091)) {
		callfunc "smoke_upgrade_set",840089,840092,EQI_ARMOR,
		                  840090,840093,EQI_GARMENT,
		                  840091,840094,EQI_SHOES;
		return;
	}

	// ==============================
	// TIER 3 BLOQUEIO
	// ==============================

	if (
		(isequipped(840072) && isequipped(840074) && isequipped(840076)) ||
		(isequipped(840080) && isequipped(840081) && isequipped(840082)) ||
		(isequipped(840086) && isequipped(840087) && isequipped(840088)) ||
		(isequipped(840092) && isequipped(840093) && isequipped(840094))
	) {
		dispbottom "Este set já atingiu o Tier máximo.";
		return;
	}

	dispbottom "Você precisa estar com o set completo equipado.";
	return;
}
// =====================================================
// SUBROTINA DE UPGRADE (MANTÉM CARTAS)
// =====================================================
function	script	smoke_upgrade_set	{

	.@RUNA_ELEMENTAL = 0;
	.@RUNA_ANCESTRAL = 840113; // fixa

	// Detecta pelo PRIMEIRO item passado
	.@base = getarg(0);

	// ==========================
	// DEFINE RUNA PELO SET REAL
	// ==========================

	switch (.@base) {

		// GODLIKE
		case 840055:
		case 840071:
			.@RUNA_ELEMENTAL = 840109;
			break;

		// PHOENIX
		case 840058:
		case 840077:
			.@RUNA_ELEMENTAL = 840110;
			break;

		// AZUR
		case 840061:
		case 840083:
			.@RUNA_ELEMENTAL = 840111;
			break;

		// ASCENSION
		case 840064:
		case 840089:
			.@RUNA_ELEMENTAL = 840112;
			break;

		default:
			dispbottom "Esse equipamento não pode ser refinado aqui.";
			return;
	}

	// ==========================
	// VERIFICA AS 2 RUNAS
	// ==========================

	if (countitem(.@RUNA_ELEMENTAL) < 1 || countitem(.@RUNA_ANCESTRAL) < 1) {
		dispbottom "Você precisa de "+mesitemlink(.@RUNA_ELEMENTAL)+" e "+mesitemlink(.@RUNA_ANCESTRAL);
		return;
	}

	// ==========================
	// REMOVE RUNAS (1 VEZ SÓ)
	// ==========================

	delitem .@RUNA_ELEMENTAL,1;
	delitem .@RUNA_ANCESTRAL,1;

	// ==========================
	// FAZ UPGRADE DAS PEÇAS
	// ==========================

	for (.@i = 0; .@i < getargcount(); .@i += 3) {

		.@old = getarg(.@i);
		.@new = getarg(.@i+1);
		.@slot = getarg(.@i+2);

		if (!isequipped(.@old)) continue;

		.@c1 = getequipcardid(.@slot,0);
		.@c2 = getequipcardid(.@slot,1);
		.@c3 = getequipcardid(.@slot,2);
		.@c4 = getequipcardid(.@slot,3);

		unequip(.@slot);
		delitem .@old,1;

		getitem2 .@new,1,1,0,0,.@c1,.@c2,.@c3,.@c4;
	}

	specialeffect2 EF_ENHANCE;
	dispbottom "As runas reagiram e evoluíram seu set!";
	return;
}
// =======================================================
// Smoke Containers
// =======================================================
function	script	smoke_containers	{
    .@tipo = getarg(0); // 0=Phoenix,1=Azur,2=Ascension (GodLike agora é dado via Renascimento/Rebirth)
    .@erro$ = "Algo deu errado!";
    .@falha$ = "Você não possui a runa necessária!";
    .@falha2$ = "Você não possui o set anterior e a runa necessária!";
    .@falha3$ = "O equipamento precisa estar equipado!";

    // Arrays simulados por variáveis separadas
    // Conjunto Anterior: Armadura, Manto, Botas
    //.@set0_armadura = 0;    .@set0_manto = 0;    .@set0_botas = 0;    .@runa0 = 840109; .@effect0 = EF_CHAINGEHOLY; .@container0 = 840067; .@announcecolor0 = 0xFFFF00;
    .@set0_armadura = 840072; .@set0_manto = 840074; .@set0_botas = 840076; .@runa0 = 840110; .@effect0 = EF_CHANGEFIRE; .@container0 = 840068; .@announcecolor0 = 0xFF3300;
    .@set1_armadura = 840080; .@set1_manto = 840081; .@set1_botas = 840082; .@runa1 = 840111; .@effect1 = EF_CHANGECOLD; .@container1 = 840069; .@announcecolor1 = 0x3399FF;
    .@set2_armadura = 840086; .@set2_manto = 840087; .@set2_botas = 840088; .@runa2 = 840112; .@effect2 = EF_CHANGEPOISON; .@container2 = 840070; .@announcecolor2 = 0x9900FF;

    // Escolher runa e set correto
    if(.@tipo == 0) { .@runa = .@runa0; .@equip0 = .@set0_armadura; .@equip1 = .@set0_manto; .@equip2 = .@set0_botas; .@effect = .@effect0; .@container = .@container0; .@announcecolor = .@announcecolor0; }
    if(.@tipo == 1) { .@runa = .@runa1; .@equip0 = .@set1_armadura; .@equip1 = .@set1_manto; .@equip2 = .@set1_botas; .@effect = .@effect1; .@container = .@container1; .@announcecolor = .@announcecolor1; }
    if(.@tipo == 2) { .@runa = .@runa2; .@equip0 = .@set2_armadura; .@equip1 = .@set2_manto; .@equip2 = .@set2_botas; .@effect = .@effect2; .@container = .@container2; .@announcecolor = .@announcecolor2; }
    //if(.@tipo == 3) { .@runa = .@runa3; .@equip0 = .@set3_armadura; .@equip1 = .@set3_manto; .@equip2 = .@set3_botas; .@effect = .@effect3; .@container = .@container3; .@announcecolor = .@announcecolor3; }

    // Checa se tem a runa
    if(countitem(.@runa) < 1) {
        message strcharinfo(0), .@falha$;
        return;
    }

    // =========================
    // GodLike não precisa de equipamentos
    // =========================
    if (.@tipo != 3) {

	// =====================================================
	// VERIFICA SE O SET ESTÁ COMPLETAMENTE EQUIPADO
	// =====================================================

	if (!isequipped(.@equip0) || !isequipped(.@equip1) || !isequipped(.@equip2)) {
		message strcharinfo(0), .@falha3$; // precisa estar equipado
		return;
	}

	// =====================================================
	// REMOVE E DEVOLVE CARTAS (SE EXISTIREM)
	// =====================================================

	getinventorylist(); // garante atualização interna

	// ARMOR
	for (.@i = 0; .@i < 3; .@i++) {
		.@card = getequipcardid(EQI_ARMOR, .@i);
		if (.@card > 0) {
			getitem .@card, 1;
		}
	}

	// GARMENT
	for (.@i = 0; .@i < 3; .@i++) {
		.@card = getequipcardid(EQI_GARMENT, .@i);
		if (.@card > 0) {
			getitem .@card, 1;
		}
	}

	// SHOES
	for (.@i = 0; .@i < 3; .@i++) {
		.@card = getequipcardid(EQI_SHOES, .@i);
		if (.@card > 0) {
			getitem .@card, 1;
		}
	}

	// =====================================================
	// REMOVE OS EQUIPAMENTOS
	// =====================================================

	unequip(EQI_ARMOR);
	unequip(EQI_GARMENT);
	unequip(EQI_SHOES);

	delitem .@equip0, 1;
	delitem .@equip1, 1;
	delitem .@equip2, 1;
	}

    // Retira a runa
    delitem(.@runa,1);

    // Aplica efeito e announce
    specialeffect2(.@effect);
    announce "[" + strcharinfo(0) + "] empunhou o Martelo dos Deuses sobre a Fornalha Divina, elevando o poder!", bc_all, .@announcecolor;

    // Dá o container
    getitem(.@container,1);
    return;
}
// ========================================
// REMOVE CARTAS DO SLOT E DEVOLVE AO PLAYER
// ========================================

function	script	Fn_RemoveCardsFromSlot	{

	.@slot = getarg(0);

	for(.@i = 0; .@i < 4; .@i++) {

		.@card = getequipcardid(.@slot,.@i);

		if(.@card > 0) {
			getitem .@card,1; // devolve carta pro inventário
		}
	}

	return;
}