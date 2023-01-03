#include "Fibonacci.h"

Fibonacci::Fibonacci(unsigned long long _n) : n{_n} {
    dp = new unsigned long long[n];
    dp[0] = 0;
    dp[1] = 1;
}

Fibonacci::~Fibonacci() {
    delete[] dp;
}

unsigned long long Fibonacci::solve() {
    for (unsigned long long i = 2; i < n; ++i) dp[i] = f(i);
    return f(n);
}

unsigned long long Fibonacci::f(unsigned long long _n) {
    return dp[_n - 1] + dp[_n - 2];
}
