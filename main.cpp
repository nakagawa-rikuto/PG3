#include "Enemy.h"


int main() {
    Enemy enemy;

    // 状態遷移を確認するためにFor文で回す
    for (int i = 0; i < 12; ++i) {
        enemy.Update();
    }

    return 0;
}