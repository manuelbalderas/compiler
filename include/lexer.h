//
// Created by Mane on 2/13/2024.
//

#ifndef PARSER_LEXER_H
#define PARSER_LEXER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "hashmap.h"
#include "linkedlist.h"
#include "token.h"
#include "tokentype.h"

typedef struct Lexer {
    const char *input;
    const char *current;
} Lexer;

static void initLexer(Lexer *lexer, const char *input);
static void skipWhitespaces(Lexer *lexer);
Token *nextToken(Lexer *lexer);

void initialize_keywords();
struct Node* tokenization(char* text);

#endif //PARSER_LEXER_H