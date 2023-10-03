#include "binary.h"

/**
 * Двоичное число в Двоичном коде, знак кодируется 1 битом
 *
 * @see Octet в octet.cpp
 */

BinaryNumber::BinaryNumber(const string &binaryNumber) {
    if (binaryNumber.empty()) {
        BinaryNumber(string("0"));
    }
    size_t len = binaryNumber.length() / 8;
    int numberStart;
    if (binaryNumber.length() % 8 != 0) {
        len++;
        numberStart = 8 - binaryNumber.length() % 8; // if length doesn't take all octets
    } else {
        numberStart = 0;
    }
//    numberStart++; // since we're putting the sign manually
    octets = new Octet[len];
    octetsLength = len;
    octets[0].setBit(0, binaryNumber[0]);

    for (int i = 1; i < binaryNumber.length(); i++) {
        if (binaryNumber[i] == '1') {
            octets[(i + numberStart) / 8].setBit((i + numberStart) % 8, true);
        } else if (binaryNumber[i] != '0') { // bit is 0 by default
            throw std::invalid_argument("Number contains symbols that are different from '0' and '1'");
        }
    }
}

BinaryNumber::BinaryNumber(long number) : BinaryNumber(longToBinary(number)) {};

BinaryNumber::BinaryNumber(BinaryNumber const &other) {
    octets = new Octet[other.octetsLength];
    octetsLength = other.octetsLength;

    for (int i = 0; i < other.octetsLength; i++) {
        octets[i] = other.octets[i].copy();
    }
}

size_t BinaryNumber::getLength() const {
    return octetsLength * 8;
}

void BinaryNumber::setBit(int index, bool value) {
    if (index < 0 or index >= getLength()) {
        throw std::out_of_range("Index is out of range");
    }
    octets[index / 8].setBit(index % 8, value);
}

/**
 * Возвращает экземпляр класса в дополнительном коде(если код этого числа - прямой)
 */
BinaryNumber BinaryNumber::getTwosComplement() const {
    bool sign = operator[](0);
    if (!sign) {
        return copy();
    }
    BinaryNumber newNum = operator~();
    newNum.setBit(0, sign);


    for (int i = getLength() - 1; i >= 0; i--) {
        if (newNum[i]) {
            newNum.setBit(i, 0);
        } else {
            newNum.setBit(i, 1);
            break;
        }
    }
    return newNum;
}

string BinaryNumber::getString() const {
    string out;
    for (int i = 0; i < getLength(); i++) {
        out.push_back(binaryToChar(operator[](i)));
    }
    return out;
}

/**
 * Полностью противоположная getTwosComplement функция
 * @see getTwosComplement()
 */
BinaryNumber BinaryNumber::getFromTwosComplement() {
    bool sign = operator[](0);
    if (!sign) {
        return copy();
    }

    BinaryNumber newNum = copy();
    for (int i = getLength() - 1; i > 0; i--) { // >0 because we ignore the sign
        if (!newNum[i]) {
            newNum.setBit(i, 1);
        } else {
            newNum.setBit(i, 0);
            break;
        }
    }
    return -(~newNum);
}


