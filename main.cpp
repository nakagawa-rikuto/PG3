#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
	// ファイル名
	std::string filePath = "Data/PG3_2024_03_02.txt";
	// メールアドレスを格納する vector
	std::vector<std::string> emailAddresses;

	// ファイルを開く
	std::ifstream inputFile(filePath);
	if (!inputFile.is_open()) {
		std::cerr << "Failed to open file: " << filePath << std::endl;
		return 1;
	}

	// ファイルからメールアドレスを読み取る
	std::string line;
	while (std::getline(inputFile, line, ',')) { // ',' 区切りで読み込む
		line.erase(std::remove(line.begin(), line.end(), '\n'), line.end()); // 改行を削除
		line.erase(std::remove(line.begin(), line.end(), '\r'), line.end()); // Windowsの改行対策
		emailAddresses.push_back(line);
	}

	inputFile.close();

	// ソートするための比較関数
	auto compareByStudentNumber = [](const std::string& a, const std::string& b) {
		// 学生番号全体（最初の10文字）を比較
		return a.substr(0, 10) < b.substr(0, 10);
		};

	// ソート
	std::sort(emailAddresses.begin(), emailAddresses.end(), compareByStudentNumber);

	// 結果を出力
	for (const auto& email : emailAddresses) {
		// std::string を C文字列に変換して出力
		printf("%s\n", email.c_str());
	}

	return 0;
}