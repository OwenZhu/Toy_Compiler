//
//  lex_parser.hpp
//  Toy-Compiler
//
//  Created by HanweiZhu on 2018/6/5.
//  Copyright © 2018年 HanweiZhu. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <set>

#include "parser.hpp"
#include "helper.hpp"

// keywords in C
const static std::set<std::string> KEYWORDS = {
    "short", "int", "long", "float", "double", "char",
    "struct", "union", "enum", "typedef", "const", "unsigned",
    "signed", "extern", "static", "void", "if", "else", "switch",
    "case", "for", "do", "while", "goto", "continue", "break",
    "default", "sizeof", "return", "true", "false"};

class LexParser : public Parser
{

public:
    LexParser();
    static std::vector<std::string> tokenize(std::string &);
    static void parse(std::vector<std::string> &);
};
