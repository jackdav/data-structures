#include <iostream>

using namespace std;

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
			if (isBlank(m) == true) {
				return matrix m(n+1);
			}
			else {
				matrix n(n+1);
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						n[i][j] = m[i][j];
					}
				}
				return n;
			}
		}
		matrix add_edge(int start, int end, matrix m) {
			if (start > m.size || end > m.size || start == 0 || end == 0) {
				cout << "Invalid Edge";
				return m;
			}
			else {
				m[start - 1][end - 1] = 1;
				m[end - 1][start -1] = 1;
				return m;
			}
		}
		matrix delete_edge(int start, int end, matrix m) {
			if (start > m.size || end > m.size || start == 0 || end == 0) {
				cout << "Invalid Edge";
				return m;
			}
			else {
				m[start - 1][end - 1] = 0;
				m[end - 1][start -1] = 0;
				return m;
			}
		}
		matrix delete_vertex(int value, matrix m) {
			if (value > m.size || value == 0) {
				cout << "Invalid Vertex";
				return m;
			}
			else {
				matrix n(m.size - 1);
				for (int i = value; i < m.size; i++) {
					for (int j = value; j < m.size; j++) {
						n[i-1][j-1] = m[i][j];

					}
				}
				return n;
			}
		}
		void display() {
            int i,j;
            for(i = 0;i < n;i++) {
                for(j = 0; j < n; j++) {
                    cout<<adj[i][j]<<"  ";
                }
            	cout<<endl;
            }
        }
};

int main() {
	return 0;
}