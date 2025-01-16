/*
int val = 10;
int *p = &val;  // p 存储了 val 的地址 assign the memory address of val to the pointer P
*p return the value stored in val and any modification to it will be performed on val

*p = 20;  // 修改 val 的值为 20

对于 int a=5;
1. a是一个变量，存储的是一个具体的值  【a】
2. &a  取地址操作符,  获取变量 a 在内存中的地址,  返回值是一个指针，指向变量 a   --->【a】
即 &a = int* p--  int* p = &a
 如果a 是一个 普通的整数变量，*a 是非法的，编译器会报错，因为 * 是解引用操作符，只有在变量是指针时才能使用。


3. *  解引用操作符，访问指针指向的内存地址中的值
 *a 表示访问该指针指向的值
int* p = &a;  // p 是一个指针，指向 a
cout << *p;   // *p 解引用，输出 a 的值：5
    tips: 如果写成int* p = a，编译器会报错，类型不匹配：p 是一个指针类型 (int*)，期待存储的是一个地址；a 是一个整数 (int)，值如 10，而不是地址
            栈内存：
            +------------+-------------+
            | 变量名      | 值          | 含义                     |
            +------------+-------------+
            | a          | 10          | 整数变量 a 的值            |
            | p          | 0x7ffeefbff4dc | 指针 p，存储的是 a 的地址 |
            +------------+-------------+

要注意的点：
int* p;  这里的p是指针，当我们说指针P的时候，用P即可，而不是*p，
*p表示的是对指针P的解引用，表示修改指针P所指的值
所以cout<< p 打印的是变量a的地址
cout<< *p 打印的是a的值
（cout << &p   // 输出 指针p 本身的地址 表示 int** 指针的指针）
变量名     内存地址        内容
--------  ------------  ------------
a         0x7ffeefbff4dc  10         （a 的值）
p         0x7ffeefbff4d0  0x7ffeefbff4dc （p 的值，指向 a）



函数中使用指针参数
如果函数参数是指针，可以直接修改指针所指向的变量的值
void update(TreeNode* head)

void update(int *x) {
    *x += 10;  // 修改指针 x 所指向的变量的值
}

计算绝对值可以使用 abs() 函数（来自 <cmath> 头文件）
int diff = abs(a - b);


int *x和int*x 无区别，只是二者强调的东西不一样
前者强调x 是一个指针，指向 int 类型
后者强调

int* x, y;  （很少这么写，容易误解）// 等价于 int *x, y;

对于基本类型一般：int *x;
对于复杂类型一般： TreeNode* head; (一个TN类型的指针，叫head)
如：
TreeNode* a,b;
TreeNode* a: 指针 存储 TreeNode 对象的地址
本质上是栈帧中的一个指针空间，指向内存中某个 TreeNode 类型的节点地址
TreeNode b :完整结构体	占用整个 TreeNode 对象的大小
一个完整的树节点对象，包含值（val）、左指针（left）和右指针（right）。
-------------------------------------------------------

ps:
变量的存储位置由其分配方式决定

栈（Stack）：
存储局部变量和函数调用相关的内存（包括基本类型和对象）。
自动分配和释放（函数返回时，栈帧销毁，变量也会释放）。
    示例：TreeNode a;（在栈上分配）
    a 是一个完整的对象，分配在栈上。
    a 的生命周期和作用域受限于它所在的函数或代码块。
    对象的所有成员变量（如 val, left, right）也会分配在栈内存中
    栈内存：
    +------------+-------------+
    | a.val      | 0           |
    | a.left     | NULL        | (指针类型，存储地址)
    | a.right    | NULL        | (指针类型，存储地址)
    +------------+-------------+




堆（Heap）：
通过动态内存分配显式创建（new 或其他分配函数）。
必须手动释放（使用 delete 或 delete[]）
    示例：TreeNode* a = new TreeNode();（在堆上分配）。
    指针 a 本身存储在栈上，占用 8 字节（64 位系统）。
    它指向一个在堆上分配的 TreeNode 对象。
    你需要显式调用 delete 释放堆内存，否则会导致内存泄漏。
    栈内存：
    +------------+-------------+
    | a (指针)   | 0x60000000  | --> 指向堆上的节点
    +------------+-------------+

    堆内存：
    +------------+-------------+
    | a->val     | 0           |
    | a->left    | NULL        | (指针类型，存储地址)
    | a->right   | NULL        | (指针类型，存储地址)
    +------------+-------------+

4. 树的节点为什么常存储在堆上？
C++ 中可以将 TreeNode 节点存储在栈上或堆上，但 树的节点更常存储在堆上

(1) 树的结构是动态的
树的节点数量和布局通常在运行时才确定。
堆支持动态内存分配，允许在运行时灵活地创建节点。

(2) 栈上的内存有限
栈内存通常比较小（例如，默认栈大小可能只有 1MB）。
如果树的节点很多，栈可能会溢出，而堆内存更适合存储大量数据。

(3) 长期存在的对象需要堆存储
栈上的对象在函数返回时会自动销毁。
如果树节点需要在函数之外继续存在（例如，树的根节点需要被多个函数共享），就需要使用堆存储。

5. 栈 vs 堆
栈上创建二叉树-----几乎不这么写，仅供理解
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
int main(){
    TreeNode root;// 根节点在栈上
    TreeNode leftchild;
    TreeNode rightchild;

    root.val = 1;
    root.left = &leftChild;
    root.right = &rightChild;

    leftChild.val = 2;
    leftChild.left = nullptr;
    leftChild.right = nullptr;

    rightChild.val = 3;
    rightChild.left = nullptr;
    rightChild.right = nullptr;

    cout << "Root: " << root.val << ", Left: " << root.left->val << ", Right: " << root.right->val << endl;

return 0;
}




堆上创建二叉树
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

};
int main(){
    TreeNode* root = new TreeNode();// 根节点在堆上
    TreeNode* leftchild = new TreeNode();
    TreeNode* rightchild = new TreeNode();

    root -> val = 1;
    root -> left = leftchild;
    root -> right = rightchild;

    leftchild ->val = 2;
    leftchild ->left = nullptr;
    leftchild ->right = nullptr;

    rightChild->val = 3;
    rightChild->left = nullptr;
    rightChild->right = nullptr;

    cout << "Root: " << root->val << ", Left: " << root->left->val << ", Right: " << root->right->val << endl;

    // 手动释放堆内存
    delete leftChild;
    delete rightChild;
    delete root;

    return 0;
}

TreeNode a 是栈上的对象：直接分配在栈上，其生命周期受限于所在的作用域。
TreeNode* a 是栈上的指针：存储一个地址，指向堆上或栈上的节点。

树的节点通常存储在堆上，因为堆支持动态分配，更适合表示复杂的树结构。




 */
