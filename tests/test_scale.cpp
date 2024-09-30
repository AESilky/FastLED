
// g++ --std=c++11 test.cpp

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "FastLED.h"
#include "lib8tion/scale8.h"
#include "lib8tion/intmap.h"

TEST_CASE("scale16by8") {
    CHECK_EQ(scale16by8(0, 0), 0);
    CHECK_EQ(scale16by8(0, 1), 0);
    CHECK_EQ(scale16by8(1, 0), 0);
    CHECK_EQ(scale16by8(map8_to_16(1), 1), 2);
    CHECK_EQ(scale16by8(0xffff, 0xff), 0xffff);
    CHECK_EQ(scale16by8(0xffff, 0xff >> 1), 0xffff >> 1);
    CHECK_EQ(scale16by8(0xffff >> 1, 0xff >> 1), 0xffff >> 2);

    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 8; ++j) {
            int total_bitshift = i + j;
            if (total_bitshift > 7) {
                break;
            }
            // print out info if this test fails to capture the i,j values that are failing
            INFO("i: " << i << " j: " << j << " total_bitshift: " << total_bitshift);
            CHECK_EQ(scale16by8(0xffff >> i, 0xff >> j), 0xffff >> total_bitshift);
        }
    }
}

