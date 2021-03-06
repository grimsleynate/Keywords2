// Keywords2.cpp
// Nathaniel Grimsley
// November 4, 2018

//we are including all the required dependencies.
#include "pch.h"
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

//this is the beginning of the main function, where code execution begins and ends.
int main()
{
	//We want to compare how many incorrect choices the user has guessed.
	const int MAX_WRONG = 8;
	// Display Title of program to user
	cout << "***********************************************************\n";
	cout << "                     Keywords 2\n\n";
	// Ask the recruit to login using their name
	cout << "Please log in using your last name: \n\n";
	// Hold the recruit's name in a var, and address them by it throughout the simulation.
	string name = "";
	cin >> name;

	//Welcome the user to the game
	cout << "\nWelcome to Keywords 2, " << name << "." << endl;
	// Display an overview of what Keywords II is to the recruit 
	cout << "Your are tasked with finding three random words.\n";
	cout << "You will not be given any hints. Every turn you\n";
	cout << "may guess a word. The correct letters will be shown\n";
	cout << "upon guessing them. You have " << MAX_WRONG << " tries per word.\n";
	cout << "Good luck, " << name << "." << endl;
	// Display an directions to the recruit on how to use Keywords
	cout << "\nHow to Play:\n\n";
	cout << "Type a letter and press enter to guess.\n";
	cout << "Type '9' at any point to exit the game.\n";
	cout << "You have " << MAX_WRONG << " guess per word.";

	// Create a collection of 10 words you had wrote down manually
	// To start, we create a constant integer to act as the list cap.
	const int NUM_WORDS = 10;
	//now we create a string list with NUM_WORDS as the list cap.
	const string WORDS[NUM_WORDS] = { "ESPIONAGE", "MOLE", "HIDING", "ASSET", "BACKSTOP", "SLEEPER", "AGENT", "SURVEILLANCE", "PHISHING", "DEFECTOR" };

	// Create an int var to count the number of simulations being run starting at 1
	int sims = 1;
	//we create a variable to store the user's choice to play again.
	char playAgain = 'y';
	//we create a variable to store the users guess
	char guess = '1';
	
	//now we start the game loop, making sure the loop ends if the user types 'quit' or chooses 'n' after completing the simulation.
	while (playAgain == 'y' && guess != '9')
	{
		// Display the simulation # is starting to the recruit. 
		cout << "\n\nNow beginning simulation number: " << sims << endl;

		// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
		// To do this, we seed the random number generator so it is more random
		srand(static_cast<unsigned int>(time(0)));
		// Now we grab three random words from the array.
		string choice1 = WORDS[rand() % NUM_WORDS];
		string choice2 = WORDS[rand() % NUM_WORDS];
		string choice3 = WORDS[rand() % NUM_WORDS];

		//then we protect ourselves from having duplicate words
		while (choice1 == choice2 || choice1 == choice3 || choice2 == choice3)
		{
			//while any of the choices is the same as the other, randomize them again.
			choice1 = WORDS[rand() % NUM_WORDS];
			choice2 = WORDS[rand() % NUM_WORDS];
			choice3 = WORDS[rand() % NUM_WORDS];
		}
		// now we want to concatenate the three words together to come up with the keyword.
		string keyword = choice1 + " " + choice2 + " " + choice3;

		//finally, we want a variable to store the number of incorrect guesses.
		int wrong = 0;
		//we create a string to store the current guess.
		string soFar(keyword.size(), '-');
		//we fill the spaces in the words with actual spaces
		soFar[choice1.size()] = ' ';
		soFar[(choice1.size() + choice2.size() + 1)] = ' ';
		//we create a variable to store the letters guessed so far.
		string used = "";

		// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
		while ((wrong != MAX_WRONG) && (guess != '9') && (soFar != keyword))
		{
			//Tell recruit how many incorrect guesses he or she has left
			cout << "You have " << MAX_WRONG - wrong << " guess left.\n";
			//Show recruit the letters he or she has guessed
			cout << "You have used the following letters: " << used << endl;
			//Show player how much of the secret word he or she has guessed
			cout << "So far, the word is: " << soFar << endl;
			//Get recruit's next guess
			cout << "\nEnter your guess: ";
			cin >> guess;
			//We take the user's guess and switch it to all uppercase, making it easier to test against.
			guess = toupper(guess);
			//While recruit has entered a letter that he or she has already guessed
			while (used.find(guess) != string::npos)
			{
				//Get recruit ’s guess
				cout << "\nYou have already entered " << guess;
				cout << "\nEnter your guess: ";
				cin >> guess;
				guess = toupper(guess);
			}
			//Add the new guess to the group of used letters
			used += guess;

			//If the guess is in the secret word
			if (keyword.find(guess) != string::npos)
			{

				//Tell the recruit the guess is correct
				cout << "That's right! " << guess << " is in the word.\n";
				//Update the word guessed so far with the new letter
				for (int i = 0; i < keyword.length(); ++i)
				{
					//if the current character in the string choice1 is equal to the guess
					if (keyword[i] == guess)
					{
						soFar[i] = guess;
					}
				}
			}
			//Otherwise
			else
			{
				//Tell the recruit the guess is incorrect
				cout << "Sorry, " << guess << " isn't in the word.\n";
				//Increment the number of incorrect guesses the recruit has made
				++wrong;
			}
		}

		// If the recruit has made too many incorrect guesses
		if (wrong == MAX_WRONG)
		{
			//Tell the recruit that he or she has failed the Keywords II course.
			cout << "\nYou have failed the CIA Keywords Training.";
		}

		// Otherwise
		else
		{
			//Congratulate the recruit on guessing the secret words
			cout << "\nCongratulations " << name << " , you guessed the keywords.\n";
			//Let them know what the words were
			cout << "The correct keywords are: " << soFar << endl;
			// Ask the recruit if they would like to run the simulation again
			cout << "Would you like to run the simulation again? (y/n) ";
			cin >> playAgain;
		}
		// If the recruit wants to run the simulation again
		if (playAgain == 'y')
		{
			//Increment the number of simiulations ran counter
			sims++;
			//Move program execution back up to // Display the simulation # is starting to the recruit. 
			continue;
		}
		// Otherwise 
		else {
			//Display End of Simulations to the recruit
			cout << "\n\nYou have chosen to end the simulation, " << name << ".\n";
			cout << "Log in again at any time to practice again.\n";
			cout << "Thank you for playing.\n";
			//Pause the Simulation with press any key to continue 
			system("pause");
		}
	}
	return 0;
}
