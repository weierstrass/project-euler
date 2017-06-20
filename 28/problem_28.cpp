#include "problem_28.hpp"

#include <iostream>

using namespace std;

int sum_for_corners_in_square(int side) {
    return 4*side*side - 6*(side - 1);
}

TEST(problem_28, full) {
    int sum(1);

    for (int d = 3; d <= 1001; d+=2) {
        sum += sum_for_corners_in_square(d);
    }
    
    EXPECT_EQ(669171001, sum);
}
