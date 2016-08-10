#ifndef STACKNODE_H
#define STACKNODE_H
#include <iostream>
#include "Node.h"

using namespace std;

class stackNode{
	public:
		stackNode();
		~stackNode();
		void setValue(Node* newNode);
		Node* getValue();
		void setNext(stackNode* newNext);
		stackNode* getNext();
	private:
		Node* value;
		stackNode* next;
};
#endif