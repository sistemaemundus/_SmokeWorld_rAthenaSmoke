// Container que dá uma arma Frontier aleatória 840135
function	script	caixaArmasFrontier	{
	// Lista de IDs de itens possíveis
	setarray(.@itens,510192, 530072, 540110, 540111, 550176, 550177, 550178, 560081, 570087, 580087, 590107, 600071, 610085, 620058, 640064, 640065, 650058, 700119, 810049);

	// Escolhe um item aleatório
	.@escolhido = .@itens[rand(0, getarraysize(.@itens) - 1)];

	// Verifica se o jogador consegue receber o item
	if (!checkweight(.@escolhido, 1)) {
		message strcharinfo(0),"Você não pode carregar este item! Verifique espaço e peso no inventário.";
		getitem 840135,1;
		end;
	}

	// Dá o item
	getitem .@escolhido, 1;
	message strcharinfo(0),"Parabéns! Você obteve "+getitemname(.@escolhido)+ "!";
	end;
}

// Container que dá uma runa Frontier aleatória 840164
function	script	caixaRunasFrontier	{
    // ===============================
    // Array de Runas (drop normal)
    // ===============================
    setarray (.@runas, 840136, 840137, 840138, 840139, 840140, 840141, 840142, 840143, 840144, 840145, 840146, 840147, 840148, 840149, 840150, 840151, 840152, 840153, 840154, 840155, 840156);

    // ===============================
    // Array de Catalisadores (ultra raro)
    // ===============================
    setarray (.@catalisadores, 840158, 840159, 840160, 840161);

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
		getitem 840164,1;
		end;
	}
	// Verifica se o jogador foi Sortudo e dá o item
	if (.@sortudo == 1) {
        getitem .@item, 1;
        specialeffect2 EF_MVP;
        announce "[Sortudo] "+strcharinfo(0)+" encontrou ["+getitemname(.@item)+"] em ["+getitemname(840164)+"]!!!",bc_all;
    } else {
        getitem .@item, 1;
    }
}