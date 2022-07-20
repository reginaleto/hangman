#include "Hangman.h"

#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;


void Hangman::start()
{
	cout << "\tHangman";
	cout << "\n-----------------------------------\n";
}

void Hangman::printHang()
{
	switch (incorrect)
	{
	case 0:
		cout << "\n\n\t+-----+" << "\n\t|     |" << "\n\t|" << "\n\t|" << "\n\t|" << "\n    ---------\n\n"; break;
	case 1:
		cout << "\n\n\t+----+" << "\n\t|     |" << "\n\t|     O" << "\n\t|" << "\n\t|" << "\n    ---------\n\n"; break;
	case 2:
		cout << "\n\n\t+----+" << "\n\t|     |" << "\n\t|     O" << "\n\t|     |" << "\n\t|" << "\n    ---------\n\n"; break;
	case 3:
		cout << "\n\n\t+----+" << "\n\t|     |" << "\n\t|     O" << "\n\t|    /|" << "\n\t|" << "\n    ---------\n\n"; break;
	case 4:
		cout << "\n\n\t+----+" << "\n\t|     |" << "\n\t|     O" << "\n\t|    /|\\" << "\n\t|" << "\n    ---------\n\n"; break;
	case 5:
		cout << "\n\n\t+----+" << "\n\t|     |" << "\n\t|     O" << "\n\t|    /|\\" << "\n\t|    /" << "\n    ---------\n\n"; break;
	case 6:
		cout << "\n\n\t+----+" << "\n\t|     |" << "\n\t|     O" << "\n\t|    /|\\" << "\n\t|    / \\" << "\n    ---------\n\n"; break;
	}
}

void Hangman::randomWord()
{
	srand(time(NULL));
	int count = 0;
	

	textFile.open("randomwords.txt");

	for (int i = 0; i < N_MAX; i++)
	{
		while (getline(textFile, output))
		{
			words[count] = output;
			// cout << "words[" << count << "]: " << words[count] << endl;
			count++;
		}
		random = words[rand() % count];
	}

	// cout << "\nrandom word: " << random << endl;
	cout << "\nNumber of Letters: " << random.length() << endl;
	
	printHang();
	analyzeChar(random);

	textFile.close();
}

void Hangman::analyzeChar(string input)
{
	int n = input.length();

	for (int i = 0; i < N_MAX; i++)
	{
		cout << "\nMystery Word: " << guesses;
		cout << "\nIncorrect Guesses: " << wrong << endl;
		cout << "\n-----------------------------------\n";
		cout << "\nGuess a Letter: ";
		cin >> guess;

		found = input.find_first_of(guess);

		while (found != string::npos)
		{
			guesses[found] = guess;
			// cout << "guesses[" << found << "]: " << guess << endl; 
			found = input.find_first_of(guess, found + 1);
			correct++;
			cout << "\nCorrect; " << correct;
		}
		
		if (input.find(guess) != string::npos)
		{			
			// cout << "\nYes, string contains character -- " << guess << endl;
			printHang();
			
			if (correct == input.length())
			{
				cout << "\n\nYay! You saved that guy!";
			}
		}
		else
		{
			wrong = wrong + guess;
			incorrect++;

			if (incorrect >= 6)
			{
				cout << "Sorry for your loss :(";
			}

			printHang();
		}
	}
}
