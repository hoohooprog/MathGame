#include "Stats.h"
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

Stats::Stats()
{

}

//constructor
void Stats::loadUser(string userName, ifstream& inData, ofstream& outData)			//CONSTRUCTOR WORKS
{
	string userFileName = userName + ".txt";
	fstream file(userFileName, ios::in | ios::out);

	inData.open(userFileName);

	//if the user file does not exist, create one
	if (!inData.is_open())
	{
		cout << "welcome new user " << userName << endl;
		//create userFile for output.  remember that when you issue	the command outData.open(userFileName.c_str());
		//if the file does not exist, it will get created.
		outData.open(userFileName);
		
		//we store values in the file to prevent an exception if we attempt to read data from an empty file
		outData << userName << endl;
		outData << 0 << endl;
		outData << 0 << endl;
		outData << 0 << endl;
		outData.close();
		cout << "A text file with your name was created\n";

		inData.open(userFileName);
		inData >> name;
		inData >> totalRight;
		inData >> totalWrong;
		inData >> totalEarnings;

		inData.close();

		cout << name;
		cout << totalRight;
		cout << totalWrong;

	}
	else //the file exists
	{
		//you may proceed to read statistics into variables

		inData >> name;
		inData >> totalRight;
		inData >> totalWrong;
		inData >> totalEarnings;
		//close file once you read the data
		inData.close();
		//open for output to save the stats --you may or you may not want to do this; let's dicuss in class why!
		//outData.open(userFileName.c_str());
		cout << "welcome " << name << "\n";
		cout << name;
		cout << totalRight;
		cout << totalWrong;

	}
}

void Stats::displayStats()		//NOT WORKING
{
	//return member variables
	cout << setprecision(2) << fixed;

	cout << "stats for " << name << endl;
	cout << "total correct " << totalRight << endl;
	cout << "total incorrect " << totalWrong << endl;
	cout << "total wages " << totalEarnings << endl;
	system("pause");
	system("cls");

}

void Stats::saveStats(ofstream& outData)
{
	//output member variables to file
	string userFileName = name + ".txt";
	outData.open(userFileName);
	outData << name << endl;
	outData << totalRight << endl;
	outData << totalWrong << endl;
	outData << totalEarnings << endl;
	outData.close();
	

	system("pause");
	system("cls");
}

void Stats::updateStats(char rightorWrong)
{
	//update stats using postfix op
	if (rightorWrong == '1')
	{
		cout << "good job" << endl;
		totalRight++;
		//totalWages = totalWages + 0.05;
		totalEarnings += 0.05;
	}

	else if (rightorWrong == '0')
	{
		cout << "WRONG!" << endl;
		totalWrong++;
		//totalWages = totalWages - 0.03;
		totalEarnings -= 0.03;
	}
}

ostream &operator <<(ostream &strm, const Stats &obj)
{
	strm << setprecision(2) << fixed;
	strm << "The stats for " << obj.name << endl;
	strm << "total correct " << obj.totalRight << endl;
	strm << "total wrong " << obj.totalWrong << endl;
	strm << "total wages " << obj.totalEarnings << endl;

	return strm;
	system("pause");
}


	


