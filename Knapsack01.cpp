#include <algorithm>
#include <iostream>
#include "Knapsack01.h"

Knapsack01::Knapsack01(int _capacity, int _n, int *_weights, int *_values) :
        capacity{_capacity}, n{_n}, weights{_weights}, values{_values} {
    dp = new int *[n + 1];
    for (int i = 0; i < n + 1; ++i) {
        dp[i] = new int[capacity + 1];
        for (int j = 0; j <= capacity; ++j)
            dp[i][j] = 0;
    }
}

Knapsack01::~Knapsack01() {
    for (int i = 0; i < n + 1; ++i)
        delete[] dp[i];
    delete[] dp;
}

int Knapsack01::solve() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= capacity; ++j) {
            if (j >= weights[i - 1])
                dp[i][j] += std::max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    solved = true;
//    show();
    return dp[n][capacity];
}

bool *Knapsack01::items() {
    if (!solved) return nullptr;

    int i = n, j = capacity;
    bool *results = new bool[n];
    for (int k = 0; k < n; ++k) results[k] = false;

    while (i > 0 || j > 0) {
        if (dp[i][j] != dp[i - 1][j]) {
            j -= weights[i - 1];
            results[i - 1] = true;
        }
        i--;
    }
    return results;
}

void Knapsack01::show() {
    std::cout << '\n';
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= capacity; ++j) {
            std::cout << dp[i][j] << ' ';
        }
        std::cout << '\n';
    }
}
