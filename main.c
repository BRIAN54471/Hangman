#include "GameRules.h"

int main() {
    
    char playAgain;  // 定義變量以存儲用戶是否再玩一局的選擇
    int maxWrongGuesses;  // 定義最多錯誤猜測次數
    char* chosenWord;  // 定義變量以存儲選擇的單詞
    int wordLength;  // 定義變量以存儲單詞長度
    int revealed[50];  // 定義揭示狀態數組
    int wrongGuesses;  // 定義錯誤猜測計數器
    int round = 1;  // 定義變量以記錄回合數

    char data[MAX_ROWS][MAX_COLS][MAX_LINE_LENGTH] = {0};
    read_hangman_csv("hangman_words.csv", data);  // 讀取單詞列表
    printf("Welcome to Hangman!\n");  // 歡迎訊息
    int topic = selectTopic();  // 選擇主題
    int difficulty = selectDifficulty();  // 選擇難度
    do {
        srand(time(NULL));  // 使用當前時間初始化隨機數生成器
        initializeGame(&chosenWord, &wordLength, revealed, &wrongGuesses, topic, data);  // 初始化遊戲狀態
        printf("--------------------------------\n"); 
        printf("Round %d :\n", round);  // 回合訊息
        round++;  // 增加回合數
        gameRule(chosenWord, wordLength, revealed, &wrongGuesses, difficulty);  // 遊戲規則

        printf("Type 'y' to play again, or any other key to quit: ");  // 提示用戶選擇是否再玩一局
        scanf(" %c", &playAgain);  // 讀取用戶選擇
    } while (playAgain == 'y' || playAgain == 'Y');  // 如果用戶選擇 'y' 或 'Y'，重新開始遊戲

    printf("Thank you for playing!\n");  // 顯示感謝訊息
    return 0;  // 結束程式
}


/*
// 測試
int main(){
    char data[MAX_ROWS][MAX_COLS][MAX_LINE_LENGTH] = {0};
    read_hangman_csv("hangman_words.csv", data);
    int topic = selectTopic();
    // Print the data to verify the contents
    printf("random word: %s, from topic: %d\n", chooseRandomWord(topic, data), topic) ;
    return 0;
}
*/