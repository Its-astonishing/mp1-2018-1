#include "mainGame.h"
#include <iostream>
#undef main
int main(int argc, char* args[])
{
    snakeObjects snake;
    snake.setFieldSize(63, 47);
    snake.init();
    drawer Drawer;
    mainGame gameObj(snake, Drawer);
    int score;
    do
    {
        system("cls");
        std::cout << "Key controlling: \nArrow up/left/right/down --- moving\nSpace\t\t\t --- boost\nEsc\t\t\t --- pause/unpause\nPlease input win-condition-score: ";
        std::cin >> score;
    } while (score < 1 || score>300);
    gameObj.gameLoop(score);
    return 0;
}