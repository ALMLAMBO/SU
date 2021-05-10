#ifndef __DEVELOPER_HPP__
#define __DEVELOPER_HPP__

#include <string>

class TeamLead;

class Developer {
public:
    Developer();
    Developer(const std::string& name);

    std::string getName() const;
    double& getSalary();
    TeamLead* getTeamLead() const;
    void setInitialSalary(double amount);
    void sendLeavingRequest();
    void sendPromotionRequest(double amount);
    void set_team_lead(TeamLead* team_lead);

protected:
    std::string name;
    double salary;
    TeamLead* team_lead;
};

#endif //__DEVELOPER_HPP__