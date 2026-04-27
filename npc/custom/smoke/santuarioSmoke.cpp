//= Santuario Smoke
//= Modificado & traduzido por Alek Emundus
//=========================================
//= Mesmo esquema da FarmZone, porém adapatada para farmar EXP ao invés de itens/pontos.

prontera,167,176,4	script	Santuario Smoke	588,{
//function	RandomizeItem;

while( 1 ){
	mes "[Santuario Smoke]";
	mes "Como posso te ajudar?";
switch( select( "- Informações:- Participar" )){
Case 1:
	clear;
	mes "[Santuario Smoke]";
	mes "O Santuario Smoke...";
	mes "Você poderá subir de nível nesta sala, mas não receberá loot dos mobs.";
	next;
	mes "Mas há algumas condições..";
	mes "Você só pode entrar ^FF0000uma vez a cada "+.RoomCleanMin+" minutos por vez.^000000";
	mes "E máximo de ^FF0000"+.MaxPlayers+" Players por "+.RoomCleanMin+" Minutos.^000000";
	//mes "Limite máximo de farm: ^FF0000"+.MaxItemLimit+"^000000";
	next;
	mes "Acontecerá a ^FF0000Conclusão do Experimento^000000 a cada "+.RoomCleanMin+" Minutos.";
	mes "Todos os jogadores serão expulsos, e será seu azar se acontecer com você lá dentro...";
	mes "^FF0000O atraso ainda será aplicado mesmo que você entre por apenas 1 segundo...^000000";
	next;
	break;

Case 2:
	if ( BaseLevel >= 275 ) {
		clear;
		mes "[Santuario Smoke]";
		mes "Você já está no nível máximo!";
		mes "Não é possível entrar no Santuário.";
		close;
	}

	if( #SantuarioDelay > gettimetick(2) ){
		set .last,#SantuarioDelay - gettimetick(2);
		set .@min,  .last % ( 24 * 3600 ) % 3600 / (60);
		mes "Espere por ^FF0000"+.@min+" Minutos^000000.";
		close;
	}else if( getarraysize( .Players ) >= .MaxPlayers ){
		mes "Atualmente a sala está lotada, volte depois.";
		close;
	}else{
		warp .Map$,0,0;
		set .Players[getarraysize( .Players )],strcharinfo(0);
		set #SantuarioDelay,gettimetick(2) + ( .DelayMin * 60 );
		//set #FarmHunt,0;
		end;
		}
	}
}

OnInit:
// Maximum Player can join per X Minutes.
set .MaxPlayers,10;

// Adding X Minutes of Delay before can go in again.
set .DelayMin,0;

// Maximum Hunt Limit per round inside the Zone.
//set .MaxItemLimit,200;

// Map that will be used in thos Zone.
set .Map$,"ordeal_2-1";

// Clear Map Every X Minutes.
set .RoomCleanMin,2;

// Quantidade de mobs Espécime
set .MobEspecime,100;

// Quantidade de mobs Guardião/Guardian.
//set .MobGuardian,2;

// Mapflag Initialization
setmapflag .Map$,mf_noreturn;
setmapflag .Map$,mf_noteleport;
setmapflag .Map$,mf_nomobloot;
setmapflag .Map$,mf_nomvploot;
setmapflag .Map$,mf_nowarp;
setmapflag .Map$,mf_nowarpto;
setmapflag .Map$,mf_nomemo;
setmapflag .Map$,mf_novending;
setmapflag .Map$,mf_nobranch;
setmapflag .Map$,mf_nopenalty;
setmapflag .Map$,mf_monster_noteleport;

while( 1 ){
	killmonster .Map$,"All";
	mapwarp .Map$,"prontera",156,191;
	monster .Map$,0,0,"Espécime",-1,.MobEspecime,strnpcinfo(0)+"::OnNormalKill";
	//monster .Map$,0,0,"[ Santuario Smoke ] Guardião",-3,.MobGuardian,strnpcinfo(0)+"::OnBossKill";
	deletearray .Players,getarraysize( .Players );
	//announce "[ Santuario Smoke ] : Santuario Smoke limpo, outros "+.MaxPlayers+" jogadores podem se juntar.",bc_blue;
	sleep ( .RoomCleanMin * 60000 );
	mapannounce .Map$,"[ Santuario Smoke ] : Experimento concluído! Todos os players presentes serão expulsos.",0;
	killmonster .Map$,"All";
	sleep 3000;
	}
end;

OnNormalKill:
if ( BaseLevel >= 275 ) {
	dispbottom "[ Santuario Smoke ] : Você atingiu o nível máximo.";
	warp "prontera",156,191;
	end;
}
//RandomizeItem( 0,rand(1,5) );
//RandomizeItem( 0,1 );
monster .Map$,0,0,"Espécime",-1,1,strnpcinfo(0)+"::OnNormalKill";
//set #FARMCOIN, #FARMCOIN + 1;
//dispbottom "[ Santuario Smoke ] : 1 FarmCoin ganha, total: "+#FARMCOIN;
end;

/*OnBossKill:
//RandomizeItem( 1,rand(1,3) );
RandomizeItem( 1,1 );
monster .Map$,0,0,"--ja--",-3,1,strnpcinfo(0)+"::OnBossKill";
set #FARMCOIN, #FARMCOIN + 10;
dispbottom "[ Santuario Smoke ] : 10 FarmCoin ganha, total: "+#FARMCOIN;
end;*/

// Function that used to Generate Random Items -> Inutilizado no Santuario

/*function	RandomizeItem	{
set #FarmHunt,#FarmHunt + getarg(1);

// Normal Monster in Zone Drops Lists
if( getarg(0) == 0 ) setarray .ItemList[0],12710,12596,100233,12437,100232;
// Normal Boss in Zone Drops Lists
if( getarg(0) == 1 ) setarray .ItemList[0],840095,840096;

for( set .@i,1; .@i <= getarg(1); set .@i,.@i + 1 ){
	getitem .ItemList[ rand( getarraysize( .ItemList ) ) ],1;
	}
deletearray .ItemList,getarraysize( .ItemList );
dispbottom "[ Santuario Smoke ] : Farmou "+#FarmHunt+" / "+.MaxItemLimit+" Itens";
if( #FarmHunt >= .MaxItemLimit ){
	message strcharinfo(0),"Chegou ao limite, poderá entrar novamente depois.";
	sleep2 2000;
	warp "prontera",155,181;
	}
return;
}*/
	
}
-	script	SantuarioSmoke_LevelCheck	-1,{

OnPCBaseLvUpEvent:
	if ( BaseLevel >= 275 && strcharinfo(3) == "ordeal_2-1" ) {
		dispbottom "[ Santuario Smoke ] : Você atingiu o nível máximo e será removido da sala.";
		sleep2 2000;
		warp "prontera",156,191;
	}
	end;

}