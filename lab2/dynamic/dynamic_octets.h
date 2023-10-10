#ifndef LAB2_DYNAMIC_OCTETS_H
#define LAB2_DYNAMIC_OCTETS_H

#include "../octet/octet.h"


/**
 * A class that stores array of Octets and manages memory
 * @see Octet
 */
class DynamicOctets {
private:
    Octet* octets;
    size_t length;
public:
    /**
     * Constructor that takes length of needed array
     * @param len
     */
    explicit DynamicOctets(size_t len) {
        length = len;
        octets = new Octet[len];
    }
    /**
     * Empty constructor that makes 0-length array
     */
    DynamicOctets() {
        length = 0;
        octets = nullptr;
    }

    DynamicOctets(const DynamicOctets &other) {
        length = other.length;
        octets = new Octet[length];
        for (int i = 0; i < length; i++) {
            octets[i] = other[i].copy();
        }
    }

    /**
     * Resizes array to given length
     * @param newLen - new length of an array
     */
    void resize(size_t newLen);

    /**
     * Returns Octet with given index
     * @throws std::invalid_argument if index is less than 0 or bigger than array's length - 1
     * @return Needed octet
     */
    Octet &operator[](int index) const;

    /**
     * Getter of array's length
     */
    size_t getLength() const {return length;}
};
#endif
