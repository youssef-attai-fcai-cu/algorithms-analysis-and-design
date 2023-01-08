#include <iostream>
#include <vector>
#include "LongestCommonSubsequence.h"
#include "Knapsack01.h"
#include "RobotCollectCoins.h"
#include "CoinRow.h"
#include "Fibonacci.h"
#include "graph/MinimumSpanningTree_Kruskal.h"

void fibonacci();

void coin_row();

void robot_collect_coins();

void longest_common_subsequence();

void knapsack_01();

void minimum_spanning_tree_kruskal();

void get_min_max();

int main() {
    get_min_max();
    return 0;
}


void minimum_spanning_tree_kruskal() {
    int n, e;
    std::cout << "Number of vertices: ";
    std::cin >> n;
    std::cout << "Number of edges: ";
    std::cin >> e;
    std::vector<std::pair<int, std::pair<int, int>>> graph;
    std::cout << "Edges:\n";
    int u, v, w;
    for (int i = 0; i < e; ++i) {
        std::cin >> u >> v >> w;
        graph.emplace_back(w, std::make_pair(u, v));
    }
    MinimumSpanningTree_Kruskal mst_kruskal(graph, n);
    std::cout << "Minimum = " << mst_kruskal.solve() << '\n';
}

void knapsack_01() {
    int n, capacity;
    std::cout << "capacity = ";
    std::cin >> capacity;
    std::cout << "n = ";
    std::cin >> n;
    int *weights = new int[n];
    std::cout << "Weights: ";
    for (int i = 0; i < n; ++i)
        std::cin >> weights[i];
    std::cout << "Values: ";
    int *values = new int[n];
    for (int i = 0; i < n; ++i)
        std::cin >> values[i];
    Knapsack01 ks(capacity, n, weights, values);
    std::cout << "Max value = " << ks.solve() << '\n';
    bool *items = ks.items();
    std::cout << "Items: ";
    for (int i = 0; i < n; ++i)
        if (items[i])
            std::cout << i + 1 << ' ';
    std::cout << '\n';
    delete[] items;
}

void longest_common_subsequence() {
    std::string first, second;
    std::cin >> first >> second;
    LongestCommonSubsequence lcs(first, second);
    std::cout << "Size of longest common subsequence = " << lcs.solve() << '\n';
    std::cout << "Longest common subsequence: " << lcs.subsequence() << '\n';
}

void robot_collect_coins() {
    int n, m;
    std::cout << "n = ";
    std::cin >> n;
    std::cout << "m = ";
    std::cin >> m;
    std::cout << "Board:\n";

    bool **board = new bool *[n];
    for (int i = 0; i < n; ++i) {
        board[i] = new bool[m];
        for (int j = 0; j < m; ++j)
            std::cin >> board[i][j];
    }

    RobotCollectCoins robotCollectCoins(board, n, m);
    std::cout << "Max collected = " << robotCollectCoins.solve() << '\n';

    for (int i = 0; i < n; ++i)
        delete[] board[i];
    delete[] board;
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
    for (int i = 0; i < n; ++i)
        if (selected[i])
            std::cout << coins[i] << ' ';
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

void get_min_max() {
    int n;
    std::cout << "n = ";
    std::cin >> n;
    int big_size = n / 2, small_size = n / 2 + (int) (n % 2 != 0);
    int big[big_size], small[small_size];
    std::cout << "Elements: ";
    for (int i = 0; i < big_size; ++i) std::cin >> big[i];
    for (int i = 0; i < small_size; ++i) std::cin >> small[i];
    for (int i = 0; i < small_size; ++i) {
        i = i % big_size;
        if (small[i] > big[i]) {
            int temp = big[i];
            big[i] = small[i];
            small[i] = temp;
        }
    }
    int M = INT32_MIN, m = INT32_MAX;
    for (int i = 0; i < n / 2; ++i) M = std::max(big[i], M);
    for (int i = 0; i < n / 2; ++i) m = std::min(small[i], m);
    std::cout << "Max = " << M << '\n';
    std::cout << "Min = " << m << '\n';
}
