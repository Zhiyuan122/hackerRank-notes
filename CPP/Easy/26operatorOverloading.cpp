/*
运算符重载（Operator Overloading）
C++ 允许重载运算符，使其适用于用户定义的类。运算符重载的基本语法为：
    返回类型 operator符号 (参数列表) {
        // 实现逻辑}

Complex operator+(const Complex& c1, const Complex& c2);

        之所以要使用 &（引用），是为了提高效率并避免不必要的拷贝，同时确保参数的值不会被修改
        为什么加 &（引用）：
                避免对象的拷贝，提升性能。
                减少不必要的内存分配。
                避免构造/析构的额外开销。
        为什么加 const：
                确保参数在函数内部不会被修改，提高代码安全性。
                允许使用 const 对象作为参数，提高灵活性。

        Complex operator+(Complex c1, Complex c2);  // 传值，会触发拷贝

        Complex operator+(const Complex& c1, const Complex& c2);  // 传引用，不拷贝

        Complex a(1.0, 2.0), b(3.0, 4.0);
        Complex c = a + b;  // 调用 operator+时a 和 b 都会被拷贝到 operator+ 函数中，意味着会调用两次拷贝构造函数，这对性能不利。
        c1 和 c2 只是引用传递，不会有额外的拷贝，性能更高。

总结（常见写法归纳）
运算符类型	推荐写法示例	是否使用 const &
算术运算符（+,-,*,/）	ClassName operator+(const ClassName& lhs, const ClassName& rhs);	是
赋值运算符（+=,-=）	ClassName& operator+=(const ClassName& other);	是
比较运算符（==, !=）	bool operator==(const ClassName& other) const;	是
自增/自减（++ --）	ClassName& operator++();（前置）	无
输入/输出运算符	friend std::ostream& operator<<(std::ostream& os, const ClassName& obj);	是（输入无）

cout 是标准输出流对象 (ostream) 的实例，而 object 是用户自定义类的实例。
由于 cout 不是 Complex 类的成员，因此无法将它作为 Complex 类的成员函数处理。
使用 friend 关键字可以允许 ostream 访问 Complex 类的私有成员，如 a 和 b。

*/
#include <iostream>
#include <string>

using namespace std;

class Complex {
public:
    int a, b;

    // 解析字符串并提取实部和虚部
    void input(string s) {
        int v1 = 0;
        int i = 0;
        
        // 解析整数部分，直到遇到 '+'
        while (s[i] != '+') {
            v1 = v1 * 10 + (s[i] - '0');//s[i] - '0'，将字符 '3' 转换成整数 3，字符 '7' 转换成整数 7
            //s[i] - '0' 是一种常见的字符转整数的技巧
            i++;
        }

        // 跳过 "+i" 部分 跳过空格 加号 i
        while (s[i] == ' ' || s[i] == '+' || s[i] == 'i') {
            i++;
        }

        // 解析虚部
        int v2 = 0;
        while (i < s.length()) {
            v2 = v2 * 10 + (s[i] - '0');
            i++;
        }

        a = v1;  // 赋值给实部
        b = v2;  // 赋值给虚部
    }
};

// 在类外定义运算符重载
// 重载加法运算符，定义如何相加两个复数对象
Complex operator+(const Complex& c1, const Complex& c2) {
    Complex res; //创建一个 Complex 类型的局部变量 res，用于存储相加后的结果。
    res.a = c1.a + c2.a;//将 c1 和 c2 的实部相加，赋值给 res.a
    res.b = c1.b + c2.b;
    return res;
}
/*
函数的返回值类型是 Complex，表示它返回一个新的 Complex 
它不属于新的类，而是一个全局函数

*/


// 重载 << 运算符，定义复数的输出格式
ostream& operator<<(ostream& out, const Complex& c) {
    out << c.a << "+i" << c.b;
    return out;
}

int main() {
    Complex x, y;
    string s1, s2;

    // 读取输入格式形如 "3+i4"
    cin >> s1 >> s2;

    // 调用input函数解析字符串
    x.input(s1);
    y.input(s2);

    Complex z = x + y;  // 使用运算符重载

    cout << z << endl;  // 使用 << 运算符重载输出结果

    return 0;
}
