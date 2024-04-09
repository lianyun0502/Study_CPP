/*
C中的字符串是以'\0'結尾的字符"數組"
在C++中有定義一個string數據類別，可以用來代替C中的字符串

- string 可以用來表示"長度可變"的字符串
- 需要包含<string>頭文件


*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "Hello, World!";
    cout << str << endl;

    // 字符串相加
    string str1 = "Hello, ";
    string str2 = "World!";
    string str3 = str1 + str2; // 字符串相加是C++ string的特性，C中的字符串不能直接相加
    cout << str3 << endl;

    // 字符串長度
    cout << "str3 length is " << str3.length() << endl;

    // 字符串比較
    string str11 = "Hello, ";
    string str12 = "World!";
    if (str11 == str12)
    {
        cout << "str11 is equal to str12" << endl;
    }
    else
    {
        cout << "str11 is not equal to str12" << endl;
    }

    // 索引
    cout << "str3[0] is " << str3[0] << endl;

    // 字符串查找
    string str4 = "Hello, World!";
    string str5 = "World";
    size_t found = str4.find(str5);
    if (found != string::npos)
    {
        cout << "found " << str5 << " at " << found << endl;
    }
    else
    {
        cout << "not found " << str5 << endl;
    }

    // 字符串截取
    string str6 = "Hello, World!";
    string str7 = str6.substr(7, 5);
    cout << "str7 is " << str7 << endl;

    // 字符串替換
    string str8 = "Hello, World!";
    string str9 = "World";
    string str10 = "C++";
    str8.replace(str8.find(str9), str9.length(), str10);
    cout << "str8 is " << str8 << endl;

    //遍歷字符串
    for (int i = 0; i < str8.length(); i++)
    {
        cout << str8[i] << " ";
    }
    cout << endl;

    return 0;
}