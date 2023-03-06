#include <iostream>
#include <conio.h>
using namespace std;
int Num;

class HeroBullet
{
public:
	int bbar[20][5];

	HeroBullet()    // constractor
	{
		Num = 0;
		for (int i = 0; i < 20; i++)
		{
			for (int k = 0; k < 5; k++)
			{
				bbar[i][k] = 0;
			}
		}
	}
	void NewBullet(int& Rh, int& Ch, int& bdir)
	{
		if (Num < 3 && bdir == 0)
		{
			bbar[Num][0] = Rh + 1;
			bbar[Num][1] = Ch + 3;
			bbar[Num][2] = 1;
			bbar[Num][3] = Ch + 33;
			bbar[Num][4] = bdir;
			Num++;
		}
		if (Num < 3 && bdir == 1)
		{
			bbar[Num][0] = Rh + 1;
			bbar[Num][1] = Ch - 3;
			bbar[Num][2] = 1;
			bbar[Num][3] = Ch - 33;
			bbar[Num][4] = bdir;
			Num++;
		}
	}
	void NewMelee(int& Rh, int& Ch, int& bdir)
	{
		if (Num < 3 && bdir == 0)
		{
			bbar[Num][0] = Rh + 1;
			bbar[Num][1] = Ch + 3;
			bbar[Num][2] = 1;
			bbar[Num][3] = Ch + 8;
			bbar[Num][4] = bdir;
			Num++;
		}
		if (Num < 3 && bdir == 1)
		{
			bbar[Num][0] = Rh + 1;
			bbar[Num][1] = Ch - 3;
			bbar[Num][2] = 1;
			bbar[Num][3] = Ch - 8;
			bbar[Num][4] = bdir;
			Num++;
		}
	}
	void FireBullet(int& bdir)
	{
		for (int r = 0; r < Num; r++)
		{
			if (bbar[r][2] == 1 && bbar[r][4] == 0)
			{
				if (bbar[r][1] < bbar[r][3])
				{
					bbar[r][1] += 2;
				}
				else
				{
					bbar[r][2] = 0;
				}
			}
			if (bbar[r][2] == 1 && bbar[r][4] == 1)
			{
				if (bbar[r][1] > bbar[r][3])
				{
					bbar[r][1] -= 2;
				}
				else
				{
					bbar[r][2] = 0;
				}
			}
		}
	}
	void DrawHeroBullet(char X[][1700], int& bdir, int& gender)
	{

		if (gender == 1)
		{
			for (int i = 0; i < Num; i++)
			{
				if (bbar[i][2] == 1 && bbar[i][4] == 0)
				{
					X[bbar[i][0]][bbar[i][1]] = 62;
				}
				if (bbar[i][2] == 1 && bbar[i][4] == 1)
				{
					X[bbar[i][0]][bbar[i][1]] = 60;
				}
			}
		}
		if (gender == 2)
		{
			for (int i = 0; i < Num; i++)
			{
				if (bbar[i][2] == 1 && bbar[i][4] == 0)
				{
					X[bbar[i][0]][bbar[i][1]] = '-';
				}
				if (bbar[i][2] == 1 && bbar[i][4] == 1)
				{
					X[bbar[i][0]][bbar[i][1]] = '-';
				}
			}
		}
	}
};



