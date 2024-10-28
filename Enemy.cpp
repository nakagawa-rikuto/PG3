#include "Enemy.h"

#include <stdio.h>

void (Enemy::* Enemy::spFuncTable[])() = {
	&Enemy::Approach,  // 要素数0
	&Enemy::Shooting,  // 要素数1
	&Enemy::Withdrawal // 要素数2
};

void Enemy::Update() {
	// メンバ関数ポインタに入っている関数を呼び出す。
	for (int i = 0; i < 3; ++i) {
		mode_ = i;
	}
	pFunc = 
	(this->*spFuncTable[static_cast<size_t>(mode_)])();
	pFunc = &Enemy::Shooting;
	(this->*spFuncTable[static_cast<size_t>(EnemyMode::Withdrawal)])();
	pFunc = &Enemy::Withdrawal;
}

void Enemy::Approach() {
	printf("接近\n");
}

void Enemy::Shooting() {
	printf("射撃\n");
}

void Enemy::Withdrawal() {
	printf("離脱\n");
}
