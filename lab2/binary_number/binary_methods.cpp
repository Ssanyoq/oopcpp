#include "binary.h"



BinaryNumber::BinaryNumber(const string &binaryNumber) {
    if (binaryNumber.empty()) {
        BinaryNumber("0");
    }
    size_t len = binaryNumber.length() / 8;
    int numberStart;
    if (binaryNumber.length() % 8 != 0) {
        len++;
        numberStart = 8 - binaryNumber.length() % 8; // if length doesn't take all octets
    } else {
        numberStart = 0;
    }

    octets = DynamicOctets(len);
    octets[0].setBit(0, charToBinary(binaryNumber[0]));

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
    octets = DynamicOctets(other.octets);
}

size_t BinaryNumber::getLength() const {
    return octets.getLength() * 8;
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


    // Below there I'm adding 1
    // Basically if there is 1, im changing it to 0 and continuing,
    // else I'm changing 0 to 1 and stopping
    for (int i = getLength() - 1; i >= 0; i--) {
        if (newNum[i]) {
            newNum.setBit(i, false);
        } else {
            newNum.setBit(i, true);
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
BinaryNumber BinaryNumber::getFromTwosComplement() const {
    bool sign = operator[](0);
    if (!sign) {
        return copy();
    }

    BinaryNumber newNum = copy();
    // Analog of adding 1 brom getTwosComplement
    for (int i = getLength() - 1; i > 0; i--) { // >0 because we ignore the getSign
        if (!newNum[i]) {
            newNum.setBit(i, 1);
        } else {
            newNum.setBit(i, 0);
            break;
        }
    }
    return -(~newNum);
}

string BinaryNumber::getInBase(unsigned int base) const {
    return decimalToBase(base, getDecimal(*this));
}

bool BinaryNumber::getSign() const {
    return operator[](0);
}


