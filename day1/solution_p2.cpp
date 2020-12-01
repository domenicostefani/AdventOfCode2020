#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#include "utils.h"

/************************************************************************/
/* Complexity should be O(n^2 log(n)):                                  */
/* Sort:   O(n log(n))                                                  */
/* Search: O(n * n * log(n))                                            */
/************************************************************************/
std::tuple<int,int,int> solve(std::vector<int> input, const int targetSum)
{
    std::sort(input.begin(),input.end());

    for (int i = 0; i < input.size(); ++i)
    {
        for (int j = i; j < input.size(); ++j)
        {
            int val1 = input[i], val2 = input[j];

            size_t idx3,left = 0,right = input.size();
            while (left != (right-1))
            {
                idx3 = (left+right)/2.0;
                if(val1+val2+input[idx3] == targetSum)
                    return std::make_tuple(val1,val2,input[idx3]);
                if(val1+val2+input[idx3] < targetSum)
                    left = idx3;
                else
                    right = idx3;
            }
        }
    }
    throw std::logic_error("Solution not found");
}

int main()
{
    std::vector<int> input;
    Utils::readInput(input);
    std::cout << "Read " << input.size() << " input values\n";

    std::tuple<int,int,int> sol = solve(input,2020);
    std::cout << "Brute solution:\nval_1 = " << std::get<0>(sol) << "\nval_2 = " << std::get<1>(sol) << "\nval_3 = " << std::get<2>(sol) << "\n";
    std::cout << "> Sum = " << (std::get<0>(sol) + std::get<1>(sol) + std::get<2>(sol)) \
                << "\n> Multiplication = " << (std::get<0>(sol) * std::get<1>(sol) * std::get<2>(sol)) << "\n";
}
