#include <string>
#include "Player.hpp"
#include "CharacterBoundingBox.hpp"
#include "CharacterCoordinates.hpp"
#include "Character.hpp"

Player* Player::mInstance = 0;

Player::Player(std::string imageFileName, std::string charName, CharacterCoordinates* coor,
                CharacterBoundingBox* bound):Character(imageFileName, charName, coor, bound){
}

Player* Player::initAndGetInstance(std::string imageFileName, std::string charName, CharacterCoordinates* coor, CharacterBoundingBox* bound) {
    mInstance = new Player(imageFileName, charName, coor, bound);
    return mInstance;
}

bool Player::isInit(){
	return mInstance == 0;
}

Player* Player::getInstance() {
	return mInstance;
}

void Player::clear(){
    mInstance = 0;
}
