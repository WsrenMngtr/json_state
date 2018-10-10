#pragma once

#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <initializer_list>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>

#include <type_traits>

#include "getJsonType.h"

// std::is_arithmetic<T>() == std::true_type()
// other
template <typename T>
std::string getJson(const T& t);
template <typename T>
std::string getJsonIsArith(const T& t, std::true_type);
template <typename T>
std::string getJsonIsArith(const T& t, std::false_type);

// char
template <>
std::string getJson(const char& c);

// bool//
template <>
std::string getJson(const bool& b);

// char*, const char*, char* const, const char* const
// char[], const char[]
// std::string
template <>
std::string getJson(const std::string& s);
template <size_t N>
std::string getJson(const char(&s)[N]);
template <size_t N>
std::string getJson(char(&s)[N]);
template <>
std::string getJson(const char* const& s);
template <>
std::string getJson(char* const& s);

// T[], const T[] but not char[]
// vector, deque, list, forward_list, initlizer_list
template <typename T, size_t N>
std::string getJson(T(&c)[N]);
template <typename T>
std::string getJson(const std::vector<T>& c);
template <typename T>
std::string getJson(const std::deque<T>& c);
template <typename T>
std::string getJson(const std::list<T>& c);
template <typename T>
std::string getJson(const std::forward_list<T>& c);
template <typename T>
std::string getJson(const std::initializer_list<T>& c);

// pair
template <typename A, typename B>
std::string getJson(const std::pair<A, B>& p);

// set, multiset, unordered_set, unordered_multiset
// map, multimap, unordered_map, unordered_multimap
template <typename K>
std::string getJson(const std::set<K>& c);
template <typename K>
std::string getJson(const std::multiset<K>& c);
template <typename K>
std::string getJson(const std::unordered_set<K>& c);
template <typename K>
std::string getJson(const std::unordered_multiset<K>& c);

template <typename K, typename V>
std::string getJson(const std::map<K, V>& m);
template <typename K, typename V>
std::string getJson(const std::multimap<K, V>& m);
template <typename K, typename V>
std::string getJson(const std::unordered_map<K, V>& m);
template <typename K, typename V>
std::string getJson(const std::unordered_multimap<K, V>& m);

// tuple
template <typename... Args>
std::string getJson(const std::tuple<Args...>& t);
template <size_t N>
struct JsonTuple;
template <>
struct JsonTuple<0>;

// Args...
template <typename... Args>
std::string getJson(const Args&... args);
template <typename First, typename... Args>
std::string getJsonArgs(const First& first, const Args&... args);
template <typename T>
std::string getJsonArgs(const T& t);

// class, and must use memberName, member, ... as args
template <typename... Args>
std::function<std::string()> getJsonByMember(const Args&... args);
template <typename First, typename... Args>
std::string getJsonMember(const std::string& key, const First& value, const Args&... args);
template <typename First>
std::string getJsonMember(const std::string& key, const First& value);

// =====================================================================
// define

// char
template <>
std::string getJson(const char& c) {
	return getJsonChar(c);
}

// bool
template <>
std::string getJson(const bool& b) {
	return getJsonBool(b);
}

// char*, const char*, char* const, const char* const
// char[], const char[]
// std::string
template <>
std::string getJson(const std::string& s) {
	return getJsonStr(s);
}
template <size_t N>
std::string getJson(char (&s)[N]) {
	return getJsonStr(s);
}
template <size_t N>
std::string getJson(const char (&s)[N]) {
	return getJsonStr(s);
}

template <>
std::string getJson(const char* const& s) {
	return getJsonStr(s);
}

template <>
std::string getJson(char* const& s) {
	return getJsonStr(s);
}

