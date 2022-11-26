//Ashley Howell
//Nov 1
//Deep rock Text based adventure

//Yes this is horribly written, but it runs

//Bugs:
//-Entering a letter instead of number leads to reapted messages


//Notes/to be done, nov 24:
//end room
//g move 8 - 20 line 1256
//g attack
//move order player move, player attack, g move, g attack

#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <string>
using namespace std;

void main()
{
	system("Color 02");
	//yes this is horrible naming, but it just makes the maps so much easier. This i all for the map and movement system
	//ore map 1
	char C1 = 'C', N1 = 'N', G1 = 'G', G11='G', G12='G';

	//movement
	char X1 = 'D', X2 = 'X', X3 = 'X', X4 = 'X', X5 = 'X', X6 = 'X', X7 = 'X';

	//location: first digit is room #, following digits is loaction, input: what the player chooses to do
	int location = 11, input = 0, nitra = 0, gold = 0, oredrop = 0, swarmchance = 13, swarm = 0, goingmap=1, oreamount=1;

	//map 2 location
	char X201 = 'X', X202 = 'X', X203 = 'X', X204 = 'X', X205 = 'X', X206 = 'X', X207 = 'X', X208 = 'X', X209 = 'X', X210 = 'X', X211 = 'X';

	//map 2 ore
	char N2 = 'N', N3 = 'N', N4 = 'N', N5 = 'N', G2 = 'G', C2 ='C';

	//swarm map locations
	char XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X', XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X', XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X', XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';

	//misc/I didnt feel like finding the correct category
	string swarmmove;
	string swarmattack;
	int validinput = 0, damage = 0, prelocation1, prelocation2, prelocation3, prelocation4, prelocation5, prelocation6;
	//combat: health = player health, gxh = enemy health, gxl = enemy location
	int health = 100, enemycount = 0, g1h = 25, g2h = 25, g3h = 25, g4h = 25, g5h = 25, g6h = 25, g7h = 25, g8h = 25, g9h = 25, g10h = 25, g11h = 25, g12h = 25, g13h = 25, gcheck = 0, g1l = 0, g2l = 0, g3l = 0, g4l = 0, g5l = 0, g6l = 0, g7l = 0, g8l = 0, g9l = 0, g10l = 0, g11l = 0, g12l = 0, g13l = 0;
	//---------------------------------------------------------------------------------------------------------------------


	//display controls
	cout << "These are your controls" << '\n' << "1) North ^" << '\n' << "2) West <" << '\n' << "3) South v" << '\n' << "4) East >" << '\n' << "5) Inventory" << '\n' << "6) Mine" << '\n' <<'\n'<< "8) Help" << '\n' << '\n';

	//first map
	cout << "#####################################" << '\n';
	cout << "#" << C1 << C1 << C1 << C1 << C1 << C1 << C1 << " |                          #" << '\n';
	cout << "#\\" << C1 << C1 << "     |                          #" << '\n';
	cout << "# \\  " << X7 << "    \\______                   #" << '\n';
	cout << "#  |             \\       __         #" << '\n';
	cout << "#  |              \\_____/  |        #" << '\n';
	cout << "#   \\   " << X6 << "        " << X2 << "        " << X3 << " \\       #" << '\n';
	cout << "#    \\                       \\      #" << '\n';
	cout << "#    |     |            |     |     #" << '\n';
	cout << "#     \\    |            |      \\    #" << '\n';
	cout << "#     |    |     " << X1 << "      |       \\__ #" << '\n';
	cout << "#     |    |            |          |#" << '\n';
	cout << "#      \\   \\            /          |#" << '\n';
	cout << "#       |   \\          /          / #" << '\n';
	cout << "#       |    \\________/          /  #" << '\n';
	cout << "#       " << N1 << X5 << "	             ___/   #" << '\n';
	cout << "#       " << N1 << "	         " << X4 << "   \\      #" << '\n';
	cout << "#      |	         " << G1 << G1 << "__/      #" << '\n';
	cout << "#      \\	         " << G11 << G12 << "         #" << '\n';
	cout << "#       \\_______________/           #" << '\n';
	cout << "#####################################" << '\n' << '\n';

	//legend
	cout << "Legend: " << '\n' << "D = Dwarf/Yourelf" << '\n' << "x = Place you can move to" << '\n' << "C = Collasped dirt" << '\n' << "N = Nitra" << '\n' << "G = Gold" << '\n' << "g = Glyphid" << '\n';

	//preveiw of map thats not a formating mess and for referance
//#####################################
//#CCCCCCC |                          #
//#\CC     |                          #
//# \ 17   \_______                   #
//#  |             \       __         #
//#  |              \_____/  |        #
//#   \  16        12      13 \       #
//#    \                       \      #
//#    |     |            |     |     #
//#     \    |            |      \    #
//#     |    |     11     |       \__ #
//#     |    |            |          |#
//#      \   \            /          |#
//#       |   \          /          / #
//#       |    \________/          /  #
//#       N	                   ___/   #
//#	      N	15               14  \    #
//#       |	                 GG__/    #
//#        \	             GG       #
//#         \_______________/         #
//#####################################

  //note managment has been laid off

	cout << '\n' << "Welcome miner, management has assigned you a simple mission to get you started, find the end of the cave and get out. Bonuses are available for minerals brought back." << '\n' << "-Mision Control" << '\n';




	//---------------------------------------------------------------------------------------------------------------------

		//Main switch statement 
findlocation:

	//enter your input
	cout << "========================================================================================" << '\n' << '\n' << "What would you like to do? ";
	cin >> input;

	//update loaction value
	if (X1 == 'D') { location = 11; }
	if (X2 == 'D') { location = 12; }
	if (X3 == 'D') { location = 13; }
	if (X4 == 'D') { location = 14; }
	if (X5 == 'D') { location = 15; }
	if (X6 == 'D') { location = 16; }
	if (X7 == 'D') { location = 17; }

	switch (location)
	{
	case 11:	switch (input)
		{
		case 1: X1 = 'X'; X2 = 'D'; goto findmap;//north
		case 5: goto inventory;//inv
		case 8: goto help;//controls
		default: cout << "You can't do that here." << '\n'; goto findlocation;
			break;
		}

	case 12:	switch (input)
		{
		case 2: X2 = 'X'; X3 = 'D'; goto findmap;//east
		case 3: X2 = 'X'; X1 = 'D'; goto findmap;//south		
		case 4: X2 = 'X'; X6 = 'D'; goto findmap;//west	
		case 5: goto inventory;//inv
		case 8: goto help;//controls
		default: cout << "You can't do that here." << '\n'; goto findlocation;
			break;
		}

	case 13:	switch (input)
		{
		case 3: X3 = 'X'; X4 = 'D'; goto findmap;//south
		case 4: X3 = 'X'; X2 = 'D'; goto findmap;//west
		case 5: goto inventory;//inv
		case 8: goto help;//controls
		default: cout << "You can't do that here." << '\n'; goto findlocation;
			break;
		}

	case 14:	switch (input)
		{
		case 1: X4 = 'X'; X3 = 'D'; goto findmap;//north
		case 4: X4 = 'X'; X5 = 'D'; goto findmap;//west
		case 5: goto inventory;//inv
		case 6: if (G1 == 'G')//mine
			{
			G11 = '_';
			G12 = '/';
			G1 = ' ';
			oreamount = 4;
			goto gold1;
			}
			  else
				{cout << "You can't do that here." << '\n'; goto findlocation;}
		case 8: goto help;//controls
		default: cout << "You can't do that here." << '\n'; goto findlocation;
			break;
		}

	case 15:	switch (input)
		{
		case 1: X5 = 'X'; X6 = 'D'; goto findmap;//north
		case 2: X5 = 'X'; X4 = 'D'; goto findmap;//east
		case 5: goto inventory;//inv
		case 6:  if (N1 == 'N')//mine
		{
			N1 = '|';
			oreamount = 2;
			goto nitra1;
		}
				  else
				{cout << "You can't do that here." << '\n'; goto findlocation;}
		case 8: goto help;//controls
		default: cout << "You can't do that here." << '\n'; goto findlocation;
			break;
		}

	case 16:	switch (input)
		{
		case 1: X6 = 'X'; X7 = 'D'; goto findmap;//north
		case 2: X6 = 'X'; X2 = 'D'; goto findmap;//east
		case 3: X6 = 'X'; X5 = 'D'; goto findmap;//south
		case 5: goto inventory;//inv
		case 8: goto help;//controls
		default: cout << "You can't do that here." << '\n'; goto findlocation;
			break;
		}

	case 17:	switch (input)
		{
		case 1:		if (C1 == ' ')//move to map 2
			{
			goingmap = 2;
			X201 = 'D';
			goto map2trans;
			}
				  else
					{cout << "There is collapsed dirt here. Maybe you could mine it. \n"; goto findlocation;}
		case 3: X7 = 'X'; X6 = 'D'; goto findmap;//south
		case 5: goto inventory;//inv
		case 6: C1 = ' '; goto findmap;//mine
		case 8: goto help;//controls
		default: cout << "You can't do that here." << '\n'; goto findlocation;
			break;
		}

	}



	//--------------------------------------------------------------------------------------------------------------------

		//inventory code
inventory:
	cout << "Your have: " << nitra << " nitra, " << gold << " gold" << '\n' << '\n';
	goto findfindlocation;

	//---------------------------------------------------------------------------------------------------------------------

		//display controls/help
help:
	cout << "1) North ^" << '\n' << "2) West <" << '\n' << "3) South v" << '\n' << "4) East >" << '\n' << "5) Inventory" << '\n' << "6) Mine" << '\n' << '\n' << '\n';
	cout << "Legend: " << '\n' << "D = Dwarf/Yourelf" << '\n' << "x = Place you can move to" << '\n' << "C = Collasped dirt" << '\n' << "N = Nitra" << '\n' << "G = Gold" << '\n' << "g = Glyphid" << '\n';
	goto findfindlocation;

	//---------------------------------------------------------------------------------------------------------------------

		//mine gold 
gold1:
	
	srand((unsigned)time(0));//ore drop between 3-8
	oredrop = (rand() % 8) + 3;
	gold = gold + oredrop * oreamount;//Mine gold
	swarmchance--;//increase chance
	cout << "Mined " << oredrop * oreamount << " ore" << '\n';
	goto findmap;

	//---------------------------------------------------------------------------------------------------------------------
		
		//mine nitra 
	nitra1:
	srand((unsigned)time(0));
	oredrop = (rand() % 15) + 7;
	nitra = nitra + oredrop * oreamount;//Mine nitra
	swarmchance = swarmchance - 1;//increase chance
	cout << "Mined " << oredrop * oreamount << " ore" << '\n';
	goto findmap;
	//---------------------------------------------------------------------------------------------------------------------

		//swarm
swarm:

	srand((unsigned)time(0));
	swarm = (rand() % swarmchance) + 1;
	
	if (swarm == 1)//if swarm is called, 
	{
		XS13 = 'D';
		swarm = 0;
		goto spawn;
	}
	else
	{
		goto findfindlocation;
	}
	//---------------------------------------------------------------------------------------------------------------------
		//swarm map and combat
	swarmmap:
	cout << "#####################################" << '\n';//this map wa orriganly 81 varriables/locations
	cout << "# A       B       C       D       E #" << '\n';
	cout << "#1"<<XS1<<"       "<<XS2<<"       " << XS3 << "       " << XS4 << "       " << XS5 << " #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#2" << XS6 << "       " << XS7 << "       " << XS8 << "       " << XS9 << "       " << XS10 << " #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#3" << XS11 << "       " << XS12 << "       " << XS13 << "       " << XS14 << "       " << XS15 << " #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#4" << XS16 << "       " << XS17 << "       " << XS18 << "       " << XS19 << "       " << XS20 << " #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#5" << XS21 << "       " << XS22 << "       " << XS23 << "       " << XS24 << "       " << XS25 << " #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#####################################" << '\n' << '\n';
	system("Color 04");
	goto combat;

	spawn:
	switch (swarmchance)
	{
	case 13: enemycount = 2, g1h = 25, g2h = 25, //enemy count assigned, and health
						XS1 = 'g', XS2 = 'g', //enemies spawned
						g1l = 1, g2l = 2; goto swarmmap;//assign location data
	case 12: enemycount = 2, g1h = 25, g2h = 25,
						XS16 = 'g', XS21 = 'g',
						g1l = 16, g2l = 21; goto swarmmap;

	case 11: enemycount = 3, g1h = 25, g2h = 25, g3h = 25,
						XS1 = 'g', XS2 = 'g', XS6 ='g',
						g1l = 1, g2l =2; goto swarmmap;

	case 10: enemycount = 3, g1h = 25, g2h = 25,  g3h=25,
						XS24 = 'g', XS25 = 'g', XS20 = 'g',
						g1l=24, g2l =25, g3l= 20; goto swarmmap;

	case 9: enemycount = 4, g1h = 25, g2h = 25, g3h =25, g4h =25,
						XS5 = 'g', XS4 = 'g', XS3='g', XS10 ='g'; goto swarmmap;

	case 8: enemycount =4, g1h = 25, g2h = 25, g3h = 25, g4h = 25,
						XS21 = 'g', XS22 = 'g', XS3 = 'g', XS4 = 'g'; goto swarmmap;

	case 7: enemycount = 5, g1h = 25, g2h = 25, g3h = 25, g4h = 25, g5h = 25,
		XS21 = 'g', XS22 = 'g', XS3 = 'g', XS4 = 'g', XS1 = 'g'; goto swarmmap;

	case 6: enemycount = 5, g1h = 25, g2h = 25, g3h = 25, g4h = 25, g5h = 25,
		XS21 = 'g', XS22 = 'g', XS3 = 'g', XS4 = 'g', XS1= 'g'; goto swarmmap;

	case 5: enemycount = 6, g1h = 25, g2h = 25, g3h = 25, g4h = 25, g5h = 25, g6h = 25,
			XS21 = 'g', XS22 = 'g', XS3 = 'g', XS4 = 'g', XS1='g', XS25; goto swarmmap;

	default: cout << "something very wrong has happened (error swarmchance below 5/13)"; goto findfindlocation;//failsafe
		break;
	}
	goto findfindlocation;
	//---------------------------------------------------------------------------------------------------------------------
combat:
	cout << "We've got a blip on the radar try and fend them off and get back to mining!" << '\n' << "-Mision Control" << '\n';

	findlocationswarm:
	//update drawf location
	if (XS1 == 'D') { location = 901;}
	if (XS2 == 'D') { location = 902;}
	if (XS3 == 'D') { location = 903;}
	if (XS4 == 'D') { location = 904;}
	if (XS5 == 'D') { location = 905;}
	if (XS6 == 'D') { location = 906;}
	if (XS7 == 'D') { location = 907;}
	if (XS8 == 'D') { location = 908;}
	if (XS9 == 'D') { location = 909;}
	if (XS10 == 'D') { location = 910;}
	if (XS11 == 'D') { location = 911;}
	if (XS12 == 'D') { location = 912; }
	if (XS13 == 'D') { location = 913; }
	if (XS14 == 'D') { location = 914; }
	if (XS15 == 'D') { location = 915; }
	if (XS16 == 'D') { location = 916; }
	if (XS17 == 'D') { location = 917; }
	if (XS18 == 'D') { location = 918; }
	if (XS19 == 'D') { location = 919; }
	if (XS20 == 'D') { location = 920; }
	if (XS21 == 'D') { location = 921; }
	if (XS22 == 'D') { location = 922; }
	if (XS23 == 'D') { location = 923; }
	if (XS24 == 'D') { location = 924; }
	if (XS25 == 'D') { location = 925; }
swarmlocation:
	
	if (enemycount == 0) { cout << "The swarm is thining out, get back to work miner." << '\n' << "-Mision Control" << '\n'; system("Color 02"); goto findmap; }

	
	

move:
	cout << "Input where you would like to move, example D3, or A1 (Case sensitive)."<<'\n';
	//cin.get(swarmmove, 3);
	//cin.ignore(80, '\n');
	getline(cin, swarmmove);
	validinput = 0;

	//Lord fogive me

	if (swarmmove == "A1")//is it [cordinate]
	{
		if (XS1 == 'X')//is it free
		{
			XS1 = 'D'; goto fixlocation;//yes skip rest go to
		}
		else cout << "Something is already in this location" << '\n'; goto move;//go back to reinput
	}//continue until input is found

	if (swarmmove == "B1")
	{
		if (XS2 == 'X')
		{
			XS2 = 'D'; goto fixlocation;
		}
		else cout << "Something is already in this location" << '\n'; goto move;
	}

	if (swarmmove == "C1")
	{
		if (XS3 == 'X')
		{
			XS3 = 'D'; goto fixlocation;
		}
		else cout << "Something is already in this location" << '\n'; goto move;
	}

	if (swarmmove == "D1")
	{
		if (XS4 == 'X')
		{
			XS4 = 'D'; goto fixlocation;
		}
		else cout << "Something is already in this location" << '\n'; goto move;
	}

	if (swarmmove == "E1")
	{
		if (XS5 == 'X')
		{
			XS5 = 'D'; goto fixlocation;
		}
		else cout << "Something is already in this location" << '\n'; goto move;
	}

	if (swarmmove == "A2")
	{
		if (XS6 == 'X')
		{
			XS6 = 'D'; goto fixlocation;
		}
		else cout << "Something is already in this location" << '\n'; goto move;
	}

	if (swarmmove == "B2")
	{
		if (XS7 == 'X')
		{
			XS7 = 'D'; goto fixlocation;
		}
		else cout << "Something is already in this location" << '\n'; goto move;
	}

	if (swarmmove == "C2")
	{
		if (XS8 == 'X')
		{
			XS8 = 'D'; goto fixlocation;
		}
		else cout << "Something is already in this location" << '\n'; goto move;
	}

	if (swarmmove == "D2")
	{
		if (XS9 == 'X')
		{
			XS9 = 'D'; goto fixlocation;
		}
		else cout << "Something is already in this location" << '\n'; goto move;
	}

	if (swarmmove == "E2")
	{
		if (XS10 == 'X')
		{
			XS10 = 'D'; goto fixlocation;
		}
		else cout << "Something is already in this location" << '\n'; goto move;
	}

	if (swarmmove == "A3")
	{
		if (XS11 == 'X')
		{
			XS11 = 'D'; goto fixlocation;
		}
		else cout << "Something is already in this location" << '\n'; goto move;
	}

	if (swarmmove == "B3")
	{
		if (XS12 == 'X')
		{
			XS12 = 'D'; goto fixlocation;
		}
		else cout << "Something is already in this location" << '\n'; goto move;
	}

	if (swarmmove == "C3")
	{
		if (XS13 == 'X')
		{
			XS13 = 'D'; goto fixlocation;
		}
		else cout << "Something is already in this location" << '\n'; goto move;
	}

	if (swarmmove == "D3")
	{
		if (XS14 == 'X')
		{
			XS14 = 'D'; goto fixlocation;
		}
		else cout << "Something is already in this location" << '\n'; goto move;
	}

	if (swarmmove == "E3")
	{
		if (XS15 == 'X')
		{
			XS15 = 'D'; goto fixlocation;
		}
		else cout << "Something is already in this location" << '\n'; goto move;
	}

	if (swarmmove == "A4")
	{
		if (XS16 == 'X')
		{
			XS16 = 'D'; goto fixlocation;
		}
		else cout << "Something is already in this location" << '\n'; goto move;
	}

	if (swarmmove == "B4")
	{
		if (XS17 == 'X')
		{
			XS17 = 'D'; goto fixlocation;
		}
		else cout << "Something is already in this location" << '\n'; goto move;
	}

	if (swarmmove == "C4")
	{
		if (XS18 == 'X')
		{
			XS18 = 'D'; goto fixlocation;
		}
		else cout << "Something is already in this location" << '\n'; goto move;
	}

	if (swarmmove == "D4")
	{
		if (XS19 == 'X')
		{
			XS19 = 'D'; goto fixlocation;
		}
		else cout << "Something is already in this location" << '\n'; goto move;
	}

	if (swarmmove == "E4")
	{
		if (XS20 == 'X')
		{
			XS20 = 'D'; goto fixlocation;
		}
		else cout << "Something is already in this location" << '\n'; goto move;
	}

	if (swarmmove == "A5")
	{
		if (XS21 == 'X')
		{
			XS21 = 'D'; goto fixlocation;
		}
		else cout << "Something is already in this location" << '\n'; goto move;
	}

	if (swarmmove == "B5")
	{
		if (XS22== 'X')
		{
			XS22 = 'D'; goto fixlocation;
		}
		else cout << "Something is already in this location" << '\n'; goto move;
	}

	if (swarmmove == "C5")
	{
		if (XS23 == 'X')
		{
			XS23 = 'D'; goto fixlocation;
		}
		else cout << "Something is already in this location" << '\n'; goto move;
	}

	if (swarmmove == "D5")
	{
		if (XS24 == 'X')
		{
			XS24 = 'D'; goto fixlocation;
		}
		else cout << "Something is already in this location" << '\n'; goto move;
	}

	if (swarmmove == "E5")
	{
		if (XS25 == 'X')
		{
			XS25 = 'D'; goto fixlocation;
		}
		else cout << "Something is already in this location" << '\n'; goto move;
	}

	cout << "Invalid Entry" << '\n'; goto move;//improper formatting, ask again
	//---------------------------------------------------------------------------------------------------------------------
	fixlocation:
	//location value is yet to be updated so I can use this to make prevuise location X 
	switch (location)
	{
	case 901:XS1 = 'X'; break;
	case 902:XS2 = 'X'; break;
	case 903:XS3 = 'X'; break;
	case 904:XS4 = 'X'; break;
	case 905:XS5 = 'X'; break;
	case 906:XS6 = 'X'; break;
	case 907:XS7 = 'X'; break;
	case 908:XS8 = 'X'; break;
	case 909:XS9 = 'X'; break;
	case 910:XS10= 'X'; break;
	case 911:XS11= 'X'; break;
	case 912:XS12= 'X'; break;
	case 913:XS13= 'X'; break;
	case 914:XS14= 'X'; break;
	case 915:XS15= 'X'; break;
	case 916:XS16= 'X'; break;
	case 917:XS17= 'X'; break;
	case 918:XS18= 'X'; break;
	case 919:XS19= 'X'; break;
	case 920:XS20= 'X'; break;
	case 921:XS21= 'X'; break;
	case 922:XS22= 'X'; break;
	case 923:XS23= 'X'; break;
	case 924:XS24= 'X'; break;
	case 925:XS25= 'X'; break;
	default: cout << "error fixlocation fail";
		break;
	}
	goto swarmmap2;
	//---------------------------------------------------------------------------------------------------------------------
	//attack


	//input coord, check if g is on coord, roll damage, aply damage
attack:
	cout << "Input where you would like to attack, example D3, or A1 (Case sensitive)." << '\n';
	getline(cin, swarmattack);
	validinput = 0;
	srand((unsigned)time(0));
	damage = (rand() % 20) + 5;

	if (swarmattack == "A1")//is it [cordinate]
	{
		if (XS1 == 'G')//is it an ememy
		{
			switch (enemycount)
			{
			case 1:g1h = g1h - damage; cout << "You dealt " << damage << "damage" << '\n'; goto gmove;
			case 2:g2h = g2h - damage; cout << "You dealt " << damage << "damage" << '\n'; goto gmove;
			case 3:g3h = g3h - damage; cout << "You dealt " << damage << "damage" << '\n'; goto gmove;
			case 4:g4h = g4h - damage; cout << "You dealt " << damage << "damage" << '\n'; goto gmove;
			case 5:g5h = g5h - damage; cout << "You dealt " << damage << "damage" << '\n'; goto gmove;
			case 6:g6h = g6h - damage; cout << "You dealt " << damage << "damage" << '\n'; goto gmove;
			}
		}
		else cout << "No ememy here." << '\n'; goto attack;//go back to reinput
	}//continue until input is found

	if (swarmattack == "B1")
	{
		if (XS2 == 'G')
		{
			switch(enemycount)
			{
			case 1:g1h = g1h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g1h < 1) { enemycount--; }goto gmove;
			case 2:g2h = g2h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g2h < 1) { enemycount--; } goto gmove;
			case 3:g3h = g3h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g3h < 1) { enemycount--; } goto gmove;
			case 4:g4h = g4h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g4h < 1) { enemycount--; } goto gmove;
			case 5:g5h = g5h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g5h < 1) { enemycount--; } goto gmove;
			case 6:g6h = g6h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g6h < 1) { enemycount--; } goto gmove;
			}
		}
		else cout << "No ememy here." << '\n'; goto attack;
	}

	if (swarmattack == "C1")
	{
		if (XS3 == 'G')
		{
			switch (enemycount)
			{
			case 1:g1h = g1h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g1h < 1) { enemycount--; }goto gmove;
			case 2:g2h = g2h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g2h < 1) { enemycount--; } goto gmove;
			case 3:g3h = g3h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g3h < 1) { enemycount--; } goto gmove;
			case 4:g4h = g4h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g4h < 1) { enemycount--; } goto gmove;
			case 5:g5h = g5h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g5h < 1) { enemycount--; } goto gmove;
			case 6:g6h = g6h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g6h < 1) { enemycount--; } goto gmove;
			}
		}
		else cout << "No ememy here." << '\n'; goto attack;
	}

	if (swarmattack == "D1")
	{
		if (XS4 == 'G')
		{
			switch (enemycount)
			{
			case 1:g1h = g1h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g1h < 1) { enemycount--; }goto gmove;
			case 2:g2h = g2h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g2h < 1) { enemycount--; } goto gmove;
			case 3:g3h = g3h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g3h < 1) { enemycount--; } goto gmove;
			case 4:g4h = g4h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g4h < 1) { enemycount--; } goto gmove;
			case 5:g5h = g5h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g5h < 1) { enemycount--; } goto gmove;
			case 6:g6h = g6h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g6h < 1) { enemycount--; } goto gmove;
			}
		}
		else cout << "No ememy here." << '\n'; goto attack;
	}

	if (swarmattack == "E1")
	{
		if (XS5 == 'G')
		{
			switch (enemycount)
			{
			case 1:g1h = g1h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g1h < 1) { enemycount--; }goto gmove;
			case 2:g2h = g2h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g2h < 1) { enemycount--; } goto gmove;
			case 3:g3h = g3h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g3h < 1) { enemycount--; } goto gmove;
			case 4:g4h = g4h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g4h < 1) { enemycount--; } goto gmove;
			case 5:g5h = g5h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g5h < 1) { enemycount--; } goto gmove;
			case 6:g6h = g6h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g6h < 1) { enemycount--; } goto gmove;
			}
		}
		else cout << "No ememy here." << '\n'; goto attack;
	}

	if (swarmattack == "A2")
	{
		if (XS6 == 'G')
		{
			switch (enemycount)
			{
			case 1:g1h = g1h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g1h < 1) { enemycount--; }goto gmove;
			case 2:g2h = g2h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g2h < 1) { enemycount--; } goto gmove;
			case 3:g3h = g3h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g3h < 1) { enemycount--; } goto gmove;
			case 4:g4h = g4h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g4h < 1) { enemycount--; } goto gmove;
			case 5:g5h = g5h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g5h < 1) { enemycount--; } goto gmove;
			case 6:g6h = g6h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g6h < 1) { enemycount--; } goto gmove;
			}
		}
		else cout << "No ememy here." << '\n'; goto attack;
	}

	if (swarmattack == "B2")
	{
		if (XS7 == 'G')
		{
			switch (enemycount)
			{
			case 1:g1h = g1h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g1h < 1) { enemycount--; }goto gmove;
			case 2:g2h = g2h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g2h < 1) { enemycount--; } goto gmove;
			case 3:g3h = g3h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g3h < 1) { enemycount--; } goto gmove;
			case 4:g4h = g4h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g4h < 1) { enemycount--; } goto gmove;
			case 5:g5h = g5h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g5h < 1) { enemycount--; } goto gmove;
			case 6:g6h = g6h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g6h < 1) { enemycount--; } goto gmove;
			}
		}
		else cout << "No ememy here." << '\n'; goto attack;
	}

	if (swarmattack == "C2")
	{
		if (XS8 == 'G')
		{
			switch (enemycount)
			{
			case 1:g1h = g1h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g1h < 1) { enemycount--; }goto gmove;
			case 2:g2h = g2h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g2h < 1) { enemycount--; } goto gmove;
			case 3:g3h = g3h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g3h < 1) { enemycount--; } goto gmove;
			case 4:g4h = g4h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g4h < 1) { enemycount--; } goto gmove;
			case 5:g5h = g5h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g5h < 1) { enemycount--; } goto gmove;
			case 6:g6h = g6h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g6h < 1) { enemycount--; } goto gmove;
			}
		}
		else cout << "No ememy here." << '\n'; goto attack;
	}

	if (swarmattack == "D2")
	{
		if (XS9 == 'G')
		{
			switch (enemycount)
			{
			case 1:g1h = g1h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g1h < 1) { enemycount--; }goto gmove;
			case 2:g2h = g2h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g2h < 1) { enemycount--; } goto gmove;
			case 3:g3h = g3h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g3h < 1) { enemycount--; } goto gmove;
			case 4:g4h = g4h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g4h < 1) { enemycount--; } goto gmove;
			case 5:g5h = g5h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g5h < 1) { enemycount--; } goto gmove;
			case 6:g6h = g6h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g6h < 1) { enemycount--; } goto gmove;
			}
		}
		else cout << "No ememy here." << '\n'; goto attack;
	}

	if (swarmattack == "E2")
	{
		if (XS10 == 'G')
		{
			switch (enemycount)
			{
			case 1:g1h = g1h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g1h < 1) { enemycount--; }goto gmove;
			case 2:g2h = g2h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g2h < 1) { enemycount--; } goto gmove;
			case 3:g3h = g3h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g3h < 1) { enemycount--; } goto gmove;
			case 4:g4h = g4h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g4h < 1) { enemycount--; } goto gmove;
			case 5:g5h = g5h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g5h < 1) { enemycount--; } goto gmove;
			case 6:g6h = g6h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g6h < 1) { enemycount--; } goto gmove;
			}
		}
		else cout << "No ememy here." << '\n'; goto attack;
	}

	if (swarmattack == "A3")
	{
		if (XS11 == 'G')
		{
			switch (enemycount)
			{
			case 1:g1h = g1h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g1h < 1) { enemycount--; }goto gmove;
			case 2:g2h = g2h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g2h < 1) { enemycount--; } goto gmove;
			case 3:g3h = g3h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g3h < 1) { enemycount--; } goto gmove;
			case 4:g4h = g4h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g4h < 1) { enemycount--; } goto gmove;
			case 5:g5h = g5h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g5h < 1) { enemycount--; } goto gmove;
			case 6:g6h = g6h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g6h < 1) { enemycount--; } goto gmove;
			}
		}
		else cout << "No ememy here." << '\n'; goto attack;
	}

	if (swarmattack == "B3")
	{
		if (XS12 == 'G')
		{
			switch (enemycount)
			{
			case 1:g1h = g1h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g1h < 1) { enemycount--; }goto gmove;
			case 2:g2h = g2h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g2h < 1) { enemycount--; } goto gmove;
			case 3:g3h = g3h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g3h < 1) { enemycount--; } goto gmove;
			case 4:g4h = g4h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g4h < 1) { enemycount--; } goto gmove;
			case 5:g5h = g5h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g5h < 1) { enemycount--; } goto gmove;
			case 6:g6h = g6h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g6h < 1) { enemycount--; } goto gmove;
			}
		}
		else cout << "No ememy here." << '\n'; goto attack;
	}

	if (swarmattack == "C3")
	{
		if (XS13 == 'G')
		{
			switch (enemycount)
			{
			case 1:g1h = g1h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g1h < 1) { enemycount--; }goto gmove;
			case 2:g2h = g2h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g2h < 1) { enemycount--; } goto gmove;
			case 3:g3h = g3h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g3h < 1) { enemycount--; } goto gmove;
			case 4:g4h = g4h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g4h < 1) { enemycount--; } goto gmove;
			case 5:g5h = g5h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g5h < 1) { enemycount--; } goto gmove;
			case 6:g6h = g6h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g6h < 1) { enemycount--; } goto gmove;
			}
		}
		else cout << "No ememy here." << '\n'; goto attack;
	}

	if (swarmattack == "D3")
	{
		if (XS14 == 'G')
		{
			switch (enemycount)
			{
			case 1:g1h = g1h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g1h < 1) { enemycount--; }goto gmove;
			case 2:g2h = g2h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g2h < 1) { enemycount--; } goto gmove;
			case 3:g3h = g3h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g3h < 1) { enemycount--; } goto gmove;
			case 4:g4h = g4h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g4h < 1) { enemycount--; } goto gmove;
			case 5:g5h = g5h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g5h < 1) { enemycount--; } goto gmove;
			case 6:g6h = g6h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g6h < 1) { enemycount--; } goto gmove;
			}
		}
		else cout << "No ememy here." << '\n'; goto attack;
	}

	if (swarmattack == "E3")
	{
		if (XS15 == 'G')
		{
			switch (enemycount)
			{
			case 1:g1h = g1h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g1h < 1) { enemycount--; }goto gmove;
			case 2:g2h = g2h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g2h < 1) { enemycount--; } goto gmove;
			case 3:g3h = g3h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g3h < 1) { enemycount--; } goto gmove;
			case 4:g4h = g4h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g4h < 1) { enemycount--; } goto gmove;
			case 5:g5h = g5h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g5h < 1) { enemycount--; } goto gmove;
			case 6:g6h = g6h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g6h < 1) { enemycount--; } goto gmove;
			}
		}
		else cout << "No ememy here." << '\n'; goto attack;
	}

	if (swarmattack == "A4")
	{
		if (XS16 == 'G')
		{
			switch (enemycount)
			{
			case 1:g1h = g1h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g1h < 1) { enemycount--; }goto gmove;
			case 2:g2h = g2h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g2h < 1) { enemycount--; } goto gmove;
			case 3:g3h = g3h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g3h < 1) { enemycount--; } goto gmove;
			case 4:g4h = g4h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g4h < 1) { enemycount--; } goto gmove;
			case 5:g5h = g5h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g5h < 1) { enemycount--; } goto gmove;
			case 6:g6h = g6h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g6h < 1) { enemycount--; } goto gmove;
			}
		}
		else cout << "No ememy here." << '\n'; goto attack;
	}

	if (swarmattack == "B4")
	{
		if (XS17 == 'G')
		{
			switch (enemycount)
			{
			case 1:g1h = g1h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g1h < 1) { enemycount--; }goto gmove;
			case 2:g2h = g2h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g2h < 1) { enemycount--; } goto gmove;
			case 3:g3h = g3h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g3h < 1) { enemycount--; } goto gmove;
			case 4:g4h = g4h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g4h < 1) { enemycount--; } goto gmove;
			case 5:g5h = g5h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g5h < 1) { enemycount--; } goto gmove;
			case 6:g6h = g6h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g6h < 1) { enemycount--; } goto gmove;
			}
		}
		else cout << "No ememy here." << '\n'; goto attack;
	}

	if (swarmattack == "C4")
	{
		if (XS18 == 'G')
		{
			switch (enemycount)
			{
			case 1:g1h = g1h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g1h < 1) { enemycount--; }goto gmove;
			case 2:g2h = g2h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g2h < 1) { enemycount--; } goto gmove;
			case 3:g3h = g3h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g3h < 1) { enemycount--; } goto gmove;
			case 4:g4h = g4h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g4h < 1) { enemycount--; } goto gmove;
			case 5:g5h = g5h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g5h < 1) { enemycount--; } goto gmove;
			case 6:g6h = g6h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g6h < 1) { enemycount--; } goto gmove;
			}
		}
		else cout << "No ememy here." << '\n'; goto attack;
	}

	if (swarmattack == "D4")
	{
		if (XS19 == 'G')
		{
			switch (enemycount)
			{
			case 1:g1h = g1h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g1h < 1) { enemycount--; }goto gmove;
			case 2:g2h = g2h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g2h < 1) { enemycount--; } goto gmove;
			case 3:g3h = g3h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g3h < 1) { enemycount--; } goto gmove;
			case 4:g4h = g4h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g4h < 1) { enemycount--; } goto gmove;
			case 5:g5h = g5h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g5h < 1) { enemycount--; } goto gmove;
			case 6:g6h = g6h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g6h < 1) { enemycount--; } goto gmove;
			}
		}
		else cout << "No ememy here." << '\n'; goto attack;
	}

	if (swarmattack == "E4")
	{
		if (XS20 == 'G')
		{
			switch (enemycount)
			{
			case 1:g1h = g1h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g1h < 1) { enemycount--; }goto gmove;
			case 2:g2h = g2h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g2h < 1) { enemycount--; } goto gmove;
			case 3:g3h = g3h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g3h < 1) { enemycount--; } goto gmove;
			case 4:g4h = g4h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g4h < 1) { enemycount--; } goto gmove;
			case 5:g5h = g5h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g5h < 1) { enemycount--; } goto gmove;
			case 6:g6h = g6h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g6h < 1) { enemycount--; } goto gmove;
			}
		}
		else cout << "No ememy here." << '\n'; goto attack;
	}

	if (swarmattack == "A5")
	{
		if (XS21 == 'G')
		{
			switch (enemycount)
			{
			case 1:g1h = g1h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g1h < 1) { enemycount--; }goto gmove;
			case 2:g2h = g2h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g2h < 1) { enemycount--; } goto gmove;
			case 3:g3h = g3h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g3h < 1) { enemycount--; } goto gmove;
			case 4:g4h = g4h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g4h < 1) { enemycount--; } goto gmove;
			case 5:g5h = g5h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g5h < 1) { enemycount--; } goto gmove;
			case 6:g6h = g6h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g6h < 1) { enemycount--; } goto gmove;
			}
		}
		else cout << "No ememy here." << '\n'; goto attack;
	}

	if (swarmattack == "B5")
	{
		if (XS22 == 'G')
		{
			switch (enemycount)
			{
			case 1:g1h = g1h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g1h < 1) { enemycount--; }goto gmove;
			case 2:g2h = g2h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g2h < 1) { enemycount--; } goto gmove;
			case 3:g3h = g3h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g3h < 1) { enemycount--; } goto gmove;
			case 4:g4h = g4h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g4h < 1) { enemycount--; } goto gmove;
			case 5:g5h = g5h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g5h < 1) { enemycount--; } goto gmove;
			case 6:g6h = g6h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g6h < 1) { enemycount--; } goto gmove;
			}
		}
		else cout << "No ememy here." << '\n'; goto attack;
	}

	if (swarmattack == "C5")
	{
		if (XS23 == 'G')
		{
			switch (enemycount)
			{
			case 1:g1h = g1h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g1h < 1) { enemycount--; }goto gmove;
			case 2:g2h = g2h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g2h < 1) { enemycount--; } goto gmove;
			case 3:g3h = g3h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g3h < 1) { enemycount--; } goto gmove;
			case 4:g4h = g4h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g4h < 1) { enemycount--; } goto gmove;
			case 5:g5h = g5h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g5h < 1) { enemycount--; } goto gmove;
			case 6:g6h = g6h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g6h < 1) { enemycount--; } goto gmove;
			}
		}
		else cout << "No ememy here." << '\n'; goto attack;
	}

	if (swarmattack == "D5")
	{
		if (XS24 == 'G')
		{
			switch (enemycount)
			{
			case 1:g1h = g1h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g1h < 1) { enemycount--; }goto gmove;
			case 2:g2h = g2h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g2h < 1) { enemycount--; } goto gmove;
			case 3:g3h = g3h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g3h < 1) { enemycount--; } goto gmove;
			case 4:g4h = g4h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g4h < 1) { enemycount--; } goto gmove;
			case 5:g5h = g5h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g5h < 1) { enemycount--; } goto gmove;
			case 6:g6h = g6h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g6h < 1) { enemycount--; } goto gmove;
			}
		}
		else cout << "No ememy here." << '\n'; goto attack;
	}

	if (swarmattack == "E5")
	{
		if (XS25 == 'G')
		{
			switch (enemycount)
			{
			case 1:g1h = g1h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g1h < 1) {enemycount--;}goto gmove;
			case 2:g2h = g2h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g2h < 1) {enemycount--;} goto gmove;
			case 3:g3h = g3h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g3h < 1) {enemycount--;} goto gmove;
			case 4:g4h = g4h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g4h < 1) {enemycount--;} goto gmove;
			case 5:g5h = g5h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g5h < 1) {enemycount--;} goto gmove;
			case 6:g6h = g6h - damage; cout << "You dealt " << damage << "damage" << '\n'; if (g6h < 1) {enemycount--;} goto gmove;
			}
		}
		else cout << "No ememy here." << '\n'; goto attack;
	}


