#include "binary.h"

/**
 * Возвращает бит числа под индексом index. Начинается с 0 и нулевой бит - знак
 * @param index int
 * @throws std::out_of_range если индекс выходит за рамки разрешенного
 */
bool BinaryNumber::operator[](int index) const {
    if (index < 0 or index >= getLength()) {
        throw std::out_of_range("Index is out of range");
    }
    size_t octet_i = (index + numberStart) / 8;
    size_t bit_i = (index + numberStart) % 8;
    return octets[octet_i][bit_i];
}

BinaryNumber BinaryNumber::operator+(const BinaryNumber &other) const {
    BinaryNumber biggerComplement = this->getTwosComplement();
    BinaryNumber smallerComplement = other.getTwosComplement();

    if (smallerComplement.octetsLength > biggerComplement.octetsLength) {
        std::swap(biggerComplement, smallerComplement);
    }

    bool buffer = false;

    int bigger_i = biggerComplement.octetsLength - 1;
    int smaller_i = smallerComplement.octetsLength - 1;

    for (; smaller_i >= 0; smaller_i--) {
        biggerComplement.octets[bigger_i] = biggerComplement
                .octets[bigger_i]
                .add(smallerComplement.octets[smaller_i], &buffer);
        bigger_i--;
    }

    if (buffer) {
        for (; bigger_i >= 0; bigger_i--) {
            biggerComplement.octets[bigger_i] = biggerComplement
                    .octets[bigger_i]
                    .add(Octet(), &buffer);
            if (!buffer) {
                break;
            }
        }
    }
    return BinaryNumber(biggerComplement.getFromTwosComplement());
}

BinaryNumber BinaryNumber::operator~() const { //TODO
    string newStr = getString();
    for (int i = 0; i < newStr.size(); i++) {
        if (newStr[i] == '1') {
            newStr[i] = '0';
        } else {
            newStr[i] = '1';
        }
    }
    return BinaryNumber(newStr);
}

BinaryNumber BinaryNumber::operator-() const {
    string newNum = getString();
    if (newNum[0] == '0') {
        newNum[0] = '1';
    } else {
        newNum[0] = '0';
    }
    return BinaryNumber(newNum);
}

std::ostream &operator<<(std::ostream &os, BinaryNumber binaryNumber) {
    os << "Number: " << "start at index " << binaryNumber.numberStart << endl;
    for (int i = 0; i < binaryNumber.octetsLength; i++) {
        os << binaryNumber.octets[i];
    }
    os << endl;
    return os;
}
