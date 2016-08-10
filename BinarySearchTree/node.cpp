#include <iostream>
#include "node.h"

Node::Node() {
	value = 0;
	left = NULL;
	right = NULL;
}

Node::~Node() {
	right = NULL;
	left = NULL;
}

void Node::setValue(int newvalue) {
	value = newvalue;
}

int Node::getValue() {
	return value;
}

void Node::setLeft(Node* newleft) {
	left = newleft;
}

Node* Node::getLeft() {
	return left;
}
void Node::setRight(Node* newright) {
	right = newright;
}

Node* Node::getRight() {
	return right;
}

