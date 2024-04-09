/*
默認參數 (C++)

在C++才有默認參數的概念，默認參數是指在函數定義時給參數一個初始值，這樣在調用函數時可以不給參數，默認使用初始值。

* 如果函數有多個參數，給其中一個參數默認值，則其後的參數都必須給默認值。
* 必須按照順序給參數默認值，不能跳過。


*/

#include <iostream>
using namespace std;

// 函數定義時給參數一個初始值
int sum(int a, int b = 20){
    return a + b;
}

int main()
{
    cout << "sum is " << sum(10) << endl; // 調用函數時不給參數，默認使用初始值
    cout << "sum is " << sum(10, 30) << endl; // 調用函數時給參數，使用給定的值

    return 0;
}