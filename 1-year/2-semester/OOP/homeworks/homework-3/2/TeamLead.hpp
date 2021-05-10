#ifndef __TEAM_LEAD_HPP__
#define __TEAM_LEAD_HPP__

#include <vector>
#include <algorithm>
#include "Developer.hpp"
#include "LeavingRequest.hpp"
#include "PromotionRequest.hpp"

class Developer;

class TeamLead : public Developer {
public:
    TeamLead();
    TeamLead(const std::string& name, const double& salary);

    std::vector<Developer*> getTeam() const;
    void addDeveloperToTeam(Developer * developer, double salary);
    void removeDeveloperFromTeam(const std::string& name);
    void increaseTeamSalariesBy(double amount);
    void decreaseTeamSalariesBy(double amount);
    void addLeavingRequest(const LeavingRequest& leavingRequest);
    void addPromotionRequest(const PromotionRequest& promotionRequest);
    void fulfillLeavingRequests();
    void fulfillPromotionRequests();

protected:
    std::vector<Developer*> team_members;
    std::vector<LeavingRequest> leaving_requests;
    std::vector<PromotionRequest> promotion_requests;

    bool developer_exists(const std::string& name);
    int get_index_of_developer(const std::string& name);
};

#endif //__TEAM_LEAD_HPP__