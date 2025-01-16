#include <iostream> //用于 cout 和 endl
#include <cstdio>   //用于 printf
using namespace std;

int main()
{
    cout << "HW1!" << "HW2!" << endl;
    printf("HW   HW1\n");

    float pi = 3.1415926;
    printf("PI IS ROUND TO : %.2f\n", pi);

    char name[] = "alice";
    printf("name is %s \n", name);

    return 0;
}
/*
在大量数据输出的场景中，printf 通常比 cout 更高效
但优先使用 cout，因为它是 C++ 的标准输出方式


格式符	类型	说明
%d	整数（int）	十进制表示的有符号整数
%f	浮点数（float/double）	默认保留6位小数
%.nf	浮点数（float/double）	保留n位小数
%s	字符串（char*）	输出字符串
%c	字符（char）	输出单个字符
%x	整数（unsigned int）	十六进制表示的小写字母
%X	整数（unsigned int）	十六进制表示的大写字母
%p	指针（void*）	输出指针地址


*/