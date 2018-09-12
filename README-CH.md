# 获得一个对象的JSON格式的工具

## 包含getJson.h文件获得组件
```c++
#include "getJson.h"
```
## 对于任何对象，使用getJson(object)
对象作为参数直接传入即可，并且支持可变参数，可变参数会被组合成列表
```c++
int i = 109;
double d = 17.7;
std::string s = "string";
getJson(i); // 109
getJson(d, s); // [ 17.700000, "string", ]
```
支持的类型：
全部的数字类型，字符，逻辑，字符指针/数组，数组，std::string
std的所有容器类，initlizer_list，pair，tuple
如果不是上述之一，那么就调用对象的getJson()成员函数或直接特化
## 对于class/struct对象，使用GETJSON宏定义getJson成员或完全定制
可以采用GETJSON宏建立通用格式
在其中使用GETJSON宏可以定制这个类想要加入json的成员
前提是加入的成员都能够被getJson(value)使用
如果对自动生成的效果不满意，可以完全自定义getJson
```c++
struct Man {
    std::string name;
    int age;
    GETJSON("name", name, "age", age)
};
Man man("Jhon Sms", 17);
man.getJson() // { name: "Jhon Sms", age: 17, }
// 你没有列入参数的成员不会被加入json
struct Man {
    std::string name;
    int age;
    GETJSON("name", name)
};
Man man("Jhon Sms", 17);
man.getJson() // { name: "Jhon Sms", }
// 完全自定义
struct Man {
    std::string firstName;
    std::string lastName;
    int age;
    std::string getJson() const {
	return "{ name: " + ::getJson(firstName + "-" + lastName) +
	    ", age: " + ::getJson(age) + "}";
	}
};
Man man("Jhon", "Sms", 17);
man.getJson() // { name: "Jhon-Sms", age: 17, }
```
注意，上面的例子并不能写成这样
```c++
// 这会导致getJson(object)的值未初始化并且和对象的值不关联
GETJSON("name", getJson(firstName + "-" + lastName), "age", age)
```
## 对于不想或者不能添加成员的类型，通过特化来定制
以std::wstring为例，假设已经存在一个wstring向string转换的函数wstr2str
```c++
template <>
std::string getJson(const std::wtring& wstr) {
    return "w" + getJson(wstr2str(wstr));
}
std::wstring wstr = L"this is wstr!";
getJson(wstr); // w"this is wstr!"
```
## 转换标准表
|c++|JSON|
|----|----|
|数字类型、bool|本身|
|字符|'内容'|
|字符指针、字符数组、std::string|"内容"|
|非字符数组、顺序容器|[ 元素1, 元素2, ..., ]|
|set及其三种拓展|{ 元素1, 元素2, ..., }|
|map及其三种拓展|{ key1: value1, key2: value2, ..., }|
|std::pair|first: second|
|std::tuple|{ 元素1, 元素2, ..., }|
|可变参数|[ 参数1, 参数2, ..., ]|
|存在std::string getJson()的类型|value.getJson()|
|存在模板特化的类型|getJson(value)|