void FillMatrixByMyBackGround(char X[][1700], int& ct4, int& ct5, int& Ch, int& Rh, int& k, int& k1, int& kct, int& ctkey3, int& ct9, int& m)
{

	for (int r = 0; r < 34; r++)
	{
		for (int c = 0; c < 1700; c++)
		{
			X[r][c] = ' ';
		}
	}
	/*if (X[Rh + 1][Ch - 4] == '~' && X[Rh + 1][Ch - 5] == '~')
	{
		ct60++;
		ct9++;
	}
	if (ct60 == 0)
	{
		X[6][166] = '~';
	}
	if (ct60 == 1)
	{
		X[6][166] = ' ';
	}*/

	X[k][k1] = 'C';
	X[k][k1 + 1] = 'O';
	X[k][k1 + 2] = 'I';
	X[k][k1 + 3] = 'N';
	X[k][k1 + 4] = 'S';
	X[k][k1 + 5] = '0';

	if (ct9 == 3)
	{
		X[m][k1 + 1] = '~';
		X[m][k1 + 2] = '~';
		X[m][k1 + 3] = '~';

	}
	if (ct9 == 2)
	{
		X[m][k1 + 1] = '~';
		X[m][k1 + 2] = '~';
		X[m][k1 + 3] = ' ';


	}
	if (ct9 == 1)
	{
		X[m][k1 + 1] = '~';
		X[m][k1 + 2] = ' ';
		X[m][k1 + 3] = ' ';

	}

	if (ct5 == 1)
	{
		X[k][k1 + 5] = '1';
	}
	if (ct5 == 2)
	{
		X[k][k1 + 5] = '2';
	}
	if (ct5 == 3)
	{
		X[k][k1 + 5] = '3';
	}
	X[21][199] = 236;
	X[21][200] = 236;
	for (int c = 0; c < 1700; c++)
	{
		X[0][c] = '~';
		X[33][c] = '~';
	}
	for (int r = 0; r < 34; r++)
	{
		X[r][0] = '|';
		X[r][239] = 219;
	}
	for (int c = 0; c < 680; c++)
	{
		X[22][c] = 178;
	}
	for (int c = 80; c < 83; c++)
	{
		X[22][c] = ' ';
	}
	/*X[21][63] = 177;			//just a tree
	X[20][63] = 177;
	X[19][63] = 177;
	X[18][63] = 79;
	X[18][64] = 79;
	X[18][62] = 79;
	X[18][61] = 79;
	X[18][65] = 79;
	X[17][63] = 79;
	X[17][64] = 79;
	X[17][62] = 79;
	X[17][65] = 79;
	X[17][61] = 79;
	X[17][66] = 79;
	X[17][60] = 79;
	X[16][63] = 79;
	X[16][64] = 79;
	X[16][62] = 79;
	X[16][65] = 79;
	X[16][66] = 79;
	X[16][60] = 79;
	X[17][66] = 79;
	X[17][60] = 79;
	X[16][61] = 79;
	X[15][63] = 79;
	X[15][64] = 79;
	X[15][62] = 79;
	*/
	X[21][100] = 177;
	//just a tree  
	X[20][100] = 177;
	X[19][100] = 177;
	X[18][100] = 79;
	X[18][99] = 79;
	X[18][101] = 79;
	X[18][98] = 79;
	X[18][102] = 79;
	X[17][100] = 79;
	X[17][101] = 79;
	X[17][102] = 79;
	X[17][103] = 79;
	X[17][99] = 79;
	X[17][98] = 79;
	X[17][97] = 79;
	X[16][100] = 79;
	X[16][99] = 79;
	X[16][98] = 79;
	X[16][97] = 79;
	X[16][101] = 79;
	X[16][102] = 79;
	//X[17][66] = 79;
	//X[17][60] = 79;
	X[16][103] = 79;
	X[15][100] = 79;
	X[15][101] = 79;
	X[15][99] = 79;

	for (int c = 50; c < 53; c++)
	{
		X[22][c] = ' ';
	}
	for (int c = 22; c < 40; c++)
	{
		X[16][c] = 178;
	}
	if (ct5 < 1)
	{
		X[14][34] = 162;
	}
	if (ct5 == 1)
	{
		X[14][34] = ' ';
	}
	if (ct5 < 2)
	{
		X[11][100] = 162;
	}
	if (ct5 == 2)
	{
		X[11][100] = ' ';
	}
	if (ct5 < 3)
	{
		X[27][147] = 162;
	}
	if (ct5 == 3)
	{
		X[20][144] = ' ';
	}
	//linking the two screens
	for (int r = 21; r > 17; r--)
	{
		X[r][142] = 219;
		X[r][146] = 219;
		X[r][150] = 219;
		X[r][154] = 219;
		if (r == 18)
		{
			X[r][142] = 286;
			X[r][146] = 286;
			X[r][150] = 286;
			X[r][154] = 286;
		}
	}
	for (int r = 21; r > 18; r--)
	{
		X[r][141] = 273;
		X[r][145] = 273;
		X[r][149] = 273;
		X[r][153] = 273;
		X[r][155] = 272;
		X[r][143] = 272;
		X[r][147] = 272;
		X[r][151] = 272;
		X[r][155] = 272;
	}
	X[21][230] = '|';
	X[20][230] = '|';
	X[19][230] = '|';
	X[18][232] = '_';
	X[18][233] = '_';
	X[18][234] = '_';
	X[18][231] = '_';
	X[21][235] = '|';
	X[20][235] = '|';
	X[19][235] = '|';

	for (int c = 213; c < 217; c++)  // water
	{
		X[22][c] = 240;
	}

	for (int c = 197; c > 146; c--)
	{
		X[8][c] = 178;
	}
	for (int r = 22; r < 29; r++)
	{
		X[r][135] = 196;
		X[r][134] = '|';
		X[r][136] = '|';
	}
	for (int r = 22; r < 29; r++)
	{
		X[r][161] = 196;
		X[r][160] = '|';
		X[r][162] = '|';
	}
	for (int c = 134; c < 163; c++)
	{
		X[29][c] = 178;
	}
	if (ct4 == 0)
	{
		X[7][175] = 232;
		X[7][176] = 196;
		X[7][177] = 239;
	}
	else
	{
		X[7][155] = ' ';
		X[7][156] = ' ';
		X[7][157] = ' ';
	}
	if (ct4 == 1 && X[Rh - 1][Ch] == '_' && ct5 == 3)
	{
		X[17][230] = 'Y';
		X[17][231] = 'O';
		X[17][232] = 'U';
		X[17][233] = ' ';
		X[17][234] = 'W';
		X[17][235] = 'O';
		X[17][236] = 'N';
		Ch = 243;
	}

	// level 2 stuff 
	for (int r = 21; r > 12; r--)					//level 1 checkpoint
	{
		X[r][249] = '|';
	}
	for (int c = 257; c < 261; c++)
	{
		X[22][c] = ' ';
	}
	for (int c = 257; c < 261; c++)
	{
		X[22][c] = 286;
	}
	int ctblock = 0;
	for (int c = 355; c < 358; c++)
	{
		X[12][c] = 178;
	}
	for (int c = 365; c < 368; c++)
	{
		X[12][c] = 178;
	}
	for (int c = 375; c < 378; c++)
	{
		X[12][c] = 178;
	}
	for (int c = 385; c < 388; c++)
	{
		X[12][c] = 178;
	}
	for (int c = 395; c < 398; c++)
	{
		X[12][c] = 178;
	}
	for (int c = 405; c < 408; c++)
	{
		X[12][c] = 178;
	}
	for (int c = 354; c < 560; c++)
	{
		X[21][c] = 127;
	}
	for (int c = 358; c < 361; c++)
	{
		X[15][c] = 178;
	}
	for (int c = 361; c < 364; c++)
	{
		X[18][c] = 178;
	}
	for (int c = 368; c < 384; c++)
	{
		X[19][c] = 178;
	}
	for (int c = 574; c < 603; c++)  // area after horizontal elevator
	{
		X[12][c] = 178;
	}
	for (int r = 12; r < 22; r++)  // area 2 ladder
	{
		X[r][603] = '|';
	}
	for (int r = 12; r < 22; r++)  // area 2 ladder
	{
		X[r][605] = '|';
	}
	for (int r = 12; r < 22; r++)  // area 2 ladder
	{
		X[r][604] = 196;
	}
	for (int r = 21; r > 12; r--)			// waving flag checkpoint
	{
		X[r][623] = '|';
	}
	for (int r = 21; r > 13; r--)  // castle towers
	{
		X[r][636] = 177;			//left tower
		X[r][640] = 219;
		X[r][637] = 177;
		X[r][638] = 177;
		X[r][639] = 177;
		X[r][661] = 177;			//right tower
		X[r][662] = 177;
		X[r][663] = 177;
		X[r][660] = 219;
		X[r][664] = 177;
	}
	for (int c = 641; c < 660; c++)  // castle main gate
	{
		X[21][c] = 177;
		X[20][c] = 177;
		X[19][c] = 177;
		X[18][c] = 177;
		X[17][c] = 177;
		X[16][c] = 177;
	}
	for (int c = 647; c < 654; c++)  // castle door
	{
		X[21][c] = ' ';
		X[20][c] = ' ';
		X[19][c] = ' ';
		X[18][c] = ' ';
	}
	for (int c = 635; c < 642; c++)  // tower summit left
	{
		X[13][c] = 219;
	}
	for (int c = 659; c < 666; c++)		// tower summit right
	{
		X[13][c] = 219;
	}
	X[12][659] = 254;			// tower wall right
	X[12][661] = 254;
	X[12][663] = 254;
	X[12][665] = 254;
	X[12][635] = 254;			// tower wall left
	X[12][637] = 254;
	X[12][639] = 254;
	X[12][641] = 254;
	X[15][641] = 254;				// tower wall upward
	X[15][643] = 254;
	X[15][645] = 254;
	X[15][655] = 254;
	X[15][657] = 254;
	X[15][659] = 254;
	for (int c = 646; c < 655; c++)			//castle middle tower
	{
		X[16][c] = 177;
		X[15][c] = 177;
		X[14][c] = 177;
		X[13][c] = 177;
		X[12][c] = 177;
		X[11][c] = 177;
		X[10][c] = 177;
	}
	for (int c = 645; c < 656; c++)			//castle middle tower wall
	{
		X[9][c] = 219;
	}
	X[8][645] = 254;			//castle middle tower small walls
	X[8][647] = 254;
	X[8][649] = 254;
	X[8][651] = 254;
	X[8][653] = 254;
	X[8][655] = 254;
	X[7][647] = '|';				// castle flag
	X[6][647] = '|';
	X[5][647] = '|';
	X[5][648] = 228;
	X[5][649] = 228;
	X[5][650] = 228;
	X[5][651] = 228;

	for (int r = 1; r < 22; r++)		//level barrier
	{
		X[r][675] = 219;
	}
	if (kct == 0)				// SECOND KEY
	{
		X[18][381] = 'o';
		X[18][382] = 196;
		X[18][383] = 239;
	}
	else
	{

		X[17][380] = ' ';
		X[17][381] = ' ';
		X[17][382] = ' ';
	}
	if (Ch > 648 && Ch < 654 && kct >0)
	{
		Ch = 810;
		Rh = 19;
	}
	// level 3 stuff
	for (int c = 795; c < 1700; c++)
	{
		X[1][c] = 177;
	}
	for (int r = 1; r < 22; r++)
	{
		X[r][795] = 177;
	}
	X[21][868] = 177;				//  high point
	X[21][869] = 177;
	X[21][870] = 177;
	X[21][871] = 177;
	X[21][872] = 177;
	X[21][873] = 177;
	X[20][870] = 177;
	X[20][871] = 177;
	X[20][872] = 177;
	X[20][873] = 177;
	X[19][872] = 177;
	X[19][873] = 177;
	X[21][874] = 177;
	X[20][874] = 177;
	X[19][874] = 177;
	X[21][874] = 177;
	X[21][875] = 177;
	X[20][875] = 177;
	X[19][875] = 177;
	X[21][876] = 177;
	X[20][876] = 177;
	X[19][876] = 177;
	X[18][876] = 177;
	X[21][877] = 177;
	X[20][877] = 177;
	X[19][877] = 177;
	X[18][877] = 177;
	X[21][875] = 177;
	X[20][875] = 177;
	X[19][875] = 177;
	X[18][875] = 177;
	for (int c = 795; c < 1700; c++)		// level 3 castle floor
	{
		X[22][c] = 177;
	}
	for (int c = 877; c < 895; c++)
	{
		X[18][c] = 177;
		X[19][c] = 177;
		X[20][c] = 177;
		X[21][c] = 177;
	}
	for (int c = 895; c < 902; c++)			// lava
	{
		X[20][c] = 247;
		X[22][c] = ' ';
	}
	for (int c = 902; c < 911; c++)
	{
		X[18][c] = 177;
		X[19][c] = 177;
		X[20][c] = 177;
		X[21][c] = 177;
	}
	for (int c = 911; c < 918; c++)			// lava
	{
		X[20][c] = 247;
		X[22][c] = ' ';
	}
	for (int c = 918; c < 925; c++)
	{
		X[18][c] = 177;
		X[19][c] = 177;
		X[20][c] = 177;
		X[21][c] = 177;
	}
	for (int c = 925; c < 932; c++)			// lava
	{
		X[20][c] = 247;
		X[22][c] = ' ';
	}
	for (int c = 932; c < 939; c++)
	{
		X[18][c] = 177;
		X[19][c] = 177;
		X[20][c] = 177;
		X[21][c] = 177;
	}
	for (int c = 939; c < 946; c++)			// lava
	{
		X[20][c] = 247;
		X[22][c] = ' ';
	}
	for (int c = 946; c < 953; c++)
	{
		X[18][c] = 177;
		X[19][c] = 177;
		X[20][c] = 177;
		X[21][c] = 177;
	}
	for (int c = 953; c < 1030; c++)			// bunch of spikes
	{
		X[21][c] = 127;
	}
	for (int c = 961; c < 969; c++)
	{
		X[16][c] = 177;
	}
	for (int c = 976; c < 997; c++)
	{
		X[8][c] = 177;
	}
	for (int c = 986; c < 990; c++)
	{
		X[8][c] = 286;
	}
	for (int c = 1007; c < 1032; c++)
	{
		X[12][c] = 177;
	}
	for (int c = 1015; c < 1020; c++)
	{
		X[12][c] = 286;
	}
	for (int r = 12; r < 31; r++)			// ladder nzool l darak l asfal
	{
		X[r][1032] = '|';
		X[r][1033] = 196;
		X[r][1034] = 196;
		X[r][1035] = '|';
	}
	for (int c = 1032; c < 1149; c++)
	{
		X[31][c] = 177;
	}
	for (int r = 2; r < 22; r++)
	{
		for (int c = 1036; c < 1135; c++)
		{
			X[r][c] = 177;
		}
	}
	for (int r = 22; r < 31; r++)			// ladder tloo3 mn l darak l asfal
	{
		X[r][1140] = '|';
		X[r][1141] = 196;
		X[r][1142] = 196;
		X[r][1143] = '|';
	}
	for (int r = 30; r > 28; r--)		// high spikes 
	{
		X[r][1048] = 286;
		X[r][1072] = 286;
		X[r][1094] = 286;
		X[r][1116] = 286;
	}
	for (int r = 23; r < 25; r++)		// high spikes 
	{
		X[r][1060] = 287;
		X[r][1083] = 287;
		X[r][1105] = 287;
		X[r][1123] = 287;
	}
	X[21][1160] = 236;				// jumppad
	X[21][1161] = 236;
	if (X[Rh + 2][Ch + 1] == char(236))
	{
		for (int i = 0; i < 14; i++)
		{
			Rh--;
		}
	}
	for (int r = 21; r > 13; r--)			// high points
	{
		X[r][1167] = 177;
		X[r][1168] = 177;
		X[r][1169] = 177;
	}
	for (int c = 1170; c < 1180; c++)
	{
		X[22][c] = 127;
	}
	for (int r = 21; r > 13; r--)			// high popints
	{
		X[r][1180] = 177;
		X[r][1181] = 177;
		X[r][1182] = 177;
	}
	for (int c = 1183; c < 1193; c++)
	{
		X[22][c] = 127;
	}
	for (int r = 21; r > 13; r--)				//high points
	{
		X[r][1193] = 177;
		X[r][1194] = 177;
		X[r][1195] = 177;
	}
	for (int c = 1196; c < 1206; c++)
	{
		X[22][c] = 127;
	}
	for (int r = 21; r > 13; r--)				//high points
	{
		X[r][1206] = 177;
		X[r][1207] = 177;
		X[r][1208] = 177;
	}
	for (int c = 1196; c < 1206; c++)
	{
		X[22][c] = 127;
	}
	for (int r = 21; r > 13; r--)					//high points
	{
		X[r][1206] = 177;
		X[r][1207] = 177;
		X[r][1208] = 177;
	}
	if (ctkey3 == 0)								//third key
	{
		X[11][1393] = 'M';
		X[11][1394] = 196;
		X[11][1395] = 239;
	}
	else
	{
		X[11][1393] = ' ';
		X[11][1394] = ' ';
		X[11][1395] = ' ';
	}
	for (int r = 16; r < 22; r++)				//exit
	{
		for (int c = 1390; c < 1401; c++)
		{
			X[r][c] = 177;
		}
	}
	for (int c = 1388; c < 1403; c++)
	{
		X[15][c] = 219;
	}
	for (int r = 21; r > 1; r--)
	{
		X[r][1408] = 176;
		X[r][1409] = 176;
	}
	for (int c = 1388; c < 1403; c += 2)
	{
		X[14][c] = 254;
	}
	for (int r = 18; r < 22; r++)
	{
		for (int c = 1392; c < 1398; c++)
		{
			X[r][c] = ' ';
		}
	}
	/*for (int r = 14; r > 10; r--)
	{
		X[r][1395] = '|';
	}*/
	/*for (int c = 1395; c < 1399; c++)
	{
		X[11][c] = 228;
	}*/
	/*if (Ch > 1395 && ctkey3 > 0)
	{
		Ch = 1490;         comment
	}*/
	/*X[13][1497] = 'W';
	X[13][1498] = 'I';
	X[13][1499] = 'N';
	X[13][1500] = 'N';
	X[13][1501] = 'E';
	X[13][1502] = 'R';

	X[15][1497] = 'C';
	X[15][1498] = 'O';
	X[15][1499] = 'N';
	X[15][1500] = 'G';
	X[15][1501] = 'R';
	X[15][1502] = 'A';
	X[15][1503] = 'T';
	X[15][1504] = 'U';
	X[15][1505] = 'L';
	X[15][1506] = 'A';
	X[15][1507] = 'T';
	X[15][1508] = 'I';
	X[15][1509] = 'O';
	X[15][1510] = 'N';
	X[15][1511] = 'S';

	X[17][1497] = 'G';
	X[17][1498] = 'G';

	X[17][1500] = 'G';
	X[17][1501] = 'A';
	X[17][1502] = 'M';
	X[17][1503] = 'E';
	X[17][1506] = 'F';
	X[17][1507] = 'I';
	X[17][1508] = 'N';
	X[17][1509] = 'I';
	X[17][1510] = 'S';
	X[17][1511] = 'H';
	X[17][1512] = 'E';
	X[17][1513] = 'D';
	*/
	X[5][1500] = 'f';
	X[5][1501] = 'i';
	X[5][1502] = 'l';
	X[5][1503] = 'e';


	X[5][1507] = 'e';
	X[5][1508] = 'd';
	X[5][1509] = 'i';
	X[5][1510] = 't';


	X[5][1516] = 'd';
	X[5][1517] = 'e';
	X[5][1518] = 'b';
	X[5][1519] = 'u';
	X[5][1520] = 'g';


	X[5][1525] = 'p';
	X[5][1526] = 'r';
	X[5][1527] = 'o';
	X[5][1528] = 'j';
	X[5][1529] = 'c';
	X[5][1530] = 't';

	X[5][1536] = 'b';
	X[5][1537] = 'u';
	X[5][1538] = 'i';
	X[5][1539] = 'l';
	X[5][1540] = 'd';


	X[5][1546] = 't';
	X[5][1547] = 'o';
	X[5][1548] = 'o';
	X[5][1549] = 'l';
	X[5][1550] = 's';

	X[5][1556] = 'w';
	X[5][1557] = 'i';
	X[5][1558] = 'n';
	X[5][1559] = 'd';
	X[5][1560] = 'o';
	X[5][1561] = 'w';


	X[5][1566] = 'h';
	X[5][1567] = 'e';
	X[5][1568] = 'l';
	X[5][1569] = 'p';

	/*X[5][1575] = 'v';
	X[5][1576] = 'i';
	X[5][1577] = 'e';
	X[5][1578] = 'w';
	*/
	X[5][1586] = 'w';
	X[5][1587] = 'i';
	X[5][1588] = 'n';
	X[5][1589] = 'd';
	X[5][1590] = 'o';
	X[5][1591] = 'w';

	X[21][1570] = 495;
	X[21][1571] = 495;
	X[17][1577] = 495;
	X[17][1576] = 495;
	X[14][1582] = 495;
	X[14][1583] = 495;



	for (int i = 92; i < 111; i++)
	{
		X[13][i] = 79;
	}


	X[21][84] = 476;
	X[20][85] = 476;
	X[19][86] = 476;
	X[18][87] = 476;
	X[17][88] = 476;            ///el solom
	X[16][89] = 476;
	X[15][90] = 476;
	X[14][91] = 476;
	X[13][92] = 476;


	X[13][48] = 79;
	X[13][49] = 79;
	X[13][50] = 79;
	X[13][51] = 79;
	X[13][52] = 79;
	X[13][53] = 79;
	X[13][54] = 79;
	X[13][55] = 79;
	X[13][56] = 79;

	if (Ch < 55 && Ch>48 && Rh == 10)
	{



		for (int i = 54;i < 114;i++)
		{
			X[11][i] = 351;
		}



	}
}
void rockets(char X[][1700], int& rr, int& rc, int& Ch, int& lkm)
{
	int ct = 0;
	X[rr][rc] = '^';
	X[rr - 1][rc] = '^';
	X[rr - 2][rc] = '^';
	X[rr - 3][rc] = '^';
	X[rr - 3][rc - 1] = '^';
	X[rr - 3][rc + 1] = '^';
	X[rr - 2][rc - 2] = '^';
	X[rr - 2][rc + 2] = '^';
	X[rr - 1][rc - 3] = '^';
	X[rr - 1][rc + 3] = '^';
	X[rr - 4][rc] = '^';
	if (Ch == rc - 2 || Ch == rc + 2)
	{                                                  /////////// 
		lkm = 1;
	}
	if (lkm == 1)
	{
		rr -= 1;
	}
	if (rr < 2)
	{
		rr = 21;
		lkm = 0;
	}
}
void prog(char X[][1700], int& pbr, int& pbc, int& lim)
{
	X[pbr][pbc + 25] = 'v';
	X[pbr][pbc + 26] = 'i';
	X[pbr][pbc + 27] = 'r';
	X[pbr][pbc + 28] = 'u';
	X[pbr][pbc + 29] = 's';

	X[pbr][pbc + 36] = 'e';
	X[pbr][pbc + 37] = 'r';
	X[pbr][pbc + 38] = 'r';
	X[pbr][pbc + 39] = 'o';
	X[pbr][pbc + 40] = 'r';

	X[pbr][pbc + 16] = 'b';
	X[pbr][pbc + 17] = 'u';
	X[pbr][pbc + 18] = 'g';                          ///////////
	if (lim == 0)
	{
		if (pbr < 20)
		{
			pbr += 2;
		}
		else
		{
			lim = 1;
		}
	}
	if (lim == 1)
	{
		if (pbr > 5)
		{
			pbr -= 2;
		}
		else
		{
			lim = 0;
		}
	}
}
void comp(char X[][1700], int& cb, int& cr, int& cc, int& chop)
{
	if (cb == 0)
	{
		int ct = 0;
		X[cr - 1][cc] = 176;
		X[cr - 1][cc + 1] = 176;
		X[cr][cc] = 176;
		X[cr][cc + 1] = 176;
		X[cr][cc + 2] = 176;
		X[cr][cc + 3] = 176;
		X[cr + 1][cc] = 176;
		X[cr + 1][cc + 1] = 176;
		X[cr + 1][cc + 2] = 176;
		X[cr + 1][cc + 3] = 176;
		X[cr + 1][cc + 4] = 176;
		X[cr + 1][cc + 5] = 176;
		X[cr + 2][cc] = 176;
		X[cr + 2][cc + 1] = 's';
		X[cr + 2][cc + 2] = 'o';
		X[cr + 2][cc + 3] = 'n';
		X[cr + 2][cc + 4] = 'y';
		X[cr + 2][cc + 5] = 176;
		X[cr + 2][cc + 6] = 176;
		X[cr + 2][cc + 7] = 176;
		X[cr + 3][cc] = 176;
		X[cr + 3][cc + 1] = 176;
		X[cr + 3][cc + 2] = 176;
		X[cr + 3][cc + 3] = 176;
		X[cr + 3][cc + 4] = 176;
		X[cr + 3][cc + 5] = 176;
		X[cr + 4][cc] = 176;
		X[cr + 4][cc + 1] = 176;                    ////////
		X[cr + 4][cc + 2] = 176;
		X[cr + 4][cc + 3] = 176;
		X[cr + 5][cc] = 176;
		X[cr + 5][cc + 1] = 176;
		X[cr + 3][chop] = 423;
		X[cr][chop - 9] = 423;
		if (ct == 0)
		{
			chop -= 3;
		}
		if (chop <= 1500)
		{
			chop = 1588;
		}
	}

}
void laserenemy(char X[][1700], int& ler, int& lec, int& lop, int& len)
{
	if (len == 0)
	{
		X[ler][lec] = 145;
		X[ler + 1][lec] = 240;
		X[ler + 1][lec + 1] = '\\';
		X[ler + 1][lec - 2] = 170;
		X[ler + 1][lec - 1] = '/';
		X[ler + 2][lec] = 208;
		//X[ler + 1][lop] = 95;
		X[ler + 1][lop - 1] = 499;
		X[ler + 1][lop - 2] = 499;
		X[ler + 1][lop - 3] = 499;
		X[ler + 1][lop - 4] = 499;

		if (lop > 90)
		{
			lop--;
		}
		else
		{
			lop = 110;
		}
	}
	if (X[ler + 1][lec + 4] == char(351) || X[ler + 1][lec - 4] == char(351))           ////////
	{
		len = 1;
	}
	if (len == 1)
	{
		X[ler][lec] = ' ';
		X[ler + 1][lec] = ' ';
		X[ler + 1][lec + 1] = ' ';
		X[ler + 1][lec - 2] = ' ';
		X[ler + 1][lec - 1] = ' ';
		X[ler + 2][lec] = ' ';
		X[ler + 1][lop] = ' ';
		X[ler + 1][lop - 1] = ' ';
		X[ler + 1][lop - 2] = ' ';
		X[ler + 1][lop - 3] = ' ';
		X[ler + 1][lop - 4] = ' ';
		len = 2;
		Num = 0;
	}
}
void DispTopScreen(char X[][1700], int& Ch, int& Rh)
{
	system("cls");
	if (Ch <= 60)
	{
		for (int r = 0; r < 34; r++)
		{
			for (int c = 0; c < 120; c++)
			{
				cout << X[r][c];
			}
		}
	}
	if (Ch > 60)
	{
		for (int r = 0; r < 34; r++)
		{
			for (int c = Ch - 60; c < Ch + 60; c++)
			{
				cout << X[r][c];
			}
		}
	}
}
void Drawlvl2Enemy(char X[][1700], int& Enmcl2, int& Enmrl2, int& hoppp, int& Rh, int& Ch, int& vvx)
{
	if (vvx == 0)
	{
		int ct = 0;
		X[Enmrl2][Enmcl2] = 145;
		X[Enmrl2 + 1][Enmcl2] = 240;
		X[Enmrl2 + 1][Enmcl2 + 1] = '\\';
		X[Enmrl2 + 1][Enmcl2 - 2] = 170;
		X[Enmrl2 + 1][Enmcl2 - 1] = '/';
		X[Enmrl2 + 2][Enmcl2] = 208;
		X[Enmrl2 + 1][hoppp] = 238;
		if (ct == 0)
		{
			hoppp -= 2;
		}
		if (hoppp <= 611)
		{
			hoppp = 630;
		}
	}
	if (X[Enmrl2 + 1][Enmcl2 + 4] == char(60) || X[Enmrl2 + 1][Enmcl2 - 4] == char(62) || X[Enmrl2 + 1][Enmcl2 + 4] == '-' || X[Enmrl2 + 1][Enmcl2 - 4] == '-')
	{
		vvx = 1;
	}
	if (vvx == 1)
	{
		X[Enmrl2][Enmcl2] = ' ';
		X[Enmrl2 + 1][Enmcl2] = ' ';
		X[Enmrl2 + 1][Enmcl2 + 1] = ' ';
		X[Enmrl2 + 1][Enmcl2 - 1] = ' ';
		X[Enmrl2 + 2][Enmcl2] = ' ';
		X[Enmrl2 + 1][hoppp] = ' ';
		vvx++;
		Num = 0;
	}
}

