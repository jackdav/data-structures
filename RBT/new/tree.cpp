#include <iostream>
#include <fstream>
#include <string.h>
#include <queue>

using namespace std;

struct node {
	node* parent;
	node* left = NULL;
	node* right = NULL;
	int value;
	char color;
};

void insert(node*&);
void remove(node*&);
void read(node* &);
void search(node*);
void addnode(node* &, node*&, int);
void removenode(node*&, int);
void print(node*);
node* find(node*, int);
bool in_tree(node*, int);
node* grandparent(node*);
node* uncle(node*);
node* sibling(node*);
void ione(node*&, node*&);
void itwo(node*&, node*&);
void ithree(node*&, node*&);
void ifour(node*&, node*&);
void ifive(node*&, node*&);
void rone(node*&, node*&);
void rtwo(node*&, node*&);
void rthree(node*&, node*&);
void rfour(node*&, node*&);
void rfive(node*&, node*&);
void rsix(node*&, node*&);
char null_color(node*);
void rotate_right(node*&, node*&);
void rotate_left(node*&, node*&);

int main() {
	node* head = NULL;
	int r = 0;
	while (r == 0){
		cout << " 1. Add a node";
		cout << "\n 2. Delete a node";
		cout << "\n 3. Read a file of numbers";
		cout << "\n 4. Print the tree";
		cout << "\n 5. Search the tree";
		cout << "\n 6. Quit the program\n";
		int i;
		while (!(cin >> i)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Please enter a number\n";
		}
		switch(i) {
			case 1 : insert(head);
				break;
			case 2 : remove(head);
				break;
			case 3 : read(head);
				break;
			case 4 : print(head);
				break;
			case 5 : search(head);
				break;
			case 6 : r = 1;
				break;
			default : cout << "Please enter a valid number\n";
				break;
		}
	}
}

