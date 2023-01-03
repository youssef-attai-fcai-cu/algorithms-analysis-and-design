#pragma once

/*
 test case:
------------
 n = 5
 m = 6
 Board:
 0 0 0 0 1 0
 0 1 0 1 0 0
 0 0 0 1 0 1
 0 0 1 0 0 1
 1 0 0 0 1 0
*/

class RobotCollectCoins {
public:
    RobotCollectCoins(bool **_board, int _n, int _m);

    int solve();

    ~RobotCollectCoins();

private:
    bool **board;
    int **dp;
    int n, m;

    int f(int i, int j);
};
