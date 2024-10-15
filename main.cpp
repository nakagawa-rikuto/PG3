#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>
#include <functional>
#include <thread>

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

// SetTimeout 関数: 指定したミリ秒後にコールバック関数を呼び出す
void SetTimeout(int milliseconds, std::function<void()> callback) {
    std::thread([milliseconds, callback]() {
        // 指定時間待機
        Sleep(milliseconds);
        // 待機後にコールバックを実行
        callback();
        }).detach(); // スレッドをデタッチして、非同期で動作させる
}

// サイコロの出目を決定し、ユーザーの予想と比較する関数
void RollDiceAndJudge(const char* userGuess) {
    // ランダムな出目を生成（1～6）
    int diceRoll = rand() % 6 + 1;

    // 抽選結果を奇数か偶数で判定
    bool isEven = (diceRoll % 2 == 0);
    bool userGuessedEven = (userGuess[0] == '丁'); // 丁の場合は偶数と判定

    // ラムダ式を使って、3秒後に結果を表示するようにする
    SetTimeout(3000, [isEven, userGuessedEven]() {
        DisplayResult(isEven == userGuessedEven);
        });
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

    // 終了前にユーザー入力を待つ（スレッドの実行を待つため）
    getchar();
    getchar();

    return 0;
}