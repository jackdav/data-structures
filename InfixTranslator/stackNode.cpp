#include <iostream>
#include "stackNode.h"
#include "Node.h"

stackNode::stackNode() {
	value = 0;
	next = NULL;
}

stackNode::~stackNode() {
	delete value;
	next = NULL;
}

void stackNode::setValue(Node* newNode) {
	value = newNode;
}

Node* stackNode::getValue() {
	return value;
}

void stackNode::setNext(stackNode* newNext) {
	next = newNext;
}

stackNode* stackNode::getNext() {
	return next;
}

