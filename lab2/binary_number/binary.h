#ifndef LAB2_BINARY_H
#define LAB2_BINARY_H

#include "../octet/octet.h"
#include "../util_functions/utils.h"
#include "../dynamic/dynamic_octets.h"


/**
 * Class that stores Number in its binary form using array of Octets
 * @see Octet DynamicOctets
 */
class BinaryNumber {
private:
//    int numberStart; // starting position

    DynamicOctets octets; // data storage
public:

    /**
     * @brief Constructor that makes number from string with its binary form
     * @note First symbol is considered to be a sign
     * @param binaryNumber `std::string` of 1's, 0's (and -)
     * @throws std::invalid_argument If string contains other symbols
     */
    explicit BinaryNumber(const string &binaryNumber);

    /**
     * @brief Constructor that makes class from long number
     */
    explicit BinaryNumber(long number);

    /**
     * Copying constructor that makes a copy of given object
     * @param other Object to copy
     * @see BinaryNumber::copy()
     */
    BinaryNumber(BinaryNumber const &other);

    /**
     * @returns Copy of this class object
     */
    BinaryNumber copy() const {
        return BinaryNumber{*this};
    }

    /**
     * Getter of number's length
     * @returns Amount of bits that are used to store this class
     * @note In some cases octets can be completely empty(for example if you're making class from `long` number)
     */
    size_t getLength() const;

    /**
     * Sets bit of given index to given value
     * @param index Index of bit to change
     * @param value New value of this bit
     * @throws std::out_of_range If index is out of range of this number
     */
    void setBit(int index, bool value);

    /**
     * Returns bit of given index
     * @param index int
     * @throws std::out_of_range if index is out of range of this number
     */
    bool operator[](int index) const;


    /**
     * @returns two's complement of this number
     */
    BinaryNumber getTwosComplement() const;

    /**
     * Opposite of `getTwosComplement()`
     */
    BinaryNumber getFromTwosComplement() const;


    /**
     * Returns string interpretation of this number in given base
     * @param base new base of number
     * @throws std::logic_error If this base is not supported
     * @return string number
     */
    string getInBase(unsigned int base) const;

    /**
     * @returns String representation of this number
     */
    string getString() const;

    /**
     * @returns Sign of this number. Analog of this[0]
     */
    bool getSign() const;

    /**
     * Concantenates 2 numbers. Uses 2's complement
     * @param other
     * @return Resulting BinaryNumber
     */
    BinaryNumber operator+(const BinaryNumber &other) const;

    /**
     * Performs bitwise NOT
     */
    BinaryNumber operator~() const;

    /**
     * Changes sign of a number
     * @returns Resulting number
     */
    BinaryNumber operator-() const;

    BinaryNumber operator-(const BinaryNumber &other) const;

    /**
     * Performs prefix -- operation
     */
    BinaryNumber operator--();

    /**
     * Performs postfix ++ operation
     */
    BinaryNumber operator++(int _);

    /**
     * Checks if 2 numbers have simillar value
     * @note Amount of octets doesn't matter. '00000001' == '00000000000000001'
     * @param other another number
     */
    bool operator==(const BinaryNumber& other) const;

    /**
     * Opposite of ==
     */
    bool operator!=(const BinaryNumber& other) const;

    friend std::ostream &operator<<(std::ostream &os, BinaryNumber binaryNumber);

};

#include "../util_functions/base_converters.h" // uses BinaryNumber,
// so it should be included after class declaration

#endif //LAB2_BINARY_H
