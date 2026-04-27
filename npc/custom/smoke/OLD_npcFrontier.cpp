mall01,72,107,5	script	Nelson Frontier	534,{
    if (countitem(840157) == 0) {        
        mes "[Nelson Frontier]";
        mes "Boas vindas, "+strcharinfo(0)+"!";
        mes "Venho de muito longe, e trago informações";
        mes "valiosas e de grande poder!";
        next;
        clear;
        mes "[Nelson Frontier]";
        mes "Precisaremos de alguns artefatos que provém de onde eu venho...";
        mes "A Grande Frontier!";
        next;
        clear;
        mes "[Nelson Frontier]";
        mes "Em posse dos artefatos específicos posso lhe prover";
        mes "algo de poder inimaginável...";
        mes "Algo que vai além da percepção e do poder da humanidade!";
        next;
        clear;
        mes "[Nelson Frontier]";
        mes "Você teria interesse em saber mais?";
        if(select("Não, obrigado...:Continue falando...") == 1){
            clear;
            mes "[Nelson Frontier]";
            mes "Eu imaginei...";
            close;
        } else {
            Story:
            clear;
            mes "[Nelson Frontier]";
            mes "Bom, vamos lá!";
            next;
            clear;
            mes "[Nelson Frontier]";
            mes "No seu mundo há criaturas que guardam algo magnífico,";
            mes "um poder além da capacidade deles próprios controlarem.";
            next;
            clear;
            mes "[Nelson Frontier]";
            mes "Preciso que você, jovem "+strcharinfo(0)+",";
            mes "elimine tais criaturas para obter esses artefatos";
            next;
            clear;
            mes "[Nelson Frontier]";
            mes "E com eles em posse, poderemos trabalhar";
            mes "em prol da sua evolução para um poder";
            mes "no qual você não sabia que existia!";
			next;
			if (countitem(840157) >= 1) {
				clear;
                mes "[Nelson Frontier]";
                mes "Até mais!";
                close;
			} else {
				clear;
				mes "[Nelson Frontier]";
				mes "Fique com este arfetato de amostra,";
				mes "ele vai servir como uma chave para nossa comunicação!";
				getitem 840157,1;
				close;
			}
        }
    } else {
        mes "[Nelson Frontier]";
        mes "Olá, como está?";
        switch(select("Produzir artefatos.:Informações.:Cancelar")) {
            case 1:
                clear;
				mes "[Nelson Frontier]";
				mes "Vamos lá!";
				close2;
                callshop "nelsonFrontier",1;
				break;
            case 2:
                goto Story;
            case 3:
                clear;
                mes "[Nelson Frontier]";
                mes "Ok, até a próxima!";
                close;
        }
    }
    if (countitem(840158) == 1 && countitem(840159) == 1 && countitem(840160) == 1 && countitem(840161) == 1) {
        mes "[Nelson Frontier]";
        mes "Vejo que você está em posse de todos os artefatos";
        mes "catalisadores...";
        next;
        clear;
        mes "[Nelson Frontier]";
        mes "Gostaria despertar o poder oculto neles?";
        if (select("Agora não...:Vamos nessa!") == 1) {
            clear;
            mes "[Nelson Frontier]";
            mes "Ok, até a próxima!";
            close;
        } else {
            clear;
            mes "[Nelson Frontier]";
            mes "Minha nossa, quanto poder!";
            specialeffect2 EF_SPHEREWIND;
            delitem 840157,1;
            delitem 840158,1;
            delitem 840159,1;
            delitem 840160,1;
            delitem 840161,1;
            getitem 840135,1;
            next;
            clear;
            mes "[Nelson Frontier]";
            mes "Tenho medo do que você vai fazer com isso em mãos...";
            close;
        }
    }
}