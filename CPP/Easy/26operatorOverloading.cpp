/*
运算符重载（Operator Overloading）
C++ 允许重载运算符，使其适用于用户定义的类。运算符重载的基本语法为：
    返回类型 operator符号 (参数列表) {
        // 实现逻辑}

Complex operator+(const Complex& c1, const Complex& c2);

        之所以要使用 &（引用），是为了提高效率并避免不必要的拷贝，同时确保参数的值不会被修改
        为什么加 &（引用）：
                避免对象的拷贝，提升性能。
                减少不必要的内存分配。
                避免构造/析构的额外开销。
        为什么加 const：
                确保参数在函数内部不会被修改，提高代码安全性。
                允许使用 const 对象作为参数，提高灵活性。

        Complex operator+(Complex c1, Complex c2);  // 传值，会触发拷贝

        Complex operator+(const Complex& c1, const Complex& c2);  // 传引用，不拷贝

        Complex a(1.0, 2.0), b(3.0, 4.0);
        Complex c = a + b;  // 调用 operator+时a 和 b 都会被拷贝到 operator+ 函数中，意味着会调用两次拷贝构造函数，这对性能不利。
        c1 和 c2 只是引用传递，不会有额外的拷贝，性能更高。

总结（常见写法归纳）
运算符类型	推荐写法示例	是否使用 const &
算术运算符（+,-,*,/）	ClassName operator+(const ClassName& lhs, const ClassName& rhs);	是
赋值运算符（+=,-=）	ClassName& operator+=(const ClassName& other);	是
比较运算符（==, !=）	bool operator==(const ClassName& other) const;	是
自增/自减（++ --）	ClassName& operator++();（前置）	无
输入/输出运算符	friend std::ostream& operator<<(std::ostream& os, const ClassName& obj);	是（输入无）



*/