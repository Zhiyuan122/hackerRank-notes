/*
1. C++ 异常处理（Exception Handling）
用于在程序运行时捕获并处理错误的机制，以防止程序崩溃
    throw（抛出异常）
    try（尝试执行）
    catch（捕获异常）
重点：
如何定义和使用标准异常，如 std::exception。
如何自定义异常类，并重写 what() 方法。
noexcept 关键字的使用，表明函数不会抛出异常。

void testFunction (int n){
    if (n < 0){
        throw runtime_error("not allowed")
    }
    cout << "Valid number: " << n << endl;
}

int main(){
    try{
        testFunction(-5);
    } catch (exception& e){ //catch (exception& e) 捕获了异常，e 指向实际抛出的异常对象，并调用 e.what() 获取错误消息。
    cout << "Caught an exception: " << e.what() << endl;
    }
    return 0;
}

基本语法：
try {
    // 可能抛出异常的代码
} catch (exception_type& variable) {
    // 处理异常的代码
}

what() 是 std::exception 类的一个成员函数，返回一个 C 风格的字符串（const char*），其中包含异常的详细描述。
exception& e 是一个引用，允许访问异常对象并调用 what()。
what() 返回异常描述的字符串，帮助调试错误。
并不要求抛出的对象必须是"正确恰当的异常类"，只要写了 throw，C++ 就会执行异常抛出，除非没有合适的 catch 处理。

throw 抛出的类型（runtime_error）必须与 catch 捕获的类型相匹配，才能正确处理。
如果类型不匹配，程序会跳过 catch 块并终止

在编写异常处理代码时，你需要根据函数的实现来确定可能抛出的异常类型。
如果不确定具体异常类型，你可以使用通用捕获语法 catch(...) 来捕获所有类型的异常：

catch 语句中的变量名称可以自定义，但其类型必须与抛出的异常类型匹配

使用 const 确保 catch 块中不会修改异常对象，提高代码的安全性
异常对象通常较大，使用引用 & 可以避免拷贝，提升性能
catch (exception e)  // ❌ 不推荐，会创建异常对象的副本
const & 作为惯例，使代码更易维护



2. 自定义异常类（Custom Exception Class）
继承 std::exception，并重写 what() 方法，以提供异常描述信息
使用构造函数初始化异常数据，如错误代码、错误描述等。
在 what() 方法中返回 const char* 类型的字符串。
这是标准库异常基类 std::exception 中的一个虚函数（virtual），在异常发生时返回一条描述信息。

throw runtime_error("Negative number not allowed"); 
语句中，字符串 "Negative number not allowed" 作为参数传递给 runtime_error 构造函数，存储在内部。
调用 e.what() 时，它会返回该消息。
e.what() 返回 "Negative number not allowed"

//
what()是标准库异常基类 std::exception 中的一个虚函数（virtual），在异常发生时返回一条描述信息。
这里我们重写了它，使得自定义异常可以返回特定的错误信息。

class MyException : public exception {
    public:
        const char* what() const noexcept override{
            return "Custom exception occurred";
        }

};

const char*表示返回一个 C 风格的字符串指针（const char*），即不可修改的字符数组。
what()标准库异常基类 std::exception 中的一个虚函数（virtual），在异常发生时返回一条描述信息。
const：确保 what() 方法是只读的，可以被 const 对象调用
noexcept表示此函数不会抛出异常，有助于提高代码的安全性和性能优化。是 C++11 引入的特性，声明此函数不会抛出异常，否则可能会导致未定义行为。
override 表示此函数是重写基类的虚函数，确保正确地覆盖 std::exception 的 what() 方法

what() 返回的内容是一条自定义的错误消息
如果没有重写 what()，则会返回标准库默认的错误消息（通常是 "std::exception"）


void testFunction(int n){
    if (n<0) {
        throw MyException(); // 抛出自定义异常
    }
}

int main (){
    try {
        testFunction(-5);
    } catch (const MyExctption& e){
        cout << "Caught custom exception: " << e.what() << endl;
    }
    return 0;
}





*/
//C++ 异常处理模板
#include <iostream>
#include <exception>

using namespace std;

// 1. 定义一个自定义异常类（继承自 std::exception）
class MyException : public exception {
public:
    // 重写 what() 函数，提供错误描述
    const char* what() const noexcept override {
        return "Custom exception occurred";
    }
};

// 2. 可能抛出异常的函数
void testFunction(int n) {
    if (n < 0) {
        throw MyException();  // 抛出自定义异常 ,MyException() 是一个自定义异常类的实例化，并不是一个函数调用。
    }//它会将 MyException 类的临时对象抛出，并在 catch 语句中捕获。
    cout << "Valid number: " << n << endl;
}

int main() {
    try {
        testFunction(-5);  // 调用可能抛出异常的函数
    } catch (const exception& e) {  // 捕获异常
        cout << "Caught an exception: " << e.what() << endl;
    }
    return 0;
}

重点：

定义异常类： 继承 std::exception 并重写 what() 返回错误信息。
抛出异常： 在错误情况下使用 throw 抛出异常。
捕获异常： 使用 try-catch 捕获并处理异常,catch (const exception& e) 是最常见的写法。
e.what() 获取错误信息： 用于打印异常描述。

常见应用场景
1.输入验证
void validateInput(int age) {
    if (age < 0) throw MyException();
}
2.文件操作
void openFile(const string& filename) {
    throw runtime_error("File not found");
}
3.数学计算
void divide(int a, int b) {
    if (b == 0) throw logic_error("Division by zero");
}

如果不想定义自己的异常类，可以使用 C++ 标准异常类，简化代码：
#include <iostream>
#include <stdexcept>
using namespace std;

void testFunction(int n) {
    if (n < 0) {
        throw runtime_error("Negative number not allowed");  // 直接抛出标准异常
    } //runtime_error 类的实例化**，其中的字符串 "Negative number not allowed" 是其构造函数的参数。
}

int main() {
    try {
        testFunction(-5);
    } catch (const exception& e) {
        cout << "Caught an exception: " << e.what() << endl;
    }
    return 0;
}

要点：
直接使用 std::runtime_error 处理常见运行时错误。
catch (const exception& e) 捕获所有标准异常。
使用 e.what() 获取错误信息。



在 BadLengthException 类中，我们定义了一个私有成员变量 length，用于存储错误的用户名长度。因此，必须提供一个构造函数来初始化该变量。
如果类仅用于提供固定的错误信息（如 MyException），则不需要构造函数，直接重写 what() 即可。

4. 什么时候需要构造函数？
如果你的异常类需要存储额外信息，例如：

错误代码
错误描述
发生错误的具体参数（如 length）
那么你需要一个构造函数来接受这些信息。
class ValueTooHighException : public exception {
private:
    int value;
public:
    ValueTooHighException(int v) : value(v) {}

    const char* what() const noexcept override {
        static string msg;
        msg = "Value too high: " + to_string(value);
        return msg.c_str();
    }
};

void test() {
    throw ValueTooHighException(100);
}