gmove:
	
	//once again this is horribble code
	//I thought on it and thi i the best way I can do it with my current knowegde and time
	switch (location)
	{
	case 901: switch (enemycount)
				{
				case 1: XS2 = 'G', XS3 = 'X', XS4 = 'X', XS5 = 'X', XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X', XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X', XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';//clear map apart from player and put G in new location
					break;
				case 2: XS2 = 'G', XS3 = 'X', XS4 = 'X', XS5 = 'X', XS6 = 'G', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X', XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X', XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 3: XS2 = 'G', XS3 = 'X', XS4 = 'X', XS5 = 'X', XS6 = 'G', XS7 = 'G', XS8 = 'X', XS9 = 'X', XS10 = 'X', XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X', XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 4: XS2 = 'G', XS3 = 'G', XS4 = 'X', XS5 = 'X', XS6 = 'G', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X', XS11 = 'G', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X', XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 5: XS2 = 'G', XS3 = 'G', XS4 = 'X', XS5 = 'X', XS6 = 'G', XS7 = 'G', XS8 = 'X', XS9 = 'X', XS10 = 'X', XS11 = 'G', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X', XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 6: XS2 = 'G', XS3 = 'G', XS4 = 'X', XS5 = 'X', XS6 = 'G', XS7 = 'G', XS8 = 'X', XS9 = 'X', XS10 = 'X', XS11 = 'G', XS12 = 'G', XS13 = 'X', XS14 = 'X', XS15 = 'X', XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				}
	case 902: switch (enemycount)
				{
				case 1: XS1 = 'X', XS3 = 'G', XS4 = 'X', XS5 = 'X', XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X', XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X', XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 2: XS1 = 'G', XS3 = 'G', XS4 = 'X', XS5 = 'X', XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X', XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X', XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 3: XS1 = 'G', XS3 = 'G', XS4 = 'X', XS5 = 'X', XS6 = 'X', XS7 = 'G', XS8 = 'X', XS9 = 'X', XS10 = 'X', XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X', XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 4: XS1 = 'G', XS3 = 'G', XS4 = 'X', XS5 = 'X', XS6 = 'G', XS7 = 'G', XS8 = 'X', XS9 = 'X', XS10 = 'X', XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X', XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 5: XS1 = 'G', XS3 = 'G', XS4 = 'X', XS5 = 'X', XS6 = 'G', XS7 = 'G', XS8 = 'G', XS9 = 'X', XS10 = 'X', XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X', XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 6: XS1 = 'G', XS3 = 'G', XS4 = 'G', XS5 = 'X', XS6 = 'G', XS7 = 'G', XS8 = 'G', XS9 = 'X', XS10 = 'X', XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X', XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				}
	case 903:switch (enemycount)
				{
				case 1: XS2 = 'X', XS4 = 'G', XS1 = 'X', XS5 = 'X', XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X', XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X', XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 2: XS2 = 'G', XS4 = 'G', XS1 = 'X', XS5 = 'X', XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X', XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X', XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 3: XS2 = 'G', XS4 = 'G', XS1 = 'X', XS5 = 'X', XS6 = 'X', XS7 = 'X', XS8 = 'G', XS9 = 'X', XS10 = 'X', XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X', XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 4: XS2 = 'G', XS4 = 'G', XS1 = 'X', XS5 = 'X', XS6 = 'X', XS7 = 'G', XS8 = 'G', XS9 = 'X', XS10 = 'X', XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X', XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 5: XS2 = 'G', XS4 = 'G', XS1 = 'X', XS5 = 'X', XS6 = 'X', XS7 = 'G', XS8 = 'G', XS9 = 'G', XS10 = 'X', XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X', XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 6: XS2 = 'G', XS4 = 'G', XS1 = 'G', XS5 = 'X', XS6 = 'X', XS7 = 'G', XS8 = 'G', XS9 = 'G', XS10 = 'X', XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X', XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				}
	case 904: switch (enemycount)
				{
				case 1: XS1 = 'X', XS2 = 'X', XS3 = 'G', XS5 = 'X', XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X', XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X', XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 2: XS1 = 'X', XS2 = 'X', XS3 = 'G', XS5 = 'G', XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X', XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X', XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 3: XS1 = 'X', XS2 = 'X', XS3 = 'G', XS5 = 'G', XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'G', XS10 = 'X', XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X', XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 4: XS1 = 'X', XS2 = 'X', XS3 = 'G', XS5 = 'G', XS6 = 'X', XS7 = 'X', XS8 = 'G', XS9 = 'G', XS10 = 'X', XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X', XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 5: XS1 = 'X', XS2 = 'X', XS3 = 'G', XS5 = 'G', XS6 = 'X', XS7 = 'X', XS8 = 'G', XS9 = 'G', XS10 = 'G', XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X', XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 6: XS1 = 'X', XS2 = 'G', XS3 = 'G', XS5 = 'G', XS6 = 'X', XS7 = 'X', XS8 = 'G', XS9 = 'G', XS10 = 'G', XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X', XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				}
	case 905:switch (enemycount)
				{
				case 1: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'G', XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X', XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X', XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 2: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'G', XS6 = 'G', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X', XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X', XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 3: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'G', XS6 = 'G', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'G', XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X', XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 4: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'G', XS6 = 'G', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'G', XS11 = 'G', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X', XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 5: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'G', XS6 = 'G', XS7 = 'X', XS8 = 'X', XS9 = 'G', XS10 = 'G', XS11 = 'G', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X', XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 6: XS1 = 'X', XS2 = 'X', XS3 = 'G', XS4 = 'G', XS6 = 'G', XS7 = 'X', XS8 = 'X', XS9 = 'G', XS10 = 'G', XS11 = 'G', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X', XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				}
	case 906:switch (enemycount)//fix
				{
				case 1: XS1 = 'G', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X', 
									XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X', 
						XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X',
						XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', 
						XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 2: XS1 = 'G', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X', 
								   XS7 = 'G', XS8 = 'X', XS9 = 'X', XS10 = 'X', 
						XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X', 
						XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', 
						XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 3: XS1 = 'G', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X', 
									XS7 = 'G', XS8 = 'X', XS9 = 'X', XS10 = 'X', 
						XS11 = 'G', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X', 
						XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', 
						XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 4: XS1 = 'G', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X', 
									XS7 = 'G', XS8 = 'X', XS9 = 'X', XS10 = 'X',
						XS11 = 'G', XS12 = 'G', XS13 = 'X', XS14 = 'X', XS15 = 'X', 
						XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', 
						XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 5: XS1 = 'G', XS2 = 'G', XS3 = 'X', XS4 = 'X', XS5 = 'X', 
									XS7 = 'G', XS8 = 'X', XS9 = 'X', XS10 = 'X', 
						XS11 = 'G', XS12 = 'G', XS13 = 'X', XS14 = 'X', XS15 = 'X', 
						XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', 
						XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 6: XS1 = 'G', XS2 = 'G', XS3 = 'G', XS4 = 'X', XS5 = 'X', 
									XS7 = 'G', XS8 = 'X', XS9 = 'X', XS10 = 'X', 
						XS11 = 'G', XS12 = 'G', XS13 = 'X', XS14 = 'X', XS15 = 'X', 
						XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', 
						XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				}
	case 907: switch (enemycount)
				{
				case 1: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X', 
						XS6 = 'X',			  XS8 = 'X', XS9 = 'X', XS10 = 'X', 
						XS11 = 'X', XS12 = 'G', XS13 = 'X', XS14 = 'X', XS15 = 'X', 
						XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', 
						XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 2: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X', 
						XS6 = 'G',			  XS8 = 'X', XS9 = 'X', XS10 = 'X', 
						XS11 = 'X', XS12 = 'G', XS13 = 'X', XS14 = 'X', XS15 = 'X',
						XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', 
						XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 3: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
						XS6 = 'G',			  XS8 = 'X', XS9 = 'X', XS10 = 'X', 
						XS11 = 'G', XS12 = 'G', XS13 = 'X', XS14 = 'X', XS15 = 'X', 
						XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', 
						XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 4: XS1 = 'X', XS2 = 'G', XS3 = 'X', XS4 = 'X', XS5 = 'X', 
						XS6 = 'G',			  XS8 = 'X', XS9 = 'X', XS10 = 'X',
						XS11 = 'G', XS12 = 'G', XS13 = 'X', XS14 = 'X', XS15 = 'X', 
						XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', 
						XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 5: XS1 = 'X', XS2 = 'G', XS3 = 'X', XS4 = 'X', XS5 = 'X',
						XS6 = 'G',			 XS8 = 'G', XS9 = 'X', XS10 = 'X',
						XS11 = 'G', XS12 = 'G', XS13 = 'X', XS14 = 'X', XS15 = 'X', 
						XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', 
						XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 6: XS1 = 'X', XS2 = 'G', XS3 = 'G', XS4 = 'X', XS5 = 'X', 
						XS6 = 'G',				XS8 = 'G', XS9 = 'X', XS10 = 'X', 
						XS11 = 'G', XS12 = 'G', XS13 = 'X', XS14 = 'X', XS15 = 'X', 
						XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X', 
						XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
				}
	case 908: switch (enemycount)
				{
				case 1: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
						XS6 = 'X',	XS7 = 'X',			 XS9 = 'X', XS10 = 'X',
						XS11 = 'X', XS12 = 'X', XS13 = 'G', XS14 = 'X', XS15 = 'X',
						XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
						XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 2: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
						XS6 = 'G', XS7 = 'G',			XS9 = 'X', XS10 = 'X',
						XS11 = 'X', XS12 = 'X', XS13 = 'G', XS14 = 'X', XS15 = 'X',
						XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
						XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 3: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
						XS6 = 'X', XS7 = 'G',			XS9 = 'G', XS10 = 'X',
						XS11 = 'X', XS12 = 'X', XS13 = 'G', XS14 = 'X', XS15 = 'X',
						XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
						XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 4: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
						XS6 = 'X', XS7 = 'G',			XS9 = 'G', XS10 = 'X',
						XS11 = 'X', XS12 = 'G', XS13 = 'G', XS14 = 'X', XS15 = 'X',
						XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
						XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 5: XS1 = 'X', XS2 = 'X', XS3 = 'G', XS4 = 'X', XS5 = 'X',
						XS6 = 'X', XS7 = 'G',			XS9 = 'G', XS10 = 'X',
						XS11 = 'X', XS12 = 'G', XS13 = 'G', XS14 = 'X', XS15 = 'X',
						XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
						XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				case 6: XS1 = 'X', XS2 = 'G', XS3 = 'G', XS4 = 'X', XS5 = 'X',
					XS6 = 'X', XS7 = 'G', XS9 = 'G', XS10 = 'X',
					XS11 = 'X', XS12 = 'G', XS13 = 'G', XS14 = 'X', XS15 = 'X',
					XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
					XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
					break;
				}
	case 909: switch (enemycount)//unformated, I aint spending the next hour tabbing this so its uniform
	{
	case 1: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'G', XS15 = 'X',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 2: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'G', XS10 = 'X',
		XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'G', XS15 = 'X',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 3: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'G', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'G', XS10 = 'X',
		XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'G', XS15 = 'X',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 4: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'G', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'G', XS10 = 'G',
		XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'G', XS15 = 'X',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 5: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'G', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'G', XS10 = 'G',
		XS11 = 'X', XS12 = 'X', XS13 = 'G', XS14 = 'G', XS15 = 'X',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 6: XS1 = 'X', XS2 = 'X', XS3 = 'G', XS4 = 'G', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'G', XS10 = 'G',
		XS11 = 'X', XS12 = 'X', XS13 = 'G', XS14 = 'G', XS15 = 'X',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	}
	case 910: switch (enemycount)
	{
	case 1: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'G',
		XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 2: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'G',
		XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'G',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 3: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'G',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'G',
		XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'G',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 4: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'G',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'G',
		XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'G', XS15 = 'G',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 5: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'G', XS5 = 'G',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'G',
		XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'G', XS15 = 'G',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 6: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'G', XS5 = 'G',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'G',
		XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'G', XS15 = 'G',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'G',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	}
	case 911: switch (enemycount)
	{
	case 1: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS12 = 'G', XS13 = 'X', XS14 = 'X', XS15 = 'X',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 2: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'G', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS12 = 'G', XS13 = 'X', XS14 = 'X', XS15 = 'X',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 3: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'G', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS12 = 'G', XS13 = 'X', XS14 = 'X', XS15 = 'X',
		XS16 = 'G', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 4: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'G', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS12 = 'G', XS13 = 'X', XS14 = 'X', XS15 = 'X',
		XS16 = 'G', XS17 = 'G', XS18 = 'X', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 5: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'G', XS7 = 'G', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS12 = 'G', XS13 = 'X', XS14 = 'X', XS15 = 'X',
		XS16 = 'G', XS17 = 'G', XS18 = 'X', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 6: XS1 = 'G', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'G', XS7 = 'G', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS12 = 'G', XS13 = 'X', XS14 = 'X', XS15 = 'X',
		XS16 = 'G', XS17 = 'G', XS18 = 'X', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	}
	case 912: switch (enemycount)
	{
	case 1: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS13 = 'G', XS14 = 'X', XS15 = 'X',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 2: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'G', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS13 = 'G', XS14 = 'X', XS15 = 'X',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 3: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'G', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS13 = 'G', XS14 = 'X', XS15 = 'X',
		XS16 = 'X', XS17 = 'G', XS18 = 'X', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 4: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'G', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'G', XS13 = 'G', XS14 = 'X', XS15 = 'X',
		XS16 = 'X', XS17 = 'G', XS18 = 'X', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 5: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'G', XS8 = 'G', XS9 = 'X', XS10 = 'X',
		XS11 = 'G', XS13 = 'G', XS14 = 'X', XS15 = 'X',
		XS16 = 'X', XS17 = 'G', XS18 = 'X', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 6: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'G', XS8 = 'G', XS9 = 'X', XS10 = 'X',
		XS11 = 'G', XS13 = 'G', XS14 = 'X', XS15 = 'X',
		XS16 = 'G', XS17 = 'G', XS18 = 'X', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	}
	case 913: switch (enemycount)
	{
	case 1: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'G', XS14 = 'X', XS15 = 'X',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 2: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'G', XS14 = 'X', XS15 = 'X',
		XS16 = 'X', XS17 = 'X', XS18 = 'G', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 3: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'G', XS14 = 'G', XS15 = 'X',
		XS16 = 'X', XS17 = 'X', XS18 = 'G', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 4: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'G', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'G', XS14 = 'G', XS15 = 'X',
		XS16 = 'X', XS17 = 'X', XS18 = 'G', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 5: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'G', XS9 = 'G', XS10 = 'X',
		XS11 = 'X', XS12 = 'G', XS14 = 'G', XS15 = 'X',
		XS16 = 'X', XS17 = 'X', XS18 = 'G', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 6: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'G', XS9 = 'G', XS10 = 'X',
		XS11 = 'X', XS12 = 'G', XS14 = 'G', XS15 = 'X',
		XS16 = 'X', XS17 = 'G', XS18 = 'G', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	}
	case 914: switch (enemycount)
	{
	case 1: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'X', XS13 = 'X', XS15 = 'X',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'G', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 2: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'X', XS13 = 'G', XS15 = 'X',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'G', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 3: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'G', XS10 = 'X',
		XS11 = 'X', XS12 = 'X', XS13 = 'G', XS15 = 'X',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'G', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 4: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'G', XS10 = 'X',
		XS11 = 'X', XS12 = 'X', XS13 = 'G', XS15 = 'G',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'G', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 5: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'G', XS9 = 'G', XS10 = 'X',
		XS11 = 'X', XS12 = 'X', XS13 = 'G', XS15 = 'G',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'G', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 6: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'G', XS9 = 'G', XS10 = 'X',
		XS11 = 'X', XS12 = 'X', XS13 = 'G', XS15 = 'G',
		XS16 = 'X', XS17 = 'X', XS18 = 'G', XS19 = 'G', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	}
	case 915: switch (enemycount)
	{
	case 1: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'G',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 2: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'G',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'G',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 3: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'G',
		XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'G',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'G',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 4: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'G',
		XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'G',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'G', XS20 = 'G',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 5: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'G', XS10 = 'G',
		XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'G',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'G', XS20 = 'G',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 6: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'G',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'G', XS10 = 'G',
		XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'G',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'G', XS20 = 'G',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	}
	case 916: switch (enemycount)
	{
	case 1: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X',
		XS17 = 'G', XS18 = 'X', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 2: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'G', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X',
		XS17 = 'G', XS18 = 'X', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 3: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'G', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X',
		XS17 = 'G', XS18 = 'X', XS19 = 'X', XS20 = 'X',
		XS21 = 'G', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 4: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'G', XS12 = 'G', XS13 = 'X', XS14 = 'X', XS15 = 'X',
		XS17 = 'G', XS18 = 'X', XS19 = 'X', XS20 = 'X',
		XS21 = 'G', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 5: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'G', XS12 = 'G', XS13 = 'X', XS14 = 'X', XS15 = 'X',
		XS17 = 'G', XS18 = 'X', XS19 = 'X', XS20 = 'X',
		XS21 = 'G', XS22 = 'G', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 6: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'G', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'G', XS12 = 'G', XS13 = 'X', XS14 = 'X', XS15 = 'X',
		XS17 = 'G', XS18 = 'X', XS19 = 'X', XS20 = 'X',
		XS21 = 'G', XS22 = 'G', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	}
	case 917: switch (enemycount)
	{
	case 1: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'G', XS13 = 'X', XS14 = 'X', XS15 = 'X',
		XS16 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 2: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'G', XS13 = 'X', XS14 = 'X', XS15 = 'X',
		XS16 = 'X', XS18 = 'G', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 3: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'G', XS13 = 'X', XS14 = 'X', XS15 = 'X',
		XS16 = 'G', XS18 = 'G', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 4: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'G', XS13 = 'X', XS14 = 'X', XS15 = 'X',
		XS16 = 'G', XS18 = 'G', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'G', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 5: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'G', XS13 = 'G', XS14 = 'X', XS15 = 'X',
		XS16 = 'G', XS18 = 'G', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'G', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 6: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'G', XS13 = 'G', XS14 = 'X', XS15 = 'X',
		XS16 = 'G', XS18 = 'G', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'G', XS23 = 'G', XS24 = 'X', XS25 = 'X';
		break;
	}
	case 918: switch (enemycount)
	{
	case 1: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'X', XS13 = 'G', XS14 = 'X', XS15 = 'X',
		XS16 = 'X', XS17 = 'X', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 2: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'X', XS13 = 'G', XS14 = 'X', XS15 = 'X',
		XS16 = 'X', XS17 = 'G', XS19 = 'X', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 3: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'X', XS13 = 'G', XS14 = 'X', XS15 = 'X',
		XS16 = 'X', XS17 = 'G', XS19 = 'G', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 4: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'X', XS13 = 'G', XS14 = 'X', XS15 = 'X',
		XS16 = 'X', XS17 = 'G', XS19 = 'G', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'G', XS24 = 'X', XS25 = 'X';
		break;
	case 5: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'X', XS13 = 'G', XS14 = 'X', XS15 = 'X',
		XS16 = 'X', XS17 = 'G', XS19 = 'G', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'G', XS24 = 'G', XS25 = 'X';
		break;
	case 6: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'G', XS13 = 'G', XS14 = 'X', XS15 = 'X',
		XS16 = 'X', XS17 = 'G', XS19 = 'G', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'G', XS24 = 'G', XS25 = 'X';
		break;
	}
	case 919: switch (enemycount)
	{
	case 1: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X',
		XS16 = 'X', XS17 = 'X', XS18 = 'G', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 2: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'G', XS15 = 'X',
		XS16 = 'X', XS17 = 'X', XS18 = 'G', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 3: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'G', XS15 = 'X',
		XS16 = 'X', XS17 = 'X', XS18 = 'G', XS20 = 'X',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'G', XS25 = 'X';
		break;
	case 4: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'G', XS15 = 'X',
		XS16 = 'X', XS17 = 'X', XS18 = 'G', XS20 = 'G',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'G', XS25 = 'X';
		break;
	case 5: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'X', XS13 = 'G', XS14 = 'G', XS15 = 'X',
		XS16 = 'X', XS17 = 'X', XS18 = 'G', XS20 = 'G',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'G', XS25 = 'X';
		break;
	case 6: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'X', XS13 = 'G', XS14 = 'G', XS15 = 'G',
		XS16 = 'X', XS17 = 'X', XS18 = 'G', XS20 = 'G',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'G', XS25 = 'X';
		break;
	}
	case 920: switch (enemycount)
	{
	case 1: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'G',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 2: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'G',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'G',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'X';
		break;
	case 3: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'G',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'G',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'G';
		break;
	case 4: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'G', XS15 = 'G',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'G',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'X', XS25 = 'G';
		break;
	case 5: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
		XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'G', XS15 = 'G',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'G',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'G', XS25 = 'G';
		break;
	case 6: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
		XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'G',
		XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'G', XS15 = 'G',
		XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'G',
		XS21 = 'X', XS22 = 'X', XS23 = 'X', XS24 = 'G', XS25 = 'G';
		break;
	}

			//8-20 here




	case 921: switch (enemycount)
				{
				case 1: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
						XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
						XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X',
						XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
						XS22 = 'G', XS23 = 'X', XS24 = 'X', XS25 = 'X'; // pos 21 1g
					break;

				case 2: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
						XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
						XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X',
						XS16 = 'G', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
						XS22 = 'G', XS23 = 'X', XS24 = 'X', XS25 = 'X'; // pos 21 2g
					break;
				case 3: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
						XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
						XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X',
						XS16 = 'G', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
						XS22 = 'G', XS23 = 'G', XS24 = 'X', XS25 = 'X'; // pos 21 3g
					break;
				case 4: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
						XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
						XS11 = 'G', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X',
						XS16 = 'G', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
						XS22 = 'G', XS23 = 'G', XS24 = 'X', XS25 = 'X'; // pos 21 4g
					break;
				case 5: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
						XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
						XS11 = 'G', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X',
						XS16 = 'G', XS17 = 'G', XS18 = 'X', XS19 = 'X', XS20 = 'X',
						XS22 = 'G', XS23 = 'G', XS24 = 'X', XS25 = 'X'; // pos 21 5g
					break;
				case 6: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
						XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
						XS11 = 'G', XS12 = 'G', XS13 = 'X', XS14 = 'X', XS15 = 'X',
						XS16 = 'G', XS17 = 'G', XS18 = 'X', XS19 = 'X', XS20 = 'X',
						XS22 = 'G', XS23 = 'G', XS24 = 'X', XS25 = 'X'; // pos 21 6g
					break;
				}

	case 922:switch (enemycount)
				{
				case 1: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
						XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
						XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X',
						XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
						XS21 = 'G',				XS23 = 'X', XS24 = 'X', XS25 = 'X'; // pos 22 1g
					break;
				case 2: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
						XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
						XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X',
						XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
						XS21 = 'G',				XS23 = 'G', XS24 = 'X', XS25 = 'X'; // pos 22 2g
					break;
				case 3: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
						XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
						XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X',
						XS16 = 'X', XS17 = 'G', XS18 = 'X', XS19 = 'X', XS20 = 'X',
						XS21 = 'G',				XS23 = 'G', XS24 = 'X', XS25 = 'X'; // pos 22 3g
					break;
				case 4: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
						XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
						XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X',
						XS16 = 'G', XS17 = 'G', XS18 = 'X', XS19 = 'X', XS20 = 'X',
						XS21 = 'G',				XS23 = 'G', XS24 = 'X', XS25 = 'X'; // pos 22 4g
					break;
				case 5:	XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
						XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
						XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X',
						XS16 = 'G', XS17 = 'G', XS18 = 'G', XS19 = 'X', XS20 = 'X',
						XS21 = 'G',				XS23 = 'G', XS24 = 'X', XS25 = 'X'; // pos 22 5g
					break;
				case 6: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
						XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
						XS11 = 'X', XS12 = 'G', XS13 = 'X', XS14 = 'X', XS15 = 'X',
						XS16 = 'G', XS17 = 'G', XS18 = 'G', XS19 = 'X', XS20 = 'X',
						XS21 = 'G',				XS23 = 'G', XS24 = 'X', XS25 = 'X'; // pos 22 6g
					break;
				}
	case 923: switch (enemycount)
			{
				case 1: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
						XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
						XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X',
						XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
						XS21 = 'X', XS22 = 'X',				XS24 = 'G', XS25 = 'X'; // pos 23 1g
					break;
				case 2: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
						XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
						XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X',
						XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
						XS21 = 'X', XS22 = 'G',				XS24 = 'G', XS25 = 'X'; // pos 23 2g
					break;
				case 3: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
						XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
						XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X',
						XS16 = 'X', XS17 = 'X', XS18 = 'G', XS19 = 'X', XS20 = 'X',
						XS21 = 'X', XS22 = 'G',				XS24 = 'G', XS25 = 'X'; // pos 23 3g
					break;
				case 4: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
						XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
						XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X',
						XS16 = 'X', XS17 = 'G', XS18 = 'G', XS19 = 'X', XS20 = 'X',
						XS21 = 'X', XS22 = 'G',				XS24 = 'G', XS25 = 'X'; // pos 23 4g
					break;
				case 5: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
						XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
						XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X',
						XS16 = 'X', XS17 = 'G', XS18 = 'G', XS19 = 'G', XS20 = 'X',
						XS21 = 'X', XS22 = 'G',				XS24 = 'G', XS25 = 'X'; // pos 23 5g
					break;
				case 6: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
						XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
						XS11 = 'X', XS12 = 'X', XS13 = 'G', XS14 = 'X', XS15 = 'X',
						XS16 = 'X', XS17 = 'G', XS18 = 'G', XS19 = 'G', XS20 = 'X',
						XS21 = 'X', XS22 = 'G',				 XS24 = 'G', XS25 = 'X'; // pos 23 6g
					break;
				}
	case 224: switch (enemycount)
			{
			case 1: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
					XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
					XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X',
					XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
					XS21 = 'X', XS22 = 'X', XS23 = 'X',				XS25 = 'G'; // pos 24 1g
				break;
			case 2: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
					XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
					XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X',
					XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
					XS21 = 'X', XS22 = 'X', XS23 = 'G',				XS25 = 'G'; // pos 24 2g
				break;
			case 3: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
					XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
					XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X',
					XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'G', XS20 = 'X',
					XS21 = 'X', XS22 = 'X', XS23 = 'G',				XS25 = 'G'; // pos 24 3g
				break;
			case 4: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
					XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
					XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X',
					XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'G', XS20 = 'G',
					XS21 = 'X', XS22 = 'X', XS23 = 'G',				XS25 = 'G'; // pos 24 4g
				break;
			case 5: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
					XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
					XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X',
					XS16 = 'X', XS17 = 'X', XS18 = 'G', XS19 = 'G', XS20 = 'G',
					XS21 = 'X', XS22 = 'X', XS23 = 'G',				XS25 = 'G'; // pos 24 5g
				break;
			case 6: XS1 = 'X', XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
					XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
					XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'G', XS15 = 'X',
					XS16 = 'X', XS17 = 'X', XS18 = 'G', XS19 = 'G', XS20 = 'G',
					XS21 = 'X', XS22 = 'X', XS23 = 'G',				XS25 = 'G'; // pos 24 6g
				break;
				}
	case 225: switch (enemycount)
			{
			case 1: XS1 = ‘X’, XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
					XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
					XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X',
					XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'X',
					XS21 = 'X', XS22 = 'X', XS23 = 'X',	XS24 = 'G';				// pos 25 1g
				break;
			case 2: XS1 = ‘X’, XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
					XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
					XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X',
					XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'X', XS20 = 'G',
					XS21 = 'X', XS22 = 'X', XS23 = 'X',	XS24 = 'G';				//pos 25 2g
				break;
			case 3: XS1 = ‘X’, XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
					XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
					XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'X',
					XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'G', XS20 = 'G',
					XS21 = 'X', XS22 = 'X', XS23 = 'X',	XS24 = 'G';				//pos 25 3g 
				break;
			case 4: XS1 = ‘X’, XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
					XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
					XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'G',
					XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'G', XS20 = 'G',
					XS21 = 'X', XS22 = 'X', XS23 = 'X',	XS24 = 'G';				//pos 25 4g
				break;
			case 5: XS1 = ‘X’, XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
					XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
					XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'X', XS15 = 'G',
					XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'G', XS20 = 'G',
					XS21 = 'X', XS22 = 'X', XS23 = 'G', XS24 = 'G';				//pos 25 5g
				break;
			case 6: XS1 = ‘X’, XS2 = 'X', XS3 = 'X', XS4 = 'X', XS5 = 'X',
					XS6 = 'X', XS7 = 'X', XS8 = 'X', XS9 = 'X', XS10 = 'X',
					XS11 = 'X', XS12 = 'X', XS13 = 'X', XS14 = 'G', XS15 = 'G',
					XS16 = 'X', XS17 = 'X', XS18 = 'X', XS19 = 'G', XS20 = 'G',
					XS21 = 'X', XS22 = 'X', XS23 = 'G', XS24 = 'G';				//pos 25 6g
				break;
			}
	}
	//display map after G move
	cout << "#####################################" << '\n';
	cout << "# A       B       C       D       E #" << '\n';
	cout << "#1" << XS1 << "       " << XS2 << "       " << XS3 << "       " << XS4 << "       " << XS5 << " #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#2" << XS6 << "       " << XS7 << "       " << XS8 << "       " << XS9 << "       " << XS10 << " #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#3" << XS11 << "       " << XS12 << "       " << XS13 << "       " << XS14 << "       " << XS15 << " #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#4" << XS16 << "       " << XS17 << "       " << XS18 << "       " << XS19 << "       " << XS20 << " #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#5" << XS21 << "       " << XS22 << "       " << XS23 << "       " << XS24 << "       " << XS25 << " #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#####################################" << '\n' << '\n';
	

	//player health = playerhealth - damage*enemycount
	

	
	//---------------------------------------------------------------------------------------------------------------------
		//find which find location to go to
