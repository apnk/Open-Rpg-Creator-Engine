#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <string>

#include "Character.hpp"
#include "CharacterBoundingBox.hpp"
#include "CharacterCoordinates.hpp"

class Player : public Character{
protected:
	static Player* mInstance;
	Player(std::string, std::string, CharacterCoordinates*, CharacterBoundingBox*);

public:
	static bool isInit();
	static void clear();
	static Player* getInstance();
	static Player* initAndGetInstance(std::string, std::string, CharacterCoordinates*, CharacterBoundingBox*);
};

#endif
