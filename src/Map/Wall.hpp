#ifndef _WALL_HPP_
#define _WALL_HPP_

#include <iostream>
#include <map>
#include "../Utils/common.hpp"

class Wall {
private:
    std::multimap<int, int>* wall;
    bool isNotOnCollisionBorder(int x, int y, Direction direction);

public:
    bool checkCollision(int x, int y, Direction direction);
    void addWall(int, int);
    Wall();
    ~Wall();
};

#endif
