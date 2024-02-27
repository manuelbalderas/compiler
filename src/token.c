//
// Created by Mane on 2/12/2024.
//

#include "../include/token.h"

Token* createToken(TokenType type, const char* lexeme) {
    Token* newToken = (Token*)malloc(sizeof(Token));
    if (newToken == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newToken->type = type;
    newToken->lexeme = strdup(lexeme);
    if (newToken->lexeme == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return newToken;
}

void freeToken(Token* token) {
    free(token->lexeme);
    free(token);
}