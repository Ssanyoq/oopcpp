#include "binary.h"


bool BinaryNumber::operator[](int index) const {
    if (index < 0 or index >= getLength()) {
        throw std::out_of_range("Index is out of range");
    }

    return octets[index / 8][index % 8];
}

BinaryNumber BinaryNumber::operator+(const BinaryNumber &other) const {
    BinaryNumber longerNumber(getTwosComplement());
    BinaryNumber shorterNumber(other.getTwosComplement());
    if (shorterNumber.octets.getLength() > longerNumber.octets.getLength()) {
        std::swap(longerNumber, shorterNumber);
    }

    bool carry = false;
    int longerInd = longerNumber.octets.getLength() - 1;

    // Adding 2 numbers until shorter one(by Octets amount) ends
    for (int shorterInd = shorterNumber.octets.getLength() - 1; shorterInd >= 0; shorterInd--) {
        longerNumber.octets[longerInd] =
                longerNumber.octets[longerInd]
                        .add(shorterNumber.octets[shorterInd], &carry);
        longerInd--;
    }

    // Shorter one ended, now adding 1 to longer one until carry is 0
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
    for (int i = 0; i < newNumber.octets.getLength(); i++) {
        newNumber.octets[i] = ~newNumber.octets[i];
    }
    return newNumber;
}

BinaryNumber BinaryNumber::operator-() const {
    BinaryNumber out = copy();
    out.octets[0].setBit(0, !(out.octets[0][0]));
    return out;
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

bool BinaryNumber::operator==(const BinaryNumber &other) const { // by value
    if (other.getSign() != getSign()) {
        return false;
    }
    size_t thisI = getLength() - 1;
    size_t otherI = other.getLength() - 1;
    for (; thisI > 0, otherI > 0; thisI--, otherI--) {
        if (operator[](thisI) != other[otherI]) {
            return false;
        }
    }

    // Now 1 of 2 numbers ended, so we're checking if there are any 1's in remaining octets
    for (; thisI > 0; thisI--) {
        if (operator[](thisI) != 0) {
            return false;
        }
    }
    for (; otherI > 0; otherI--) {
        if (other[otherI] != 0) {
            return false;
        }
    }
    return true;
}

bool BinaryNumber::operator!=(const BinaryNumber &other) const {
    return !(operator==(other));
}

std::ostream &operator<<(std::ostream &os, BinaryNumber binaryNumber) {
    os << "Number: ";
    for (int i = 0; i < binaryNumber.getLength(); i++) {
        os << binaryNumber[i];
        if (i == 0) {
            os << '.'; // getSign delimiter
        }
    }
    os << "; " << binaryNumber.octets.getLength() << " octet";
    if (binaryNumber.octets.getLength() != 1) {
        os << "s are"; // plural
    } else cout << " is"; // singular
    os << " used." << endl;
    return os;
}
