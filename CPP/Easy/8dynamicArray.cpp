/*
动态数组----指在运行时，根据用户输入动态分配大小的数组
vector<int> arr;

vector<vector<int>> arr(n);
会初始化一个大小为 n 的顶层 vector。
也就是说，arr 是一个包含 n 行的二维数组，每行默认是空的 vector<int>。






*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// n：是二维数组有几行
// k:每一行的数组有几个元素
// q:是查询的次数
// i:是顶层数组的索引，表示要查询的数组是哪一行。
// j:是某一行数组中的索引，表示要查询的具体元素。
//  输入格式：
//  n q          // n 是二维数组的行数，q 是查询的次数
//  k1 a[1][0] a[1][1] ... a[1][k1-1]   // 第一行数组的长度和元素
//  k2 a[2][0] a[2][1] ... a[2][k2-1]   // 第二行数组的长度和元素
//  ...
//  kn a[n][0] a[n][1] ... a[n][kn-1]   // 第 n 行数组的长度和元素
//  i1 j1       // 第 1 次查询，i1 是数组索引，j1 是数组内的索引
//  i2 j2       // 第 2 次查询
//  ...
//  iq jq       // 第 q 次查询
/*
如果你直接通过索引访问 arr[i][j]
当你使用 arr[i][j] 来直接访问数组元素时，resize 是必须的。
因为未初始化的 vector（例如 arr[i]）是空的，直接访问会导致 运行时错误


*/

int main()
{
    int n, q;
    cin >> n >> q;

    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        arr[i].resize(k);

        for (int j = 0; j < k; j++)
        {
            cin >> arr[i][j];
        }
    }

    // query
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << arr[x][y] << endl;
    }

    return 0;
}