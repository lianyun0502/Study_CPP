/*
函數指針

*/
#include <iostream>
#include <string>
using namespace std;

string studentInfo(string name, int age)
{
    return "name: " + name + ", age: " + to_string(age);
}

const string& longString(const string& str1, const string& str2)
{
    return str1.size() > str2.size() ? str1 : str2;
}


// 函數指針作為函數參數

const string & selectString(const string& str1, const string& str2, const string& (*p)(const string&, const string&))
{
    return p(str1, str2);
} 

// 寫法二

typedef const string& (*pLongString)(const string&, const string&);

const string & selectString2(const string& str1, const string& str2, pLongString p)
{
    return p(str1, str2);
}

// 寫法三 (C++11)

typedef decltype(longString) LongString2; // decltype 是一個運算符，用來獲取表達式的類型,最後在定義一個新的類型名稱
typedef decltype(longString) *pLongString2; // 函數指針
const string & selectString3(const string& str1, const string& str2, LongString2 p)
{
    return p(str1, str2);
}


// 函數指針作為函數返回值

// LongString2 selectString4(const string& str1, const string& str2) // 錯的，不能返回函數類型
// {
//     return longString;
// }

pLongString2 selectString5(const string& str1, const string& str2)
{
    return longString;
}

int main()
{
    // 定義一個函數指針
    string (*p)(string, int) = nullptr;
    p = studentInfo;

    // 通過函數指針調用函數
    cout << p("John", 18) << endl;

    // 定義一個函數指針
    const string& (*p2)(const string&, const string&) = nullptr;    
    p2 = longString;

    // 通過函數指針調用函數
    cout << p2("hello", "world") << endl;

    return 0;
}