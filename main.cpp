#include <stdio.h>

template <typename T>
class Comparator {
public:
    // Minƒƒ“ƒoŠÖ”
    T Min(T a, T b) {
        return (a < b) ? a : b;
    }
};

int main() {
    // intŒ^‚ÌƒCƒ“ƒXƒ^ƒ“ƒX
    Comparator<int> intComp;
    printf("intŒ^‚ÆintŒ^ %d\n", intComp.Min(114, 551));

    // floatŒ^‚ÌƒCƒ“ƒXƒ^ƒ“ƒX
    Comparator<float> floatComp;
    printf("floatŒ^‚ÆfloatŒ^ %.2f\n", floatComp.Min(114.0f, 54.2f));

    // doubleŒ^‚ÌƒCƒ“ƒXƒ^ƒ“ƒX
    Comparator<double> doubleComp;
    printf("doubleŒ^‚ÆdoubleŒ^ %.2f\n", doubleComp.Min(11.0, 55.5));

    // intŒ^‚ÆfloatŒ^‚Ì”äŠr (int -> float‚ÉƒLƒƒƒXƒg‚µ‚Ä”äŠr)
    printf("intŒ^‚ÆfloatŒ^ %.2f\n", floatComp.Min(static_cast<float>(10), 54.2f));

    // intŒ^‚ÆdoubleŒ^‚Ì”äŠr (int -> double‚ÉƒLƒƒƒXƒg‚µ‚Ä”äŠr)
    printf("intŒ^‚ÆdoubleŒ^ %.2f\n", doubleComp.Min(static_cast<double>(114), 55.5));

    // floatŒ^‚ÆdoubleŒ^‚Ì”äŠr (float -> double‚ÉƒLƒƒƒXƒg‚µ‚Ä”äŠr)
    printf("floatŒ^‚ÆdoubleŒ^ %.2f\n", doubleComp.Min(static_cast<double>(114.0f), 55.5));

    return 0;
}