void Drawlvl3Enemy(char X[][1700], int& Enmc2, int& Enmr2, int& hop, int& Rh, int& Ch, int& vx)
{
	if (Ch > 813)
	{
		if (vx == 0)
		{
			int ct = 0;
			X[Enmr2][Enmc2] = 20;
			X[Enmr2 + 1][Enmc2] = 240;
			X[Enmr2 + 1][Enmc2 + 1] = '\\';
			X[Enmr2 + 1][Enmc2 - 2] = 170;
			X[Enmr2 + 1][Enmc2 - 1] = '/';
			X[Enmr2 + 2][Enmc2] = 208;
			X[Enmr2 + 1][hop] = 238;
			if (ct == 0)
			{
				hop -= 2;
			}
			if (hop <= 822)
			{
				hop = 850;
			}
		}
		if (X[Enmr2 + 1][Enmc2 + 3] == char(60) || X[Enmr2 + 1][Enmc2 - 3] == char(62) || X[Enmr2 + 1][Enmc2 + 3] == '-' || X[Enmr2 + 1][Enmc2 - 3] == '-')
		{
			vx = 1;
		}
		if (vx == 1)
		{
			X[Enmr2][Enmc2] = ' ';
			X[Enmr2 + 1][Enmc2] = ' ';
			X[Enmr2 + 1][Enmc2 + 1] = ' ';
			X[Enmr2 + 1][Enmc2 - 1] = ' ';
			X[Enmr2 + 2][Enmc2] = ' ';
			X[Enmr2 + 1][hop] = ' ';
			vx++;
			Num = 0;
		}
	}
}
void DrawThirdEnemy(char X[][1700], int& Enmc, int& Enmr, int& hopp, int& Rh, int& Ch, int& xv)
{
	if (Ch > 890)
	{
		if (xv == 0)
		{
			int ct = 0;
			X[Enmr][Enmc] = 21;
			X[Enmr + 1][Enmc] = 240;
			X[Enmr + 1][Enmc + 1] = '\\';
			X[Enmr + 1][Enmc - 1] = '/';
			X[Enmr + 2][Enmc] = 208;
			X[Enmr + 1][hopp] = 238;
			if (ct == 0)
			{
				hopp -= 2;
			}
			if (hopp <= 887)
			{
				hopp = 922;
			}
		}
		if (X[Enmr + 1][Enmc + 3] == char(62) || X[Enmr + 1][Enmc - 3] == char(60) || X[Enmr + 1][Enmc + 3] == '-' || X[Enmr + 1][Enmc - 3] == '-')
		{
			xv = 1;
		}
		if (xv == 1)
		{
			X[Enmr][Enmc] = ' ';
			X[Enmr + 1][Enmc] = ' ';
			X[Enmr + 1][Enmc + 1] = ' ';
			X[Enmr + 1][Enmc - 1] = ' ';
			X[Enmr + 2][Enmc] = ' ';
			X[Enmr + 1][hopp] = ' ';
			xv++;
			Num = 0;
		}
	}
}
void DrawFallingSpikes(char X[34][1700], int& fbr, int& fbc)
{
	X[fbr][fbc + 5] = 287;
	X[fbr][fbc + 16] = 287;
	X[fbr][fbc + 27] = 287;
	X[fbr + 1][fbc + 39] = 287;
	X[fbr + 1][fbc + 49] = 287;
	X[fbr + 1][fbc + 58] = 287;
}
void MoveFallingSpikes(int& fbr, int& fbc, int& Ch)
{
	if (Ch > 267 && fbr < 20)
	{
		fbr += 2;
	}
	else
	{
		fbr = 2;
	}
}
void MovethirdElevator(char X[][1700], int& thelr, int& thelc, int& Rh, int& Ch, int& thedir)
{
	if (Ch > 969 && Ch < 975)
	{
		if (thedir == 0)
		{
			if (thelr > 6)
			{
				thelr--;
			}
			else
			{
				thedir = 1;
			}
		}
		if (thedir == 1)
		{
			if (thelr < 15)
			{
				thelr++;
			}
			else
			{
				thedir = 0;
			}
		}
	}
}
void DrawHorizontalElevator(char X[][1700], int& hevr, int& hevc)
{
	X[hevr][hevc] = 205;
	X[hevr][hevc + 1] = 205;
	X[hevr][hevc + 2] = 205;
	X[hevr][hevc + 3] = 205;
	X[hevr][hevc + 4] = 205;
	X[hevr][hevc + 5] = 205;
}
void MoveHorizontalElevator(char X[][1700], int& hevr, int& hevc, int& hedir, int& Ch, int& lvl2c, int& k1)
{
	if (hedir == 0)
	{
		if (hevc < 570)
		{
			hevc += 2;
			Ch += 2;
			lvl2c += 2;
			k1 += 2;
		}
		else
		{
			hedir = 1;
		}
	}
	if (hedir == 1)
	{
		if (hevc > 411)
		{
			hevc -= 2;
			Ch -= 2;
			k1 -= 2;
		}
		else
		{
			hedir = 0;
		}
	}
}
void DrawElevator(char X[][1700], int& Evr, int& Evc)
{
	X[22][340] = ' ';
	X[22][340 + 1] = ' ';
	X[22][340 + 2] = ' ';
	X[22][340 + 3] = ' ';
	X[22][340 + 4] = ' ';
	X[22][340 + 5] = ' ';
	X[Evr][Evc] = 254;
	X[Evr][Evc + 1] = 254;
	X[Evr][Evc + 2] = 254;
	X[Evr][Evc + 3] = 254;
	X[Evr][Evc + 4] = 254;
	X[Evr][Evc + 5] = 254;
}
void MoveElevator(char X[][1700], int& Evr, int& Evc, int& Rh, int& Ch, int& dee)
{
	if (dee == 0)
	{
		if (Evr > 8)
		{
			Evr--;
		}
		else
		{
			dee = 1;
		}
	}
	if (dee == 1)
	{
		if (Evr < 22)
		{
			Evr++;

		}
		else
		{
			dee = 0;
		}
	}
}
void MoveEnemy1(char X[][1700], int& De1, int& Ec1, int& Er1, int& yow)
{
	if (De1 == 1)
	{
		if (yow == 0)
		{
			X[Er1 + 1][Ec1 + 2] = 244;
		}
		if (Ec1 < 39)
		{
			Ec1++;
		}
		else
		{
			De1 = -1;
			X[Er1 + 1][Ec1 + 2] = ' ';
		}
	}
	else
	{
		if (yow == 0)
		{
			X[Er1 + 1][Ec1 - 2] = 244;
		}
		if (Ec1 > 22)
		{
			Ec1--;
		}
		else
		{
			De1 = 1;
			X[Er1 + 1][Ec1 - 2] = ' ';
		}
	}
}
void sahaba(char X[][1700], int& s, int& ebo, int& lai)
{

	X[s][ebo] = '+';
	X[s + 4][ebo + 15] = '+';
	X[s + 4][ebo - 15] = '+';
	X[s + 4][ebo + 30] = '+';
	X[s + 4][ebo - 30] = '+';
	X[s + 10][ebo + 15] = '+';
	X[s + 10][ebo - 15] = '+';
	X[s + 16][ebo - 5] = '+';
	X[s + 10][ebo + 30] = '+';
	X[s + 10][ebo - 30] = '+';
	X[s + 15][ebo - 30] = '+';
	X[s + 16][ebo - 30] = '+';
	if (lai == 0)
	{
		if (ebo > 1200)
		{
			ebo -= 2;
		}
		else
		{                                            ///////////
			lai = 1;
		}
	}
	if (lai == 1)
	{
		if (ebo < 1350)
		{
			ebo += 2;
		}
		else
		{
			lai = 0;
		}
	}
}
void Ebullet(char X[][1700], int& Ec2, int& Er2, int& bmw, int& Rh, int& Ch)
{
	if (Rh > 0 && Rh <= 5)
	{
		X[Er2 + 1][bmw + 2] = '+';              //enemy bullet w hwa mashy
		bmw += 2;
	}
}
void MoveEnemy2(char X[][1700], int& De3, int& Er2, int& Ec2, int& sp)
{
	if (De3 == 1)
	{
		if (sp == 0)
		{
			X[5 + 1][Ec2 + 2] = 213;
		}
		if (Ec2 < 196)
		{
			Ec2 += 2;
		}
		else
		{
			De3 = -1;
			if (sp == 0)
			{
				X[5 + 1][Ec2 - 2] = 184;
			}
		}
	}
	else
	{
		if (sp == 0)
		{
			X[5 + 1][Ec2 - 2] = 184;
		}
		if (Ec2 > 148)
		{
			Ec2 -= 2;
		}
		else
		{
			De3 = 1;
			if (sp == 0)
			{
				X[5 + 1][Ec2 + 2] = 213;
			}
		}
	}
}
void MovePlane(int& De2, int& Pr, int& Pc, char X[][1700], int& dp)
{
	int g = Pc + 7;
	if (De2 == 1)
	{
		if (Pc < 122)
		{
			Pc += 3;
		}
		else
		{
			De2 = -1;
		}
	}
	else
	{
		Pc = 6;
		De2 = 1;
	}
	if (dp == 0)
	{
		X[Pr + 1][g + 1] = 186;
		X[Pr + 2][g + 1] = 186;
		X[Pr + 3][g + 1] = 186;
		X[Pr + 4][g + 1] = 186;
		X[Pr + 5][g + 1] = 186;
		X[Pr + 6][g + 1] = 186;
		X[Pr + 7][g + 1] = 186;
		X[Pr + 8][g + 1] = 186;
		X[Pr + 9][g + 1] = 186;
		if (X[Pr + 10][g] == ' ')
		{
			X[Pr + 10][g + 1] = 186;
			X[Pr + 11][g + 1] = 186;
			X[Pr + 12][g + 1] = 186;
			X[Pr + 13][g + 1] = 186;
			X[Pr + 14][g + 1] = 186;
			X[Pr + 15][g + 1] = 186;
		}
	}
	if (dp == 1)
	{
		X[Pr + 1][g + 1] = ' ';
		X[Pr + 2][g + 1] = ' ';
		X[Pr + 3][g + 1] = ' ';
		X[Pr + 4][g + 1] = ' ';
		X[Pr + 5][g + 1] = ' ';
		X[Pr + 6][g + 1] = ' ';
		X[Pr + 7][g + 1] = ' ';
		X[Pr + 8][g + 1] = ' ';
		X[Pr + 9][g + 1] = ' ';
		X[Pr + 10][g + 1] = ' ';
		X[Pr + 11][g + 1] = ' ';
		X[Pr + 12][g + 1] = ' ';
		X[Pr + 13][g + 1] = ' ';
		X[Pr + 14][g + 1] = ' ';
		X[Pr + 15][g + 1] = ' ';

	}
}
void HellBladeMove(char X[][1700], int& hblr, int& hblc, int& hbd, int& Ch, int& Rh, int& p, int& dd, int& ddd, int& dddd, int& ddddd)
{
	if (hbd == 0)
	{
		if (hblr > 10)
		{
			hblr--;

			hblc -= 2;
			p -= 3;
			dd -= 4;
			ddd -= 5;
			X[hblr][hblc] = '/';
			X[hblr + 1][p] = '/';
			X[hblr + 2][dd] = '/';
			X[hblr + 3][ddd] = 235;
		}
		else
		{
			hbd = 1;
		}
	}
	if (hbd == 1)
	{
		if (hblr < 14)
		{
			hblr++;
			hblc += 2;
			p += 3;
			dd += 4;
			ddd += 5;

			X[hblr][hblc] = '/';
			X[hblr + 1][p] = '/';
			X[hblr + 2][dd] = '/';
			X[hblr + 3][ddd] = 235;;
		}
		else
		{
			hbd = 0;
		}
	}
}
void MoveFallingCelling(char X[][1700], int& fcellr, int& fcellc, int& fcdir, int& Ch, int& Rh)
{
	if (Ch > 1220)
	{
		if (fcdir == 0)
		{
			if (fcellr < 19)
			{
				fcellr++;
			}
			else
			{
				fcdir = 1;
			}
		}
		else
		{
			if (fcellr > 13)
			{
				fcellr--;
			}
			else
			{
				fcdir = 0;
			}
		}
	}
}
void Hearts(char X[][1700], int& htr, int& htc, int& Rh, int& Ch, int& ct8)
{
	if (Ch > 790)
	{
		if (ct8 == 0)
		{
			X[htr][htc] = 3;
			X[htr][htc + 1] = 3;
			X[htr][htc + 2] = 3;
		}
		if (ct8 == 1)
		{
			X[htr][htc] = 3;
			X[htr][htc + 1] = 3;
			X[htr][htc + 2] = ' ';
		}
		if (ct8 == 2)
		{
			X[htr][htc] = 3;
			X[htr][htc + 1] = ' ';
			X[htr][htc + 2] = ' ';
		}
	}
}
void DrawFallingCelling(char X[][1700], int& fcellr, int& fcellc)
{
	int ctspikes = 0;
	for (int c = 1230; c < 1310; c++)
	{
		X[fcellr - 1][c] = 177;
	}
	for (int c = 1230; c < 1310; c++)
	{
		if (ctspikes < 8)
		{
			X[fcellr][c] = 281;
			ctspikes++;
		}
		else
		{
			c += 8;
			ctspikes = 0;
		}
	}
}
void DrawThirdElevator(char X[][1700], int& thelr, int& thelc)
{
	X[thelr][thelc] = 254;
	X[thelr][thelc + 1] = 254;
	X[thelr][thelc + 2] = 254;
	X[thelr][thelc + 3] = 254;
	X[thelr][thelc + 4] = 254;
	X[thelr][thelc + 5] = 254;
}
void MoveWavingFlag(char X[][1700], int& wavingflagr, int& wavingflagc, int& Rh, int& Ch)
{
	if (Ch >= 619)
	{
		if (wavingflagr > 13)
		{
			wavingflagr--;
		}
	}
}
void MoveWavingFlaglvl1(char X[][1700], int& wflvl1r, int& wflvl1c, int& Rh, int& Ch)
{
	if (Ch >= 249)
	{
		if (wflvl1r > 13)
		{
			wflvl1r--;
		}
	}
}
void DrawWavingFlaglvl1(char X[][1700], int& wflvl1r, int& wflvl1c)
{
	X[wflvl1r][wflvl1c] = 228;
	X[wflvl1r][wflvl1c + 1] = 228;
	X[wflvl1r][wflvl1c + 2] = 228;
}
void DrawWavingFlag(char X[][1700], int& wavingflagr, int& wavingflagc)
{
	X[wavingflagr][wavingflagc] = 228;
	X[wavingflagr][wavingflagc + 1] = 228;
	X[wavingflagr][wavingflagc + 2] = 228;
}
void Drawlvl3(char X[][1700], int& lvl3r, int& lvl3c)
{
	X[lvl3r][lvl3c - 2] = 76;
	X[lvl3r][lvl3c - 1] = 69;
	X[lvl3r][lvl3c] = 86;
	X[lvl3r][lvl3c + 1] = 69;
	X[lvl3r][lvl3c + 2] = 76;
	X[lvl3r][lvl3c + 4] = 73;
	X[lvl3r][lvl3c + 5] = 73;
	X[lvl3r][lvl3c + 6] = 73;
}
void qnabl(char X[][1700], int& qhop, int& qnr, int& abl)
{
	X[21][1650] = 157;
	X[21][1620] = 157;
	X[qnr][qhop] = 423;
	X[qnr - 1][qhop] = 423;
	X[qnr - 1][qhop - 1] = 423;
	X[qnr][qhop - 1] = 423;



	X[qnr][qhop - 30] = 423;
	X[qnr - 1][qhop - 30] = 423;
	X[qnr - 1][qhop - 31] = 423;                //////////
	X[qnr][qhop - 31] = 423;
	if (abl == 0)
	{
		if (qnr > 9)
		{
			qnr -= 2;
			qhop--;
		}
		else
		{
			abl = 1;
		}
	}
	if (abl == 1)
	{
		if (qnr < 21)
		{
			qnr += 2;
			qhop--;
		}
		else
		{
			qnr = 20;
			qhop = 1650;
			abl = 0;
		}
	}

}
void Drawlvl2(char X[][1700], int& lvl2r, int& lvl2c, int& ct4, int& bec, int& tbu)
{
	X[lvl2r][lvl2c - 2] = 76;
	X[lvl2r][lvl2c - 1] = 69;
	X[lvl2r][lvl2c] = 86;
	X[lvl2r][lvl2c + 1] = 69;
	X[lvl2r][lvl2c + 2] = 76;
	X[lvl2r][lvl2c + 4] = 73;
	X[lvl2r][lvl2c + 5] = 73;
	X[10][bec] = 209;
	X[10][bec - 20] = 209;
	X[10][bec - 50] = 209;
	X[10][bec - 70] = 209;
	if (tbu == 1)
	{
		if (bec > 411)
		{
			bec -= 2;
		}
		else
		{
			tbu = 0;
		}
	}
	if (tbu == 0)
	{
		if (bec - 70 < 600)
		{
			bec += 2;
		}
		else
		{
			tbu = 1;
		}
	}
}
void DrawLvl(char X[][1700], int& lvlr, int& lvlc)
{
	X[lvlr][lvlc - 2] = 76;
	X[lvlr][lvlc - 1] = 69;
	X[lvlr][lvlc] = 86;
	X[lvlr][lvlc + 1] = 69;
	X[lvlr][lvlc + 2] = 76;
	X[lvlr][lvlc + 4] = 73;
}
void DrawEnemy1(char X[][1700], int Er1, int Ec1, int& yow)
{
	if (yow == 0)
	{
		X[Er1][Ec1] = 15;
		X[Er1 + 1][Ec1] = 240;
		X[Er1 + 1][Ec1 + 1] = '\\';
		X[Er1 + 1][Ec1 - 1] = '/';
		X[Er1 + 2][Ec1] = 208;
	}
	if (X[Er1 + 1][Ec1 - 2] == char(62) || X[Er1 + 1][Ec1 + 2] == char(60) || X[Er1 + 1][Ec1 + 2] == '-' || X[Er1 + 1][Ec1 - 2] == '-')
	{
		yow = 1;
	}
	if (yow == 1)
	{
		X[Er1][Ec1] = ' ';
		X[Er1 + 1][Ec1] = ' ';
		X[Er1 + 1][Ec1 + 1] = ' ';
		X[Er1 + 1][Ec1 - 1] = ' ';
		X[Er1 + 2][Ec1] = ' ';
		yow++;
		Num = 0;
	}
}
void DrawPlane(char X[][1700], int Pr, int Pc, int& dp)
{
	if (dp == 0)
	{
		X[Pr][Pc - 3] = 278;
		X[Pr][Pc - 2] = 278;
		X[Pr][Pc - 1] = 278;
		X[Pr][Pc] = 278;
		X[Pr][Pc + 1] = 278;
		X[Pr][Pc + 2] = 278;
		X[Pr][Pc + 3] = 278;
		X[Pr][Pc + 4] = 278;
		X[Pr][Pc + 5] = 272;
		X[Pr - 2][Pc - 1] = 196;
		X[Pr - 2][Pc] = 196;
		X[Pr - 2][Pc + 1] = 196;
		X[Pr + 2][Pc - 1] = 196;
		X[Pr + 2][Pc] = 196;
		X[Pr + 2][Pc + 1] = 196;
		X[Pr + 1][Pc] = '/';
		X[Pr + 1][Pc + 2] = '/';
		X[Pr - 1][Pc] = '\\';
		X[Pr - 1][Pc + 2] = '\\';
		X[Pr][Pc - 3] = 228;
		X[Pr][Pc - 4] = ']';
	}
	if (X[Pr + 3][Pc - 1] == '^' || X[Pr + 3][Pc] == '^' || X[Pr + 3][Pc + 1] == '^' || X[Pr + 2][Pc] == '^' || X[Pr + 2][Pc + 2] == '^' || X[Pr][Pc + 6] == '^')
	{
		dp = 1;
	}
	if (dp == 1)
	{
		X[Pr][Pc - 3] = ' ';
		X[Pr][Pc - 2] = ' ';
		X[Pr][Pc - 1] = ' ';
		X[Pr][Pc] = ' ';
		X[Pr][Pc + 1] = ' ';
		X[Pr][Pc + 2] = ' ';
		X[Pr][Pc + 3] = ' ';
		X[Pr][Pc + 4] = ' ';
		X[Pr][Pc + 5] = ' ';
		X[Pr - 2][Pc - 1] = ' ';
		X[Pr - 2][Pc] = ' ';
		X[Pr - 2][Pc + 1] = ' ';
		X[Pr + 2][Pc - 1] = ' ';
		X[Pr + 2][Pc] = ' ';
		X[Pr + 2][Pc + 1] = ' ';
		X[Pr + 1][Pc] = ' ';
		X[Pr + 1][Pc + 2] = ' ';
		X[Pr - 1][Pc] = ' ';
		X[Pr - 1][Pc + 2] = ' ';
		X[Pr][Pc - 3] = ' ';
		X[Pr][Pc - 4] = ' ';
		dp++;
	}
}
/*void tlqa(char X[][1700], int& Rh, int& Ch, char ch, int& pos, int& pos2)
{
	if (ch == 'o')
	{
		X[Rh - 1][Ch] = '+';
		pos = Rh-1;
		pos2 = Ch;
	}
	if (X[pos][pos2] == '+')
	{
		X[pos - 1][pos2] = '+';
		X[pos][pos2] = ' ';
		pos--;
	}

}*/
void DrawEnemy2(char X[][1700], int Er2, int Ec2, int& sp)
{
	if (sp == 0)
	{
		X[Er2][Ec2] = 233;
		X[Er2 + 1][Ec2] = 240;
		X[Er2 + 1][Ec2 + 1] = '\\';
		X[Er2 + 1][Ec2 - 1] = '/';
		X[Er2 + 2][Ec2] = 208;
	}
	if (X[Er2 + 1][Ec2 + 2] == char(60) || X[Er2 + 1][Ec2 - 2] == char(62) || X[Er2 + 1][Ec2 + 2] == '-' || X[Er2 + 1][Ec2 - 2] == '-')
	{
		sp = 1;
	}
	if (sp == 1)
	{
		X[Er2][Ec2] = ' ';
		X[Er2 + 1][Ec2] = ' ';
		X[Er2 + 1][Ec2 + 1] = ' ';
		X[Er2 + 1][Ec2 - 1] = ' ';
		X[Er2 + 2][Ec2] = ' ';
		sp++;
		Num = 0;
	}
}
void DrawHero(char X[][1700], int Rh, int Ch)
{
	X[Rh][Ch] = 2;
	X[Rh + 1][Ch] = 232;
	X[Rh + 1][Ch + 1] = '\\';
	X[Rh + 1][Ch - 1] = '/';
	X[Rh + 2][Ch] = 531;
	X[Rh + 1][Ch + 2] = 213;
	X[Rh + 1][Ch - 2] = 184;
}
void drawhero2(char X[][1700], int Rh, int Ch)
{
	X[Rh][Ch] = '@';
	X[Rh + 1][Ch] = 232;
	X[Rh + 1][Ch + 1] = '\\';
	X[Rh + 1][Ch - 1] = '/';
	X[Rh + 2][Ch - 1] = '/';
	X[Rh + 2][Ch + 1] = '\\';
	X[Rh + 1][Ch + 2] = '-';                 //////////
	X[Rh + 1][Ch + 3] = '-';
	X[Rh + 1][Ch - 2] = '-';
	X[Rh + 1][Ch - 3] = '-';
	X[Rh + 2][Ch] = 429;
}

