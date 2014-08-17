#ifndef _DRAW_H_
#define _DRAW_H_

#include <vector>
#include <iostream>
#include <SDL/SDL.h>
#include "../Character/Npc.hpp"
#include "../Utils/ObjectsContainer.hpp"

SDL_Surface* loadImage(std::string);
SDL_Surface* createEmptySurface(int, int);
void drawImage(int x, int y, SDL_Surface* image, SDL_Surface* destination, SDL_Rect* clip);	
void drawNpcs(ObjectsContainer<Npc*>* npcs, SDL_Surface* destination, int playerX, int playerY, SDL_Rect* clip);
void printString(int x, int y, std::string text, SDL_Surface* screen);

#endif
