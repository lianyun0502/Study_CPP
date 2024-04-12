/*

const 修飾成員函數

this 指針其實是一個指針常數，所以是不能修改指針的指向的，但是可以修改指針指向的值
如果想要保護成員函數不被修改，可以在成員函數後加上 const 修飾，這樣函數就不能修改成員變數了
同等於 const Person * const this

mutable 修飾成員變數
如果想要在 const 函數中修改成員變數，可以在成員變數前加上 mutable 修飾


const 修飾物件

const 修飾物件，物件的成員變數不能被修改，除非成員變數前加上 mutable 修飾


*/


#include <iostream>
using namespace std;

class Person
{

public:
    string name = "Eric";
    mutable int age = 30; // mutable 修飾成員變數
    void show() const // const 修飾成員函數
    {
        // name = "Tom"; // 錯誤，不能修改成員變數
        // this = nullptr; // 錯誤，不能修改指針的指向
        age = 20; // 正確，可以修改 mutable 修飾的成員變數
        cout << "show()" << endl;
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
    }

    void show_not_const()
    {
        cout << "show()" << endl;
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
    }


};

int main()
{
    const Person p; // const 修飾物件
    // p.show_not_const(); // 錯誤，不能調用非 const 成員函數
    p.age = 20; // 正確，可以修改 mutable 修飾的成員變數
    p.show(); // 正確，可以調用 const 成員函數

    return 0;
}