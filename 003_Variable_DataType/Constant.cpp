#include<iostream>
using namespace std;

// 常量為一個固定的值，編譯後不可改變

/* 
1. 符號常量 (Symbolic Constants)
    -使用 #define 預處理器
    -C的寫法，不推薦使用
    -"#" 代表預處理器，預處理器會在編譯前處理代碼，將代碼中的 #define 替換為後面的值
 */
#define ZERO 0
#define PI 3.14159
#define NAME "John"

/*
2. const 修飾符
    -C++的寫法，推薦使用
    -const 修飾符定義常量，並且可以定義常量的類型
    -const 修飾符定義的常量在編譯時就會被確定，不可改變
 */

const int Zero = 0;
const float Pi = 3.14159;
const string Name = "John";

int main(){
    cout<<"Zero: "<<ZERO<<endl;
    cout<<"Pi: "<<PI<<endl;
    cout<<"Name: "<<NAME<<endl;

    cout<<"Zero: "<<Zero<<endl;
    cout<<"Pi: "<<Pi<<endl;
    cout<<"Name: "<<Name<<endl;

    cin.get();
    return 0;
}