#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a, b, c;
    int sum;

    // sum = a+b+c;
    // sum 如果在这里，就会导致局部变量 a, b, c, sum未显式初始化计算出的 sum 是不可预测的值，可能是内存中的随机数
    // 也可以直接cout << (a+b+c)<< endl;

    cin >> a >> b >> c;
    sum = a + b + c;
    cout << sum << endl;
    cout << a + b + c << endl;

    return 0;
}
/*
cin 从标准输入读取数据，遇到空格或换行符时会停止读取。
endl：向标准输出添加换行符，并刷新缓冲区。
\n：添加换行符，但不刷新缓冲区（性能稍优于 endl）

输入多种类型：
在更复杂的场景下，可以结合 getline 或 stringstream 来处理多行输入。




*/
