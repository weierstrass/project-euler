# [Problem 26](https://projecteuler.net/problem=26) C++

## Solution approach
Important to realise for this problem is that it is not needed to compute the recurring cycles, just the length of them. With this my algorithm is based on long division where I count the iteration until we arrive to the same remainder, that is the length of the cycle. 

## Result
20 ms to run on a 2007 MacBook. Compiled with clang 6.0.

## Compile in debug mode

```cmake . -DCMAKE_BUILD_TYPE=Debug && make```

## Compile in release mode

```cmake . -DCMAKE_BUILD_TYPE=Release && make```

## Run

```./problem_26 --gtest_filter=problem_26.full```

