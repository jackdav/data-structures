#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <iomanip>
#include "Node.h"
#include <algorithm>
#include <queue>
#include <string.h>
#include <fstream>

using namespace std;

void readFile(char*, Node* &);
bool searchTree(int, Node* &);
void printTree(Node* &);
void addNumber(Node* &, int);
void deleteNode(Node* &, int);
void insert1(Node*&);
void insert2(Node*&);
void fixDelete(Node* &);
Node* findNode(Node* &, int);


int main() {
	Node* head = NULL;
	cout << "Enter the root of the tree" << endl;
	int root;
	while (!(cin>>root)) {
		cin.clear();
		cin.ignore(9999, '\n');
		cout << "Please enter a number" << endl;
	}
	cin.ignore(1000, '\n');
	head = new Node();
	head->setValue(root);
	head->setColor('b');
	bool running = true;
	while (running==true) {
		cout << "Commands: " << endl;
		cout << "A = Add a number to the tree" << endl;
		cout << "D = Delete a number from the tree" << endl;
		cout << "R = Read a file for inputs to the tree" << endl;
		cout << "S = Search for a number to see if it is in the tree" << endl;
		cout << "P = Print out a tree representation" << endl;
		cout << "Q = Quit the program (terminates current tree)" << endl;
		char response;
		response = cin.get();
		cin.ignore(10000, '\n');
		tolower(response);
		if (response != 'a' && response != 'd' && response != 'q' && response != 'r' && response != 's' && response != 'p') {
			cout << "Command doesn't work" << endl;
		} 
		else if (response == 'a') {
			cout << "What number would you like to add?" << endl;
			int temp;
			while (!(cin>>temp)) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Please enter a number" << endl;
			}
			cin.ignore(1000, '\n');
			addNumber(head, temp);
		}
		else if (response == 'd') {
			cout << "What number would you like to delete?" << endl;
			int temp;
			while (!(cin>>temp)) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Please enter a number" << endl;
			}
			deleteNode(head, temp);
			cin.ignore(1000, '\n');					
		}
		else if (response == 'r') {
			char* temp = new char[100];
			cout << "What is the file name for which you would like to read in?" << endl;
			cout << "File content requirements: must have all numbers, only seperated by spaces" << endl;
			cin.get(temp, 99);
			cin.ignore(1000, '\n');	
			readFile(temp, head);
		}
		else if (response == 's') {
			int temp;
			cout << "What number would you like to search for" << endl;
			while (!(cin>>temp)) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Please enter a number" << endl;
			}
			cin.ignore(1000, '\n');
			bool read = false;
			//read = searchTree(temp, head);
			if (read == true) {
				cout << "Yes, that number is in the tree" << endl;
			}
			else {
				cout << "No, that number is not in the tree" << endl;
			}
		}
		else if (response == 'p') {
			printTree(head);
		}
		else {
			running = false;
		}
	}
	return 0;
}

void printTree(Node* &head) {
	cout << endl;
    if (head == NULL) {
        return;
    }
    else {
		queue<Node*> currentLevel;
		queue<Node*> nextLevel;
		currentLevel.push(head);
		while (!currentLevel.empty()) {
			Node* currNode = currentLevel.front();
			currentLevel.pop();
			if (currNode) {
				cout << currNode->getValue();
				cout << currNode->getColor() << " ";
				nextLevel.push(currNode->getLeft());
				nextLevel.push(currNode->getRight());
			}
			if (currentLevel.empty()) {
				cout << endl;
				swap(currentLevel, nextLevel);
			}
		}
	}
}


bool searchTree(Node* &head, int num) {
	if (head == NULL) {
		return false;
	}
	Node* trailling;
	Node* travel = head;
	if (head->getValue() == num) {
		return true;
	}
	while (travel != NULL) {
		if (travel->getValue() != num && travel->getValue() > num) {
			trailling = travel;
			travel = travel->getLeft();
		}
		else if (travel->getValue() != num && travel->getValue() < num) {
			trailling = travel;
			travel = travel->getRight();
		}
		else {
			return true;
		}
	}
	return false;
}

