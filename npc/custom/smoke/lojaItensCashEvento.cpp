//===== rAthena Script
// Criado por Alek Emundus
// NPCs vendendo itens que, normalmente, são de Cash/Evento
// =====================================================
// NPC: Vendedor Especial (Menu)
// Descrição: Exibe um menu com categorias e chama as lojas definidas abaixo.
// =====================================================

// ========== DEFINIÇÃO DAS LOJAS (padrão rAthena) ==========
// Cada shop é um NPC independente, com seus próprios itens e preços.
// Os nomes das lojas devem corresponder aos usados no callshop.

// Loja de Acessórios
-	shop	AccessoryShop	-1,420006:5000000

// Loja de Garments
-	shop	GarmentShop	-1,420110:5000000,19495:5000000,20745:5000000,28502:5000000

// Loja de Head Top
-	shop	HeadTopShop	-1,19140:5000000,19436:5000000,19102:5000000,19249:5000000,19296:5000000,5907:5000000,400022:5000000,400049:5000000,400061:5000000,400054:5000000,400044:5000000,400021:5000000,400011:5000000,5208:5000000,5897:5000000,19426:5000000,18823:5000000,19138:5000000,19327:5000000,19101:5000000,19380:5000000,19274:5000000,19299:5000000,18791:5000000

// Loja de Head Middle
-	shop	HeadMidShop	-1,19444:5000000,2202:5000000

// Loja de Head Lower
-	shop	HeadLowShop	-1,28565:5000000,19306:5000000,18564:5000000,19268:5000000

// ========== NPC MENU ==========
// Este NPC exibe as opções e chama as lojas usando callshop.
mall01,94,97,4	script	Vendedor Especial	405,{
    mes "[Vendedor Especial]";
    mes "Olá, sou o vendedor de equipamentos especiais.";
    mes "^00BFFFTenho itens que, normalmente, são encontrados apenas em eventos ou na loja de Cash.^000000";
    mes "Escolha uma categoria:";
    next;
    switch(select(
        "Acessórios:Garments:Head Top:Head Middle:Head Lower:Cancelar"
    )) {
    case 1:
        close2;
        callshop "AccessoryShop", 1;
        end;
    case 2:
        close2;
        callshop "GarmentShop", 1;
        end;
    case 3:
        close2;
        callshop "HeadTopShop", 1;
        end;
    case 4:
        close2;
        callshop "HeadMidShop", 1;
        end;
    case 5:
        close2;
        callshop "HeadLowShop", 1;
        end;
    case 6:
        mes "[Vendedor Especial]";
        mes "Até a próxima!";
        close;
    }
    end;
}