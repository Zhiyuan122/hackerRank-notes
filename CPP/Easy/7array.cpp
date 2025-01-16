/*
 Array---相同类型数据 的集合，这些数据在内存中是 连续存储 的
特点
1. 固定大小：定义数组时，必须指定大小（除非使用动态分配）。
2. 连续内存：元素在内存中是连续存储的，这使得通过索引访问元素非常高效。
3. 相同类型：所有元素类型必须相同，例如整数数组只能存储整数。

静态数组的定义
定义一个大小为 10 的整数数组：int arr[10];
定义并初始化数组：int arr[5] = {1, 2, 3, 4, 5};  // 初始化为 1, 2, 3, 4, 5

动态数组的定义（C++ 特性）会在栈上分配内存
int n;
cin >> n;
int arr[n];

数组初始化
如果没有初始化，数组中的值是未定义的（随机垃圾值）
int arr[5] = {0};  // 所有元素初始化为 0

3. 数组的访问和操作
访问数组元素：arr[0] 第一个，arr[n-1] 最后一个
数组索引访问非常快，因为它基于指针偏移：arr[i] 等价于 *(arr + i)

遍历数组：for (int i= 0，i<n, i++){}
         for(int i = n, i>=0, i--){}

  最值：int MAX = arr[0];
       for (int i = 0, i<n. i++){
                if(MAX < arr[i]) Max = arr[i];
        }


*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 如果return，该返回什么值
// 或者不return直接修改原数组
// void reverse()

int main()
{

    int n;
    cin >> n;
    int arr[n];

    // Q：往一个数组里输入一串数字
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
        // if (i < n - 1) cout << " ";仅在不是最后一个元素时添加空格
    }
    return 0;
}
/*
solu:
A)数组：正序输入+逆序输出
        逆序输入+正序输出
B）STACK

#include<iostream>
#include<stack>
using namespace std;

int main(){
    int n;
    cin >> n;
    stack<int> s;

    for(int i = 0 ; i<n ; i++){
        int num;
        cin >> num;
        s.push(num);
    }

    while (!s.empty()){
        cout << s.top() << " " ;
        s.pop();
    }



return 0;
}

如果用栈去做，并且想把主函数的操作单独拎出来成一个函数的时候
void pushElements(stack<int>& s, int n) // 相当于直接修改栈
这样能避免拷贝，提升性能 如果不使用引用，而直接传递 stack<int>，会创建 stack 的副本。
创建副本的代价：
栈可能包含大量的数据，复制整个栈会消耗额外的时间和内存。
复制的栈与原始栈无关，函数对副本的操作不会影响原始栈。

也可以使用全局栈
如果栈在整个程序中都会被多次使用，可以将栈定义为全局变量，函数只操作全局栈
stack<int> s;
void pushStack(int n){};
void popStack(){};




*/

/*
对于数组，普通数组不能直接作为返回值，可以通过指针、引用参数或 STL 容器间接实现
(1) 返回指针
函数可以返回数组的起始地址（指针），通过动态内存分配解决数组的生命周期问题。

int* getArray(){
    int* arr = new int[5];
    return arr;
}
还可以returnSTL容器，这个之后讲


*/
