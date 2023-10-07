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
    BinaryNumber longerNumber(getTwosComplement());
    BinaryNumber shorterNumber(other.getTwosComplement());
    if (shorterNumber.octetsLength > longerNumber.octetsLength) {
        std::swap(longerNumber, shorterNumber);
    }

    bool carry = false;
    int longerInd = longerNumber.octetsLength - 1;
    for (int shorterInd = shorterNumber.octetsLength - 1; shorterInd >= 0; shorterInd--) {
        longerNumber.octets[longerInd] =
                longerNumber.octets[longerInd]
                        .add(shorterNumber.octets[shorterInd], &carry);
        longerInd--;
    }

    for (; longerInd >= 0; longerInd--) {
        longerNumber.octets[longerInd] = longerNumber.octets[longerInd].add(Octet(), &carry);
        if (!carry) {
            break;
        }
    }

    return longerNumber.getFromTwosComplement();
}

BinaryNumber BinaryNumber::operator-(const BinaryNumber &other) const {
    return operator+(-other);
}

BinaryNumber BinaryNumber::operator~() const {
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


BinaryNumber BinaryNumber::operator--() {
    *this = this->operator+(-BinaryNumber(1));
    return *this;
}

BinaryNumber BinaryNumber::operator++(int _) {
    BinaryNumber temp = copy();
    *this = this->operator+(BinaryNumber(1));
    return temp;
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
