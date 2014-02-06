#ifndef GAMEDATA_HPP
#define	GAMEDATA_HPP

#include "../Character/Player.hpp"
#include "../Map/Map.hpp"

class Map;

class GameData{
private:
    Player* player;
    MapData* map;
    
public:
    void setPlayer(Player* p){
        player = p;
    }
    
    void setMap(MapData* m){
        map = m;
    }
    
    Player* getPlayer(){
        return player;
    }
    
    MapData* getMap(){
        return map;
    }
};

#endif	

