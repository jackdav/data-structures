#include <iostream>
#include <cstring>
#include <string.h>
#include <stdio.h>
#include <string>

using namespace std;

char *getMessage(); //Prototype

char *messageMorse(); //prototype

char *deleteRepeats(); //prototype

char *encryptTable(); //prototype

char *encryptReplace(char*, char*); //prototype

void output(char*); //prototype

char *decrypt(); //prototype

char *decryptTwo(); //prototype

int main(){

//Part 1 encrypt
    cout << "Please enter the message you would like to encrypt: " << endl;
    char *morse = messageMorse();
        cout << morse << endl;
    char *encrypt = encryptTable();
    char *encryptMessage = encryptReplace(encrypt, morse);
    output(encryptMessage);


//Part 2 decrypt
    decryptTwo();


return 0;
}



/*********************************************************************
** Function: getMessage
** Description: This function gets the inputted cstring from the user
and adds each letter or space to the array. It is dynamically allocat-
ed each time.
** Parameters: None
** Pre-Conditions: The user inputs only letters and spaces.
** Post-Conditions: The program returns a character array of the letters
and spaces inputted by the user.
*********************************************************************/ 
char *getMessage(){

    char inputChar;
    char *aPtr;
    int LENG = 0;

    aPtr = new char[1];// Allocate 1 character for null termination
    
    while ((inputChar = cin.get()) != '\n') {//Gets input until 'enter' is pressed
        
        LENG++; //Continuously increase string length
                                   
        char *temporary = aPtr;//Saves the string
        
        aPtr = new char[LENG+1];//Allocate string to size LENG
        
        for (int i = 0; i < LENG-1; i++){//Copy aPtr to temporary
            aPtr[i] = temporary[i];
        }
        
        aPtr[LENG - 1] = inputChar;//Add the new character
        
        delete []temporary;//Delete temporary
    
    }
    
    aPtr[LENG] = '\0';//Add null termination at the last part of the array
    
    /*Function used to make all uppercase, copied and pasted from last assignment*/
    locale loc;
        for(int i = 0; i < strlen(aPtr); i++){
            aPtr[i] = toupper(aPtr[i], loc);
        }

    return aPtr;	
}



