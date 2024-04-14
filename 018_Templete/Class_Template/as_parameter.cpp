/*

* 類別模板做參數傳入
    - 指定傳入參數的類型
    - 參數模板化
    - 整個類別模板化

!! 第一種居然使用最廣泛

*/

#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

template<class T1, class T2>
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

// 1. 類模板做參數傳入

void PrintPerson(Person<string, int> &p){
    // 我個人會認為這樣的寫法沒有很好，因為這樣就有點失去了泛型的意義。不過如果本來這就是個需要限制型別的函數，那這樣的寫法就是可以的。
    p.ShowPerson();
}

void test01(){
    Person<string, int> p1("Tom", 20);
    
    PrintPerson(p1);
}


// 2. 參數模板化
// 這樣寫稍嫌麻煩，但是這樣的寫法可以讓函數更加通用，可以接受任何類型的參數

template<class T1, class T2>
void PrintPerson2(Person<T1, T2> &p){
    p.ShowPerson();

    cout << "T1 type is : " << typeid(T1).name() << endl;
    cout << "T2 type is : " << typeid(T2).name() << endl;
}

void test02(){
    Person<string, int> p1("Tom", 20);
    PrintPerson2(p1);
}

// 3. 整個類別模板化
// 這樣的寫法可以讓函數更加通用，可以接受任何類型的參數，但是可讀性會稍差，因為這樣的寫法會讓人不知道這個函數到底是要接受什麼樣的參數，需要註解

template<class T>
void PrintPerson3(T &p){
    p.ShowPerson();
    cout << "T type is : " << typeid(T).name() << endl;
}

void test03(){
    Person<string, int> p1("Tom", 20);
    PrintPerson3(p1);
}


int main(){
    test01();
    test02();
    test03();
    return 0;
}