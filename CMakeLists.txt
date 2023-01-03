cmake_minimum_required(VERSION 3.24)
project(dynamic_programming)

set(CMAKE_CXX_STANDARD 17)

add_executable(dynamic_programming main.cpp Fibonacci.cpp Fibonacci.h CoinRow.cpp CoinRow.h RobotCollectCoins.cpp RobotCollectCoins.h LongestCommonSubsequence.cpp LongestCommonSubsequence.h Knapsack01.cpp Knapsack01.h)
