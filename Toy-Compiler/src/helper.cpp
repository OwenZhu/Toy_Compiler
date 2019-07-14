//
//  helper.cpp
//  Toy-Compiler
//
//  Created by HanweiZhu on 6/1/19.
//  Copyright © 2019 HanweiZhu. All rights reserved.
//

#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>


void open_file(std::string const file_name, std::ifstream*& infile){
    infile = new std::ifstream;
    infile->open(file_name);
    if (!infile){
        std::cerr << "Cannot open " << file_name << std::endl;
    }
}


std::vector<std::string> split(std::string s, char delim){
    
    std::stringstream ss(s);
    std::string item;
    std::vector<std::string> tokens;
    while (std::getline(ss, item, delim)) {
        if(item != ""){
            tokens.push_back(item);
        }
    }
    return tokens;
}


void trim(std::string& str){
    size_t first = str.find_first_not_of(" \n\r\t");
    size_t last = str.find_last_not_of(" \n\r\t;");
    str = str.substr(first, (last-first + 1));
}
