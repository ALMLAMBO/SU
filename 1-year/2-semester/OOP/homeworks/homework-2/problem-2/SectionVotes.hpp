#ifndef __SECTION_VOTES_HPP__
#define __SECTION_VOTES_HPP__

#include <map>
#include <string>
#include <vector>
#include <iostream>

enum Party {
	PARTY1 = 0,
	PARTY2 = 1,
	PARTY3 = 2
};

class SectionVotes {
public:
	SectionVotes(int party1Votes = 0, int party2Votes = 0, int party3Votes = 0);
	int votesForParty(Party) const;

	friend std::istream& operator>>(std::istream& in, SectionVotes& section);
	friend std::ostream& operator<<(std::ostream& out, const SectionVotes& section);

private:
	std::map<Party, int> party_votes;
};

#endif // !__SECTION_VOTES_HPP__