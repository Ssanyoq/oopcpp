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
    if (binaryNumber.length() % 8 != 0) {
        len++;
        numberStart = 8 - binaryNumber.length() % 8; // if length doesn't take all octets
    } else {
        numberStart = 0;
    }
    octets = new Octet[len];
    octetsLength = len;

    for (int i = 0; i < binaryNumber.length(); i++) {
        if (binaryNumber[i] == '1') {
            octets[(i + numberStart) / 8].setBit((i + numberStart) % 8, true);
        } else if (binaryNumber[i] != '0') { // bit is 0 by default
            throw std::invalid_argument("Number contains symbols that are different from '0' and '1'");
        }
    }
}

BinaryNumber::BinaryNumber(long number) {
    BinaryNumber(longToBinary(number));
}

BinaryNumber::BinaryNumber(BinaryNumber const &other) {
    octets = new Octet[other.octetsLength];
    octetsLength = other.octetsLength;
    numberStart = other.numberStart;

    for (int i = 0; i < other.octetsLength; i++) {
        octets[i] = other.octets[i].copy();
    }
}

size_t BinaryNumber::getLength() const {
    return octetsLength * 8 - numberStart;
}


/**
 * Возвращает экземпляр класса в дополнительном коде(если код этого числа - прямой)
 */
BinaryNumber BinaryNumber::getTwosComplement() const {
    string newNum;
    bool sign = operator[](0);
    if (!sign) {
        return copy();
    }
    newNum = operator~().getString();
    newNum[0] = '1';


    for (int i = getLength() - 1; i >= 0; i--) {
        if (newNum[i] == '1') {
            newNum[i] = '0';
        } else {
            newNum[i] = '1';
            break;
        }
    }
    return BinaryNumber(newNum);
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

    string newNum = getString();
    for (int i = getLength() - 1; i > 0; i--) { // >0 because of sign
        if (newNum[i] == '0') {
            newNum[i] = '1';
        } else {
            newNum[i] = '0';
            break;
        }
    }
    return -(~BinaryNumber(newNum));
}


