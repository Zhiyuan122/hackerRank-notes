/*
C++模板（Templates）与模板特化（Template Specialization）
A class template provides a specification for generating classes based on parameters.
模板允许我们编写通用代码，编译时根据传入的数据类型自动生成对应的代码。模板分为：

    1. 函数模板（Function Templates）-----允许你为不同的数据类型编写相同的代码
        函数模板：求两个数的最大值
        template <typename T>
        T maxElement(T a, T b) {
            return (a > b) ? a : b;
        }

        int main() {
            cout << maxElement(10, 20) << endl;         // int 类型
            cout << maxElement(5.5, 2.3) << endl;       // double 类型
            cout << maxElement('a', 'b') << endl;       // char 类型

    2. 类模板（Class Templates）

        类模板:
        通常用于实现数据容器containers，如 vector、map 等
            template<typename T>
            class AddElements{
                T element;
            
            public:
                AddElements(T arg) {element = arg;}
                T add(T other) {return element + other;}
            };

模板特化（Template Specialization）---类模板的一种特化，用于为特定的数据类型提供不同的实现，而不是泛化处理所有类型。
模板特化允许我们为特定类型提供不同的实现，例如字符串拼接，而不是数学加法。
template <>
class AddElements<string> {
    string element;
public:
    AddElements(string arg) { element = arg; }
    string concatenate(string other) { return element + other; }
};
——————————————————————————————————————————————————————————————————————
template <typename T>  // 定义一个模板，T是占位符，可以代表任意类型
class AddElements {
    T element;  // 存储一个泛型的元素
public:
    AddElements(T arg) { element = arg; }  // 构造函数，接收任意类型的参数
    T add(T other) { return element + other; }  // 加法操作，返回元素的和
};
——————
AddElements<int> myInt(5);
cout << myInt.add(10);  // 输出: 15

AddElements<float> myFloat(2.5);
cout << myFloat.add(1.5);  // 输出: 4.0
——————
template <>  // 特化声明，表示该版本是专门为 string 设计的
class AddElements<string> {
    string element;
public:
    AddElements(string arg) { element = arg; }  // 存储字符串
    string concatenate(string other) { return element + other; }  // 拼接字符串
};
_______

template <typename T> → 泛化
template <> class AddElements<string> → 特化


*/

/*
题目要求的实现
我们需要定义一个模板类 AddElements，可以处理 int、float 和 string 类型：

对于 int 和 float 类型： 提供 add() 函数，返回两个数的和。
对于 string 类型（特化）： 提供 concatenate() 函数，返回字符串拼接结果。
*/

template <class T>
class AddElements{
    T element; //定义了一个私有成员变量 element，类型由模板参数 T 决定。
public:
    AddElements(T arg){element = arg;}//构造函数接收一个与 T 类型相同的参数 arg，并将其存入类的私有成员变量 element
    T add(T other){return element + other;} //add 方法接收一个与 T 类型相同的参数 other，并返回当前对象的 element 与 other 之和。
     
};
/*
拆解记忆：
template <class T> // 模板类声明，使类 AddElements 变成一个通用类，支持任意数据类型 T。
class AddElements{ // 定义类 AddElements，在实例化时 T 会被具体类型替代。
    T element; 
public:
    AddElements(T arg){element = arg;}
        T arg：构造函数参数，类型为模板参数 T，比如 int、double 等。
        element = arg;：将传入的参数 arg 赋值给成员变量 element


    T add(T other){return element + other;} 
        T: 函数返回类型
        add(T other):
            函数名 add，表示执行“加法”操作。
            参数 T other：类型为模板参数 T，表示要加上的值
        element + other，适用于支持 + 运算符的类型（如 int, float, string）。
};

AddElements<int> obj1(10); //模板中的所有 T 都会被替换为 int，从而生成一个操作 int 类型数据的类
std::cout << obj1.add(5) << std::endl;  // 输出 15
AddElements: 模板类的名称。
<int>: 模板参数，指定模板参数 T 的具体类型为 int
obj1 是类 AddElements<int> 的一个对象，当这个对象被创建时，它拥有类中定义的所有成员变量和方法，例如 element 和 add

10 是一个传递给类构造函数的参数，对应模板类中的 T arg


*/


template<>
class AddElements<string>{
    string element;
public:
    AddElements (string arg){ element = arg;}

    string concatenate(string other){ return element + other; }

};
/*

在模板编程中，类模板和其特化版本的名称必须相同
因为模板特化是在相同的模板基础上提供不同的实现，而不是创建新的类。编译器根据不同的模板参数自动选择适合的模板版本。




template<> //表明我们正在对某个类型进行特化。
class AddElements<char> { //char 指定特化类型。
    char element;
public:
    AddElements(char arg) { element = arg; } //初始化 element 为传入的 char 类型参数。

    // 处理 char 类型的特化方法
    char printElement() { //返回 element 值，仅适用于 char 类型的对象。
        return element;
    }
};

泛化模板 (Generic Template) 提供了一个通用解决方案，可以适用于多种不同的数据类型，
而特化模板 (Specialization Template) 是为某些特定类型提供更合适的优化实现或不同的逻辑。

假设我们有一个泛化模板用于数值的加法：这个模板很好地适用于 int 和 float：
但是，当我们尝试使用 string 类型时，会发现问题：
此时，我们可以特化 string 类型，提供不同的实现：
这样，我们的用户仍然可以使用相同的类名 AddElements<T>，而不需要知道不同类型的处理方式。

ps:
模板（Template）不是类，模板是一种生成类或函数的机制。
它是一种通用的设计工具，用来创建类型安全的代码，提供代码的复用性。
在编译时，模板会根据你提供的具体类型来实例化成真正的类或函数。

定义了一个泛化的 AddElements 类：
template <typename T>
class AddElements {
    T element;
public:
    AddElements(T arg) { element = arg; }
    T add(T other) { return element + other; }
};

使用 int 时，编译器会自动生成这样的类：
class AddElements_int {
    int element;
public:
    AddElements_int(int arg) { element = arg; }
    int add(int other) { return element + other; }
};

模板特化 和 继承 是完全不同的概念：
特化模板提供的是某些特定类型的特定实现，而不是从泛化模板继承，它是针对某些类型提供特定逻辑的单独实现。

为什么不用继承，而是用特化？
如果 AddElements<string> 继承自 AddElements<T>，
那么 add() 方法在字符串类型下无法直接复用，因为 std::string 具有特殊的拼接逻辑，而不是加法操作。
因此，我们使用模板特化来针对 std::string 单独实现拼接，而不是继承泛化模板

final answer:

template <class T>
class AddElements{
        T element;
    public:
        AddElements(T arg){element = arg;}
        T add(T other){return element+other;}
};

template<>
class AddElements<string>{
        string element;
    public:
        AddElements(string arg){element = arg;}
        string concatenate(string other){
            return element + other ;
        }
};

模板名和里面的具体函数名可以根据main函数中的名字去判断

主函数中的对象声明：
AddElements<double> myfloat(element1);
AddElements<int> myint(element1);
AddElements<string> mystring(element1);
这表明类模板的名称应该是 AddElements，并且它支持 int、double、string 类型。
myfloat → 这是变量名，用户自己定义的名名字

主函数调用方式：
myfloat.add(element2);
myint.add(element2);
mystring.concatenate(element2);
对于 int 和 double 类型，应该实现 add() 方法。
对于 string 类型，应该实现 concatenate() 方法。
ddd






*/