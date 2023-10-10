#ifndef LAB2_BINARY_H
#define LAB2_BINARY_H

#include "../octet/octet.h"
#include "../util_functions/utils.h"


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
    bool operator[](int index) const;


    /**
     * Возвращает экземпляр класса в дополнительном коде(если код этого числа - прямой)
     */
    BinaryNumber getTwosComplement() const;

    /**
     * Полностью противоположная getTwosComplement функция
     * @see getTwosComplement()
     */
    BinaryNumber getFromTwosComplement() const;


    string getInBase(unsigned int base) const;

    string getString() const;

    bool getSign() const;

    BinaryNumber operator+(const BinaryNumber &other) const;

    BinaryNumber operator~() const;

    BinaryNumber operator-() const;

    BinaryNumber operator-(const BinaryNumber &other) const;

    BinaryNumber operator--();

    BinaryNumber operator++(int _);

    bool operator==(const BinaryNumber& other) const;

    bool operator!=(const BinaryNumber& other) const;

    friend std::ostream &operator<<(std::ostream &os, BinaryNumber binaryNumber);

};

#include "../util_functions/base_converters.h" // uses BinaryNumber,
// so it should be included after class declaration

#endif //LAB2_BINARY_H
