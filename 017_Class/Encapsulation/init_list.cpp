/*
初始化列表

初始化列表是在建構子函數的參數列後面，建構子函數的大括號前面，使用冒號分隔的一個列表。
語法：
class_name (parameter_list) : member1(value1), member2(value2), member3(value3) { }



*/

#include <iostream>
using namespace std;


class Person
{
private:
    string name;
    int age;
public:
    Person(string n, int a):name(n), age(a)
    {
        // name = n;
        // age = a;
    }

    void show()
    {
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
    }
};

int main()
{
    Person p("Tom", 20);
    p.show();
    return 0;
}