findfindlocation:

	switch (goingmap)
	{
	case 1:goto findlocation;
	case 2:goto findlocation2;
	}
	//---------------------------------------------------------------------------------------------------------------------
		
		//Map 2 main switch
findlocation2:

	cout << "========================================================================================" << '\n' << '\n' << "What would you like to do? ";
	cin >> input;

	//update location
	if (X201 == 'D') { location = 201; }
	if (X202 == 'D') { location = 202; }
	if (X203 == 'D') { location = 203; }
	if (X204 == 'D') { location = 204; }
	if (X205 == 'D') { location = 205; }
	if (X206 == 'D') { location = 206; }
	if (X207 == 'D') { location = 207; }
	if (X208 == 'D') { location = 208; }
	if (X209 == 'D') { location = 209; }
	if (X210 == 'D') { location = 210; }
	if (X211 == 'D') { location = 211; }


	switch (location)
	{
	case 201:	switch (input)
			{
			case 1: X201 = 'X'; X202 = 'D'; goto findmap;//north
			case 3: X201 = 'X'; X7 = 'D'; goingmap = 1; goto findmap; //south back to map1
			case 5: goto inventory;//inv
			case 8: goto help;//controls
			default: cout << "You can't do that here." << '\n'; goto findlocation2;
				break;
			}
	case 202:	switch (input)
			{
			case 1: X202 = 'X'; //north
					X203 = 'D'; 
					goto findmap;
			case 3: X202 = 'X';//south
					X201 = 'D';
					goto findmap;
			case 4: X202 = 'X';//West
					X204 = 'D';
					goto findmap;
			case 5: goto inventory;//inv
			case 8: goto help;//controls
			default: cout << "You can't do that here." << '\n'; goto findlocation2;
				break;
			}
	case 203:	switch (input)
			{
			case 1:if (C2 == ' ')//north through dirt
					{
					X203 = 'X'; 
					X210 = 'D';
					goto findmap;
					}
					 else
						{
						cout << "There is collapsed dirt here. Maybe you could mine it. \n"; goto findlocation2;
						}
			case 4: X203 = 'X';//West
					X204 = 'D';
					goto findmap;
			case 5: goto inventory;//inv
			case 6: C2 = ' ';//mine
					goto findmap;
			case 8: goto help;//controls
			default: cout << "You can't do that here." << '\n'; goto findlocation2;
				break;
			}
	case 204:	switch (input)
			{
			case 2: X204 = 'X';//east
					X202 = 'D';
					goto findmap;
						break;
			case 4: X204 = 'X'; //west
					X205 = 'D'; 
					goto findmap;
						break;
			case 5: goto inventory;//inv
			case 8: goto help;//controls
			default: cout << "You can't do that here." << '\n'; goto findlocation2;

			}
	case 205:	switch (input)
				{
				case 1: X205 = 'X';//north
						X206 = 'D';
						goto findmap;
				case 2: X205 = 'X';//east
						X204 = 'D';
						goto findmap;
				case 5: goto inventory;//inv
				case 8: goto help;//controls
				default: cout << "You can't do that here." << '\n'; goto findlocation2;
				}
	case 206:	switch (input)
			{
			case 1: X206 = 'X';//north
					X207 = 'D';
					goto findmap;
			case 3: X206 = 'X';//south
					X205 = 'D';
					goto findmap;
			case 5: goto inventory;//inv
			case 8: goto help;//controls
			case 6:if (N2 == 'N')//mine
			{
				N2 = '/'; 
				N3 = ' ';
				oreamount = 3;
				goto nitra1;
			}
				  else
				{
				cout << "You can't do that here." << '\n'; goto findlocation2;
				}
			default: cout << "You can't do that here." << '\n'; goto findlocation2;
			}
	case 207:switch (input)
			{
			case 2: X207 = 'X';//east
					X208 = 'D';
					goto findmap;
			case 3: X207 = 'X';//south
					X206 = 'D';
					goto findmap;
			case 5: goto inventory;//inv
			case 8: goto help;//controls
			case 6:if (N4 == 'N')//mine
			{
				N4 = '/';
				N5 = ' '; 
				oreamount = 3;
				goto nitra1;
			}
			  else
				{
				cout << "You can't do that here." << '\n'; goto findlocation2;
				}
			default: cout << "You can't do that here." << '\n'; goto findlocation2;
	}
	case 208: switch (input)
			{
			case 1: X208 = 'X';//north
					X209 = 'D';
					goto findmap;
			case 4: X208 = 'X';//West
				X207 = 'D';
				goto findmap;
			case 5: goto inventory;//inv
			case 8: goto help;//controls
			case 6:if (G2 == 'G')//mine
			{
				G2 = '/';
				oreamount = 2;
				goto gold1;
			}
				  else
				{
				cout << "You can't do that here." << '\n'; goto findlocation2;
				}
			default: cout << "You can't do that here." << '\n'; goto findlocation2;
			}
	case 209: switch (input)
			{
			case 3: X209 = 'X';//south
					X208 = 'D';
			goto findmap;
			case 2: X209 = 'X';//east
					X210 = 'D';
					goto findmap;
			case 5: goto inventory;//inv
			case 8: goto help;//controls
			default: cout << "You can't do that here." << '\n'; goto findlocation2;
			}
	case 210:	switch (input)
			{
			case 1: X210 = 'X';//north
					X211 = 'D';
					goto findmap;
			case 2: X210 = 'X';//west
					X211 = 'D';
					goto findmap;
			case 3:if (C2 == ' ')//south through dirt
					{
					X210 = 'X';
					X203 = 'D';
					goto findmap;
					}
					  else
					{
					cout << "There is collapsed dirt here. Maybe you could mine it. \n"; goto findlocation2;
					}
			case 4: X210 = 'X'; //west
					X209 = 'D';
					goto findmap;
						break;
			case 6: C2 = ' ';
				goto findmap;
			case 5: goto inventory;//inv
			case 8: goto help;//controls
			default: cout << "You can't do that here." << '\n'; goto findlocation2;

			}
	case 211:{}
	}
	//---------------------------------------------------------------------------------------------------------------------

		//map 2 code
	//cout << "#####################################" << '\n';
	//cout << "#                                  _#" << '\n';
	//cout << "#                  ___           _/ #" << '\n';
	//cout << "#               __/   \__    ___/ X11#" << '\n';
	//cout << "#        __    /         \__/      _#" << '\n';
	//cout << "#       /  \__/  X9            X10/ #" << '\n';
	//cout << "#       |               __      _/  #" << '\n';
	//cout << "#      N            ___/  \C   /    #" << '\n';
	//cout << "#     NNX7 ___   X8G      /CCC/     #" << '\n';
	//cout << "#    _|   /   \___G     _|CCCC\     #" << '\n';
	//cout << "#   /    N         ____/   CC  |    #" << '\n';
	//cout << "#   |X6 NN     ___/         X3  \   #" << '\n';
	//cout << "#   |_   \   _/               __/   #" << '\n';
	//cout << "#     \   |_/                 \     #" << '\n';
	//cout << "#      \_X5                    \    #" << '\n';
	//cout << "#        \____  X4           X2 |   #" << '\n';
	//cout << "#	         \_____            \   #" << '\n';
	//cout << "#       	           \     _      |  #" << '\n';
	//cout << "#       	            |___/ |   X1 \ #" << '\n';
	//cout << "#                           \      \#" << '\n';
	//cout << "#####################################" << '\n'

	//changed after mine
	//N2 = '/'; 
	//N3 = ' ';
	//N4 = '/'; 
	//N5 = ' '; 
	//G2 = '/';
	goto findlocation2;
	//---------------------------------------------------------------------------------------------------------------------
	//used when going to map 2 as is will not display the map/ weird workaround for bug
