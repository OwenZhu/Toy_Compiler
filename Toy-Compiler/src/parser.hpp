//
//  parser.hpp
//  Toy-Compiler
//
//  Created by HanweiZhu on 6/1/19.
//  Copyright © 2019 HanweiZhu. All rights reserved.
//

#ifndef parser_hpp
#define parser_hpp

#include <stdio.h>
#include <string>

#endif /* parser_hpp */

class ParserDef
{
public:
    ParserDef() : type_("lex"){};
    ParserDef(std::string type_);

private:
    std::string type_;
};

class Parser
{
public:
    Parser(const ParserDef &parser_def);
    virtual void parse() = 0;
};
