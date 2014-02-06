#ifndef _DOOR_HPP_
#define _DOOR_HPP_

#include <iostream>

class Door {

private:
	int doorX;
	int doorY;
	std::string mapName;

public:
	Door(int x, int y, std::string map) :
			doorX(x), doorY(y), mapName(map) {
	}
	std::string getMapName() {
		return mapName;
	}
	bool checkX(int x) {
		return x == doorX;
	}
	bool checkY(int y) {
		return y == doorY;
	}
};

#endif
