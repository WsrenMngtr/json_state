// json_state.cpp: 定义控制台应用程序的入口点。

#include "stdafx.h"
#include "defineJsonState.h"
#include <cstdio>
#include <iostream>
#include <type_traits>
#include <string>

using namespace std;

int main() {
	int ia[4] = { 1, 2, 3, 4 };
	string str = "THIS IS STRING";
	char ac[10] = "c-style";
	
	cout << getJsonState(44)() << '\n';
	cout << getJsonState(55L)() << "L" << '\n';
	cout << getJsonState(67.8)() << '\n';
	cout << getJsonState(ia)() << '\n';
	cout << getJsonState(ac)() << '\n';
	cout << getJsonState(str)() << '\n';

    return 0;
}

