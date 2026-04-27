//===== Script =======================================
//= “Try Before Buy” Rental Booth [v1.0] — (5-minute test rentals; blocks trade/party; auto-return; 24h rebate on purchase)
//===== By: =========================================
//= Checkmate (idea & implementation)
//===== Summary =====================================
//= Shop / Sales utility:
//= • Rent selected gears/cosmetics for a short demo (default 5 minutes).
//= • While renting, player is temporarily blocked from trade/party/storage/drop.
//= • When time ends, item auto-expires (rentitem) and blocks are lifted automatically.
//= • If the SAME item is purchased here within 24h, a % rebate is returned.
//= • Per-account cooldown between rentals; simple, tidy UI.
//= (Validate item IDs/prices via https://ratemyserver.net/)
//
// v1.1 (If Got Update)
// //= Add per-IP throttle + SQL logs.
// //= Separate “Cosmetic-only” pool and “Gear test” pool by level.
// //= Optional VIP longer demo or higher rebate.
//
//===================================================
//= QUICK SETUP
//= 1) Save as: npc/custom/rental_booth_try_before_buy.txt
//= 2) Edit CONFIG in OnInit: .ItemPool[], .PricePool[], .RentSeconds, .RebateRate, etc.
//= 3) @reloadscript. NPC spawns in Prontera (170,187) — duplicate anywhere.
//===================================================

