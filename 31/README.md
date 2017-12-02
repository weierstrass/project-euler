# [Problem 31](https://projecteuler.net/problem=31) C++

## Solution approach
The base of the solution is realising that the solotion can be expressed recursively. The possible combinations of coins is the sum of all combinations including a specific coin + all solutions not including this specific coin. This recursive algorithm has exponential complexity with respect to the number of coins. By using dynamic programming we can reduce the complexity. Without the memoization the algorithm runs in 1000 ms compared to 4 ms with.

## Result
4 ms to run on a 2007 MacBook. Compiled with clang 6.0.

## Compile in debug mode

```cmake . -DCMAKE_BUILD_TYPE=Debug && make```

## Compile in release mode

```cmake . -DCMAKE_BUILD_TYPE=Release && make```

## Run

```./problem_31 --gtest_filter=problem_31.full```

