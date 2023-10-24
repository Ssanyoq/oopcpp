#include "binary_number/binary.h"
#include "octet/octet.h"
#include "dynamic/dynamic_octets.h"
long getNum(long min = std::numeric_limits<int>::lowest(), long max = std::numeric_limits<int>::max()) {
    long a;
    while (true) {
        std::cin >> a;
        if (std::cin.eof())
            throw std::runtime_error("EOF");
        else if (std::cin.bad())
            throw std::runtime_error(std::string("Failed to read number: ") + strerror(errno));
        else if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Bad input, try again: " << std::endl;
        } else if (a >= min && a <= max)
            return a;
        else {
            cout << "Not in range, again: ";
        }
    }
}

int main() {
    BinaryNumber binaryNumber(0);
    while (true) {
        cout << "Pick option: " << endl;
        cout << "1 - create new number" << endl;
        cout << "2 - add number to current number" << endl;
        cout << "3 - print out a number" << endl;
        cout << "4 - perform bitwise NOT" << endl;
        cout << "5 - get number in some base" << endl;
        cout << "0 - quit" << endl;

        int option = getNum(0, 5);
        bool isQuitting = false;
        switch (option) {
            case 0: {
                isQuitting = true;
                break;
            }
            case 1: {
                cout << "Input new number: ";
                long newNumber = getNum();
                binaryNumber = BinaryNumber(newNumber);
                break;
            }
            case 2: {
                cout << "Input number to add: ";
                long newNumber = getNum();
                binaryNumber = binaryNumber + BinaryNumber(newNumber);
                break;
            }
            case 3: {
                cout << binaryNumber << endl;
                break;
            }
            case 4: {
                binaryNumber = ~binaryNumber;
                break;
            }
            case 5: {
                cout << "Input base(any from 2 to 36, as defined in util_functions/utils.h): ";
                long base = getNum();
                cout << binaryNumber.getInBase(base) << endl;
                break;
            }

        }
        if (isQuitting) {
            break;
        }
    }

    return 0;
}