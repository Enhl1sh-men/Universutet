#include "Client.h"

// 2. ����������� �� �������������
Client::Client() : clientName("") {}

// 2. ����������� � �����������
Client::Client(const std::string& name) : clientName(name) {}

std::string Client::getClientName() const {
    return clientName;
}

void Client::setClientName(const std::string& name) {
    clientName = name;
}