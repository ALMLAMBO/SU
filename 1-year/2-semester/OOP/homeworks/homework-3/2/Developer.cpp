#include "Developer.hpp"
#include "TeamLead.hpp"

Developer::Developer() {
    this->salary = 0;
    this->team_lead = nullptr;
}

Developer::Developer(const std::string &name) {
    this->name = name;
    this->salary = 0;
    this->team_lead = nullptr;
}

std::string Developer::getName() const {
    return this->name;
}

double& Developer::getSalary() {
    return this->salary;
}

TeamLead* Developer::getTeamLead() const {
    return this->team_lead;
}

void Developer::setInitialSalary(double amount) {
    if(this->salary == 0) {
        this->salary = amount;
    }
}

void Developer::sendLeavingRequest() {
    if(this->team_lead != nullptr) {
       this->team_lead->addLeavingRequest(
               LeavingRequest(this->name));
   }
}

void Developer::sendPromotionRequest(double amount) {
    if(this->team_lead != nullptr) {
        this->team_lead->addPromotionRequest(
                PromotionRequest(this->name, amount));
    }
}

void Developer::set_team_lead(TeamLead* team_lead) {
    this->team_lead = team_lead;
}