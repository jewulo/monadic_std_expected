#pragma once

#include <chrono>
#include <expected>
#include <format>
#include <iostream>
#include <string>
#include <sstream>

namespace transform {
	namespace ex1 {
		enum class Err { succ, fail };
		std::expected<int, Err> doubleValue(int value) {
			return value * 2;
		}

		void run() {
			auto tr = std::expected<int, Err>(10).transform(doubleValue);
			if (tr.has_value())
				std::cout << tr.value().value() << '\n';
		}
	}

	namespace ex2 {
		std::expected<std::chrono::year_month_day, std::string>
		parseDate(const std::string& dateStr) {
			std::istringstream iss(dateStr);
			std::chrono::year_month_day ymd;
			iss >> std::chrono::parse("%F", ymd);
			if (!ymd.ok())
				return std::unexpected("Parsing failed: invalid date format");

			return ymd;
		}

		std::string formatDate(const std::chrono::year_month_day& ymd) {
			return std::format("Back to string: {:%Y-%m-%d}", ymd);
		}

		void run() {
			std::string input = "2024-04-29";
			auto result = parseDate(input).transform(formatDate);

			if (!result) {
				std::cout << "Error: " << result.error() << '\n';
				// return -1;
			}

			std::cout << "Formatted Date: " << *result << '\n';
		}
	}
}

