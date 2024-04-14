/*
與普通函數的調用規則
    - 重載優先調用普通函數
    - 可以通過"空模板參數列表"強制調用模板函數
    - 如果函數模板可以更好匹配，會優先調用

*/
#include <iostream>
using namespace std;

void Print(int a){
    cout << "Print(int a)" << endl;
}   

template<class T>
void Print(T a){
    cout << "Print(T a)" << endl;
}

int main(){
    int a = 10;
    Print(a); // 輸出Print(int a)
    Print<>(a); // 輸出Print(T a) (強制調用模板函數)
    char b = 'a';
    Print(b); // 輸出Print(T a) (雖然一般函數會做隱式轉換，但編譯器會覺得函數模板是更好的)
    return 0;
}