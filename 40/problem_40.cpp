#include "problem_40.hpp"

#include <iostream>

using namespace std;

TEST(problem_40, full) {
    string str;
    for (int i = 1; i <= 1e6; ++i) { str += to_string(i); }

    int d = 1;
    for (int i = 1; i <= 1e6; i *= 10) { d *= str[i - 1] - '0'; }
    
    EXPECT_EQ(210, d);
}
