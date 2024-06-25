#ifndef DIFFICULTY_H
#define DIFFICULTY_H

#include <stdio.h>

int difficulty;  // 定義難度變量
// 定義難度選擇
int selectDifficulty(){
    printf("Select difficulty:\n");
    printf("1. Easy   (10 wrong guesses)\n");
    printf("2. Medium ( 7 wrong guesses)\n");
    printf("3. Hard   ( 5 wrong guesses)\n");
    printf("Enter your choice: ");
    scanf("%d", &difficulty);
    switch (difficulty) {
        case 1:
            return 10;
        case 2:
            return 7;
        case 3:
            return 5;
        default:
            printf("Invalid choice. Setting difficulty to medium.\n");
            return 7;
    }
}

#endif // DIFFICULTY_H
