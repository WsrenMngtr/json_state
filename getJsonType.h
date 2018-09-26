#pragma once
#include <string>
#include <functional>

// class, and must use memberName, member, ... as args
template <typename... Args>
std::function<std::string()> getJsonByMember(const Args&... args);

template <typename First, typename... Args>
std::string getJsonMember(const std::string& key, const First& value, const Args&... args);

template <typename First>
std::string getJsonMember(const std::string& key, const First& value);

template <typename T>
std::string getJsonChar(const T& c);

template <typename T>
std::string getJsonBool(const T& c);

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

template <typename T>
std::string getJsonCon(const T& c);

// std::is_arithmetic<T>() == std::true_type()
template <typename T>
std::string getJsonArithmetic(const T& a) {
	return std::to_string(a);
}

// char
template <typename T>
std::string getJsonChar(const T& c) {
	return { '\'', c, '\'' };
}

// bool
template <typename T>
std::string getJsonBool(const T& b) {
	return b ? "true" : "false";
}

// char*, const char*, char* const, const char* const
// char[], const char[]
// std::string
template <typename T>
std::string getJsonStr(const T& str) {
	return "\"" + std::string(str) + "\"";
}

// T[], const T[] but not char[]
// vector, deque, list, forward_list, initlizer_list
template <typename T>
std::string getJsonList(const T& l) {
	std::string str;
	str.append("[ ");
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
	return getJson(p.first) + ": " + getJson(p.second);
}

// set, multiset, unordered_set, unordered_multiset
// map, multimap, unordered_map, unordered_multimap
template <typename T>
std::string getJsonAssoc(const T& c) {
	std::string str;
	str.append("{ ");
	for (const auto& element : c) {
		str.append(getJson(element));
		str.append(", ");
	}
	str.append("}");
	return str;
}

// contrat
template <typename T>
std::string getJsonCon(const T& c, const char& leftChar, const char& rightChar) {
	std::string str;
	str.append({leftChar, ' '});
	for (const auto& element : c) {
		str.append(getJson(element));
		str.append(", ");
	}
	str.append(rightChar);
	return str;
}

// other
template <typename T>
std::string getJsonClass(const T& o) {
	return o.getJson();
}
