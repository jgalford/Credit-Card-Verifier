/**
 * @file Project01.ccp
 * To process the user's input and validate it using the CreditCard class
 * @author Johnathan Alford
 * @date September 2021
*/

#include <iostream>
#include "CreditCard.h"
using namespace std;

int main()
{
	int uInput[16] = {}; //integer array to store the user's card number
	string userInput = ""; //string to store anything the user inputs
	int curIndex = 0; //stores the current index
	bool error = false; //boolean to determine if an error occurred with the user's input
	bool exit = false; //boolean to determine if the user wants to exit the program

	cout << "Enter \"exit\" any time if you would like to exit the program." << endl;
	while (exit == false)
	{
		
		cout << "Enter a credit card number to validate: ";
		getline(cin, userInput);
		for (int i = 0; i < userInput.length();i++)
		{
			if (isdigit(userInput[i]))
			{
				uInput[curIndex] = userInput[i] - '0';
				curIndex++;
			}
			if (curIndex > 15)
			{
				break;
			}
			if (!isdigit(userInput[i]) && userInput[i] != ' ' && userInput[i] != '-') //if the user enters something invalid
			{
				error = true;
				break;
			}
		}

		if (error == true) //if there was an invalid input
		{
			cout << "An invalid input was entered, please only enter numbers, spaces, and dashes." << endl;
		}
		else if (curIndex != 16) //if there was a valid input but there were too few numbers
		{
			cout << "Not enough numbers to validate credit card number." << endl;
			error = true;
		}

		if (error == true) //if either error occurs prompt the user to re enter the card number
		{
			cout << "Please reinput the credit card number." << endl;
		}

		if (error == false) //if there were no errors check if the card number is valid
		{
			CreditCard myCard; //create an instance of the class
			myCard.setNumber(uInput); //use setter to input the number, the param input is an int array
			if (myCard.validateNum() == true)
			{
				cout << myCard.toString() << " is a valid card number." << endl;
			}
			else
			{
				cout << "Not a valid card number." << endl;
			}
		}
		curIndex = 0; //resets curIndex to be used when building the new uInput array
		error = false; //resets the error bool for the new card number

		if (userInput == "exit") //if the user entered "exit" then exit the while loop
		{
			exit = true;
		}
	}

	//Exit the program
	return 0;
}
