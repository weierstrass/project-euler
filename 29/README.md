# [Problem 29](https://projecteuler.net/problem=29) C++

## Solution approach
We realise that to compute the terms, even if the complexty is not too high we will have problem with big numbers, 100^100 will never fit in any built in type in C++. The trick is to check the number of unique terms of b * log2(a) = log2(a^b) which will give the same number since log2 is strictly increasing.

## Result
1 ms to run on a 2007 MacBook. Compiled with clang 6.0.

## Compile in debug mode

```cmake . -DCMAKE_BUILD_TYPE=Debug && make```

## Compile in release mode

```cmake . -DCMAKE_BUILD_TYPE=Release && make```

## Run

```./problem_29 --gtest_filter=problem_29.full```

