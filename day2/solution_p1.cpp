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
        int count = 0;
        for(char c : entry.str)
            if ( c == entry.character )
                count++;
        // std::cout << "ch: " << entry.str << "\n";
        if ((count >= entry.min) && (count <= entry.max))
            correct++;
        else
            wrong++;
    }

    std::cout << correct << " are correct \n";
    std::cout << wrong << " are wrong \n";
}