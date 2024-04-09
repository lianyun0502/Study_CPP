// Integrasl Type 整數型別

/*
    1. char                1 byte
    2. short               2 bytes
    3. int                 2 bytes
    4. long                4 bytes
    5. long long (C++11)   8 bytes
    6. bool                1 byte


    - 1 byte = 8 bits (一個位"元組"等於8"位元"，大陸稱byte為字節)
    - 最一開始的系統 int 為 2 bytes，但現在很多的系統 int 為 4 bytes，windows7, win10, macOS 32位元系統，int 4 bytes
*/

/*
    無符號整數 (Unsigned Integers)
        - 用來表示正整數 

    在變數名稱前加上 unsigned 關鍵字，可以表示無符號整數
        - unsigned int
        - unsigned short
        - unsigned long
        - unsigned long long (C++11)

*/

/* 
    二補數(2's complement)
        - 用來表示負整數
        - 二補數是一種將正整數轉換為負整數的方法
        - 二補數的表示方法為將正整數的二進位表示 "取反+1" 
        舉例
            1. 3 的二進位表示為 0000 0011
            2. 3 的二補數為 1111 1101 + 1 = 1111 1110
            3. 1111 1110 的十進位表示為 -3
*/
/*
    型別通用考慮
    1.一般整數都用int
    2.超過範圍用long long
    3.確定無負數用unsigned

*/

#include <iostream>
using namespace std;


int main(){
    char a = 'A'; // 1 byte
    short b = 32768; // 2 bytes (最大值為 32767，超過會溢位)
    int c = 20; // 4 bytes
    long d = 30; // 4 bytes
    long long e = 40; // 8 bytes
    bool f = true; // 1 byte
    unsigned short g = 65535; // 4 bytes

    cout<<"Size of char: "<<sizeof(char)<<" byte"<<endl;
    cout<<"Size of short: "<<sizeof(short)<<" bytes"<<endl;
    cout<<"Size of int: "<<sizeof(int)<<" bytes"<<endl;
    cout<<"Size of long: "<<sizeof(long)<<" bytes"<<endl;
    cout<<"Size of long long: "<<sizeof(long long)<<" bytes"<<endl;
    cout<<"Size of bool: "<<sizeof(bool)<<" byte"<<endl;
    cout<<"Size of unsigned int: "<<sizeof(unsigned int)<<" bytes"<<endl;

    cout<<"Value of a: "<<a<<endl;
    cout<<"Value of b: "<<b<<endl;
    cout<<"Value of c: "<<c<<endl;
    cout<<"Value of d: "<<d<<endl;
    cout<<"Value of e: "<<e<<endl;
    cout<<"Value of f: "<<f<<endl;
    cout<<"Value of g: "<<g<<endl;

    cin.get();
    return 0;
}