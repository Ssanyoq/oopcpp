#include "octet.h"

void printUint8_t(uint8_t num) {
    printf("%hu\n", num);
}

uint8_t dpow(int base, unsigned int exponent) {
    uint8_t out = 1;
    for (int i = 0; i < exponent; i++) {
        out *= base;
    }
    return out;
}


class Octet {
private:
    uint8_t data;
public:
    explicit Octet(const int byte[8]) {
        data = 0;
        uint8_t weight = 1;
        for (int i = 7; i > -1; i--) {
            if (byte[i] != 0) {
                data += weight;
            }
            weight *= 2;
        }
    }

    explicit Octet(uint8_t byte) : data(byte) {
    };


    Octet operator+(Octet other) const {
        return Octet(other.data + data);
    }

    Octet operator&(Octet other) const {
        return Octet(other.data & data);
    }

    bool operator[](int index) const {
//        if (index == -1) {
//            index = 7;
//        }
        if (index < 0 or index > 7) {
            throw std::out_of_range("Index is out of range");
        }
        if (dpow(2, 7 - index) & data) { // <<
            return true;
        } else {
            return false;
        }
    }

    Octet operator~() const {
        return Octet(~data);
    };

    Octet add(Octet other, bool *flag = nullptr) const {
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

    int getAddition() const {
        return 256 - data;
    }

    friend std::ostream &operator<< (std::ostream &os, Octet octet);
};



std::ostream &operator<< (std::ostream &os, Octet octet) {
    os << "Octet: " << endl;
    for (int i = 0; i < 8; i++) {
        os << octet[i] << " ";
    }
    os << endl;
    return os;
}

int main() {
    int byte[] = {0, 0, 0, 0, 0, 0, 1, 0};
    int byte2[] = {1, 0,0,1,0,0,0,0};
    Octet oct(byte);
    Octet oct2(byte2);
    cout << oct << oct2 << endl;

    cout << oct.add(oct2);

    cout << ~oct2;

    cout << oct.getAddition() << endl;


    return 0;
}