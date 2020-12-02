#pragma once

#include <fstream>
#include <cstring>
#include <string>
#include <vector>

namespace Utils
{

struct Entry
{
    int min,max;
    char character;
    std::string str;

    Entry(int min, int max, char character, std::string str)
    {
        this->min = min;
        this->max = max;
        this->character = character;
        this->str = str;
    }
};

std::pair<int,int> getMinMax(std::string mmstring)
{
    int min,max;

    char str[100]; 
    strcpy(str,mmstring.c_str());
    char *token; 
    char *rest = str; 

    std::string tmp = "";
    token = strtok_r(rest, "-", &rest);
    tmp = token;
    min = std::stoi(tmp);

    token = strtok_r(rest, "-", &rest);
    tmp = token;
    max = std::stoi(tmp);

    return std::pair<int,int> (min,max);
}

/** Read input file and fill int vector*/
void readInput(std::vector<Entry>& outvec)
{
    std::ifstream inputFile ("input.txt");
    
    if (!inputFile.is_open())
        throw std::logic_error("Unable to open file"); 
    
    std::string minmax,  val, pswd;
    while ( inputFile >> minmax >> val >> pswd)
    {
        std::pair<int,int> minmax_i = getMinMax(minmax);
        char val_c = val.at(0);

        outvec.emplace_back(minmax_i.first,minmax_i.second,val_c,pswd);
    }
    inputFile.close();
}

} // namespace Utils
