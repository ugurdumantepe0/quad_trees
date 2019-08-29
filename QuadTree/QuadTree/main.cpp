// QuadTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <sstream>
#include <fstream> 
#include <string>
#include "LinkedListRectangle.h"
#include "RectangleXY.h"
#include "TwoDimTreeNode.h"
#include "Point.h"

using namespace std;

int main()
{
	

	std::ifstream inFile("rectdb.txt");
	
	int top, left, bottom, right,x,y;
	istringstream ss;
	string line;
	RectangleXY mainExtent;
	std::getline(inFile, line);
	
	LinkedListRectangle pointList = LinkedListRectangle();
	LinkedListRectangle *foundRectangles;

	// read root extent dimensions
	ss.str(line);
	ss >> top >> left >> bottom >> right;

	mainExtent = RectangleXY(top, left, bottom, right);
	TwoDimTreeNode *rootNode = new TwoDimTreeNode(mainExtent);




	// read rectangles
	while (std::getline(inFile, line))
	{
		ss.clear();
		ss.str(line);

		ss >> top;
		if (top == -1)
			break;
		ss >> left >> bottom >> right;

		rootNode->push(RectangleXY(top, left, bottom, right));
		
	}

	// read points
	while (std::getline(inFile, line))
	{
		ss.clear();
		ss.str(line);

		ss >> x;
		if (x == -1)
			break;
		ss >> y;

		pointList.push(RectangleXY(x, y, 0, 0));

	}


	inFile.close();

	// output
	for (int i = 0; i < pointList.size(); ++i) {
		RectangleXY temp = pointList.getCurrent();
		Point point = Point(temp.getTop(), temp.getLeft());
		foundRectangles = rootNode->getRectanglesForPoint(point, new LinkedListRectangle());

		cout << point.x<< " "<<point.y << endl;
		cout << foundRectangles->size() << endl;;

		for (int i = 0; i < foundRectangles->size(); ++i) {
			cout << foundRectangles->getCurrent();
			foundRectangles->next();
		}
		foundRectangles->resetIterator();
		pointList.next();
	}

		
	cout << "\nprogram ended. press any key ..." << endl;


	getchar();


	delete rootNode;
    return 0;
}

