/**
 * @file CreditCard.h
 * A class to validate credit card numbers
 * @author Johnathan Alford
 * @date September 2021
*/

#ifndef CREDITCARD_H
#define CREDITCARD_H

#include <string>
using namespace std;

class CreditCard{
private:
	/** size of the array*/
	static const int SIZE = 16;
	/** array of integers*/
	int cArray[SIZE] = {};

public:
	/**
	* default constructor
	*/
	CreditCard();

	/**
	  * insert the card number into an array
	  * @param userInput the input that the user entered
	  */
	void setNumber(int userInput[]);

	/**
	  * determine if the number is valid in the array
	  * @return true if the number is valid
	  */
	bool validateNum();

	/**
	  * store all the numbers in the array into one string
	  * @return the string
	  */
	string toString();
};

#endif //Project_01_CREDITCARD_H