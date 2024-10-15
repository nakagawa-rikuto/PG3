#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>

// 判定結果を表示するためのコールバック関数の型を定義
typedef void (*ResultCallback)(bool);

// 判定結果を表示するコールバック関数
void DisplayResult(bool isCorrect) {
    if (isCorrect) {
        printf("正解\n");
    } else {
        printf("不正解\n");
    }
}

// サイコロの出目を決定し、ユーザーの予想と比較する関数
void RollDiceAndJudge(const char* userGuess) {
    // ランダムな出目を生成（1～6）
    int diceRoll = rand() % 6 + 1;

    // 抽選結果を奇数か偶数で判定
    bool isEven = (diceRoll % 2 == 0);
    bool userGuessedEven = (userGuess[0] == '丁'); // 丁の場合は偶数と判定

    // 3秒間待つ
    Sleep(3000); // Sleepの引数はミリ秒なので3000に変更

    // ユーザーの予想と結果を比較し、コールバック関数を呼び出す
    DisplayResult(isEven == userGuessedEven);
}

int main() {
    // 乱数シードを設定
    srand((unsigned int)time(NULL));

    char userGuess[10]; // 配列サイズを十分に大きくしておく

    // ユーザーに奇数（半）か偶数（丁）かの予想を求める
    printf("サイコロの出目を半か丁かを予想してください（半 = 奇数/丁 = 偶数）: ");
    scanf_s("%s", userGuess, (unsigned)_countof(userGuess));

    // サイコロを振り、判定と結果表示を行う
    RollDiceAndJudge(userGuess);

    return 0;
}