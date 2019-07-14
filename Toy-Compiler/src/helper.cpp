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

using namespace std;

void open_source_file(string const file_name, ifstream& infile){
    ifstream infile(file_name);
    if (!infile){
        cerr << "Cannot open " << file_name << endl;
    }
    //return infile;
}
