#include "mainGame.h"



mainGame::mainGame()
{
    gWindow = NULL;
    gRenderer = NULL;

}
int mainGame::step(drawer& dwr,short int dir) // returns: 0 when head hits the walls, 1 when snake moved on field w/out any events, 2 when snake ate an apple
{
    point _tale = snake.getTail();
    point _head = snake.getHead();
    point apple = snake.getApple();
    int k = snake.move(dir);
    if (k == 0)
        return 0;
    if (snake.isGameLost())
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
void mainGame::initDraw(drawer& dwr)
{
    for (int i = 0; i < 69; i++)
    {
        for (int j = 0; j < 48; j++)
        {

            dwr.render(i, j, 6);
        }
    }
    std::vector <point> ssnake = snake.getSnake();
    dwr.render(ssnake[0].x, ssnake[0].y, 3);
    for (int i = 0; i < 64; i++)
    {
        for (int j = 0; j < 48; j++)
        {
            dwr.render(0, j, 7);
            dwr.render(1, j, 7);
            dwr.render(62, j, 7);
            dwr.render(63, j, 7);
            
        }
        dwr.render(i, 0, 7);
        dwr.render(i, 1, 7);
        dwr.render(i, 46, 7);
        dwr.render(i, 47, 7);
        
    }
    for (int i = 1; i < ssnake.size(); i++)
    {
        dwr.render(ssnake[i].x, ssnake[i].y, 4);
    }
    dwr.renderText(64, 0, 80, 28, "Score");
    drawScore(dwr);
    SDL_RenderPresent(gRenderer);

}

bool mainGame::init()
{
    bool success = true;
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {

        //Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            printf("Warning: Linear texture filtering not enabled!");
        }

        gWindow = SDL_CreateWindow("Snake game v 1.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREENH, SCREENW, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (gRenderer == NULL)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }
                if (TTF_Init() == -1)
                {
                    printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
                    success = false;
                }
            }
        }
    }

    return success;
}
void mainGame::drawScore(drawer& dwr)
{
    short int points = snake.size() - STARTBLOCKS;
    std::ostringstream ost;
    ost << points;
    std::string s_num = ost.str();
    dwr.render(64, 2, 6);
    dwr.renderText(64, 2, 16, 16, s_num);
}

void mainGame::gameLoop(short int score)
{
    if (init())
    {
        drawer dwr;
        dwr.init(gWindow, gRenderer);
        if (dwr.loadMedia()&&dwr.loadMediaText())
        {
            bool quit = false;
            SDL_Event e;
            short direct = 3;
            int sleepDelay;
            bool pause = 1;
            initDraw(dwr);
            while (!quit)
            {
                sleepDelay = 200;
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
                            sleepDelay = 50;
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
                if (!pause)
                {
                    switch (step(dwr, direct))
                    {
                    case 0:quit = 1; break;
                    case 1:break;
                    case 2:drawScore(dwr); break;
                    }
                    if (snake.size() - STARTBLOCKS == score)
                    {
                        gameResult = 1;
                        quit = 1;
                    }
                    SDL_RenderPresent(gRenderer);
                    SDL_Delay(sleepDelay);
                }
                else
                    SDL_Delay(500);
            }

            if (gameResult)
                dwr.renderText(20, 20, 350, 100, "GAME IS WON!");
            else
                dwr.renderText(20, 20, 350, 100, "GAME IS OVER!");

            SDL_RenderPresent(gRenderer);
            SDL_Delay(1500);
        }
        dwr.close();
    }
}


mainGame::~mainGame()
{
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;
}
