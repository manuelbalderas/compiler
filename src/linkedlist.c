//
// Created by Mane on 2/12/2024.
//

#include <stdio.h>
#include <stdlib.h>

#include "../include/linkedlist.h"
#include "../include/token.h"
#include "../include/tokentype.h"

struct Node* createNode(void* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** headRef, void* data) {
    struct Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

void insertAtEnd(struct Node** headRef, void* data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(struct Node* head, void (*printFunction)(void*)) {
    struct Node* temp = head;
    while (temp != NULL) {
        printFunction(temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void saveTokensAsJSON(struct Node* list, FILE* file) {
    struct Node* temp = list;
    fprintf(file, "[\n");
    while (temp != NULL) {
        Token* token = (Token*)temp->data;
        fprintf(file, "\t{\n");
        fprintf(file, "\t\t\"ID\": %d,\n", token->type);
        fprintf(file, "\t\t\"Type\": \"%s\",\n", tokenTypeToString(token->type));
        fprintf(file, "\t\t\"Lexeme\": \"%s\"\n", token->lexeme);
        fprintf(file, "\t}");
        if (temp->next) {
            fprintf(file, ",");
        }
        fprintf(file, "\n");
        temp = temp->next;
    }
    fprintf(file, "]\n");
}

void printInt(void* data) {
    printf("%d", *(int*)data);
}

void printString(void* data) {
    printf("%s", (char*)data);
}

void printToken(void* data){
    Token* token = (Token*)data;
    printf("ID: %d, Type: %s, Lexeme: %s\n", token->type, tokenTypeToString(token->type), token->lexeme);
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        freeToken(temp->data);
        free(temp);
    }
}