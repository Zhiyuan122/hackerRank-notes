/*
stringstream
 C++ 标准库中的一个流类，专门用于操作字符串。
类似于 cin/cout，但它的输入/输出对象是字符串，而不是标准输入/输出设备。
#include <sstream>

<<	向 stringstream 中插入数据（类似 cout）。
>>	从 stringstream 中提取数据（类似 cin）。
str()	获取当前流中的字符串内容。
str(string)	设置新的字符串内容。

如果字符串包含非数字字符，stringstream 会停止解析，剩余部分不会被存入向量。

stringstream ss(str);作用是将字符串 str 转换为一个可读的输入流，类似于标准输入 cin。
之后可以通过 >> 运算符提取数据。
stringstream 的构造函数，使用字符串 str 初始化流对象 ss。
ss 现在包含 str 的内容，并可以像 cin 一样使用提取运算符 >> 进行解析。
string str = "100 200 300";
stringstream ss(str);

int a,b,c;
ss >> a >> b >> c;
cout << a << " " << b << " " << c << endl;
// 输出：100 200 300

stringstream 本质上是一个流对象Stream object
它的行为类似于标准输入流（cin）或输出流（cout），
但它操作的对象是内存中的字符串，而不是键盘或屏幕。
一个**“存放字符串的缓冲区”**，你可以从这个缓冲区读取数据或向其写入数据。
+---------------------------+
|  "23,4,56" (字符串缓冲区)  |  <-- ss 流对象内部存储的字符串
+---------------------------+
             ↑
             |   读取操作（>>）
             |
         --------
         |  23  |  <-- 第一次提取
         --------
             ↑
         --------
         |  ,4  |  <-- 第二次提取时跳过 `,` 读取 `4`
         --------
             ↑
         --------
         |  ,56 |  <-- 第三次提取
         --------

stream 一种用于输入和输出数据的抽象概念
提供了一种连续传输数据的方式。流本质上是一种**“数据流动的渠道”**
可以将数据从一个地方流向另一个地方（如从键盘到程序，或从程序到屏幕、文件等）

C++ 提供了一系列流对象，它们是类的实例（对象），用于处理不同的输入/输出操作。例如：

流对象	        作用	        头文件
cin	标准输入（用于从键盘读取数据）	<iostream>
cout	标准输出（控制台屏幕输出）	<iostream>
cerr	标准错误输出（立即输出错误信息）	<iostream>
clog	标准错误输出（缓冲输出错误信息）	<iostream>

ifstream	文件输入流（从文件读取数据）	<fstream>
ofstream	文件输出流（写入数据到文件）	<fstream>
fstream	文件输入/输出流（读取和写入文件）	<fstream>

stringstream	字符串流（操作内存字符串）	<sstream>
istringstream	输入字符串流（从字符串读取数据）	<sstream>
ostringstream	输出字符串流（写入数据到字符串）	<sstream>

流的特性
流对象（如 cin、cout）具有以下特点：

面向字节：按字节或字符操作的，数据可以是一系列的字符、数字或二进制数据。
顺序访问：流通常是顺序访问的，例如从文件头到文件尾。
缓冲机制：流通常具有缓冲区（cin 读取数据之前会缓存输入）。
状态管理：流对象可以检测读取或写入状态，如 eof()（是否到达文件末尾）等。

cin、cout 与 stringstream 的区别
功能	cin/cout	stringstream
数据来源	键盘输入/屏幕输出	字符串（内存）
适用场景	直接交互、用户输入/输出	处理和解析字符串
输入运算符	cin >> var;	ss >> var;
输出运算符	cout << var;	ss << var;
主要用途	实时数据处理	字符串数据的处理和解析


*/

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<int> parseInts(str)
{
    stringstream ss(string str); // 创建 stringstream 流
    vector<int> result;          // 存储解析出的整数
    int num;
    char ch;

    while (ss >> num)
    {                          // 只要 stringstream 成功提取数字
        result.push_back(num); // 将数字存入 vector
        ss >> ch;              // 跳过逗号
    }
    return result;
}
/*
成功从字符串中提取一个整数并存入变量 num 时，条件返回true，继续循环；
如果提取失败（如遇到非数字字符或流结束），条件返回 false，
*/

int main()
{
    string str;
    cin >> str;

    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++)
    {
        cout << integers[i] << "\n";
    }

    return 0;
}
