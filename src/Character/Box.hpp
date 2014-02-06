#ifndef _BOX_HPP_
#define _BOX_HPP_

class Box{

private:
	int shiftX;
	int shiftY;
	int width;
	int height;

public:

	Box(int x, int y, int w, int h){
		shiftX = x;
		shiftY = y;
		width = w;
		height = h;
	}

	int getXShift(){
		return shiftX;
	}

	int getYShift(){
		return shiftY;
	}

	int getWidth(){
		return width;
	}

	int getHeight(){
		return height;
	}
};

#endif