void readFile(char* array, Node* &head) {
	char* filename = array;
	strcat(filename, ".txt");
	ifstream myReadFile;
	myReadFile.open(filename);
	int num[50];
	int n = 0;
	while (!myReadFile.eof()) {
		myReadFile >> num[n];
		addNumber(head, num[n]);
		n++;
	}
	myReadFile.close();
}

void addNumber(Node* &head, int num) {
	Node* trail;
	Node* carry = head;
	if (head == NULL) {
		head = new Node();
		head->setValue(num);
		head->setColor('b');
		insert1(head);
	}
	else if (carry->getValue() > num && carry->getLeft() == NULL) {
		carry->setLeft(new Node());
		carry->getLeft()->setValue(num);
		carry->getLeft()->setParent(carry);
		if (carry->getLeft()->getParent()->getColor() == 'r') {
			carry->getLeft()->setColor('b');
		}
		Node* temp = new Node();
		temp = carry->getLeft();
		insert1(temp);
	}
	else if (carry->getValue() < num && carry->getRight() == NULL) {
		carry->setRight(new Node());
		carry->getRight()->setValue(num);
		carry->getRight()->setParent(carry);
		if (carry->getRight()->getParent()->getColor() == 'r') {
			carry->getRight()->setColor('b');
		}
		Node* temp = new Node();
		temp = carry->getRight();
		insert1(temp);
	}
	else if (carry->getValue() > num && carry->getLeft() != NULL) {
		carry = carry->getLeft();
		addNumber(carry, num);
	}
	else if (carry->getValue() < num && carry->getRight() != NULL) {
		carry = carry->getRight();
		addNumber(carry, num);
	}
	else if (carry->getValue() == num && carry->getRight() == NULL) {
		carry->setRight(new Node());
		carry->getRight()->setValue(num);
		carry->getRight()->setParent(carry);
		if (carry->getRight()->getParent()->getColor() == 'r') {
			carry->getRight()->setColor('b');
		}
		Node* temp = new Node();
		temp = carry->getRight();
		insert1(temp);
	}
	else {
		carry = carry->getRight();
		addNumber(carry, num);
	}
}

