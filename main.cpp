#include <stdio.h>

template <typename Type>
Type Min(Type a, Type b) {

	if (a < b) {
		return static_cast<Type>(b);
	} else {
		return static_cast<Type>(a);
	}
}

/// ===テンプレートの解除=== ///
//NOTE: template <> = テンプレの解除
template <>
char Min<char>(char a, char b) {
	printf("数字以外は代入できません");
	return ' ';
}

int main() {

	printf("%d : int型\n", Min<int>(114, 551)); // int型
	printf("%3.1f : float型\n", Min<float>(114.0f, 54.2f)); // float型
	printf("%3.1lf : double型\n", Min<double>(11.0f, 55.5f)); // double型
	printf("%c : char型\n", Min<char>(11, 55)); // char型

	return 0;
}