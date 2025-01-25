/*
预处理指令（Preprocessor Directives） 的应用，
特别是 宏定义（macro definitions）

预处理器在实际编译代码之前检查代码，并在常规语句实际生成任何代码之前解析所有这些指令。


#define 宏定义:
定义常量 #define INF 10000000
定义宏函数 #define add(a, b) ((a) + (b))

    #define INF 10000000
    if( val == INF) {
    //Do something
    }
    After the preprocessor has replaced the directives, the code will be
    if( val == 10000000) { //Here INF is replaced by the value with which it's defined.
    //Do something
    }
---------------------------------
    #define add(a, b) a + b
    int x = add(a, b);

    The second statement after the preprocessor has replaced the directives will be:
    int x = a + b;

条件编译
控制代码是否编译
#ifndef HEADER_FILE
#define HEADER_FILE
#endif



#include <iostream> 头文件包含指令，它告诉编译器在编译之前插入 <iostream> 文件的内容。
#include 是预处理指令，但它的作用主要是包含外部库。

预处理指令（如 #define、#if、#error）编译之前 由 预处理器 处理，进行 宏替换、条件编译、文件包含等操作。

如何识别这些是宏？
1. 宏的调用方式通常是全大写字母（习惯性命名规范）：
宏一般采用全大写字母，例如 INF、FUNCTION、toStr 等，在实际开发中，这是一种约定俗成的命名方式，区别于普通的变量和函数。

2. 宏通常不会带有声明，而是直接使用（没有类型声明）：
在正常的 C++ 代码中，minimum 和 maximum 这样的名称，通常会出现在函数定义或类方法中，比如：
int minimum(int a, int b) { return a < b ? a : b; }

FUNCTION(minimum, <) //  并没有任何声明，直接使用，这意味着它必须是在编译前由宏展开
宏替换会将 FUNCTION(minimum, <) 展开成 void minimum(int &a, int b) { if (b < a) a = b; }

宏定义的格式：
    #define 宏名(参数1, 参数2, ...) 替换文本

    括号里的参数（宏参数） 只是用于占位和替换，而展开后的代码是宏的替换文本。
    宏的参数替换遵循纯文本替换的原则，因此不直接决定函数参数的数量，而是通过宏定义时的替换内容来决定。


*/

/* Enter your macros here */

#include <iostream>
#include <vector>
using namespace std;

#define INF 100000000
#define toStr(x) #x   //#x 是预处理器语法，用于将参数 x 转换为字符串。
//观察到 toStr(Result =), 推测它的参数就是 Result =，因此宏的定义需要接受一个参数并将其转换为字符串。
#define io(v) cin >> v
//cin >> v[i]; 是处理输入的常见方式，因此推测 io(v) 需要展开为 cin >> v
#define FUNCTION(name, op) void name(int a, int b) { if(b op a) a = b ;}
#define foreach(v, i) for (size_t i = 0; i < v.size(); i++)
//foreach 并不是标准的 C++ 语法，而是一个宏定义的占位符。假设它的功能是类似于 for 循环，按照惯例，我们可以定义它如下：

#define INF 10000000
#define toStr(x) #x
#define io(v) cin >> v
#define FUNCTION(name, op) void name(int &a, int b) { if (b op a) a = b; }
#define foreach(v, i) for (size_t i = 0; i < v.size(); i++)
/*
int &a 意味着 a 直接引用了调用该函数时传入的变量，因此对 a 的修改会影响到原变量。例如：
void updateValue(int &a, int b) {
    if (b < a) a = b;  // 修改的是原始变量
}

int main() {
    int x = 10;
    updateValue(x, 5);
    cout << x;  // 输出 5，x 被修改了
    return 0;
}

int &a 改为 int a，则参数 a 会在函数内部创建一个 副本（copy），对 a 进行的任何更改 不会影响 原始变量。例如：
void updateValue(int a, int b) {
    if (b < a) a = b;  // 修改的是副本，不影响原始变量
}

int main() {
    int x = 10;
    updateValue(x, 5);
    cout << x;  // 输出 10，x 没有被修改
    return 0;
}





*/




#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
//#if !defined：检查 toStr、io、FUNCTION、INF 是否被定义。
#error Missing preprocessor definitions
//这些宏需要在代码编译前被定义，否则会报错
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result =) <<' '<< ans;
	return 0;

}