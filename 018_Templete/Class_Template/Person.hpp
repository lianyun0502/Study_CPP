/*

.hpp file is used to store the template class definition.

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

