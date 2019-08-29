#pragma once


#ifndef TwoDimTreeNode_h
#define TwoDimTreeNode_h


#include "RectangleXY.h"
#include "LinkedListRectangle.h"
#include "Point.h"




enum Direction { XCenter, YCenter, topLeft, topRight, bottomRight, bottomLeft };



class TwoDimTreeNode
{

private: 
	
	RectangleXY extent; 
	
	Point center;
	
	LinkedListRectangle verticalList, horizontalList;
	
	// 4 quadrants
	TwoDimTreeNode *topLeftNode, *topRightNode, *bottomLeftNode, *bottomRightNode;
	
	// this is for debugging
	void printExtent();

	// this is for debugging
	string getStringFromEnum(Direction direction);

	// get quadrant from the extent according to the Enum Direction
	RectangleXY getQuadrant(Direction direction);

	// check if extent intersects with point
	bool intersectWithPoint(Point point, Direction direction);

	// check if extent intersects with rectangle
	bool intersectWithRectangle(RectangleXY rectangle, Direction direction);

public:

	LinkedListRectangle* getRectanglesForPoint(Point point, LinkedListRectangle* resultingList);

	// this is for debugging
	void query();

	// push rectangle that will be searched
	Direction push(RectangleXY rectangle);

	TwoDimTreeNode(RectangleXY rectangle);
	~TwoDimTreeNode();
};

#endif