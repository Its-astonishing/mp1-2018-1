#include "drawer.h"



drawer::drawer()
{
}
//bool drawer::init()
//{
//    bool success = 1;
//
//    if (SDL_Init(SDL_INIT_VIDEO) < 0)
//        success = false;
//
//    else
//    {
//        gWindow = SDL_CreateWindow("Snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1080, 720, SDL_WINDOW_SHOWN);
//
//        if (gWindow == NULL)
//            success = false;
//        else
//        {
//            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
//
//            if (gRenderer == NULL)
//                success = false;
//            else
//            {
//                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
//                int imgFlags = IMG_INIT_PNG;
//
//                if (!(IMG_Init(imgFlags) & imgFlags))
//                    success = false;
//            }
//        }
//    }
//    return success;
//}

void drawer::free()
{
    if (mTexture != NULL)
    {
        SDL_DestroyTexture(mTexture);
        mTexture = NULL;
    }
}
void drawer::freeT()
{
    if (textTexture != NULL)
    {
        SDL_DestroyTexture(textTexture);
        textTexture = NULL;
    }
}
void drawer::renderText(int _x, int _y, int sizex, int sizey, std::string t)
{
    SDL_Rect renderQuad = { _x * 16, _y * 16, sizex, sizey };
    SDL_Color textColor = { 0, 0, 0 };
    if (!loadFromRenderedText(t, textColor))
    {
        printf("Failed to render text texture!\n");
    }
    //Render to screen
    SDL_RenderCopy(gRenderer, textTexture, NULL, &renderQuad);

}

bool drawer::loadFromRenderedText(std::string textureText, SDL_Color textColor)
{
    //Get rid of preexisting texture
    freeT();

    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
    if (textSurface == NULL)
    {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
    }
    else
    {
        //Create texture from surface pixels
        textTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
        if (textTexture == NULL)
        {
            printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
        }

        //Get rid of old surface
        SDL_FreeSurface(textSurface);
    }

    //Return success
    return textTexture != NULL;
}
bool drawer::loadMediaText()
{
    //Loading success flag
    bool success = true;

    //Open the font
    gFont = TTF_OpenFont("11719.ttf", 28);
    if (gFont == NULL)
    {
        printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
        success = false;
    }
    else
    {
        //Render text
        SDL_Color textColor = { 0, 0, 0 };
        if (!loadFromRenderedText("Score:", textColor))
        {
            printf("Failed to render text texture!\n");
            success = false;
        }
    }

    return success;
}

void drawer::render(int _x, int _y, int i)
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { _x*16, _y*16, 16, 16 };
    
    //Render to screen
    SDL_RenderCopy(gRenderer, mTexture, &gSpriteClips[i], &renderQuad);
}

void drawer::init(SDL_Window *_gWindow, SDL_Renderer *_gRenderer)
{
    gWindow = _gWindow;
    gRenderer = _gRenderer;
}

bool drawer::loadFromFile(std::string path)
{
    bool success = 1;
    //Get rid of preexisting texture
    free();

    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());

    if (loadedSurface == NULL)
        success = 0;

    else
    {
        //Color key image
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);

        if (newTexture == NULL)
            success = 0;
        else
         SDL_FreeSurface(loadedSurface);
    }

    mTexture = newTexture;
    return success;  
}
bool drawer::loadMedia()
{
    bool success = true;

    //Load sprite sheet texture
    if (!loadFromFile("snaketexture2.png"))
        success = false;
    else
        for (int i = 0,k=0; i < 2; i++)
            for (int j = 0; j < 4; j++, k++)
            {
                gSpriteClips[k].x = j * 16;
                gSpriteClips[k].y = i * 16;
                gSpriteClips[k].w = 16;
                gSpriteClips[k].h = 16;
            }
    return success;
}
SDL_Rect * drawer::getSpriteClips()
{
    return gSpriteClips;
}
void drawer::close()
{
    free();
    freeT();
    TTF_CloseFont(gFont);
    gFont = NULL;
    IMG_Quit();
    SDL_Quit();
}


drawer::~drawer()
{
    close();
}
