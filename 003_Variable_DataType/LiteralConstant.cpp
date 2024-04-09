/*

通常一開始會使用int型別，因為int型別在大多數的系統上是最快的

十進制如果不夠用，會優先使用long，再來是long long
但如果是八和十六進制，則會優先使用無符號類型 unsigned int 再選 long...，原因十六進制是無符號的。。
有時候也會加入後綴，例如 
    20u，u代表unsigned int 
    20l代表long 
    20ul代表unsigned long

*/

#include <iostream>
using namespace std;

int main()
{
    int a = 20;
    long b = 20;
    long long c = 20;
    unsigned int d = 20;
    unsigned long e = 20;
    unsigned long long f = 20;

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
    cout << "d: " << d << endl;
    cout << "e: " << e << endl;
    cout << "f: " << f << endl;

    cin.get();
    return 0;
}