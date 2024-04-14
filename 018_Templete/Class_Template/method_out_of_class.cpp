/*

模板類別的類外函數

- 記得類別內要聲明類別外的函數(參數也要寫)
- 類外函數的類別作用域要加上模板參數

*/

#include <iostream>
using namespace std;

template <class T1, class T2>
class Person
{
    T1 name_;
    T2 age_;

public:
    Person(T1 name, T2 age);
};

template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) : name_(name), age_(age)
{
    cout << "name: " << name_ << " age: " << age_ << endl;
}

int main()
{
    Person<string, int> p1("Tom", 20);
    return 0;
}