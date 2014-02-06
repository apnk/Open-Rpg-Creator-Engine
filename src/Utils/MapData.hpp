#ifndef _MAPDATA_HPP
#define	_MAPDATA_HPP

#include "../Character/Npc.hpp"
#include "ObjectsContainer.hpp"

class MapData {
private:
    std::string mapName;
    SDL_Surface* lowerSurface;
    SDL_Surface* higherSurface;
    Wall* mapWalls;
    int mapWidth;
    int mapHeight;
    ObjectsContainer<Npc*>* mapNpcs;

public:

    void setMapName(std::string& name) {
        mapName = name;
    }

    std::string getMapName() {
        return mapName;
    }

    void setLowerSurface(SDL_Surface* surface) {
        lowerSurface = surface;
    }

    SDL_Surface* getLowerSurface() {
        return lowerSurface;
    }

    void setHigherSurface(SDL_Surface* surface) {
        higherSurface = surface;
    }

    SDL_Surface* getHigherSurface() {
        return higherSurface;
    }

    void setWalls(Wall* walls) {
        mapWalls = walls;
    }

    Wall* getWalls() {
        return mapWalls;
    }

    void setMapWidth(int width) {
        mapWidth = width;
    }

    int getMapWidth() {
        return mapWidth;
    }

    void setMapHeight(int height) {
        mapHeight = height;
    }

    int getMapHeight() {
        return mapHeight;
    }

    void setNpcs(ObjectsContainer<Npc*>* npcs) {
        mapNpcs = npcs;
    }

    ObjectsContainer<Npc*>* getNpcs() {
        return mapNpcs;
    }
};

#endif

