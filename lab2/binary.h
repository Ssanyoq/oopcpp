#ifndef LAB2_BINARY_H
#define LAB2_BINARY_H

#include "octet.h"
#include "utils.h"


class BinaryNumber {
private:
//    int numberStart; // starting position

    size_t octetsLength;
    Octet *octets; // data storage
public:

    /**
     * Конструктор, принимающий строку
     * @param binaryNumber - нужное число в двоичном представлении, прямой код
     *
     * (первый бит - знак числа)
     */
    explicit BinaryNumber(const string &binaryNumber);

    explicit BinaryNumber(long number);

    BinaryNumber(BinaryNumber const &other);

    BinaryNumber copy() const {
        return BinaryNumber(*this);
    }

    size_t getLength() const;

    void setBit(int index, bool value);

    /**
     * Возвращает бит числа под индексом index. Начинается с 0 и нулевой бит - знак
     * @param index int
     * @throws std::out_of_range если индекс выходит за рамки разрешенного
     */
    bool operator [](int index) const;


    /**
     * Возвращает экземпляр класса в дополнительном коде(если код этого числа - прямой)
     */
    BinaryNumber getTwosComplement() const;

    /**
     * Полностью противоположная getTwosComplement функция
     * @see getTwosComplement()
     */
    BinaryNumber getFromTwosComplement();

    string getString() const;

    BinaryNumber operator +(const BinaryNumber &other) const;

    BinaryNumber operator~() const;

    BinaryNumber operator-() const;

    friend std::ostream &operator<<(std::ostream &os, BinaryNumber binaryNumber);

};

#endif //LAB2_BINARY_H
