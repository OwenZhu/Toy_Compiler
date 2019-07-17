//
//  lex_parser.cpp
//  Toy-Compiler
//
//  Created by HanweiZhu on 2018/6/5.
//  Copyright © 2018年 HanweiZhu. All rights reserved.
//

#include <algorithm>
#include <iterator>
#include "lex_parser.hpp"
#include "helper.hpp"

std::vector<std::string> LexParser::tokenize(std::string line)
{
    std::replace(std::begin(line), std::end(line), '\t', ' ');
    Helper::trim(line);

    std::vector<std::string> str_vector;
    str_vector = Helper::split(line, ' ');
    for (auto token = str_vector.begin(); token != str_vector.end(); token++)
    {
        Helper::trim(*token);
    }
    return str_vector;
}

TOKEN_TYPE LexParser::check_token_type(std::string str)
{
    TOKEN_TYPE type;
    if (KEYWORD_LIST.find(str) != KEYWORD_LIST.end())
        type = KEYWORD;
    else if (str == "//")
        type = COMMENT;
    else
        type = OPERATION;
    return type;
}

void LexParser::parse(std::vector<std::string> &str_vector)
{
    for (auto const &str : str_vector)
    {
        TOKEN_TYPE type = check_token_type(str);
        switch (type)
        {
        case KEYWORD:
            std::cout << "[KEYWORD " << *KEYWORD_LIST.find(str) << "]";
            break;
        case COMMENT:
            for (; str != *str_vector.end();)
            {
                str_vector.pop_back();
            }
            break;
        default:
            std::cout << "[OPERATION " + str + "]";
            break;
        }
    }
    std::cout << std::endl;
    /*
    char *t,*it;
    string s;
    for(t = &str[0];*t != '\0';t ++)
    {
        s = "";
        if(*t == '*')
        {
            it = t + 1;
            if(*it == '*')
            {
                t = t + 1;
                cout<<"** Operator --> ";
            }
            else if(*it == '=')
                cout<<"*= Operator --> ";
            else
                cout<<" Operator --> ";
        }
        if(*t == '=')
        {
            it = t + 1;
            if(*it == '=')
            {
                t = t + 1;
                cout<<"== Operator --> ";
            }
            else
                cout<<"= Operator --> ";
        }
        else if(*t == '+')
        {
            it = t + 1;
            if(*it == '+' || *it == '=')
                t = t + 1;
            cout<<"Operator --> ";
        }
        else if(*t == '-')
        {
            it = t + 1;
            if(*it == '-' || *it == '=')
                t = t + 1;
            cout<<"Operator --> ";
        }
        else if(*t == '&')
        {
            it = t + 1;
            if(*it == '&')
            {
                t = t + 1;
                cout<<"&& "<<"Operator --> ";
            }
            else
                cout<<"& "<<"Operator --> ";
        }
        else if(*t == '#' || *t == ',' || *t == '%' || *t == '(' || *t == ')' || *t == '{' || *t == '}' || *t == '<' || *t == '>')
        {
            it = t + 1;
            if(*it == '<' || *it == '>')
            {
                cout<<*it<<*it<<" Operator --> ";
                t++;
            }
            else
                cout<<*t<<" Operator --> ";
        }
        else if((*t >='a' && *t <='z')||(*t >='A' && *t <='Z' ))
        {
            for(it = t;(*it >= 'a' && *it <= 'z') ||(*t >='A' && *t <='Z' ) || (*it >= '0' && *it <= '9');it ++)
            {
                s = s + *it;
                cout<<*it;
            }
            cout<<" ";
            if(s == "include" || s == "using" || s == "namespace" || s == "int" || s == "void" || s == "char"  || s == "return")
                cout<<"Reverse --> ";
            else
                cout<<"Identifer --> ";
            t = it - 1;
        }
        else if(*t >='0' && *t <='9')
        {
            for(it = t;*it >= '0' && *it <= '9';it ++)
            {
                s = s + *it;
                cout<<*it;
            }
            cout<<" ";
            if((*it >='a' && *it <='z')||(*it >='A' && *it <='Z' ) || (*it >= 'a' && *it <= 'z') ||(*it >='A' && *it <='Z' ))
                cout<<"Error -->";
            else
                cout<<"Constant --> ";
            t = it - 1;
        }
        else if(*t == "\"")
        {
            for(it = t + 1;*it != 34;it ++)
            {
                s = s + *it;
                cout<<*it;
            }
            cout<<" string --> ";
            t = it;
        }
        else if(*t == '\'')
        {
            for(it = t + 1;*it != 39;it ++)
            {
                s = s + *it;
                cout<<*it;
            }
            cout<<" char --> ";
            t = it;
        }
        else if(*t == ';')
            cout<<"; Operator"<<endl;
        else
            cout<<"Error --> ";
    }
     */
}
