#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
public:
    Client();  // ����������� ��� ���������
    Client(const std::string& name);  // ����������� � ����������
    std::string getClientName() const;  // ������ ��� ��������� ���� �볺���
    void setClientName(const std::string& name);  // ������ ��� ������������ ���� �볺���
private:
    std::string clientName;
};

#endif // CLIENT_H
