/*
vector 动态数组，支持自动扩展，可以存储一组同类型的数据，常用于需要灵活调整大小的场景
vector<int> v;// 创建一个空的整数向量
vector<int> v(5); // 创建大小为5的整数向量，元素默认初始化为0
vector<int> v = {1,2,3,4,5};使用列表初始化

1.2 常用操作
操作	代码示例	说明
获取大小	v.size();	返回 vector 的元素个数
添加元素	v.push_back(x);	在末尾添加元素，大小+1
删除最后一个元素	v.pop_back();	删除末尾元素，大小-1
访问元素（索引）	v[i];	访问 vector 中的元素，0-based 索引
清空所有元素	v.clear();	清空 vector 中的所有元素
插入元素	v.insert(v.begin() + i, x);	在第 i 个位置插入元素 x

2. sort 函数
sort 函数用于对可排序的容器（如 vector、array）进行排序，默认按升序排列
sort(v.begin(), v.end());
sort(v.begin(), v.end(), greater<int>());
v.begin()：指向 vector 开头的迭代器。
v.end()：指向 vector 末尾后一个位置的迭代器。
greater<int>()：指定按降序排列。

最坏情况下的时间复杂度为 O(n log n)，使用的是**快速排序（QuickSort）**的变种。

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> integers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> integers[i];
    }

    sort(integers.begin(), integers.end());

    for (int i = 0; i < n; i++)
    {
        cout << integers[i] << " ";
    }

    return 0;
}
/*
在一整行输入完成后再处理数字，而不是逐个读取，可以使用 getline + stringstream：

int main (){
    int n;
    cin >> n;

    string line;
    getline(cin,line);//整行输入后一次性拆解存入向量
    cin.ignore();// 确保这里忽略换行符，不然输入回车之后下面就会读不到数据，从而整个vector都是空的

    vector<int> v;
    stringstream ss(line); // 将整行输入转换为流对象
    int num;// 临时变量用于存储解析出的数字

    while(ss >> num){// 只要还能从流中提取整数
        v.push_back(num); // 将提取的整数存入向量
    }

    for (int i = 0; i < n; i++){
        cout<< v[i]<<" ";
    }
    return 0;




}


*/