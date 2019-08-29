#include "TwoDimTreeNode.h"
#include<iostream>
#include <string>
using namespace std;

TwoDimTreeNode::TwoDimTreeNode(RectangleXY rectangle)
{
	extent = rectangle;
	center.x = (extent.getLeft() + extent.getRight()) / 2;
	center.y = (extent.getBottom() + extent.getTop()) / 2;
	

	topLeftNode = nullptr;  
	topRightNode = nullptr; 
	bottomLeftNode = nullptr;  
	bottomRightNode = nullptr; 
	verticalList = LinkedListRectangle();
	horizontalList = LinkedListRectangle();

}


string TwoDimTreeNode::getStringFromEnum(Direction direction) {
	
		switch (direction) {
		case Direction::XCenter:
			return "verticalList";

		case Direction::YCenter:
			return "horizontalList";

		case Direction::topLeft:
			return "topLeft";

		case Direction::topRight:
			return "topRight";


		case Direction::bottomLeft:
			return "bottomLeft";

		case Direction::bottomRight:
			return "bottomRight";

		default:
			return "None text";
		}
	
		return "None text";
}
void TwoDimTreeNode::printExtent() {

	cout << "Extent :  " << extent.getTop() << " " << extent.getLeft() << " " << " " << extent.getBottom() << " " << extent.getRight() << " " << endl;

}

RectangleXY TwoDimTreeNode::getQuadrant(Direction direction) {

	switch (direction) {
	case Direction::topLeft:

		return RectangleXY(extent.getTop(), extent.getLeft(), center.y, center.x);
		break;
	case Direction::topRight:

		return RectangleXY(extent.getTop(), center.x+1, center.y, extent.getRight());
		break;
	case Direction::bottomLeft:

		return RectangleXY(center.y+1, extent.getLeft(), extent.getBottom(), center.x);
		break;
	case Direction::bottomRight:

		return RectangleXY(center.y + 1, center.x + 1, extent.getBottom(), extent.getRight());
		break;
	default:
		throw invalid_argument("wrong Direction value is inputted");
	}
}

bool TwoDimTreeNode::intersectWithRectangle(RectangleXY rectangle, Direction direction) {


	switch (direction) {
	case Direction::topLeft:
		if (rectangle.getLeft() >= extent.getLeft() && center.x > rectangle.getRight() &&
			rectangle.getTop() >= extent.getTop() &&  center.y > rectangle.getBottom() )
			return true;
		break;

	case Direction::topRight:
		if (rectangle.getLeft() >= center.x + 1 && extent.getRight() >= rectangle.getRight() &&
			rectangle.getTop() >= extent.getTop() && center.y > rectangle.getBottom() )
			return true;
		break;


	case Direction::bottomLeft:
		if (rectangle.getLeft() >=  extent.getLeft() && center.x > rectangle.getRight() &&
			rectangle.getTop() >= center.y + 1 && rectangle.getBottom() <= extent.getBottom())
			return true;
		break;
	
	case Direction::bottomRight:
		if (rectangle.getLeft() >= center.x + 1 && extent.getRight() >= rectangle.getRight() &&
			rectangle.getTop() >= center.y + 1 && rectangle.getBottom() <= extent.getBottom())
			return true;
		break;

	case Direction::XCenter:
		if (rectangle.getLeft() <= center.x && center.x <= rectangle.getRight()) {
			return true;
		}
		break;

	case Direction::YCenter:
		if (rectangle.getTop() <= center.y && center.y <= rectangle.getBottom()) {
			return true;
		}
	default:
		return false;
	}
	return false;


}



bool TwoDimTreeNode::intersectWithPoint(Point point, Direction direction) {
	cout << point.x << " " << point.y << endl;


	switch (direction) {
	case Direction::topLeft:
		if (point.x >= extent.getLeft() && center.x > point.x &&
			point.y >= extent.getTop() && point.y < center.y)
			return true;
		break;

	case Direction::topRight:
		if (point.x >= center.x + 1 && extent.getRight() > point.x &&
			point.y >= extent.getTop() && point.y < center.y)
			return true;
		break;


	case Direction::bottomLeft:
		if (point.x >= extent.getLeft() && center.x > point.x &&
			point.y >= center.y + 1 && point.y < extent.getBottom())
			return true;
		break;

	case Direction::bottomRight:
		if (point.x >= center.x + 1 && extent.getRight() > point.x &&
			point.y <= center.y + 1 && point.y < extent.getBottom())
			return true;
		break;
	default:
		return false;
	}


	return false;
}
Direction TwoDimTreeNode::push(RectangleXY rectangle) {
	 

	Direction intersection = static_cast<Direction>(0);
	Direction direction = static_cast<Direction>(-1);
	for (unsigned int i = 0; i < 6; ++i) {
		direction = static_cast<Direction>(i);
		if (this->intersectWithRectangle(rectangle,direction)) {
			intersection = direction;
			break;
		}
	}

	switch (intersection) {
	case Direction::topLeft:

		if (topLeftNode == nullptr) {
			topLeftNode = new TwoDimTreeNode(getQuadrant(Direction::topLeft));
		}
		
		topLeftNode->push(rectangle);
		
		break;
	case Direction::topRight:
		if (topRightNode == nullptr) {
			topRightNode = new TwoDimTreeNode(getQuadrant(Direction::topRight));
		}
		topRightNode->push(rectangle);
		break;
	case Direction::bottomLeft:
		if (bottomLeftNode == nullptr) {
			bottomLeftNode = new TwoDimTreeNode(getQuadrant(Direction::bottomLeft));
		}

		bottomLeftNode->push(rectangle);
		break;

	case Direction::bottomRight:
		if (bottomRightNode == nullptr) {
			bottomRightNode = new TwoDimTreeNode(getQuadrant(Direction::bottomRight));
		}
			
		bottomRightNode->push(rectangle);
		break;

	case Direction::XCenter:
		verticalList.push(rectangle);
		break;

	case Direction::YCenter:

		horizontalList.push(rectangle);
		break;
	default:
		throw invalid_argument("undefined intersection detection");
	}
	return intersection;
}



