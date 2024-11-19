#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

// Шаблонний клас
template <typename T1, typename T2, typename T3, typename T4, typename T5>
class TemplateExample {
private:
    T1 data1;
    T2 data2;
    T3 data3;
    T4 data4;
    T5 data5;

public:
    TemplateExample(T1 d1, T2 d2, T3 d3, T4 d4, T5 d5)
        : data1(d1), data2(d2), data3(d3), data4(d4), data5(d5) {}

    void display() {
        std::cout << "Data1 (" << typeid(data1).name() << "): " << data1 << std::endl;
        std::cout << "Data2 (" << typeid(data2).name() << "): " << data2 << std::endl;
        std::cout << "Data3 (" << typeid(data3).name() << "): " << data3 << std::endl;
        std::cout << "Data4 (" << typeid(data4).name() << "): " << data4 << std::endl;
        std::cout << "Data5 (" << typeid(data5).name() << "): " << data5 << std::endl;
    }

    T1 getData1() { return data1; }
    T2 getData2() { return data2; }
    T3 getData3() { return data3; }
    T4 getData4() { return data4; }
    T5 getData5() { return data5; }

    // Шаблонний метод
    template <typename U>
    void printType(U val) {
        std::cout  << " Value: " << val << std::endl;
    }
};
