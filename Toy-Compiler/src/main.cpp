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

using namespace std;

int main(int argc, const char * argv[]) {

    ifstream* infile = 0;
    open_source_file("../source_file.txt", infile);

    string raw_text, line;

    while(getline(*infile, line)){
        /*
        if(!LexParser::pre_process(line)){
            cerr << "Syntax Error" << endl;
            return 0;
        }
        raw_text += line;
        */
        cout << line << endl;

    }
    
    cout << "Read file successfully!" << endl;
    
    
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
