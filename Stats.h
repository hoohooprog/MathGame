#ifndef Stats_H
#define Stats_H
#include <string>
#include <fstream>
#include <iostream>


using namespace std;

class Stats;

ostream &operator << (ostream & someStream, const Stats &someStats); // Overloaded << operator


class Stats
{
	protected:
		string name;
		int totalRight;
		int totalWrong;
		double totalEarnings;
		ofstream outfile;


	public:
		Stats::Stats();
		void loadUser(string, ifstream&, ofstream&);
		void updateStats(char);
		void displayStats();
		void saveStats(ofstream&);
		friend ostream &operator << (ostream &, const Stats &);

};
#endif

