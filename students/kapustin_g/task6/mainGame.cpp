#include "mainGame.h"

mainGame::mainGame(snakeObjects &_snake, drawer &_dwr) :
    snake(_snake), dwr(_dwr) { }
int mainGame::step(short int dir) // returns: 0 when head hits the walls or eats itself, 1 when snake moved on field w/out any events, 2 when snake ate an apple
{
    point _tale = snake.getTail();
    point _head = snake.getHead();
    point apple = snake.getApple();
    int k = snake.move(dir);
    if (k == 0)
        return 0;
    if (snake.headAteTale())
        return 0;
    point tale_ = snake.getTail();
    point head_ = snake.getHead();
    dwr.render(apple.x, apple.y, 5);
    switch (dir)
    {
    case 1:dwr.render(head_.x, head_.y, 1); break;
    case 2:dwr.render(head_.x, head_.y, 0); break;
    case 3:dwr.render(head_.x, head_.y, 3); break;
    case 4:dwr.render(head_.x, head_.y, 2); break;
    }
    dwr.render(_head.x, _head.y, 4);
    if (!(_tale == head_))
        dwr.render(_tale.x, _tale.y, 6);
    return k;
}
void mainGame::setFieldSize(short int x, short int y)
{
    snake.setFieldSize(x, y);
    dwr.SCREENW = x + 5;
    dwr.SCREENH = y;
}
void mainGame::initDraw()
{
    for (int i = 0; i < dwr.SCREENW; i++)
    {
        for (int j = 0; j < dwr.SCREENH; j++)
        {

            dwr.render(i, j, 6);
        }
    }
    std::vector <point> ssnake = snake.getSnake();
    dwr.render(ssnake[0].x, ssnake[0].y, 3);
    for (int i = 0; i < dwr.SCREENW - 5; i++)
    {
        for (int j = 0; j < dwr.SCREENH; j++)
        {
            dwr.render(0, j, 7);
            dwr.render(1, j, 7);
            dwr.render(dwr.SCREENW - 6, j, 7);
            dwr.render(dwr.SCREENW - 7, j, 7);

        }
        dwr.render(i, 0, 7);
        dwr.render(i, 1, 7);
        dwr.render(i, dwr.SCREENH - 1, 7);
        dwr.render(i, dwr.SCREENH - 2, 7);

    }
    for (int i = 1; i < ssnake.size(); i++)
    {
        dwr.render(ssnake[i].x, ssnake[i].y, 4);
    }
    dwr.renderText(dwr.SCREENW - 5, 0, 80, 28, "Score");
    drawScore();
    dwr.renderText(dwr.SCREENW - 5, 4, 80, 28, "Goal");
    std::ostringstream ost;
    ost << scoreGoal;
    std::string s_num = ost.str();
    dwr.render(dwr.SCREENW - 5, 2, 6);
    dwr.renderText(dwr.SCREENW - 5, 6, 16, 16, s_num);
    dwr.renderPresent();
}
void mainGame::drawScore()
{
    std::ostringstream ost;
    ost << scoreCurrent;
    std::string s_num = ost.str();
    dwr.render(dwr.SCREENW - 5, 2, 6);
    dwr.renderText(dwr.SCREENW - 5, 2, 16, 16, s_num);
}
void mainGame::gameLoop(short int score)
{
    if (dwr.init())
    {
        if (dwr.loadMedia() && dwr.loadMediaText())
        {
            scoreGoal = score;
            snake.init();
            bool quit = false;
            SDL_Event e;
            short direct = 3;
            int sleepDelay;
            bool pause = 1;
            initDraw();
            while (!quit)
            {
                sleepDelay = 250;
                while (SDL_PollEvent(&e) != 0)
                {
                    switch (e.type)
                    {
                    case SDL_QUIT:
                        quit = true;
                        break;
                    case SDL_KEYDOWN:
                        switch (e.key.keysym.sym)
                        {
                        case SDLK_UP:
                            direct = 2;
                            break;

                        case SDLK_DOWN:
                            direct = 4;
                            break;

                        case SDLK_LEFT:
                            direct = 3;
                            break;

                        case SDLK_RIGHT:
                            direct = 1;
                            break;
                        case SDLK_SPACE:
                            sleepDelay = 40;
                            break;
                        case SDLK_ESCAPE:
                            pause = !pause;
                            break;
                        }
                        break;
                    default:
                        break;
                    }
                }
                if (!pause) //gamebody
                {
                    switch (step(direct))
                    {
                    case 0:
                        quit = 1;
                        break;
                    case 1:
                        break;
                    case 2:
                        scoreCurrent++;
                        drawScore();
                        break;
                    }
                    if (scoreCurrent == scoreGoal) //player won
                    {
                        gameResult = 1;
                        quit = 1;
                    }
                    dwr.renderPresent();
                    SDL_Delay(sleepDelay);
                }
                else
                    SDL_Delay(250);
            }

            if (gameResult)
                dwr.renderText(dwr.SCREENW / 2 - 170 / 16, dwr.SCREENH / 2 - 100 / 16, 350, 100, "GAME IS WON!");
            else
                dwr.renderText(dwr.SCREENW / 2 - 170 / 16, dwr.SCREENH / 2 - 100 / 16, 350, 100, "GAME IS OVER!");

            dwr.renderPresent();
            SDL_Delay(1500);
        }
    }
}
mainGame::~mainGame()
{
}
