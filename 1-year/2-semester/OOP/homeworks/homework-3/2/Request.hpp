//
// Created by aleks on 5.5.2021 г..
//

#ifndef __REQUEST_HPP__
#define __REQUEST_HPP__

#include <string>

class Request {
public:
    Request();
    Request(const std::string& message, const std::string& sender);

    std::string getMessage() const;
    std::string getSender() const;
    unsigned int getCount() const;
    unsigned int getID() const;

protected:
    std::string message;
    std::string sender;
    unsigned int id;
    static unsigned int counter;
};

#endif //__REQUEST_HPP__