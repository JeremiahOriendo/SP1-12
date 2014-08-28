// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <sstream>

// Console size, width by height
COORD ConsoleSize = {80, 25};

double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNT];

bool menu = 1 ; 
bool option = 0 ;
bool game = 0 ;
bool Ship = 0;

// Game specific variables here
COORD charLocation;
COORD ArrowLocate;
COORD ArrowLocate2;

void init()
{
	// Set precision for floating point output
	elapsedTime = 0.0;

	initConsole(ConsoleSize, "SP1 Framework");

	ArrowLocate.X = 31;
	ArrowLocate.Y = 11;

	ArrowLocate2.X = 44;
	ArrowLocate2.Y = 11;
}

void shutdown()
{
	// Reset to white text on black background
	colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

	shutDownConsole();
}

void getInput()
{    
	keyPressed[K_UP] = isKeyPressed(VK_UP);
	keyPressed[K_DOWN] = isKeyPressed(VK_DOWN);
	keyPressed[K_LEFT] = isKeyPressed(VK_LEFT);
	keyPressed[K_RIGHT] = isKeyPressed(VK_RIGHT);
	keyPressed[K_ESCAPE] = isKeyPressed(VK_ESCAPE);
	keyPressed[K_ENTER] = isKeyPressed(VK_RETURN);
}

void update(double dt)
{
	// get the delta time
	elapsedTime += dt;
	deltaTime = dt;

	if ( menu == 1 )//Main Menu
	{
		if (keyPressed[K_UP] && ArrowLocate.Y > 11)
		{
			//Beep(1440, 30);
			ArrowLocate.Y -= 3; 
			ArrowLocate2.Y -=3;
		}
		if (keyPressed[K_DOWN] && ArrowLocate.Y <18)
		{
			//Beep(1440, 30);
			ArrowLocate.Y += 3;
			ArrowLocate2.Y += 3;
		}
		if (keyPressed[K_ENTER] && ArrowLocate.Y == 11) //Start
		{
			menu = 0 ; 
			game = 1;
			init();
			gameLoop();
		}
		if (keyPressed[K_ENTER] && ArrowLocate.Y == 14) //Options
		{
			option = 1 ; 
			menu = 0 ; 
			//ArrowLocate.Y = 14; 
			//ArrowLocate2.Y = 14;
			init();
			MenuLoop();
		}
		if (keyPressed[K_ENTER] && ArrowLocate.Y == 17) //Choose Ship
		{
			menu=0;
			option=0;
			game=0;
			Ship=1;
			init();
			MenuLoop();
		}
		if (keyPressed[K_ENTER] && ArrowLocate.Y == 20) //Exit Game
		{
			exit(1);
		}
		if (keyPressed[K_ESCAPE])
		{
			g_quitGame = true;    
		}
	}
	if ( option == 1  )//Options
	{

		if (keyPressed[K_UP] && ArrowLocate.Y > 0)
		{
			//Beep(1440, 30);
			ArrowLocate.Y -=3; 
			ArrowLocate2.Y -=3;
		}
		if (keyPressed[K_DOWN] && ArrowLocate.Y < 17)
		{
			//Beep(1440, 30);
			ArrowLocate.Y += 3;
			ArrowLocate2.Y += 3;
		}
		if (keyPressed[K_ENTER] && ArrowLocate.Y == 14) //Back
		{
			option = 0 ; 
			menu = 1; 
			game = 0;
		}
		if (keyPressed[K_ESCAPE])
		{
			g_quitGame = true;    
		}
	}
	if ( Ship == 1 )
	{
		if (keyPressed[K_ESCAPE])
		{
			g_quitGame = true;  
		}
	}

	// quits the game if player hits the escape key
	if (keyPressed[K_ESCAPE])
	{
		g_quitGame = true;    
	}

}

void render()
{    
	// Clears the buffer with this colour attribute
	clearBuffer(0x00);

	// Set up sample colours, and output shadings
	COORD c;

	// displays the framerate
	std::ostringstream ss;
	ss << std::fixed << std::setprecision(3);
	ss << 1.0 / deltaTime << "fps";
	c.X = ConsoleSize.X-9;
	c.Y = 0;
	writeToBuffer(c, ss.str());

	// displays the elapsed time
	ss.str("");
	ss << elapsedTime << "secs";
	c.X = 0;
	c.Y = 0;
	writeToBuffer(c, ss.str(), 0x59);

	if ( menu == 1 ) 
	{
		rendMainMenu();
	} 

	else if ( option == 1 ) 
	{ 
		rendOptions(); 
	}
	else if ( game == 1 )
	{
	c.X = 40;
	c.Y = 15;
	writeToBuffer(c, "In game state");
	flushBufferToConsole();
	}

	else if ( Ship ==  1 )
	{
		rendChoose();
	}
	flushBufferToConsole();
}

