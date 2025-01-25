/*
使用 vector<int> 来存储多个考试分数
vector<int> v;
v.push_back(10);  // 添加元素 10 到 v 的末尾
cout << v[0];  // 输出第一个元素
int sum = accumulate(v.begin(),v.end(),0); // 求和)

*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class Student
{
private:
    int s1, s2, s3, s4, s5;

public:
    void input()
    {
        cin >> s1 >> s2 >> s3 >> s4 >> s5;
    }
    int calculateTotalScore()
    {
        return s1 + s2 + s3 + s4 + s5;
    }
};

int main()
{
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students

    for (int i = 0; i < n; i++)
    {
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        int total = s[i].calculateTotalScore();
        if (total > kristen_score)
        {
            count++;
        }
    }

    // print result
    cout << count;

    return 0;
}

/*
class Box{
    private:
        int arrtibute1;
        int attribute2;

    public:
        Box() {length = breadth = height = 0;} // default constructor
        Box(int l, int b, int h) {length = l; breadth = b; height = h;} // parameterized constructor
        Box(int l, int b, int h) : length(l), breadth(b), height(h) {} // parameterized constructor
（手动赋值）：
在构造函数的函数体内部赋值。。
每次调用构造函数时，先调用默认构造函数（隐式），再手动赋值。
第二种（初始化列表）：
在初始化列表中直接初始化成员变量。
更高效，避免额外的默认初始化，直接赋值，提高性能。
        Box(const Box &B) {length = B.length; breadth = B.breadth; height = B.height;} // copy constructor


}

2. 构造函数是一种特殊的成员函数，在创建对象时自动调用：

默认构造函数： 无参数，初始化默认值。
参数化构造函数： 允许在创建对象时初始化成员变量。
拷贝构造函数： 用一个对象初始化另一个对象。

(3) 运算符重载
C++ 允许重载运算符，使自定义类支持标准操作。例如：

重载 < 运算符： 让 Box 可以比较大小。
重载 << 运算符： 让 Box 可以直接输出到 cout

在重载 < 运算符时使用 const 修饰符
bool operator<(const Box& other) const {
    if (length < other.length) return true;
    if (breadth < other.breadth && length == other.length) return true;
    if (height < other.height && breadth == other.breadth && length == other.length) return true;
    return false;
}

const Box& other：
other 是传入的比较对象，使用 引用 & 避免不必要的拷贝，提高效率。
const 保证 other 不能被修改，确保只读访问

const 作用在函数末尾：
表示此函数不会修改调用它的对象。
即：this 指针变为 const Box*，保证不会修改当前 Box 实例。

上面相当于重新定义了一个比较逻辑，
bool compare(Box a, Box b) {
    if (a.length < b.length) return true;
    if (a.length == b.length && a.breadth < b.breadth) return true;
    if (a.length == b.length && a.breadth == b.breadth && a.height < b.height) return true;
    return false;
}




<< 运算符要加 friend 关键字!!!
friend ostream& operator<<(ostream& out, const Box& B) {
    out << B.length << " " << B.breadth << " " << B.height;
    return out;
}
重载了 << 运算符，使得我们可以用 cout 直接输出 Box 对象，而不需要手动调用 get 方法
Box b(2, 3, 4);
cout << b << endl;  // 输出: 2 3 4

ostream& out：
该参数表示输出流（例如 cout）。
使用引用 &，避免创建新的 ostream 实例。

const Box& B：
表示要输出的 Box 对象。
使用 const 避免修改 B。

假设不使用运算符重载，输出 Box 类可能会这样写：
void printBox(Box b) {
    cout << b.getLength() << " " << b.getBreadth() << " " << b.getHeight();
}
printBox(b);  // 输出: 2 3 4
但通过运算符重载，代码简化为：
Box b(2, 3, 4);
cout << b << endl;
运算符重载使代码更简洁，更易读。

为什么需要 friend？ → 访问私有成员。
为什么使用 &？ → 避免不必要的拷贝，提高性能。
为什么使用 const？ → 确保对象不被修改。

重载 << 运算符的常见模式：
friend ostream& operator<<(ostream& out, const ClassName& obj) {
    out << obj.property1 << " " << obj.property2;
    return out;
}
重载 < 运算符的常见模式：
bool operator<(const ClassName& other) const {
    return this->property < other.property;
}

// 重载 == 运算符 (判断类对象是否相等)
bool operator==(const ClassName& other) const {
    return this->property == other.property;
}









(4) 友元函数
友元函数是类的友元，可以访问类的私有成员。友元函数可以是普通函数、成员函数或其他类的成员函数。
#include <iostream>
using namespace std;

class Point {
private:
    int x, y;
public:
    Point(int x, int y) : x(x), y(y) {}

    // 在类内部声明友元函数
    friend ostream& operator<<(ostream& out, const Point& p);
};

// 在类外定义运算符函数（具体逻辑）
ostream& operator<<(ostream& out, const Point& p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

int main() {
    Point p1(2, 3);
    cout << p1 << endl;  // 输出: (2, 3)
    return 0;
}

在类内声明的原因：

让编译器知道类支持 << 运算符。
通过 friend 使非成员函数能够访问私有数据。
在类外定义的原因：

提供具体实现，分离声明和定义，增加可读性。
友元函数可以访问类的私有成员，但不是类的成员。







*/