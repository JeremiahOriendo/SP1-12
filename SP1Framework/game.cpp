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

	ArrowLocate2.X = 50;
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

    // Updating the location of the character based on the key press
    //if (keyPressed[K_UP] && charLocation.Y > 0)
    //{
    //    //Beep(1440, 30);
    //    charLocation.Y+2; 
    //}
	if (keyPressed[K_UP] && ArrowLocate.Y > 11)
    {
        //Beep(1440, 30);
        ArrowLocate.Y--; 
		ArrowLocate2.Y--;
    }
	if (keyPressed[K_DOWN] && ArrowLocate.Y <14)
    {
        //Beep(1440, 30);
        ArrowLocate.Y++;
		ArrowLocate2.Y++;
    }
	if (keyPressed[K_ENTER] && ArrowLocate.Y == 11) //Start
	{
		init();
		mainLoop();
	}
	if (keyPressed[K_ENTER] && ArrowLocate.Y == 12) //Options
	{
		DisplayOptions();
	}
	if (keyPressed[K_ENTER] && ArrowLocate.Y == 13) //Choose Ship
	{

	}
	if (keyPressed[K_ENTER] && ArrowLocate.Y == 14) //Exit Game
	{
		g_quitGame = true; 
	}
    //if (keyPressed[K_LEFT] && charLocation.X > 0)
    //{
    //    Beep(1440, 30);
    //    charLocation.X--;
    //}
    //if (keyPressed[K_DOWN] && charLocation.Y < ConsoleSize.Y - 1)
    //{
    //    //Beep(1440, 30);
    //    charLocation.Y;
    //}
    if (keyPressed[K_RIGHT] && charLocation.X < ConsoleSize.X - 1)
    {
        //Beep(1440, 30);
        charLocation.X++;
    }

    // quits the game if player hits the escape key
    if (keyPressed[K_ESCAPE])
        g_quitGame = true;    
}

void render()
{    
    // Clears the buffer with this colour attribute
    clearBuffer(0x00);
    // Set up sample colours, and output shadings
	DisplayMainMenu();
    COORD c;
	/*for (int i = 0; i < 12; ++i)
	{
		c.X = 5*i;
        c.Y = i+1;
		colour(colors[i]);
		writeToBuffer(c, " °±²Û", colors[i]);
	}
*/
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

    // Draw the location of the character
    //writeToBuffer(charLocation, (char)1, 0x0C);
	writeToBuffer(ArrowLocate, (std::string)">>", 0x0C);
	writeToBuffer(ArrowLocate2, (std::string)"<<", 0x0C);

    // Writes the buffer to the console, hence you will see what you have written
    flushBufferToConsole();
}
