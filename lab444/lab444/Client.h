#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
public:
    Client();
    Client(const std::string& name);
    std::string getClientName() const;
    void setClientName(const std::string& name);

private:
    std::string clientName;
};

#endif // CLIENT_H
