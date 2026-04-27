// Container que dá uma Coroa Frontier aleatória 840192
function	script	caixaCoroasFrontier	{
	// Lista de IDs de itens possíveis
	setarray(.@itens, 400975, 400976, 400977, 400978, 400979, 400980, 400981, 400982, 400983, 400984, 400985, 400986, 400987, 400988, 400989, 400990, 400991, 400992);

	// Escolhe um item aleatório
	.@escolhido = .@itens[rand(0, getarraysize(.@itens) - 1)];

	// Verifica se o jogador consegue receber o item
	if (!checkweight(.@escolhido, 1)) {
		message strcharinfo(0),"Você não pode carregar este item! Verifique espaço e peso no inventário.";
		getitem 840192,1;
		end;
	}

	// Dá o item
	getitem .@escolhido, 1;
	message strcharinfo(0),"Parabéns! Você obteve "+getitemname(.@escolhido)+ "!";
	end;
}

// Container que dá uma runa Frontier Coroa aleatória 840191
function	script	caixaRunasCoroasFrontier	{
    // ===============================
    // Array de Runas (drop normal)
    // ===============================
    setarray (.@runas, 840165, 840166, 840167, 840168, 840169, 840170, 840171, 840172, 840173, 840174, 840175, 840176, 840177, 840178, 840179, 840180, 840181, 840182, 840183, 840184);

    // ===============================
    // Array de Catalisadores (ultra raro)
    // ===============================
    setarray (.@catalisadores, 840187, 840188, 840189, 840190);

    // ===============================
    // Chance de Catalisador  
    // ===============================
    // 1 = ganha catalisador
    // 0 = ganha runa
    if (rand(10000) < 20) { // 0.2% chance
        // sorteia catalisador
        .@item = .@catalisadores[rand(getarraysize(.@catalisadores))];
        .@sortudo = 1;
    } else {
        // sorteia runa
        .@item = .@runas[rand(getarraysize(.@runas))];
        .@sortudo = 0;
    }
	// Verifica se o jogador consegue receber o item
	if (!checkweight(.@item, 1)) {
		message strcharinfo(0),"Você não pode carregar este item! Verifique espaço e peso no inventário.";
		getitem 840191,1;
		end;
	}
	// Verifica se o jogador foi Sortudo e dá o item
	if (.@sortudo == 1) {
        getitem .@item, 1;
        specialeffect2 EF_MVP;
        announce "[Sortudo] "+strcharinfo(0)+" encontrou ["+getitemname(.@item)+"] em ["+getitemname(840191)+"]!!!",bc_all;
    } else {
        getitem .@item, 1;
    }
}