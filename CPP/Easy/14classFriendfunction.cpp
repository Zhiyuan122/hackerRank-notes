/*
void compare(Box otherBox);  // 拷贝整个对象，效率低
void compare(Box& otherBox); // 传递引用，不拷贝，效率高

bool operator<(const Box& otherBox) const;
第一个 const（参数部分）：
const Box& otherBox 表示传入的 otherBox 参数是一个只读的 Box 对象，保证该对象在函数内部不会被修改。
第二个 const（成员函数末尾）：
末尾的 const 表示该函数不会修改当前对象的成员变量。

bool operator<(const Box& otherBox) const;
"定义了 Box 类的 < 比较运算符"，用于比较两个 Box 对象的大小。
传入的 otherBox 是一个按引用传递的只读对象，不会修改它。
const 说明该函数不改变当前对象，只进行比较。



友元函数，它可以访问 Box 类的 private 或 protected 成员。
友元函数不是类的成员函数，而是普通的独立函数。
友元的使用目的是为了允许非成员函数访问私有数据，比如直接访问 length, breadth, height。

friend ostream& operator<<(ostream& out, const Box& B);
声明了一个友元函数，用于重载 << 运算符，以便让 cout 能够直接输出 Box 对象的内容。
返回类型 ostream& 代表标准输出流的引用，这样可以连续输出

传入的 Box& B 是要输出的 Box 对象的引用
const 表示 B 在函数内部不能被修改，保证输出操作不会影响对象的状态。

*/

#include <iostream>
using namespace std;

class Box{
    private:
        int length, breadth, height;

    public:
        Box(): length(0), breadth(0), height(0){} // default constructor
        Box(int l, int b, int h) : length(l), breadth(b), height(h){}
        Box(const Box& B){
            length = B.length;
            breadth = B.breadth;
            height = B.height;
        }

        int getLength() const {return length;}
        int getBreadth() const {return breadth;}
        int getHeight() const { return height;}
        long long CalculateVolume() const{ return (long long)length * breadth *height;}
        /*
        long long volume1 = (long long)length * breadth * height;  // C风格
        long long volume2 = static_cast<long long>(length) * breadth * height;  // C++风格
         */

        bool operator<(const Box& B) const{
            if(length < B.length) return true;
            if(length == B.length && breadth < B.breadth) return true;
            if(length == B. length && breadth == B.breadth && height < B.height) return true;
            return false;
        }

        friend ostream& operator<<(ostream& out, const Box& B){
            out << B.length << " " << B.breadth<< " " << B.height;
            return out;
        }
    };

    int main(){
        Box b1;
        Box b2(1,2,3);
        Box b3(b2); // 拷贝构造函数，复制 b2 的值到 b3

        cout << b2.getLength() << " "<< b2.getBreadth() << " " << b2.getHeight() << endl;
        cout << "Volume of b2: " << b2.CalculateVolume() << endl;

        // 测试运算符重载
        if (b1 < b2) {cout << "b1 is smaller than b2" << endl;}
        // 测试 << 运算符
        cout << "b2: " << b2 << endl;

        return 0;
    }

    /*
    什么情况下会触发运算符重载, 运算符重载的触发条件是：
    左操作数为 ostream 类型，如 std::cout。右操作数为 Box 类型的对象或引用，如 b2。
    */