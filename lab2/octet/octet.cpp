#include "octet.h"
#include <format>
#include <iostream>



Octet::Octet(const int byte[8]) {
    data = 0;
    for (int i = 0; i < 8; i++) {
        data = data << 1;
        if (byte[i] > 1 or byte[i] < 0) {
            throw std::invalid_argument("Values must be 1 or 0");
        }
        data += byte[i];
    }
}


Octet Octet::operator+(Octet other) const {
    return Octet(other.data + data);
}

Octet Octet::operator&(Octet other) const {
    return Octet(other.data & data);
}

bool Octet::operator[](unsigned int index) const {
    if (index < 0 or index > 7) {
        throw std::out_of_range("Index is out of range");
    }
    return (1 << (7 - index)) & data;
}

void Octet::setBit(int index, bool value) {
    if (index < 0 or index > 7) {
        throw std::out_of_range("Index is out of range");
    }
    if (this->operator[](index) != value) {
        if (value) {
            data += 1 << (7 - index); // 2 ^ (bit's rank)
        } else {
            data -= 1 << (7 - index);
        }
    }
}

Octet Octet::operator~() const {
    return Octet(~data);
};

Octet Octet::add(Octet other, bool *flag) const {
    uint8_t sum = 0;

    bool buffer = false;
    if (flag != nullptr) {
        buffer = *flag;
    }

    for (int i = 7; i > -1; i--) {
        bool otherBit = other[i];
        bool thisBit = this->operator[](i);

        sum += (otherBit ^ thisBit ^ buffer) << (7 - i);

        buffer = (thisBit & otherBit) | (buffer & (thisBit ^ otherBit));

    }
    if (flag != nullptr) {
        *flag = buffer;
    }
    return Octet(sum);
}


int Octet::getAddition() const {
    return 256 - data;
}

Octet Octet::copy() const {
    return Octet(data);
}

std::ostream &operator<<(std::ostream &os, Octet octet) {
    os << "Octet: " << endl;
    for (int i = 0; i < 8; i++) {
        os << octet[i] << " ";
    }
    os << endl;
    return os;
}
