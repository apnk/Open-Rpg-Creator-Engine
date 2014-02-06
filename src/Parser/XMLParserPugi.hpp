#ifndef _XMLPARSERPUGI_HPP
#define	_XMLPARSERPUGI_HPP

#include "pugixml.hpp"
#include "XMLParser.hpp"
#include "../Utils/MapData.hpp"
#include "../Utils/GameData.hpp"

class XMLParserPugi : public XMLParser {
private:
    pugi::xml_document xmlFile;
    void loadFile(std::string fileName);
    int getTileX(const pugi::xpath_node *it);
    int getTileY(const pugi::xpath_node *it);
    Player* parsePlayer(std::string playerFilePath);
    int getIntegerAttribute(pugi::xpath_node node, std::string attribute);
    std::string getStringAttribute(pugi::xpath_node node, std::string attribute);
public:
    MapData* parseMap(std::string mapFilePath);
    GameData* parseGame(std::string gameFilePath);
};

#endif

