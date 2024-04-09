/* char 字元型別
    - 用來表示單一字元
    - 字元型別可以用單引號 '' 表示
    - 字元型別可以用 ASCII 編碼 (0~127 最常見)
    - 字元型別可以用 Unicode 表示
    - 字元型別可以用 UTF-8 表示
    - 字元型別可以用 UTF-16 表示
    - 字元型別可以用 UTF-32 表示

*/ 

/*
wchar_t 寬字元型別 (C++)
    - 用來表示單一字元
    - 寬字元型別可以用 L'' 表示
    - 寬字元型別可以用 Unicode 表示
    - 寬字元型別可以用 UTF-16 表示
    - 寬字元型別可以用 UTF-32 表示
    - 寬字元型別可以用 wchar_t 表示
    - 寬字元型別可以用 wstring 表示
    - 寬字元型別可以用 wcin, wcout, wcerr, wclog 表示

char16_t 16位元字元型別 (C++11)
    - 用來表示單一字元
    - 16位元字元型別可以用 u'' 表示
    - 16位元字元型別可以用 Unicode 表示
    - 16位元字元型別可以用 UTF-16 表示
    - 16位元字元型別可以用 char16_t 表示
    - 16位元字元型別可以用 u16string 表示

char32_t 32位元字元型別 (C++11)
    - 用來表示單一字元
    - 32位元字元型別可以用 U'' 表示
    - 32位元字元型別可以用 Unicode 表示
    - 32位元字元型別可以用 UTF-32 表示
    - 32位元字元型別可以用 char32_t 表示
    - 32位元字元型別可以用 u32string 表示

*/

#include <iostream>
using namespace std;

int main()
{
    char c = 65; // ASCII code for 'A'
    cout<<"Value of c: "<<c<<endl;
    cout<<"Value of c + 1 : "<< c+1 <<"(直接加1會變成數字)"<<endl;
    char d = c+1;
    cout<<"Value of d: "<<d<<endl;

    cin.get();
    return 0;
}