#define N_MAX 200

#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;


class Hangman
{ 
	// %d - int; %f - float; %c - char; %s - string
	// ifstream = 'r', reads files; ofstream = 'w', writes to files; fstream = 'a', does both + creates
public: 

	ifstream textFile; 

	string output; // puts each %c into an array + \0
	string words[N_MAX];
	string random;
	string wrong;

	size_t found;

	int correct = 0;
	int incorrect = 0;
	

	char guess;
	char guesses[N_MAX] = { ('_'), ('_'), ('_'), ('_'), ('_'), ('_'),('_') ,('_'),('_'),('_'),('_'),('_'),('_') };
	
	void start();
	void printHang();
	void randomWord();
	void analyzeChar(string input);
};
