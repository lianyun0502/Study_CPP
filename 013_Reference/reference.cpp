/*
直接為一個數據對象取一個別名，這個別名就是參考(reference)。
    - 參考的宣告：Type& name = object;
    - 參考的初始化：參考"必須在宣告時進行初始化"，且一旦初始化完成，就不能再參考其他對象，對象必須是變數。
    - 參考"不能直接存放數據"，它只是對它所指向的對象的一個別名。
    - 型別必須匹配參考對象的型別。
    - 參考的使用：參考就是它所指向的對象的別名，對參考的操作就是對它所指向的對象的操作。

* 參考的參考
    - 參考的參考的宣告：Type&& name = object;
    - 參考的參考的初始化：參考的參考"必須在宣告時進行初始化"，且一旦初始化完成，就不能再參考其他對象。
    - 參考的參考的使用：參考的參考就是它所指向的對象的別名，對參考的參考的操作就是對它所指向的對象的操作。
    - 使用時機：參考的參考主要用於函數的返回值，用於返回一個對象的參考。

*/
#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int& ref = a; // ref是a的參考

    cout << "a is " << a << endl;
    cout << "ref is " << ref << endl;
    cout << "a address is " << &a << endl;
    cout << "ref address is " << &ref << endl;

    ref = 20; // 通過ref修改a的值

    cout << "a is " << a << endl;
    cout << "ref is " << ref << endl;

    int c = 30; 
    ref = c; // 通過ref修改a的值成c的值，但是ref本身不會指向c

    cout << "a is " << a << endl;
    cout << "a address is " << &a << endl; 
    cout << "ref is " << ref << endl;
    cout << "ref address is " << &ref << endl; 

    cout << "c is " << c << endl;
    cout << "c address is " << &c << endl; 

    return 0;
}