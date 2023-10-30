#include "dynamic_octets.h"

void DynamicOctets::resize(size_t newLen) {
    if (newLen == length) {
        return;
    }
    auto *newOctets = new Octet[newLen];
    int oldI = getLength() - 1;
    for (int i = newLen - 1; (oldI >= 0) && (i >= 0); i--, oldI--) {
        newOctets[i] = octets[i].copy();
    }
    delete[] octets;
    octets = newOctets;
    length = newLen;
}

Octet &DynamicOctets::operator[](int index) const {
    if (index > length || index < 0) {
        throw std::invalid_argument("Unable to find Octet with this index");
    }
    return octets[index];
}