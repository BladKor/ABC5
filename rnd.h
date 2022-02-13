#pragma once

#include <random>
#include <vector>

const size_t kMaxSize = 1000;

struct Generator {
public: static size_t generate() {
        return 1 + Generator::getRandomMod(kMaxSize);
    }

private: static size_t getRandomMod(size_t mod) {
        return static_cast<size_t>(abs(rand())) % mod;
    }
};