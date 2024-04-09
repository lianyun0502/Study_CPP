/*
C遠言風格的字符串是一個字元陣列，以空字元結尾，所以在初始化時要多一個空字元。
char[]
*/
#include <iostream>
using namespace std;

int main()
{
    char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    cout << "Greeting message: ";
    cout << greeting << endl;
    return 0;
}