/*
重載(Overload)：在同一個作用域中，函數名稱相同，但是參數列表不同，這樣的函數稱為重載函數。 (C++)

- 函數名稱相同，但是參數列表不同，包括參數個數、參數資料型態、參數順序。
- 如果函數的返回值不同，不構成重載。
- 如果參數型別相同，但是名稱不同，不構成重載。因為聲明時可以不用寫出參數名稱。
- main 函數不能重載。

* 當參數有const修飾時會發生甚麼情況？
- 如果參數是傳值的，const修飾的參數和沒有const修飾的參數是一樣的。(邊都編不過)
- 如果是指針常數，const修飾的參數和沒有const修飾的參數是一樣的。(邊都編不過)
- 如果是參考常數，const修飾的參數和沒有const修飾的參數是不一樣的。因為常數只能由參考常數接收，不能由參考變數接收。
    也就是說，一個常數傳入函數時，只能由參考常數接收，不能由參考變數接收。 
- 如果是指向常數的指針，const修飾的參數和沒有const修飾的參數是不一樣的。因為常數只能由指向常數的指針接收，不能由指向變數的指針接收。
    也就是說，一個常數傳入函數時，只能由指向常數的指針接收，不能由指向變數的指針接收。

*/

#include <iostream>
using namespace std;

// 函數重載
int sum(int a, int b)
{
    return a + b;
}

int sum(int a, int b, int c)
{
    return a + b + c;
}

int sum(int a, int b, int c, int d)
{
    return a + b + c + d;
}

int main()
{
    cout << "sum is " << sum(10, 20) << endl;
    cout << "sum is " << sum(10, 20, 30) << endl;
    cout << "sum is " << sum(10, 20, 30, 40) << endl;

    return 0;
}
// Output