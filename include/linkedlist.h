//
// Created by Mane on 2/12/2024.
//

#ifndef PARSER_LINKEDLIST_H
#define PARSER_LINKEDLIST_H

#include "tokentype.h"

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

struct Node* createNode(void* data);
void insertAtBeginning(struct Node** headRef, void* data);
void insertAtEnd(struct Node** headRef, void* data);
void printList(struct Node* head, void (*printFunction)(void*));
void saveTokensAsJSON(struct Node* head, FILE* file);
void printInt(void* data);
void printString(void* data);
void printToken(void* data);
void freeList(struct Node* head);

#endif //PARSER_LINKEDLIST_H
