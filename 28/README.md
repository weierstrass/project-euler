# [Problem 28](https://projecteuler.net/problem=28) C++

## Solution approach
We see that for each "layer" in the spiral that the sum of the corners can be written as n^2 + n^2 - (n - 1) + n^2 - 2(n - 1) + n^2 - 3(n - 1) = 4n^2 - 6(n - 1), where n is the side of the layer, 3 <= n <= 1001.

## Result
less than 0.1 ms to run on a 2007 MacBook. Compiled with clang 6.0.

## Compile in debug mode

```cmake . -DCMAKE_BUILD_TYPE=Debug && make```

## Compile in release mode

```cmake . -DCMAKE_BUILD_TYPE=Release && make```

## Run

```./problem_28 --gtest_filter=problem_28.full```

