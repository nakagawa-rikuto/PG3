#include "Enemy.h"

#include <stdio.h>

void (Enemy::* Enemy::spFuncTable[])() = {
	&Enemy::Approach,  // �v�f��0
	&Enemy::Shooting,  // �v�f��1
	&Enemy::Withdrawal // �v�f��2
};

void Enemy::Update() {
	// �����o�֐��|�C���^�ɓ����Ă���֐����Ăяo���B
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
	printf("�ڋ�\n");
}

void Enemy::Shooting() {
	printf("�ˌ�\n");
}

void Enemy::Withdrawal() {
	printf("���E\n");
}
