#include <iostream>
#include <SDL/SDL.h>
#include "pugixml.hpp"
#include "XMLParserPugi.hpp"
#include "../Utils/common.hpp"
#include "../Utils/other.hpp"
#include "../Display/draw.hpp"
#include "../Character/NpcNormal.hpp"

class Map;


void XMLParserPugi::loadFile(std::string fileName) {
    xmlFile.load_file(fileName.c_str());
}

MapData* XMLParserPugi::parseMap(std::string mapFilePath) {
    loadFile("maps/" + mapFilePath + ".xml");
    pugi::xpath_node dim = xmlFile.select_single_node("map/dim");
    int mapWidth = getIntegerAttribute(dim, "width");
    int mapHeight = getIntegerAttribute(dim, "height");
    SDL_Surface* layer1 = createEmptySurface(tilesToPixels(mapWidth), tilesToPixels(mapHeight));
    SDL_Surface* layer2 = createEmptySurface(tilesToPixels(mapWidth), tilesToPixels(mapHeight));
    pugi::xpath_node tset = xmlFile.select_single_node("map/tileset");
    std::string tilesetName = getStringAttribute(tset, "name");
    SDL_Surface* tileset = loadImage("images/tilesets/" + tilesetName + ".png");
    std::cout << "images/tilesets/" + tilesetName + ".png" << std::endl;
    pugi::xpath_node_set l1set = xmlFile.select_nodes("map/layer1/t");
    pugi::xpath_node_set l2set = xmlFile.select_nodes("map/layer2/t");
    pugi::xpath_node_set l3set = xmlFile.select_nodes("map/layer3/t");
    pugi::xpath_node_set l4set = xmlFile.select_nodes("map/layer4/t");
    pugi::xpath_node_set::const_iterator l1 = l1set.begin();
    pugi::xpath_node_set::const_iterator l2 = l2set.begin();
    pugi::xpath_node_set::const_iterator l3 = l3set.begin();
    pugi::xpath_node_set::const_iterator l4 = l4set.begin();
    SDL_Rect tile;
    tile.w = TILE_DIMENSION;
    tile.h = TILE_DIMENSION;
    
    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            tile.y = getTileY(l1);
            tile.x = getTileX(l1);
            drawImage(tilesToPixels(x), tilesToPixels(y), tileset, layer1, &tile);
            tile.y = getTileY(l2);
            tile.x = getTileX(l2);
            drawImage(tilesToPixels(x), tilesToPixels(y), tileset, layer1, &tile);
            tile.y = getTileY(l3);
            tile.x = getTileX(l3);
            drawImage(tilesToPixels(x), tilesToPixels(y), tileset, layer2, &tile);
            tile.y = getTileY(l4);
            tile.x = getTileX(l4);
            drawImage(tilesToPixels(x), tilesToPixels(y), tileset, layer2, &tile);
            l1++;
            l2++;
            l3++;
            l4++;
        }
    }
    
    Wall* walls = new Wall();
    pugi::xpath_node_set wall = xmlFile.select_nodes("map/wall/w");
    for(pugi::xpath_node_set::const_iterator wallIt = wall.begin(); wallIt != wall.end(); wallIt++) {
        int x = getIntegerAttribute(*wallIt, "x");
        int y = getIntegerAttribute(*wallIt, "y");
        walls->addWall(x,y);
    }

    ObjectsContainer<Npc*>* npcContainer = new ObjectsContainer<Npc*>();
    pugi::xpath_node_set npcs = xmlFile.select_nodes("map/npc/n");
    for(pugi::xpath_node_set::const_iterator npcsIt = npcs.begin(); npcsIt != npcs.end(); npcsIt++){
    	int x = getIntegerAttribute(*npcsIt, "x");
    	int y = getIntegerAttribute(*npcsIt, "y");
    	std::string image = getStringAttribute(*npcsIt, "img");

    	std::string name = getStringAttribute(*npcsIt, "name");
    	CharacterCoordinates* coord = new CharacterCoordinates(x, y, 4, 8);
    	Npc* npc = new NpcNormal(image, name, coord, 0);
    	npcContainer->addObject(npc);
    }
    MapData* mapData = new MapData();
    mapData->setLowerSurface(layer1);
    mapData->setHigherSurface(layer2);
    mapData->setMapHeight(mapHeight);
    mapData->setMapWidth(mapWidth);
    mapData->setMapName(mapFilePath);
    mapData->setWalls(walls);
    mapData->setNpcs(npcContainer);
    return mapData;
}

