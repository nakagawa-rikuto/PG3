#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool data_ready = false;
std::vector<std::vector<int>> map_data;

// CSVファイルを読み込む関数
void load_csv(const std::string& file_path) {
    std::vector<std::vector<int>> temp_data;
    std::ifstream file(file_path);
    std::string line;

    // ファイルが開けなかった場合のエラーメッセージ
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << file_path << std::endl;
        return;
    }

    // ファイルを1行ずつ読み込む
    while (std::getline(file, line)) {
        std::vector<int> row; // 1行分のデータを格納するベクター
        size_t pos = 0;

        // カンマで分割して整数に変換し、行データに追加
        while ((pos = line.find(",")) != std::string::npos) {
            row.push_back(std::stoi(line.substr(0, pos))); // カンマまでの文字列を数値に変換して追加
            line.erase(0, pos + 1); // 処理済みの部分を削除
        }
        row.push_back(std::stoi(line)); // 最後の要素を追加
        temp_data.push_back(row); // 行データを一時データに追加
    }

    file.close(); // ファイルを閉じる

    // スレッド間で共有するデータを更新
    {
        std::lock_guard<std::mutex> lock(mtx); 
        map_data = temp_data; 
        data_ready = true; // データ準備完了フラグを設定
    }

    cv.notify_all(); // 他のスレッドに通知
}

// マップチップを表示する関数
void display_map() {
    std::unique_lock<std::mutex> lock(mtx); 

    // データが準備されるまで待機
    cv.wait(lock, []() { return data_ready; });

    // マップデータを表示
    for (const auto& row : map_data) {
        for (int cell : row) {
            std::cout << cell << " "; // 各セルをスペース区切りで表示
        }
        std::cout << std::endl; // 行の終わりで改行
    }
}

int main() {
    // CSVファイルのパス
    std::string csv_file = "map.csv";

    // スレッドの生成
    std::thread loader(load_csv, csv_file); // CSV読み込みスレッド
    std::thread displayer(display_map); // マップ表示スレッド

    // スレッドの終了を待機
    loader.join();
    displayer.join(); 

    return 0;
}
