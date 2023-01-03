#pragma once

/*

capacity = 5
n = 4
Weights: 2 1 3 2
Values: 12 10 20 15
 
*/

class Knapsack01 {
public:
    Knapsack01(int _capacity, int _n, int *_weights, int *_values);
    ~Knapsack01();
    int solve();
    bool * items();
    void show();
private:
    int capacity, n, *weights, *values;
    int **dp;
    bool solved{false};
};
