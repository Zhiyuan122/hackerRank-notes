/*
map 是 C++ 标准库中的 关联容器（associative container），
提供 键值对（key-value pair） 的存储方式，支持高效的查找、插入和删除操作，键（key）是唯一的，自动按照键排序。
特点：
map 内部自动按照键排序，支持快速查找、插入和删除操作。
map 的键是唯一的，如果插入一个已经存在的键，会覆盖原有的值。
map 是基于红黑树（Red-Black Tree）实现的，时间复杂度为 O(logN)。
map 的迭代器是双向迭代器，支持正向和反向遍历。
map 的键和值可以是任意类型，如 int、string、自定义类等。
map 的键和值是一一对应的，不能通过键直接修改值，只能通过迭代器遍历修改。

基本操作：声明 插入 查找 删除
map<string, int> m;  // 创建一个键类型为 string，值类型为 int 的 map

m["Alice"] = 90;                // 直接赋值方式
m.insert(make_pair("Bob", 85));  // 使用 make_pair 插入
m["Alice"] = 95;                // 修改值

需要引号的情况：键是字符串常量（直接输入 "Alice"）。
不需要引号的情况：键是变量或非字符串类型（如 int）。
string key = "Alice";
m[key] = 100;  // 这里不需要引号，因为 key 变量已存储字符串

m["Bob"] = 90;  // 正确，键是字符串，需要双引号



m.erase("Bob");                 // 删除键为 Bob 的元素
删除操作会同时删除 key 和 value。
map 的元素是由 key-value 组成的，当删除键（key）时，整个键值对都会被移除，无法仅删除 key 或 value 的一部分。

if (m.find("Alice") != m.end()) {
    cout << "Alice 的分数：" << m["Alice"] << endl;
} else {
    cout << "Alice 不存在" << endl;
}
不能直接写m.erase(m.find("Bob"))，因为会导致重复查找。




删除指定迭代器指向的元素
auto it = m.find("Bob");
if (it != m.end()) {
    m.erase(it);  // 删除指向 "Bob" 的迭代器
}


map 的迭代器是一个指向 pair<const Key, Value> 的对象
迭代器特点
1. 遍历的顺序是始终按照key 递增排序的 不能改变遍历顺序。
2. 迭代器的解引用返回的是 pair<const Key, Value>，Key 是 const 类型，不能修改。
3. 通过 iterator->first 访问 key，iterator->second 访问 value
4. 不能修改 key，只能修改 value
    it->first = "Dave";  // ❌ 错误：key 是 const 类型，不可修改
    it->second = 100;    // ✅ 正确：可以修改 value

删除迭代器指向的元素时要小心
auto it = studentMarks.begin();
while (it != studentMarks.end()) {
    if (it->second < 80) {
        it = studentMarks.erase(it);  // 删除后，返回指向下一个元素的迭代器
    } else {
        ++it;
    }
}


*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int q;
    cin >> q;

    map<string, int> m;

    while (q--)
    {
        int type, y;
        string x;
        cin >> type >> x;

        if (type == 1)
        {
            cin >> y;
            // m["x"] = m["x"] + y;}修正这里，使用变量 x 而不是字符串 "x"
            m[x] += y;
        }

        if (type == 2)
        {
            m.erase(x);
        }
        if (type == 3)
        {
            // auto it = m.find("x");
            if (m.find(x) != m.end())
            {
                cout << m[x] << endl;
            }
            else
            {
                cout << "0" << endl;
            }
        }
    }

    return 0;