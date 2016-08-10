#include <iostream>
#include <queue>

using namespace std;

struct pathnode {
	int label;
	pathnode* last;
};

struct queue_node {
	pathnode* data;
	queue_node* next = NULL;
};

struct node {
	int start;
	int end;
	node* next;
};

class mo_queue {
	private:
		queue_node* head;
	public:
		mo_queue() {
			head = NULL;
		}
		void mo_push(pathnode* data) {
			if (head == NULL) {
				queue_node* cur = new queue_node;
				cur->data = data;
				head = cur;
			}
			else {
				queue_node* travel = head;
				while (travel->next != NULL) {
					travel = travel->next;
				}
				travel->next = new queue_node;
				travel->next->data = data;
			}
		}
		void mo_pop() {
			head = head->next;
		}
		bool mo_empty() {
			if (head == NULL) {
				return true;
			}
			else {
				return false;
			}
		}
		pathnode* mo_front() {
			return head->data;
		}
};

class matrix {
	private:
		int size;
		int** adj;
	public:
		matrix(int n) {
			this->size = n;
			adj = new int*[n];
			for (int i = 0; i < n; i++) {
                adj[i] = new int[n];
                for(int j = 0; j < n; j++) {
                    adj[i][j] = 0;
                }
            }
		}
		matrix add_vertex(matrix m) {
			if (m.size == 0) {
				matrix ne(m.size+1);
				return ne;
			}
			else {
				matrix ne(m.size + 1);
				for (int i = 0; i < m.size; i++) {
					for (int j = 0; j < m.size; j++) {
						ne.adj[i][j] = m.adj[i][j];
					}
				}
				return ne;
			}
		}
		matrix add_edge(int start, int end, matrix m) {
			if (start > m.size || end > m.size || start == 0 || end == 0) {
				cout << "Invalid Edge\n";
				return m;
			}
			else {
				m.adj[start - 1][end - 1] = 1;
				return m;
			}
		}
		matrix delete_edge(int start, int end, matrix m) {
			if (start > m.size || end > m.size || start == 0 || end == 0) {
				cout << "Invalid Edge\n";
				return m;
			}
			else {
				m.adj[start - 1][end - 1] = 0;
				return m;
			}
		}
		matrix delete_vertex(int value, matrix m) {
			if (value > m.size || value == 0) {
				cout << "Invalid Vertex\n";
				return m;
			}
			else if (value == m.size + 1) {
				matrix ne(m.size - 1);
				for (int i = 0; i < ne.size; i++) {
					for (int j = 0; j < ne.size; j++) {
						ne.adj[i][j] = m.adj[i][j];
					}
				}
				cout << "Vertex successfully deleted\n";
				return ne;
			}
			else {
				node* head = get_all(m);
				matrix ne = add_all(head,  m, value);
				return ne;
			}
		}
		void display(matrix m) {
			cout << endl << endl;
            int i,j;
            for(i = 0; i < m.size;i++) {
                for(j = 0; j < m.size; j++) {
                    cout<< m.adj[i][j] <<"  ";
                }
            	cout<<endl;
            }
			cout << endl;
        }
        node* get_all(matrix m) {
        	node* head = NULL;
        	for(int i = 0; i < m.size; i++) {
                for(int j = 0; j < m.size; j++) {
                    if (m.adj[i][j] == 1) {
                    	node* cur = head;
                    	if (cur == NULL) {
                    		head = new node;
                    		head->start = i;
                    		head->end = j;
                    	}
                    	else {
	                    	while (cur->next != NULL) {
	                    		cur = cur->next;
	                    	}
	                    	cur->next = new node;
	                    	cur->next->start = i;
	                    	cur->next->end = j;
	                    }
                    }
                }
            }
            return head;
        }
        matrix add_all(node* head, matrix m, int value) {
        	if (head == NULL) {
        		matrix ne(m.size - 1);
        		return ne;
        	}
        	else {
        		matrix ne(m.size - 1);
        		value = value - 1;
        		while (head != NULL) {
        			if (head->start == value || head->end == value) {

        			}
        			else if (head->start > value && head->end > value) {
        				ne = ne.add_edge(head->start, head->end, ne);
        			}
        			else if (head->start < value && head->end > value) {
        				ne = ne.add_edge(head->start + 1, head->end, ne);
        			}
        			else if (head->start > value && head->end < value) {
        				ne = ne.add_edge(head->start, head->end+1, ne);
        			}
        			else {
        				ne = ne.add_edge(head->start+1, head->end+1, ne);
        			}
        			head = head->next;
        		}
        		return ne;
        	}
        }
		int getVertexLabel(matrix m) {
			return m.size;
		}
		int find_shortest(int s, int e, matrix m) {
			mo_queue bfs;
			mo_queue visited;
			pathnode* n = new pathnode;
			n->label = s;
			n->last = NULL;
			bfs.mo_push(n);
			while (!(bfs.mo_empty())) {
				for(int a = 0; a < m.size; a++) {
					bool b = in_visited(visited, a+1);
					bool tof = in_visited(bfs, a+1);
					if (m.adj[bfs.mo_front()->label - 1][a] == 1 && b == false && tof == false && a != (bfs.mo_front()->label - 1) ) {
						pathnode* temp = new pathnode;
						temp->last = bfs.mo_front();
						temp->label = a+1;
						bfs.mo_push(temp);
					}
				}
				visited.mo_push(bfs.mo_front());
				bfs.mo_pop();
			}
			bool is_in = in_visited(visited, e);
			if (is_in == false) {
				return 0;
			}
			else {
				pathnode* cur = find_node(visited, e);
				if (cur == NULL) {
					return 0;
				}
				int i = 0;
				while (cur->label != s) {
					cur = cur->last;
					i++;
				}
				return i;
			}
		}
		bool in_visited(mo_queue visited, int label) {
			while (!(visited.mo_empty())) {
				if (visited.mo_front()->label == label) {
					return true;
				}
				else {
					visited.mo_pop();
				}
			}
			return false;
		}
		pathnode* find_node(mo_queue q, int val) {
			while (!(q.mo_empty())) {
				if (q.mo_front()->label == val) {
					return q.mo_front();
				}
				else {
					q.mo_pop();
				}
			}
			return NULL;
		}
};

