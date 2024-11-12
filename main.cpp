#include <stdio.h>

template <typename T>
class Comparator {
public:
    // Min�����o�֐�
    T Min(T a, T b) {
        return (a < b) ? a : b;
    }
};

int main() {
    // int�^�̃C���X�^���X
    Comparator<int> intComp;
    printf("int�^��int�^ %d\n", intComp.Min(114, 551));

    // float�^�̃C���X�^���X
    Comparator<float> floatComp;
    printf("float�^��float�^ %.2f\n", floatComp.Min(114.0f, 54.2f));

    // double�^�̃C���X�^���X
    Comparator<double> doubleComp;
    printf("double�^��double�^ %.2f\n", doubleComp.Min(11.0, 55.5));

    // int�^��float�^�̔�r (int -> float�ɃL���X�g���Ĕ�r)
    printf("int�^��float�^ %.2f\n", floatComp.Min(static_cast<float>(10), 54.2f));

    // int�^��double�^�̔�r (int -> double�ɃL���X�g���Ĕ�r)
    printf("int�^��double�^ %.2f\n", doubleComp.Min(static_cast<double>(114), 55.5));

    // float�^��double�^�̔�r (float -> double�ɃL���X�g���Ĕ�r)
    printf("float�^��double�^ %.2f\n", doubleComp.Min(static_cast<double>(114.0f), 55.5));

    return 0;
}