void drawelevators(char X[][1700], int& ans, int& dlr, int& dlc)
{
	if (ans == 1)
	{
		X[dlr][dlc + 1] = '=';
		X[dlr][dlc + 2] = '=';
		X[dlr][dlc + 3] = '=';                  //////////
		X[dlr][dlc + 4] = '=';

	}
}
void moveelevators(char X[][1700], int& dlr, int& dlc, int& Rh, int& Ch)
{
	if (dlr > 10)
	{
		dlr--;
		Rh--;                               //////////////
		dlc += 2;
		Ch += 2;
	}
}
void enemyga(char X[][1700], int& gac, int& gar, int& gabr, int& gabc)
{
	X[gar][gac] = 20;
	X[gar + 1][gac] = 240;
	X[gar + 1][gac + 1] = '\\';
	X[gar + 1][gac - 2] = '-';
	X[gar + 1][gac - 3] = '-';
	X[gar + 1][gac - 4] = 425;
	X[gar + 2][gac - 4] = '|';
	X[gar + 1][gac - 5] = '-';
	X[gar + 1][gac - 1] = '/';
	X[gar + 2][gac] = 208;
	X[gar + 3][gac - 4] = '=';
	X[gar + 3][gac - 3] = '=';
	X[gar + 3][gac - 2] = '=';
	X[gar + 3][gac - 1] = '=';
	X[gar + 3][gac] = '=';
	X[gar + 3][gac + 1] = '=';
	X[gar + 3][gac + 2] = '=';
	X[gar + 3][gac + 3] = '=';


	X[gabr][gabc] = 423;
	X[gabr][gabc - 4] = 423;
	X[gabr][gabc - 2] = 423;
	if (gabr < 21)
	{
		gabr += 2;
		gabc--;
	}
	else
	{
		gabr = 6;
		gabc = 1686;
	}

}

