#ifndef CHARACTERBOUNDINGBOX_HPP_
#define CHARACTERBOUNDINGBOX_HPP_

#include "Box.hpp"
#include "../Utils/common.hpp"

/**
 * Klasa odpowiedzialna za zarządzenia boxami
 * do detekcji kolizji
 */
class CharacterBoundingBox{
private:
	Box *box[4];

public:
	CharacterBoundingBox(Box&, Box&, Box&, Box&);
	Box getBox(Direction);
};

#endif
