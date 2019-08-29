#include "LinkedListRectangle.h"
#include<iostream>
//#include <windows.h>
#include <string>
#include <sstream>    

using namespace std;

LinkedListRectangle::LinkedListRectangle() {
	topElement = nullptr;
	lastElement = nullptr;
	currentElement = nullptr;
		 
}
void LinkedListRectangle::push(RectangleXY val) {

	Node  *temp;
	temp = new Node();
	temp->data = val;
	temp->next = nullptr;



	if (topElement == nullptr) {
		topElement = temp;
		lastElement = temp;
		currentElement = temp;
	}
	else {


		lastElement->next = temp;
		lastElement = temp;
	}


}
void LinkedListRectangle::pop() {

	Node  *temp;
	if (topElement == nullptr) {
		throw std::invalid_argument("list is empty");

	}
	else
	{
		temp = topElement;
		topElement = topElement->next;
		currentElement = topElement;
		delete temp;
		temp = nullptr;

	}
}


void LinkedListRectangle::next() {
	if (currentElement != nullptr)
		currentElement = currentElement->next;
	else
		throw std::invalid_argument("reached the end of the list");


}


void LinkedListRectangle::resetIterator() {
	currentElement = topElement;
}
RectangleXY LinkedListRectangle::getCurrent() {
	return currentElement->data;
}

RectangleXY LinkedListRectangle::top() {
	return topElement->data;
}


int LinkedListRectangle::size() {

	int count = 0;
	Node  *temp;
	temp = topElement;
	while (temp != nullptr)
	{
		temp = temp->next;
		count++;
	}
	return count;
}


LinkedListRectangle::~LinkedListRectangle() {

	//OutputDebugStringA(string("destructor " + size() + string(" ... \n")).c_str());
	Node  *temp;
	temp = topElement;

	while (size() != 0)
	{
		stringstream ss;
		//ss<<top();
		//OutputDebugStringA(ss.str().c_str());
		pop();
	}



}
