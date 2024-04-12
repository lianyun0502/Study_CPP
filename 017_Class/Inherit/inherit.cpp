/**
 繼承 (Inherit)
    1. 繼承的基本語法
        class 子類別名稱 : 繼承方式 父類別名稱
        {
            // 子類別新增的成員
        };

    2. 繼承方式
        - public: 公共繼承 -> 子類別中的成員訪問權限和父類別中的一樣，父類private成員不能被訪問
        - protected: 保護繼承 -> 子類別中的成員訪問權限和變成protected，父類private成員不能被訪問
        - private: 私有繼承 -> 子類別中的成員訪問權限變成private，父類private成員不能被訪問

    3. 繼承的特點
        - 所有父類別的非靜態屬性都會被子類別繼承下來，記憶體中會複製一份
        - 如果想拿到父類別的同名屬性，可以使用作用域解析運算符(::)來訪問
        - 如果想要調用父類別的同名函數，可以使用作用域解析運算符(::)來訪問 (子.父類名::函數名)
        - 靜態成員不會被繼承，如果有同名靜態成員，子類會隱藏父類的同名成員，可以使用作用域解析運算符(::)來訪問
            - 透過物件訪問 -> 子類.父類::靜態成員
            - 透過類別訪問 -> 子類::父類::靜態成員
*/
#include <iostream>
using namespace std;

class Animal
{
protected:
    string name = "Animal";
public:
    int age;

    Animal()
    {
        cout << "Animal constructor" << endl;
    }
    ~Animal()
    {
        cout << "Animal destructor" << endl;
    }
    void eat()
    {
        cout << name << " eat" << endl;
    }
    void sleep()
    {
        cout << name <<" sleep" << endl;
    }
    void show()
    {
        cout << name << " age = " << age << endl;
    }
};

class Dog : public Animal{

public:
    Dog()
    {
        cout << "Dog constructor" << endl;
        name = "Dog";
    }
    ~Dog()
    {
        cout << "Dog destructor" << endl;
    }
};

class Cat : public Animal{
public:
    Cat()
    {
        cout << "Cat constructor" << endl;
        name = "Cat";
    }
    ~Cat()
    {
        cout << "Cat destructor" << endl;
    }
};

int main()
{
    Dog d;
    d.age = 3;
    d.show();
    d.eat();
    d.sleep();

    Cat c;
    c.age = 2;
    c.show();
    c.eat();
    c.sleep();

    return 0;
}
