#pragma once
#include <string>

#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <initializer_list>

#include "getJsonType.h"

//
template <typename T>
std::string getJson(const T& t);

// getJsonChar
template <>
std::string getJson(const char& c);

// getJsonStr
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

//---------------------------------------

// getJsonChar
template <>
std::string getJson(const char& c) {
	return getJsonChar(c);
}

// getJsonStr
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
std::string getJson(T(&c)[N]) {
	return getJsonList(c);
}

template <typename T>
std::string getJson(const std::vector<T>& c) {
	return getJsonList(c);
}

template <typename T>
std::string getJson(const std::deque<T>& c) {
	return getJsonList(c);
}

template <typename T>
std::string getJson(const std::list<T>& c) {
	return getJsonList(c);
}

template <typename T>
std::string getJson(const std::forward_list<T>& c) {
	return getJsonList(c);
}

template <typename T>
std::string getJson(const std::initializer_list<T>& c) {
	return getJsonList(c);
}

// 
template <typename T>
std::string getJson(const T& t) {
	return "default getJson";
}