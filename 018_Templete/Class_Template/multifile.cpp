/*

分文件編寫

問題:
    模板類的的成員函數是在執行階段調用才生成的，所以編譯會鏈結不到對應的函數定義，所以會報錯。

解決方法:
    - 直接包含cpp文件
    - 將模板類的聲明和定義放在一個文件中，並使用.hpp後綴

*/

#include <iostream>
#include "Person.hpp"

int main()
{
    Person<string, int> p1("Tom", 20);
    return 0;
}