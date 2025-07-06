#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a, b, c;
    int sum;
    // 错误点1 
    // sum = a+b+c;
    // sum 如果在这里，就会导致局部变量 a, b, c, sum未显式初始化计算出的 sum 是不可预测的值，可能是内存中的随机数
    // 也可以直接cout << (a+b+c)<< endl;

    cin >> a >> b >> c;
    sum = a + b + c;
    cout << sum << endl;
    cout << a + b + c << endl;
    //错误点2 ： cin >>;    cout <<  ;
    //错误点3 ： 编译器不允许把赋值表达式当作 ostream 的内容直接输出    cout << sum = a+b+c << endl;
    //          但是可以直接直接cout << (a+b+c)<< endl;

    return 0;
}
/*
cin 从标准输入读取数据，遇到空格或换行符时会停止读取。
endl：向标准输出添加换行符，并刷新缓冲区。
\n：添加换行符，但不刷新缓冲区（性能稍优于 endl）

输入多种类型：
在更复杂的场景下，可以结合 getline 或 stringstream 来处理多行输入。

延申问题：
1. 如果输入是 a b c，但是用户只输入了两个怎么办？
cin 会等待第三个输入，直到你输入完或遇到 EOF

2. 如果用户输入的是 1 abc 3 呢？
会读取 1，然后读取失败停在 abc，导致后续出错

拓展问题：
1. 如何读入 整行输入 再进行拆分？（用 getline() + istringstream）

int main(){
    string line;
    getline(cin, line);// 从键盘整行读入（放进 line 里）它是个字符串（string 类型），还没有拆分！

    istringstream iss(line); // 创建一个字符串流,把 line 包装成输入流 iss

    while(iss >> num ){// 不断从字符串流中提取整数,从 iss 里一个一个提取下一个空格前的内容取出（比如数字）
        sum += num;
    }

    cout << "Sum =" << sum << endl;
    return 0;
}


2. 如何处理 不确定个数的输入？（用 while(cin >> num)）

int main(){
    int num, sum = 0;
    while (cin >> num){
        sum += num;
    }
    
    return 0;
}


| 功能     | `getline + istringstream` | `while(cin >> num)` |
| ------ | ------------------------- | ------------------- |
| 输入方式   | 一整行一次性读入                  | 一个一个读，直到 EOF        |
| 拆分方式   | 通过字符串流手动提取                | 自动每次一个变量            |
| 输入结束信号 | 一行结束自动处理                  | 需要 Ctrl+D / Ctrl+Z  |
| 使用场景   | 多用于一行内拆词或数字               | 多用于输入长度未知的整数序列      |

EOF 全称：End Of File，是输入的“结束信号”
| 操作系统        | 按键              |
| Windows     | `Ctrl + Z` 然后回车 |
| Mac / Linux | `Ctrl + D`      |

cin >> num 是“按空格分割的逐个输入”
它只读取一个 token（单元），也就是遇到空格、Tab、换行就停。

getline(cin, line) 是“一整行读取到字符串”
它会把整行的所有字符都读入，直到遇到 \n（换行符）为止。
空格也会保留。
用于读入整段文字、句子，或者后面要手动拆分的时候。

cin >> num 能循环读，是因为？
每次尝试从流中读一个 int，失败就自动退出循环。cin 是可以自动判断输入状态的流



*/
