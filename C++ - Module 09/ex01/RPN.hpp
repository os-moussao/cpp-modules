#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stack>
#include <exception>

class ExprError: public std::exception {
    public:
        virtual const char *what() const throw();
};

enum Type {
    UNK = 1,
    NBR = (1 << 1),
    PLUS = (1 << 2),
    MINUS = (1 << 3),
    MULT = (1 << 4),
    DIV = (1 << 5),
};

struct Token {
    int type;
    int value;
    Token(int type, int value = 0);
};

int calc(char *expr);