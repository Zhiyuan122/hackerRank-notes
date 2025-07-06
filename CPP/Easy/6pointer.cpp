/*
summary:
（1）声明指针变量：星号和类型放在一起的时候，就改变了类型的定义，表示该变量现在是一个XX型指针
     如 int * px = &x;
     integer pointer named px(pointer to x用P前缀表示指针是一个习惯用法)  is set to  "the address of" x 
     目的： accessing X by reference instead of by value 通过引用来传递而非值
//
 (2)解引用dereference: 星号和类型没有放在一起的时候,通过指针找到对应内存地址，并读取其中的值
 举例：若想用这个指针把X的值赋给新变量，
       则int y = *px; y等于指针PX解引用的值
   integer y is set to the thing pointed to by px

   快速索引表：
   &x: the address of" x 变量X的地址
   *x: the thing pointed to by x  指针x所指向的东西
   int * x:  integer pointer named x 整数型指针X


为什么需要指针
1.函数参数传引用（pass by reference）
 比如C中当一个结构体或变量不在函数作用域内，为了让函数修改原始变量, 我们需要通过引用传参“pass the struct by reference”传入指针（地址）。,使得结构体的指针进入XX的作用域，进行修改,目的是为了在函数中直接修改调用者的值
  void modify(struct Data *d);  // 传入结构体指针
  
       我们要“修改主函数里的变量”，才需要传地址，用指针
       void update(int a, int b);   // 拿到的是 a 和 b 的“副本” 默认是值传递（pass by value）
       这样写，你在函数里怎么修改 a, b，主函数里的 a, b 都不会变，因为你改的是副本。
           void update(int *a, int *b);
       主函数中再传地址进去：
           update(&a, &b);
是否使用指针，关键在于你是否想“在函数中修改主函数变量的值”。
想改：传地址 → 函数用指针参数（或引用）

不想改：传值 → 函数内部自己玩


2. 静态分配内存 static allocation  通常放在栈内存中始终在函数作用域内有效，但是当动态内存分配（dynamic allocation）时，通过malloc从堆内存/sbreak等内存分配器分配的内存，你会得到一个指向越界内存的指针（a pointer to memory that is out of scope）
   二者区别是，一个的大小在compile的时候就确定了，另一个在程序运行的时候能改变
   1)静态内存分配（static allocation）：
   变量大小在编译期确定
   通常分配在栈（stack）
   生命周期受限于函数作用域
  
   2)动态内存分配（dynamic allocation）：
   比如通过 malloc、new
   分配在堆（heap）
   生命周期可控
   返回的是“指向堆空间的指针”，可能超出当前作用域 → 必须用指针来管理

定义用 & 是引用，使用用 & 是地址。
| 场景              | `&` 的含义    | 例子              |
| --------------- | ---------- | --------------- |
|  **声明/定义变量时**  | 表示“引用”（别名） | `int& ref = x;` |
|  **表达式/使用变量时** | 表示“取地址”    | `int* p = &x;`  |
引用（reference） 和它绑定的变量只占同一块内存，不会单独分配内存空间。
没有在内存中再新开一块空间给 ref，而是让 ref 这个名字直接映射到 x 的内存地址。


三者对比
普通值传递（传副本）
void update(int a){
     a = a+1;
}
int main(){
     int x = 10;
     update(x);
     cout << x ; // // 还是 10
     return 0;
}

地址传递（传指针）：
void update(int* x){
     *a = *a + 1; // 解引用修改原值
}
int main(){
     int x =10;
     update(&x);
     return 0;  // 变成 11
}

C++ 专属：引用传递
看起来像“传值”实际是传引用”，能直接修改原变量
更安全：不需要解引用 *，不可能出现空指针 nullptr
void update(int& a){
     a = a+1;
}
int mian(){
     int x =10;
     update(x);  // 看起来像值传递，其实是引用
     return 0;  // 输出 11
}

void update_by_ptr(int* a) { *a = *a + 1; }     // 指针方式
void update_by_ref(int& a) { a = a + 1; }       // 引用方式

int main(){
     int x = 10;
     update_by_ptr(&x);   // 要写 &x
     update_by_ref(x);    // 看起来像传值，实际传引用
     return 0;
}


PS:
方法一（推荐）
   函数声明（告诉编译器有这个函数）
   void update(int *a, int *b);
   
   int main() {
       // 主函数里可以使用 update()
       update(&a, &b);
   }
   
   void update(int *a, int *b) {
       // 真正的实现
   }

 方法二：直接先写函数定义，再写主函数


记忆：
int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b); // scanf() 的第二个及后续参数必须是变量的“地址”，因为要把你输入的值写到那块内存里。
    update(pa, pb);
    printf("%d\n%d", a, b);
    
    return 0;

}

例外：char name[100];
scanf("%s", name);   // ⚠️ 不用加 &，因为 name 本身就是地址
scanf() 要做的事情是：
读取你输入的数据 → 把这个数据“写”到变量里
那就必须知道这个变量在内存的哪个位置 → 所以你要传地址
换句话说：
你告诉 scanf()：
你就把读到的东西写到这个地址上吧


int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);// ✅ 传指针
    //update(*pa, *pb); ❌ 错：你传的是“值”而不是“地址”； int* pa 这么写你就明白了
    
    printf("%d\n%d", a, b);
    
    //主函数调用时传入的是指针（地址），函数实现时接收的是指针类型（int*）

    return 0;
}





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
