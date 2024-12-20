#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int current_thread = 1;

void print_thread(int thread_id, int next_thread_id) {
    std::unique_lock<std::mutex> lock(mtx);

    // �ҋ@: ���݂̃X���b�hID����v����܂�
    cv.wait(lock, [thread_id]() { return current_thread == thread_id; });

    // ���b�Z�[�W�̕\��
    printf("thread %d\n", thread_id);

    // ���̃X���b�h�ɐ؂�ւ�
    current_thread = next_thread_id;

    // ���̃X���b�h���N��
    cv.notify_all();
}

int main() {
    // �X���b�h�𐶐�
    std::thread t1(print_thread, 1, 2);
    std::thread t2(print_thread, 2, 3);
    std::thread t3(print_thread, 3, 1);

    // �X���b�h�̏I����ҋ@
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
