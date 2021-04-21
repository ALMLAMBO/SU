#pragma once
#ifndef __ELECTION_RESULTS_DATABASE_HPP__
#define __ELECTION_RESULTS_DATABASE_HPP__

#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "SectionVotes.hpp"

class ElectionResultsDatabase {
public:
	void addResultsFromFile(const char* filename);
	int numberOfSections() const;
	int votesForParty(Party) const;
	Party winningParty() const;

	friend std::istream& operator>>(std::istream& in,
		ElectionResultsDatabase& database);

	friend std::ostream& operator<<(std::ostream& out,
		const ElectionResultsDatabase& database);

private:
	std::vector<SectionVotes> sections;
};

#endif // !__ELECTION_RESULTS_DATABASE_HPP__