void insert(node* &root) {
	cout << "Number to be added?\n";
	int i;
	while (!(cin>>i)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Enter a valid number\n";
	}
	addnode(root, root, i);
}
void remove(node* &root) {
	cout << "Number to be removed?\n";
	int i;
	while (!(cin>>i)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Enter a valid number\n";
	}
	removenode(root, i);
}
void read(node* &n) {
	char* filename = new char[100];
	cout << "What is the file name for which you would like to read in?" << endl;
	cout << "File content requirements: must have all numbers, only seperated by spaces" << endl;
	cin >> filename;
	cin.ignore(1000, '\n');	
	strcat(filename, ".txt");
	ifstream file;
	file.open(filename);
	int num[50];
	int index = 0;
	while (!file.eof()) {
		file >> num[index];
		addnode(n, n, num[index]);
		index++;
	}
	file.close();
}
void print(node* root) {
    if (root == NULL) {
        return;
    }
    else {
		cout << endl;
		queue<node*> currentLevel;
		queue<node*> nextLevel;
		currentLevel.push(root);
		while (!currentLevel.empty()) {
			node* currNode = currentLevel.front();
			currentLevel.pop();
			if (currNode) {
				cout << currNode->value;
				cout << currNode->color;
				if (currNode->parent != NULL) {
					cout << '(' << currNode->parent->value << ") ";
				}
				nextLevel.push(currNode->left);
				nextLevel.push(currNode->right);
			}
			if (currentLevel.empty()) {
				cout << endl;
				swap(currentLevel, nextLevel);
			}
		}
	}
}
void search(node* root) {
	cout << "Number to be searched?\n";
	int i;
	while (!(cin>>i)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Enter a valid number\n";
	}
	bool r = in_tree(root, i);
	if (r == true) cout << "Node is in the tree\n";
	else cout << "Node is not in the tree\n";
}
bool in_tree(node* n, int v) {
	if (n == NULL) {
		return false;
	}
	node* trailling;
	node* travel = n;
	if (n->value == v) {
		return true;
	}
	while (travel != NULL) {
		if (travel->value != v && travel->value > v) {
			trailling = travel;
			travel = travel->left;
		}
		else if (travel->value != v && travel->value < v) {
			trailling = travel;
			travel = travel->right;
		}
		else {
			return true;
		}
	}
	return false;
}
void addnode(node* &root, node* &n, int num) {
	node* trail;
	node* carry = n;
	if (root == NULL) {
		root = new node;
		root->value = num;
		root->color = 'b';
		ione(root, n);
		return;
	}
	else if (carry->value > num && carry->left == NULL) {
		node* temp = new node;
		carry->left = temp;
		temp->value = num;
		temp->color = 'r';
		temp->parent = carry;
		if (carry->color == 'r') {
			temp->color = 'b';
		}
		ione(root, temp);
	}
	else if (carry->value < num && carry->right == NULL) {
		node* temp = new node;
		carry->right = temp;
		temp->value = num;
		temp->color = 'r';
		temp->parent = carry;
		if (carry->color == 'r') {
			temp->color = 'b';
		}
		ione(root, temp);
	}
	else if (carry->value > num && carry->left != NULL) {
		carry = carry->left;
		addnode(root, carry, num);
	}
	else if (carry->value < num && carry->right != NULL) {
		carry = carry->right;
		addnode(root, carry, num);
	}
	else if (carry->value == num && carry->right == NULL) {
		node* temp = new node;
		carry->right = temp;
		temp->value = num;
		temp->color = 'r';
		temp->parent = carry;
		if (carry->color == 'r') {
			temp->color = 'b';
		}
		ione(root, temp);
	}
	else {
		carry = carry->right;
		addnode(root, carry, num);
	}
}
void removenode(node* &head, int number) {
	node* n = find(head, number);
	if (n == NULL) {
		cout << "Number invalid\n";
	}
	else {
		if (n == head) {
			if (head->left != NULL) {
				if (head->left->right != NULL) {
					node* t = new node;
					t = n->left->right;
					while(t->right != NULL) {
						t = t->right;
					}
					int replace = t->value;
					if (t->left != NULL) {
						t->parent->right = t->left;
						t->left->parent = t->parent;
						if (t->color == 'b' && t->left->color == 'r') {
							t->left->color = 'b';
						}
					}
					else {
						node* saved_p = t->parent;
						if (t->color == 'b') {
							rone(t, head);
						}
						saved_p->right = NULL;
					}
					n->value = replace;
					return;
				}
				else {
					if (n->left->left != NULL) {
						head->value = n->left->value;
						node* saved_l = head->left;
						head->left = saved_l->left;
						head->left->parent = head;
						head->left->color = 'b';
						return;
					}
					else {
						int replace = head->left->value;
						node* saved_l = head->left;
						rone(head->left, head);
						n->left = NULL;
						n->value = replace;
						return;
					}
				}
			}
			else if (head->right != NULL) {
				head = n->right;
				head->parent = NULL;
				n->right->color = 'b';
				return;
			}
			else {
				head = NULL;
				return;
			}
		}
		if ((n->right == NULL && n->left != NULL) || (n->right != NULL && n->left == NULL)) {
			if (n->right != NULL) {
				if(n->parent->left == n) {
					n->parent->left = n->right;
					n->right->parent = n->parent;
					if(n->color == 'b' && n->right->color == 'r') {
						n->right->color = 'b';
					}
					return;
				}
				else {
					n->parent->right = n->right;
					n->right->parent = n->parent;
					if(n->color == 'b' && n->right->color == 'r') {
						n->right->color = 'b';
					}
					return;
				}
			}
			if (n->left != NULL) {
				if(n->parent->left == n) {
					n->parent->left = n->left;
					n->left->parent = n->parent;
					if(n->color == 'b' && n->left->color == 'r') {
						n->left->color = 'b';
					}
					return;
				}
				else {
					n->parent->right = n->left;
					n->left->parent = n->parent;
					if(n->color == 'b' && n->left->color == 'r') {
						n->left->color = 'b';
					}
					return;
				}
			}
		}
		if (n->right != NULL && n->left != NULL) {
			if (n->left->right != NULL) {
				node* t = new node;
				t = n->left->right;
				while (t->right != NULL) {
					t = t->right;
				}
				int replace = t->value;
				if (t->left != NULL) {
					t->parent->right = t->left;
					t->left->parent = t->parent;
					if (t->color == 'b' && t->left->color == 'r') {
						t->left->color = 'b';
					}
				}
				else {
					node* saved_p = t->parent;
					if (t -> color == 'b') {
						rone(t, head);
					}
					saved_p->right = NULL;
				}
				n->value = replace;
				return;
			}
			else {
				if (n->left->left != NULL) {
					n->value = n->left->value;
					node* saved_l = n->left;
					n->left = saved_l->left;
					n->left->parent = n;
					n->left->color = 'b';
					return;
				}
				else {
					int replace = n->left->value;
					node* saved_l = n->left;
					rone(n->left, head);
					n->left = NULL;
					n->value = replace;
					return;
				}
			}
		}
		else {
			if (n->parent->left == n) {
				node* saved_p = n->parent;
				if(n->color == 'b') {
					rone(n, head);
				}
				saved_p->left = NULL;
				return;
			}
			else {
				node* saved_p = n->parent;
				if (n->color == 'b') {
					rone(n, head);
				}
				saved_p->right = NULL;
				return;
			}
		}
	}
}
node* find(node* head, int val) {
	if (head->value == val) {
		return head;
	}
	else {
		while (head != NULL) {
			if (head->value == val) {
				return head;
			}
			else if (val > head->value) {
				head = head->right;
			}
			else {
				head = head->left;
			}
		}
		return NULL;
	}
}
void ione(node* &root, node* &n) {
	if (n->parent == NULL) n->color = 'b';
	else itwo(root, n);
}
void itwo(node* &root, node* &n) {
	if (n->parent->color == 'b') return;
	else ithree(root, n);
}
void ithree(node* &root, node* &n) {
	node* u = uncle(n);
	node* g = grandparent(n);
	if (n->parent->color == 'r' && u != NULL && u->color == 'r') {
		n->color = 'r';
		n->parent->color = 'b';
		u->color = 'b';
		g->color = 'r';
		ione(root, g);
	}
	else {
		ifour(root, n);
	}
}
void ifour(node* &root, node* &n) {
    if (n == n->parent->right && n->parent == grandparent(n)->left) {
		node* g = grandparent(n);
		if (g != NULL && g->value == root->value) {
			node* savedp = n->parent;
			node* savedl = n->left;
			root->left = n;
			n->left = savedp;
			savedp->parent = n;
			savedp->right = savedl;
			n->parent = root;
			if (savedl != NULL) {
				savedl->parent = savedp;
			}
		}
		else {
			node* savedp = n->parent;
			node* savedl = n->left;
			g->left = n;
			n->left = savedp;
			savedp->parent = n;
			savedp->right = savedl;
			n->parent = g;
			if (savedl != NULL) {
				savedl->parent = savedp;
			}
		}
        n = n->left;
	}
    else if (n == n->parent->left && n->parent == grandparent(n)->right) {
		node* g = grandparent(n);
		if (g != NULL && g->value == root->value) {
			node* savedp = n->parent;
			node* savedr = n->right;
			root->right = n;
			n->right = savedp;
			savedp->parent = n;
			savedp->left = savedr;
			n->parent = root;
			if (savedr != NULL) {
				savedr->parent = savedp;
			}
		}
		else {
			node* savedp = n->parent;
			node* savedr = n->right;
			g->right = n;
			n->right = savedp;
			savedp->parent = n;
			savedp->left = savedr;
			n->parent = g;
			if (savedr != NULL) {
				savedr->parent = savedp;
			}			
		}
        n = n->right;
    }
    ifive(root, n);
}
void ifive(node* &root, node* &n) {
	node* g = grandparent(n);
	n->color = 'r';
	n->parent->color = 'b';
	g->color = 'r';
	if (n == n->parent->left) {
		if (g != NULL && g->parent == NULL) {
			node* savedr = n->parent->right;
			root = n->parent;
			n->parent->parent = NULL;
			n->parent->right = g;
			g->parent = root;
			g->left = savedr;
			if (savedr != NULL) {
				savedr->parent = g;
			}
		}
		else {
			node* savedr = n->parent->right;
			g->parent->left = n->parent;
			n->parent->parent = g->parent;
			n->parent->right = g;
			g->parent = n->parent;
			g->left = savedr;
			if (savedr != NULL) {
				savedr->parent = g;
			}
		}
	}
	else {
		if (g != NULL && g->parent == NULL) {
			node* savedl = n->parent->left;
			root = n->parent;
			n->parent->parent = NULL;
			n->parent->left = g;
			g->parent = root;
			g->right = savedl;
			if (savedl != NULL) {
				savedl->parent = g;
			}
		}
		else {
			node* savedl = n->parent->left;
			g->parent->right = n->parent;
			n->parent->parent = g->parent;
			n->parent->left = g;
			g->parent = n->parent;
			g->right = savedl;		
			if (savedl != NULL) {
				savedl->parent = g;
			}			
		}
	}
}
node* grandparent(node* n) {
	if (n != NULL && n->parent != NULL) {
		return n->parent->parent;
	}
	else return NULL;
}
node* uncle(node* n) {
	node* g = grandparent(n);
	if (g == NULL) return NULL;
	else if (n->parent == g->right) return g->left;
	else return g->right;
}
node* sibling(node* n) {
	if (n == NULL || n->parent == NULL) {
  		return NULL;
	}
 	if (n == n->parent->left) {
  		return n->parent->right;
 	}
 	else {
 		return n->parent->left;
 	}
}
void rone(node* &n, node* &root) {
	if (n->parent != NULL) {
		rtwo(n, root);
	}
}
void rtwo(node* &n, node* &root) {
	node* s = sibling(n);
	if (s != NULL && s->color == 'r') {
		n->parent->color = 'r';
		s->color = 'b';
		if (n == n->parent->left) {
			rotate_left(s, root);
		}
		else {
			rotate_right(s, root);
		}
	}
	rthree(n, root);
}
void rthree(node* &n, node* &root) {
	node* s = sibling(n);
	if (n->parent->color == 'b' && s->color == 'b' && null_color(s->right) == 'b' && null_color(s->left) == 'b') {
		s->color = 'r';
		rone(n->parent, root);
	}
	else {
		rfour(n, root);
	}
}
void rfour(node* &n, node* &root) {
	node* s = sibling(n);
	if (n->parent->color == 'r' && s->color == 'b' && null_color(s->right) == 'b' && null_color(s->left) == 'b') {
		s->color = 'r';
		n->parent->color = 'b';
	}
	else {
		rfive(n, root);
	}
}
void rfive(node* &n, node* &root) {
	node* s = sibling(n);
	if (s->color == 'b') {
		if (n == n->parent->left &&  null_color(s->right) == 'b' && null_color(s->left) == 'r') {
			s->color = 'r';
			if (s->left != NULL) {
				s->left->color = 'b';
			}
			rotate_right(s->left, root);
		}
		else if (n == n->parent->right && null_color(s->left) == 'b' && null_color(s->right) == 'r'){
			s->color = 'r';	
			if (s->right != NULL){
				s->right->color = 'b';
			}
			rotate_left(s->right, root);
		}
	}
	rsix(n, root);
}
void rsix(node* &n, node* &root) {
	node* s = sibling(n);
	s->color = n->parent->color;
	n->parent->color = 'b';
	if(n == n->parent->left) {
		if(s->right != NULL) {
			s->right->color = 'b';
		}
		rotate_left(s, root);
	}
	else {
		if(s->left != NULL) {
			s->left->color = 'b';
		}
		rotate_right(s, root);
	}
}
char null_color(node* n) {
	if (n == NULL) {
		return 'b';
	}
	else {
		return n->color;
	}
}
void rotate_left(node* &n, node* &root) {
	node* g = grandparent(n);
	if (g != NULL) {
		if (g->left == n->parent) {
			node* saved_p = g->left;
			node* saved_l = n->left; 
			g->left = n;
			n->parent = g;
			n->left = saved_p;
			saved_p->parent = n;
			saved_p->right = saved_l;
			if (saved_l != NULL) {	
				saved_l->parent = saved_p;
			}		
		}
		else {
			node* saved_p = g->right;
			node* saved_l = n->left;
			g->right = n;
			n->parent = g;
			n->left = saved_p;
			saved_p->parent = n;
			saved_p->right = saved_l;
			if (saved_l != NULL) {	
				saved_l->parent = saved_p;
			}
		}
	}
	else {
		node* saved_l = n->left;
		n->left = n->parent;
		n->parent->parent = n;
		n->parent->right = NULL;
		n->parent = NULL;
		if (saved_l != NULL) {
			n->left->right = saved_l;
			saved_l->parent = n->left;
		}
		root = n;
	}
}

void rotate_right(node* &n, node* &root) {
	node* g = grandparent(n);
	if (g != NULL) {
		if (g->left == n->parent) {
			node* saved_p = g->left;
			node* saved_r = n->right; 
			g->left = n;
			n->parent = g;
			n->right = saved_p;
			saved_p->parent = n;
			saved_p->left = saved_r;
			if (saved_r != NULL) {
				saved_r->parent = saved_p;
			}			
		}
		else {
			node* saved_p = g->right;
			node* saved_r = n->right;
			g->right = n;
			n->parent = g;
			n->right = saved_p;
			saved_p->parent = n;
			saved_p->left = saved_r;
			if (saved_r != NULL) {
				saved_r->parent = saved_p;
			}
		}
	}
	else {
		node* saved_r = n->right;
		n->right = n->parent;
		n->parent->parent = n;
		n->parent->left = NULL;
		n->parent = NULL;
		if (saved_r != NULL) {
			n->right->left = saved_r;
			saved_r->parent = n->right;
		}
		root = n;
	}
}