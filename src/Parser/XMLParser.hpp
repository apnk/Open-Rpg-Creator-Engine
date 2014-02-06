#ifndef _XMLPARSER_HPP
#define	_XMLPARSER_HPP

#include <iostream>
#include "../Game.hpp"
#include "../Map/Map.hpp"
#include "../Utils/GameData.hpp"

class Map;
class Game;

class XMLParser{
public:
    virtual ~XMLParser(){};
    virtual MapData* parseMap(std::string mapName) = 0;
    virtual GameData* parseGame(std::string gameName) = 0;
};


#endif