map2trans:
	cout << "#####################################" << '\n';
	cout << "#                                  _#" << '\n';
	cout << "#                  ___           _/ #" << '\n';
	cout << "#               __/   \\__    ___/ " << X211 << " #" << '\n';
	cout << "#        __    /         \\__/      _#" << '\n';
	cout << "#       /  \\__/  " << X209 << "             " << X210 << "  / #" << '\n';
	cout << "#       |               __      _/  #" << '\n';
	cout << "#      " << N4 << "            ___/  \\" << C2 << "   /    #" << '\n';
	cout << "#     " << N4 << N5 << X207 << "  ___   " << X208 << " " << G2 << "      /" << C2 << C2 << C2 << "/     #" << '\n';
	cout << "#    _|   /   \\___" << G2 << "     _|" << C2 << C2 << C2 << C2 << "\\     #" << '\n';
	cout << "#   /    " << N2 << "         ____/   " << C2 << C2 << "  |    #" << '\n';
	cout << "#   | " << X206 << " " << N2 << N3 << "     ___/         " << X203 << "   \\   #" << '\n';
	cout << "#   |_   \\   _/               __/   #" << '\n';
	cout << "#     \\   |_/                 \\     #" << '\n';
	cout << "#      \\_" << X205 << "                     \\    #" << '\n';
	cout << "#        \\____  " << X204 << "            " << X202 << "  |   #" << '\n';
	cout << "#             \\_____            \\   #" << '\n';
	cout << "#     	            \\     _      |  #" << '\n';
	cout << "#  	             |___/ |   " << X201 << "  \\ #" << '\n';
	cout << "#                           \\      \\#" << '\n';
	cout << "#####################################" << '\n' << '\n';
	goto swarm;

	//---------------------------------------------------------------------------------------------------------------------
