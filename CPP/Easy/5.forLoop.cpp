/*
for (initialization; condition; increment) {
    // Code to execute in each iteration
}

奇偶性判断
通过取模运算符 % 判断一个整数是奇数还是偶数：
除以2的余数
偶数：n % 2 == 0
奇数：n % 2 != 0

*/

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a, b;
    // 错误写法：cin >> a,b;
    cin >> a >> b;
    string array[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for (int n = a; n <= b; n++)
    {
        if (n >= 1 && n <= 9)
        {
            cout << array[n] << endl;
        }
        else if (n > 9 && n % 2 == 0)
        {
            cout << "even" << endl;
        }
        else
        {
            cout << "odd" << endl;
        }
    }
    return 0;
}