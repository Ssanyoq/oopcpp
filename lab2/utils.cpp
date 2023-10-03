#include "utils.h"

std::string longToBinary(long num) {
    std::bitset<sizeof(long) * 8> binarySet(num);

    return binarySet.to_string();
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
    } else if (bit == '1') {
        return true;
    } else {
        throw std::invalid_argument("Cannot convert this character to boolean value");
    }
}