prontera,170,187,3	script	Rental Booth#v1	4_F_TW_TREASURE,{

	// =========================================================
	// MAIN MENU
	// =========================================================
	mes "[Try-Before-Buy Booth]";
	switch (select("Rent Test Gear ("+ (.RentSeconds/60) +" min):Purchase & Claim Rebate:Help")) {

	// ---------------------------------------------------------
	// RENT: give a temporary (rentitem) demo and block risky actions
	// ---------------------------------------------------------
	case 1:
		// cooldown
		if (#RB_LastRent && gettimetick(2) < #RB_LastRent) {
			mes "Please wait ^FF0000"+ (#RB_LastRent - gettimetick(2)) +"s^000000 before renting again.";
			close;
		}

		// build menu of rentables
		.@sz = getarraysize(.ItemPool);
		if (!.@sz) { mes "No items available right now."; close; }

		mes "Pick an item to try ("+ (.RentSeconds/60) +" minutes):";
		.@menu$ = "";
		for (.@i=0; .@i<.@sz; .@i++) .@menu$ += getitemname(.ItemPool[.@i]) + " ["+ .PricePool[.@i] +"z]:";
		.@pick = select(.@menu$) - 1;

		// simple weight safety (demo items usually equip; adjust if needed)
		if (Weight >= MaxWeight) { mes "Please reduce your weight first."; close; }

		// if already renting something, deny
		if (#RB_RentItem && gettimetick(2) < #RB_RentEnd) {
			mes "You're already renting ^0055FF"+ getitemname(#RB_RentItem) +"^000000.";
			close;
		}

		// apply temporary blocks and give rent item
		callsub S_BlockOn;
		rentitem .ItemPool[.@pick], .RentSeconds;
		#RB_RentItem = .ItemPool[.@pick];
		#RB_RentEnd  = gettimetick(2) + .RentSeconds;
		#RB_LastRent = gettimetick(2) + .CooldownSeconds;

		// schedule auto unblocking for this player after duration
		addtimer (.RentSeconds*1000), strnpcinfo(3)+"::OnUnblockTimer";

		mes "Enjoy your test of ^0055FF"+ getitemname(#RB_RentItem) +"^000000!";
		mes "Trading/party/storage/drop are temporarily blocked during the demo.";
		mes "Buy the same item here within 24h to get a rebate.";
		close;

	// ---------------------------------------------------------
	// PURCHASE: buy the same item and receive a % rebate if within 24h of rent end
	// ---------------------------------------------------------
	case 2:
		// must have a last rented item and still within 24h window
		if (!#RB_RentItem || gettimetick(2) > (#RB_RentEnd + 24*3600)) {
			mes "No eligible rebate window found (must buy within 24h of your demo).";
			close;
		}

		// locate the item in our price pool
		.@id = #RB_RentItem;
		.@sz = getarraysize(.ItemPool);
		.@idx = -1;
		for (.@i=0; .@i<.@sz; .@i++) if (.ItemPool[.@i] == .@id) { .@idx = .@i; break; }
		if (.@idx < 0) { mes "This item is not sold here."; close; }

		.@price = .PricePool[.@idx];
		if (.@price <= 0) { mes "This item has no price set."; close; }

		mes "Purchase ^0055FF"+ getitemname(.@id) +"^000000 for ^FF9900"+ .@price +"z^000000?";
		mes "You will receive a ^00AA00"+ .RebateRate +"%^000000 rebate at checkout (demo buyer bonus).";
		if (select("Buy:Cancel") == 2) close;

		if (Zeny < .@price) { mes "Not enough zeny."; close; }
		if (Weight + (getiteminfo(.@id, ITEMINFO_WEIGHT)/10) > MaxWeight) { mes "Too heavy to carry. Free some weight."; close; }

		// charge and give item
		Zeny -= .@price;
		getitem .@id, 1;

		// rebate
		.@reb = (.@price * .RebateRate) / 100;
		if (.@reb > 0) { Zeny += .@reb; }

		mes "Purchased! Rebate returned: ^00AA00"+ .@reb +"z^000000.";
		close;

	// ---------------------------------------------------------
	// HELP
	// ---------------------------------------------------------
	case 3:
		mes "• Rent selected items for "+ (.RentSeconds/60) +" minutes (demo use).";
		mes "• While renting, trade/party/storage/drop are blocked to prevent abuse.";
		mes "• After time ends, the item auto-expires and blocks are lifted.";
		mes "• Buy the same item here within 24h to receive a "+ .RebateRate +"% rebate.";
		mes "• There is a per-account cooldown of "+ (.CooldownSeconds/60) +" minute(s) between rentals.";
		close;
	}

	// =========================================================
	// TIMERS / SAFETY
	// =========================================================
OnUnblockTimer:
	// Fired by addtimer for the renting player only
	if (#RB_RentEnd && gettimetick(2) >= #RB_RentEnd) {
		callsub S_BlockOff;
		#RB_RentItem = 0;
		#RB_RentEnd  = 0;
	}
	end;

	// Extra safety if a player relogs while blocked and already expired
OnPCLoginEvent:
	if (#RB_RentEnd && gettimetick(2) >= #RB_RentEnd) {
		callsub S_BlockOff;
		#RB_RentItem = 0;
		#RB_RentEnd  = 0;
	}
	end;

	// =========================================================
	// SUBS: BLOCK / UNBLOCK
	// =========================================================
S_BlockOn:
	pcblock PCBLOCK_TRADE,   1;
	pcblock PCBLOCK_PARTY,   1;
	pcblock PCBLOCK_STORAGE, 1;
	pcblock PCBLOCK_DROP,    1;
	return;

S_BlockOff:
	pcblock PCBLOCK_TRADE,   0;
	pcblock PCBLOCK_PARTY,   0;
	pcblock PCBLOCK_STORAGE, 0;
	pcblock PCBLOCK_DROP,    0;
	return;

	// =========================================================
	// INIT / CONFIG
	// =========================================================
OnInit:
	// --- Demo duration & economy ---
	.RentSeconds     = 300;   // 5 minutes
	.CooldownSeconds = 600;   // 10-minute cooldown per account between rentals
	.RebateRate      = 15;    // % rebate if purchased within 24h

	// --- What can be rented & bought here ---
	// Fill with your server’s real item IDs (validate at https://ratemyserver.net/)
	// Pair each item with its sell price at this booth.
	setarray .ItemPool[0], 2301, 2302, 2303;       // SAMPLE item IDs (replace!)
	setarray .PricePool[0], 50000, 75000, 100000;  // Price per matching index

	end;
}