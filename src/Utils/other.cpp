#include "other.hpp"
#include <stdlib.h>
#include <math.h>
#include "common.hpp"

int randomNumber(int n) {
	//srand(time(NULL));
	return rand() % n;
}
;

int tilesToPixels(int tile) {
	return floor(tile * TILE_DIMENSION);
}
;

int pixelsToTile(int pixels) {
	return floor(pixels / TILE_DIMENSION);
}
;

//Zwraca górny lewy róg grafiki gracza
int getScreenCenterX() {
	return SCREEN_WIDTH / 2;// - TILE_DIMENSION / 2;
}
;

//Zwraca górny lewy róg grafiki gracza
int getScreenCenterY() {
	return SCREEN_HEIGHT / 2;// - TILE_DIMENSION / 2;
}

int calculateNpcX(int npcX, int playerX) {
	int centerX = getScreenCenterX();
	int newX = npcX - playerX;
	return centerX + newX;
}
;

int calculateNpcY(int npcY, int playerY) {
	int centerY = getScreenCenterY();
	int newY = npcY - playerY;
	return centerY + newY;
}
;
