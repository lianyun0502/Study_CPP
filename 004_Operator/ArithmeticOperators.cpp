/*
算數運算子
+	加法
-	減法
*	乘法
/	除法
%	取餘數

運算子的優先順序
1. ()
2. ++, --, +, -, !, ~, (type), sizeof, &, *
3. *, /, %
4. +, -
5. <<, >>
6. <, <=, >, >=
7. ==, !=
8. &
9. ^
10. |
11. &&
12. ||
13. ?:
14. =, +=, -=, *=, /=, %=, <<=, >>=, &=, ^=, |=
15. ,

*/

/*
運算符重載

運算符重載（Operator Overloading）是一種多態性的表現形式，它允許運算符在不同的情況下有不同的功能，這樣的運算符稱為重載運算符。

int a = 10;
int b = 7;
int c;
c = a / b; // c = 10 / 7 = 1

float d = 10.0;
float e = d / b; // e = 10.0 / 7 = 1.42857

*/

/*
複合復值運算子
+=	加法賦值運算子
-=	減法賦值運算子
*=	乘法賦值運算子
/=	除法賦值運算子
%=	取餘賦值運算子

舉例
int a = 10;
int b = 3;
int sum = 0;

sum = sum + a; // sum = 0+10 = 10
sum = sum + b; // sum = 10+3 = 13

sum += a; // sum = 13+10 = 23
sum += b; // sum = 23+3 = 26

*/

/*
位運算子
<<	左位移運算子
>>	右位移運算子
&	按位與運算子
|	按位或運算子
^	按位異或運算子
~	按位取反運算子



舉例

int a = 60; // 60 = 0011 1100
int b = 13; // 13 = 0000 1101
int c = 0;


c = a & b; // 12 = 0000 1100
c = a | b; // 61 = 0011 1101
c = a ^ b; // 49 = 0011 0001
c = ~a; // -61 = 1100 0011
c = a << 2; // 240 = 1111 0000
c = a >> 2; // 15 = 0000 1111

- 較小的整數型別(short, char, bool)在進行位運算時，會先轉換為較大的整數型別(int)再進行運算，輸出結果也是較大的整數型別
- 如果超出型別範圍，溢位的被丟棄

*/
/*
遞增和遞減運算子

++	遞增運算子
--	遞減運算子

遞增運算子
int a = 10;
int b = 0;

b = a++; // b = 10, a = 11
b = ++a; // b = 12, a = 12

遞減運算子
int a = 10;
int b = 0;


*/

#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int b = 3;
    int c = 0;

    c = a + b;
    cout << "a + b = " << c << endl;

    c = a - b;
    cout << "a - b = " << c << endl;

    c = a * b;
    cout << "a * b = " << c << endl;

    c = a / b;
    cout << "a / b = " << c << endl;

    c = a % b;
    cout << "a % b = " << c << endl;

    cin.get();
    return 0;
}