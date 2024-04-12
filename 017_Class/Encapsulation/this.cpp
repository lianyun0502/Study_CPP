/*
*空的類別佔據的記憶體大小 -> 1 byte
*只有"非靜態的成員變數"才會影響物件的記憶體空間大小(屬於物件的記憶體空間)

* this指標
this指標指向"成員函數所操作的物件"
用途:
    1. 在成員函數中，如果參數名稱與成員變數名稱相同，可以使用this指標來區分
    2. 如果想要 return 物件本身，可以使用this指標 (return *this)
        - 可以實現鏈式調用
        - 參考返回 -> 返回原本的物件
        - 值返回　-> 返回新的物件



*/

#include <iostream>
using namespace std;

class Person
{
public:
    int age;
    Person(int age)
    {
        this->age = age;
    }

    Person &add_age_ref(int a)
    {
        age += a;
        return *this;
    }

    Person add_age_value(int a)
    {
        age += a;
        return *this;
    }
};

int main()
{
    Person p(20);
    cout << p.age << endl;

    p.add_age_ref(10).add_age_ref(20);
    cout << p.age << endl; // 參考返回為原本的物件

    p.add_age_value(10).add_age_value(20);
    cout << p.age << endl;// 值返回為新的物件 

    return 0;
}