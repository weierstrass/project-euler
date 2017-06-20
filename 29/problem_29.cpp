#include "problem_29.hpp"

#include <cmath>

using namespace std;

TEST(problem_29, full) {
    vector<double> combinations;

    for (int a = 2; a <= 100; ++a) {
        for (int b = 2; b <= 100; ++b) {
            combinations.push_back(b * log2(a));
        }
    }

    // Using vector and after removing the duplicates is 5 times
    // faster than to use a set.
    sort(combinations.begin(), combinations.end());
    combinations.erase(
        unique(combinations.begin(), combinations.end()),
        combinations.end());
    
    EXPECT_EQ(9183, combinations.size());
}
