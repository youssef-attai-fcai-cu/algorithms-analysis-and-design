#pragma once

class Fibonacci {
public:
    explicit Fibonacci(unsigned long long _n);
    ~Fibonacci();
    unsigned long long solve();
    
private:
    unsigned long long f(unsigned long long _n);
    
private:
    unsigned long long *dp;
    unsigned long long n;
};
