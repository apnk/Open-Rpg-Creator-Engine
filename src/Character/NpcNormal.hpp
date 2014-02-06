#ifndef NPCNORMAL_HPP_
#define NPCNORMAL_HPP_

#include "Npc.hpp"

class NpcNormal : public Npc{
public:
	NpcNormal(std::string, std::string, CharacterCoordinates*, CharacterBoundingBox*);
	ActionSet startAction();
};


#endif
