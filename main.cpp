#include <iostream>
#include <string>
#include <fstream>
#include "Stats.h"
#include "Gen.h"

using namespace std;

void credits();
Gen nameValidatenLoad();
void inputValidation(string &name);
void alterStats(Stats *, int choice);
void menu();
string selection(Gen &);
void validateChoice(string& choice);
void gennUpdate(string choice, int&, Gen&);	//generate question/display stats n change stats depending on answer


int main()
{
	string choice;
	int i = 0;
	char cont = 'y';

	credits();		//first screen where user sees credit and must answer Y/y in order to continue, any other answer will terminate program
	Gen userStat = nameValidatenLoad();
	cout << userStat;		//fine here
	for (i = 0; i < 1; i++)
	{
		menu();
		choice = selection(userStat); //validate and return choice 
		gennUpdate(choice, i, userStat);		//excludes n/N which exits program
		//menu();
		//choice = selection(userStat);
	}


	system("pause");
	return 0;
}

void credits()
{
	string cont;

	cout << "***********************" << endl;
	cout << "***********************" << endl;
	cout << "***********************" << endl;
	cout << "******           ******" << endl;
	cout << "******TheMathGame******" << endl;
	cout << "******    by     ******" << endl;
	cout << "****** JingyiTay ******" << endl;
	cout << "******           ******" << endl;
	cout << "***********************" << endl;
	cout << "***********************" << endl;
	cout << "***********************" << endl;

	cout << "y/Y to continue, other keys to exit\n";

	getline(cin, cont);

	if (cont != "y" && cont != "Y")
	{
		exit(0);
	}



}

void alterStats(Stats *userStat, int choice)	//use of pointers to access Stats object & choice to indicate user's action
{

}

Gen nameValidatenLoad()
{
	string name;
	
	cout << "Enter your name and press <ENTER>\n";
	getline(cin, name);
	inputValidation(name);

	Gen userStat(name); //create Stats object(userStat)

	return userStat;

}

string selection(Gen &userStat)
{
	string choice;		//user choice input
	getline(cin, choice);
	validateChoice(choice);
	
	return choice;
	
}

void validateChoice(string& choice)    //function header(same as function prototype but has body to define function); function inside selection
{
	//cout << switchChoice << endl;
	int counter = 0;
	char choiceChar;


	while (counter == 0)	//has to be less than length because max index is length - 1
	{									// or cond can be (counter <= userInputLength - 1)

		while (choice.length() > 1 || choice.length() == 0)		//if choice input more than 1 char or 0 capture whitespace?
		{
			cout << "enter the appropriate selection \n";
			getline(cin, choice);
		}

		choiceChar = choice[0];		//since only 1 char, take the 1 char stored at index 0 in string 


		while (counter < 1)
		{
			if (choiceChar == 49 || choiceChar == 50 || choiceChar == 51 || choiceChar == 52 || choiceChar == 53)
			{
				counter++;
			}

			else if (choiceChar == 'n' || choiceChar == 'N')
			{
				exit(0);
			}
			
			else
			{
				cout << "that is an invalid choice \n";
				cout << "enter the appropriate selection \n";
				getline(cin, choice);


				while (choice.length() > 1 || choice.length() == 0)		//if choice input more than 1 char or 0 capture whitespace?
				{
					cout << "enter the appropriate selection \n";
					getline(cin, choice);
				}

				choiceChar = choice[0];		//since only 1 char, take the 1 char stored at index 0 in string 

			}

		}

		
		

	}

}

void inputValidation(string &name)    //function header(same as function prototype but has body to define function)
{
	int userInputLength;
	int counter = 0;


	userInputLength = name.length();	//how many characters in string var userInput

	while (userInputLength == 0)	//check if they typed nothing, just press enter, first validation
	{								/* use while than If since it loops until user gives right answer, user stuck in loop*/
		system("cls");
		cout << " you did not enter anything" << endl;
		cout << "please enter it again" << endl;
		getline(cin, name);	//get another entry if wrong
		userInputLength = name.length(); //check again and compares with condition, if cond still true, loop again

	}

	while (counter < userInputLength)	/*has to be less than length because max index is length - 1*/
	{									// or cond can be (counter <= userInputLength - 1)
		if (!(isalpha(name[counter]))) //note ! in 1st outer parenthesis
		{
			cout << "you did not enter a proper name" << endl;

			cout << "please enter it again" << endl;
			getline(cin, name);
			userInputLength = name.length();

			counter = 0;

			while (userInputLength == 0)	//check if they typed nothing, just press enter, first validation
			{								/* use while than If since it loops until user gives right answer, user stuck in loop*/
				cout << " you did not enter anything" << endl;
				cout << "please enter it again" << endl;
				getline(cin, name);	//get another entry if wrong
				userInputLength = name.length(); //check again and compares with condition, if cond still true, loop again

			}
		}

		else
		{
			counter = counter + 1; //or counter++;
			
		}
		
		
	

		
		
	}
	system("cls");
}

void menu()
{
	cout << "*****CHOOSE A PROBLEM*****" << endl;
	cout << "**************************" << endl;
	cout << "**************************" << endl;
	cout << "*****                *****" << endl;
	cout << "*****  1. Add        *****" << endl;
	cout << "*****  2. Subtract   *****" << endl;
	cout << "*****  3. Divide     *****" << endl;
	cout << "*****  4. Multiply   *****" << endl;
	cout << "*****  5. Stats      *****" << endl;
	cout << "*****  n/N to quit   *****" << endl;
	cout << "*****                *****" << endl;
	cout << "**************************" << endl;
	cout << "**************************" << endl;

}

void gennUpdate(string choice, int &i, Gen &genQns)
{
	char choiceChar = choice[0];
	
	char rightOrWrong;		//accepts 1 or 0 to indicate correct or wrong
	ofstream outData;

	if (choiceChar == 49)
	{
		rightOrWrong = genQns.Add();
		//genQns.update(rightOrWrong);		//update stats based on rightOrWrong(1 or 0)
		genQns.saveStats(outData);
		--i;
	}

	else if (choiceChar == 50)
	{
		rightOrWrong = genQns.Subtract();
		//genQns.update(rightOrWrong);
		genQns.saveStats(outData);
		--i;

	}

	else if (choiceChar == 51)
	{
		rightOrWrong = genQns.Mult();
		//genQns.update(rightOrWrong);
		genQns.saveStats(outData);
		--i;

	}

	else if (choiceChar == 52)
	{
		rightOrWrong = genQns.Divide();	//generate division question; check answer and output 1 or 0; 
		//genQns.update(rightOrWrong);
		genQns.saveStats(outData);
		--i;

	}

	else if (choiceChar == 53)
	{
		cout << genQns;
		--i;
	}


}