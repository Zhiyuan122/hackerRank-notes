/*
class BaseClass{};

class DrivedClass : public BaseClass{};

public 继承：基类的 public 成员在派生类中保持 public，protected 成员保持 protected。
protected 继承：基类的 public 成员变为 protected，protected 成员保持 protected。
private 继承：基类的 public 和 protected 成员都变为 private。

继承使我们可以从一个已有的类创建一个新的类，
新的类（派生类）将继承基类的所有公共（public）和受保护（protected）的成员，
并可以添加额外的功能或重写基类方法。

*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Triangle
{
public:
    void triangle()
    {
        cout << "I am a triangle\n";
    }
};

class Isosceles : public Triangle //不同再强调class
{
public:
    void isosceles()
    {
        cout << "I am an isosceles triangle\n";
    }
    // Write your code here.
    void description()
    {
        cout << "In an isosceles triangle two sides are equal" << endl;
    }
};

int main()
{
    Isosceles isc;
    isc.isosceles();
    isc.description();
    isc.triangle();