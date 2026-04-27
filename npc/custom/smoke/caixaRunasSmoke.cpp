function	script	F_SmokeRunes	{

	.@r = rand(10000);

	if (.@r < 3500)
		getitem 840109,1;
	else if (.@r < 6000)
		getitem 840110,1;
	else if (.@r < 7800)
		getitem 840111,1;
	else if (.@r < 9000)
		getitem 840112,1;
	else if (.@r < 9600)
		getitem 840113,1;
	else if (.@r < 9950)
		getitem 840114,1;
	else {
		getitem 840132,1;
		announce "[Sortudo] "+strcharinfo(0)+" encontrou ["+getitemname(840132)+"] em ["+getitemname(840134)+"]!!!",bc_all;
	}
	end;
}