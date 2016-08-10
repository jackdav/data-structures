#include <iostream>

using namespace std;

int main() {
	for (int i = 1; i < 6; i += 2) {
      for (int j = 0; j < 9 - i / 2; j++)
        cout << " ";

      for (int j = 0; j < i; j++)
        cout << "*";
      	cout << "\n";
    }
    for (int i = 3; i > 0; i -= 2) {
      for (int j = 0; j < 9 - i / 2; j++)
        cout << " ";

      for (int j = 0; j < i; j++)
        cout << "*";
      	cout << "\n";
    }
	return 0;
}