//
// Created by Mane on 2/9/2024.
//

#ifndef PARSER_TOKENTYPE_H
#define PARSER_TOKENTYPE_H

typedef enum TokenType {
    // Identifier
    IDENTIFIER = 0,
    // Datatype
    CONSTANT = 1, INT = 1, FLOAT = 2, STRING = 3, DATATYPE = 4,
    // Operators
    ASSIGN = 18, ADD = 5, MULTIPLY = 6, RELATIONAL = 7,
    // Logical Operators
    OR = 8, AND = 9, NOT = 10, EQUALS = 11,
    // Delimeters
    SEMICOLON = 12, COMMA = 13, LEFT_PAREN = 14, RIGHT_PAREN = 15, LEFT_BRACK = 16, RIGHT_BRACK = 17,
    // Keywords
    IF = 19, WHILE = 20, RETURN = 21, ELSE = 22,
    // EOF
    EOL = 23,
    // Error
    ERROR = -1,
} TokenType;

const char* tokenTypeToString(TokenType type);

#endif //PARSER_TOKENTYPE_H
