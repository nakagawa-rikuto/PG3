#pragma once

class Enemy {
public:/// ===メンバ関数=== ///

	Enemy();
	~Enemy();

	enum EnemyMode {
		approach,
		shooting,
		withdrawal
	};

	void Update();      // 更新

	void Approach();    // 接近
	void Shooting();	// 射撃
	void Withdrawal();  // 離脱

private:/// ===メンバ変数=== ///

	// 静的メンバ変数としてのモード
	static int mode_;

	// メンバ関数ポインタ
	void (Enemy::* pFunc)();

	// メンバ関数ポインタのテーブル
	static void (Enemy::* spFuncTable[])();
};