#ifndef LAB2_DYNAMIC_OCTETS_H
#define LAB2_DYNAMIC_OCTETS_H

#include "../octet/octet.h"

class DynamicOctets {
private:
    Octet* octets;
    size_t length;
public:
    explicit DynamicOctets(size_t len) {
        length = len;
        octets = new Octet[len];
    }
    DynamicOctets() {
        length = 0;
        octets = nullptr;
    }

    void resize(size_t newLen);

    Octet &operator[](int index) const;

    size_t getLength() const {return length;}

    ~DynamicOctets() {
        delete[] octets;
    }
};
#endif
