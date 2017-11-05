# [Problem 40](https://projecteuler.net/problem=40) C++

## Solution approach
Build the whole decimal fraction as a string, this is possible since it is not an incredible big string ~5MB. Depending on which compiler you are using, there is a risk of overflowing the stack, if that is the case you can allocate it on the heap instead or further optimise the solution (see below), Then construct the product asked in the question.

85% of the run time is for converting integers to strings. Further optimisations would be to not build the full decimal fraction but rather compute the product "on the fly".

## Result
300 ms to run on a 2007 MacBook. Compiled with clang 6.0.

## Compile in debug mode

```cmake . -DCMAKE_BUILD_TYPE=Debug && make```

## Compile in release mode

```cmake . -DCMAKE_BUILD_TYPE=Release && make```

## Run

```./problem_40 --gtest_filter=problem_40.full```

