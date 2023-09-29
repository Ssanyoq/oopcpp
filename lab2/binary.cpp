#include "octet.h"
#include "binary.h"

/**
 * Двоичное число в ПК
 *
 * @see Octet в octet.cpp
 */
class BinaryNumber {
private:
    vector<Octet> octets; // data storage
    int numberStart; // starting position
public:

    /**
     * Конструктор, принимающий строку
     * @param binaryNumber - нужное число в двоичном представлении, прямой код
     *
     * (первый бит - знак числа)
     */
    explicit BinaryNumber(const string &binaryNumber) {
        if (binaryNumber == "") {
            octets = vector<Octet>(1);
            numberStart = 7;
            return;
        }
        size_t len = binaryNumber.length() / 8;
        if (binaryNumber.length() % 8 != 0) {
            len++;
            numberStart = 8 - binaryNumber.length() % 8; // if length doesn't take all octets
        } else {
            numberStart = 0;
        }
        octets = vector<Octet>(len);

        for (int i = 0; i < binaryNumber.length(); i++) {
            if (binaryNumber[i] == '1') {
                octets[(i + numberStart) / 8].setBit((i + numberStart) % 8, true);
            } else if (binaryNumber[i] != '0') { // bit is 0 by default
                throw std::invalid_argument("Number contains symbols that are different from '0' and '1'");
            }
        }
    }

//    explicit BinaryNumber(long number) {
//    }

//    BinaryNumber getTwosComplement() const {
//    }
    friend std::ostream &operator<<(std::ostream &os, BinaryNumber binaryNumber);

};

std::ostream &operator<<(std::ostream &os, BinaryNumber binaryNumber) {
    os << "Number: " << "start at index " << binaryNumber.numberStart << endl;
    for (int i = 0; i < binaryNumber.octets.size(); i++) {
        os << binaryNumber.octets[i];
    }
    os << endl;
    return os;
}

int main() {

    BinaryNumber b("1001");

    cout << b;
}