#pragma once
#include "drawer.h"
#include "snakeObjects.h"
#include <iostream>
#include <sstream>

#define SCREENH 1104 
#define SCREENW 768

class mainGame
{
    SDL_Window *gWindow;
    SDL_Renderer *gRenderer;
    snakeObjects snake;
    short unsigned int score = 0;
    bool gameResult = 0; 
    bool init();
    int step(drawer& _dwr, short int dir);  // returns: 0 when head hits the walls, 1 when snake moved on field w/out any events, 2 when snake ate an apple
    void drawScore(drawer& dwr);
    void initDraw(drawer& dwr);

public:
    void gameLoop(short int score);
    mainGame();
    ~mainGame();
};

