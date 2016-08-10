#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

class Node{
	public:
		Node();
		~Node();
		void setValue(int value);
		int getValue();
		void setColor(char color);
		char getColor();
		void setRight(Node* newright);
		Node* getRight();
		void setLeft(Node* newleft);
		Node* getLeft();
		void setParent(Node* newparent);
		Node* getParent();
	private:
		int value;
		char color;
		Node* right;
		Node* left;
		Node* parent;
};
#endif

