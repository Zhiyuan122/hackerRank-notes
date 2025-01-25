/*
class Student{
    private:
        int val1;
        string val2;

    public:
        void setVal(int v){ val1 = v;}
        int getVal(){return val1;}
};

2. 访问控制修饰符（Access Specifiers)
public	类的成员可以在任何地方访问（类外部、类内部都可以访问）。
private	类的成员只能在类内部访问（类外部不可访问）。
protected	类的成员在类内部和派生类中可访问（继承时使用）

*/
#include <iostream>
#include <sstream>
using namespace std;

class Student
{
private:
    int age;
    string first_name;
    string last_name;
    int standard;

public:
    void set_age(int a) { age = a; }
    int get_age() { return age; }

    void set_first_name(string b) { first_name = b; }
    string get_first_name() { return first_name; }

    void set_last_name(string c) { last_name = c; }
    string get_last_name() { return last_name; }

    void set_standard(int d) { standard = d; }
    int get_standard() { return standard; }

    string to_string(){
        stringstream ss;
        ss << age << "," << first_name << "," << last_name << "," << standard；
        // stringstream 只能处理你手动放入的内容，它不会自动接收来自 cin 的数据。需要像这样手动插入数据
        //endl;在 to_string() 方法中是不必要的，因为 endl 适用于 cout，在字符串流中会影响输出格式
        return ss.str();
    }
    /*
    在 C++ 中，to_string() 函数的目的是返回一个 字符串（std::string），而不是在函数内部直接输出到控制台

    而 cout 仅仅是输出数据到控制台, 用于打印输出，它不会返回字符串，
    只会在终端输出内容，无法作为 to_string() 的返回值。

    直接 cout 会破坏 to_string() 的设计理念，使其不能在其他地方复用。

    为什么使用 stringstream？
    类型安全：支持不同数据类型的拼接，不需要手动转换。
    自动处理空格、逗号等格式。

    如果你仅仅想在 main() 中打印数据，而不是需要将其返回为字符串，那么 cout 是合适的：
    void print_student() {
    cout << age << "," << first_name << "," << last_name << "," << standard << endl;
}
    cout 适合直接输出，但不适合 to_string()，因为 to_string() 需要返回字符串，便于后续处理

    ss.str() 当你使用 ss 将数据插入 stringstream 后，可以使用 ss.str() 获取内部存储的字符串。
    ss.str("new content") 可以将新的字符串赋给 stringstream 对象，并替换掉当前内容。
    ss.str() 常见用法：
    格式化字符串——将不同类型的数据拼接为一个字符串
    int age = 20;
    string name = "Alice";

    stringstream ss;
    ss << "Name: " << name << ", Age: " << age;
    cout << ss.str() << endl;
    // 输出：Name: Alice, Age: 20

    */
};

int main()
{
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;
    // cin 只是将输入数据读取到变量，并不会直接进入 stringstream，而是先存入类的成员变量，之后在 to_string() 中再组合成字符串。

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();

    return 0;
}