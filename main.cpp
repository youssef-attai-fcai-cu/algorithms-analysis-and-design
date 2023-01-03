#include <iostream>
#include "Fibonacci.h"

int main() {
    unsigned long long n;
    std::cout << "n = ";
    std::cin >> n;
    Fibonacci fib(n);
    std::cout << "fib(" << n << ") = " << fib.solve() << '\n';
    return 0;
}
