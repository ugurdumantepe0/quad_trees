#include "RectangleXY.h"




RectangleXY::RectangleXY() {
	top = -1;
	bottom = -1;
	left = -1;
	right = -1;
}

RectangleXY::RectangleXY(int top, int left, int bottom, int right) {
	this->top = top;
	this->left = left;
	this->bottom = bottom;
	this->right = right;
}

int RectangleXY::getTop() { return top; }
int RectangleXY::getBottom() { return bottom; }
int RectangleXY::getLeft() { return left; }
int RectangleXY::getRight() { return right; }




RectangleXY::~RectangleXY()
{



}

std::ostream & operator<<(std::ostream &os, const RectangleXY& p)
{
	os << p.top << " " << p.left << " " << p.bottom << " " << p.right << std::endl;
	return os;
}


bool RectangleXY::containsPoint(Point point) {
	if (top <= point.y && point.y < bottom && left <= point.x && point.x < right)
		return true;
	else
		return false;


}