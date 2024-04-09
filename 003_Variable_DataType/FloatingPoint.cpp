/*
有單精度浮點數（float）和雙精度浮點數（double）兩種浮點數型別。

float：4個字節，32位，精度為7位有效數字。

double：8個字節，64位，精度為15位有效數字。

long double：16個字節，128位，精度為19位有效數字。(C++)

可以使用科學記號表示浮點數，例如：3.14e2 = 3.14 * 10^2 = 314.0

*/

#include <iostream>
using namespace std;

int main()
{
    float f = 3.14;
    double d = 3.14;
    long double ld = 3.14;
    float e = 3.14e2;

    cout << "Size of float: " << sizeof(float) << " bytes" << endl;
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;
    cout << "Size of long double: " << sizeof(long double) << " bytes" << endl;
    cout << "Size of e: " << sizeof(e) << " bytes" << endl;

    cout << "Value of f: " << f << endl;
    cout << "Value of d: " << d << endl;
    cout << "Value of ld: " << ld << endl;
    cout << "Value of e: " << e << endl;

    cin.get();
    return 0;
}