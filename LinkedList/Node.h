#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

struct Student {
  char* firstName;
  char* lastName;
  int studentID;
  float GPA;
};
class Node{
	public:
		Node();
		~Node();
		void setValue(Student* newstudent);
		Student* getValue();
		void setNext(Node* newnext);
		Node* getNext();
	private:
		Student* value;
		Node* next;
};
#endif
