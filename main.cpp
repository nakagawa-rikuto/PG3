#include "Enemy.h"


int main() {
    Enemy enemy;

    // ��ԑJ�ڂ��m�F���邽�߂�For���ŉ�
    for (int i = 0; i < 12; ++i) {
        enemy.Update();
    }

    return 0;
}