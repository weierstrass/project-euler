#include "problem_31.hpp"

#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

typedef pair<int, int> memo_key_t;
typedef map<memo_key_t, int> memo_t;

int coin_comb(vector<int>::const_iterator start, vector<int>::const_iterator end, const int amount, memo_t& memo) {

    if (amount == 0) return 1;

    if (amount < 0) return 0;

    const int num_coins = end - start;

    if (num_coins == 0) return 0;

    // all combinations including the first coin
    const memo_key_t key_first = make_pair(num_coins, amount - *start);
    auto it_first = memo.find(key_first);
    
    if (it_first == memo.end()) {
        memo[key_first] = coin_comb(start, end, amount - *start, memo);
    }

    // all combinations not including the first coin
    const memo_key_t key_not_first = make_pair(num_coins - 1, amount);
    auto it_not_first = memo.find(key_not_first);

    if (it_not_first == memo.end()) {
        memo[key_not_first] = coin_comb(start + 1, end, amount, memo);
    }
    
    return  memo[key_first] + memo[key_not_first];
}

TEST(problem_31, full) {
    const int amount = 200;
    const vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200};
    memo_t memo;
    
    EXPECT_EQ(73682, coin_comb(coins.begin(), coins.end(), amount, memo));
}
