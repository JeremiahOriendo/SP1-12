#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;

const unsigned char FPS = 100; // FPS of this game
const unsigned int frameTime = 1000 / FPS; // time for each frame

//int getKey()
//{
//	int choice;
//	cin >> choice;
//	return choice;
//}
//
//void Selection()
//{
//	int choice = 0;
//	do
//	{
//		choice = getKey();
//		switch(choice)
//		{
//		case 1: ChangeShip();
//			break;
//		case 2: DisplayOptions();
//			break;
//		case 3: ChangeShip();
//			break;
//		case 4: shutdown();
//		default:
//			break;
//		}
//	} while ( choice != 4 );
//}
//

void rendMainMenu()
{
	clearBuffer(0x00);
	COORD a;
	a.X=0;
	a.Y=0;
	colour(0x10A);
	writeToBuffer(a,(std::string) "                             #######   ########   ",0x10A);-
		a.Y++;
	writeToBuffer(a,(std::string) "                            #########  ###   #### ",0x10A);
	a.Y++;
	writeToBuffer(a,(std::string) "                           ####    ### ###    ####",0x10A);
	a.Y++;
	writeToBuffer(a,(std::string) "                            ####       ###   #### ",0x10A);
	a.Y++;
	writeToBuffer(a,(std::string) "                              ####     ########   ",0x10A);
	a.Y++;
	writeToBuffer(a,(std::string) "                                 ####  ###        ",0x10A);
	a.Y++;
	writeToBuffer(a,(std::string) "                                  #### ###        ",0x10A);
	a.Y++;
	writeToBuffer(a,(std::string) "                           ###    #### ###        ",0x10A);
	a.Y++;
	writeToBuffer(a,(std::string) "                            #########  ###        ",0x10A);
	a.Y++;
	writeToBuffer(a,(std::string) "                             #######   ### SPACE PEWTER",0x10A);
	a.Y++;
	writeToBuffer(a,(std::string) "");
	a.Y++;
	if ( ArrowLocate.Y == 11 )
	{
		writeToBuffer(a,(std::string) "                                    START",0x10E);
	}
	else
	{
		writeToBuffer(a,(std::string) "                                    start",0x10A);
	}
	a.Y++;
	writeToBuffer(a,(std::string) "");
	a.Y++;
	writeToBuffer(a,(std::string) "");
	a.Y++;
	if ( ArrowLocate.Y == 14 )
	{
		writeToBuffer(a,(std::string) "                                   CONTROLS",0x10E);
	}
	else
	{
		writeToBuffer(a,(std::string) "                                   controls",0x10A);
	}
	a.Y++;
	writeToBuffer(a,(std::string) "");
	a.Y++;
	writeToBuffer(a,(std::string) "");
	a.Y++;
	if ( ArrowLocate.Y == 17 )
	{
		writeToBuffer(a,(std::string) "                                 CHOOSE SHIP",0x10E);
	}
	else
	{
		writeToBuffer(a,(std::string) "                                 choose ship",0x10A);
	}
	a.Y++;
	writeToBuffer(a,(std::string) "");
	a.Y++;
	writeToBuffer(a,(std::string) "");
	a.Y++;
	if ( ArrowLocate.Y == 20 )
	{
		writeToBuffer(a,(std::string) "                                  EXIT GAME",0x10E);
	}
	else
	{
		writeToBuffer(a,(std::string) "                                  exit game",0x10A);
	}
	writeToBuffer(ArrowLocate, (std::string)">>", 0x0C);
	writeToBuffer(ArrowLocate2, (std::string)"<<", 0x0C);
	flushBufferToConsole();
}

void rendOptions()
{
	clearBuffer(0x00);
	COORD a;
	a.X=29;
	a.Y=5;
	COORD b;
	b.X = 37;
	colour(0x10A);
	writeToBuffer(a, "Insert Controls here");
	b.Y = 14;
	writeToBuffer(b, "Back");
	ArrowLocate.Y = 14;
	ArrowLocate2.Y = 14;
	writeToBuffer(ArrowLocate, ">>", 0x0C);
	writeToBuffer(ArrowLocate2, "<<", 0x0C);
	flushBufferToConsole();
}

