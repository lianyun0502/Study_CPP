/*
* 靜態變數
    - 靜態變數的生命週期是整個程式的執行期間
    - 靜態變數的初始化只會在第一次進入函數時執行
    - 靜態變數的記憶體位置在程式的資料區
    - 局部靜態變數只能在函數內部使用 

*靜態變數與全局變數的差別是甚麼?
    - 靜態變數只能在函數內部使用
    - 全局變數可以在程式的任何地方使用
    - 靜態變數和全局變數的生命週期是整個程式的執行期間
    - 靜態變數和全局變數的記憶體位置在程式的資料區，一般變數是存在stack裡

    



*/

#include <iostream>
using namespace std;

int call_time(); // 如果函數在main函數之後定義，則需要在main函數之前聲明

int main(){
    call_time();
    call_time();
    call_time();
    call_time();
    call_time();
    return 0;
}

int call_time(){
    static int a = 0; // 靜態變數
    a++;
    cout << "number of function called is " << a << endl;
    return a;
}