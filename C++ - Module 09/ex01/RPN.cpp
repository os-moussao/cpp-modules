#include "RPN.hpp"

const char * ExprError::what() const throw() {
    return "Expression Error";
}

Token::Token(int type, int value) : type(type), value(value) {};

Token makeToken(char stok) {
    switch (stok) {
        case '+':
            return Token(PLUS);
        case '-':
            return Token(MINUS);
        case '*':
            return Token(MULT);
        case '/':
            return Token(DIV);
        default:
            return isdigit(stok) ? Token(NBR, stok - '0') : Token(UNK);
    }
}

int calc(char *expression) {
    std::stringstream expr(expression);
    std::stack<int> stak;
    char stok;

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