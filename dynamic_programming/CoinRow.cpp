#include <algorithm>
#include "CoinRow.h"

CoinRow::CoinRow(int *_coins, int _n) :
        solved{false}, coins{_coins}, n{_n} {
    dp = new int[n + 1];
    dp[0] = 0;
    dp[1] = coins[0];
}

CoinRow::~CoinRow() {
    delete[] dp;
}

int CoinRow::solve() {
    for (int i = 2; i < n + 1; ++i)
        dp[i] = f(i);
    solved = true;
    return dp[n];
}

int CoinRow::f(int _n) {
    return std::max(coins[_n - 1] + dp[_n - 2], dp[_n - 1]);
}

bool * CoinRow::selectedCoins() {
    if (!solved) return nullptr;
    bool *result = new bool[n];
    for (int i = 0; i < n; ++i) result[i] = false;
    int current = dp[n];
    for (int i = n; i > 0; --i) {
        if (current != dp[i]) continue;
        if (dp[i] != dp[i - 1]) {
            result[i - 1] = true;
            current = dp[i] - coins[i - 1];
        }
    }
    return result;
}
