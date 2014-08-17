#include "draw.hpp"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "../Utils/other.hpp"
#include "../Character/Npc.hpp"

void drawImage(int x, int y, SDL_Surface* image, SDL_Surface* destination, SDL_Rect* clip = 0) {
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(image, clip, destination, &offset);
}

SDL_Surface* loadImage(std::string filename) {
    SDL_Surface* loadedImage = 0;
    SDL_Surface* optimizedImage = 0;
    loadedImage = IMG_Load(filename.c_str());
    if (loadedImage != 0) {
        optimizedImage = SDL_DisplayFormat(loadedImage);
        if (optimizedImage != 0) {
            //Invisible color R-236, G-0, B-140
            Uint32 colorkey = SDL_MapRGB(optimizedImage->format, 255, 255, 255);
            SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorkey);
        }
        SDL_FreeSurface(loadedImage);
        return optimizedImage;
    } else {
        std::cout << "Błąd!! Nie udało się wczytać pliku graficznego " << filename << std::endl;
        return 0;
    }
}

SDL_Surface* createEmptySurface(int width, int height) {
    return SDL_CreateRGBSurface(SDL_SWSURFACE, width, height,
            32, 0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff);
}
