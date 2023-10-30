#include "base_converters.h"


int getDecimal(const BinaryNumber& number) {
    int decimal = 0;
    size_t len = number.getLength();
    for (int i = 1; i < len; i++) {
        decimal += number[i] << (len - 1 - i);
    }
    if (number[0]) {
        decimal *= -1;
    }
    return decimal;
}
string decimalToBase(unsigned int base, int decimal) {
    if (base < 2 or base > DIGITS.size()) {
        throw std::logic_error("Inputted base is not supported");
    }
    bool minus = false;
    if (decimal < 0) {
        minus = true;
        decimal *= -1;
    }
    string out;
    unsigned remainder, quotient = decimal;
    while (quotient >= base) {
        remainder = quotient % base;
        quotient = quotient / base;
        out.push_back(DIGITS[remainder]);
    }
    out.push_back(DIGITS[quotient]);
    if (minus) {
        out.push_back('-');
    }
    std::reverse(out.begin(), out.end());
    return out;
}