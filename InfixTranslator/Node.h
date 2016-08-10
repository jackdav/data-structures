#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

class Node{
	public:
		Node();
		~Node();
		char getValue();
		void setLeft(Node*);
		void setRight(Node*);
		Node* getLeft();
		Node* getRight();
		void setValue(char);
	private:
		Node* right;
		Node* left;
		char value;
};
#endif