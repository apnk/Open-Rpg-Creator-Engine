#ifndef GAME_HPP_
#define GAME_HPP_

#include <string>
#include "Map/Map.hpp"
#include "Utils/Timer.hpp"
#include "Character/Player.hpp"
#include "Parser/XMLParser.hpp"
#include "Display.hpp"
#include <SDL/SDL.h>

class Map;
class XMLParser;
class Display;

class Game {
private:
    static Game* INSTANCE;
    static const std::string GAME_TITLE;
    static const std::string SETTINGS_FILE;
    
    Map* map;
    Timer timer;
    Player *player;
    SDL_Event event;
    Uint8 *keystates;
    Display* display;
    SDL_Surface* screen;
    XMLParser* xmlParser;
    SDL_Rect screenBorder;
    
    Game();
    bool isSet();
    bool isRunning;
    void handleTimer();
    void handleEvents();
    void handleArrows();
    void handleKeyboard();
    void movePlayer(Direction, bool);
    void setPlayerInStandingPosition();
    
public:
    void run();
    static Game& getInstance();
    friend class XMLParser;
    friend class ResourceParser;
};

#endif
