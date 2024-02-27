//
// Created by Mane on 2/9/2024.
//

#ifndef PARSER_HASHMAP_H
#define PARSER_HASHMAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokentype.h"

#define HASHMAP_SIZE 100

typedef struct Entry {
    char *key;
    TokenType value;
    struct Entry *next;
} Entry;

typedef struct HashMap {
    Entry *buckets[HASHMAP_SIZE];
} HashMap;

int hash_function(const char *key);
Entry *create_entry(const char *key, TokenType value);
void hashmap_insert(HashMap *map, const char *key, TokenType value);
TokenType hashmap_get(HashMap *map, const char *key);
TokenType hashmap_get_or_default(HashMap *map, const char *key, TokenType default_value);

#endif //PARSER_HASHMAP_H
