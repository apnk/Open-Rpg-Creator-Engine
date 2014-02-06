#ifndef NPCCONTAINER_HPP_
#define NPCCONTAINER_HPP_

#include <vector>
#include "../Character/Npc.hpp"

template <class T>
class ObjectsContainer{
private:
	std::vector<T> *objects;
public:
	void addObject(T object){
		objects->push_back(object);
	}
	ObjectsContainer<T>(){
		objects = new std::vector<T>();
	}
	std::vector<T> *getVectorOfObjects(){
		return objects;
	}
};


#endif /* NPCCONTAINER_HPP_ */
