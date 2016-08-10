#include <iostream>
#include <cstring>
#include <string.h>
#include <stdio.h>
#include <string>

using namespace std;

char *getMessage(); //Prototype

char *messageMorse(char*); //prototype

char *deleteRepeats();

int main(){

char *message = getMessage();
cout << message << endl;
cout << strlen(message) << endl;

char *morse = messageMorse(message);
cout << morse << endl;
cout << strlen(morse) << endl;

deleteRepeats();

return 0;
}

char *getMessage(){
    char inputChar;
    char *aPtr;
    int LENG = 0;

    aPtr = new char[1];// Allocate 1 char for null termination
    
    while ((inputChar = cin.get()) != '\n') {//Gets input until 'enter' is pressed
        
        LENG++; //Continuously increase string length
                                   
        char *temporary = aPtr;//Save aPtr
        
        aPtr = new char[LENG+1];//Allocate aPtr to size LENG
        
        for (int i = 0; i < LENG-1; i++){//Copy aPtr to temporary
            aPtr[i] = temporary[i];
        }
        
        aPtr[LENG - 1] = inputChar;//Add the new character
        
        delete []temporary;//Delete temporary
    
    }
    
    aPtr[LENG] = '\0';//Add null termination at the last part of the array
    
    return aPtr;	
}

