/*
lower_bound 是 C++ 标准库中的一个函数，定义在 <algorithm> 头文件中。
它用于在有序容器（如 vector）中查找第一个不小于给定值的位置

auto it = lower_bound(v.begin(), v.end(), value);
v.begin()：迭代器指向 vector 的开始位置
v.end()：迭代器指向 vector 的结束位置
value：要查找的值
返回值 it：指向第一个大于或等于 value 的元素的迭代器。
如果 value 存在，它指向第一个 value，否则指向下一个比 value 大的元素。
核心 ： lower_bound 返回的是 “第一个不小于” 查询值的元素位置。

迭代器（it）是指针类型，不是直接的数值
lower_bound 返回的是指向 vector 内部元素的迭代器（iterator）。
直接输出 it，会输出类似于内存地址的内容，而不是你希望的数组位置。
it - v.begin() 计算的是迭代器之间的距离，即元素的索引。

表示迭代器 it 距离容器起始位置 v.begin() 的偏移量，也就是 0-based 索引。
两个迭代器的相减本质上是计算它们指向的内存地址之间的差值，
但是这种差值表示的是元素的数量，而不是直接以字节为单位的内存地址差异。

vector 容器中：

v.begin() 指向第一个元素。
v.end() 指向的是“最后一个元素的下一个位置”，即超出 vector 范围的下一个位置。

vector<int> v = {10, 20, 30, 40};
v[0] 或 *(v.begin()) → 访问第一个元素 10
v[1] 或 *(v.begin() + 1) → 访问第二个元素 20
v[2] 或 *(v.begin() + 2) → 访问第三个元素 30
v[3] 或 *(v.begin() + 3) → 访问第四个元素 40
v.end() → 指向元素 40 之后的位置，不能解引用，否则未定义行为

cout << *v.end() << endl;  // ❌ 错误，访问越界，未定义行为！

v.insert(v.end(), 50);  // 在末尾插入 50





4. 适用的容器
    可以直接相减的容器（支持随机访问迭代器）：

    vector
    array
    deque

    不支持直接相减的容器（不支持随机访问迭代器）：

    list（双向迭代器）
    set / map（基于平衡树，使用双向迭代器）

本质上it是一个和begin，end 一样的指针，在vector上面动，如果动到最后
if (it == v.end()) {
    cout << "Element not found";
}

 while (q--) {...}它表示：在每次循环迭代后，将 q 减 1，直到 q == 0 时退出循环。

while (q > 0) {
    // 执行代码
    q--;  // 每次循环后递减
}



*/

/*
对于此题，下面两种方法都可以
1. 两个数组vector， 一个存储原始数据，一个存储查询数据，然后用lower_bound查找，限定条件依次是第二个数组的值

int main(){
    int n;
    cin >> n;
    vector<int> v1(n);
    for (int i = 0; i < n; i++){
        cin >> v1[i];
    }
    int q;
    cin >> q;
    vector<int> v2(q);
    for (int i = 0; i < q; i++){
        cin >> v2[i];
    }

    for (int i = 0; i < q; i++){
        auto it = lower_bound(v1.begin(), v1.end(), v2[i]);
        if (it == v1.end()){
            cout << "No" << endl;
        } else {
            cout << "Yes " << it - v1.begin() + 1 << endl;
        }
    }
}

2. 一个数组vector，然后用lower_bound查找，用while loop，限定查询次数
int main() {
    int n;
    cin >> n;
    vector<int> v(n);

    // 读取数组元素
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int q;
    cin >> q;
    
    while (q--) {
        int x;
        cin >> x;

        // 查找 lower_bound
        auto it = lower_bound(v.begin(), v.end(), x);
        
        if (it != v.end() && *it == x) {
            cout << "Yes " << (it - v.begin() + 1) << endl;
        } else {
            cout << "No " << (it - v.begin() + 1) << endl;
        }
    }

    return 0;
}