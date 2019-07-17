#pragma once

#include <vector>
#include <string>
#include <fstream>

class Helper
{
public:
    static void OpenFile(std::string const, std::ifstream *&);
    static std::vector<std::string> split(std::string, char);
    static void trim(std::string &);
};
