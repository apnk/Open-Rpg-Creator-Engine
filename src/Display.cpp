#include "Display.hpp"
#include <SDL/SDL.h>
#include "Utils/draw.hpp"
#include <SDL/SDL_ttf.h>

Display* Display::INSTANCE;

Display::Display() {
	SDL_Init(SDL_INIT_EVERYTHING);
	setGameTitle("OpenRpgCreator Engine");
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
	SDL_WM_SetCaption(gameTitle.c_str(), 0);
	TTF_Init();
	screenBorder.w = SCREEN_WIDTH;
	screenBorder.h = SCREEN_HEIGHT;
}

void Display::setMap(Map* map){
	this->map = map;
}

Display::~Display() {
	delete(map);
	delete(screen);
}

void Display::setGameTitle(std::string gameTitle){
	this->gameTitle = gameTitle;
}

void Display::renderFrame(Player* player){
	screenBorder.x = player->getX() - SCREEN_WIDTH / 2;
	screenBorder.y = player->getY() - SCREEN_HEIGHT / 2;
	SDL_FillRect(screen, 0, 0x000000);
	drawImage(0, 0, map->getLowerSurface(), screen, &screenBorder);
	drawImage(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, player->getImage(), screen,
			0);
	drawNpcs(map->getNpcContainer(), screen, player->getX(), player->getY(),
			&screenBorder);
	drawImage(0, 0, map->getHigherSurface(), screen, &screenBorder);
	SDL_Flip(screen);
}

void Display::drawNpcs(ObjectsContainer<Npc*>* npcs, SDL_Surface* destination, int playerX, int playerY, SDL_Rect* clip = 0) {
    std::vector<Npc*>* npcVector = npcs->getVectorOfObjects();
    for (unsigned int i = 0; i < npcVector->size(); i++) {
        int npcX = npcVector->at(i)->getX();
        int npcY = npcVector->at(i)->getY();
        drawImage(calculateNpcX(npcX, playerX), calculateNpcY(npcY, playerY), npcVector->at(i)->getImage(), destination, 0);
    }
}

Display* Display::getInstance(){
	if(INSTANCE == 0){
		INSTANCE = new Display();
	}
	return INSTANCE;
}
