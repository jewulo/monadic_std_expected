#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <expected>
#include <chrono>
#include <format>

/*
	In this file we will combine all we did in the previews files
	and_then_1.h, and_then_2.h, or_else.h, transform.h, transform_error.h.
*/


namespace wrap_up {
	bool isWeekend(const std::chrono::year_month_day& ymd) {
		auto wd = std::chrono::weekday(ymd);
		return wd == std::chrono::Sunday || wd == std::chrono::Saturday;
	}

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
		return std::format("{:%Y-%m-%d}", ymd);
	}
	
	void run(const std::string& input) {
		//std::string input = "2024-04-28";	// This is a Saturday
		//std::string input = "2024-04-30";	// This is a Monday
		auto result = parseDate(input)
			.and_then([](const std::chrono::year_month_day& ymd)
						-> std::expected<std::chrono::year_month_day, std::string>{
				if (isWeekend(ymd)) {
					return std::unexpected("Date falls on a weekend");
				}
				return ymd;
			})
			.transform([](const std::chrono::year_month_day& ymd) -> std::string {
				return formatDate(ymd);
			})
			.transform_error([](const std::string& error) -> std::string {
				return "Error encountered: " + error;
			})
			.or_else([](const std::string& error) {
				std::cout << "Handled Error: " << error << '\n';
				return std::expected<std::string, std::string>
					(std::unexpected(error));
			});

			if (result)
				std::cout << "Formatted Date: " << *result << '\n';
			else
				std::cout << "Final Error: " << result.error() << '\n';
	}
}
