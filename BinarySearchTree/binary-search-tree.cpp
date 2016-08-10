#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <iomanip>
#include "node.h"
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;
void addNumber(Node* &, int);
void printTree(Node* &);
void deleteNumber(Node* &, int);
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
	bool running = true;
	while (running==true) {
		cout << "Commands: " << endl;
		cout << "A = Add a number to the tree" << endl;
		cout << "D = Delete a number from the tree" << endl;
		cout << "Q = Quit the program (terminates current tree)" << endl;
		char response;
		response = cin.get();
		cin.ignore(10000, '\n');
		tolower(response);
		if (response != 'a' && response != 'd' && response != 'q') {
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
			printTree(head);
		}
		else if (response == 'd') {
			cout << "What number would you like to delete?" << endl;
			int temp;
			while (!(cin>>temp)) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Please enter a number" << endl;
			}
			cin.ignore(1000, '\n');			
			deleteNumber(head, temp);	
			printTree(head);			
		}
		else {
			running = false;
		}
	}
	return 0;
}

void addNumber(Node* &head, int num) {
	Node* carry = head;
	if (carry->getValue() > num && carry->getLeft() == NULL) {
		carry->setLeft(new Node());
		carry->getLeft()->setValue(num);
	}
	else if (carry->getValue() < num && carry->getRight() == NULL) {
		carry->setRight(new Node());
		carry->getRight()->setValue(num);
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
	}
	else {
		carry = carry->getRight();
		addNumber(carry, num);
	}
}
void deleteNumber(Node* &head, int num) {
	Node* parent = findNode(head, num);
	if (parent == NULL) {
		cout << "There is no node with that value" << endl;
	}
	else if (parent->getValue() == num) {
		if (parent->getRight() == NULL && parent->getLeft() == NULL) {
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
				cout << currNode->getValue() << " ";
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
			return trailling;
		}
	}
	return NULL;
}





