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
    explicit Octet(): data(0){};

    explicit Octet(const int byte[8]);

    explicit Octet(uint8_t byte) : data(byte){};

    Octet operator+(Octet other) const;

    Octet operator&(Octet other) const;

    bool operator[](unsigned int index) const;


    /**
     * Sets individual bit to given value
     * @param index index of a bit that needs to be changed
     * @param value new boolean value
     *
     * @throws std::out_of_range if index is out of range( < 0 or > 7)
     */
    void setBit(int index, bool value);

    Octet operator~() const;

    Octet add(Octet other, bool *flag = nullptr) const;

    int getAddition() const;

    Octet copy() const;

    friend std::ostream &operator<< (std::ostream &os, Octet octet);
};










#endif //LAB2_OCTET_H
