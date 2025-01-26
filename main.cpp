#include <iostream>
#include <string>
#include <chrono>

int main() {
    // 100,000������'a'�ŏ��������ꂽ��������쐬
    std::string a(100000, 'a');

    // �R�s�[����̎��Ԃ��v��
    auto start_copy = std::chrono::high_resolution_clock::now();
    std::string b = a; // �R�s�[
    auto end_copy = std::chrono::high_resolution_clock::now();
    auto copy_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_copy - start_copy).count();

    // �ړ�����̎��Ԃ��v��
    auto start_move = std::chrono::high_resolution_clock::now();
    std::string c = std::move(a); // �ړ�
    auto end_move = std::chrono::high_resolution_clock::now();
    auto move_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_move - start_move).count();

    // ���ʂ�\��
    printf("100,000�������ړ��ƃR�s�[�Ŕ�r���܂����B\n");
    printf("�R�s�[ : %lld\u03bcs\n", copy_duration);
    printf("�ړ� : %lld\u03bcs\n", move_duration);

    return 0;
}