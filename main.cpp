#include <stdio.h>

template <typename Type>

class Math {
public:

	// メンバ変数
	Type int_;
	Type float_;
	Type double_;

	// コンストラクタ
	Type Math(Type num1, Type num2, Type num3) : int_(num1), float_(num2), double_(num3) {};

	Type Min(Type a, Type b) {
		if (a < b) {
			return static_cast<Type>(a);
		} else {
			return static_cast<Type>)(b);
		}
	}
};

int main() {

	return 0;
}
