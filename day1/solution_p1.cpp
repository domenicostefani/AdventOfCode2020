#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#include "utils.h"

/*************************************************************************/
/* Solution 0: Brute [O(n^2)]                                             |
/*************************************************************************/
std::pair<int,int> solveBrute(std::vector<int> input, const int targetSum)
{
    for (size_t i = 0; i < input.size(); ++i)
        for(size_t j = i; j < input.size(); ++j)
            if(input[i]+input[j] == targetSum)
                return std::pair<int,int>(input[i],input[j]);
    throw std::logic_error("Solution not found");
}

/*************************************************************************/
/* Solution 1: Sort&search second value with divide et impera [O(n log(n))]
/*************************************************************************/
std::pair<int,int> solveOnlogn(std::vector<int> input, const int targetSum)
{
    std::sort(input.begin(), input.end()); // Should be O(n logn)
    for (int firstValue : input)
    {
        size_t secondIdx,leftIdx = 0,rightIdx = input.size();
        while(leftIdx != (rightIdx-1))
        {
            secondIdx = (rightIdx+leftIdx)/2.0;

            if(firstValue + input[secondIdx] == targetSum)
                return std::pair<int,int>(firstValue,input[secondIdx]);
            
            if(firstValue + input[secondIdx] < targetSum)
                leftIdx = secondIdx; 
            else
                rightIdx = secondIdx; 
        }
    }
    throw std::logic_error("Solution not found");
}

int main()
{
    std::vector<int> input;
    Utils::readInput(input);
    std::cout << "Read " << input.size() << " input values\n";

    std::pair<int,int> sol = solveOnlogn(input,2020);
    std::cout << "Solution:\nval_1 = " << sol.first << "\nval_2 = " << sol.second << "\n";
    std::cout << "> Sum = " << (sol.first+sol.second) << "\n> Multiplication = " << (sol.first*sol.second) << "\n";
}
