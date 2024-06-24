#ifndef MYHEAD_H
#define MYHEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 打印單詞狀態的函數
void printWordStatus(const char* word, const int* revealed) {
    for (int i = 0; word[i] != '\0'; i++) {  // 遍歷單詞的每個字母
        printf("%c ", revealed[i] ? word[i] : '_');  // 如果字母已揭示，打印字母，否則打印底線
    }
    printf("\n");  // 揭示狀態後換行
}

// 從單詞列表中隨機選擇一個單詞的函數
char* chooseRandomWord(char* words[], int numWords) {
    return words[rand() % numWords];  // 從單詞列表中隨機選擇一個單詞並返回
}

// 初始化遊戲狀態的函數
void initializeGame(char** chosenWord, int* wordLength, int revealed[], int* wrongGuesses) {
    char* words[] = {"programming", "hangman", "computer", "software", "hardware"};  // 定義單詞列表
    int numWords = sizeof(words) / sizeof(words[0]);  // 計算單詞數量
    *chosenWord = chooseRandomWord(words, numWords);  // 隨機選擇新單詞
    *wordLength = strlen(*chosenWord);  // 獲取單詞長度
    memset(revealed, 0, 50 * sizeof(int));  // 初始化揭示狀態數組，假設單詞長度不超過50
    *wrongGuesses = 0;  // 初始化錯誤猜測計數器
    srand(time(NULL));  // 使用當前時間初始化隨機數生成器
}

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

#define MAX_LINE_LENGTH 1024
#define MAX_CELL_LENGTH 256
#define MAX_COLUMNS 5

void read_hangman_csv(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        perror("打開檔案時發生錯誤");
        return;
    }

    char line[MAX_LINE_LENGTH];
    char themes[MAX_COLUMNS][MAX_CELL_LENGTH] = {0};
    int line_count = 0;

    // 讀取檔案第一行作為主題
    if (fgets(line, sizeof(line), file)) {
        char *token;
        int column = 0;

        token = strtok(line, ",");
        while (token != NULL && column < MAX_COLUMNS) {
            strncpy(themes[column], token, MAX_CELL_LENGTH);
            themes[column][strcspn(themes[column], "\n")] = '\0'; // 去除換行符
            column++;
        }
    }

    // 打印主題
    for (int i = 0; i < MAX_COLUMNS; i++) {
        printf("%s\t", themes[i]);
    }
    printf("\n");

    // 讀取並打印檔案剩餘內容
    while (fgets(line, sizeof(line), file)) {
        char *token;
        int column = 0;

        token = strtok(line, ",");
        while (token != NULL && column < MAX_COLUMNS) {
            printf("%s\t", token);
            token = strtok(NULL, ",");
            column++;
        }
        printf("\n");
    }

    fclose(file);
}

// 定義難度選擇
int selectDifficulty() {
    int difficulty;  // 定義難度選擇
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

// 遊戲規則的函數
void gameRule(const char* chosenWord, int wordLength, int revealed[], int* wrongGuesses, int difficulty) {
    int maxWrongGuesses = difficulty;  // 設置最大錯誤猜測次數
    while (*wrongGuesses < maxWrongGuesses) {  // 當錯誤猜測次數少於最大次數時
        printWordStatus(chosenWord, revealed);  // 打印當前單詞狀態
        printf("Guess a letter: ");  // 提示用戶猜一個字母
        char guess;  // 定義變量以存儲用戶的猜測
        scanf(" %c", &guess);  // 從用戶那裡讀取一個字母，注意前面的空格以忽略前面的換行符

        int correct = 0;  // 初始化變量以記錄猜測是否正確
        for (int i = 0; i < wordLength; i++) {  // 遍歷單詞的每個字母
            if (!revealed[i] && chosenWord[i] == guess) {  // 如果該字母未揭示且與猜測的字母匹配
                revealed[i] = 1;  // 設置為揭示狀態
                correct = 1;  // 標記猜測正確
            }
        }

        if (!correct) {  // 如果猜測不正確
            (*wrongGuesses)++;  // 增加錯誤猜測次數
            printf("Wrong! You have %d more guesses.\n", maxWrongGuesses - *wrongGuesses);  // 提示剩餘的猜測次數
        }

        int won = 1;  // 初始化變量以記錄是否已經猜出整個單詞
        for (int i = 0; i < wordLength; i++) {  // 遍歷單詞的每個字母
            if (!revealed[i]) {  // 如果有字母未揭示
                won = 0;  // 標記尚未完全猜出
                break;  // 跳出循環
            }
        }

        if (won) {  // 如果已經猜出整個單詞
            printf("Congratulations! You've guessed the word: %s\n", chosenWord);  // 恭喜訊息
            break;  // 跳出循環
        }
    }

    if (*wrongGuesses >= maxWrongGuesses) {  // 如果錯誤猜測次數達到最大次數
        printf("You've lost! The correct word was: %s\n", chosenWord);  // 顯示失敗訊息和正確單詞
    }
}


#endif // MYHEAD_H
