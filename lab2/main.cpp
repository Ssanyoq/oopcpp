#include "binary.h"
#include "octet.h"

int main() {
    //  (0)1001010

    BinaryNumber b("1001010");
    BinaryNumber b1("11110110");
    cout << b.getTwosComplement();
    cout << b1.getFromTwosComplement();
    cout << b + b1;
}