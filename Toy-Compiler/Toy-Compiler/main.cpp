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

using namespace std;

int main(int argc, const char * argv[]) {

    string file_name = "source_file.txt";
    ifstream fin;
    
    fin.open(file_name, ios::in);
    if (!fin.is_open()){
        cerr << "Cannot open " << file_name << endl;
        return 0;
    }
    
    string raw_text, line;
    while(getline(fin, line))
    {
        LexParser::trim(line);
        LexParser::pre_process(line);
        cout << line << endl;
        raw_text += line;
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
    
    fin.close();
    system("pause");
    return 0;
}
