#ifndef _CHARACTERCOORDINATES_HPP_
#define _CHARACTERCOORDINATES_HPP_

#include "../Utils/common.hpp"

class CharacterCoordinates {
private:
    int x, y;
    int normalSpeed;
    int runSpeed;
    Direction currentDirection;

public:
    void setDirection(Direction direction);
    CharacterCoordinates(int x, int y, int normalSpeed, int runSpeed);
    void move(Direction direction, bool isRunning);
    Direction getDirection();
    int getX();
    int getY();
    int getTileX(bool forwarding);
    int getTileY(bool forwarding);
};

#endif
