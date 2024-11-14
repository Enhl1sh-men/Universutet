#include "Client.h"

Client::Client() : clientName("") {}

Client::Client(const std::string& name) : clientName(name) {}

std::string Client::getClientName() const {
    return clientName;
}

void Client::setClientName(const std::string& name) {
    clientName = name;
}
