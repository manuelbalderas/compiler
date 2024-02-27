//
// Created by Mane on 2/9/2024.
//

#include "../include/hashmap.h"

int hash_function(const char *key) {
    unsigned long hash = 5381;
    int c;
    while ((c = *key++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % HASHMAP_SIZE;
}

Entry *create_entry(const char *key, TokenType value) {
    Entry *new_entry = (Entry *)malloc(sizeof(Entry));
    if (new_entry == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_entry->key = strdup(key);
    new_entry->value = value;
    new_entry->next = NULL;
    return new_entry;
}

void hashmap_insert(HashMap *map, const char *key, TokenType value) {
    int index = hash_function(key);
    Entry *new_entry = create_entry(key, value);
    new_entry->next = map->buckets[index];
    map->buckets[index] = new_entry;
}

TokenType hashmap_get(HashMap *map, const char *key) {
    int index = hash_function(key);
    Entry *entry = map->buckets[index];
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }
        entry = entry->next;
    }
    return ERROR;
}

TokenType hashmap_get_or_default(HashMap *map, const char *key, TokenType default_value) {
    int index = hash_function(key);
    Entry *entry = map->buckets[index];
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }
        entry = entry->next;
    }
    return default_value;
}
