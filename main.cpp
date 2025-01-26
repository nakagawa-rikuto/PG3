#include <iostream>
#include <string>
#include <chrono>

int main() {
    // 100,000文字の'a'で初期化された文字列を作成
    std::string a(100000, 'a');

    // コピー操作の時間を計測
    auto start_copy = std::chrono::high_resolution_clock::now();
    std::string b = a; // コピー
    auto end_copy = std::chrono::high_resolution_clock::now();
    auto copy_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_copy - start_copy).count();

    // 移動操作の時間を計測
    auto start_move = std::chrono::high_resolution_clock::now();
    std::string c = std::move(a); // 移動
    auto end_move = std::chrono::high_resolution_clock::now();
    auto move_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_move - start_move).count();

    // 結果を表示
    printf("100,000文字を移動とコピーで比較しました。\n");
    printf("コピー : %lld\u03bcs\n", copy_duration);
    printf("移動 : %lld\u03bcs\n", move_duration);

    return 0;
}