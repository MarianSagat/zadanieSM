#include "pch.h"
#include "split.h"

std::vector<std::string> siemens::split(const std::string& string, const std::string& delimiter)
{
	std::string token{}, copy = string;
	size_t position{ std::string::npos };
	std::vector<std::string> result;
	while ((position = copy.find(delimiter)) != std::string::npos) {
		result.push_back(copy.substr(0, position));
		copy.erase(0, position + delimiter.length());
	}
	result.push_back(copy);

	return result;
}
