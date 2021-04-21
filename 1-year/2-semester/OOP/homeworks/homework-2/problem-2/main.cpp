#include <iostream>
#include "ElectionResultsDatabase.hpp"

using namespace std;

int main() {
	ElectionResultsDatabase db;
	ifstream file("section_votes.txt");
	cout << db.votesForParty(Party::PARTY3) << endl;
	cout << db.numberOfSections() << endl;
	return 0;
}