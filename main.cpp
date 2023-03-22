/*
    filename: hangman.cpp
    summary: host a game of hangman
    author: Abdurrahman Alyajouri
    date: 3/20/2023
    
    Program 1
*/

#include <iostream>
#include <string>

using namespace std;

char getUserChar(char[]);
void fillArray(char[]);
void searchWord(char[], char[], char, int&, int&);
bool checkWord(char[]);
void displayHangman(int);
void printIncorrect(char[]);

const string word = "pneumonoultramicroscopicsilicovolcanoconiosis";
const int SIZE = word.length();
const string hangman = "O/|\\/\\";

int main() {
    
    char guess,
         construct_word[SIZE],
         incorrect_letters[6];
    
    int fails;
        
    fillArray(construct_word);
        
    fails = 0;
    
    int k = 0;
    
    do {
        int guess = getUserChar(incorrect_letters);
        searchWord(construct_word, incorrect_letters, guess, fails, k);
        if(!checkWord(construct_word)) {
            cout << "You guessed the word! It was " << word;
            break;
        } else if(fails > 5) {
            cout << "You ran out of guesses. The word was " << word;
            break;
        }
    } while(fails < 6);

    return 0;
}

void printIncorrect(char array[]) {
    for(int i = 0; i < 6; i++) {
        cout << array[i] << ' ';
    }
}

char getUserChar(char array[]) {
    char userChar;
    cout << "Guess a letter in the mystery word! (All lowercase letters)\n";
    cout << "Incorrect Letters so far: "; 
    printIncorrect(array);
    cout << endl;
    cin.get(userChar);
    cin.ignore();
    return userChar;
}

void fillArray(char array[]) {
    for(int i = 0; i < SIZE; i++) {
        array[i] = '_';
    }
}

void searchWord(char array[], char array2[], char guess, int& fails, int& k) {
    if(word.find(guess) < SIZE) {
        cout << "Letter " << guess << " is in the mystery word!\n";
        for(int i = 0; i < SIZE; i++) {
            if(word[i] == guess) {
                array[i] = guess;
            }
            cout << array[i];
        }
        cout << endl;
    } else {
        array2[k++] = guess;
        fails++;
        displayHangman(fails);
        cout << "Letter " << guess << " is not in the mystery word!\n";
        cout << "You have " << 6 - fails << " guesses left!\n";
    }
}

bool checkWord(char array[]) {
    int counter = 0;
    bool result = false;
    for(int i = 0; i < SIZE; i++) {
        if(array[i] == '_') {
            counter++;
        }
    }
    if(counter > 0) {
        result = true;
    }
    return result;
}

void displayHangman(int fails) {
    cout << ' ';
    for(int i = 0; i < fails; i++) {
        if(i == 1) {
            cout << endl;
        }
        if(i == 4) {
            cout << endl;
        }
        if(i == 5) {
            cout << ' ';
        }
        cout << hangman[i];
    }   
    cout << endl << endl;
}
























