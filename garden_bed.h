#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <thread>
#include <mutex>

const static size_t kSize = 40;

class Garden_Bed {
    std::vector<size_t> watered;
    std::vector<size_t> dry;
    std::mutex mutex;

public:
    Garden_Bed() {
        for (size_t i = 0; i < kSize; ++i) {
            watered.push_back(i);
        }
        for (size_t i = 0; i < kSize / 2; ++i) {
            dry.push_back(getRandomFlower(watered));
        }
    }

    void waterRandomDry(size_t number) {
        mutex.lock();

        std::cout << "Gardener ";
        std::cout << std::to_string(number);
        std::cout << "\t:\t";
        if (dry.empty()) {
            std::cout << "the garden bed is fine\n";
            mutex.unlock();
            return;
        }
        watered.push_back(getRandomFlower(dry));
        std::cout << "water flower number ";
        std::cout << std::to_string(watered.back()) << '\n';

        mutex.unlock();
    }

    void drainRandomFlower() {
        mutex.lock();

        std::cout << "Butterfly\t:\t";
        if (watered.empty()) {
            std::cout << "garden is fully drained\n";
            mutex.unlock();
            return;
        }
        dry.push_back(getRandomFlower(watered));
        std::cout << "drained flower number ";
        std::cout << std::to_string(dry.back()) << '\n';

        mutex.unlock();
    }

private:
    size_t getRandomFlower(std::vector<size_t>& arr) {
        std::random_shuffle(arr.begin(), arr.end());
        size_t flower = arr.back();
        arr.pop_back();
        return flower;
    }
};