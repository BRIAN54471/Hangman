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

void initialzeGame(char* chosenWord, int wordLength, int revealed[], int wrongGuesses, const int maxWrongGuesses) {
    char* words[] = {"programming", "hangman", "computer", "software", "hardware"};  // 定義單詞列表
    int numWords = sizeof(words) / sizeof(words[0]);  // 計算單詞數量
    chosenWord = chooseRandomWord(words, numWords);  // 隨機選擇新單詞
    wordLength = strlen(chosenWord);  // 獲取單詞長度
    revealed[50] = {0};  // 初始化揭示狀態數組，假設單詞長度不超過50
    wrongGuesses = 0;  // 初始化錯誤猜測計數器
    int numWords = sizeof(words) / sizeof(words[0]);  // 計算單詞數量
    srand(time(NULL));  // 使用當前時間初始化隨機數生成器
}

int main() {
    char playAgain;  // 定義變量以存儲用戶是否再玩一局的選擇
    initialzeGame(chosenWord, wordLength, revealed, wrongGuesses, maxWrongGuesses);
    do {
        const int maxWrongGuesses = 7;  // 定義最多錯誤猜測次數
        printf("Welcome to Hangman!\n");  // 歡迎訊息

        while (wrongGuesses < maxWrongGuesses) {  // 當錯誤猜測次數少於最大次數時
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
                wrongGuesses++;  // 增加錯誤猜測次數
                printf("Wrong! You have %d more guesses.\n", maxWrongGuesses - wrongGuesses);  // 提示剩餘的猜測次數
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

        if (wrongGuesses >= maxWrongGuesses) {  // 如果錯誤猜測次數達到最大次數
            printf("You've lost! The correct word was: %s\n", chosenWord);  // 顯示失敗訊息和正確單詞
        }

        printf("Type 'y' to play again, or any other key to quit: ");  // 提示用戶選擇是否再玩一局
        scanf(" %c", &playAgain);  // 讀取用戶選擇
        memset(revealed, 0, sizeof(revealed));  // 重置揭示狀態數組
        initialzeGame(chosenWord, wordLength, revealed, wrongGuesses, maxWrongGuesses);
    } while (playAgain == 'y' || playAgain == 'Y');  // 如果用戶選擇 'y' 或 'Y'，重新開始遊戲

    printf("Thank you for playing!\n");  // 顯示感謝訊息
    return 0;  // 結束程式
}
