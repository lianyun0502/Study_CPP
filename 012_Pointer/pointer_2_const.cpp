/*
指向常量的指针
    - 指向常量的指针不能通过指针修改所指向的内容
    - 指向常量的指针可以指向变量，不可以指向常量
    - 宣告指向常量的指针的方法：const int *ptr


指针常量
    - 指针常量不能修改指针的指向 (只能指向初始化时的地址)
    - 指针常量可以通过指针修改所指向的内容
    - 宣告指针常量的方法：int *const ptr
*/

#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    const int b = 20;

    int* p1 = &a; // 指向整數的指針
    const int* p2 = &a; // 指向整數的常量指針
    int* const p3 = &a; // 指向整數的指針常量
    const int* const p4 = &a; // 指向整數的常量指針常量

    cout << "a is " << a << endl;
    cout << "b is " << b << endl;

    cout << "*p1 is " << *p1 << endl;
    cout << "*p2 is " << *p2 << endl;
    cout << "*p3 is " << *p3 << endl;
    cout << "*p4 is " << *p4 << endl;

    // p1 = &b; // p1不可以指向b
    // *p1 = 30; // 不能通過p1修改b的值

    p2 = &b; // p2可以指向b
    // *p2 = 30; // 不能通過p2修改b的值

    // p3 = &b; // 不能修改p3的指向
    *p3 = 30; // 可以通過p3修改a的值

    // p4 = &b; // 不能修改p4的指向
    // *p4 = 30; // 不能通過p4修改b的值


    // ============================
    const int c = 40;
    
    int * const p5 = &a; // 指向整數的指針常量

    // p5 = &b; // 不能修改p5的指向
    *p5 = 50; // 可以通過p5修改a的值

    cout << "a is " << a << endl;

    return 0;
}