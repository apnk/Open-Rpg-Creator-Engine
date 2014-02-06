#ifndef OTHER_HPP_
#define OTHER_HPP_

#include <vector>
#include <iostream>

struct Tuple {
	int x, y;
	Tuple(int vx, int vy) :
			x(vx), y(vy) {
	};
};

class KeyPair{
public:
	int key1, key2;
	KeyPair(int k1, int k2){
		key1 = k1; key2 = k2;
	}
	bool operator<(const KeyPair& keys)const{
		return (keys.key1 > key1 && keys.key2 > key2);
	}
};

struct Path {
	std::vector<Tuple> npcPath;
	void addToPath(Tuple tuple) {
		npcPath.push_back(tuple);
	}
};

/** */
int randomNumber(int);
int pixelsToTile(int);
int tilesToPixels(int);
int calculateNpcX(int npcX,int playerX);
int calculateNpcY(int npcY,int playerY);
#endif
