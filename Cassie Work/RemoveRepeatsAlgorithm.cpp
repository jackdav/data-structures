#include <iostream>
#include <string.h>

using namespace std; 

char* remove_repeats(char*);

int main() {
	char* array = "hello";
	array = remove_repeat(array);
	cout << array << endl;
}

char* remove_repeats(char* array) {
	int i = 0;
	char* trail = array[i];
    while(trail != '\0'){
        int count = 0;
        for (int a = 0; a <= strlen(word); a++) {
            if (word[a] == trail){
                count++;
            }
        }
        if (count > 1) {
        	char temp = array[]
        }
        i++;
        trail = array[i]; 
    }
    cout << phrase << endl;
    cout << strlen(phrase) << endl;
    return phrase;
}