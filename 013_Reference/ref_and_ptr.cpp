#include<iostream>
using namespace std;

int main()
{
    int a = 10;

    // 綁訂指標的參考
    int * ptr = &a;
    int* & pref = ptr; // pref是ptr的參考

    *pref = 20; // 通過pref修改a的值

    cout << "a is " << a << endl;

    //為什麼要使用指標的參考?
    //1. 為了讓指標的指向可以被改變
    //2. 為了讓指標的指向可以被函數修改
    //3. 為了讓指標的指向可以被函數返回


    //指向參考的指標
    int b = 30;
    int & ref = b;
    // int& *p = ref; // 沒有這種用法，因為參考(ref)本身是沒有地址的，他只是參考一個變數
    int* p = &ref; // p是指向int類型的指標，並且指向ref



    return 0;
}