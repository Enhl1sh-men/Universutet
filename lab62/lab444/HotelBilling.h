#ifndef HOTELBILLING_H
#define HOTELBILLING_H

#include <vector>
#include <iostream>

template<typename T1, typename T2, typename T3, typename T4, typename T5>
class HotelBilling {
public:
    HotelBilling(std::vector<T1> clients, T2 totalAmount, T3 discount, T4 taxRate, T5 serviceCharge)
        : clients(clients), totalAmount(totalAmount), discount(discount), taxRate(taxRate), serviceCharge(serviceCharge) {}

    void displayTotalAmount() const {
        T2 total = totalAmount;
        total -= discount;
        total += total * taxRate;
        total += serviceCharge;
        std::cout << "Total amount to be paid by all clients: $" << total << std::endl;
    }

private:
    std::vector<T1> clients;
    T2 totalAmount;
    T3 discount;
    T4 taxRate;
    T5 serviceCharge;
};

#endif // HOTELBILLING_H
