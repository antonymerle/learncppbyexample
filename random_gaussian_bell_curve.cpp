#include <algorithm>
#include <array>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <print>
#include <random>
#include <vector>

void random_gaussian_normal_dist()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dist;

    const int max       = 3;
    constexpr size_t sz = max * 2 + 1;

    // Generate 1000 random numbers from a normal distribution
    std::array<int, sz> hist;
    for (size_t i = 0; i < 1000; ++i) {
        double non_clamped = dist(gen);
        if (non_clamped < -3 || non_clamped > 3) std::println("non-clamped : {}", non_clamped);
        double val = std::clamp<double>(dist(gen), -max, max);
        // std::println("clamped : {}", val);
        hist[(size_t)round(val) + max]++;
    }

    // Scale histogram to the range [0-30]
    int max_sum = *std::max_element(hist.begin(), hist.end());
    std::transform(hist.begin(), hist.end(), hist.begin(),
                   [max_sum](auto& n) { return static_cast<float>(n) / (float)max_sum * 30.0f; });

    // Print out the histogram
    int i = -max;
    for (auto n : hist) {
        std::cout << std::setw(2) << i << "|" << std::string((size_t)n, '#') << "\n";
        i++;
    }
}
