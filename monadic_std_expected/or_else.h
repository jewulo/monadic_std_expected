#pragma once

#include <iostream>
#include <expected>

namespace or_else{
    std::expected<int, std::string> incrementIfPositive(int value) {
        if (value > 0)
            return value + 1;
        return std::unexpected("Value must be positive");
    }

    std::expected<int, std::string> getInput(int x) {
        if (x % 2 == 0)
            return x;

        return std::unexpected("Value not even!");
    }

    std::expected<int, std::string> handleError(const std::string& error) {
        std::cerr << "Error encountered: " << error << '\n';
        return std::unexpected(error);
    }

    void run_1() {
        auto handled = std::expected<int, std::string>(std::unexpected("Failure")).or_else(handleError);
    }

    void run_2() {
        auto input = getInput(2);
        auto result = input.and_then(incrementIfPositive)
            .or_else(handleError);

        if (result)
            std::cout << result.value() << '\n';
    }

    void run_3() {
        auto input = getInput(-2);
        auto result = input.and_then(incrementIfPositive)
            .or_else(handleError);

        if (result)
            std::cout << result.value() << '\n';
    }
}
