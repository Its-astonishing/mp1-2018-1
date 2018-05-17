#include "mainGame.h"

#undef main
int main(int argc, char* args[])
{
    mainGame gameObj;
    short int score;
    do
    {
        system("cls");
        std::cout << "Key controlling: \nArrow up/left/right/down --- moving\nSpace\t\t\t --- boost\nEsc\t\t\t --- pause/unpause\nPlease input win-condition-score: ";
        std::cin >> score;
    } while (score < 1 && score>300);
    gameObj.gameLoop(score);
    return 0;
}