#pragma once
#include "drawer.h"
#include "snakeObjects.h"
#include <iostream>
#include <sstream>

class mainGame
{
    snakeObjects &snake;
    drawer &dwr;
    short unsigned int score = 0;
    bool gameResult = 0;
    int step(short int dir);  // returns: 0 when head hits the walls, 1 when snake moved on field w/out any events, 2 when snake ate an apple
    void drawScore();
    void initDraw();
public:
    void setFieldSize(short int x, short int y);
    void gameLoop(short int score);
    mainGame(snakeObjects &_snake, drawer &_dwr);
    ~mainGame();
};

