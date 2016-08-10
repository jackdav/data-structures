#include <iostream>
#include "Node.h"

Node::Node() {
	value = 0;
	color = 'r';
	left = NULL;
	right = NULL;
	parent = NULL;
}

Node::~Node() {
	right = NULL;
	left = NULL;
	parent = NULL;
}

void Node::setValue(int newvalue) {
	value = newvalue;
}

int Node::getValue() {
	return value;
}

void Node::setColor(char newColor) {
	color = newColor;
}

char Node::getColor() {
	return color;
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
void Node::setParent(Node* newparent) {
	parent = newparent;
}

Node* Node::getParent() {
	return parent;
}