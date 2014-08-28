#ifndef _GAME_H
#define _GAME_H

#include "Framework\timer.h"

extern StopWatch g_timer;
extern bool g_quitGame;

enum Keys
{
    K_UP,
    K_DOWN,
    K_LEFT,
    K_RIGHT,
    K_ESCAPE,
	K_ENTER,
    K_COUNT
};


void init();                // initialize your variables, allocate memory, etc
void getInput();            // get directional input
void update(double dt);     // update the game and the state of the game
void render();              // renders the current state of the game to the console(in game-state)
void rendMainMenu();      // renders the main menu of the game
void rendOptions();       // renders options menu
void rendChoose();
void shutdown();            // do clean up, free memory

extern COORD ArrowLocate;
extern COORD ArrowLocate2;
extern COORD ArrowLocate3;
extern COORD ArrowLocate4;

extern int *a;
extern int state;

void gameLoop();
void MenuLoop();
void OptionsLoop();
void ChooseLoop();
int getKey(); //Get player numerical input
void Selection(); //Swicth cases for navigating menu
void Pause(); //Pause function
void gRestart(); //Restart func
void ChangeShip(); //ChangeShip func
void DisplayInGame();
void Selection();
void GameOver();

#endif // _GAME_H