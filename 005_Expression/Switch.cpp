/*

- 每個case後面都要加上break，否則會繼續執行下一個case
- default是當所有case都不符合時執行的部分
- 如果沒有default，也沒有符合的case，則不會執行任何部分
- case 後面的值只能是整數形別或字元型態，不能是浮點數或字串

*/

#include<iostream>
using namespace std;

int main()
{
    int x = 2;
    switch (x)
    {
    case 1:
        cout << "x is 1" << endl;
        break;
    case 2:
        cout << "x is 2" << endl;
        break;
    case 3:
        cout << "x is 3" << endl;
        break;
    default:
        cout << "x is not 1, 2, or 3" << endl;
    }
    return 0;
}