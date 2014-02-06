#include <string>
#include <iostream>
#include "Character.hpp"
#include "CharacterBoundingBox.hpp"

void Character::move(Direction dir, bool run){
	mCoordinates->move(dir, run);
	mAnimation->nextFrame();
}

void Character::rotate(Direction dir){
    mCoordinates->setDirection(dir);
    mAnimation->nextFrame();
}

void Character::stand(){
	mAnimation->setFrame(1);
}

Character::Character(std::string imageFileName, std::string charName, CharacterCoordinates* coor, CharacterBoundingBox* bound){
	name = charName;
	mAnimation = new CharacterAnimation(imageFileName);
	mCoordinates = coor;
	mBoundingBox = bound;
}

SDL_Surface* Character::getImage(){
	return mAnimation->getFrame(getDirection());
}

Direction Character::getDirection(){
	return mCoordinates->getDirection();
}
