//
//  main.cpp
//  Toy-Compiler
//
//  Created by HanweiZhu on 2018/6/5.
//  Copyright © 2018年 HanweiZhu. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>

#include "lex_parser.hpp"
#include "helper.cpp"


#define DATA_PATH "../res/sample.cpp"


int main(int argc, const char * argv[]) {

    std::ifstream* infile = nullptr;
    open_file(DATA_PATH, infile);

    std::string raw_text, line;
    while(std::getline(*infile, line)){
        /*
        if(!LexParser::pre_process(line)){
            cerr << "Syntax Error" << endl;
            return 0;
        }
        raw_text += line;
        */
        std::cout << line << std::endl;
    }
    infile->close();
    std::cout << "Read file successfully!" << std::endl;
    
    
    /*
     for(t = &source[0];*t != '\0';t ++)
     {
     s = "";
     for(;*t != ' ';t ++)
     {
     s = s + *t;
     }
     if(*t == ' ')
     analysis(s);
     }
     */
    
    // infile->close();
    return 0;
}
