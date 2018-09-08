#pragma once
#include <string>
#include "getJsonType.h"

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

template <typename T>
std::string getJson(const T& t);

// 
template <typename T>
std::string getJson(const T& t) {
	return "default getJson";
}

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
