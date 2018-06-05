//
//  lex_parser.hpp
//  Toy-Compiler
//
//  Created by HanweiZhu on 2018/6/5.
//  Copyright © 2018年 HanweiZhu. All rights reserved.
//

#ifndef lex_parser_hpp
#define lex_parser_hpp

#include <stdio.h>
#include <string>

#endif /* lex_parser_hpp */

class LexParser{
    
public:
    static void trim(std::string& s);
    static void pre_process(std::string& s);
    static void parse(std::string& str);
};
