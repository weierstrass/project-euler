# [Problem 36](https://projecteuler.net/problem=36) C++

## Solution approach
The upper decimal limit of one milion gives us the binary limit of max 20 digits. First, we generate all possible palindroms in base 2 and then for each of them check if they are also a palindrom in base 10. This will lead to 2^10 ~1000 numbers to check which should be no problem for any computer. The base 2 palindroms to check are generated in a recursive manner (see code). It is only needed to go down 10 levels into the recursion to generate a 20 digit palindrom.

## Result
3 ms to run on a 2007 MacBook. Compiled with clang 6.0.

## Compile in debug mode

```cmake . -DCMAKE_BUILD_TYPE=Debug && make```

## Compile in release mode

```cmake . -DCMAKE_BUILD_TYPE=Release && make```

## Run

```./problem_36 --gtest_filter=problem_36.full```

