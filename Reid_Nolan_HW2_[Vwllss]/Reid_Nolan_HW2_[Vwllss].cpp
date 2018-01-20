/* Reid_Nolan_HW2_[Vwllss].cpp : Defines the entry point for the console application.
Author: Reid Nolan
Date: 02-01-2017
C++ program that prompts the user to input a string. The program then uses a user-defined function to
remove all ofthe vowels, consonants, digits, or custom data from a string input by the user.*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

//function prototypes
void removeVowels(string userInput, char *newArray, int vowelCount, int stringLength, int newArrayCounter);
void removeConsonants(string userInput, char *newArray, int consonantCount, int stringLength, int newArrayCounter);
void removeDigits(string userInput, char *newArray, int digitCount, int stringLength, int newArrayCounter);
void removePunctuation(string userInput, char *newArray, int punctuationCount, int stringLength, int newArrayCounter);

//main
int main()
{
	//variable for continue until exit loop
	bool userDone = false;	

	//display program header
	cout << "Reid_Nolan_HW2_[Vwllss]" << endl << endl;

	while(!userDone)
	{
		//declare and initialize variables
		bool stringGood = false;
		bool menuGood = false;
		char menuSelection = '\0';
		string userInput = "";
		int vowelCount = 0;
		int consonantCount = 0;
		int digitCount = 0;
		int punctuationCount = 0;
		int customCount = 0;
		int stringLength = 0;
		int newArrayCounter = 0;		

		//prompt for and validate input
		while (!stringGood)
		{
			//prompt user for input, read input from console, store length of string to variable
			cout << "Enter a string: ";
			getline(cin, userInput);
			stringLength = userInput.length();
			cout << endl;
			//cout << "stringLength = " << stringLength << endl;

			if(stringLength > 0)
			{
				stringGood = true;
				break;
			}
			else 
			{
				cout << "You did not enter anything. Try again." << endl;
			}
		}

		//declare and initialize dynamic array elements
		char *newArray = new char[stringLength];
		for (int i = 0; i < stringLength; i++)
		{
			newArray[i] = { '\0' };
		}

		//confirm user entry
		cout << "You typed: \"" << userInput << "\"" << endl << endl;

		//display option menu and get selection
		cout << "Please select from one of the options below." << endl;
		cout << "1. Remove vowels." << endl;
		cout << "2. Remove consonants." << endl;
		cout << "3. Remove digits." << endl;
		cout << "4. Remove punctuation." << endl;
		cout << "5. Exit program." << endl;		
		
		while (!menuGood)
		{
			cout << "Selection: ";
			cin >> menuSelection;
			//drop newline character from buffer
			cin.ignore(512, '\n');

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(512, '\n');
			}
			else
			{
				//no else needed
			}

			//switch for menu option
			switch (menuSelection)
			{
			case '1':
				removeVowels(userInput, newArray, vowelCount, stringLength, newArrayCounter);
				menuGood = true;
				break;
			case '2':
				removeConsonants(userInput, newArray, consonantCount, stringLength, newArrayCounter);
				menuGood = true;
				break;
			case '3':
				removeDigits(userInput, newArray, digitCount, stringLength, newArrayCounter);
				menuGood = true;
				break;
			case '4':
				removePunctuation(userInput, newArray, punctuationCount, stringLength, newArrayCounter);
				menuGood = true;
				break;
			case '5':
				cout << "exiting program...";
				delete[] newArray;
				exit(1);
			default:
				cout << "Invalid input. Try again." << endl;
				break;
			}
		}		
		delete[] newArray;
	}	
}

//function to remove vowels from string
void removeVowels(string userInput, char *newArray, int vowelCount, int stringLength, int newArrayCounter)
{	
	//loop to check string for vowels
	for(int i = 0; i < stringLength; i++)
	{
		//check for vowels
		if (userInput[i] == 'a' || userInput[i] == 'e' || userInput[i] == 'i' || userInput[i] == 'o' || userInput[i] == 'u' || userInput[i] == 'A' || userInput[i] == 'E' || userInput[i] == 'I' || userInput[i] == 'O' || userInput[i] == 'U')
		{
			vowelCount++;
		}
		else
		{
			//if not a vowel copy string element to new array element
			newArray[newArrayCounter] = userInput[i];
			newArrayCounter++;
		}
	}

	//output new string without vowels and display number of vowels removed
	cout << endl << "String w/vowels removed: \"";
	for(int i = 0; i < newArrayCounter; i++)
	{
		cout << newArray[i] << "";
	}
	cout << "\"" << endl;
	cout << "Vowels removed: " << vowelCount << endl << endl << endl;
}

//function to remove consonants from string
void removeConsonants(string userInput, char *newArray, int consonantCount, int stringLength, int newArrayCounter)
{
	//loop to check string for vowels
	for(int i = 0; i < stringLength; i++)
	{
		//check for vowels
		if (userInput[i] == 'a' || userInput[i] == 'e' || userInput[i] == 'i' || userInput[i] == 'o' || userInput[i] == 'u' || userInput[i] == 'A' || userInput[i] == 'E' || userInput[i] == 'I' || userInput[i] == 'O' || userInput[i] == 'U')
		{
			//if not a consonant copy string element to new array element
			newArray[newArrayCounter] = userInput[i];
			newArrayCounter++;
		}
		else
		{
			consonantCount++;
		}
	}

	//output new string without consonants and display number of consonants removed
	cout << endl << "String w/consonants removed: \"";
	for(int i = 0; i < newArrayCounter; i++)
	{
		cout << newArray[i] << "";
	}
	cout << "\"" << endl;
	cout << "Consonants removed: " << consonantCount << endl << endl << endl;
}

//function to remove digits from string
void removeDigits(string userInput, char *newArray, int digitCount, int stringLength, int newArrayCounter)
{
	//loop to check string for digits
	for(int i = 0; i < stringLength; i++)
	{
		//check for digits
		if (isdigit(userInput[i]))
		{
			digitCount++;
		}
		else
		{			
			//if not a digit copy string element to new array element
			newArray[newArrayCounter] = userInput[i];
			newArrayCounter++;
		}
	}

	//output new string without digits and display number of digits removed
	cout << endl << "String w/digits removed: \"";
	for(int i = 0; i < newArrayCounter; i++)
	{
		cout << newArray[i] << "";
	}
	cout << "\"" << endl;
	cout << "Digits removed: " << digitCount << endl << endl << endl;
}

//function to remove punctuation from string
void removePunctuation(string userInput, char *newArray, int punctuationCount, int stringLength, int newArrayCounter)
{
	//loop to check string for punctuation
	for (int i = 0; i < stringLength; i++)
	{
		//check for punctuation
		if (ispunct(userInput[i]))
		{
			punctuationCount++;
		}
		else
		{
			//if not punctuation copy string element to new array element
			newArray[newArrayCounter] = userInput[i];
			newArrayCounter++;
		}
	}

	//output new string without punctuation and display number of punctuation removed
	cout << endl << "String w/punctuation removed: \"";
	for (int i = 0; i < newArrayCounter; i++)
	{
		cout << newArray[i] << "";
	}
	cout << "\"" << endl;
	cout << "Punctuation removed: " << punctuationCount << endl << endl << endl;
}