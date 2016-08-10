#include <iostream>

using namespace std;

int main() {
	int i;
	cout << "Please enter a number\n";
	while (!(cin>>i)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Please enter a valid number\n";
	}
	for (int a = 1; a <= i; a = a+1) {
		for (int b = 0; b < a; b = b+1) {
			cout << i;
		}
		cout << '\n';
	}
	return 0;
}