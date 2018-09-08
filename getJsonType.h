#pragma once
#include <string>
#include <type_traits>

template <typename T>
std::string getJsonArithmetic(const T& a);

template <typename T>
std::string getJsonStr(const T& str);

template <typename T>
std::string getJsonList(const T& l);

template <typename T>
std::string getJsonPair(const T& p);

template <typename T>
std::string getJsonPair(const T& p);

// std::is_arithmetic<T>() == std::true_type()
template <typename T>
std::string getJsonArithmetic(const T& a) {
	return std::to_string(a);
}

// char
template <typename T>
std::string getJsonChar(const T& c) {
	return { c };
}

// char*, const char*, char* const, const char* const
// char[], const char[]
// std::string
template <typename T>
std::string getJsonStr(const T& str) {
	return str;
}

// T[], const T[] but not char[]
// vector, deque, list, forward_list, initlizer_list
template <typename T>
std::string getJsonList(const T& l) {
	std::string str;
	str.append("[");
	auto i = begin(l);
	str.append(getJson(*i));
	for (i++; i != end(l); i++) {
		str.append(", ");
		str.append(getJson(*i));
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
std::string getJsonAssoc(const T& p) {
	std::string str;
	str.append("{");
	for (const T& element : array) {
		str.append(getJson(element));
		str.append(", ");
	}
	str.append("}");
}

// other
template <typename T>
std::string getJsonClass(const T& o) {
	return o.getJson();
}
