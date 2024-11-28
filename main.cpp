#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
	// �t�@�C����
	std::string filePath = "Data/PG3_2024_03_02.txt";
	// ���[���A�h���X���i�[���� vector
	std::vector<std::string> emailAddresses;

	// �t�@�C�����J��
	std::ifstream inputFile(filePath);
	if (!inputFile.is_open()) {
		std::cerr << "Failed to open file: " << filePath << std::endl;
		return 1;
	}

	// �t�@�C�����烁�[���A�h���X��ǂݎ��
	std::string line;
	while (std::getline(inputFile, line, ',')) { // ',' ��؂�œǂݍ���
		line.erase(std::remove(line.begin(), line.end(), '\n'), line.end()); // ���s���폜
		line.erase(std::remove(line.begin(), line.end(), '\r'), line.end()); // Windows�̉��s�΍�
		emailAddresses.push_back(line);
	}

	inputFile.close();

	// �\�[�g���邽�߂̔�r�֐�
	auto compareByStudentNumber = [](const std::string& a, const std::string& b) {
		// �w���ԍ��S�́i�ŏ���10�����j���r
		return a.substr(0, 10) < b.substr(0, 10);
		};

	// �\�[�g
	std::sort(emailAddresses.begin(), emailAddresses.end(), compareByStudentNumber);

	// ���ʂ��o��
	for (const auto& email : emailAddresses) {
		// std::string �� C������ɕϊ����ďo��
		printf("%s\n", email.c_str());
	}

	return 0;
}