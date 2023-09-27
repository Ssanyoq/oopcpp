#ifndef LAB2_OCTET_H
#define LAB2_OCTET_H

#include <cstdint>
#include <vector>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>

using std::vector;
using std::pow;
using std::cout;
using std::endl;
using std::string;

class Octet {
private:
    uint8_t data;
public:
    explicit Octet(const int byte[8]);

    explicit Octet(uint8_t byte) : data(byte){};

    Octet operator+(Octet other) const;

    Octet operator&(Octet other) const;

    bool operator[](int index) const;

    Octet operator~() const;

    Octet add(Octet other, bool *flag = nullptr) const;

    int getAddition() const;

    friend std::ostream &operator<< (std::ostream &os, Octet octet);
};










#endif //LAB2_OCTET_H