/*********************************************************************
** Function: messageMorse
** Description: This function reads the array inputted by the user and
creates a new array of *'s, -'s, and X's based on the letter equivalents
provided.
** Parameters: char *message
** Pre-Conditions: The function uses the message inputted by the user.
** Post-Conditions: The function returns the message in the form of *,
-, X.
*********************************************************************/ 
char *messageMorse(){

    char *message = getMessage();
    cout << message << endl;

	char inputChar;
    char *aPtr;
    int LENG = 0;

    aPtr = new char[1000];// Allocate 1 char for null termination
    
    for(int i = 0; message[i] != '\0'; i++) {//Gets input until 'enter' is pressed
        
        /*This set of if statements checks to see what letter message[i] is.
        Depending on the letter, the proper set of morse code is added to the
        string aPtr. LENG is increased based on how many characters are in the
        morse code for each letter.*/
        	if(message[i] == 'A'){
        		aPtr[LENG] = '*';
        		aPtr[LENG + 1] = '-';
        		aPtr[LENG + 2] = 'X';
        		LENG = LENG + 3;
        	}
        	if(message[i] == 'B'){
        		aPtr[LENG] = '-';
        		aPtr[LENG + 1] = '*';
        		aPtr[LENG + 2] = '*';
        		aPtr[LENG + 3] = '*';
        		aPtr[LENG + 4] = 'X';
        		LENG = LENG + 5;
        	}
        	if(message[i] == 'C'){
        		aPtr[LENG] = '-';
        		aPtr[LENG + 1] = '*';
        		aPtr[LENG + 2] = '-';
        		aPtr[LENG + 3] = '*';
        		aPtr[LENG + 4] = 'X';
        		LENG = LENG + 5;
        	}
        	if(message[i] == 'D'){
        		aPtr[LENG] = '-';
        		aPtr[LENG + 1] = '*';
        		aPtr[LENG + 2] = '*';
        		aPtr[LENG + 3] = 'X';
        		LENG = LENG + 4;
        	}
        	if(message[i] == 'E'){
        		aPtr[LENG] = '*';
        		aPtr[LENG + 1] = 'X';
        		LENG = LENG + 2;
        	}
        	if(message[i] == 'F'){
        		aPtr[LENG] = '*';
        		aPtr[LENG + 1] = '*';
        		aPtr[LENG + 2] = '-';
        		aPtr[LENG + 3] = '*';
        		aPtr[LENG + 4] = 'X';
        		LENG = LENG + 5;
        	}
        	if(message[i] == 'G'){
        		aPtr[LENG] = '-';
        		aPtr[LENG + 1] = '-';
        		aPtr[LENG + 2] = '*';
        		aPtr[LENG + 3] = 'X';
        		LENG = LENG + 4;
        	}
        	if(message[i] == 'H'){
        		aPtr[LENG] = '*';
        		aPtr[LENG + 1] = '*';
        		aPtr[LENG + 2] = '*';
        		aPtr[LENG + 3] = '*';
        		aPtr[LENG + 4] = 'X';
        		LENG = LENG + 5;
        	}
        	if(message[i] == 'I'){
        		aPtr[LENG] = '*';
        		aPtr[LENG + 1] = '*';
        		aPtr[LENG + 2] = 'X';
        		LENG = LENG + 3;
        	}
        	if(message[i] == 'J'){
        		aPtr[LENG] = '*';
        		aPtr[LENG + 1] = '-';
        		aPtr[LENG + 2] = '-';
        		aPtr[LENG + 3] = '-';
        		aPtr[LENG + 4] = 'X';
        		LENG = LENG + 5;
        	}
        	if(message[i] == 'K'){
        		aPtr[LENG] = '-';
        		aPtr[LENG + 1] = '*';
        		aPtr[LENG + 2] = '-';
        		aPtr[LENG + 3] = 'X';
        		LENG = LENG + 4;
        	}
        	if(message[i] == 'L'){
        		aPtr[LENG] = '*';
        		aPtr[LENG + 1] = '-';
        		aPtr[LENG + 2] = '*';
        		aPtr[LENG + 3] = '*';
        		aPtr[LENG + 4] = 'X';
        		LENG = LENG + 5;
        	}
        	if(message[i] == 'M'){
        		aPtr[LENG] = '-';
        		aPtr[LENG + 1] = '-';
        		aPtr[LENG + 2] = 'X';
        		LENG = LENG + 3;
        	}
        	if(message[i] == 'N'){
        		aPtr[LENG] = '-';
        		aPtr[LENG + 1] = '*';
        		aPtr[LENG + 2] = 'X';
        		LENG = LENG + 3;
        	}
        	if(message[i] == 'O'){
        		aPtr[LENG] = '-';
        		aPtr[LENG + 1] = '-';
        		aPtr[LENG + 2] = '-';
        		aPtr[LENG + 3] = 'X';
        		LENG = LENG + 4;
        	}
        	if(message[i] == 'P'){
        		aPtr[LENG] = '*';
        		aPtr[LENG + 1] = '-';
        		aPtr[LENG + 2] = '-';
        		aPtr[LENG + 3] = '*';
        		aPtr[LENG + 4] = 'X';
        		LENG = LENG + 5;
        	}
        	if(message[i] == 'Q'){
        		aPtr[LENG] = '-';
        		aPtr[LENG + 1] = '-';
        		aPtr[LENG + 2] = '*';
        		aPtr[LENG + 3] = '-';
        		aPtr[LENG + 4] = 'X';
        		LENG = LENG + 5;
        	}
        	if(message[i] == 'R'){
        		aPtr[LENG] = '*';
        		aPtr[LENG + 1] = '-';
        		aPtr[LENG + 2] = '*';
        		aPtr[LENG + 3] = 'X';
        		LENG = LENG + 4;
        	}
        	if(message[i] == 'S'){
        		aPtr[LENG] = '*';
        		aPtr[LENG + 1] = '*';
        		aPtr[LENG + 2] = '*';
        		aPtr[LENG + 3] = 'X';
        		LENG = LENG + 4;
        	}
        	if(message[i] == 'T'){
        		aPtr[LENG] = '-';
        		aPtr[LENG + 1] = 'X';
        		LENG = LENG + 2;
        	}
        	if(message[i] == 'U'){
        		aPtr[LENG] = '*';
        		aPtr[LENG + 1] = '*';
        		aPtr[LENG + 2] = '-';
        		aPtr[LENG + 3] = 'X';
        		LENG = LENG + 4;
        	}
        	if(message[i] == 'V'){
        		aPtr[LENG] = '*';
        		aPtr[LENG + 1] = '*';
        		aPtr[LENG + 2] = '*';
        		aPtr[LENG + 3] = '-';
        		aPtr[LENG + 4] = 'X';
        		LENG = LENG + 5;
        	}
        	if(message[i] == 'W'){
        		aPtr[LENG] = '*';
        		aPtr[LENG + 1] = '-';
        		aPtr[LENG + 2] = '-';
        		aPtr[LENG + 3] = 'X';
        		LENG = LENG + 4;
        	}
        	if(message[i] == 'X'){
        		aPtr[LENG] = '-';
        		aPtr[LENG + 1] = '*';
        		aPtr[LENG + 2] = '*';
        		aPtr[LENG + 3] = '-';
        		aPtr[LENG + 4] = 'X';
        		LENG = LENG + 5;
        	}
        	if(message[i] == 'Y'){
        		aPtr[LENG] = '-';
        		aPtr[LENG + 1] = '*';
        		aPtr[LENG + 2] = '-';
        		aPtr[LENG + 3] = '-';
        		aPtr[LENG + 4] = 'X';
        		LENG = LENG + 5;
        	}
        	if(message[i] == 'Z'){
        		aPtr[LENG] = '-';
        		aPtr[LENG + 1] = '-';
                aPtr[LENG + 2] = '*';
        		aPtr[LENG + 3] = '*';
        		aPtr[LENG + 4] = 'X';
        		LENG = LENG + 5;
        	}
        	if(message[i] == ' '){
        		aPtr[LENG] = 'X';
        		LENG = LENG + 1;
        	}
    
    }
    
    aPtr[LENG] = 'X';
    aPtr[LENG + 1] = '\0';//Add null termination at the last part of the array
    
    return aPtr;	

}



