#ifndef MYHEAD_H
#define MYHEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define MAX_WORD_LENGTH 100
#define MAX_WORDS 30

int readvocabularyCSV(const char* filename, char* vocabulary[], int* numWords) {
    FILE* file = fopen(filename, "r"); // Open file in read mode
    if (file == NULL) {
        printf("Error: File not found\n");
        return 0;
    }

    char buffer[MAX_WORD_LENGTH];
    int wordCount = 0;

    // Skip the header line
    fgets(buffer, MAX_WORD_LENGTH, file);

    // Read each word
    while (fgets(buffer, MAX_WORD_LENGTH, file) && wordCount < MAX_WORDS) {
        // Remove the newline character
        buffer[strcspn(buffer, "\n")] = '\0';
        
        // Allocate memory for the word
        vocabulary[wordCount] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        if (vocabulary[wordCount] == NULL) {
            printf("Error: Memory allocation failed\n");
            fclose(file);
            return 0;
        }
        
        // Copy the word to the vocabulary array
        strcpy(vocabulary[wordCount], buffer);
        wordCount++;
    }

    fclose(file);
    *numWords = wordCount;
    return 1;
}

int Filereading() {
    const char* filename = "hangman_words.csv";
    char* vocabulary[MAX_WORDS];
    int numWords;

    if (readvocabularyCSV(filename, vocabulary, &numWords)) {
        printf("Words read from file:\n");
        for (int i = 0; i < numWords; i++) {
            printf("%s\n", vocabulary[i]);
            free(vocabulary[i]); // Free the allocated memory for each word
        }
    } else {
        printf("Failed to read words from file\n");
    }

    return 0;
}

#endif // MYHEAD_H