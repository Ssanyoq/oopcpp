#ifndef LAB2_OCTET_H
#define LAB2_OCTET_H

#include <cstdint>
#include <vector>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>

using std::cout;
using std::endl;
using std::string;

/**
 * A class that stores 8 bits(a byte). Uses `uint8_t`
 */
class Octet {
private:
    uint8_t data;
public:
    /**
     * Empty constructor mainly made for easier initialization of array with this type
     */
    explicit Octet(): data(0){};

    /**
     * Constructor that takes an array of 1's and 0's and
     * makes Octet from them
     * @param byte array of size 8 or more
     * @throws std::invalid_argument if values are not 0 and 1
     */
    explicit Octet(const int byte[8]);

    /**
     * @brief Constructor that takes `uint8_t`
     * @param byte integer of type `uint8_t`
     */
    explicit Octet(uint8_t byte) : data(byte){};

    /**
     * @brief Adds value of this Octet to other Octet
     * @param other another Octet
     * @returns Resulting Octet
     * @see Octet::add()
     */
    Octet operator+(const Octet &other) const;

    /**
     * @brief Performs bitwise AND with other Octet
     * @param other other Octet
     * @returns Resulting Octet
     */
    Octet operator&(const Octet &other) const;

    /**
     * @brief Returns value of needed bit
     * @param index Unsigned index of needed bit
     * @throws std::out_of_range If index is too big(> 7)
     * @return Boolean value of bit with index `index`
     */
    bool operator[](unsigned int index) const;



    /**
     * Sets individual bit to given value
     * @param index index of a bit that needs to be changed
     * @param value new boolean value
     *
     * @throws std::out_of_range if index is out of range( < 0 or > 7)
     */
    void setBit(int index, bool value);

    /**
     * @brief Performs bitwise NOT
     * @return Resulting Octet
     */
    [[nodiscard]] Octet operator~() const;

    /**
     * @brief Adds two Octets and writes carry in boolean variable
     * @note If `flag` is not nullptr, it will use its initial value in addition
     * @param other Another Octet
     * @param flag Pointer to boolean variable that will store carry resulting from addition
     * @return Resulting Octet
     */
    [[nodiscard]] Octet add(Octet other, bool *flag = nullptr) const;

    /**
     * @brief Returns value that equals 2^8 - Octet's value
     * @warning This value in some cases can be bigger than `uint8_t`
     * @return resulting integer value
     */
    int getAddition() const;

    /**
     * @returns Copy of this Octet
     */
    [[nodiscard]] Octet copy() const;

    friend std::ostream &operator<< (std::ostream &os, Octet octet);
};

#endif //LAB2_OCTET_H
