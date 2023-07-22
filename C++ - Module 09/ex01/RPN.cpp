#include "RPN.hpp"

const char * ExprError::what() const throw() {
    return "Expression Error";
}

Token::Token(int type, int value) : type(type), value(value) {};

Token makeToken(std::string &stok) {
    if (stok == "+")
        return Token(PLUS);
    if (stok == "-")
        return Token(MINUS);
    if (stok == "*")
        return Token(MULT);
    if (stok == "/")
        return Token(DIV);
    
    size_t idx;
    int val;

    try {
        val = std::stoi(stok, &idx);
    } catch (std::exception &e) {
        // ignore stoi error
        idx = ULLONG_MAX, val = 0;
    }

    if (idx != stok.size() || abs(val) > 10)
        return Token(UNK);
    
    return Token(NBR, val);
}

int calc(char *expression) {
    std::stringstream expr(expression);
    std::string stok;
    std::stack<int> stak;

    while (expr >> stok) {
        Token tok = makeToken(stok);

        if (tok.type & UNK)
            throw ExprError();

        if (tok.type & NBR)
            stak.push(tok.value);
        
        else {

            // operator needs two values
            if (stak.size() < 2)
                throw ExprError();

            // get left and right            
            int r = stak.top(); stak.pop();
            int l = stak.top(); stak.pop();

            // cannot divide by zero
            if ((tok.type & DIV) && r == 0)
                throw ExprError();
            
            // handle operations
            stak.push(
                tok.type & PLUS? l + r:
                tok.type & MINUS? l - r:
                tok.type & MULT? l * r:
                l / r
            );
        }
    }

    // stak needs to contain final result only
    if (stak.size() != 1)
        throw ExprError();
    
    return stak.top();
}