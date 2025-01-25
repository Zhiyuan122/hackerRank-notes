/*
#include <string>

string a = "123";
string b = "def";
int len = a.size(); // 3
.size() 和 .length() 在 C++ 标准库中是等效的，

字符串拼接（Concatenation）
可以使用 + 运算符将两个字符串连接在一起

 访问和修改字符串中的字符（Accessing elements）
C++ 字符串支持使用下标 [] 访问和修改特定字符。
string s = "abc";
char firstChar = s[0];  // 取出第一个字符 'a'
s[0] = 'z';  // 修改字符串，变为 "zbc"

5. 读取和输出字符串
(1) cin 读取单个字符串（不包含空格）
string s;
cin >> s;
cout << s;
//input: hello world
//output: hello

(2) getline 读取一行字符串（包含空格）
string s;
getling(cin, s);
cout << s;
//input: hello world
//output: hello world

(3) cout 输出字符串 
string s = "hello";
cout << s;
//output: hello

(4) 字符串连接  
string a = "hello";
string b = "world";
string c = a + b;
cout << c;
//output: helloworld

(5) 字符串长度
string s = "hello";
int len = s.size(); // 5
//或者
int len = s.length(); // 5

(6) 字符串遍历
string s = "hello";
for (int i = 0; i < s.size(); i++)
{
    cout << s[i] << endl;
}
//output: h e l l o

(7) 字符串查找  
string s = "hello";
int pos = s.find("l"); // 2
//或者
int pos = s.find("l", 3); // 3
//或者

int pos = s.find("l", 3, 1); // 3
//或者
int pos = s.find("l", 3, 2); // -1

(8) 字符串截取
string s = "hello";
string sub = s.substr(2); // "llo"
//或者
string sub = s.substr(2, 2); // "ll"

(9) 字符串替换
string s = "hello";
s.replace(2, 3, "123"); // "he123o"

(10) 字符串插入
string s = "hello";

*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a, b, c;
    cin >> a >> b;

    cout << a.size() << " " << b.size() << endl;
    c = a + b;

    cout << c << endl;

    // 交换两元素常用逻辑
    char temp = a[0];
    a[0] = b[0];
    b[0] = temp;

    cout << a << " " << b << endl;
    return 0;
}