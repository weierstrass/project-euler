#include "problem_26.hpp"

#include <string>
#include <numeric>

using namespace std;

int cycle_length_for_denominator(int denom) {
    int length(0), rest(1);
    
    vector<int> rests;

    // Cycle can be max d - 1 if d is the denominator.
    for (int i = 0; i < denom; ++i) { 

        rest = (10 * rest) % denom;
            
        if (find(rests.begin(), rests.end(), rest) != rests.end()) {
            break;
        }
        
        rests.push_back(rest);
        
        length++;
    }

    return length;
}
 
TEST(problem_26, cycle_length) {
    EXPECT_EQ(6, cycle_length_for_denominator(7));
    EXPECT_EQ(1, cycle_length_for_denominator(6));
}

TEST(problem_26, full) {
    int max_cycle_length(0), max_denominator(0), cycle_length(0);
    
    for (int d = 0; d < 1000; ++d) {
        cycle_length = cycle_length_for_denominator(d);

        if (cycle_length > max_cycle_length) {
            max_cycle_length = cycle_length;
            max_denominator = d;
        }
    }

    EXPECT_EQ(982, max_cycle_length);
    EXPECT_EQ(983, max_denominator);
}
