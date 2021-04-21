#include "ElectionResultsDatabase.hpp"
#include "SectionVotes.hpp"

void ElectionResultsDatabase::addResultsFromFile(const char* filename) {
	std::ifstream file_to_read(filename);

	if (file_to_read.is_open()) {
		file_to_read >> *this;
	}

	file_to_read.close();
}

int ElectionResultsDatabase::numberOfSections() const {
	return this->sections.size();
}

int ElectionResultsDatabase::votesForParty(Party party) const {
	int result_votes = 0;

	for (int i = 0; i < this->sections.size(); i++) {
		result_votes += this->sections[i].votesForParty(party);
	}

	return result_votes;
}

Party ElectionResultsDatabase::winningParty() const {
	std::vector<int> result_votes;

	for (int i = 0; i < this->sections.size(); i++) {
		result_votes.push_back(this->
			votesForParty(static_cast<Party>(i)));
	}

	std::vector<int>::iterator it = std::max(result_votes.begin(), result_votes.end());

	return static_cast<Party>(it - result_votes.end());
}

std::istream& operator>>(std::istream& in,
	ElectionResultsDatabase& database) {

	SectionVotes votes;
	
	while (in >> votes) {
		database.sections.push_back(votes);
	}

	return in;
}

std::ostream& operator<<(std::ostream& out,
	const ElectionResultsDatabase& database) {

	for (int i = 0; i < database.sections.size(); i++) {
		out << database.sections[i];
	}

	return out;
}