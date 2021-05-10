#include <iostream>
#include "1/TwowayCounter.hpp"
#include "1/LimitedTwowayCounter.hpp"
#include "2/TeamLead.hpp"

using namespace std;

int main() {
    TeamLead t1("Ivan", 4000);
    Developer d1("Kaloyan");
    Developer d2("Misho");
    Developer d3("Pesho");
    t1.addDeveloperToTeam(&d1, 3000);
    t1.addDeveloperToTeam(&d2, 3000);
    t1.addDeveloperToTeam(&d3, 3000);
    t1.removeDeveloperFromTeam("Pesho");

    return 0;
}