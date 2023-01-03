#include "LongestCommonSubsequence.h"

#include <utility>
#include <algorithm>
#include <iostream>

/*

president providence
 
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
            if (first[i - 1] == second[j - 1])
                dp[i][j].direction = DIAGONAL;
            else if (dp[i - 1][j].value >= dp[i][j - 1].value)
                dp[i][j].direction = UP;
            else if (dp[i - 1][j].value < dp[i][j - 1].value)
                dp[i][j].direction = LEFT;
            dp[i][j].value += f(i, j);
        }
    solved = true;
    return dp[first.size()][second.size()].value;
}

int LongestCommonSubsequence::f(size_t i, size_t j) {
    return std::max(dp[i - 1][j].value, dp[i][j - 1].value) + (int) (first[i - 1] == second[j - 1]);
}

std::string LongestCommonSubsequence::subsequence() {
    if (!solved) return "";
    
//    std::cout << '\n';
//    for (size_t i = 0; i <= first.size(); ++i) {
//        for (size_t j = 0; j <= second.size(); ++j)
//            std::cout << "(" << dp[i][j].value << ',' << dp[i][j].direction << ") ";
//        std::cout << '\n';
//    }

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
                result += second[j];
                break;
            default:
                throw "wtf?";
        }
    }
    std::reverse(result.begin(), result.end());
    return result;
}
