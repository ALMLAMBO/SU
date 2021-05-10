//
// Created by aleks on 5.5.2021 г..
//

#ifndef __LEAVING_REQUEST_HPP__
#define __LEAVING_REQUEST_HPP__

#include "Request.hpp"

class LeavingRequest : public Request {
public:
    LeavingRequest() = default;
    LeavingRequest(const std::string& sender);
};

#endif //__LEAVING_REQUEST_HPP__