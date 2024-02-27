//
// Created by Mane on 2/18/2024.
//

#include "../include/tokentype.h"

const char* tokenTypeToString(TokenType type) {
    switch (type) {
        case IDENTIFIER: return "IDENTIFIER";
        case INT: return "INT";
        case FLOAT: return "FLOAT";
        case STRING: return "STRING";
        case DATATYPE: return "DATATYPE";
        case ASSIGN: return "ASSIGN";
        case ADD: return "ADD";
        case MULTIPLY: return "MULTIPLY";
        case RELATIONAL: return "RELATIONAL";
        case OR: return "OR";
        case AND: return "AND";
        case NOT: return "NOT";
        case EQUALS: return "EQUALS";
        case SEMICOLON: return "SEMICOLON";
        case COMMA: return "COMMA";
        case LEFT_PAREN: return "LEFT_PAREN";
        case RIGHT_PAREN: return "RIGHT_PAREN";
        case LEFT_BRACK: return "LEFT_BRACK";
        case RIGHT_BRACK: return "RIGHT_BRACK";
        case IF: return "IF";
        case WHILE: return "WHILE";
        case RETURN: return "RETURN";
        case ELSE: return "ELSE";
        case EOL: return "EOF";
        case ERROR: return "ERROR";
    }
}
