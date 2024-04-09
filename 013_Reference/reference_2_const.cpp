/*
對常數(const)的參考
    - 對常數的參考是一種常數參考，即在聲明時在類型名稱前加const關鍵字
    - 初始化可以使用常量或者變量來初始化，也可以使用表達式來初始化
    - 對常數的引用不能修改其值
    - 可以將常數賦值給常數引用，也能將變量賦值給常數引用
    - 對常數的引用主要用於函數參數的傳遞，可以防止誤操作


*/
#include <iostream>
using namespace std;

int main()
{
    const int a = 10;
    const int& ref = a; // ref是a的常數參考

    cout << "a is " << a << endl;
    cout << "ref is " << ref << endl;

    // ref = 20; // 不能通過ref修改a的值

    int b = 20;
    // ref = b; // 不能通過ref修改a的值成b的值

    cout << "a is " << a << endl;
    cout << "ref is " << ref << endl;

    const int & ref2 = b; // 可以將變量賦值給常數引用
    const int & ref3 = 30; // 可以將常數賦值給常數引用

    cout << "ref2 is " << ref2 << endl;
    cout << "ref3 is " << ref3 << endl;

    return 0;
}