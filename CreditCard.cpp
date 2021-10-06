/**
 * @file CreditCard.ccp
 * A class to validate credit card numbers
 * @author Johnathan Alford
 * @date September 2021
*/

#include "CreditCard.h"
#include <string>

/**
* constructor
*/
CreditCard::CreditCard()
{
	for (int i = 0;i < SIZE;i++)
	{
		cArray[i] = 0;
	}
}

/**
* insert the card number into an array
* @param userInput the input that the user entered
*/
void CreditCard::setNumber(int userInput[])
{
	for (int i = 0;i < SIZE;i++)
	{
		cArray[i] = userInput[i];
	}
}

/**
* determine if the number is valid in the array
* @return true if the number is valid
*/
bool CreditCard::validateNum()
{
	int cSum = 0; //variable to store the sum of the card numbers
	//double every other
	for (int i = 0; i < SIZE;i++)
	{
		if (i % 2 == 0) //if the index is even
		{
			cArray[i] = 2 * cArray[i]; //multiply the number at that index by 2
		}
	}
	//sum the digits
	for (int i = 0; i < SIZE;i++)
	{
		if (cArray[i] > 9 && (i % 2) == 0) //adds the digits together if they are two digit numbers
		{
			int secDigit = cArray[i] % 10;
			cArray[i] = 1 + secDigit;
		}
		cSum += cArray[i];
	}
	if (cSum % 10 == 0) //if the sum of the digits are a multiple of 10
	{
		return true;
	}
	else //if the sum of the digits are not a multiple of 10
	{
		return false;
	}
}

/**
* store all the numbers in the array into one string
* @return the string
*/
string CreditCard::toString()
{
	string validNumber = ""; //string to store the valid card number
	for (int i = 0;i < SIZE;i++)
	{
		if (i==3||i==7||i==11)
		{
			validNumber = validNumber + to_string(cArray[i])+"-";
		}
		else
		{
			validNumber = validNumber + to_string(cArray[i]);
		}
	}
	return validNumber;
}