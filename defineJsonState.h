#pragma once
#include <string>
#include <vector>
#include <functional>
#include <type_traits>

template <typename T>
std::function<std::string()> getJsonState(T&& t);

template <>
std::function<std::string()> getJsonState<const char&>(const char& c);

template <>
std::function<std::string()> getJsonState<char&>(char& c);

template <>
std::function<std::string()> getJsonState<const char* &&>(const char* && str);

template <>
std::function<std::string()> getJsonState<const char*& const>(const char*& const str);

// int, float, array, pointer
template <typename T>
std::function<std::string()> getJsonState(T&& t, std::true_type, std::false_type, std::false_type);

template <typename T>
std::function<std::string()> getJsonState(T&& t, std::false_type, std::true_type, std::false_type);

template <typename T>
std::function<std::string()> getJsonState(T&& t, std::false_type, std::false_type, std::true_type);

template <typename T>
std::function<std::string()> getJsonState(T&& t, std::false_type, std::false_type, std::false_type);

// class, string, vector, deque, list, forward_list, map, set, initlizer_list
template <>
std::function<std::string()> getJsonState<const std::string&>(const std::string& str);

template <>
std::function<std::string()> getJsonState<std::string&>(std::string& str);

template <typename T>
std::function<std::string()> getJsonState(T&& t) {
	return getJsonState(
		std::forward<T>(t),
		std::is_arithmetic<std::remove_reference_t<T>>(),
		std::is_array<std::remove_reference_t<T>>(),
		std::is_pointer<std::remove_reference_t<T>>()
	);
}

// char
template <>
std::function<std::string()> getJsonState<const char&>(const char& c) {
	return [=]()->std::string {
		return '\'' + std::string({ c }) + '\'';
	};
}

template <>
std::function<std::string()> getJsonState<char&>(char& c) {
	return [=]()->std::string {
		return '\'' + std::string({ c }) + '\'';
	};
}

// char*
template <>
std::function<std::string()> getJsonState<const char* &&>(const char* && str) {
	return [=]()->std::string {
		return '\"' + std::string(str) + '\"';
	};
}

template <>
std::function<std::string()> getJsonState<const char*& const>(const char*& const str) {
	return [=]()->std::string {
		return '\"' + std::string(str) + '\"';
	};
}

// first bool_type is int or float like, second is array like, third is pointer
// int or float like type
template <typename T>
std::function<std::string()> getJsonState(T&& t, std::true_type, std::false_type, std::false_type) {
	return [=]()->std::string {
		return std::to_string(t);
	};
}

// array type
template <typename T>
std::function<std::string()> getJsonState(T&& t, std::false_type, std::true_type, std::false_type) {
	return [=]()->std::string {
		std::string str;
		str.append("[");
		for (const auto& element : t) {
			str.append(getJsonState(element)());
			str.append(", ");
		}
		str.append("]");
		return str;
	};
}

// pointer type
template <typename T>
std::function<std::string()> getJsonState(T&& t, std::false_type, std::false_type, std::true_type) {
	return [=]()->std::string {
		return "p" + std::to_string((int)t);
	};
}

// had jsonState class
template <typename T>
std::function<std::string()> getJsonState(T&& t, std::false_type, std::false_type, std::false_type) {
	return [=]()->std::string {
		return t.jsonState;
	};
}

// std::string
template <>
std::function<std::string()> getJsonState<const std::string&>(const std::string& str) {
	return [=]()->std::string {
		return '\"' + str + '\"';
	};
}

template <>
std::function<std::string()> getJsonState<std::string&>(std::string& str) {
	return [=]()->std::string {
		return '\"' + str + '\"';
	};
}


/*#include <type_traits>
template <typename First, typename... Args>
First ADD(First first, Args... args);

template <typename T>
T ADD(T t);

template <typename First, typename... Args>
First ADD(First first, Args... args) {
	return (first + ADD(args...));
}
*/
