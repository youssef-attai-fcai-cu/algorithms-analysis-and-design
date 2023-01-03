#pragma once

#include <string>

enum Direction {
    NONE, UP, LEFT, DIAGONAL
};

struct cell {
    int value;
    Direction direction;

    cell() : value{0}, direction{NONE} {}
};

class LongestCommonSubsequence {
public:
    LongestCommonSubsequence(std::string _first, std::string _second);

    ~LongestCommonSubsequence();

    int solve();

    void show();
    std::string show(Direction d);
    
    std::string subsequence();

private:
    int f(size_t i, size_t j);

private:
    cell **dp;
    std::string first, second;
    bool solved{false};
};