int XMLParserPugi::getTileX(const pugi::xpath_node *it) {
    return tilesToPixels((atoi((*it).node().attribute("n").value()) - 1) % 8);
}

int XMLParserPugi::getTileY(const pugi::xpath_node *it) {
    return tilesToPixels((atoi((*it).node().attribute("n").value()) - 1) / 8);
}

GameData* XMLParserPugi::parseGame(std::string gameFilePath) {
    loadFile(gameFilePath);
        pugi::xpath_node initMap = xmlFile.select_single_node("settings/initmap");

    pugi::xpath_node initPlayer = xmlFile.select_single_node("settings/player");
    std::string playerName = getStringAttribute(initPlayer, "name");
    std::string playerGraphic = getStringAttribute(initPlayer, "graphics");
    int startX = getIntegerAttribute(initPlayer, "playerx");
    int startY = getIntegerAttribute(initPlayer, "playery");
    int playerNormalSpeed = getIntegerAttribute(initPlayer, "normalspeed");
    int playerRunSpeed = getIntegerAttribute(initPlayer, "runspeed");
    CharacterCoordinates* coord = new CharacterCoordinates(startX, startY,
            playerNormalSpeed, playerRunSpeed);

    pugi::xpath_node playerBox = xmlFile.select_single_node("settings/bup");
    Box* upBox = new Box(getIntegerAttribute(playerBox, "x"),
                         getIntegerAttribute(playerBox, "y"),
                         getIntegerAttribute(playerBox, "w"),
                         getIntegerAttribute(playerBox, "h"));

    playerBox = xmlFile.select_single_node("settings/bdown");
    Box* downBox = new Box(getIntegerAttribute(playerBox, "x"),
                           getIntegerAttribute(playerBox, "y"),
                           getIntegerAttribute(playerBox, "w"),
                           getIntegerAttribute(playerBox, "h"));

    playerBox = xmlFile.select_single_node("settings/bright");
    Box* rightBox = new Box(getIntegerAttribute(playerBox, "x"),
                            getIntegerAttribute(playerBox, "y"),
                            getIntegerAttribute(playerBox, "w"),
                            getIntegerAttribute(playerBox, "h"));

    playerBox = xmlFile.select_single_node("settings/bleft");
    Box* leftBox = new Box(getIntegerAttribute(playerBox, "x"),
                           getIntegerAttribute(playerBox, "y"),
                           getIntegerAttribute(playerBox, "w"),
                           getIntegerAttribute(playerBox, "h"));

    //CharacterBoundingBox *bound = new CharacterBoundingBox(*downBox, *leftBox,
    //*rightBox, *upBox);
    Player::initAndGetInstance("images/characters/" + playerGraphic + ".png", playerName,
                               coord, 0);
    Player* player = Player::getInstance();


    MapData* map = parseMap(getStringAttribute(initMap, "name"));
    
    GameData* gameData = new GameData();
    gameData->setMap(map);
    gameData->setPlayer(player);
    return gameData;
}

int XMLParserPugi::getIntegerAttribute(pugi::xpath_node node, std::string attribute){
    return atoi(node.node().attribute(attribute.c_str()).value());
}

std::string XMLParserPugi::getStringAttribute(pugi::xpath_node node, std::string attribute){
    return node.node().attribute(attribute.c_str()).value();
}
