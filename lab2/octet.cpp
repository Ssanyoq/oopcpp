#include "octet.h"
#include <format>
#include <iostream>



Octet::Octet(const int byte[8]) {
    data = 0;
    for (int i = 0; i < 8; i++) {
        data = data << 1;
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
    if ((1 << (7 - index)) & data) {
        return true;
    } else {
        return false;
    }
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
    uint8_t curWeight = 1;
    for (int i = 7; i > -1; i--) {
        bool otherBit = other[i];
        bool thisBit = this->operator[](i);

        sum += (otherBit ^ thisBit ^ buffer) * curWeight;

        buffer = (thisBit & otherBit) | (buffer & (thisBit ^ otherBit));

        curWeight *= 2;
    }
    if (flag != nullptr) {
        *flag = buffer;
    }
    return Octet(sum);
}


int Octet::getAddition() const {
    return 256 - data;
}

std::ostream &operator<<(std::ostream &os, Octet octet) {
    os << "Octet: " << endl;
    for (int i = 0; i < 8; i++) {
        os << octet[i] << " ";
    }
    os << endl;
    return os;
}

//int main() {
//    int byte[] = {0, 0, 0, 0, 0, 0, 1, 0};
//    int byte2[] = {1, 0, 0, 1, 0, 0, 0, 0};
//    Octet oct(byte);
//    Octet oct2(byte2);
////    cout << oct << oct2 << endl;
////
////    cout << oct.add(oct2);
////
////    cout << ~oct2;
////
////    cout << oct.getAddition() << endl;
//
//    cout << oct;
//
//    oct.setBit(0, 1);
//
//    cout << oct;
//
//    oct.setBit(1, 1);
//    oct.setBit(6, 0);
//    oct.setBit(0, 1);
//
//    cout << oct;
//
//    return 0;
//}