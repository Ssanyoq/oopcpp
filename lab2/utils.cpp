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