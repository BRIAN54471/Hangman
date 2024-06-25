#ifndef TOPIC_H
#define TOPIC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROWS 30
#define MAX_COLS 5
#define MAX_LINE_LENGTH 100


// Function to choose the topic of the words
int selectTopic() {
    int topic;  // Define the topic choice
    printf("Select topic:\n");
    printf("1. Animal\n");    
    printf("2. Fruits\n");
    printf("3. Countries\n");
    printf("4. Professions\n");
    printf("5. Sports\n");
    printf("Enter your choice: ");
    scanf("%d", &topic);
    return topic;
}


void read_hangman_csv(const char *file_path, char data[MAX_ROWS][MAX_COLS][MAX_LINE_LENGTH]) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int row = 0;

    while (fgets(line, sizeof(line), file) && row < MAX_ROWS) {
        char *token;
        int col = 0;

        // Use strtok to split the line by commas
        token = strtok(line, ",");
        while (token != NULL && col < MAX_COLS) {
            strncpy(data[row][col], token, MAX_LINE_LENGTH);
            token = strtok(NULL, ",");
            col++;
        }
        row++;
    }

    fclose(file);
}


char* words[MAX_ROWS];

void initializeWords(char data[MAX_ROWS][MAX_COLS][MAX_LINE_LENGTH], int topic) {
    int numWords = 0;
    for (int i = 0; i < MAX_ROWS; i++) {
        if (strcmp(data[i][0], "") != 0 && atoi(data[i][1]) == topic) {
            words[numWords] = data[i][2];
            numWords++;
        }
    }
}
char* chooseRandomWord(char* words[], int numWords) {
    return words[rand() % numWords];  // 從單詞列表中隨機選擇一個單詞並返回
}


#endif // TOPIC_H
