/*

返回值

* 無返回值


*/

#include <iostream>
using namespace std;

// 無返回值的函數 (子過程)

void print_hello(){
    cout << "Hello World!" << endl;
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

// 有返回值的函數 (子程序)

int add(int a, int b){
    return a+b;
}

string & longer_string(string str1, string str2){
    // 返回值是參考，因為返回的是str1或str2的參考，而不是拷貝，可以增加效率

    // 用參考返回要注意返回的變數"不能是局部變數"，因為局部變數在"函數結束後會被釋放"
    // string str = "hello";
    // return str; // 這樣是錯誤的，因為str是局部變數

    return str1.size() > str2.size() ? str1 : str2;
}


// 返回陣列的函數

typedef int arrayT[5]; // 定義一個陣列類型, typedef 是一個關鍵字，用來定義新的類型名稱

arrayT * get_array(){
    int arr[5] = {1,2,3,4,5}; // 靜態局部變數，不會在函數結束後被釋放
    return &arr;
}

// 也可以這樣寫
auto fun3()-> arrayT(*)[5];

int main(){
    print_hello();
    int a = 10;
    int b = 20;
    cout << "a is " << a << endl;
    cout << "b is " << b << endl;
    swap(a,b);
    cout << "a is " << a << endl;
    cout << "b is " << b << endl;


    int sum = add(a,b);
    cout << "sum is " << sum << endl;
    return 0;
}