#include <iostream>
#include "Node.h"

Node::Node() {
	value = 0;
	right = NULL;
	left = NULL;
}

Node::~Node() {
	right = NULL;
	left = NULL;
}

void Node::setRight(Node* newRight) {
	right = newRight;
}
void Node::setLeft(Node* newLeft){
	left = newLeft;
}
void Node::setValue(char newValue) {
	value = newValue;
}
Node* Node::getRight() {
	return right;
}
Node* Node::getLeft() {
	return left;
}
char Node::getValue() {
	return value;
}
 