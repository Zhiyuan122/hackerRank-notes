/*
多级继承
一个类继承自另一个已经继承自第三个类的类。类似于链式传递，即：
C 继承自 B，而 B 继承自 A，那么 C 就可以访问 A 和 B 中的成员。

主要特点：
1. C 继承了 B 和 A 的功能。
    C 可以访问 A 和 B 中的 public 或 protected 成员函数和变量。
2. 继承的执行顺序：
    C -> B -> A（从最底层派生类一直向上追溯）。
3. 基类构造函数的调用顺序：
    先调用 A，然后调用 B，最后调用 C。

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Triangle{
	public:
		void triangle(){
			cout<<"I am a triangle\n";
		}
};

class Isosceles : public Triangle{
  	public:
  		void isosceles(){
    		cout<<"I am an isosceles triangle\n";
  		}
};


class Equilateral : public Isosceles{
    public:
        void equilateral(){
            cout<<"I am an equilateral triangle\n";
        }
};

int main(){
  
    Equilateral eqr; //构造了一个C类，然后调用了一个A,B类的方法
    eqr.equilateral();
    eqr.isosceles();
    eqr.triangle();
    return 0;
}
