#pragma once
#include "RectangleXY.h"
#include <stdexcept>


#ifndef LinkedListRectangle_h
#define LinkedListRectangle_h


using namespace std;


struct Node {
	Node *next;
	RectangleXY data;
};
class LinkedListRectangle {
private:
	Node* topElement;
	Node* lastElement;
	Node *currentElement;
public:
	LinkedListRectangle();

	// reset iterator to the beginning position of the list
	void resetIterator();
	
	// move list to one step ahead
	void next();

	// get current element
	RectangleXY getCurrent();
	
	// push element
	void push(RectangleXY val);

	// pop element from stack    
	void pop();

	// top of the stack
	RectangleXY top();

	// size of the stack
	int size();

	// destroy the stack
	~LinkedListRectangle();

};

#endif 