void MoveHero(char ch, int& Rh, int& Ch, int Ec1, int& f, char X[][1700], int Ec2, int& ct2, int& ct4, int& ct5, int& h, int& b1, int& k, int& k1, int& lvlr, int& lvlc, int& lvl2r, int& lvl2c, int& kct, HeroBullet& bull, int& bdir, int& lvl3r, int& lvl3c, int& ct7, int& ctkey3, int& htc, int& ct9, int& ct60)
{
	int r = 0;

	if (ch == 'd')
	{
		if (Ch + 4 != 675 && Ch != 1404 && X[Rh][Ch + 3] != char(176))
		{
			if (Ch + 3 == 239 && ct4 != 0 && ct5 != 0)
			{
				Ch += 2;
			}
			if (Ch < 239 || Ch>239)
			{
				Ch += 2;
			}
		}
		if (Ch > 59)
		{
			k1 += 2;
		}
		if (Ch > 858)
		{
			htc += 2;
		}
		if (Ch > 59 && Ch < 239)
		{
			lvlc += 2;
		}
		if (Ch > 300 && Ch < 670)
		{
			lvl2c += 2;
		}
		if (Ch > 855 && Ch < 1700)
		{
			lvl3c += 2;
		}
		bdir = 0;
		X[Rh + 1][Ch + 2] = 213;
	}
	if (ch == 'a' && X[Rh][Ch - 2] != char(219) && X[Rh][Ch - 1] != char(176))
	{
		Ch -= 2;
		if (Ch > 60)
		{
			k1 -= 2;
		}
		if (Ch > 59 && Ch < 239)
		{
			lvlc -= 2;
		}
		if (Ch < 300 && Ch > 675)
		{
			lvl2c -= 2;
		}
		if (Ch > 855 && Ch < 1700)
		{
			lvl3c -= 2;
		}
		bdir = 1;
	}
	if (ch == 's')
	{
		if (X[Rh + 3][Ch] != char(178) && X[Rh + 3][Ch] != char(177))
		{
			Rh++;
		}
	}
	if (ch == 'x')
	{
		if (Ch < 235 || Ch + 4 == char(176))
		{
			Ch += 4;
			if (Ch > 59)
			{
				k1 += 4;
			}
			if (Ch > 59)
			{
				htc += 4;
			}
			if (Ch > 800)
			{
				htc = 800;
			}
			if (Ch > 59 && Ch < 239)
			{
				lvlc += 4;
			}
			if (Ch > 300 && Ch < 480)
			{
				lvl2c += 4;
			}
			if (Ch > 795 && Ch < 1700)
			{
				lvl3c += 4;
			}
		}
		if (Ch > 237 && ct5 == 3)
		{
			Ch += 4;
		}
	}
	if (ch == 'z')
	{
		if (Ch - 2 != 239)
		{
			if (Ch < 675 || Ch>679)
			{
				Ch -= 4;
			}
		}
		if (Ch > 60)
		{
			k1 -= 4;
		}
		if (Ch > 59 && Ch < 239)
		{
			lvlc -= 4;
		}
		if (Ch > 300 && Ch > 240)
		{
			lvl2c -= 4;
		}
		if (Ch > 855 && Ch < 1700)
		{
			lvl3c -= 4;
		}
	}
	if (ch == 'e')
	{
		bull.NewBullet(Rh, Ch, bdir);
	}
	if (X[Rh + 1][Ch + 4] == char(499) || X[Rh][Ch + 1] == char(499) || X[Rh - 1][Ch - 1] == char(423) || X[Rh - 1][Ch + 1] == char(423) || X[Rh - 1][Ch] == char(423) || X[Rh - 1][Ch] == 'o' || X[Rh - 1][Ch] == 'e' || X[Rh - 1][Ch] == 's' || X[Rh - 1][Ch] == 'u' || X[Rh - 1][Ch] == 'r' || X[Rh - 1][Ch] == 'i' || X[Rh - 1][Ch] == 'v' || X[Rh - 1][Ch] == 'g' || X[Rh - 1][Ch] == 'b' || X[Rh + 2][Ch + 3] == char(423) || X[Rh + 1][Ch + 4] == char(423) || X[Rh][Ch + 2] == char(423) || X[Rh][Ch + 1] == char(233) || X[Rh][Ch + 1] == char(15) || X[Rh][Ch - 1] == char(233) || X[Rh][Ch - 1] == char(15) || X[Rh][Ch + 2] == char(186) || X[Rh][Ch - 2] == char(186) || X[Rh - 2][Ch] == char(186) || X[Rh - 1][Ch - 2] == char(186) || X[Rh][Ch] == char(186) || X[Rh - 1][Ch] == char(287) || X[Rh + 3][Ch] == char(286) || X[Rh + 1][Ch + 2] == char(287) || X[Rh + 1][Ch - 2] == char(287) || X[Rh + 1][Ch + 3] == char(17) || X[Rh + 1][Ch - 3] == char(16) || X[Rh + 1][Ch + 3] == '+' || X[Rh + 1][Ch + 4] == char(273) || X[Rh + 1][Ch - 4] == char(272) || X[Rh][Ch + 3] == char(278) || X[Rh + 3][Ch] == char(127) || X[Rh + 1][Ch - 3] == char(209) || X[Rh - 1][Ch] == char(281) || X[Rh + 1][Ch + 3] == char(238))
	{
		f = 1;
	}
	if (X[Rh + 2][Ch - 2] == char(239))
	{
		ct4++;
	}
	if (X[Rh + 2][Ch + 1] == 'o' || X[Rh + 2][Ch] == 'o')
	{
		kct++;
	}
	if (X[Rh + 1][Ch + 4] == 'M' || X[Rh + 1][Ch + 3] == 'M')
	{
		ctkey3++;
	}
	if (X[Rh + 1][Ch + 3] == char(162) || X[Rh + 1][Ch + 4] == char(162))
	{
		ct5++;
	}
	if (Ch == 199 || Ch == 200)
	{
		if (X[Rh + 3][Ch] != ' ')
		{
			for (int i = 0; i < 17; i++)
			{
				Rh--;
			}
		}
	}
	if (ch == 'w' && X[Rh + 3][Ch] != ' ')
	{
		Rh -= 6;
	}
	if (ch == 'p' && X[Rh + 3][Ch] != ' ')
	{
		for (int i = 0; i < 8; i++)
		{
			if (X[Rh - 1][Ch] == ' ')
			{
				Rh--;
			}
		}
	}
	if (ch == ' ')
	{
		if (ct60 < 3)
		{                          //double jump//
			Rh -= 4;
			ct60++;
		}
	}
	if (X[Rh + 3][Ch] == char(476) || X[Rh + 3][Ch] == char(79) || X[Rh + 4][Ch] == '=' || X[Rh + 3][Ch] == char(495) || X[Rh + 3][Ch] == char(176) || X[Rh + 3][Ch] == char(178) || X[Rh + 3][Ch] == char(196) || X[Rh + 3][Ch] == '|' || X[Rh + 3][Ch] == char(286) || X[Rh + 3][Ch] == char(254) || X[Rh + 3][Ch] == char(205) || X[Rh + 3][Ch] == char(177))
	{
		ct60 = 0;
	}

}

