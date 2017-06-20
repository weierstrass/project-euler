#include "problem_30.hpp"

#include <iostream>

using namespace std;

bool fifth_power_for_number(const int num) {
    int digit(0), n(num), sum(0);
    
    while (n > 0) {
        digit = n % 10;

        // More than 2 times faster than pow(digit, 5),
        sum += digit*digit*digit*digit*digit;

        if (sum > num) return false;
        
        n /= 10;
    }

    return sum == num;
}

TEST(problem_30, fifth_power) {
    EXPECT_TRUE(fifth_power_for_number(4150));
}

TEST(problem_30, full) {
    int sum(0);

    for (int n = 3125; n <= 10e6; ++n) {
        if (fifth_power_for_number(n)) {
            sum += n;
        }
    }
    
    EXPECT_EQ(443839, sum);
}
