#include "Client.h"

// 2. Конструктор за замовчуванням
Client::Client() : clientName("") {}

// 2. Конструктор з параметрами
Client::Client(const std::string& name) : clientName(name) {}

std::string Client::getClientName() const {
    return clientName;
}

void Client::setClientName(const std::string& name) {
    clientName = name;
}