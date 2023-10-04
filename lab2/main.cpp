#include "binary_number/binary.h"
#include "octet/octet.h"

int main() {
    BinaryNumber b("10101");
    BinaryNumber b2(-11);
    cout << b2;
    cout << b2.getInBase(10) << endl;
}