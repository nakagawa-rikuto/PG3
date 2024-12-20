#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int current_thread = 1;

void print_thread(int thread_id, int next_thread_id) {
    std::unique_lock<std::mutex> lock(mtx);

    // 待機: 現在のスレッドIDが一致するまで
    cv.wait(lock, [thread_id]() { return current_thread == thread_id; });

    // メッセージの表示
    printf("thread %d\n", thread_id);

    // 次のスレッドに切り替え
    current_thread = next_thread_id;

    // 他のスレッドを起床
    cv.notify_all();
}

int main() {
    // スレッドを生成
    std::thread t1(print_thread, 1, 2);
    std::thread t2(print_thread, 2, 3);
    std::thread t3(print_thread, 3, 1);

    // スレッドの終了を待機
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
