/*
把相同型別的資料放在一起，並且給予一個名稱，這樣的名稱就是陣列。
在記憶體中，陣列的資料是連續存放的，所以可以透過索引值來存取資料。

- 需指名陣列的型別
- 陣列的大小必須是"常數"，不能是變數
- 有初始化的陣列，可以不指定大小，編譯器會自動計算大小
- 如果陣列大小和初始化的資料數量不一致，資料列小於陣列大小，則剩餘的元素會被初始化為0，大於的話，會有編譯錯誤
- 陣列不能直接指定給另一個陣列，可以透過迴圈來複製陣列

- 如果去索引超過陣列大小的元素會發生甚麼事情？ Answer: 合法語法，會取到記憶體中的某個資料，可能是其他變數的值，可能是垃圾值，任意修改極度危險。
- 如何知道沒指定長度的陣列大小？ Answer: sizeof(a)/sizeof(a[0])
- 直接cout陣列會得到甚麼結果？ Answer: 陣列的記憶體位置


在C++11中有新定義的一個資料結構 Array，可以用來取代傳統的陣列，Array可以透過size()方法取得大小，也可以透過at()方法來存取元素，並且會檢查索引值是否合法。


*/

#include <iostream>
using namespace std;

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {1, 2, 3, 4, 5};
    int c[5] = {1, 2, 3};
    // int d[] = c; //error
    int e[5] = {1, 2, 3, 4};        //ok
    // int f[5] = {1, 2, 3, 4, 5, 6}; //error

    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << endl;
    }

    int g[5];
    for (int i = 0; i < 5; i++)
    {
        g[i] = i;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << g[i] << endl;
    }

    return 0;
}