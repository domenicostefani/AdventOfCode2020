#pragma once

#include <fstream>
#include <string>
#include <vector>

namespace Utils
{
/** Read input file and fill int vector*/
void readInput(std::vector<int>& outvec)
{
    std::ifstream inputFile ("input.txt");
    
    if (!inputFile.is_open())
        throw std::logic_error("Unable to open file"); 
    
    std::string line;
    while ( getline (inputFile,line) )
        outvec.push_back(std::stoi(line));
    inputFile.close();
}

} // namespace Utils
