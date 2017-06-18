#include "problem_23.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <numeric>
#include <cmath>
#include <map>

using namespace std;

static const int MAX_VAL(28123);

int get_divisor_sum(const int num) {
    int sum(1);
    const int lim(sqrt(num));

    for (int i = 2; i <= lim; ++i) {
        if (num % i == 0) {
            sum += i;
            if (i != (num / i) && (num / i) != num) {
                sum += num/i;
            }
        }
    }
    return sum;
}

struct abundant_finder {
    
    bool operator()(const int val) {
        return get_divisor_sum(val) > val;
    }

} is_abundant;

TEST(problem_23, divisor_sum) {
    EXPECT_EQ(28, get_divisor_sum(28));
    EXPECT_EQ(16, get_divisor_sum(12));
}

TEST(problem_23, abundant_finder) {
    EXPECT_TRUE(is_abundant(12));
    EXPECT_FALSE(is_abundant(10));
    EXPECT_FALSE(is_abundant(11));
    EXPECT_FALSE(is_abundant(1));
    EXPECT_TRUE(is_abundant(54));
    EXPECT_FALSE(is_abundant(34));
}

TEST(problem_23, full) {
    // Find all abundant numbers.
    vector<int> all_nums(MAX_VAL);
    iota(begin(all_nums), end(all_nums), 1);

    vector<int> abundant_nums(MAX_VAL);

    auto it = copy_if(all_nums.begin(), all_nums.end(), abundant_nums.begin(), abundant_finder());
    abundant_nums.resize(distance(abundant_nums.begin(), it));

    // Find the sums of all the pairs of abundant numbers.
    vector<bool> abundant_sum(MAX_VAL);

    for (size_t i = 0; i < abundant_nums.size(); ++i) {
        for (size_t j = 0; j <= i; ++j) {
            int sum = abundant_nums[i] + abundant_nums[j];
            if (sum <= MAX_VAL){
                abundant_sum[sum] = true;
            } else {
                break;
            }
        }
    }

    // Sum up all numbers that were not a sum of two abundant numbers.
    int sum(0);
    for (int i = 0; i < MAX_VAL; ++i) {
        if (!abundant_sum[i]) sum += i;
    }
    
    EXPECT_EQ(4179871, sum);
}
