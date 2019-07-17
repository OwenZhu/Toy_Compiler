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

enum TOKEN_TYPE
{
    KEYWORD,
    OPERATION,
    COMMENT
};

// keywords in C
const static std::set<std::string> KEYWORD_LIST = {
    "short", "int", "long", "float", "double", "char",
    "struct", "union", "enum", "typedef", "const", "unsigned",
    "signed", "extern", "static", "void", "if", "else", "switch",
    "case", "for", "do", "while", "goto", "continue", "break",
    "default", "sizeof", "return", "true", "false"};

class LexParser : public Parser
{
private:
    static TOKEN_TYPE check_token_type(std::string);

public:
    LexParser();
    static std::vector<std::string> tokenize(const std::string);
    static void parse(std::vector<std::string> &);
};
