#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
public:
    Client(); // 1. Конструктор за замовчуванням
    Client(const std::string& name); // 2. Конструктор з параметрами

    std::string getClientName() const;
    void setClientName(const std::string& name);

private:
    std::string clientName;
};

#endif // CLIENT_H