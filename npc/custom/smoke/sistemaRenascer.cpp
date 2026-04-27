//===== NexoMMORPG Script ==================================================================================
//= Rebirth & Reset Stats / Skills / Maps for Adjustable Star Gladiator.
//===== By: ================================================================================================
//=  JinYuichi
//===== Last Updated: ======================================================================================
//= 02/07/2024
//===== Description: =======================================================================================
//= Added Cost in Zeny "(Editable)" : Version: 1.1
//= Added Max Level "(Editable)" : Version: 1.2
//= Added Max Rebirth 5 "(Editable)" : Version: 1.3
//= Added Stats per Rebirth "(Editable)" : Version: 1.4
//= Added Cash Required for Level 4 and 5 "(Editable)" : Version: 1.5
//= Added Option to Enable/Disable Cash Points for Rebirths 4 and 5 : Version: 1.6
//= Added Class Restriction "(Editable)" By Hyroshima : Version 1.7
//= Added Reset Stats / Skills / Star Gladiator Maps : Version 1.8
//= Added Verification for those who do not have rebirth to use the Reset options : Version 1.9
//==========================================================================================================
//= Traduzido por @sistemaemundus
//= Alterado para 4th class

mall01,99,131,5	script	Padre das Trevas	1198,{

    // Initial settings
    set .@cost, 5000000;       // Cost for Rebirth
    set .@blvl, 250;          // Minimum Base Level for Rebirth
    set .@max_rebirth, 5;    // Maximum number of rebirths
    
    // Additional stat points per rebirth
    setarray .@bstats[0], 200, 400, 600, 800, 1000;
    
    // Items required for rebirth (Item ID, Quantity)
    setarray .@items_id[0], 671;  // Required item IDs
    setarray .@items_qty[0], 1000;       // Required quantities of each item
    
    // Cash Points required for rebirth 4 and 5
    set .@cashpoint_cost[3], 1000;  // Rebirth 4: 500 Cash Points
    set .@cashpoint_cost[4], 5000; // Rebirth 5: 1000 Cash Points
    
    // Option to enable/disable Cash Points for rebirths 4 and 5
    set .@use_cash_points, 1;  // 1 = Enabled, 0 = Disabled by default
    
    // Allowed classes IDs
    setarray .@allowed_classes[0], 4252, 4253, 4254, 4255, 4256, 4257, 4258, 4259, 4260, 4261, 4262, 4263, 4264, 4302, 4303, 4304, 4305, 4306, 4307, 4308;

    // Reset settings
    setarray .@Reset[0], 5000, 5000, 9000, 15000;

    // Welcome and introduction message
    mes "[^FF0000Padre das Trevas^000000]";
    mes "*Crack, Crack*";
    next;
    mes "[^FF0000Padre das Trevas^000000]";
    mes "Olá "+strcharinfo(0)+", Eu sou o ^0055FFPadre das Trevas^000000.";
    mes "Posso te ajudar com duas coisas importantes:";
    mes "1. Renascer para ganhar mais poder.";
    mes "2. Resetar seus Status, Skills & SG Maps.";
    next;

    // Main menu
	mes "[^FF0000Padre das Trevas^000000]";
    mes "O que você gostaria de fazer hoje?";
    switch(select("Renascer:Resetar Status/Skills/SG Maps:Cancelar")) {
        case 1:
            // Check if the maximum number of rebirths has been reached
            if (Rebirth >= .@max_rebirth) {
                mes "[^FF0000Padre das Trevas^000000]";
                mes "Desculpe, mas você já atingiu o número máximo de renascimentos permitidos.";
                close;
            }

            // Confirmation and explanation of the rebirth process
            mes "Este será o seu "+(Rebirth + 1)+"º Renascimento.";
            next;
            mes "Veja como funciona o renascimento:";
            mes "Quando você atinge o Base Level "+.@blvl+", você pode renascer como um High Novice Level 1 e receber pontos de status adicionais.";
            mes "Você receberá diferentes pontos de status de acordo com o número de renascimentos:";
            for (set .@i, 0; .@i < .@max_rebirth; set .@i, .@i + 1) {
                mes "Renascimento "+(.@i + 1)+"º: "+.@bstats[.@i]+" pontos de status.";
            }
            mes "Você pode renascer até "+.@max_rebirth+" vezes.";
            mes "Além do custo em Zeny, você precisará dos seguintes itens para renascer:";
            for (set .@i, 0; .@i < getarraysize(.@items_id); set .@i, .@i + 1) {
                mes .@items_qty[.@i]+" x "+getitemname(.@items_id[.@i]);
            }
            next;
            mes "Você está pronto para Renascer agora??";
            if (select("Sim:Não") == 2) {
                mes "Tudo bem, volte quando estiver pronto.";
                close;
            }
            
            // Pre-rebirth checks
            set .@missing_requirements, 0;

            if (BaseLevel < .@blvl) {
                mes "[^FF0000Padre das Trevas^000000]";
                mes "Você precisa atingir pelo menos o Base Level "+.@blvl+" para Renascer.";
                set .@missing_requirements, 1;
            }
            
            // Check if the class is allowed to rebirth
            if (inarray(.@allowed_classes, Class) == -1) {
                mes "[^FF0000Padre das Trevas^000000]";
                mes "Sua classe atual não pode renascer.";
                set .@missing_requirements, 1;
            }
            
            // Check for sufficient Zeny
            if (Zeny < .@cost) {
                mes "[^FF0000Padre das Trevas^000000]";
                mes "Você precisa de pelo menos "+.@cost+" Zeny para realizar o renascimento.";
                mes "Por favor, volte quando tiver o suficiente de Zeny.";
                set .@missing_requirements, 1;
            }
            
            // Check for required items
            for (set .@i, 0; .@i < getarraysize(.@items_id); set .@i, .@i + 1) {
                if (countitem(.@items_id[.@i]) < .@items_qty[.@i]) {
                    mes "[^FF0000Padre das Trevas^000000]";
                    mes "Você não tem todos os itens necessários para o renascimento:";
                    mes .@items_qty[.@i]+" x "+getitemname(.@items_id[.@i]);
                    set .@missing_requirements, 1;
                }
            }
            
            // Check for Cash Points for rebirths 4 and 5
            if (.@use_cash_points && (Rebirth >= 3 && Rebirth <= 4)) {
                if (#CASHPOINTS < .@cashpoint_cost[Rebirth]) {
                    mes "[^FF0000Padre das Trevas^000000]";
                    mes "Você precisa de pelo menos "+.@cashpoint_cost[Rebirth]+" Cash Points para realizar este renascimento.";
                    mes "Por favor, volte quando tiver o suficiente de Cash Points.";
                    set .@missing_requirements, 1;
                }
            }
            
            // Show missing requirements message and end if there are any missing requirements
            if (.@missing_requirements) {
                close;
            }
            
            // Perform the rebirth
            if (.@use_cash_points && (Rebirth >= 3 && Rebirth <= 4)) {
                set #CASHPOINTS, #CASHPOINTS - .@cashpoint_cost[Rebirth];
            }
            
            set Zeny, Zeny - .@cost;
            for (set .@i, 0; .@i < getarraysize(.@items_id); set .@i, .@i + 1) {
                delitem .@items_id[.@i], .@items_qty[.@i];
            }
            jobchange 4001;
            Resetlvl 1;            
            set StatusPoint, StatusPoint + .@bstats[Rebirth];
            set Rebirth, Rebirth + 1;
            mes "[^FF0000Padre das Trevas^000000]";
            mes "Parabéns, você renasceu!";
            close;

        case 2:
            // Reset menu
            mes "[^FF0000Padre das Trevas^000000]";
            mes "Posso resetar seus status e/ou skills por um preço:";
            mes "Resetar status: "+callfunc("F_InsertComma", .@Reset[1])+"z";
            mes "Resetar skills: "+callfunc("F_InsertComma", .@Reset[0])+"z";
            mes "Resetar ambos: "+callfunc("F_InsertComma", .@Reset[2])+"z";
            mes "Resetar SG maps: "+callfunc("F_InsertComma", .@Reset[3])+"z";
            next;
            set .@i, (select("Resetar skills:Resetar status:Resetar ambos:Resetar Star Gladiator maps:Cancelar"));
            if (.@i > 4) close;
            mes "[^FF0000Padre das Trevas^000000]";
            if (Zeny < .@Reset[.@i - 1]) {
                mes "Desculpe, você não tem Zeny suficiente.";
                close;
            }
            set Zeny, Zeny - .@Reset[.@i - 1];
            if (.@i & 1) {
                sc_end_class;
                ResetSkill;
            }
            if (.@i & 2) ResetStatus;
            if (.@i == 4) {
                // Reset Star Gladiator maps
                if (Class == Job_Star_Gladiator) {
                    mes "Eu vou redefinir os seus designados maps.";
                    next;
                    atcommand "@feelreset";
                } else {
                    mes "Somente Star Gladiators podem redefinir seus maps.";
                }
            }
            mes "Feito!";
            close;

        case 3:
            mes "[^FF0000Padre das Trevas^000000]";
            mes "Tudo bem... volte logo.";
            close;
    }
}