void rendChoose()
{
	clearBuffer(0x00);
	COORD d;
	d.X = 0;
	d.Y = 1;
	writeToBuffer(d, "IJUASIJDASIJDBAS");
	flushBufferToConsole();
}

//void DisplayInGame()
//{
//	std::ostringstream ss;
//	gotoXY(35,5);
//	colour(0x10A);
//	cls();
//	ss << endl << endl << endl << endl;
//	ss << "                        ****  " << " ****  " << "*    * " << "***** " << "***** " << endl;
//	ss << "                        *   * " << "*    * " << "*    * " << "*     " << "*     " << endl;
//	ss << "                        ****  " << "****** " << "*    * " << "***** " << "***** " << endl;
//	ss << "                        *     " << "*    * " << "*    * " << "    * " << "*     " << endl;
//	ss << "                        *     " << "*    * " << " ****  " << "***** " << "***** " << endl;
//	ss << "                                1 - Restart" << endl;
//	ss << "                                2 - Exit Game" << endl;
//	ss << "                                3 - Back to Main Menu" << endl;
//	ss << "                                     ";
//	int H = 0;
//	H = getKey();
//
//	switch ( H )
//	{
//	case 1: init(); 
//		gRestart();
//		break;
//	case 2: shutdown();
//		break;
//	case 3: DisplayMainMenu();
//		break;
//	}
//	return;
//}
//
//void Pause()
//{
//	DisplayInGame();
//}
//
//void ChangeShip()
//{
//	std::ostringstream ss;
//	char ship1[5][20] =
//	{
//		"__",
//		"| \\",
//		"}[_H)--.____",
//		"}[+-,------'",
//		" [_/"
//	}; 
//	char ship2[5][20] = 
//	{
//		"     /\\",
//		" |\\  \\ \\",
//		"| <====}>",
//		" |/  / /",
//		"     \\/"
//	};
//
//	colour(0x10A);
//	cls();
//	ss << "Choose the spaceship you want to use" << endl << endl;
//
//	ss << "Ship 1" << endl;
//
//	for (int count = -2; count <= 2; count++)
//	{
//		ss << ship1[2 + count] << endl;
//	}
//	ss << endl;
//
//	ss << "Ship 2" << endl;
//
//	for (int count = -2; count <= 2; count++)
//	{
//		ss << ship2[2 + count] << endl;
//	}
//	ss << endl << "1 - X-Wing" << endl << "2 - Arrowhead" << endl << "3 - Main Menu" << endl;
//	int shipNum = 1;
//
//	cin >> shipNum;
//
//	switch (shipNum)
//	{
//	case 1:
//		for (int count = 0; count < 5; count++)
//		{
//			strcpy(ship[count], ship1[count]);
//		}
//		init();
//		mainLoop();
//		break;
//	case 2:
//		for (int count = 0; count < 5; count++)
//		{
//			strcpy(ship[count], ship2[count]);
//		}
//		init();
//		mainLoop();
//		break;
//	case 3: DisplayMainMenu();
//		Selection();
//		break;
//	default: 
//		for (int count = 0; count < 5; count++)
//		{
//			strcpy(ship[count], ship1[count]);
//		}
//		init();
//		mainLoop();
//		break;
//	}
//}
//
//void gRestart()
//{
//	g_timer.startTimer();    // Start timer to calculate how long it takes to render this frame
//	while (!g_quitGame)      // run this loop until user wants to quit 
//	{        
//		getInput();                         // get keyboard input
//		update(g_timer.getElapsedTime());   // update the game
//		render();                           // render the graphics output to screen
//		g_timer.waitUntil(frameTime);       // Frame rate limiter. Limits each frame to a specified time in ms.      
//	}    
//}
//
//void GameOver()
//{
//	std::ostringstream ss;
//	init(); 
//	cls();
//	ss << endl << endl << endl << endl << endl << endl << endl << endl;
//	ss << "                                  GAME OVER" << endl;
//	ss << "                                  1.Continue? " << endl;
//	ss << "                                  2.Main Menu" << endl;
//	ss << "                                  3.Exit" << endl;
//	ss << "                                   " << endl;
//	int H = 0;
//	H = getKey();
//
//	switch ( H )
//	{
//	case 1: init();
//		gRestart();
//		break;
//	case 2: DisplayMainMenu();
//		break;
//	case 3: shutdown();
//		break;
//	}
//	return;
//}