findmap:

	switch (goingmap) 
	{
	case 1:
	{
		cout << "#####################################" << '\n';
		cout << "#" << C1 << C1 << C1 << C1 << C1 << C1 << C1 << " |                          #" << '\n';
		cout << "#\\" << C1 << C1 << "     |                          #" << '\n';
		cout << "# \\  " << X7 << "    \\______                   #" << '\n';
		cout << "#  |             \\       __         #" << '\n';
		cout << "#  |              \\_____/  |        #" << '\n';
		cout << "#   \\   " << X6 << "        " << X2 << "        " << X3 << " \\       #" << '\n';
		cout << "#    \\                       \\      #" << '\n';
		cout << "#    |     |            |     |     #" << '\n';
		cout << "#     \\    |            |      \\    #" << '\n';
		cout << "#     |    |     " << X1 << "      |       \\__ #" << '\n';
		cout << "#     |    |            |          |#" << '\n';
		cout << "#      \\   \\            /          |#" << '\n';
		cout << "#       |   \\          /          / #" << '\n';
		cout << "#       |    \\________/          /  #" << '\n';
		cout << "#       " << N1 << X5 << "	             ___/   #" << '\n';
		cout << "#       " << N1 << "	         " << X4 << "   \\      #" << '\n';
		cout << "#      |	         " << G1 << G1 << "__/      #" << '\n';
		cout << "#      \\	         " << G11 << G12 << "         #" << '\n';
		cout << "#       \\_______________/           #" << '\n';
		cout << "#####################################" << '\n' << '\n';
		goto findfindlocation;
	}
	case 2:
	{
		cout << "#####################################" << '\n';
		cout << "#                                  _#" << '\n';
		cout << "#                  ___           _/ #" << '\n';
		cout << "#               __/   \\__    ___/ " << X211 << " #" << '\n';
		cout << "#        __    /         \\__/      _#" << '\n';
		cout << "#       /  \\__/  " << X209 << "             " << X210 << "  / #" << '\n';
		cout << "#       |               __      _/  #" << '\n';
		cout << "#      " << N4 << "            ___/  \\" << C2 << "   /    #" << '\n';
		cout << "#     " << N4 << N5 << X207 << "  ___   " << X208 << " " << G2 << "      /" << C2 << C2 << C2 << "/     #" << '\n';
		cout << "#    _|   /   \\___" << G2 << "     _|" << C2 << C2 << C2 << C2 << "\\     #" << '\n';
		cout << "#   /    " << N2 << "         ____/   " << C2 << C2 << "  |    #" << '\n';
		cout << "#   | " << X206 << " " << N2 << N3 << "     ___/         " << X203 << "   \\   #" << '\n';
		cout << "#   |_   \\   _/               __/   #" << '\n';
		cout << "#     \\   |_/                 \\     #" << '\n';
		cout << "#      \\_" << X205 << "                     \\    #" << '\n';
		cout << "#        \\____  " << X204 << "            " << X202 << "  |   #" << '\n';
		cout << "#             \\_____            \\   #" << '\n';
		cout << "#     	            \\     _      |  #" << '\n';
		cout << "#  	             |___/ |   " << X201 << "  \\ #" << '\n';
		cout << "#                           \\      \\#" << '\n';
		cout << "#####################################" << '\n' << '\n';
		goto findfindlocation;
	}
	
	}
swarmmap2:
	cout << "#####################################" << '\n';//this map wa orriganly 81 varriables/locations
	cout << "# A       B       C       D       E #" << '\n';
	cout << "#1" << XS1 << "       " << XS2 << "       " << XS3 << "       " << XS4 << "       " << XS5 << " #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#2" << XS6 << "       " << XS7 << "       " << XS8 << "       " << XS9 << "       " << XS10 << " #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#3" << XS11 << "       " << XS12 << "       " << XS13 << "       " << XS14 << "       " << XS15 << " #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#4" << XS16 << "       " << XS17 << "       " << XS18 << "       " << XS19 << "       " << XS20 << " #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#5" << XS21 << "       " << XS22 << "       " << XS23 << "       " << XS24 << "       " << XS25 << " #" << '\n';
	cout << "#                                   #" << '\n';
	cout << "#####################################" << '\n' << '\n';
	goto attack;


	cin.get();  //keep console window open
	cin.ignore();
}