// json_state.cpp: 定义控制台应用程序的入口点。

#include "stdafx.h"
#include "getJsonType.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int ia[4] = { 1, 2, 3, 4 };
	string str = "THIS IS STRING";
	char ac[10] = "c-style";
	vector<int> vi = { 1, 4, 5, 6 };

	cout << getJsonArithmetic(44) << '\n';
	cout << getJsonArithmetic(55L) << "L" << '\n';
	cout << getJsonArithmetic(67.8) << '\n';
	cout << getJsonList(ia) << '\n';
	cout << getJsonList(vi) << '\n';
	cout << getJsonPointer(&ia[0]) << '\n';
	cout << getJsonStr(ac) << '\n';
	cout << getJsonStr(str) << '\n';
	cout << getJsonStr(&ac[0]) << '\n';
	cout << getJsonStr("c-style-constexpr") << '\n';

    return 0;
}

