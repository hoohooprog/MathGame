#ifndef Gen_H
#define Gen_H
#include <string>
#include "Stats.h"
#include <cstdlib>
#include <iostream>

using namespace std;

class Gen : public Stats
{
	private:
		string theUserResponse;
		
		char rightorWrong;
		int num1;
		int num2;
		int theCorrectAnswer;

	public:
		Gen::Gen();
		Gen::Gen(string userName);
		char Add();
		char Subtract();
		char Mult();
		char Divide();
		char checkTheAnswer(string, int *, char *);
		void validateUserInput(string &);
		
	

};
#endif

