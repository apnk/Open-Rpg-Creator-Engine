#ifndef _MAP_HPP_
#define _MAP_HPP_

#include <map>
#include "Wall.hpp"
#include <SDL/SDL.h>
#include "../Utils/MapData.hpp"
#include "../Utils/other.hpp"
#include "../Character/Player.hpp"
#include "../Character/Character.hpp"
#include "../Parser/XMLParser.hpp"
#include "../Utils/ObjectsContainer.hpp"

class XMLParser;

class Map {
    private:
        Wall* walls;
        int mapWidth;
        int mapHeight;
        int mapWidthTiles;
        int mapHeightTiles;
        std::string mapName;
        SDL_Surface* lowerSurface;
        SDL_Surface* higherSurface;
        ObjectsContainer<Npc*>* npcContainer;
        std::map<std::pair<int, int>, std::string> *doors;
        
        bool checkWallCollision(int x, int y, Direction direction);
        bool checkMapBorderCollision(int x, int y);
        void checkDoor(Character* character, Direction direction);
        
    public:
        void nextFrame();
        Map(MapData* mapData);
        SDL_Surface* getLowerSurface();
        SDL_Surface* getHigherSurface();
        ObjectsContainer<Npc*>* getNpcContainer();
        bool checkCollision(Player* player, Direction direction, bool isRunning);
};


#endif
