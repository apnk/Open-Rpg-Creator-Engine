#ifndef CHARACTERANIMATION_HPP_
#define CHARACTERANIMATION_HPP_

#include <SDL/SDL.h>
#include <string>

#include "../Utils/common.hpp"

/*
 * Klasa zarządza animacją
 */
class CharacterAnimation {
private:
	int mActualFrame;			//Licznik aktualnej klatki animacji
	SDL_Surface* mImage;		//Warstwa zawierająca wszytskie animacje
	SDL_Surface* mFrames[12];	//Tablica pojedynczych animacji ruchu

public:
	SDL_Surface* getFrame(Direction);			//Metoda pobiera aktualną klatkę animacji
	void nextFrame();		//Metoda pobiera kolejną klatkę animacji
	void setFrame(int);
	CharacterAnimation(std::string filename);	//Konstruktor
};
#endif
