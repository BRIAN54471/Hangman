#ifndef DIFFICULTY_H
#define DIFFICULTY_H

#include <stdio.h>

int difficulty;  // 定義難度變量
// 定義難度選擇
int selectDifficulty(){
    int maxWrongGuesses;  // 定義最多錯誤猜測次數
    printf("Select difficulty:\n");
    printf("1. Easy   (10 wrong guesses)\n");
    printf("2. Medium ( 7 wrong guesses)\n");
    printf("3. Hard   ( 5 wrong guesses)\n");
    printf("Enter your choice: ");
    scanf("%d", &difficulty);
    printf("--------------------------------\n");
    printf("\n");
    printf("\033[0;34m");
    switch (difficulty) {
        case 1:
            printf("You have selected Easy\n");
            maxWrongGuesses = 10;
            break;
        case 2:
            printf("You have selected Medium\n");
            maxWrongGuesses = 7;
            break;
        case 3:
            printf("You have selected Hard\n");
            maxWrongGuesses = 5;
            break;
        default:
            printf("Invalid choice. Setting difficulty to medium.\n");
            break;
    }
    printf("\033[0m");// Reset text color
    printf("\n");
    return maxWrongGuesses;
}

#endif // DIFFICULTY_H
