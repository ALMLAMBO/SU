//
// Created by aleks on 5.5.2021 г..
//

#include "Request.hpp"

unsigned int Request::counter = 0;

Request::Request() {
    this->id = ++Request::counter;
}

Request::Request(const std::string &message, const std::string &sender) {
    this->message = message;
    this->sender = sender;

    this->id = ++Request::counter;
}

std::string Request::getMessage() const {
    return this->message;
}

std::string Request::getSender() const {
    return this->sender;
}

unsigned int Request::getCount() const {
    return Request::counter;
}

unsigned int Request::getID() const {
    return this->id;
}