void TwoDimTreeNode::query() {

	printExtent();

	cout << "vertical List size " << verticalList.size()<< endl;

	for (int i = 0; i < verticalList.size(); ++i) {
		cout << verticalList.getCurrent() << endl;
		verticalList.next();
	}
	verticalList.resetIterator();
	
	cout << "horizontal List size " << horizontalList.size() << endl;

	for (int i = 0; i < horizontalList.size(); ++i) {
		cout << horizontalList.getCurrent() << endl;
		horizontalList.next();
	}
	horizontalList.resetIterator();

	if (topLeftNode != nullptr) {

		topLeftNode->printExtent();

		cout << getStringFromEnum(Direction::topLeft) << endl;

		topLeftNode->query();
	}
	if (topRightNode != nullptr) {

		topRightNode->printExtent();

		cout << getStringFromEnum(Direction::topRight) << endl;

		topRightNode->query();

	}
	if (bottomLeftNode != nullptr) {
		bottomLeftNode->printExtent();

		cout << getStringFromEnum(Direction::bottomLeft) << endl;

		bottomLeftNode->query();

	}
	if (bottomRightNode != nullptr) {

		bottomRightNode->printExtent();

		cout << getStringFromEnum(Direction::bottomRight) << endl;

		bottomRightNode->query();

	}
}


LinkedListRectangle  * TwoDimTreeNode::getRectanglesForPoint(Point point,LinkedListRectangle* resultingList) {



	LinkedListRectangle *temporaryList;


	if (center.x == point.x || center.y == point.y) {
		resultingList->push(extent);
		return resultingList;
	}


	for (int i = 0; i < verticalList.size(); ++i) {

		if (verticalList.getCurrent().containsPoint(point)) {
			resultingList->push(verticalList.getCurrent());
		}
		verticalList.next();
	}
	verticalList.resetIterator();



	for (int i = 0; i < horizontalList.size(); ++i) {

		if (horizontalList.getCurrent().containsPoint(point)) {
			resultingList->push(horizontalList.getCurrent());
		}
		horizontalList.next();
	}
	horizontalList.resetIterator();


	if (topLeftNode != nullptr && getQuadrant(Direction::topLeft).containsPoint(point)) {


		temporaryList =  topLeftNode->getRectanglesForPoint(point, new LinkedListRectangle());
		

		for (int i = 0; i < temporaryList->size(); ++i) {

			if (temporaryList->getCurrent().containsPoint(point)) {
				resultingList->push(temporaryList->getCurrent());
			}
			temporaryList->next();
		}
		temporaryList->resetIterator();
		delete temporaryList;
	
	}



	if (topRightNode != nullptr && getQuadrant(Direction::topRight).containsPoint(point)) {

		temporaryList = topRightNode->getRectanglesForPoint(point, new LinkedListRectangle());


		for (int i = 0; i < temporaryList->size(); ++i) {

			if (temporaryList->getCurrent().containsPoint(point)) {
				resultingList->push(temporaryList->getCurrent());
			}
			temporaryList->next();
		}
		temporaryList->resetIterator();
		delete temporaryList;

	}



	if (bottomLeftNode != nullptr && getQuadrant(Direction::bottomLeft).containsPoint(point)) {

		temporaryList = bottomLeftNode->getRectanglesForPoint(point, new LinkedListRectangle());


		for (int i = 0; i < temporaryList->size(); ++i) {

			if (temporaryList->getCurrent().containsPoint(point)) {
				resultingList->push(temporaryList->getCurrent());
			}
			temporaryList->next();
		}
		temporaryList->resetIterator();
		delete temporaryList;

	}



	if (bottomRightNode != nullptr && getQuadrant(Direction::bottomRight).containsPoint(point)) {

		temporaryList = bottomRightNode->getRectanglesForPoint(point, new LinkedListRectangle());


		for (int i = 0; i < temporaryList->size(); ++i) {

			if (temporaryList->getCurrent().containsPoint(point)) {
				resultingList->push(temporaryList->getCurrent());
			}
			temporaryList->next();
		}
		temporaryList->resetIterator();
		delete temporaryList;

	}


	return resultingList;

}
TwoDimTreeNode::~TwoDimTreeNode()
{
}
