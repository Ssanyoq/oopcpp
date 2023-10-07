#include "../catch2/catch_amalgamated.hpp"
#include "../octet/octet.h"
#include "../binary_number/binary.h"
#include "../util_functions/utils.h"
#include "../util_functions/base_converters.h"

#define SET_RAND srand(time(NULL))


TEST_CASE("Octet constructors") {
    SET_RAND;
    SECTION("Int array") {
        int arr[8];
        for (int &i: arr) {
            i = abs(rand()) % 2;
        }
        Octet o(arr);
        for (int &i: arr) {
            REQUIRE(o[i] == arr[i]);
        }

    }SECTION("Illegal int array") {
        int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
        REQUIRE_THROWS(Octet(arr));

    }SECTION("uint8_t") {
        uint8_t num = abs(rand()) % 256;
        Octet o(num);
        for (int i = 0; i < 8; i++) {
            bool cur = num & (1 << (7 - i));
            REQUIRE(cur == o[i]);
        }
    }SECTION("Empty") {
        Octet o;
        for (int i = 0; i < 8; i++) {
            REQUIRE(o[i] == 0);
        }
    }
}

TEST_CASE("Arithmetic octet operators") {
    SET_RAND;
    SECTION("+") {
        uint8_t num1 = abs(rand()) % 256, num2 = abs(rand()) % 256, sum = num1 + num2;

        Octet o1(num1), o2(num2), o_sum = o1 + o2;

        for (int i = 0; i < 8; i++) {
            bool cur = sum & (1 << (7 - i));
            REQUIRE(o_sum[i] == cur);
        }
    }
}

TEST_CASE("Bitwise octet operators") {
    SET_RAND;
    SECTION("~") {
        int arr[8];
        for (int &i: arr) {
            i = abs(rand()) % 2;
        }

        Octet o = ~(Octet(arr));
        for (int &i: arr) {
            int curNum = (arr[i] + 1) % 2;
            REQUIRE(curNum == o[i]);
        }
    }SECTION("&") {
        int arr1[8], arr2[8];
        for (int i = 0; i < 8; i++) {
            arr1[i] = abs(rand()) % 2;
            arr2[i] = abs(rand()) % 2;
        }

        Octet o = Octet(arr1) & Octet(arr2);

        for (int i = 0; i < 8; i++) {
            bool cur = arr1[i] & arr2[i];
            REQUIRE(o[i] == cur);
        }

    }
}

TEST_CASE("Index operators") {
    SET_RAND;
    SECTION("Index < 0") {
        Octet o;
        REQUIRE_THROWS(o[-abs(rand())]);
    }SECTION("Index > 7") {
        Octet o;
        REQUIRE_THROWS(o[abs(rand()) + 7]);
    }
}

TEST_CASE("Octet copying") {
    SET_RAND;
    Octet o(abs(rand()) % 256);
    Octet oCopy = o.copy();
    for (int i = 0; i < 8; i++) {
        REQUIRE(o[i] == oCopy[i]);
    }
}

TEST_CASE("Octet addition") {
    SET_RAND;
    uint8_t a = abs(rand()) % 256, b = abs(rand()) % 256;
    uint16_t sum = a + b;
    Octet o1(a), o2(b);
    bool carry = false;
    Octet o = o1.add(o2, &carry);
    if (sum > 255) {
        REQUIRE(carry);
    }
    Octet oSum = o1 + o2;
    for (int i = 0; i < 8; i++) {
        REQUIRE(oSum[i] == o[i]);
    }
}

TEST_CASE("Octet setBit") {
    SECTION("All 1s") {
        Octet o;
        for (int i = 0; i < 8; i++) {
            o.setBit(i, 1);
            REQUIRE(o[i]);
        }
    }SECTION("All 0s") {
        int ones[] = {1,1,1,1,1,1,1,1};
        Octet o(ones);
        for (int i = 0; i < 8; i++) {
            o.setBit(i, 0);
            REQUIRE(!o[i]);
        }
    }SECTION("Random") {
        Octet o(abs(rand()) % 256);
        for (int i = 0; i < 8; i++) {
            bool cur = abs(rand()) % 2;
            o.setBit(i, cur);
            REQUIRE(o[i] == cur);
        }
    }SECTION("Index > 7") {
        Octet o;
        REQUIRE_THROWS(o.setBit(abs(rand()) + 7, 1));
    }SECTION("Index < 0") {
        Octet o;
        REQUIRE_THROWS(o.setBit(-abs(rand()) - 1, 0));
    }
}

TEST_CASE("Octets' addition") {
    SET_RAND;
    uint8_t num = abs(rand()) % 256;
    Octet o(num);
    REQUIRE(256 - num == o.getAddition());
}