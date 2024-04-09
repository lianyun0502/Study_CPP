/*
我們可以注意到，印出陣列這個變數時就是陣列的位址，所以"陣列這個變數就是一個指標"。
他的指向其實就是陣列的"第一個元素的位址"。


指標運算
指標可以進行運算，這種運算稱為指針運算。指針運算有以下幾種：
    - 指針加法，即指針加上一個型別的整數，結果是一個新的指針，這個指針指向原來指針指向的位置加上整數乘以型別的大小後的位置。
    - 指針減法，即指針減去一個型別的整數，結果是一個新的指針，這個指針指向原來指針指向的位置減去整數乘以型別的大小後的位置。
    - 一個指針減去另一個指針，結果是兩個指針相減後除以型別的大小，得到的是兩個指針之間相差的元素個數。

* 指標陣列: 指針陣列是一個陣列，裡面的元素都是指標。
    - 例如: int* arr[5]; // arr是一個指標陣列，裡面有5個int型別的指標。
* 陣列指標: 陣列指標是一個指標，指向一個陣列。
    - 例如: int arr[5]; int* p = arr; // p是一個指向int型別的指標，指向陣列arr的第一個元素。
    - 或 int (* arr)[5]; // arr是一個指向包含5個int型別元素的陣列的指標。

*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    vector<int>  v = {1, 2, 3, 4, 5};

    cout << "====array==== " << endl;   
    int* p = arr; // arr是陣列的第一個元素的位址
    
    cout << "arr is " << arr << endl;
    cout << "p is " << p << endl;

    cout << "*p is " << *p << endl;
    cout << "*(p+1) is " << *(p+1) << endl; // p+1是指向arr[1]的指標(指針運算)
    cout << "*(p+2) is " << *(p+2) << endl;
    cout << "*(p+3) is " << *(p+3) << endl;
    cout << "*(p+4) is " << *(p+4) << endl;

    //cout << "====vector==== " << endl;
    //int* vp = v; // v是vector的第一個元素的位址
    //cout << "v is " << vp << endl;
    
    // 指標陣列

    int* arr2[5]; // arr2是一個指標陣列，裡面有5個int型別的指標
    int a = 10, b = 20, c = 30, d = 40, e = 50;
    arr2[0] = &a;
    arr2[1] = &b;
    arr2[2] = &c;
    arr2[3] = &d;
    arr2[4] = &e;

    cout << "====pointer array==== " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << *arr2[i] << " ";
    }
    cout << endl;

    // 陣列指標
    int arr3[5] = {1, 2, 3, 4, 5};
    int* p2 = arr3; // p2是一個指向int型別的指標，指向陣列arr3的第一個元素

    cout << "====array pointer==== " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << *(p2 + i) << " ";
    }
    cout << endl;

    return 0;
}