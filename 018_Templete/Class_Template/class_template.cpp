/*

類別模板(Class Template)是一種通用的類別，可以用來建立具有不同資料型態的物件。

* 類模板與函數模板的差別:
    - 類模板可以有默認參數
    - 類模版創建物件時一定要有顯式的指定資料型態

* 類別模板與普通類別在成員函數實現上的區別:
    - 一般類別的函數是在一開始就創建出來的(編譯時期)
    - 類模板中的成員函數在調用時才會實例化(實例化時期)，可以想成因為編譯時期不知道資料型態，所以無法創建出函數
    - 這差異會影響例如: 類外函數以及編寫header file時的實現方式



*/

#include <iostream>
using namespace std;



template<class T1, class T2 = int>
class Person
{
    T1 name_;
    T2 age_;

public:
    Person(T1 name, T2 age):name_(name), age_(age){};
    void ShowPerson(){
        cout << "name: " << name_ << " age: " << age_ << endl;
    }
};


class Person1
{
public:

    void ShowPerson1(){
        cout << "show person 1" << endl;
    }
};

class Person2
{
public:

    void ShowPerson2(){
        cout << "show person 2" << endl;
    }
};


template<class T>
class MyClass
{
    T obj;
public:
    MyClass(T &obj){
        this->obj = obj;
    }
    void ShowObj(){
        // 編譯時期不會抱錯，但是在實例化時會報錯，因為類別模板的函數是在調用時才實例化的
        // 個人會覺得這是很不好的寫法與設計
        obj.ShowPerson1();
        obj.ShowPerson2();
    }
};

int main(){
    Person<string, int> p("Tom", 20); // 這裡要顯式指定資料型態
    p.ShowPerson();

    Person<string> p2("Jerry", 30); // 這裡只指定了一個資料型態，默認第二個參數是int
    p2.ShowPerson();

    Person1 p1;
    MyClass<Person1> c1(p1);
    c1.ShowObj(); // 編譯時期不會抱錯，但是在實例化時會報錯，因為類別模板的函數是在調用時才實例化的


    return 0;
}