//
// Created by Mane on 2/13/2024.
//

#include "../include/lexer.h"

HashMap keywords;

static void initLexer(Lexer *lexer, const char *input) {
    lexer->input = input;
    lexer->current = input;
}

static void skipWhitespaces(Lexer *lexer) {
    while (isspace(*(lexer->current))) {
        lexer->current++;
    }
}

Token *nextToken(Lexer *lexer) {
    skipWhitespaces(lexer);

    const char *start = lexer->current;
    TokenType type = ERROR;

    char c = *(lexer->current);

    switch (c) {
        case '\0': return NULL;
        case '$': type = EOL; lexer->current++; break;
        case '=': type = ASSIGN; lexer->current++; if (*lexer->current == '=') { type = EQUALS; lexer->current++; } break;
        case '!': lexer->current++; if (*lexer->current == '=') { type = NOT; lexer->current++; } break;
        case '<':
        case '>':
            type = RELATIONAL;
            lexer->current++;
            if (*lexer->current == '=') {
                lexer->current++;
            }
            break;
        case '|':
            lexer->current++;
            if (*lexer->current == '|') {
                type = OR;
                lexer->current++;
            }
            break;
        case '&':
            lexer->current++;
            if (*lexer->current == '&') {
                type = AND;
                lexer->current++;
            }
            break;
        case '(': type = LEFT_PAREN; lexer->current++; break;
        case ')': type = RIGHT_PAREN; lexer->current++; break;
        case '{': type = LEFT_BRACK; lexer->current++; break;
        case '}': type = RIGHT_BRACK; lexer->current++; break;
        case ',': type = COMMA; lexer->current++; break;
        case ';': type = SEMICOLON; lexer->current++; break;
        case '*':
        case '/':
            type = MULTIPLY;
            lexer->current++;
            break;
        case '+':
        case '-':
            type = ADD;
            lexer->current++;
            break;
        case '"':
            lexer->current++;
            while ((*lexer->current >= 32 && *lexer->current <= 126) && *lexer->current != '\n' && *lexer->current != '"') {
                lexer->current++;
            }
            if (*lexer->current == '"') {
                type = STRING;
                lexer->current++;
            }
            break;
        case '.':
            lexer->current++;
            if (isdigit(*lexer->current)) {
                type = FLOAT;
                while (isdigit(*lexer->current)) {
                    lexer->current++;
                }
            }
            break;
        default:
            if (isdigit(c)) {
                type = INT;
                while (isdigit(*lexer->current)) {
                    lexer->current++;
                }
                if (*lexer->current == '.') {
                    type = ERROR;
                    lexer->current++;
                    if (isdigit(*lexer->current)) {
                        type = FLOAT;
                        lexer->current++;
                    }
                    while (isdigit(*lexer->current)) {
                        lexer->current++;
                    }
                }
            }
            else if (isalpha(c) || c == '_') {
                type = IDENTIFIER;
                lexer->current++;
                while (isalpha(*lexer->current) || *lexer->current == '_') {
                    lexer->current++;
                }
            }
            else {
                lexer->current++;
            }
    }

    int lexemeLength = lexer->current - start;
    char *lexeme = (char *)malloc((lexemeLength + 1) * sizeof(char));
    strncpy(lexeme, start, lexemeLength);
    lexeme[lexemeLength] = '\0';
    type = hashmap_get_or_default(&keywords, lexeme, type);

    return createToken(type, lexeme);
}

void initialize_keywords() {
    hashmap_insert(&keywords, "if", IF);
    hashmap_insert(&keywords, "while", WHILE);
    hashmap_insert(&keywords, "return", RETURN);
    hashmap_insert(&keywords, "else", ELSE);
    hashmap_insert(&keywords, "int", DATATYPE);
    hashmap_insert(&keywords, "float", DATATYPE);
    hashmap_insert(&keywords, "char", DATATYPE);
    hashmap_insert(&keywords, "void", DATATYPE);
}

struct Node* tokenization(char* input) {
    Lexer lexer;
    initLexer(&lexer, input);
    Node *tokens = NULL;
    Token *currentToken = NULL;

    while ((currentToken = nextToken(&lexer)) != NULL) {
        insertAtEnd(&tokens, currentToken);
    }

    return tokens;
}