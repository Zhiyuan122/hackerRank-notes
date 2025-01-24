#include <iostream>
using namespace std;

class Rectangle
{
protected:
    int width, height; // 保护成员，子类可以访问，外部不行

public:
    void display()
    {
        cout << width << " " << height << endl; // 直接访问基类的 protected 成员
    }
};

class RectangleArea : public Rectangle
{
public:
    void read_input()
    {
        cin >> width >> height;
    }

    void display()
    {
        cout << width * height << endl;
    }
};

int main()
{
    RectangleArea r;
    r.read_input();
    r.Rectangle ::display(); // 调用基类方法
    r.display();             // 调用派生类方法
    return 0;
}

/*

继承后不需要在子类中重复定义基类的成员变量
protected 的数据
或
private 的数据+ public的访问接口（如 getter/setter）。



A:
void display() {
    cout << width << " " << height << endl;
}

B:
int calculateArea() {
    return width * height;
}

// 调用时：
int area = r.calculateArea();
cout << "The area is: " << area << endl;

如果调用者需要对返回值进行进一步计算、存储或逻辑操作，应使用返回值。
而不需要在代码中再次使用这些数据，直接 cout 即可


#include <iostream>
using namespace std;

class Rectangle {
private:
    int width, height;

public:
    // Setter functions to set values
    void setWidth(int w) { width = w;}
    void setHeight(int h) { height = h;}

    // Getter functions to retrieve values
    int getWidth() {return width;}
    int getHeight() {return height;}

    // Method to display the rectangle dimensions
    void display() {cout << width << " " << height << endl;}
};


class RectangleArea : public Rectangle {
public:
    void read_input() {
        int w, h;
        cin >> w >> h;

        setWidth(w);   // Using the setter function
        setHeight(h);  // Using the setter function
    }

    void display() { cout << getWidth() * getHeight() << endl;  // Using getter functions}
};

int main() {
    RectangleArea r;
    r.read_input();
    r.Rectangle::display();  // Call base class display
    r.display();  // Call derived class display (prints the area)

    return 0;
}
父类 private 成员变量不能被子类直接访问，必须通过 getter/setter 方法。
getter 方法用于读取数据，setter 方法用于修改数据。
遵循封装原则，保护类的内部数据，提供受控访问。



*/