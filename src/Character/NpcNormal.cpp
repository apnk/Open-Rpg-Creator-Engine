/*
 * NpcNormal.cpp
 *
 *  Created on: 21 lip 2013
 *      Author: apnk
 */

#include "NpcNormal.hpp"

NpcNormal::NpcNormal(std::string imageFileName, std::string charName, CharacterCoordinates* coor, CharacterBoundingBox* bound) : Npc(imageFileName, charName, coor, bound){

}

ActionSet NpcNormal::startAction(){
	return ActionSet();
}
