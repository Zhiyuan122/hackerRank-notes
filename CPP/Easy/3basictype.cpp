#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    /*错误写法
    scanf("%d","%ld","%c","%f","%lf", &a, &b,&c,&d,&e);
    printf("%d","%ld","%c","%f","%lf",a,b,c,d,e);
    */
    int a;
    long b;
    char c;
    float d;
    double e;

    scanf("%d %ld %c %f %lf", &a, &b, &c, &d, &e);
    printf("%d\n", a);
    printf("%ld\n", b);
    printf("%c\n", c);
    printf("%.3f\n", d);
    printf("%.9lf\n", e);
    // 或者这么写printf("%d\n%ld\n%c\n%f\n%lf\n",a,b,c,d,e);

    return 0;
}

/*
数据类型data type	说明符（Format Specifier）	位宽（Bit Width）	示例
int	             %d	                        32 位	        3
long	         %ld                    	64 位	12345678912345
char	        %c	                        8 位	'a'
float	        %f	                        32 位	334.23
double	        %lf                     	64 位	14049.30493

scanf(): 使用 scanf 按照指定的格式说明符读取多个数据值，并将其存储到变量中

int a;
long b;
char c;
float d;
double e;

scanf("%d %ld %c %f %lf", &a,&b,&c,&d,&e);
& 是取地址符，用于 scanf 将输入值存储到变量的地址中

printf();  按照指定格式打印变量的值,""本质上是一串字符串
printf("%d\n",a);
printf("%ld\n", b);
printf("%c\n",c)
printf("%.3f\n",d);
printf("%.9lf\n",e);

scanf 和 printf 在处理大量输入输出时性能优于 cin 和 cout，因为它们使用的是 C 的底层 I/O。

scanf 会自动忽略输入中的空格和换行符。

*/