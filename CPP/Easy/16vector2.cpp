/*
v.erase()
单个元素删除
v.erase(v.begin() + index);
v.begin() 返回 vector 的起始位置，v.begin() + index 指向要删除的元素。
注意：索引是 0-based，而输入可能是 1-based，因此要手动调整。

范围删除
v.erase(v.begin() + start, v.begin() + end);
删除 [start, end) 范围内的元素，起始位置包含，结束位置不包含。
需要将 1-based 输入转换为 0-based 索引。

erase 需要一个迭代器作为参数，而不是直接传入整数索引
v.erase(v.begin() + 6);

 vector 容器中，删除元素后，后续元素会整体前移，以保持连续的存储结构。vector 是基于动态数组实现的，因此删除一个元素后，会将其后面的所有元素向前移动，以填补被删除元素的位置。

C++ erase 的特性是区间的第二个参数是开区间，即不包括 b
 inclusive of a and exclusive of b.

*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*

解析
输入 6 个元素 1 4 6 2 8 9

删除第 2 个元素，结果为 1 6 2 8 9
v.erase(v.begin() + x - 1);

删除 [2,4) 范围，即第 2 和 3 个元素，结果为 1 8 9
v.begin() + a - 1, v.begin() + b - 1

输出 3 以及 1 8 9

*/

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int a, b, x;
    cin >> x;
    v.erase(v.begin() + x - 1);

    cin >> a >> b;
    v.erase(v.begin() + a - 1, v.begin() + b - 1);

    cout << v.size() << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}