void insert_vertex(matrix &);
void remove_vertex(matrix &);
void insert_edge(matrix &);
void remove_edge(matrix &);
void shortest_path(matrix);

int main() {
	matrix am(0);
	int r = 0;
	while (r == 0) {
		cout << " 1. Add a vertex";
		cout << "\n 2. Delete a vertex";
		cout << "\n 3. Add an edge";
		cout << "\n 4. Delete an edge";
		cout << "\n 5. Search for shortest path";
		cout << "\n 6. Display the adjacency matrix";
		cout << "\n 7. Quit the program\n";
		int i;
		while (!(cin >> i)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Please enter a number\n";
		}
		switch(i) {
			case 1 : insert_vertex(am);
				break;
			case 2 : remove_vertex(am);
				break;
			case 3 : insert_edge(am);
				break;
			case 4 : remove_edge(am);
				break;
			case 5 : shortest_path(am);
				break;
			case 6 : am.display(am);
				break;
			case 7 : r = 1;
				break;
			default : cout << "Please enter a valid number\n";
				break;
		}
	}
	return 0;
}

void insert_vertex(matrix &am) {
	am = am.add_vertex(am);
	int i = am.getVertexLabel(am);
	cout << "The vertex label for your new vertex is: " << i << endl;
}

void remove_vertex(matrix &am) {
	cout << "What is the label for the vertex you would like to delete?\n";
	int i;
	while (!(cin >> i)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Please enter a number\n";
	}
	am = am.delete_vertex(i, am);
}

void insert_edge(matrix &am) {
	cout << "What is the vertex label of the starting point of the edge?\n";
	int i;
	while (!(cin >> i)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Please enter a number\n";
	}
	cout << "What is the vertex label of the ending point of the edge\n";
	int a;
	while (!(cin >> a)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Please enter a number\n";
	}
	am = am.add_edge(i, a, am);
}

void remove_edge(matrix &am) {
	cout << "What is the vertex label of the starting point of the edge you would like to delete?\n";
	int i;
	while (!(cin >> i)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Please enter a number\n";
	}
	cout << "What is the vertex label of the ending point of the edge you would like to delete\n";
	int a;
	while (!(cin >> a)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Please enter a number\n";
	}
	am = am.delete_edge(i, a, am);
}

void shortest_path(matrix am) {
	cout << "What is the vertex label of the starting point of the path\n";
	int i;
	while (!(cin >> i)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Please enter a number\n";
	}
	cout << "What is the vertex label of the ending point of the path\n";
	int a;
	while (!(cin >> a)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Please enter a number\n";
	}
	int num = am.find_shortest(i, a, am);
	if (num == 0) {
		cout << "Path not found\n";
	}
	else {
		cout << "Path length: " << num << endl;
	}
}
