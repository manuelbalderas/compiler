//
// Created by Mane on 2/9/2024.
//

#include <stdio.h>
#include <string.h>
#include <time.h>

#include "./include/lexer.h"

#define MAX_FILENAME_LENGTH 100

char* generate_filename() {
    char* filename = (char*)malloc(MAX_FILENAME_LENGTH * sizeof(char));
    if (filename == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    time_t current_time;
    struct tm *timeinfo;
    time(&current_time);
    timeinfo = localtime(&current_time);

    strftime(filename, MAX_FILENAME_LENGTH, "./Tokens/file_%Y%m%d_%H%M%S.json", timeinfo);

    return filename;
}

char* readFileContent(const char *filename) {
    FILE *file;
    char *content = NULL;
    char ch;
    int length = 0;

    file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "Unable to open the file\n");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    length = ftell(file);
    rewind(file);

    content = (char*)malloc((length + 1) * sizeof(char));

    int i = 0;
    while ((ch = fgetc(file)) != EOF) {
        content[i++] = ch;
    }
    content[i] = '\0';

    fclose(file);

    return content;
}

int main() {
    const char *inputFilename = "../input.txt";
    const char *outputFilename = generate_filename();

    FILE* outputFile = NULL;

    char *input = readFileContent(inputFilename);

    initialize_keywords();

    struct Node* tokens = tokenization(strcat(input, "$"));

    printf("Input:\n%s\n", input);
    printList(tokens, printToken);

    outputFile = fopen(outputFilename, "w");
    saveTokensAsJSON(tokens, outputFile);

    fclose(outputFile);
    freeList(tokens);
    free(input);

    return 0;
}