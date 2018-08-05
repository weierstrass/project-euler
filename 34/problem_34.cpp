#include "problem_34.hpp"

#include <iostream>
#include <array>

using namespace std;

static const int MAX_VAL = 2700000;

static const array<int,10> FACTORIALS {
    {
    1,
    1,
    2,
    6,
    24,
    120,
    720,
    5040,
    40320,
     362880}
};

bool digit_factorial(const int n) {
    int digit(n);
    int sum(0);
    while(digit > 0) {
        //   cout << digit % 10 << endl;
        sum += FACTORIALS[digit % 10];
        //cout << sum << endl;
        if (sum > n) return false;
        digit /= 10;
    }
    return sum == n;
}

TEST(problem_34, digit_factorial_145) {
    EXPECT_TRUE(digit_factorial(145));
}

TEST(problem_34, full) {
    //cout << "Problem 34" << endl;

    int sum = 0;
    for (int n = 10; n < MAX_VAL; ++n) {
        if (digit_factorial(n)) sum += n;
    }
    
    EXPECT_EQ(40730, sum);
}
