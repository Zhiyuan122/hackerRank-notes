/*
C++ 提供的一种方式来组合多个数据字段，以表示一个复合数据结构
8.              结构体                  vs. 类
对比项	        struct	            class
默认访问权限	public	            private
用途	       数据结构，偏向于数据存储	            面向对象，具有封装、继承等特性
继承	                支持	                            支持
函数成员	            可以有成员函数	                主要包含成员函数

struct Student  {
    string name;
    int age;
    float score;
};

class Person {
private:
    int age;
public:
    void setAge(int a) { age = a;}
    int getAge() { return age;}
}

对于结构体的成员变量，使用点运算符进行访问和更改
Student s1;  // 声明一个 Student 类型的变量 s1
s1.name = "Tom";
s1.age = 18;

结构体初始化：
student s2 = {15, "jy","kp", 34};

构体常见操作
(1) 结构体数组
Student students[3] = { // 声明一个包含 5 个 Student 类型元素的数组
    {"Tom", 18, 90.5},
    {"John", 20, 92.5},
    {"Alice", 21, 95.5}
};
(2) 结构体函数传递
可以将结构体传递给函数：
void printStudent(Student s) {
    cout << s.name << " " << s.age << " " << s.score << endl;
}

使用 const Student &s，避免拷贝，节省内存。



(3) 结构体嵌套
可以在一个结构体内部嵌套另一个结构体：

struct Address {
    string city;
    string street;
    int number;
};

struct Person {
    string name;
    int age;
    Address address;
};


(4) 结构体指针----treenode

Student *s = new Student;  // 创建一个 Student 类型的指针 s
s->name = "Tom";  // 使用 -> 运算符访问指钩所指向的结构体的成员
s->age = 18;

(5) 结构体数组指针
Student *students = new Student[3];  // 创建一个包含 3 个 Student 类型元素的数组
students[0].name = "Tom";

(6) 结构体数组指针传递


*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Student
{
    int age;
    string first_name;
    string last_name;
    int standard;
};

int main()
{
    Student st;

    cin >> st.age >> st.first_name >> st.last_name >> st.standard;
    cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;

    return 0;
}