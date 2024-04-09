#include<iostream>
#include<string>

using namespace std;


int main(){
    string str;
    // 1. 捕獲一個字串
    cin >> str;
    cout << "String: " << str << endl; // cin 只能捕獲空格前的字串


    // 2. 捕獲一整行
    string str2;
    getline(cin, str2);
    cout << "String 2: " << str << endl;
    return 0;
}