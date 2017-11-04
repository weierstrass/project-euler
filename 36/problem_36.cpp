#include "problem_36.hpp"

#include <iostream>
#include <utility>

using namespace std;

const int MAX_VALUE = 1e6;

bool is_palindrom_dec(unsigned int n) {
    string num(to_string(n));
    string::const_iterator beg = num.begin(), end = num.end()-1;

    while (beg <= end) {
        if (*beg++ != *end--) {
            return false;
        }
    }

    return true;
}

unsigned int add_to_sum(string bits) {
    unsigned int n = bitset<20>(bits).to_ulong();

    if (n < MAX_VALUE && is_palindrom_dec(n)) return n;

    return 0;
}

void generate_bin(string bits, int& sum) {
    // generate full binary palindrom
    string rbits(bits);
    reverse(rbits.begin(), rbits.end());

    // add potential base 10 values from binary
    // palindrom
    sum += add_to_sum(rbits+bits)
        + add_to_sum(rbits + "1" + bits)
        + add_to_sum(rbits + "0" + bits);

    // stop recursion when reaching 10 digits
    if (bits.size() < 10) {   
        generate_bin("1" + bits, sum);
        generate_bin("0" + bits, sum);
    }
}

TEST(problem_36, is_palindrom_dec) {
    EXPECT_TRUE(is_palindrom_dec(585));
    EXPECT_TRUE(is_palindrom_dec(55));
    EXPECT_FALSE(is_palindrom_dec(586));
    EXPECT_TRUE(is_palindrom_dec(1));
    EXPECT_FALSE(is_palindrom_dec(10));
}

TEST(problem_36, full) {
    int sum(1);

    generate_bin("1", sum);

    EXPECT_EQ(872187, sum);
}