// T[], const T[] but not char[]
// vector, deque, list, forward_list, initlizer_list
template <typename T, size_t N>
std::string getJson(T (&c)[N]) {
	return getJsonContrat(c, '[', ']');
}
template <typename T>
std::string getJson(const std::vector<T>& c) {
	return getJsonContrat(c, '[', ']');
}
template <typename T>
std::string getJson(const std::deque<T>& c) {
	return getJsonContrat(c, '[', ']');
}
template <typename T>
std::string getJson(const std::list<T>& c) {
	return getJsonContrat(c, '[', ']');
}
template <typename T>
std::string getJson(const std::forward_list<T>& c) {
	return getJsonContrat(c, '[', ']');
}
template <typename T>
std::string getJson(const std::initializer_list<T>& c) {
	return getJsonContrat(c, '[', ']');
}

// pair
template <typename A, typename B>
std::string getJson(const std::pair<A, B>& p) {
	return getJsonPair(p);
}

// set, multiset, unordered_set, unordered_multiset
// map, multimap, unordered_map, unordered_multimap
// tuple
template <typename K>
std::string getJson(const std::set<K>& c) {
	return getJsonContrat(c, '{', '}');
}
template <typename K>
std::string getJson(const std::multiset<K>& c) {
	return getJsonContrat(c, '{', '}');
}
template <typename K>
std::string getJson(const std::unordered_set<K>& c) {
	return getJsonContrat(c, '{', '}');
}
template <typename K>
std::string getJson(const std::unordered_multiset<K>& c) {
	return getJsonContrat(c, '{', '}');
}
template <typename K, typename V>
std::string getJson(const std::map<K, V>& m) {
	return getJsonContrat(m, '{', '}');
}
template <typename K, typename V>
std::string getJson(const std::multimap<K, V>& m) {
	return getJsonContrat(m, '{', '}');
}
template <typename K, typename V>
std::string getJson(const std::unordered_map<K, V>& m) {
	return getJsonContrat(m, '{', '}');
}
template <typename K, typename V>
std::string getJson(const std::unordered_multimap<K, V>& m) {
	return getJsonContrat(m, '{', '}');
}

// tuple
template <typename... Args>
std::string getJson(const std::tuple<Args...>& t) {
	return "{ " + JsonTuple<std::tuple_size_v<std::tuple<Args...>> - 1>()(t) + "}";
}
template <size_t N>
struct JsonTuple {
	template <typename... Args>
	std::string operator()(const std::tuple<Args...>& t) {
		return JsonTuple<N - 1>()(t) + getJson(std::get<N>(t)) + ", ";
	}
};
template <>
struct JsonTuple<0> {
	template <typename... Args>
	std::string operator()(const std::tuple<Args...>& t) {
		return getJson(std::get<0>(t)) + ", ";
	}
};

// std::is_arithmetic<T>() == std::true_type()
// other
template <typename T>
std::string getJson(const T& t) {
	return getJsonIsArith(t, std::is_arithmetic<T>());
}
template <typename T>
std::string getJsonIsArith(const T& t, std::true_type) {
	return getJsonArithmetic(t);
}
template <typename T>
std::string getJsonIsArith(const T& t, std::false_type) {
	return getJsonClass(t);
}

// Args...
template <typename... Args>
std::string getJson(const Args&... args) {
	return "[ " + getJsonArgs(args...) + "]";
}
template <typename First, typename... Args>
std::string getJsonArgs(const First& first , const Args&... args) {
	return getJson(first) + ", " + getJsonArgs(args...);
}
template <typename T>
std::string getJsonArgs(const T& t) {
	return getJson(t);
}

// class, can use GETJSON(keyName, value, keyName, value, ...) like
#define GETJSON(...) std::string getJson() const { \
	return "{" + getJsonMember(__VA_ARGS__) + "}"; \
}
template <typename First, typename... Args>
std::string getJsonMember(const std::string& key, const First& value, const Args&... args) {
	return getJsonMember(key, value) + getJsonMember(args...);
}
template <typename First>
std::string getJsonMember(const std::string& key, const First& value) {
	return key + ": " + getJson(value) + ", ";
}
