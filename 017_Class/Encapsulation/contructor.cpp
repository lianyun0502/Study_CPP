/*
建構函數
建構函數是一個特殊的成員函數，它將在創建對象時自動調用，用於初始化對象的數據成員。
- 語法:
    class_name() { // 函數體 }
- 特點:
    - 只能是 public 權限
    - 函數名與類名相同
    - 沒有返回值 void
    - 可以有參數
    - 可以有多個建構函數
    - 可以重載
    - 可以有默認參數
    - 可以使用初始化列表

    - 可以使用委託構造函數
    - 可以使用 explicit 關鍵字
    - 可以使用 delete 關鍵字

- 分類
    * 按參數分類
        - 默認構造函數
        - 有參數構造函數
    * 按類型分類
        - 普通構造函數
        - 拷貝構造函數
        - 委託構造函數

    - explicit 關鍵字
    - delete 關鍵字
甚麼時候會使用到拷貝構造函數?
- 當使用一個對象初始化另一個物件時
- 以"傳值"方式傳遞物件給函數的參數
- 以"值返回"方式從函數返回物件

定義有參數的構造函數->沒有默認構造函數 但有默認拷貝構造函數
定義拷貝構造函數->沒有默認構造函數 也沒有默認的拷貝構造函數


解構函數
與建構函數相對應的是析構函數，它將在對象被刪除時自動調用，用於釋放對象所佔用的資源。

- 語法:
    ~class_name() { // 函數體 }
- 特點:
    - 不可以有參數
    - 不可以有返回值
    - 不可以重載

*/

#include <iostream>
using namespace std;

class Person
{
public:
    Person()
    {
        // 默認構造函數
        cout << "call Person constructor without parameter" << endl;
    }
    Person(string name, int age = 20)
    {
        // 有參數構造函數
        cout << "call Person constructor with parameter" << endl;
        this->age = age;
        this->name = name;
    }
    Person(const Person &p)
    {
        // 拷貝構造函數
        cout << "call Person copy constructor" << endl;
        this->age = p.age;
        this->name = p.name;
    }

    ~Person()
    {
        cout << "call Person destructor" << endl;
    }

    void showInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

private:
    string name;
    int age;
};

int main()
{
    Person p = Person("David");
    p.showInfo();

    Person p2 = Person(p);
    p2.showInfo();

    Person p3 = string("Eric"); // 等價於 Person p3 = Person("Eric");
    p3.showInfo();
    return 0;
}