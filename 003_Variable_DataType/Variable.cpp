#include<iostream>
using namespace std;


// in {} is mean in the "scope"，variable a is defined in the scope of main function
// 在函數中定義的變量稱為局部變量(local variable)，在函數外定義的變量稱為全局變量(global variable)
// 在函數中定義的變量只能在該函數中使用，而在函數外定義的變量可以在整個程序中使用(同名變量會以最接近作用域的變量為主)



int a = 20;
int b; // 全局變量可以不定義初始值，局部變量必須先定義初始值

void example(){
    // 如果想在函數中使用全局變量，可以使用作用域解析運算符(::)
    cout<<"Value of a in main: "<<::a<<endl;
    cout<<"Value of b in main: "<<::b<<endl; // 全局變量才可以不先定義初始值，int 會自動初始化為0
    int a = 30;
    cout<<"Value of a in example: "<<a<<endl;

}


int main(){
    int a = 10;
    float b = 10.5;
    char c = 'A';
    bool d = true;
    std::cout<<"Value of a: "<<a<<std::endl;
    std::cout<<"Value of b: "<<b<<std::endl;
    std::cout<<"Value of c: "<<c<<std::endl;
    std::cout<<"Value of d: "<<d<<std::endl;
    example();
    cin.get();
    return 0;
}