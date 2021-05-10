#include <iostream>
#include "TeamLead.hpp"

TeamLead::TeamLead() : Developer() {}

TeamLead::TeamLead(const std::string &name, const double &salary) : Developer(name) {
    this->setInitialSalary(salary);
}

std::vector<Developer *> TeamLead::getTeam() const {
    return this->team_members;
}

void TeamLead::addDeveloperToTeam(Developer *developer, double salary) {
    if(developer != nullptr) {
        if(developer->getTeamLead() == nullptr) {
            developer->set_team_lead(this);
            developer->setInitialSalary(salary);
            this->team_members.push_back(developer);
        }
    }
}

void TeamLead::removeDeveloperFromTeam(const std::string& name) {
    int index = this->get_index_of_developer(name);
    if(index >= 0) {
        this->team_members[index]->set_team_lead(nullptr);
        this->team_members.erase(this->team_members.begin() + index);
    }
}

void TeamLead::increaseTeamSalariesBy(double amount) {
    for (Developer* developer : this->team_members) {
        developer->getSalary() += amount;
    }
}

void TeamLead::decreaseTeamSalariesBy(double amount) {
    for (Developer* developer : this->team_members) {
        developer->getSalary() -= amount;
    }
}

void TeamLead::addLeavingRequest(const LeavingRequest &leavingRequest) {
    this->leaving_requests.push_back(leavingRequest);
}

void TeamLead::addPromotionRequest(const PromotionRequest &promotionRequest) {
    this->promotion_requests.push_back(promotionRequest);
}

void TeamLead::fulfillLeavingRequests() {
    for(const LeavingRequest& leaving_request : this->leaving_requests) {
        this->removeDeveloperFromTeam(leaving_request.getSender());
    }

    this->leaving_requests.clear();
}

void TeamLead::fulfillPromotionRequests() {
    for(const PromotionRequest& promotion_request : this->promotion_requests) {
        int index = this->get_index_of_developer(promotion_request.getSender());
        if(index >= 0) {
            this->team_members[index]->getSalary() +=
                    promotion_request.getAmount();
        }
    }

    this->promotion_requests.clear();
}

bool TeamLead::developer_exists(const std::string &name) {
    return std::any_of(
            this->team_members.rbegin(),
            this->team_members.rend(),
            [name](const Developer* developer) {
                return developer->getName() == name;
            });
}

int TeamLead::get_index_of_developer(const std::string &name) {
    int index = -1;

    if(this->developer_exists(name)) {
        std::vector<Developer*>::reverse_iterator it = std::find_if(
                this->team_members.rbegin(),
                this->team_members.rend(),
                [name](const Developer* developer) {
                    return developer->getName() == name;
                });

        index = it.base() - this->team_members.begin() - 1;
    }
    return index;
}