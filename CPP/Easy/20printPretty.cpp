/*
流操纵符（manipulators），用于控制输入输出格式
1. std::hex、std::showbase、std::nouppercase（十六进制输出）
    将数值转换为十六进制格式。
    showbase 添加 0x 前缀。
    nouppercase 使用小写字母表示十六进制（a-f）。
int num = 100;
cout << std::hex << std::showbase << std::nouppercase << num << endl;
0x64



2. std::fixed、std::setprecision（固定小数点格式输出）
    fixed 强制以固定小数点格式显示。
    setprecision(n) 设置小数点后 n 位精度。
double value = 2006.008;
cout << std::fixed << std::setprecision(2) << value << endl;

2006.01

3. std::setw、std::setfill（控制字段宽度和填充）
    setw(width) 设置输出的最小宽度，不足部分补齐。
    setfill(char) 设置填充字符。
cout << std::setw(15) << std::setfill('_') << value << endl;
_______+2006.01

4. std::scientific、std::uppercase（科学计数法输出）
    scientific 将浮点数输出为科学计数法格式。
    uppercase 让科学计数法中的 e 变为 E。

double value = 2331.41592653498;
cout << std::scientific << std::uppercase << setprecision(9) << value << endl;

2.331415927E+03


知识点	用法示例	说明
std::hex	cout << std::hex << num;	输出十六进制格式
std::showbase	cout << std::showbase << num;	显示 0x 前缀
std::nouppercase	cout << std::nouppercase << num;	小写十六进制
std::fixed	cout << std::fixed << setprecision(2);	固定小数点格式
std::setw(n)	cout << setw(15);	设置最小宽度
std::setfill('_')	cout << setfill('_');	设置填充字符
std::scientific	cout << scientific;	科学计数法
std::uppercase	cout << uppercase;	输出大写字母

特定格式设置的优先级
在流操作时，有些格式是全局设置的，有些是仅影响下一次输出的：


格式化操作	作用范围	示例
setprecision()	全局生效	cout << setprecision(2) << 3.14159;
setw()	仅影响下一次输出	cout << setw(10) << 42;
setfill()	影响后续输出直到更改	cout << setfill('_');
fixed/scientific	影响全局浮点数格式	cout << fixed;
hex/dec/oct	影响后续数值格式	cout << hex << 255;


总结：
先设置全局影响的格式（如 fixed、scientific、hex）。
再设置局部影响的格式（如 setw、setfill）。
最后放置实际输出的变量，确保格式不会在下一个操作时被覆盖。
部分格式（如 setw）仅影响紧随其后的输出，需要注意顺序。





*/