void deleteNode(Node* &head, int num) {
	Node* temp = findNode(head, num);
	Node* parent = temp->getParent();
	if (temp == NULL) {
		cout << "There is no node with that value" << endl;
	}
	else if (parent == NULL) {
		if (temp->getRight() == NULL && temp->getLeft() == NULL) {
			head = NULL;
		}
		else {
			Node* next = head->getLeft();
			Node* trail;
			if (next->getRight() == NULL) {
				int number = next->getValue();
				head->setValue(number);
				head->setLeft(next->getLeft());
			}
			else {
				while (next->getRight() != NULL) {
					trail = next;
					next = next->getRight();
				}
				int number;
				number = next->getValue();
				head->setValue(number);
				if (next->getLeft() != NULL) {
					trail->setRight(next->getLeft());
				}
				else{
					trail->setRight(NULL);
				}
			}
		}
	}
	else if (parent->getLeft() != NULL && parent->getLeft()->getValue() == num && parent->getLeft()->getLeft() == NULL && parent->getLeft()->getRight() == NULL) {
		parent->setLeft(NULL);
	}
	else if (parent->getRight() != NULL && parent->getRight()->getValue() == num && parent->getRight()->getLeft() == NULL && parent->getRight()->getRight() == NULL) {
		parent->setRight(NULL);
	}
	else if (parent->getLeft() != NULL && parent->getLeft()->getValue() == num && parent->getLeft()->getLeft() != NULL && parent->getLeft()->getRight() == NULL) {
		parent->setLeft(parent->getLeft()->getLeft());
	}
	else if (parent->getRight() != NULL && parent->getRight()->getValue() == num && parent->getRight()->getLeft() != NULL && parent->getRight()->getRight() == NULL) {
		parent->setRight(parent->getRight()->getLeft());
	}
	else if (parent->getLeft() != NULL && parent->getLeft()->getValue() == num && parent->getLeft()->getLeft() == NULL && parent->getLeft()->getRight() != NULL) {
		parent->setLeft(parent->getLeft()->getRight());
	}
	else if (parent->getRight() != NULL && parent->getRight()->getValue() == num && parent->getRight()->getLeft() == NULL && parent->getRight()->getRight() != NULL) {
		parent->setRight(parent->getRight()->getRight());
	}
	else if (parent->getLeft() != NULL && parent->getLeft()->getValue() == num && parent->getLeft()->getLeft() != NULL && parent->getLeft()->getRight() != NULL) {
		Node* next = parent->getLeft()->getLeft();
		Node* trail;
		if (next->getRight() == NULL) {
			int number = next->getValue();
			parent->getLeft()->setValue(number);
			parent->getLeft()->setLeft(next->getLeft());
		}
		else {
			while (next->getRight() != NULL) {
				trail = next;
				next = next->getRight();
			}
			
			int number;
			number = next->getValue();
			parent->getLeft()->setValue(number);
			if (next->getLeft() != NULL) {
				trail->setRight(next->getLeft());
			}
			else{
				trail->setRight(NULL);
			}
		}		
	}
	else {
		Node* next = parent->getRight()->getLeft();
		Node* trail;
		if (next->getRight() == NULL) {
			int number = next->getValue();
			cout << number << endl;
			parent->getRight()->setValue(number);
			parent->getRight()->setLeft(next->getLeft());
		}
		else {
			while (next->getRight() != NULL) {
				trail = next;
				next = next->getRight();
			}
			int number;
			number = next->getValue();
			parent->getRight()->setValue(number);
			trail->setRight(NULL);
		}			
	}
	fixDelete(head);
}

void insert_case1(Node* t, Node* n)
{
    if (n->getParent() == NULL)
        n->setColor('b');
    else
        insert_case2(t, n);
}

void insert_case2(Node* t, Node* n)
{
    if (n->getParent('b')) {
        return;
    }
    else
        insert_case3(t, n);
}

void insert_case3(rbtree t, node n)
{
    if (node_color(uncle(n)) == RED)
    {
        n->parent->color = BLACK;
        uncle(n)->color = BLACK;
        grandparent(n)->color = RED;
        insert_case1(t, grandparent(n));
    }
    else
    {
        insert_case4(t, n);
    }
}

void insert_case4(rbtree t, node n)
{
    if (n == n->parent->right && n->parent == grandparent(n)->left)
    {
        rotate_left(t, n->parent);
        n = n->left;
    }
    else if (n == n->parent->left && n->parent == grandparent(n)->right)
    {
        rotate_right(t, n->parent);
        n = n->right;
    }
    insert_case5(t, n);
}

void RBTree::insert_case5(rbtree t, node n)
{
    n->parent->color = BLACK;
    grandparent(n)->color = RED;
    if (n == n->parent->left && n->parent == grandparent(n)->left)
    {
        rotate_right(t, grandparent(n));
    }
    else
    {
        assert (n == n->parent->right && n->parent == grandparent(n)->right);
        rotate_left(t, grandparent(n));
    }
}

void fixDelete(Node* &head){
	
}
Node* findNode(Node* &head, int num) {
	if (head == NULL) {
		return NULL;
	}
	Node* trailling;
	Node* travel = head;
	if (head->getValue() == num) {
		return travel;
	}
	while (travel != NULL) {
		if (travel->getValue() != num && travel->getValue() > num) {
			trailling = travel;
			travel = travel->getLeft();
		}
		else if (travel->getValue() != num && travel->getValue() < num) {
			trailling = travel;
			travel = travel->getRight();
		}
		else {
			return travel;
		}
	}
	return NULL;
}

