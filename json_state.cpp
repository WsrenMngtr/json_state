// json_state.cpp: 定义控制台应用程序的入口点。

#include "stdafx.h"
#include "getJson.h"
#include <iostream>

using namespace std;

struct Test {
	std::string name;
	int age;
	function<string()> getJson = getJsonByMember("name", name, "age", age);
};

int main() {
	int ia[4] = { 1, 2, 3, 4 };
	double ba[3] = { 1, 2.2 };
	string str = "THIS IS STRING";
	char ac[10] = "c-style";
	vector<char> vc = { 'v', 'e', 'c', 't', 'o', 'r' };
	const deque<char> cdc = { 'd', 'e', 'q', 'u', 'e' };
	set<char> sc = { 's', 'e', 't' };
	map<int, string> mis = {
		{1, "one"},
		{2, "two"},
	};
	Test man{ "Jack Mao", 17 };
	auto tidc = make_tuple(17, 0.2, 'c');

	cout << "int: " << getJson(44) << '\n';
	cout << "int&: " << getJson(ia[0]) << '\n';
	cout << "long: " << getJson(55L) << "L" << '\n';
	cout << "double: " << getJson(67.8) << '\n';
	cout << "bool: " << getJson(false) << '\n';
	cout << "double&: " << getJson(ba[0]) << '\n';
	cout << "int[]: " << getJson(ia) << '\n';
	cout << "vector<>: " << getJson(vc) << '\n';
	cout << "const deque<>: " << getJson(cdc) << '\n';
	cout << "set<>: " << getJson(sc) << '\n';
	cout << "map<>: " << getJson(mis) << '\n';
	cout << "int, char, const char[], bool: "
		<< getJson(3, 'a', "af", true) << '\n';
	cout << "tuple<>: " << getJson(tidc) << '\n';

	//cout << getJsonList({'i', 'n', 'i', 't'}) << '\n';
	//cout << "int*: " << getJsonPointer(&ia[0]) << '\n';
	cout << "char[]: " << getJson(ac) << '\n';
	cout << "string: " << getJson(str) << '\n';
	cout << "char*: " << getJson(&ac[0]) << '\n';
	cout << "const char[]: " << getJson("c-style-constexpr") << '\n';
	cout << "class: " << getJson(man) << '\n';
    return 0;
}
