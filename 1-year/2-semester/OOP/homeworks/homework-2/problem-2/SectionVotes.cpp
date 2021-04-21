#include "SectionVotes.hpp"

SectionVotes::SectionVotes(int party1Votes, int party2Votes, int party3Votes) {
	this->party_votes.insert(
		std::pair<Party, int>(Party::PARTY1, party1Votes));

	this->party_votes.insert(
		std::pair<Party, int>(Party::PARTY2, party2Votes));

	this->party_votes.insert(
		std::pair<Party, int>(Party::PARTY3, party3Votes));
}

int SectionVotes::votesForParty(Party party) const {
	return this->party_votes.at(party);
}

std::istream& operator>>(std::istream& in, SectionVotes& section) {
	std::vector<int> votes;
	
	for (int i = 0; i < 3; i++) {
		int temp = 0;

		in >> temp;
		votes.push_back(temp);
	}

	section = SectionVotes(votes[0], votes[1], votes[2]);

	return in;
}

std::ostream& operator<<(std::ostream& out, const SectionVotes& section) {
	std::string result;

	for (int i = 0; i < 3; i++) {
		result += std::to_string(section.party_votes
			.at(static_cast<Party>(i)));

		if (i != 2) {
			result += " ";
		}
	}

	result += "\n";
	out << result;

	return out;
}