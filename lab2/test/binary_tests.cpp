#include "../catch2/catch_amalgamated.hpp"
#include "../octet/octet.h"
#include "../binary_number/binary.h"
#include "../util_functions/utils.h"
#include "../util_functions/base_converters.h"

#define SET_RAND srand(time(NULL))

#define RAND_RANGE 1000

/* ------------------------------------------------------------
                    Constructors
   ------------------------------------------------------------ */

TEST_CASE("String constructor") {
    unsigned len = rand() % RAND_RANGE;
    string strNum;
    for (int i = 0; i < len; i++) {
        if (rand() % 2 == 1) {
            strNum.push_back('1');
        } else {
            strNum.push_back('0');
        }
    }
    BinaryNumber binNum(strNum);

    REQUIRE(binNum.getSign() == charToBinary(strNum[0]));

    int stringI = strNum.size() - 1; // index for string
    int binI = binNum.getLength() - 1; // index for BinaryNumber
    for (; binI > 0, stringI > 0; binI--, stringI--) { // 0th is sign
        REQUIRE(binNum[binI] == charToBinary(strNum[stringI]));
    }
}

TEST_CASE("Long constructor") {
    long number = rand() % RAND_RANGE;
    if (rand() % 2) {
        number *= -1;
    }
    BinaryNumber binaryNumberFromLong(number);
    string stringNum = longToBinary(number);
    BinaryNumber binaryNumberFromString(stringNum);
    REQUIRE(binaryNumberFromLong == binaryNumberFromString);
}

TEST_CASE("Copying constructor") {
    long number = rand() % RAND_RANGE;
    BinaryNumber original(number);
    BinaryNumber copy(original);
    REQUIRE(original == copy);
}


/* ------------------------------------------------------------
                    Operators
   ------------------------------------------------------------ */


TEST_CASE("BinaryNumber == and !=") {
    long number = rand() % RAND_RANGE;
    if (rand() % 2) {
        number *= -1;
    }SECTION("Equals") {
        BinaryNumber binaryNumber1(number), binaryNumber2(number);
        REQUIRE(binaryNumber1 == binaryNumber2);
        REQUIRE(!(binaryNumber2 != binaryNumber1));
    }SECTION("Not equals") {
        REQUIRE(BinaryNumber(number) != BinaryNumber(number + 1));
        REQUIRE(!(BinaryNumber(number) == BinaryNumber(number + 1)));
        REQUIRE(BinaryNumber(number) != BinaryNumber(-number));
    }SECTION("Equals with different octet amounts") {
        string s1 = "0000000000000000000000000000000000000000001010",
                s2 = "01010";
        BinaryNumber n1(s1), n2(s2);
        REQUIRE(n1.getLength() != n2.getLength()); // for correct test
        REQUIRE(n1 == n2);
        REQUIRE(!(n1 != n2));
    }
}

TEST_CASE("BinaryNumber []") {
    long number = rand() % RAND_RANGE;
    BinaryNumber binaryNumber(number);
    size_t len = binaryNumber.getLength();
    SECTION("i >= length") {
        REQUIRE_THROWS_AS(binaryNumber[len], std::out_of_range);
    }SECTION("i < 0") {
        REQUIRE_THROWS_AS(binaryNumber[-1], std::out_of_range);
    }
}

TEST_CASE("BinaryNumber +") {
    long number1 = rand() % RAND_RANGE;
    if (rand() % 2) {
        number1 *= -1;
    }
    long number2 = rand() % RAND_RANGE;
    if (rand() % 2) {
        number2 *= -1;
    }
    BinaryNumber binaryNumberOverloadedSum = BinaryNumber(number1) + BinaryNumber(number2),
            binaryNumberOGSum = BinaryNumber(number2 + number1);
    REQUIRE(binaryNumberOverloadedSum == binaryNumberOGSum);
}

TEST_CASE("BinaryNumber unary -") {
    long number1 = rand() % RAND_RANGE;
    if (rand() % 2) {
        number1 *= -1;
    }
    BinaryNumber binaryNumber1(-number1), binaryNumber2 = -BinaryNumber(number1);
    REQUIRE(binaryNumber1 == binaryNumber2);
}

TEST_CASE("BinaryNumber binary -") {
    long number1 = rand() % RAND_RANGE, number2 = rand() % RAND_RANGE;
    BinaryNumber normalMinus(number1 - number2), overloadedMinus = BinaryNumber(number1) - BinaryNumber(number2);

    REQUIRE(normalMinus == overloadedMinus);
}

TEST_CASE("BinaryNumber ~") {
    string s;
    for (int i = 0; i < RAND_RANGE; i++) {
        if (rand() % 2 == 1) {
            s.push_back('1');
        } else {
            s.push_back('0');
        }
    }
    BinaryNumber binaryNumber = ~BinaryNumber(s);
    REQUIRE(charToBinary(s[0]) != binaryNumber.getSign());
    for (int binaryI = binaryNumber.getLength() - 1, stringI = s.size() - 1;
         binaryI > 0, stringI > 0; binaryI--, stringI--) {
        REQUIRE(charToBinary(s[stringI]) != binaryNumber[binaryI]);
    }
}

TEST_CASE("BinaryNumber n++") {
    long number = rand() % RAND_RANGE;
    if (rand() % 2) {
        number *= -1;
    }
    BinaryNumber binaryNumber(number);
    BinaryNumber after = binaryNumber++;
    REQUIRE((after + BinaryNumber(1)) == binaryNumber);
}

TEST_CASE("BinaryNumber --n") {
    long number = rand() % RAND_RANGE;
    if (rand() % 2) {
        number *= -1;
    }
    BinaryNumber binaryNumber(number);
    BinaryNumber after = --binaryNumber;
    REQUIRE(after == binaryNumber);
}


TEST_CASE("BinaryNumber.setBit") {
    string s;
    for (int i = 0; i < RAND_RANGE; i++) {
        if (rand() % 2 == 1) {
            s.push_back('1');
        } else {
            s.push_back('0');
        }
    }
    int i = rand() % RAND_RANGE;
    BinaryNumber methodNumber(s);
    bool newValue = rand() % 2;
    s[i] = binaryToChar(newValue);
    methodNumber.setBit(i, newValue);
    REQUIRE(methodNumber == BinaryNumber(s));

    SECTION("Throw check") {
        REQUIRE_THROWS_AS(methodNumber.setBit(-1, 1), std::out_of_range);
        REQUIRE_THROWS_AS(methodNumber.setBit(methodNumber.getLength(), 0), std::out_of_range);
    }
}

TEST_CASE("BinaryNumber two's complement") {
    BinaryNumber number("11101011");
    cout << number;
    REQUIRE(number.getTwosComplement() == BinaryNumber("10010101"));

    BinaryNumber num(rand() % RAND_RANGE);
    REQUIRE(num == num.getTwosComplement().getFromTwosComplement());
}



/*
 * Related util
 */

TEST_CASE("get decimal") {
    long number = rand() % RAND_RANGE;
    REQUIRE(getDecimal(BinaryNumber(number)) == number);
    REQUIRE(getDecimal(BinaryNumber(-number)) == -number);

    SECTION(">=0 in binary") {
        string binary = longToBinary(number);
        string methodBinary = '0' + BinaryNumber(number).getInBase(2);
        REQUIRE(BinaryNumber(binary) == BinaryNumber(methodBinary));
    }SECTION("< 0 in binary") {
        number *= -1;
        string binary = longToBinary(number);
        string methodBinary = BinaryNumber(number).getInBase(2);
        REQUIRE(BinaryNumber(binary) == BinaryNumber(methodBinary));
    }

}