#include "LongestCommonSubsequence.h"

#include <utility>
#include <algorithm>
#include <iostream>

/*

president providence
providence president
 
 */

LongestCommonSubsequence::LongestCommonSubsequence(std::string _first, std::string _second) :
        first{std::move(_first)}, second{std::move(_second)} {
    dp = new cell *[first.size() + 1];
    for (size_t i = 0; i < first.size() + 1; ++i)
        dp[i] = new cell[second.size() + 1];
}

LongestCommonSubsequence::~LongestCommonSubsequence() {
    for (size_t i = 0; i < first.size() + 1; ++i)
        delete[] dp[i];
    delete[] dp;
}

int LongestCommonSubsequence::solve() {
    for (size_t i = 1; i <= first.size(); ++i)
        for (size_t j = 1; j <= second.size(); ++j) {
            if (first[i - 1] == second[j - 1]) {
                dp[i][j].value = dp[i - 1][j - 1].value + 1;
                dp[i][j].direction = DIAGONAL;
            } else if (dp[i - 1][j].value >= dp[i][j - 1].value) {
                dp[i][j].value = dp[i - 1][j].value;
                dp[i][j].direction = UP;
            } else if (dp[i - 1][j].value < dp[i][j - 1].value) {
                dp[i][j].value = dp[i][j - 1].value;
                dp[i][j].direction = LEFT;
            }
        }
    solved = true;
//    show();
    return dp[first.size()][second.size()].value;
}

std::string LongestCommonSubsequence::subsequence() {
    if (!solved) return "";

    std::string result;
    size_t i = first.size(), j = second.size();
    while (i > 0 || j > 0) {
        switch (dp[i][j].direction) {
            case UP:
                i--;
                break;
            case LEFT:
                j--;
                break;
            case DIAGONAL:
                i--;
                j--;
                result += first[i];
                break;
            default:
                throw "wtf?";
        }
    }
    std::reverse(result.begin(), result.end());
    return result;
}

void LongestCommonSubsequence::show() {
    std::cout << '\n';
    for (size_t i = 0; i <= first.size(); ++i) {
        for (size_t j = 0; j <= second.size(); ++j)
            std::cout << "(" << dp[i][j].value << ',' << show(dp[i][j].direction) << ") ";
        std::cout << '\n';
    }
}

std::string LongestCommonSubsequence::show(Direction d) {
    switch (d) {
        case Direction::DIAGONAL:
            return "d";
        case Direction::UP:
            return "u";
        case Direction::LEFT:
            return "l";
        default:
            return "X";
    }
}
