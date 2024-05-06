#pragma once

#include <expected>
#include <iostream>
#include <string>

namespace and_then_2 {
    std::expected<int, std::string> convertToInt(const std::string& input) {
        int value;
        auto [ptr, ec] = std::from_chars(input.data(), input.data() + input.size(), value);
        if (ec == std::errc())
            return value;

        return std::unexpected("Conversion failed: invalid input");
    }

    std::expected<int, std::string> calculate(int number) {
        if (number > 0)
            return number * 2;

        return std::unexpected("Calculation failed: number must be positive");
    }

	namespace if_else {
        void run() {
            std::string input;
            //std::cout << "Enter a number: ";
            //std::cin >> input;
            input = "123";

            auto converted = convertToInt(input);
            if (!converted) {
                std::cout << converted.error() << '\n';
                //return -1;
            }

            auto result = calculate(*converted);
            if (!result) {
                std::cout << result.error() << '\n';
                //return -1;
            }

            std::cout << "Result: " << *result << '\n';
        }
	}

    namespace monadic {
        void run() {
            std::string input;
            //std::cout << "Enter a number: ";
            //std::cin >> input;
            input = "123";

            auto result = convertToInt(input)
                .and_then(calculate)
                .and_then([](int num) {
                    std::cout << "Result: " << num << '\n';
                    return std::expected<int, std::string>(num);
                });

            if (!result)
                std::cout << result.error() << '\n';
        }
    }
}