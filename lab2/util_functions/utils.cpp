#include "utils.h"

std::string longToBinary(long num) {
    bool minus = false;
    if (num < 0) {
        minus = true;
        num *= -1;
    }
    std::bitset<sizeof(long) * 8> binarySet(num);

    std::string out = binarySet.to_string();

    if (minus) {
        out = '1' + out;
    } else {
        out = '0' + out;
    }
    return out;
}

char binaryToChar(bool bin) {
    if (bin) {
        return '1';
    } else {
        return '0';
    }
}

bool charToBinary(char bit) {
    if (bit == '0') {
        return false;
    } else if (bit == '1' or bit == '-') {
        return true;
    } else {
        throw std::invalid_argument("Cannot convert this character to boolean value");
    }
}