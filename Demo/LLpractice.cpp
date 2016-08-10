#include <iostream>
#include <stdlib.h>

using namespace std;

struct node {
	node* next = NULL;
	node* back;
	int value;
};

void add_number(node* &, int);
void print_list(node*);
node* remove_all(node*&, int);

int main() {
	node* head = new node;
	head->value = 1;
	for (int i = 1; i < 20; i++) {
		int a = rand() % 100;
		add_number(head, a);
	}
	cout << "here\n";
	print_list(head);
	cout << endl;
	remove_all(head, 40);
	if (head != NULL) {
		print_list(head);
	}
	cout << endl;
}

void add_number(node* &n, int num) {
	if (n->next == NULL) {
		n->next = new node;
		n->next->value = num;
		node* temp = n->next;
	}
	else add_number(n->next, num);
}

void print_list(node* n) {
	if (n == NULL) {
		return;
	}
	else {
		cout << n->value << "(" << n->back->value << ")-> ";
		print_list(n->next);
	}
}

node* remove_all(node* &n, int num) {
	if (n != NULL) {
		if (n->value == num) {
			if (n->back != NULL) {
				cout << n->back->value;
				node* parent = n->back;
				parent->next = n->next;
			}
			else {
				n = n->next;
			}
		}
		return remove_all(n->next, num);
	}
	else {
		return n;
	}
}