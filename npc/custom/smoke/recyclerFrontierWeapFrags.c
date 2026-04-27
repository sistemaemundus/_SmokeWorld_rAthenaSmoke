//===== rAthena Script ===========================================|
//= Equipment Recycle NPC                                        =|
//===== By: ======================================================|
//= crazyarashi                                                  =|
//===== Current Version: =========================================|
//= 1.0 Initial Version                                          =|
//= 1.1 Fix Item Reward                                          =|
//================================================================|
//= A Recycle NPC that uses the shop for interface               =|
//===== Requirements: ============================================|
//= https://github.com/rathena/rathena/pull/4195/files           =|
//================================================================|

-	shop	recycleshop	-1,no,501:-1

-	script	equipment_recycle	-1,{
	disable_items;
	callshop "recycleshop",2;
	npcshopattach "recycleshop";
	end;
	
OnInit:
	.reward_type = false; //= true = Item / false = Points
	.refine_bonus = true;
	.card_check = true; //= Don't accept item with cards.
	.reward_id = 501;
	.reward_point$ = "#KAFRAPOINT";
	function list_create;
	function list_add;
	list_create();
end;
/*
*=============================================================================|
* .@r = Refine | .@b = Bonus                                                 =|
* list_add("<Equip ID>,<Value>{,<Starting .@r for .@b>,.@b1:.@b2:.@b3:..."); =|
*=============================================================================|	
* Cotton_Shirt w/ +8 Starting .@r bonus                                      =|
* .@r = 8 : 1 Bonus Item/Point                                               =|
* .@r = 9 : 5 Bonus Item/Point                                               =|
* .@r >= 10 : 7 Bonus Item/Point.                                            =|
*=============================================================================|
* list_add(2301,8,"1:5:7");                                                  =|
==============================================================================|
*/
function	list_create	{
	//= Remove samples and add here.
	
	list_add(2301,10,8,"1:5:7"); //Cotton_Shirt
	list_add(1201,10,7,"1:2:3:4:5"); //Knife
	list_add(2504,5); //Muffler_
	
	return;
}

function	list_add	{
	.@size = getarraysize(.eq_list$);
	.eq_list$[.@size] = getarg(0);
	.eq_list$[.@size+1] = getarg(1);
	.eq_list$[.@size+2] = 0;
	.eq_list$[.@size+3] = 0;
	if(getargcount() > 2){
		if(getarg(2) == 0) 
			.eq_list$[.@size+2] = 1; 
		else 
			.eq_list$[.@size+2] = getarg(2);
		if(getarg(3) == "")
			.eq_list$[.@size+3] = "1";
		else
			.eq_list$[.@size+3] = getarg(3);
	}
	return;
}

OnSellItem:
	function checkout;
	function add_bonus;
	function call_error;
	function clear_data;
	checkout();
	clear_data();
end;

function	checkout	{
	.@size = getarraysize(@sold_nameid);
	if(!.@size) 
		call_error(1);
	for(.@i = 0; .@i < .@size; .@i++){	
		if(getiteminfo(@sold_nameid[.@i],2) != IT_ARMOR && getiteminfo(@sold_nameid[.@i],2) != IT_WEAPON) continue;
		.@index = inarray(.eq_list$,@sold_nameid[.@i]);
		if(.@index == -1) continue;
		if(.card_check) if(@sold_card1[.@i] > 0) continue;
		uniqueid_delitem(@sold_uniqueid[.@i]);
		.@value = atoi(.eq_list$[.@index+1]);
		if(.refine_bonus == true && atoi(.eq_list$[.@index+2]) > 0 && @sold_refine[.@i] >= atoi(.eq_list$[.@index+2]))
			.@bonus = add_bonus(@sold_refine[.@i],atoi(.eq_list$[.@index+2]),.eq_list$[.@index+3]);
		.@total += .@value + .@bonus;
		.@disp$[getarraysize(.@disp$)] = (@sold_refine[.@i] > 0 ? "+" + @sold_refine[.@i] : "") + " " + getitemname(@sold_nameid[.@i]) + " : " + (.@value + .@bonus);
		.@sold++;
	}
	if(!.@sold)
		call_error(2);
	dispbottom "|================= Total : " + .@total + " =================|",0xFFA500;
	for(.@i = 0; .@i < .@sold; .@i++)
		dispbottom "| " + .@disp$[.@i],0xFFA500;
	if(!.reward_type)
		setd(.reward_point$,getd(.reward_point$) + .@total);
	else
		getitem .reward_id,.@total;
	dispbottom "|============================================|",0xFFA500;
	return;
}

function	add_bonus	{
	.@index = getarg(0) - getarg(1);
	explode(.@T$,getarg(2),":");
	.@size = getarraysize(.@T$);
	if(.@index > (.@size-1))
		return atoi(.@T$[.@size-1]);
	else
		return atoi(.@T$[.@index]);
}

function	call_error	{
	switch(getarg(0)){
		case 1:
			dispbottom "No items were added to the shop.",0xFFA500;
			clear_data();
			
		case 2:
			dispbottom "There is no recyclable equipment on the items that were sold.",0xFFA500;
			clear_data();
	}
}

function	clear_data	{
	deletearray @sold_quantity, getarraysize(@sold_quantity);
	deletearray @sold_nameid, getarraysize(@sold_nameid);
	deletearray @sold_uniqueid, getarraysize(@sold_uniqueid);
	end;
}

}