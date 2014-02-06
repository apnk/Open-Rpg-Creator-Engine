#include <math.h>
#include <iostream>
#include "CharacterCoordinates.hpp"
#include "../Utils/common.hpp"
#include "../Utils/other.hpp"

CharacterCoordinates::CharacterCoordinates(int x, int y, int normalSpeed,
		int runSpeed) :
		x(x), y(y), normalSpeed(normalSpeed), runSpeed(runSpeed) {
	currentDirection = DOWN;
}

Direction CharacterCoordinates::getDirection(){
	return currentDirection;
}

void CharacterCoordinates::setDirection(Direction dir){
    currentDirection = dir;
}
void CharacterCoordinates::move(Direction dir, bool run) {
	int move = run ? runSpeed : normalSpeed;
	setDirection(dir);
	switch (dir) {
	case DOWN:
		y += move;
		break;
	case UP:
		y -= move;
		break;
	case LEFT:
		x -= move;
		break;
	case RIGHT:
		x += move;
		break;
	}
}

int CharacterCoordinates::getX() {
	return x;
}

int CharacterCoordinates::getY() {
	return y;
}

int CharacterCoordinates::getTileX(bool forwarding=false) {
	return pixelsToTile(x+forwarding) + 1;
}

int CharacterCoordinates::getTileY(bool forwarding=false) {
	return pixelsToTile(y+forwarding) + 1;

}
