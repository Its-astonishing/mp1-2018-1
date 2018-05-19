#include "mainGame.h"
#include <iostream>

#undef main
int main(int argc, char* args[])
{
    snakeObjects snake; //this class contains information about snake, food and also int contains size of the game field
    drawer Drawer; // this class provides ability to work with sdl: load textures, render them, create windows etc 
    mainGame gameObj(snake, Drawer); //this one is the main class it draws image, controls keyboard
    short int score;
    short int w;
    short int h;
    do
    {
        system("cls");
        std::cout << "Key controlling: \nArrow up/left/right/down --- moving\nSpace\t\t\t --- boost\nEsc\t\t\t --- pause/unpause\nPlease input win-condition-score: ";
        std::cin >> score;
        std::cout << std::endl << "Input width and height of the field (in blocks, 1 block = 16 px, > 17):";
        std::cin >> w >> h;
    } while (score < 1 || score>300 || w < 17 || h < 17);
    gameObj.setFieldSize(w, h);
    gameObj.gameLoop(score);
    return 0;
}