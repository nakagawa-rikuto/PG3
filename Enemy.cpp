#include "Enemy.h"
#include <iostream>

// 静的メンバの初期化
int Enemy::mode_ = Enemy::EnemyMode::approach;  // 初期状態を接近に設定

// メンバ関数ポインタのテーブルを初期化
void (Enemy::* Enemy::spFuncTable[])() = {
    &Enemy::Approach,
    &Enemy::Shooting,
    &Enemy::Withdrawal
};

// コンストラクタ
Enemy::Enemy() : pFunc(spFuncTable[mode_]) {}

// デストラクタ
Enemy::~Enemy() {}

// 更新関数
void Enemy::Update() {
    // 現在の状態に対応する関数を呼び出し
    (this->*pFunc)();

    // 次の状態に遷移
    mode_ = (mode_ + 1) % 3;  // 循環させるため3で割った余りを使う
    pFunc = spFuncTable[mode_];
}

// 接近状態
void Enemy::Approach() {
    printf("接近\n");
    printf("↓\n");
}

// 射撃状態
void Enemy::Shooting() {
    printf("射撃\n");
    printf("↓\n");
}

// 離脱状態
void Enemy::Withdrawal() {
    printf("離脱\n");
    printf("\n");
}
