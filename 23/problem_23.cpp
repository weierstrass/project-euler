#include "problem_23.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <numeric>
#include <cmath>

using namespace std;

static const int MAX_VAL(28123);


struct is_divisor {

    is_divisor(int num) : m_num(num) {}
    
    bool operator()(int divisor_cand) {
        return m_num % divisor_cand == 0;
    }

private:
    int m_num;
};

struct abundant_finder {
    bool operator()(int val) {
//        cout << sqrt(val) << endl;

        vector<int> divisor_cands(val/2);
        iota(begin(divisor_cands), end(divisor_cands), 1);
                
        vector<int> divisors(val/2);
        auto it =
            copy_if(divisor_cands.begin(), divisor_cands.end(), divisors.begin(), is_divisor(val));
        divisors.resize(distance(divisors.begin(), it));

        return accumulate(divisors.begin(), divisors.end(), 0) > val;
    }
} is_abundant;

TEST(problem_23, divisor_finder) {
    is_divisor divisor_finder(28);

    EXPECT_TRUE(divisor_finder(1));
    EXPECT_TRUE(divisor_finder(2));
    EXPECT_TRUE(divisor_finder(4));
    EXPECT_TRUE(divisor_finder(7));
    EXPECT_TRUE(divisor_finder(14));
    EXPECT_FALSE(divisor_finder(15));
    EXPECT_FALSE(divisor_finder(56));
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

    vector<int> all_vals(MAX_VAL);
    iota(begin(all_vals), end(all_vals), 1);

    EXPECT_EQ(5, all_vals.at(4));


    vector<int> abundant_nums(MAX_VAL);

    auto it = copy_if(all_vals.begin(), all_vals.end(), abundant_nums.begin(), is_abundant);
    abundant_nums.resize(distance(abundant_nums.begin(), it));

    vector<int> abundant_sums;

    for (int term1 : abundant_nums) {
        for (int term2 : abundant_nums) {
            int sum = term1 + term2;
            if (sum <= MAX_VAL)
                abundant_sums.push_back(sum);
        }
    }

    sort(abundant_sums.begin(), abundant_sums.end());
    abundant_sums.erase(unique(abundant_sums.begin(), abundant_sums.end()), abundant_sums.end());

    vector<int> all_nums(MAX_VAL);
    iota(begin(all_nums), end(all_nums), 1);

    cout << abundant_sums.size() << ", " << all_nums.size() << endl;

     std::vector<int> non_abundant_sums;

     std::set_symmetric_difference(all_nums.begin(), all_nums.end(),
                                   abundant_sums.begin(), abundant_sums.end(),
                                   back_inserter(non_abundant_sums));

     std::copy(non_abundant_sums.begin(), non_abundant_sums.end(),
               std::ostream_iterator<int>(cout, " "));

     int total = accumulate(non_abundant_sums.begin(), non_abundant_sums.end(), 0);
            
    
    EXPECT_EQ(52749780, total);
}
