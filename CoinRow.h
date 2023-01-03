#pragma once

class CoinRow {
public:
    explicit CoinRow(int *_coins, int _n);

    ~CoinRow();

    int solve();
    
    bool * selectedCoins();

private:
    int f(int _n);

private:
    int *dp;
    int *coins;
    int n;
    bool solved;
};
