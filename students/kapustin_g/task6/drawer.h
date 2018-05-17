#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <SDL_ttf.h>
#include <string>

class drawer
{
    SDL_Window *gWindow = NULL;
    SDL_Renderer *gRenderer = NULL;
    SDL_Texture * mTexture = NULL;
    SDL_Texture *textTexture = NULL;
    TTF_Font *gFont = NULL;
    SDL_Rect gSpriteClips[10]; 
    SDL_Rect *getSpriteClips();

    void freeT();
    void free();
public:
    void init(SDL_Window *_gWindow, SDL_Renderer *_gRenderer);
    bool loadMedia(); //loads snake sprite into rectangles
    bool loadMediaText();
    void render(int _x, int _y, int i); 
    void renderText(int _x, int _y, int sizex, int sizey, std::string t);
    bool loadFromFile(std::string path); //loads any texture into mTexture
    bool loadFromRenderedText(std::string textureText, SDL_Color textColor);
    void close();
    drawer();
    ~drawer();
};

