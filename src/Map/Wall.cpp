#include "Wall.hpp"
#include <iostream>
#include "../Utils/other.hpp"
#include "../Utils/common.hpp"

Wall::Wall() {
    wall = new std::multimap <int, int>;
}

Wall::~Wall() {
    delete(wall);
}

void Wall::addWall(int x, int y) {
    wall->insert(std::make_pair(x, y));
}

bool Wall::checkCollision(int x, int y, Direction direction) {
    for (auto mIterator = wall->begin(); mIterator != wall->end(); mIterator++) {
    	std::cout << (mIterator->first == pixelsToTile(x)) << ", " << (mIterator->second == pixelsToTile(y)) << ", " <<  isNotOnCollisionBorder(x, y, direction) << std::endl;
        if (mIterator->first == pixelsToTile(x) && mIterator->second == pixelsToTile(y) && isNotOnCollisionBorder(x, y, direction))
            return true;
    }
    return false;
}

bool Wall::isNotOnCollisionBorder(int x, int y, Direction direction) {
	if(direction == UP || direction == DOWN){
		return (y % TILE_DIMENSION) == 0;
	}else{
		return (x % TILE_DIMENSION) == 0;
	}
}