char *messageMorse(char *message){

	char inputChar;
    char *aPtr;
    int LENG = 0;

    aPtr = new char[1];// Allocate 1 char for null termination
    
    for(int i = 0; message[i] != '\0'; i++) {//Gets input until 'enter' is pressed
                                   
        char *temporary = aPtr;//Save aPtr
        
        aPtr = new char[LENG];//Allocate aPtr to size LENG
        
        for (int i = 0; i < LENG; i++){//Copy aPtr to temporary
            aPtr[i] = temporary[i];
        }
        
        	if(message[i] == 'a'){
        		aPtr[LENG] = '*';
        		aPtr[LENG + 1] = '-';
        		aPtr[LENG + 2] = 'X';
        		LENG = LENG + 3;
        	}
        	if(message[i] == 'b'){
        		aPtr[LENG] = '-';
        		aPtr[LENG + 1] = '*';
        		aPtr[LENG + 2] = '*';
        		aPtr[LENG + 3] = '*';
        		aPtr[LENG + 4] = 'X';
        		LENG = LENG + 5;
        	}
        	if(message[i] == 'c'){
        		aPtr[LENG] = '-';
        		aPtr[LENG + 1] = '*';
        		aPtr[LENG + 2] = '-';
        		aPtr[LENG + 3] = '*';
        		aPtr[LENG + 4] = 'X';
        		LENG = LENG + 5;
        	}
        	if(message[i] == 'd'){
        		aPtr[LENG] = '-';
        		aPtr[LENG + 1] = '*';
        		aPtr[LENG + 2] = '*';
        		aPtr[LENG + 3] = 'X';
        		LENG = LENG + 4;
        	}
        	if(message[i] == 'e'){
        		aPtr[LENG] = '*';
        		aPtr[LENG + 1] = 'X';
        		LENG = LENG + 2;
        	}
        	if(message[i] == 'f'){
        		aPtr[LENG] = '*';
        		aPtr[LENG + 1] = '*';
        		aPtr[LENG + 2] = '-';
        		aPtr[LENG + 3] = '*';
        		aPtr[LENG + 4] = 'X';
        		LENG = LENG + 5;
        	}
        	if(message[i] == 'g'){
        		aPtr[LENG] = '-';
        		aPtr[LENG + 1] = '-';
        		aPtr[LENG + 2] = '*';
        		aPtr[LENG + 3] = 'X';
        		LENG = LENG + 4;
        	}
        	if(message[i] == 'h'){
        		aPtr[LENG] = '*';
        		aPtr[LENG + 1] = '*';
        		aPtr[LENG + 2] = '*';
        		aPtr[LENG + 3] = '*';
        		aPtr[LENG + 4] = 'X';
        		LENG = LENG + 5;
        	}
        	if(message[i] == 'i'){
        		aPtr[LENG] = '*';
        		aPtr[LENG + 1] = '*';
        		aPtr[LENG + 2] = 'X';
        		LENG = LENG + 3;
        	}
        	if(message[i] == 'j'){
        		aPtr[LENG] = '*';
        		aPtr[LENG + 1] = '-';
        		aPtr[LENG + 2] = '-';
        		aPtr[LENG + 3] = '-';
        		aPtr[LENG + 4] = 'X';
        		LENG = LENG + 5;
        	}
        	if(message[i] == 'k'){
        		aPtr[LENG] = '-';
        		aPtr[LENG + 1] = '*';
        		aPtr[LENG + 2] = '-';
        		aPtr[LENG + 3] = 'X';
        		LENG = LENG + 4;
        	}
        	if(message[i] == 'l'){
        		aPtr[LENG] = '*';
        		aPtr[LENG + 1] = '-';
        		aPtr[LENG + 2] = '*';
        		aPtr[LENG + 3] = '*';
        		aPtr[LENG + 4] = 'X';
        		LENG = LENG + 5;
        	}
        	if(message[i] == 'm'){
        		aPtr[LENG] = '-';
        		aPtr[LENG + 1] = '-';
        		aPtr[LENG + 2] = 'X';
        		LENG = LENG + 3;
        	}
        	if(message[i] == 'n'){
        		aPtr[LENG] = '-';
        		aPtr[LENG + 1] = '*';
        		aPtr[LENG + 2] = 'X';
        		LENG = LENG + 3;
        	}
        	if(message[i] == 'o'){
        		aPtr[LENG] = '-';
        		aPtr[LENG + 1] = '-';
        		aPtr[LENG + 2] = '-';
        		aPtr[LENG + 3] = 'X';
        		LENG = LENG + 4;
        	}
        	if(message[i] == 'p'){
        		aPtr[LENG] = '*';
        		aPtr[LENG + 1] = '-';
        		aPtr[LENG + 2] = '-';
        		aPtr[LENG + 3] = '*';
        		aPtr[LENG + 4] = 'X';
        		LENG = LENG + 5;
        	}
        	if(message[i] == 'q'){
        		aPtr[LENG] = '-';
        		aPtr[LENG + 1] = '-';
        		aPtr[LENG + 2] = '*';
        		aPtr[LENG + 3] = '-';
        		aPtr[LENG + 4] = 'X';
        		LENG = LENG + 5;
        	}
        	if(message[i] == 'r'){
        		aPtr[LENG] = '*';
        		aPtr[LENG + 1] = '-';
        		aPtr[LENG + 2] = '*';
        		aPtr[LENG + 3] = 'X';
        		LENG = LENG + 4;
        	}
        	if(message[i] == 's'){
        		aPtr[LENG] = '*';
        		aPtr[LENG + 1] = '*';
        		aPtr[LENG + 2] = '*';
        		aPtr[LENG + 3] = 'X';
        		LENG = LENG + 4;
        	}
        	if(message[i] == 't'){
        		aPtr[LENG] = '-';
        		aPtr[LENG + 2] = 'X';
        		LENG = LENG + 3;
        	}
        	if(message[i] == 'u'){
        		aPtr[LENG] = '*';
        		aPtr[LENG + 1] = '*';
        		aPtr[LENG + 2] = '-';
        		aPtr[LENG + 3] = 'X';
        		LENG = LENG + 4;
        	}
        	if(message[i] == 'v'){
        		aPtr[LENG] = '*';
        		aPtr[LENG + 1] = '*';
        		aPtr[LENG + 2] = '*';
        		aPtr[LENG + 3] = '-';
        		aPtr[LENG + 4] = 'X';
        		LENG = LENG + 5;
        	}
        	if(message[i] == 'w'){
        		aPtr[LENG] = '*';
        		aPtr[LENG + 1] = '-';
        		aPtr[LENG + 2] = '-';
        		aPtr[LENG + 3] = 'X';
        		LENG = LENG + 4;
        	}
        	if(message[i] == 'x'){
        		aPtr[LENG] = '-';
        		aPtr[LENG + 1] = '*';
        		aPtr[LENG + 2] = '*';
        		aPtr[LENG + 3] = '-';
        		aPtr[LENG + 4] = 'X';
        		LENG = LENG + 5;
        	}
        	if(message[i] == 'y'){
        		aPtr[LENG] = '-';
        		aPtr[LENG + 1] = '*';
        		aPtr[LENG + 2] = '-';
        		aPtr[LENG + 3] = '-';
        		aPtr[LENG + 4] = 'X';
        		LENG = LENG + 5;
        	}
        	if(message[i] == 'z'){
        		aPtr[LENG] = '-';
        		aPtr[LENG + 1] = '-';
        		aPtr[LENG + 2] = '*';
        		aPtr[LENG + 3] = 'X';
        		LENG = LENG + 4;
        	}
        	if(message[i] == ' '){
        		aPtr[LENG] = 'X';
        		LENG = LENG + 1;
        	}
    
        delete []temporary;//Delete temporary
    }
    
    aPtr[LENG + 1] = '\0';//Add null termination at the last part of the array
    
    return aPtr;	

}

char *deleteRepeats(){
    char *word = getMessage();
    char *phrase;

    int i = 0;
    int j = 0;

    char trail = word[0];

    while(trail != '\0'){
        int count = 0;
        for (int a = 0; a <= strlen(word); a++) {
            if(word[a] == trail){
                count++;
            }
        }
    }

    cout << phrase << endl;
    cout << strlen(phrase) << endl;

    return phrase;

 }
