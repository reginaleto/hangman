#define _CRT_SECURE_NO_WARNINGS
#include "Hangman.h"

#include <iostream>
#include <string>
#include <fstream>
#include <time.h>


using namespace std;

int main()
{
	Hangman player;

	player.start();
	player.randomWord();

}
