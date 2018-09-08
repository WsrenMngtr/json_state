#pragma once
#include <string>
#include <type_traits>

// std::is_arithmetic<T>() == std::true_type()
template <typename T>
std::string getJsonArithmetic(const T& a) {
	return std::to_string(a);
}

// char*, const char*, char* const, const char* const
// char[], const char[]
// std::string
template <typename T>
std::string getJsonStr(const T& str) {
	return str;
}

// T* but not char*
template <typename T>
std::string getJsonPointer(const T& p) {
	return 'p' + std::to_string((int)p);
}

// T[], const T[] but not char[]
// vector, deque, list, forward_list, initlizer_list
template <typename T>
std::string getJsonList(const T& l) {
	std::string str;
	str.append("[");
	for (const auto& element : l) {
		str.append(getJson(element));
		str.append(", ");
	}
	str.append("]");
	return str;
}

// pair
template <typename T>
std::string getJsonPair(const T& p) {
	std::string str = getJson(p.first) + ": " + getJson(p.second);
}

// set, multiset, unordered_set, unordered_multiset
// map, multimap, unordered_map, unordered_multimap
template <typename T>
std::string getJsonPair(const T& p) {
	std::string str;
	str.append("{");
	for (const T& element : array) {
		str.append(getJson(element));
		str.append(", ");
	}
	str.append("}");
}
