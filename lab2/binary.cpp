#include "binary.h"

/**
 * Двоичное число в Двоичном коде, знак кодируется 1 битом
 *
 * @see Octet в octet.cpp
 */
class BinaryNumber {
private:
    int numberStart; // starting position

    size_t octetsLength;
    Octet *octets; // data storage
public:

    /**
     * Конструктор, принимающий строку
     * @param binaryNumber - нужное число в двоичном представлении, прямой код
     *
     * (первый бит - знак числа)
     */
    explicit BinaryNumber(const string &binaryNumber) {
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

    explicit BinaryNumber(long number) {
        BinaryNumber(longToBinary(number));
    }

    size_t getLength() const {
        return octetsLength * 8 - numberStart;
    }

    /**
     * Возвращает бит числа под индексом index. Начинается с 0 и нулевой бит - знак
     * @param index int
     * @throws std::out_of_range если индекс выходит за рамки разрешенного
     */
    bool operator [](int index) const {
        if (index < 0 or index >= getLength()) {
            throw std::out_of_range("Index is out of range");
        }
        size_t octet_i = (index + numberStart) / 8;
        size_t bit_i = (index + numberStart) % 8;
        return octets[octet_i][bit_i];
    }


    /**
     * Возвращает экземпляр класса в дополнительном коде(если код этого числа - прямой)
     */
    BinaryNumber getTwosComplement() const {
        string newNum;
        bool sign = operator[](0);
        newNum.push_back(binaryToChar(sign));
        for (int i = 1; i < getLength(); i++) {
            bool newBit = operator[](i);
            if (sign) {
                newBit = !newBit;
            }
            newNum.push_back(binaryToChar(newBit));
        }

        if (!sign) {
            return BinaryNumber(newNum);
        }
        bool buf = true;
        for (int i = getLength() - 1; i >= 0; i--) {
            if (buf) {
                if (newNum[i] == '1') {
                    newNum[i] = '0';
                } else {
                    newNum[i] = '1';
                    buf = false;
                    break;
                }
            }
        }
        return BinaryNumber(newNum);
    }

    friend std::ostream &operator<<(std::ostream &os, BinaryNumber binaryNumber);

};

std::ostream &operator<<(std::ostream &os, BinaryNumber binaryNumber) {
    os << "Number: " << "start at index " << binaryNumber.numberStart << endl;
    for (int i = 0; i < binaryNumber.octetsLength; i++) {
        os << binaryNumber.octets[i];
    }
    os << endl;
    return os;
}

int main() {

    BinaryNumber b("1001000");

    cout << b;
    cout << b.getLength() << endl << b[0] << endl;
    cout << b.getTwosComplement();
}