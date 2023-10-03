#include "binary.h"

/**
 * Возвращает бит числа под индексом index. Индексируется с 0 и нулевой бит - знак
 * @param index int
 * @throws std::out_of_range если индекс выходит за рамки разрешенного
 */
bool BinaryNumber::operator[](int index) const {
    if (index < 0 or index >= getLength()) {
        throw std::out_of_range("Index is out of range");
    }

    return octets[index / 8][index % 8];
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
    BinaryNumber newNumber = copy();
    for (int i = 0; i < newNumber.octetsLength; i++) {
        newNumber.octets[i] = ~newNumber.octets[i];
    }
    return newNumber;
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
    os << "Number: ";
    for (int i = 0; i < binaryNumber.getLength(); i++) {
        cout << binaryNumber[i];
        if (i == 0) {
            cout << '.'; // sign delimiter
        }
    }

    cout << "; " << binaryNumber.octetsLength << " octet";
    if (binaryNumber.octetsLength != 1) {
        cout << "s are"; // plural
    } else cout << " is"; // singular

    cout << " used.";

    os << endl;
    return os;
}
