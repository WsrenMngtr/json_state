// json_state.cpp: 定义控制台应用程序的入口点。

#include "stdafx.h"
#include "getJsonType.h"
#include "getJson.h"
#include <iostream>

#include <string>

#include <vector>
#include <list>
#include <deque>
#include <forward_list>

using namespace std;

int main() {
	int ia[4] = { 1, 2, 3, 4 };
	double ba[3] = { 1, 2.2 };
	string str = "THIS IS STRING";
	char ac[10] = "c-style";
	vector<char> vi = { 'v', 'e', 'c', 't', 'o', 'r' };
	
	cout << "int: " << getJsonArithmetic(44) << '\n';
	cout << "int&: " << getJsonArithmetic(ia[0]) << '\n';
	cout << "long: " << getJsonArithmetic(55L) << "L" << '\n';
	cout << "double: " << getJsonArithmetic(67.8) << '\n';
	cout << "double&: " << getJsonArithmetic(ba[0]) << '\n';
	cout << "int[]: " << getJsonList(ia) << '\n';
	cout << "vector<>: " << getJsonList(vi) << '\n';
	//cout << getJsonList({"a", "HE"}) << '\n'; ???
	cout << "int*: " << getJsonPointer(&ia[0]) << '\n';
	cout << "char[]: " << getJson(ac) << '\n';
	cout << "string: " << getJson(str) << '\n';
	cout << "char*: " << getJson(&ac[0]) << '\n';
	cout << "const char[]: " << getJson("c-style-constexpr") << '\n';

    return 0;
}

