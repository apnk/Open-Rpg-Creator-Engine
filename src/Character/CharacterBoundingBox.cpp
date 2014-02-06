#include "CharacterBoundingBox.hpp"
#include "Box.hpp"

CharacterBoundingBox::CharacterBoundingBox(Box &down, Box &left, Box &right, Box &up){

	*box[2] = right;
	*box[3] = up;
	*box[0] = down;
		*box[1] = left;
}

Box CharacterBoundingBox::getBox(Direction direction){
	return *box[direction];
}