void main()
{
	int len = 0;
	int ler = 10;
	int lec = 110;
	int lop = 107;
	int ct60 = 0;
	int lkm = 0;
	int dp = 0;
	int j = 0;
	int pos = 0;
	int pos2 = 0;
	int sp = 0;
	int yow = 0;
	int bec = 630;
	int hedir = 0;
	int hevr = 12;
	int hevc = 411;
	int p = 80;
	int dd = 80;
	int ddd = 80;
	int dddd = 80;
	int ddddd = 80;
	int hbd = 0;
	int hblr = 13;
	int hblc = 80;
	HeroBullet bull;
	int fbc = 270;
	int bdir = 0;
	int fbr = 2;
	int ct5 = 0;
	int ct4 = 0;
	int ct2 = 0;
	char X[34][1700];
	int Rh = 18;
	int Ch = 15;
	int Er1 = 13;
	int Ec1 = 31;
	int De1 = 1;
	int De2 = 1;
	int De3 = 1;
	int Pc = 77;
	int Pr = 6;
	int Br = 9;
	int Bc = 78;
	int ct = 0;
	int Er2 = 5;
	int Ec2 = 168;
	int f = 0;
	int r = 3;
	int d = 120;
	int t = 0;
	int bl = 19;
	int obl = bl;
	int h = 0;
	int Evr = 21;
	int Evc = 340;
	int dee = 0;
	int yu = 0;
	int gg = 60;
	int lvlr = 2;
	int lvlc = 4;
	int k = 3;
	int k1 = 2;
	int lvl2r = 2;
	int lvl2c = 243;
	int lvl3r = 3;
	int lvl3c = 798;
	int kct = 0;
	int wavingflagr = 21;
	int wavingflagc = 624;
	int ct7 = 0;
	int thelr = 15;
	int thelc = 970;
	int thedir = 0;
	int bmw = Ec2;
	int tbu = 0;
	int ct8 = 0;
	int ct11 = 0;
	int wflvl1c = 250;
	int wflvl1r = 21;
	int fcellr = 13;
	int fcellc = 1230;
	int fcdir = 0;
	int Enmc = 922;
	int Enmr = 15;
	int hop = Enmc + 1;
	int Enmc2 = 850;
	int Enmr2 = 19;
	int hopp = Enmc2 + 1;
	int xv = 0;
	int vx = 0;
	int Enmcl2 = 630;
	int Enmrl2 = 19;
	int vvx = 0;
	int hoppp = Enmcl2 + 1;
	int ctkey3 = 0;
	int htr = 2;
	int htc = 798;
	int m = 4;
	int s = 4;
	int lai = 0;
	int ebo = 1350;
	int ct9 = 3;
	int gender;
	int pbr = 6;
	int pbc = 1500;
	int lim = 0;
	int cr = 16;
	int cc = 1590;
	int cb = 0;
	int chop = 1588;
	int rr = 21;
	int rc = 43;
	int ans = 0;
	int dlr = 21;
	int dlc = 1360;
	int gha = 0;
	int qnr = 20;
	int qhop = 1650;
	int abl = 0;
	int gar = 5;
	int gac = 1690;
	int gabr = 6;
	int gabc = 1686;
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "                                           choose 1 for mario , 2 for femario :)";
	cin >> gender;
	for (int i = 0; ; i++)
	{
		if (yu == 0)
		{
			if (_kbhit())
			{
				yu++;
				while (1)
				{
					if (X[Rh + 3][Ch] != char(476) && X[Rh + 3][Ch] != char(79) && X[Rh + 4][Ch] != '=' && X[Rh + 3][Ch] != char(495) && X[Rh + 3][Ch] != char(176) && X[Rh + 3][Ch] != char(178) && X[Rh + 3][Ch] != char(196) && X[Rh + 3][Ch] != '|' && X[Rh + 3][Ch] != char(286) && X[Rh + 3][Ch] != char(254) && X[Rh + 3][Ch] != char(205) && X[Rh + 3][Ch] != char(177))
					{
						Rh++;
					}
					if (X[Rh + 3][Ch] == char(254))
					{
						Rh--;
					}
					if (X[Rh + 3][Ch] == char(205) && Rh == 8 && Ch == 971)
					{
						Ch++;
					}
					if (_kbhit())
					{
						char ch = _getch();
						if (ch == 'k')
						{
							int pos_r = 2000, pos_c = 2000;
							while (1)
							{
								cout << "enter col";
								cin >> pos_c;
								cout << "enter row";
								cin >> pos_r;
								if (pos_c < 2000 && pos_c >= 0 && pos_r < 20 && pos_r > 0)
								{
									Ch = pos_c;
									Rh = pos_r;
									break;
								}
							}
						}
						if (Ch == 1360 && ans == 0)
						{
							cout << "you have to answer the question to continue ";
							cout << endl;
							cout << "what is the '%'sign means in c++" << endl;             //////////
							cout << "1.Remainder      2.percent";
							cin >> ans;
						}

						MoveHero(ch, Rh, Ch, Ec1, f, X, Ec2, ct2, ct4, ct5, h, bl, k, k1, lvlr, lvlc, lvl2r, lvl2c, kct, bull, bdir, lvl3r, lvl3c, ct7, ctkey3, htc, ct9, ct60);
						//tlqa(X, Rh, Ch, ch, pos, pos2);
						if (ct4 > 0 && X[Rh - 1][Ch] == '_' && ct5 == 3)
						{
							cout << "YOU WON NOW PRESS X TO ADVANCE TO THE NEXT AREA";
						}
						if (ans == 2)
						{
							break;
						}
						if (f == 1)
						{
							if (Ch > 624 && ct11 < 3 && Ch < 1500)
							{
								ct11++;
								Ch = 624;
								Rh = 19;
								f = 0;
							}
							if (ct11 >= 3)
							{
								cout << "YOU WERE SLAIN BY AN ENEMY";
								break;
							}
							if ((Ch < 624) && (ct9 == 0))
							{
								cout << "YOU WERE SLAIN BY AN ENEMY";
								break;
							}
							if (Ch < 624 && ct9>1)
							{
								Ch = 15;
								Rh = 19;
								f = 0;
								k1 = 2;
								ct9--;
							}
							if (Ch > 1500)
							{
								cout << "YOU WERE killed by a compiler issue";
								break;

							}
						}
						if (X[Rh + 3][Ch] == char(79) && Rh > 11)
						{
							Rh = 18;
							Ch = 1500;         ////////
						}
						if (Ch > 1690)
						{
							Ch = 98;
							Rh = 19;

						}
						if (Ch == 1395 && ctkey3 > 0)
						{
							cout << "you won" << endl;
							break;
						}
					}

					if (Ch > 1395 && Ch < 1400 && ctkey3 > 0)
					{
						cout << "congratulation" << endl;
						cout << "you won" << endl;
						cout << "game finished" << endl;
						break;
					}
					if (X[Rh + 3][Ch] == char(79) && Rh > 11)
					{
						Rh = 18;
						Ch = 1500;         ////////
					}
					if (X[Rh + 1][Ch + 4] == char(499) || X[Rh][Ch + 1] == char(499) || X[Rh - 1][Ch - 1] == char(423) || X[Rh - 1][Ch + 1] == char(423) || X[Rh - 1][Ch] == char(423) || X[Rh - 1][Ch] == 'o' || X[Rh - 1][Ch] == 'e' || X[Rh - 1][Ch] == 's' || X[Rh - 1][Ch] == 'u' || X[Rh - 1][Ch] == 'r' || X[Rh - 1][Ch] == 'i' || X[Rh - 1][Ch] == 'v' || X[Rh - 1][Ch] == 'g' || X[Rh - 1][Ch] == 'b' || X[Rh + 2][Ch + 3] == char(423) || X[Rh + 1][Ch + 4] == char(423) || X[Rh][Ch + 2] == char(423) || X[Rh][Ch + 1] == char(233) || X[Rh][Ch + 1] == char(15) || X[Rh][Ch - 1] == char(233) || X[Rh][Ch - 1] == char(15) || X[Rh][Ch + 2] == char(186) || X[Rh][Ch - 2] == char(186) || X[Rh - 2][Ch] == char(186) || X[Rh - 1][Ch - 2] == char(186) || X[Rh][Ch] == char(186) || X[Rh - 1][Ch] == char(287) || X[Rh + 3][Ch] == char(286) || X[Rh + 1][Ch + 2] == char(287) || X[Rh + 1][Ch - 2] == char(287) || X[Rh + 1][Ch + 3] == char(17) || X[Rh + 1][Ch - 3] == char(16) || X[Rh + 1][Ch + 3] == '+' || X[Rh + 1][Ch + 4] == char(273) || X[Rh + 1][Ch - 4] == char(272) || X[Rh][Ch + 3] == char(278) || X[Rh + 3][Ch] == char(127) || X[Rh + 1][Ch - 3] == char(209) || X[Rh - 1][Ch] == char(281) || X[Rh + 1][Ch + 3] == char(238))
					{
						f = 1;
					}
					if (f == 1)
					{
						if (Ch > 624 && ct11 < 3 && Ch < 1500)
						{
							ct11++;
							Ch = 624;
							Rh = 19;
							f = 0;
						}
						if (ct11 >= 3)
						{
							cout << "YOU WERE SLAIN BY AN ENEMY";
							break;
						}
						if (Ch < 624 && ct9 < 1)
						{
							cout << "YOU WERE SLAIN BY AN ENEMY";
							break;
						}
						if (Ch < 624 && ct9>0)
						{
							Ch = 15;
							Rh = 19;
							f = 0;
							k1 = 2;
							ct9--;
						}
						if (Ch > 1500)
						{
							cout << "YOU WERE killed by a compiler issue";      ///////
							break;

						}
					}
					if (Rh > 22 && X[Rh + 3][Ch] == ' ' && X[Rh + 2][Ch] == ' ')			//jumping underground
					{
						if (Ch < 1033 || Ch>1130)
						{
							if (Ch > 624 && ct11 < 3 && Ch < 1500)
							{
								ct11++;
								Ch = 627;
								Rh = 19;
								f = 0;
							}
							if (ct11 >= 3)
							{
								cout << "YOU FELL OUT OF THE WORLD";
								break;
							}
							if ((Ch < 624) && (ct9 == 0))
							{
								cout << "YOU WERE SLAIN BY AN ENEMY";
								break;
							}
							if (Ch < 624 && ct9>0)
							{
								Ch = 15;
								Rh = 19;
								k1 = 2;
								f = 0;
								ct9--;
							}
							if (Ch > 1500)
							{
								cout << "YOU WERE killed by a compiler issue";
								break;

							}
						}
					}

					FillMatrixByMyBackGround(X, ct4, ct5, Ch, Rh, k, k1, kct, ctkey3, ct9, m);
					if (gender == 1)
					{
						DrawHero(X, Rh, Ch);          ////////
					}
					if (gender == 2)
					{
						drawhero2(X, Rh, Ch);
					}
					bull.DrawHeroBullet(X, bdir, gender);
					bull.FireBullet(bdir);
					DrawElevator(X, Evr, Evc);
					DrawHorizontalElevator(X, hevr, hevc);

					drawelevators(X, ans, dlr, dlc);
					if (X[Rh + 4][Ch] == '=')
					{
						gha = 1;                  //////
					}
					if (gha == 1)
					{
						moveelevators(X, dlr, dlc, Rh, Ch);            /////////
					}
					DrawEnemy1(X, Er1, Ec1, yow);
					DrawFallingSpikes(X, fbr, fbc);
					laserenemy(X, ler, lec, lop, len);
					MoveFallingSpikes(fbr, fbc, Ch);
					rockets(X, rr, rc, Ch, lkm);
					Ebullet(X, Ec2, Er2, bmw, Rh, Ec2);
					HellBladeMove(X, hblr, hblc, hbd, Ch, Rh, p, dd, ddd, dddd, ddddd);
					MoveEnemy1(X, De1, Ec1, Er1, yow);
					enemyga(X, gac, gar, gabr, gabc);
					MovePlane(De2, Pr, Pc, X, dp);
					MoveElevator(X, Evr, Evc, Rh, Ch, dee);
					MovethirdElevator(X, thelr, thelc, Rh, Ch, thedir);
					MoveWavingFlaglvl1(X, wflvl1r, wflvl1c, Rh, Ch);
					MoveWavingFlag(X, wavingflagr, wavingflagc, Rh, Ch);
					MoveFallingCelling(X, fcellr, fcellc, fcdir, Ch, Rh);
					qnabl(X, qhop, qnr, abl);
					//laserhero(X, Rh, Ch);
					prog(X, pbr, pbc, lim);
					//Drawlvl2Enemy(X , Enmcl2, Enmrl2, hoppp, Rh, Ch, vvx);
					Drawlvl3Enemy(X, Enmc2, Enmr2, hopp, Rh, Ch, vx);
					DrawThirdEnemy(X, Enmc, Enmr, hop, Rh, Ch, xv);
					Hearts(X, htr, htc, Rh, Ch, ct8);
					sahaba(X, s, ebo, lai);
					if (X[Rh + 3][Ch] == char(461) || X[Rh + 2][Ch] == char(461) || X[Rh + 4][Ch] == char(461))
					{
						MoveHorizontalElevator(X, hevr, hevc, hedir, Ch, lvl2c, htc);
					}
					DrawPlane(X, Pr, Pc, dp);
					DrawLvl(X, lvlr, lvlc);
					Drawlvl2(X, lvl2r, lvl2c, ct4, bec, tbu);
					Drawlvl3(X, lvl3r, lvl3c);
					comp(X, cb, cr, cc, chop);
					DrawFallingCelling(X, fcellr, fcellc);
					DrawWavingFlag(X, wavingflagr, wavingflagc);
					DrawWavingFlaglvl1(X, wflvl1r, wflvl1c);
					DrawThirdElevator(X, thelr, thelc);
					DrawEnemy2(X, Er2, Ec2, sp);
					MoveEnemy2(X, De3, Er1, Ec2, sp);
					DispTopScreen(X, Ch, Rh);
				}
			}
		}
	}
}
