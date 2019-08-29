#pragma once


#ifndef RectangleXY_h
#define RectangleXY_h

#include <ostream>
#include "Point.h"

class RectangleXY
{

private: 
	int top; 
	int left; 
	int bottom;
	int right; 

	friend std::ostream & operator<<(std::ostream &os, const RectangleXY& p);
public:

	// check if point is inside of this rectangle
	bool containsPoint(Point point);
	RectangleXY();
	RectangleXY(int top, int left, int bottom, int right);
	int getTop();
	int getBottom();
	int getLeft();
	int getRight();
	~RectangleXY();
};

#endif