#include <stdio.h>

void update(int *a, int *b)
{                      // 此a非彼a和下面主函数的a含义不一样
    int sum = *a + *b; // 上面已经说了a,b是指针，*a +*b相当于其值相加
    int diff = (*a - *b) < 0 ? -(*a - *b) : (*a - *b);
    // int diff = abs(*a - *b); // 使用 abs 计算绝对值,#include <stdlib.h> // 包含 abs 函数的头文件
    *a = sum;
    *b = diff;
}

int main()
{
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b); //&a 和 &b：传递变量 a 和 b 的地址给 scanf，使它可以将输入的值存储到这些地址中
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}

/*
 scanf("%d %d", &a, &b);的本质就是从输入中读取值，并将这些值存储到变量 a 和 b 所在的内存地址中。
  将识别出的第一个整数 4 写入地址 &a（0x1000）
  。。。。。
scanf 通过地址知道变量的位置，然后将输入的值存储到这个地址中
a 是变量的值，scanf 无法得知变量的内存地址，也就无法修改它的值
所以一般用法都是
scanf("%d", &a);  // 传递 a 的地址，允许 scanf 修改 a 的值
scanf("%d", a);   // 错误：a 是值，不是地址

C 语言的函数参数传递机制是 按值传递 当一个变量被传递到函数时，函数接收到的是变量值的副本。
这种情况下，函数无法修改调用者的变量。
通过传递变量的地址，函数可以操作原变量，而不仅仅是它的副本。
scanf 通过地址直接修改原变量的值

void modify(int a) {
    a = 20;  // 修改的是 a 的副本
}

void modifyPointer(int* a) {
    *a = 20;  // 修改的是原变量
}

int main() {
    int x = 10;

    modify(x);  // 按值传递，x 不会被修改
    printf("x after modify: %d\n", x);//10

    modifyPointer(&x);  // 按地址传递，x 会被修改
    printf("x after modifyPointer: %d\n", x); //20

而如果因为变量本身就是地址， 则scanf 不需要 &
(1) 字符数组（字符串）
字符数组的名称本身就是指针，不需要使用 &。
char str[100];
scanf("%s", str);  // 不需要写成 &str，因为 str 已经是地址
(2) 已经是指针的变量
如果变量本身是指针，scanf 就不需要再取地址。
int a;
int* p = &a;
scanf("%d", p);  // p 本身是指向 a 的地址
总结来说，在使用 scanf 时，任何普通变量都需要 & 来传递地址

*/