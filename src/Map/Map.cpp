#include <math.h>
#include "Map.hpp"
#include "../Utils/common.hpp"
#include "../Character/Player.hpp"
#include "../Parser/ResourceParser.hpp"
#include "../Character/CharacterBoundingBox.hpp"

Map::Map(MapData* mapData){
    mapName = mapData->getMapName();
    lowerSurface = mapData->getLowerSurface();
    higherSurface = mapData->getHigherSurface();
    walls = mapData->getWalls();
    doors = 0;
    mapWidthTiles = mapData->getMapWidth();
    mapHeightTiles = mapData->getMapHeight();
    mapWidth = tilesToPixels(mapWidthTiles);
    mapHeight = tilesToPixels(mapHeightTiles);
    npcContainer = mapData->getNpcs();
}

bool Map::checkWallCollision(int x, int y, Direction direction) {
    return walls->checkCollision(x, y, direction);
}

void Map::checkDoor(Character* character, Direction direction) {

}

ObjectsContainer<Npc*>* Map::getNpcContainer(){
	return npcContainer;
}

SDL_Surface* Map::getLowerSurface() {
    return lowerSurface;
}

SDL_Surface* Map::getHigherSurface() {
    return higherSurface;
}

void Map::nextFrame(){
    //poruszyć npc
    //poruszyć animację
}

/**
 * Zwraca true jeżeli jest kolizja, false w przeciwnym wypadku
 */
bool Map::checkMapBorderCollision(int cx, int cy){
    if(cx < 0 || cy < 0 || cx > this->mapWidth - CHARSET_WIDTH || cy > this->mapHeight - CHARSET_HEIGHT){
        return true;
    }else{
        return false;
    }
}

bool Map::checkCollision(Player* player, Direction direction, bool isRunning){
    int playerX = player->getX();
    int playerY = player->getY();
    int step = isRunning ? 8 : 4;
    switch(direction){
        case UP:
            playerY -= step;
        break;
        case DOWN:
            playerY += step;
        break;
        case LEFT:
            playerX -= step;
        break;
        case RIGHT:
            playerX += step;
        break;
    }
    if(checkMapBorderCollision(playerX, playerY)){
        return true;
    }else if(checkWallCollision(playerX, playerY, direction)){
        return true;
    }else{
        return false;
    }
    //Sprawdzić kolizję z NPC
}
