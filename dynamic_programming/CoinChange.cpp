#include <iostream>
#include "CoinChange.h"

CoinChange::~CoinChange() {
    for (int i = 0; i < n + 1; ++i)
        delete[] dp[i];
    delete[] dp;
}

CoinChange::CoinChange(int _capacity, int _n, int *_values) :
        capacity{_capacity}, n{_n}, values{_values} {
    dp = new int *[n + 1];
    for (int i = 0; i < n + 1; ++i) {
        dp[i] = new int[capacity + 1];
        for (int j = 0; j <= capacity; ++j)
            dp[i][j] = 0;
    }
}

int CoinChange::solve() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= capacity; ++j) {
            int coins = j / values[i - 1];
            if (coins * values[i - 1] != j)
                dp[i][j] += std::min(dp[i - 1][j - (coins * values[i - 1])] + coins, dp[i - 1][j]);
            else
                dp[i][j] = coins;
        }
    }
    show();
    return dp[n][capacity];
}

void CoinChange::show() {
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= capacity; ++j) {
            std::cout << dp[i][j] << ' ';
        }
        std::cout << '\n';
    }
}
