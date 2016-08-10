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
		void setRight(Node* newright);
		Node* getRight();
		void setLeft(Node* newleft);
		Node* getLeft();
	private:
		int value;
		Node* right;
		Node* left;
};
#endif
