#ifndef _CHARACTER_HPP_
#define _CHARACTER_HPP_

#include <string>
#include <SDL/SDL.h>
#include "../Utils/common.hpp"
#include "CharacterAnimation.hpp"
#include "CharacterBoundingBox.hpp"
#include "CharacterCoordinates.hpp"

class Character {
protected:
    std::string name;
    CharacterAnimation* mAnimation;
    CharacterCoordinates* mCoordinates;
    CharacterBoundingBox* mBoundingBox;

public:
    void stand();
    void rotate(Direction dir);
    void move(Direction, bool);
    SDL_Surface* getImage();
    Direction getDirection();
    CharacterBoundingBox getBoundingBox(Direction);
    Character(std::string, std::string, CharacterCoordinates*, CharacterBoundingBox*);

    int getX() {
        return mCoordinates->getX();
    }

    int getY() {
        return mCoordinates->getY();
    }

    int getTileX(int forward = 0) {
        return mCoordinates->getTileX(forward);
    }

    int getTileY(int forward = 0) {
        return mCoordinates->getTileY(forward);
    }
};


#endif
