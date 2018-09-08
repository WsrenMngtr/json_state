# JSON STATE 解决方案规划
## 原始算法
```c++
template <typename T>
std::string getJson(const T& t);

// std::is_arithmetic<T>() == std::true_type()
std::string str = std::to_string(a);

// char*, const char*, char* const, const char* const
// char[], const char[]
// std::string
std::string str = std::string(str)

// T* but not char*
std::string str = 'p' + std::to_string((int)p);

// T[], const T[] but not char[]
// vector, deque, list, forward_list, initlizer_list
std::string str;
str.append("[");
for (const T& element: array) {
    str.append(getJson(element));
    str.append(", ");
}
str.append("]");

// set,... 

// map,...

// others
std::string str = t.getJson
```