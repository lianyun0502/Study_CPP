/*
* 指向指針的指針
    - 指向指針的指針是一種特殊的指針，它的值是另一個指針的地址
    - 語法：type** var-name;

*/


#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int* p = &a;
    int** pp = &p;

    cout << "a is " << a << endl;
    cout << "p is " << p << endl; // p是a的地址
    cout << "pp is " << pp << endl; // pp是p的地址

    cout << "*p is " << *p << endl; // *p是a的值
    cout << "**pp is " << **pp << endl; // **pp是a的值

    return 0;
}