//
// Created by Mane on 2/12/2024.
//

#ifndef PARSER_TOKEN_H
#define PARSER_TOKEN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tokentype.h"

typedef struct Token {
    TokenType type;
    char* lexeme;
} Token;


Token* createToken(TokenType type, const char* lexeme);
void freeToken(Token* token);

#endif //PARSER_TOKEN_H
