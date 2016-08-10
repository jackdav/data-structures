#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <iomanip>
#include "Node.h"

void printStudents(Node* &);
void deleteS(Node* &, int);
void add(Node* &, char*, char*, int, float);
void avgGPA(Node* &);

int main() {
  Node* head = NULL;
  bool quit = false;
  while (quit == false) {
   cout << "Welcome to the SHS Student Database!" << endl;
   cout << "Would you like to add a student, print a list of students, or remove a student, get the average GPA, or quit the program? (A = add, P = print, D = delete, Q = quit, and M = mean GPA)" << endl;
    char response[2];
    response[0] = cin.get();
    cin.ignore(100, '\n');
    tolower(response[0]);
    while (response[0] != 'a' && response[0] != 'p' && response[0] != 'q' && response[0] != 'd' && response[0] != 'm') {
      cout << "Sorry that is not a valid command!" << endl;
      cout << "You can either Add, Search, or Quit!" << endl;
      response[0] = cin.get();
      cin.ignore(100, '\n');
      tolower(response[0]);
    }
    if (response[0] == 'a') {
        Node* current = head;
        cout << endl <<  "Welcome to the Add Student Screen" << endl;
        cout << "Please start by giving us the first name of the student!" << endl;
        char* fname = new char[100];
        cin.get(fname, 99);
        cin.ignore(1000, '\n');
        cout << "What is the last name of the student?" << endl;
        char* lname = new char[100];
        cin.get(lname, 99);
        cin.ignore(1000, '\n');
        cout << "What is this student's ID number?" << endl;
        int id = 0;
        while (!(cin >> id))  {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input, please enter a number" << endl;
        }
        cout << "What is this student's GPA? (Rounded to 2 decimal places)" << endl;
        float gpa = 0;
        while (!(cin >> gpa)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid GPA, please enter a number rounded to 2 decimal places";
        }
        cout << "This student has been successfully added!" << endl << endl;
        add(head, fname, lname, id, gpa);
    }
    else if (response[0] == 'p') {
        printStudents(head);
    }
    else if (response[0] == 'd') {
        cout << "What is this student's ID number that you would like to delete?" << endl;
        int ID = 0;
        while (!(cin >> ID))  {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input, please enter a number" << endl;
        }
        deleteS(head, ID);
    }
    else if(response[0] == 'm') {
        avgGPA(head);
    }
    else {
      quit = true;
    }
  }
  return 0;
}


void add(Node* &head, char* fname, char* lname, int id, float gpa) {
  Node* current = head;
  Student* x = new Student();
  x->firstName = fname;
  x->lastName = lname;
  x->studentID = id;
  x->GPA = gpa;
  if (current == NULL) {
    head = new Node();
    head->setValue(x);
  }
  else {
      if (current->getNext() == NULL && current->getValue()->studentID <= x->studentID) {
          current->setNext(new Node());
          current->getNext()->setValue(x);
      }
      else if (current->getValue()->studentID <= x->studentID) {
        current = current->getNext();
        add(current, x->firstName, x->lastName, x->studentID, x->GPA);
      }
      else {
          current->setNext(new Node());
          current->getNext()->setValue(x);
      }
  }
}

void printStudents(Node* &head) {
  Node* current = head;
  while (current != NULL) {
  cout << current->getValue()->firstName << " " << current->getValue()->lastName << ", "; 
  cout << current->getValue()->studentID << ", " << current->getValue()->GPA << endl;
  current = current->getNext();
  }
  cout << endl;
}

void deleteS(Node* &head, int ID) {
    Node* current = head;
    Node* trailing;
    if (current == NULL) {
        cout << "There is nothing to delete" << endl;
    }
    else {
        Node* ahead = current->getNext();
        while (ahead != NULL) {
            if (current->getValue()->studentID == ID) {
                break;
            }
            else {
                trailing = current;
                current = current->getNext();
                ahead = current->getNext();
            }
        }
        if (current->getValue()->studentID == ID) {
            delete current;
            trailing->setNext(ahead);
        }
        else {
            cout << "There is no student with that ID" << cout;
        }
    }
}

void avgGPA(Node* &head) {
    Node* current = head;
    float average = 0;
    int counts = 0;
    while (current != NULL) {
        average = average + current->getValue()->GPA;
        counts++;
        current = current->getNext();
    }
    average = (average)/(counts);
    cout << "Average GPA is: " << setprecision(3) << average << endl;
}
