#include <SDL/SDL.h>
#include <string>
#include "CharacterAnimation.hpp"
#include "../Display/draw.hpp"
#include "../Utils/common.hpp"

SDL_Surface* CharacterAnimation::getFrame(Direction dir){
	return mFrames[dir*CHARSET_ANIMATION_COLUMNS + mActualFrame];
}

void CharacterAnimation::nextFrame(){
	mActualFrame = (mActualFrame+1)%CHARSET_ANIMATION_COLUMNS;
}

void CharacterAnimation::setFrame(int frameNumber){
	mActualFrame = frameNumber;
}

CharacterAnimation::CharacterAnimation(std::string filename){
	mActualFrame = 0;
	mImage = loadImage(filename);
	SDL_Rect tile;
	tile.w = CHARSET_WIDTH;
	tile.h = CHARSET_HEIGHT;
	for(int y = 0; y < CHARSET_ANIMATION_ROWS; y++){
		for(int x = 0; x < CHARSET_ANIMATION_COLUMNS; x++){
			mFrames[y*CHARSET_ANIMATION_COLUMNS+x] = createEmptySurface(CHARSET_WIDTH, CHARSET_HEIGHT);
			tile.x = x*CHARSET_WIDTH;
			tile.y = y*CHARSET_HEIGHT;
			drawImage(0, 0, mImage, mFrames[y*CHARSET_ANIMATION_COLUMNS+x], &tile);
		}
	}
}