/*********************************************************************
** Function: deleteRepeats
** Description: This function takes in a keyword to use for Table 2. It
deletes repeat letters from the keyword.
** Parameters: None
** Pre-Conditions: The user inputs a word.
** Post-Conditions: The function returns the word with no repeat letters.
*********************************************************************/ 
char *deleteRepeats(){

    cout << "Please enter the one-word password: " << endl;

    char *word = getMessage(); //Use getMessage to get keyword
    char *phrase = new char[26]; //phrase wont be bigger than 26

    int i = 0;
    int j = 0;

    /*This while loop reads each letter in the keyword. It checks to see if 
    that letter exists in the new phrase or not. If it doesn't the letter is 
    added to phrase. If it is, the letter is not added. The result is phrase
    which is word without any duplicate letters.*/
    while(i < strlen(word)){
        char letter = word[i];
        char *exist = strchr(phrase, letter);
            if(exist == NULL){
                phrase[j] = letter;
                j++;
            }
    i++;
    }

    phrase[j] = '\0';//Add null terminator to phrase

    return phrase;
 }



/*********************************************************************
** Function: encryptTable
** Description: The function takes the keyword from deleteRepeat and 
puts it into an array and adds the rest of the alphabet to the array.
** Parameters: char *phrase
** Pre-Conditions: The word used is a word with no repeat letters
** Post-Conditions: The function returns an array with the alphabet
rearranged.
*********************************************************************/ 
 char *encryptTable(){
    
    char *phrase = deleteRepeats();

    int length = strlen(phrase);
    int j = 0;
    int i = 0;
    //character array for the alphabet
    char alphabet[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char *alpha = new char[27];

    /*This while loop uses the same thought process as deleteRepeats.
    It walks through each letter in alphabet and checks to see if that letter
    exists in a new array. The new array contains phrase in the first elements.
    If the letter in alphabet doesnt exist in the new array yet, it is added.*/
    while(i < strlen(alphabet)){
            while(j < strlen(phrase)){
                alpha[j] = phrase[j];
                j++;
            }
            char letter = alphabet[i];
            char *exist = strchr(alpha, letter);
            if(exist == NULL){
                alpha[j] = letter;
                j++;
            }
    i++;
    }
    alpha[j] = '\0'; //Add null terminator
    return alpha;

 }



/*********************************************************************
** Function: encryptReplace
** Description: The function uses table 2 to change the morse string
into new letters
** Parameters: char *alpha and char *morse
** Pre-Conditions: The morse code and the alpha arryy
** Post-Conditions: The function returns the encrypted message.
*********************************************************************/ 
 char *encryptReplace(char *alpha, char *morse){

    int i = 0;
    int j = 0;
    char *code = new char[4];
    char *encrypt = new char[200];
   
    /*This while loop creates char arrays for each column from table 2.
    It uses strcmp to see if that char array matches the set of three 
    characters from the morse code. If it does, the encrypted message
    array gets the letter associated with the column from table 2.*/
    while (i < strlen(morse)){
        /*Code is each set of three characters from the morse code
        cstring*/
        code[0] = morse[i];
        code[1] = morse[i + 1];
        code[2] = morse[i + 2];
        code[3] = '\0';
    
            char one[4] = {'*','*','*', '\0'}; //Column one morse
            if(strcmp(code, one) == 0){ //Does the set of three match column one?
                encrypt[j] = alpha[0]; //If so, the letter associated is added
            }
            char two[4] = {'*','*','-', '\0'};
            if(strcmp(code, two) == 0){
                encrypt[j] = alpha[1];
            }
            char three[4] = {'*','*','X', '\0'};
            if(strcmp(code, three) == 0){
                encrypt[j] = alpha[2];
            }
            char four[4] = {'*','-','*', '\0'};
            if(strcmp(code, four) == 0){
                encrypt[j] = alpha[3];
            }
            char five[4] = {'*','-','-', '\0'};
            if(strcmp(code, five) == 0){
                encrypt[j] = alpha[4];
            }
            char six[4] = {'*','-','X', '\0'};
            if(strcmp(code, six) == 0){
                encrypt[j] = alpha[5];
            }
            char seven[4] = {'*','X','*', '\0'};
            if(strcmp(code, seven) == 0){
                encrypt[j] = alpha[6];
            }
            char eight[4] = {'*','X','-', '\0'};
            if(strcmp(code, eight) == 0){
                encrypt[j] = alpha[7];
            }
            char nine[4] = {'*','X','X', '\0'};
            if(strcmp(code, nine) == 0){
                encrypt[j] = alpha[8];
            }
            char ten[4] = {'-','*','*', '\0'};
            if(strcmp(code, ten) == 0){
                encrypt[j] = alpha[9];
            }
            char eleven[4] = {'-','*','-', '\0'};
            if(strcmp(code, eleven) == 0){
                encrypt[j] = alpha[10];
            }
            char twelve[4] = {'-','*','X', '\0'};
            if(strcmp(code, twelve) == 0){
                encrypt[j] = alpha[11];
            }
            char thirteen[4] = {'-','-','*', '\0'};
            if(strcmp(code, thirteen) == 0){
                encrypt[j] = alpha[12];
            }
            char fourteen[4] = {'-','-','-', '\0'};
            if(strcmp(code, fourteen) == 0){
                encrypt[j] = alpha[13];
            }
            char fifteen[4] = {'-','-','X', '\0'};
            if(strcmp(code, fifteen) == 0){
                encrypt[j] = alpha[14];
            }
            char sixteen[4] = {'-','X','*', '\0'};
            if(strcmp(code, sixteen) == 0){
                encrypt[j] = alpha[15];
            }
            char seventeen[4] = {'-','X','-', '\0'};
            if(strcmp(code, seventeen) == 0){
                encrypt[j] = alpha[16];
            }
            char eighteen[4] = {'-','X','X', '\0'};
            if(strcmp(code, eighteen) == 0){
                encrypt[j] = alpha[17];
            }
            char nineteen[4] = {'X','*','*', '\0'};
            if(strcmp(code, nineteen) == 0){
                encrypt[j] = alpha[18];
            }
            char twenty[4] = {'X','*','-', '\0'};
            if(strcmp(code, twenty) == 0){
                encrypt[j] = alpha[19];
            }
            char twentyone[4] = {'X','*','X', '\0'};
            if(strcmp(code, twentyone) == 0){
                encrypt[j] = alpha[20];
            }
            char twentytwo[4] = {'X','-','*', '\0'};
            if(strcmp(code, twentytwo) == 0){
                encrypt[j] = alpha[21];
            }
            char twentythree[4] = {'X','-','-', '\0'};
            if(strcmp(code, twentythree) == 0){
                encrypt[j] = alpha[22];
            }
            char twentyfour[4] = {'X','-','X', '\0'};
            if(strcmp(code, twentyfour) == 0){
                encrypt[j] = alpha[23];
            }
            char twentyfive[4] = {'X','X','*', '\0'};
            if(strcmp(code, twentyfive) == 0){
                encrypt[j] = alpha[24];
            }
            char twentysix[4] = {'X','X','-', '\0'};
            if(strcmp(code, twentysix) == 0){
                encrypt[j] = alpha[25];
            }

    i = i + 3;
    j++;
    }
    encrypt[j] = '\0'; //Add null terminator
    return encrypt;
 }



/*********************************************************************
** Function: output
** Description: This function takes the encrypted message and divides it
into sets of 5
** Parameters: char *encrypt 
** Pre-Conditions: The message is of letters.
** Post-Conditions: Outputs the message divided into groups of 5
*********************************************************************/ 
void output(char *encrypt){
    
    cout << "The encrypted message is: " << endl;

    int i = 0;
    for(int j = 0; j < strlen(encrypt); j++){
        cout << encrypt[j];
        if(j == (5*i + 4)){ //Add a space at every 5th letter
            cout << " ";
            i++;
        }
    }
    cout << endl;
}



/*********************************************************************
** Function: decrypt
** Description: This function takes the encrypted message and turns it
back into *-X.
** Parameters: char *encrypt, char *alpha, char *aPtr 
** Pre-Conditions: The function takes in the morse message and a few
arrays. 
** Post-Conditions: The function returns the decrypted message back into
morse code.
*********************************************************************/ 
char *decrypt(){

    cout << endl;
    //Ask user if they want to decrypt the message now
    cout << "Enter the message you would like to decrypt: " << endl;
    char *temporary = getMessage();

    char *code = new char[300];
    int i = 0;
    int j = 0;

    /*This block of code reads the inputted decrypted message and removes
    any spaces from it.*/
    char *encrypt = new char [300];
    int h = 0;
    int k = 0;
    while(h < strlen(temporary)){
        if(temporary[h] != ' '){
            encrypt[k] = temporary[h];
            k++;
        }
        h++;
    }

    /*Create new table 2 using password*/
    char *alpha = encryptTable();


    /*This while loop reads the encrypted message. If the letter in the
    encrypted message is equal to a certain letter column from table two,
    the morse code equivalent is added to a new string that stores the 
    morse code again.*/
    while(j < strlen(encrypt)){

            if(encrypt[j] == alpha[0]){ //Does the letter equal the first letter in Table 2?
                code[i] = '*'; //If so, these elements are added to the new array
                code[i + 1] = '*';
                code[i + 2] = '*';
            }
            if(encrypt[j] == alpha[1]){
                code[i] = '*';
                code[i + 1] = '*';
                code[i + 2] = '-';
            }
            if(encrypt[j] == alpha[2]){
                code[i] = '*';
                code[i + 1] = '*';
                code[i + 2] = 'X';
            }
            if(encrypt[j] == alpha[3]){
                code[i] = '*';
                code[i + 1] = '-';
                code[i + 2] = '*';
            }
            if(encrypt[j] == alpha[4]){
                code[i] = '*';
                code[i + 1] = '-';
                code[i + 2] = '-';
            }
            if(encrypt[j] == alpha[5]){
                code[i] = '*';
                code[i + 1] = '-';
                code[i + 2] = 'X';
            }
            if(encrypt[j] == alpha[6]){
                code[i] = '*';
                code[i + 1] = 'X';
                code[i + 2] = '*';
            }
            if(encrypt[j] == alpha[7]){
                code[i] = '*';
                code[i + 1] = 'X';
                code[i + 2] = '-';
            }
            if(encrypt[j] == alpha[8]){
                code[i] = '*';
                code[i + 1] = 'X';
                code[i + 2] = 'X';
            }
            if(encrypt[j] == alpha[9]){
                code[i] = '-';
                code[i + 1] = '*';
                code[i + 2] = '*';
            }
            if(encrypt[j] == alpha[10]){
                code[i] = '-';
                code[i + 1] = '*';
                code[i + 2] = '-';
            }
            if(encrypt[j] == alpha[11]){
                code[i] = '-';
                code[i + 1] = '*';
                code[i + 2] = 'X';
            }
            if(encrypt[j] == alpha[12]){
                code[i] = '-';
                code[i + 1] = '-';
                code[i + 2] = '*';
            }
            if(encrypt[j] == alpha[13]){
                code[i] = '-';
                code[i + 1] = '-';
                code[i + 2] = '-';
            }
            if(encrypt[j] == alpha[14]){
                code[i] = '-';
                code[i + 1] = '-';
                code[i + 2] = 'X';
            }
            if(encrypt[j] == alpha[15]){
                code[i] = '-';
                code[i + 1] = 'X';
                code[i + 2] = '*';
            }
            if(encrypt[j] == alpha[16]){
                code[i] = '-';
                code[i + 1] = 'X';
                code[i + 2] = '-';
            }
            if(encrypt[j] == alpha[17]){
                code[i] = '-';
                code[i + 1] = 'X';
                code[i + 2] = 'X';
            }
            if(encrypt[j] == alpha[18]){
                code[i] = 'X';
                code[i + 1] = '*';
                code[i + 2] = '*';
            }
            if(encrypt[j] == alpha[19]){
                code[i] = 'X';
                code[i + 1] = '*';
                code[i + 2] = '-';
            }
            if(encrypt[j] == alpha[20]){
                code[i] = 'X';
                code[i + 1] = '*';
                code[i + 2] = 'X';
            }
            if(encrypt[j] == alpha[21]){
                code[i] = 'X';
                code[i + 1] = '-';
                code[i + 2] = '*';
            }
            if(encrypt[j] == alpha[22]){
                code[i] = 'X';
                code[i + 1] = '-';
                code[i + 2] = '-';
            }
            if(encrypt[j] == alpha[23]){
                code[i] = 'X';
                code[i + 1] = '-';
                code[i + 2] = 'X';
            }
            if(encrypt[j] == alpha[24]){
                code[i] = 'X';
                code[i + 1] = 'X';
                code[i + 2] = '*';
            }
            if(encrypt[j] == alpha[25]){
                code[i] = 'X';
                code[i + 1] = 'X';
                code[i + 2] = '-';
            }
        
        i = i + 3; //Increment code by three
        j++; //Read the encrypted message one by one
    }

    code[i] = '\0'; //Add null terminator
    cout << code << endl;

    return code;

}



/*********************************************************************
** Function: decryptTwo
** Description: This function takes the morse code and based on Table 1,
turns it back into words.
** Parameters: char *code
** Pre-Conditions: This function takes in a cstring of X*- and turns it
back into the words originally inputted.
** Post-Conditions: This function returns the original message.
*********************************************************************/ 
char *decryptTwo(){

  char *code = decrypt();

  char *pch;
  char *out = new char[300];
  pch = strtok (code,"X"); //Divide the string into tokens that are separated by X
  int hi = 0;

  /*This while loop goes until pch doesnt equal null. Pch is each token. New char arrays
  are created for each letter from table 1. If the token is equal to these char arrays,
  the associated letter is stored into a new array.*/
  while (pch != NULL){
    char a[] = {'*', '-','\0'}; //Char array for letter A
    if(strcmp(pch, a) == 0){ //Does the token equal this string of chars?
        out[hi] = 'A'; //If so, A is added to the message
    }
    char b[] = {'-', '*', '*', '*','\0'};
    if(strcmp(pch, b) == 0){
        out[hi] = 'B';
    }
    char c[] = {'-', '*', '-', '*','\0'};
    if(strcmp(pch, c) == 0){
        out[hi] = 'C';
    }
    char d[] = {'-', '*', '*','\0'};
    if(strcmp(pch, d) == 0){
        out[hi] = 'D';
    }
    char e[] = {'*','\0'};
    if(strcmp(pch, e) == 0){
        out[hi] = 'E';
    }
    char f[] = {'*', '*', '-', '*','\0'};
    if(strcmp(pch, f) == 0){
        out[hi] = 'F';
    }
    char g[] = {'-','-','*','\0'};
    if(strcmp(pch, g) == 0){
        out[hi] = 'G';
    }
    char h[] = {'*','*','*','*','\0'};
    if(strcmp(pch, h) == 0){
        out[hi] = 'H';
    }
    char i[] = {'*','*','\0'};
    if(strcmp(pch, i) == 0){
        out[hi] = 'I';
    }
    char j[] = {'*','-','-','-','\0'};
    if(strcmp(pch, j) == 0){
        out[hi] = 'J';
    }
    char k[] = {'-','*','-','\0'};
    if(strcmp(pch, k) == 0){
        out[hi] = 'K';
    }
    char l[] = {'*','-','*','*','\0'};
    if(strcmp(pch, l) == 0){
        out[hi] = 'L';
    }
    char m[] = {'-','-','\0'};
    if(strcmp(pch, m) == 0){
        out[hi] = 'M';
    }
    char n[] = {'-','*','\0'};
    if(strcmp(pch, n) == 0){
        out[hi] = 'N';
    }
    char o[] = {'-','-','-','\0'};
    if(strcmp(pch, o) == 0){
        out[hi] = 'O';
    }
    char p[] = {'*','-','-','*','\0'};
    if(strcmp(pch, p) == 0){
        out[hi] = 'P';
    }
    char q[] = {'-','-','*','-','\0'};
    if(strcmp(pch, q) == 0){
        out[hi] = 'Q';
    }
    char r[] = {'*','-','*','\0'};
    if(strcmp(pch, r) == 0){
        out[hi] = 'R';
    }
    char s[] = {'*','*','*','\0'};
    if(strcmp(pch, s) == 0){
        out[hi] = 'S';
    }
    char t[] = {'-','\0'};
    if(strcmp(pch, t) == 0){
        out[hi] = 'T';
    }
    char u[] = {'*','*','-','\0'};
    if(strcmp(pch, u) == 0){
        out[hi] = 'U';
    }
    char v[] = {'*','*','*','-','\0'};
    if(strcmp(pch, v) == 0){
        out[hi] = 'V';
    }
    char w[] = {'*','-','-','\0'};
    if(strcmp(pch, w) == 0){
        out[hi] = 'W';
    }
    char x[] = {'-','*','*','-','\0'};
    if(strcmp(pch, x) == 0){
        out[hi] = 'X';
    }
    char y[] = {'-','*','-','-','\0'};
    if(strcmp(pch, y) == 0){
        out[hi] = 'Y';
    }
    char z[] = {'-','-','*','*','\0'};
    if(strcmp(pch, z) == 0){
        out[hi] = 'Z';
    }

    pch = strtok (NULL, "X"); 

    hi++;

  }
  
  cout << out << endl;
  
  return out;
}

