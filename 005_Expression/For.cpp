/*
C++11  範圍 For Loop

for (型別 變數名稱 : 序列)
{
    // 陣列中的元素
}

*/


#include<iostream>
using namespace std;


int main()
{
    for (int i = 0; i < 5; i++)
    {
        cout << "i is " << i << endl;
    }

    int a[5] = {1, 2, 3, 4, 5};

    for (int n : a)
    {
        cout << n << endl;
    }
    return 0;
}