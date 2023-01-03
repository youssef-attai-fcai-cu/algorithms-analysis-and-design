#include <iostream>
#include "Fibonacci.h"
#include "CoinRow.h"

void fibonacci();

void coin_row();

int main() {
    coin_row();
    return 0;
}

void coin_row() {
    int n;
    std::cout << "n = ";
    std::cin >> n;
    int coins[n];
    for (int i = 0; i < n; ++i) std::cin >> coins[i];
    CoinRow coinRow(coins, n);
    std::cout << "Max amount = " << coinRow.solve() << '\n';
    std::cout << "Selected coins: ";
    bool *selected = coinRow.selectedCoins();
    for (int i = 0; i < n; ++i) if (selected[i]) std::cout << coins[i] << ' ';
    std::cout << '\n';
    delete[] selected;
}

void fibonacci() {
    unsigned long long n;
    std::cout << "n = ";
    std::cin >> n;
    Fibonacci fib(n);
    std::cout << "fib(" << n << ") = " << fib.solve() << '\n';
}
