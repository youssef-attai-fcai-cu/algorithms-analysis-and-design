#include <algorithm>
#include "RobotCollectCoins.h"

RobotCollectCoins::RobotCollectCoins(bool **_board, int _n, int _m) :
        board{_board}, n{_n}, m{_m} {
    dp = new int *[n + 1];
    for (int i = 0; i < n + 1; ++i) {
        dp[i] = new int[m + 1];
        for (int j = 0; j < m + 1; ++j) 
            dp[i][j] = 0;
    }
}

RobotCollectCoins::~RobotCollectCoins() {
    for (int i = 0; i < n + 1; ++i) 
        delete[] dp[i];
    delete[] dp;
}

int RobotCollectCoins::solve() {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) 
            dp[i][j] += f(i, j);
    return dp[n][m];
}

int RobotCollectCoins::f(int i, int j) {
    return std::max(dp[i - 1][j], dp[i][j - 1]) + board[i - 1][j - 1];
}
