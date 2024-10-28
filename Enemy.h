#pragma once

class Enemy {
public:/// ===�����o�֐�=== ///

	Enemy();
	~Enemy();

	enum EnemyMode {
		Approach,
		Shooting,
		Withdrawal
	};

	void Update();      // �X�V

	void Approach();    // �ڋ�
	void Shooting();	// �ˌ�
	void Withdrawal();  // ���E

private:/// ===�����o�ϐ�=== ///

	static int mode_;

	// �����o�֐��|�C���^
	void (Enemy::* pFunc)();

	// �����o�֐��|�C���^�̃e�[�u��
	static void (Enemy::* spFuncTable[])();

};