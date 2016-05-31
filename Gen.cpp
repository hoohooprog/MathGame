#include "Gen.h"

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>

using namespace std;

Gen::Gen()
{

}


Gen::Gen(string userName)
{
	ifstream inData;
	ofstream outData;
	loadUser(userName, inData,outData);
}

char Gen::Add()
{

	srand((unsigned int)time(NULL));
	num1 = rand() % 10;
	num2 = rand() % 10;
	theCorrectAnswer = num1 + num2;		//com generate answer

	cout << num1 << " + " << num2 << " = ";
	getline(cin, theUserResponse);
	//validate the userAnswer
	validateUserInput(theUserResponse);
	rightorWrong = checkTheAnswer(theUserResponse, &theCorrectAnswer, &rightorWrong);	//decided whether 1 or 0; rightorWrong in void Genupdate in main.cpp
	updateStats(rightorWrong);		//update stats based on 1 or 0, in stats.h
	saveStats(outfile);			//in stats.h

	return rightorWrong;

}

char Gen::Mult()
{
	srand((unsigned int)time(NULL));
	num1 = rand() % 10;
	num2 = rand() % 10;
	theCorrectAnswer = num1 * num2;

	cout << num1 << " * " << num2 << " = ";
	getline(cin, theUserResponse);
	//validate the userAnswer
	validateUserInput(theUserResponse);
	rightorWrong = checkTheAnswer(theUserResponse, &theCorrectAnswer, &rightorWrong);
	updateStats(rightorWrong);
	saveStats(outfile);

	return rightorWrong;

}

char Gen::Subtract()
{
	
	num1 = 0;
	num2 = 0;
	theCorrectAnswer = 0;

	do
	{
		srand((unsigned int)time(NULL));
		num1 = rand() % 10 + 1;
		num2 = rand() % 10;
		theCorrectAnswer = num1 - num2;
	} while (num1 < num2);
	cout << num1 << " - " << num2 << " = ";
	getline(cin, theUserResponse);
	//validate the userAnswer
	validateUserInput(theUserResponse);
	rightorWrong = checkTheAnswer(theUserResponse, &theCorrectAnswer, &rightorWrong);		//rightorWrong in void Genupdate in main.cpp
	updateStats(rightorWrong);
	saveStats(outfile);
	return rightorWrong;

}

char Gen::Divide()
{
	srand((unsigned int)time(NULL));
	num1 = rand() % 10;
	num2 = rand() % 10 + 1;
	theCorrectAnswer = num1;

	cout << num1*num2 << " / " << num2 << " = ";
	getline(cin, theUserResponse);
	//validate the userAnswer
	validateUserInput(theUserResponse);
	checkTheAnswer(theUserResponse, &theCorrectAnswer,&rightorWrong);
	updateStats(rightorWrong);
	saveStats(outfile);
	return rightorWrong;
}

void Gen::validateUserInput(string &theUserResponse)
{
	int userInputLength;
	int counter = 0;


	userInputLength = theUserResponse.length();	//how many characters in string var userInput

	while (userInputLength == 0)	//check if they typed nothing, just press enter, first validation
	{								/* use while than If since it loops until user gives right answer, user stuck in loop*/
		cout << " you did not enter anything" << endl;
		cout << "please enter it again" << endl;
		getline(cin, theUserResponse);	//get another entry if wrong
		userInputLength = theUserResponse.length(); //check again and compares with condition, if cond still true, loop again

	}

	while (counter < userInputLength)	/*has to be less than length because max index is length - 1*/
	{									// or cond can be (counter <= userInputLength - 1)
		if (!(isdigit(theUserResponse[counter]))) //note ! in 1st outer parenthesis
		{
			cout << "you did not enter a proper digit" << endl;

			cout << "please enter it again" << endl;
			getline(cin, theUserResponse);
			userInputLength = theUserResponse.length();

			counter = 0;

			while (userInputLength == 0)	//check if they typed nothing, just press enter, first validation
			{								/* use while than If since it loops until user gives right answer, user stuck in loop*/
				cout << " you did not enter anything" << endl;
				cout << "please enter it again" << endl;
				getline(cin, theUserResponse);	//get another entry if wrong
				userInputLength = theUserResponse.length(); //check again and compares with condition, if cond still true, loop again

			}//end of nested loop
		}
		else
		{
			counter = counter + 1; //or counter++;
		}
	}
}

char Gen::checkTheAnswer(string theUserResponse, int *theCorrectAnswer, char *rightorWrong)		//check answer and issue 1 or 0
{
	int userAnswer = stoi(theUserResponse);



	if (userAnswer == *theCorrectAnswer)
	{
		*rightorWrong = '1';
	}
	else
	{
		*rightorWrong = '0';
	}

	return *rightorWrong;
}