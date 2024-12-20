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

// CSV�t�@�C����ǂݍ��ފ֐�
void load_csv(const std::string& file_path) {
    std::vector<std::vector<int>> temp_data;
    std::ifstream file(file_path);
    std::string line;

    // �t�@�C�����J���Ȃ������ꍇ�̃G���[���b�Z�[�W
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << file_path << std::endl;
        return;
    }

    // �t�@�C����1�s���ǂݍ���
    while (std::getline(file, line)) {
        std::vector<int> row; // 1�s���̃f�[�^���i�[����x�N�^�[
        size_t pos = 0;

        // �J���}�ŕ������Đ����ɕϊ����A�s�f�[�^�ɒǉ�
        while ((pos = line.find(",")) != std::string::npos) {
            row.push_back(std::stoi(line.substr(0, pos))); // �J���}�܂ł̕�����𐔒l�ɕϊ����Ēǉ�
            line.erase(0, pos + 1); // �����ς݂̕������폜
        }
        row.push_back(std::stoi(line)); // �Ō�̗v�f��ǉ�
        temp_data.push_back(row); // �s�f�[�^���ꎞ�f�[�^�ɒǉ�
    }

    file.close(); // �t�@�C�������

    // �X���b�h�Ԃŋ��L����f�[�^���X�V
    {
        std::lock_guard<std::mutex> lock(mtx); 
        map_data = temp_data; 
        data_ready = true; // �f�[�^���������t���O��ݒ�
    }

    cv.notify_all(); // ���̃X���b�h�ɒʒm
}

// �}�b�v�`�b�v��\������֐�
void display_map() {
    std::unique_lock<std::mutex> lock(mtx); 

    // �f�[�^�����������܂őҋ@
    cv.wait(lock, []() { return data_ready; });

    // �}�b�v�f�[�^��\��
    for (const auto& row : map_data) {
        for (int cell : row) {
            std::cout << cell << " "; // �e�Z�����X�y�[�X��؂�ŕ\��
        }
        std::cout << std::endl; // �s�̏I���ŉ��s
    }
}

int main() {
    // CSV�t�@�C���̃p�X
    std::string csv_file = "map.csv";

    // �X���b�h�̐���
    std::thread loader(load_csv, csv_file); // CSV�ǂݍ��݃X���b�h
    std::thread displayer(display_map); // �}�b�v�\���X���b�h

    // �X���b�h�̏I����ҋ@
    loader.join();
    displayer.join(); 

    return 0;
}
