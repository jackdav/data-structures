#include <iostream>
#include <ctype.h>
#include <string.h>
#include "Node.h"
#include "stackNode.h"

using namespace std;
bool isOperator(char);
char* printPostfix(Node*);
char* printPrefix(Node*);
stackNode* createExpressionTree(char*, stackNode* &, int);
stackNode* pop (stackNode* &);
void push(Node*, stackNode* &);
Node* peek(stackNode* &);

int main () {
	stackNode* head = NULL;
	char* array = new char[100];
	int i = 0;
	cout << "Please enter an equation with only single digit numbers and basic operators" << endl;
	cin.get(array, 99);
	cin.ignore(100, '\n');
	while (array[i] != '\0') {
		if(array[i] != '+' && array[i] != '-' && array[i] != '*' && array[i] != '/' && array[i] != '1' &&
			array[i] != '2' && array[i] != '3' && array[i] != '4' && array[i] != '5'  && array[i] != '6'
			&& array[i] != '7' && array[i] != '8' && array[i] != '9' && array[i] != '(' && array[i] != ')') {
				cout <<  "Unaccepted Input, try again!" << endl;
				main();
			}
		i++;
	}
    char* arr = new char[100];
	char e = ')';
	char s = '(';
	char* end = &(e);
	arr[0] = s;
	strcat(arr, array);
	strcat(arr, end);
	cout << arr << endl;
	head = createExpressionTree(arr, head, 13);
	cout << "Postfix: " << printPostfix(head->getValue()) << endl;
	cout << "Prefix: " << printPrefix(head->getValue()) << endl;
	return 0;
}

stackNode* createExpressionTree(char* input, stackNode* &head, int index) {
    for (int tokenIndex = 0; tokenIndex < index; tokenIndex++) {
        char token = input[tokenIndex];
        Node* tokenNode = new Node();
        tokenNode->setValue(token);
        if (token == '(') {
            push(tokenNode, head);
        }
        else if (isOperator(token) == false && token != ')') {
            if (isOperator(peek(head)->getValue())) {
                stackNode* operation = pop(head);
                operation->getValue()->setRight(tokenNode);
                push(operation->getValue(), head);
            }
            else {
                push(tokenNode, head);
            }
        }
        else if(isOperator(token)) {
            stackNode* top = pop(head);
            tokenNode->setLeft(top->getValue());
            push(tokenNode, head);
        }
        else {
            stackNode* current = pop(head);
            stackNode* top = pop(head);
            while (top->getValue()->getValue() != '(') {
                top->getValue()->setRight(current->getValue());
                current = top;
                top = pop(head);
            }
            push(current->getValue(), head);
        }
    }
    return pop(head);
}

char* printPostfix(Node* curRoot) {
	if (curRoot->getLeft() != NULL && curRoot->getRight() != NULL) {
		char* ret;
		strcpy(ret, printPostfix(curRoot->getLeft()));
		strcat(ret, printPostfix(curRoot->getRight()));
		char temp = (curRoot->getValue());
		char* tempPtr = &temp;
		strcat(ret, tempPtr);
		return ret;
	}
	else if (curRoot->getLeft() == NULL && curRoot->getRight() != NULL) {
		char* ret;
		strcpy(ret, printPostfix(curRoot->getRight()));
		char temp = (curRoot->getValue());
		char* tempPtr = &temp;
		strcat(ret, tempPtr);
		return ret;
	}
	else if (curRoot->getLeft() != NULL && curRoot->getRight() == NULL) {
		char* ret;
		strcpy(ret, printPostfix(curRoot->getLeft()));
		char temp = (curRoot->getValue());
		char* tempPtr = &temp;
		strcat(ret, tempPtr);
		return ret;
	}
	else {
		char temp = (curRoot->getValue());
		char* tempPtr = &temp;
		return tempPtr;
	}
}

char* printPrefix(Node* curRoot) {
	char* prefix = new char[100];
	return prefix;
}
bool isOperator(char token) {
	if (token == '+' || token == '-' || token == '*' || token == '/') {
		return true;
	}
	else {
		return false;
	}
}
void push(Node* newNode, stackNode* &head) {
	if (head != NULL) {
		stackNode* temp = head;
		head->setValue(newNode);
		head->setNext(temp);
	}
	else {
		head = new stackNode();
		head->setValue(newNode);
	}
}
stackNode* pop (stackNode* &head) {
	if (head != NULL) {
		stackNode* temp = head;
		head = head->getNext();
		return temp;
	}
	else {
		stackNode* temp = head;
		head = NULL;
		return temp;
	}
}
Node* peek(stackNode* &head) {
	if (head != NULL) {
		return head->getValue();
	}
	else {
		return NULL;
	}
}
