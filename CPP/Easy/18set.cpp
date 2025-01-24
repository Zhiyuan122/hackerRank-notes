/*
set / map（基于平衡树，使用双向迭代器）
一种 有序集合（ordered set），它的主要特点包括：

1.存储唯一元素（不允许重复值）。
2.自动排序（默认升序存储，使用 std::less 比较）。
3.基于平衡二叉搜索树（如红黑树）实现，查找、插入、删除的时间复杂度为 O(log n)。
4.不支持随机访问（必须使用迭代器）。
set<int> s = {1, 2, 3};


对比之下
vector
动态数组（dynamic array）
1.可以存储重复元素。
2. 连续存储在内存中，支持随机访问（O(1) 时间复杂度）。
3. 插入和删除：
    在末尾插入或删除的时间复杂度为 O(1)。
    在中间插入或删除需要移动元素，时间复杂度为 O(n)。
    自动扩容机制，当容量不足时，会重新分配更大的内存。
vector<int> v = {1, 3, 5, 3};

array
静态数组（static array）
1. 大小在编译时确定，不能动态调整。
2. 内存布局与普通 C 数组类似，支持随机访问（O(1）时间复杂度）。
3. 性能优于 vector，没有动态分配的开销。
array<int, 3> arr = {10, 20, 30};



特性	std::set	std::vector	std::array
存储类型	唯一、有序	可重复、无序	固定大小、无序
底层实现	平衡二叉搜索树（红黑树）	动态数组	静态数组
时间复杂度	插入/删除/查找 O(log n)	访问 O(1)，插入/删除 O(n)	访问 O(1)，无扩展能力
随机访问	不支持	支持	支持
插入性能	较慢（自动排序，O(log n)）	末尾插入快 O(1)	无插入操作，仅初始化
空间效率	较高（存储树结构）	适中（动态扩展）	最优（无额外开销）
适用场景	唯一元素、去重、有序存储	动态数据存储	固定大小数据

何时使用哪种容器？
使用 set：
需要存储唯一、自动排序的数据（如排行榜、字典、集合操作）。
查找、删除操作频繁。

使用 vector：
需要快速随机访问。
元素会频繁增加、删除（尤其是在尾部）。

使用 array：
数据大小固定，且需要最高性能。
用于栈分配数据，避免堆分配的开销。


---------------------------------------------------------------------------------
常见操作
set<int> s; // 创建一个整数集合，存储唯一元素，默认升序
set<int, greater<int>> s;  // 创建一个降序集合
set<int> s = {1, 2, 3};  // 创建并初始化集合

int len = s.size();  // 获取集合大小
s.insert(4);  // 插入元素 4,，若已存在，不会重复存储

查找元素：
set<int>::iterator it = s.find(3);  // 查找元素 3
if (it != s.end()) {
    cout << "Found";
} else {
    cout << "Not found";
}

遍历集合
for (auto it = s.begin(); it != s.end(); it++) {
    cout << *it << " ";
}

删除元素
s.erase(3);  // 删除元素 3
s.clear();  // 清空集合

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int q;
    cin >> q;
    set<int> s;

    while (q--)
    {
        int type, x;
        cin >> type >> x;

        if (type == 1)
        {
            s.insert(x);
        }
        if (type == 2)
        {
            s.erase(x);
        }
        if (type == 3)
        {
            set<int>::iterator it = s.find(x); // auto it = s.find(x);
            if (it != s.end())
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}

/*
set<int>::iterator it = s.find(x);
iterator 不是一个独立的类型，而是 set<int> 类型的内部类型，因此必须使用 作用域解析符 来指定其作用域。

why 使用using namespace std; 也不能省略 set<int>::iterator
因为using namespace std; 只导入标准库的命名空间，而不导入 set<int> 的命名空间。
1. 它可以让你直接使用 cin、cout 等，但 iterator 只是一个通用的术语，不是一个独立的类型，它必须与某个容器相关联。
2. C++ 标准库中不同容器（如 vector、set、map 等）都有各自的 iterator 类型，编译器需要知道你指的具体是哪种迭代器。

如果你希望使用更简洁的写法，可以使用 auto 关键字，C++11 之后引入：
auto it = s.find(x);
这样，编译器会自动推断 it 的类型，避免手动写 set<int>::iterator



为什么需要 set<int>::iterator？
因为 C++ STL 容器（如 set、vector、map 等）都有自己的内部迭代器类型。
例如：
vector<int>::iterator
set<int>::iterator
map<int, string>::iterator


*/
