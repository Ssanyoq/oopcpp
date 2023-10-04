#ifndef LAB2_BASE_CONVERTERS_H
#define LAB2_BASE_CONVERTERS_H

#include "../binary_number/binary.h"

const string DIGITS("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");

int getDecimal(const BinaryNumber& number);

string decimalToBase(int base, int decimal);

#endif
