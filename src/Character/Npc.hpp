/*
 * Npc.hpp
 *
 *  Created on: 21 lip 2013
 *      Author: apnk
 */

#ifndef NPC_HPP_
#define NPC_HPP_

#include "Character.hpp"
#include "ActionSet.hpp"

class Npc : public Character{
public:
	void randomMove();
	void moveAlongPath();
	virtual ActionSet startAction() = 0;
	virtual ~Npc();
	Npc(std::string imageFileName, std::string charName, CharacterCoordinates* coor, CharacterBoundingBox* bound);
};

#endif /* NPC_HPP_ */
