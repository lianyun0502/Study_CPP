/*
類別的靜態成員

- 靜態成員是屬於類別的成員，而不是屬於物件的成員。
- 靜態成員可以被所有的物件共用，而不是每個物件都有一份。
- 靜態成員可以是資料成員或函數成員，會在前面加關鍵字 static。

靜態成員屬變數
- 所有物件會共享一份靜態成員變數。
- 會再編譯時期配置記憶體空間，並在程式執行前初始化。
- 類別內宣告，但在類別外定義。

靜態成員函數
- 靜態成員函數只能存取靜態成員變數。
- 所有物件共用一份靜態成員函數。


訪問靜態成員變數
- 通過類名訪問靜態成員變數，類名::靜態成員變數。
- 通過物件訪問靜態成員變數。

*/

#include <iostream>
using namespace std;

class Person
{
public:
    static int num_legs; // 靜態成員變數,類內聲明
    static int num_arms;

    static void show_num_legs()
    {
        cout << "num_legs: " << num_legs << endl;
    }
};

int Person::num_legs = 2; // 靜態成員變數,類外定義
int Person::num_arms = 2;


int main()
{
    cout << "num_legs: " << Person::num_legs << endl; // 通過類名訪問靜態成員變數
    cout << "num_arms: " << Person::num_arms << endl;

    Person::show_num_legs();


    Person p1;
    Person p2;
    p1.num_legs = 4;    
    cout << "num_legs: " << p2.num_legs << endl; // 共用一份靜態成員變數，通過物件訪問

    return 0;
}
