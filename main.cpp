#include <stdio.h>

// 前の一時間でもらった時給 *　2 - 50円の計算
int Recursive(int n, int salary) {
	if (n <= 1) {
		return salary;
	}

	int currentResult = salary * 2 - 50; // 今回の計算
	return Recursive(n - 1, currentResult) + salary; // 前回の計算結果を足す
}

int main() {

	int time = 0;
	int salary = 100;
	int result = 0;
	int select = 0;

	printf("労働時間を入力してください\n");
	scanf_s("%d", &time);

	result = 1079 * time;
	printf("%d\n", result);

	result = Recursive(time, salary);
	printf("%d\n", result);

	return 0;
}