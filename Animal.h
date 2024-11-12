#pragma once
#include <memory>

// アニマル
class Animal {
public:/// ===仮想関数=== ///

	virtual void Voice() const = 0;
	virtual ~Animal() = default;
};

