#pragma once

#include <vector>
#include <string>
#include <fstream>

class Helper{
public:
    static void OpenFile(std::string const file_name, std::ifstream*& infile);
    static std::vector<std::string> split(std::string s, char delim);
    static void trim(std::string& str);
};
