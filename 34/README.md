# [Problem 34](https://projecteuler.net/problem=34) C++

## Solution approach
The first thing we need to check is to find out what the upper limit would be of the numbers we need to check. We realise that there must be an upper limit since as the number itself grows linearly its sums of factorials only grow logarithmically so there is a point where it is no longer possible to find more factorial sums. Basically an upper limit for the biggest number can be estimated taking only 9!s for the factorial digit sum. Basically we want to find n where:

n > 9!(digits of n)
n > 9!(log10(n) + 1)

We can not solve it analytically but we see that n must be smaller than 1e7 which can be used as uper limit or we can try to get a more precise limit through for instance:
http://www.wolframalpha.com/input/?i=n+%3E+9!(log10(n)+%2B+1)

which gives n as approximately 2.7e6.

After the upper limit is determined it is relatively straightforward to implement the algorithm. Make sure to not recompute the factorials of each digit [0,9] but only do it once and reuse the result. 

## Result
105 ms to run on a 2007 MacBook. Compiled with clang 6.0.

## Compile in debug mode

```cmake . -DCMAKE_BUILD_TYPE=Debug && make```

## Compile in release mode

```cmake . -DCMAKE_BUILD_TYPE=Release && make```

## Run

```./problem_34 --gtest_filter=problem_34.full```

