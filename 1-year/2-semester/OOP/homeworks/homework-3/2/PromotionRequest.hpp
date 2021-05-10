//
// Created by aleks on 5.5.2021 г..
//

#ifndef __PROMOTION_REQUEST_HPP__
#define __PROMOTION_REQUEST_HPP__

#include "Request.hpp"

class PromotionRequest : public Request {
public:
    PromotionRequest() = default;
    PromotionRequest(const std::string& sender, const double& amount);

    double getAmount() const;

private:
    double amount;
};


#endif //__PROMOTION_REQUEST_HPP__
