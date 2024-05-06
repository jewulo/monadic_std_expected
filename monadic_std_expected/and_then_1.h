#pragma once

#include <expected>
#include <iostream>
#include <string>

namespace and_then_1
{
    std::expected<int, std::string> increamentIfPositive(int value) {
        if (value > 0)
            return value + 1;

        return std::unexpected("Value must be positive");
    }

    std::expected<int, std::string> getInput(int x) {
        if (x % 2 == 0)
            return x;

        return std::unexpected("Value not even!");
    }

    void run() {
        auto input = getInput(-2);
        auto result = input.and_then(increamentIfPositive);

        if (result)
            std::cout << *result << '\n';
        else
            std::cout << result.error() << '\n';
    }
}
