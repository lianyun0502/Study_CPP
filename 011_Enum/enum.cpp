/*
枚舉型別(enum)是一種自訂的資料型別，它是由一組"已知長度" "具名" 的"整數常數"所組成的資料型別。
主要用法是用來定義一組相關的常數，以便提高程式的可讀性。

枚舉型別的宣告方式如下：
enum 枚舉型別名稱 { 常數名稱1, 常數名稱2, ..., 常數名稱n };

- 枚舉型別的宣告方式與變數宣告方式相同，只是在枚舉型別名稱前加上 enum 關鍵字。(C++ 可以省略)
- 枚舉型別的常數名稱可以是任何合法的識別字，但不能重複。
- 枚舉型別的常數名稱會被自動指定整數值，從 0 開始，依序遞增。

*/
#include <iostream>
using namespace std;

enum Weekday
{
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

int main()
{
    Weekday today = Monday;
    Weekday tomorrow = Weekday(2);

    // Weekday yesterday = 0; // 會報錯，因為 0 並不是 Weekday 型別


    // cout << "Yesterday is " << Weekday.Sunday << endl; //不能直接引用 Weekday 型別的常數
    cout << "Today is " << today << endl;
    cout << "Tomorrow is " << tomorrow << endl;
   
}