#pragma once

#include <iostream>
#include <expected>

namespace transform_error {
	std::expected<int, std::string> transformError(const std::string& error) {
		return std::unexpected("New Error: " + error);
	}

	void run() {
		auto errorTransformed = std::expected<int, std::string>
			(std::unexpected("Original Error")).transform_error(transformError);

		// this crashes
		/*
 		std::cout << errorTransformed.has_value() ?
			errorTransformed.value()
			: errorTransformed.error();
		*/
	}
}