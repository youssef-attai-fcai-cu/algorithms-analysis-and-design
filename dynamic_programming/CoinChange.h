#pragma once

class CoinChange {
public:
    CoinChange(int _capacity, int _n, int *_values);
    ~CoinChange();
    int solve();
    void show();
private:
    int capacity, n, *values;
    int **dp;
};