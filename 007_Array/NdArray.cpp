/*
多維陣列

- 二維陣列一定要指定第二維的大小
*/
#include <iostream>
using namespace std;

int main()
{
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};

    // 遍歷二維陣列
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // 索引
            cout << a[i][j] << " ";
        }
        cout << endl;
    }


    // C++11 範圍 For Loop
    for (auto& row : a ) // auto是C++11的新特性，自動判斷型別，&是參考
    {
        for (auto col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    return 0;
}