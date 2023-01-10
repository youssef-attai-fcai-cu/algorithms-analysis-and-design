cmake_minimum_required(VERSION 3.24)
project(algorithms_analysis_and_design)

set(CMAKE_CXX_STANDARD 14)

include_directories(dynamic_programming)

add_executable(algorithms_analysis_and_design
        dynamic_programming/CoinRow.cpp
        dynamic_programming/CoinRow.h
        dynamic_programming/Fibonacci.cpp
        dynamic_programming/Fibonacci.h
        dynamic_programming/Knapsack01.cpp
        dynamic_programming/Knapsack01.h
        dynamic_programming/LongestCommonSubsequence.cpp
        dynamic_programming/LongestCommonSubsequence.h
        dynamic_programming/RobotCollectCoins.cpp
        dynamic_programming/RobotCollectCoins.h
        main.cpp graph/MinimumSpanningTree_Kruskal.cpp graph/MinimumSpanningTree_Kruskal.h dynamic_programming/CoinChange.cpp dynamic_programming/CoinChange.h)
