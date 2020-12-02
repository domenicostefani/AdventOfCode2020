#include "utils.h"

#include <iostream>
#include <tuple>

int main()
{
    std::vector<Utils::Entry> res;
    Utils::readInput(res);
    std::cout << "Read " << res.size() << " values \n";
    
    size_t correct = 0, wrong = 0;
    for(auto entry : res)
    {
        if (!(entry.str[entry.min-1] == entry.character) != !(entry.str[entry.max-1] == entry.character)) // Logic xor :  A XOR B  : !A != !B
            correct++;
        else
            wrong++;
    }

    std::cout << correct << " are correct \n";
    std::cout << wrong << " are wrong \n";
}