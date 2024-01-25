#ifndef LAB2_BASE_CONVERTERS_H
#define LAB2_BASE_CONVERTERS_H

#include "../binary_number/binary.h"


const string DIGITS("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");

/**
 * @returns decimal representation of given BinaryNumber
 */
int getDecimal(const BinaryNumber& number);

/**
 * Converts decimal number to any supported base
 * @param base base number
 * @param decimal decimal number to convert
 * @note You can see(and change) how many bases are supported by checking out(or changing) `DIGITS`
 * @returns string with number's representation in requested base
 */
string decimalToBase(unsigned int base, int decimal);

#endif
