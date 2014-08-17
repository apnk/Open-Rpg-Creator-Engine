#ifndef _DISPLAY_HPP_
#define _DISPLAY_HPP_

#include "Map/Map.hpp"

class Map;

class Display {
private:

	static Display* INSTANCE;

	Map* map;
	SDL_Surface* screen;
	std::string gameTitle;
	SDL_Rect screenBorder;

	Display();

public:
	static Display* getInstance();
	void setMap(Map* map);
	virtual ~Display();
	void setGameTitle(std::string gameTitle);
	void renderFrame(Player* player);
	//void drawNpcs(ObjectsContainer<Npc*>* npcs, SDL_Surface* destination, int playerX, int playerY, SDL_Rect* clip);
};


//void drawImage(int x, int y, SDL_Surface* image, SDL_Surface* destination, SDL_Rect* clip);
//void drawNpcs(ObjectsContainer<Npc*>* npcs, SDL_Surface* destination, int playerX, int playerY, SDL_Rect* clip);
//void printString(int x, int y, std::string text, SDL_Surface* screen);


#endif
