#pragma once

class Enemy {
public:/// ===メンバ関数=== ///

	Enemy();
	~Enemy();

	enum EnemyMode {
		Approach,
		Shooting,
		Withdrawal
	};

	void Update();      // 更新

	void Approach();    // 接近
	void Shooting();	// 射撃
	void Withdrawal();  // 離脱

private:/// ===メンバ変数=== ///

	static int mode_;

	// メンバ関数ポインタ
	void (Enemy::* pFunc)();

	// メンバ関数ポインタのテーブル
	static void (Enemy::* spFuncTable[])();

};