/*



*/
#include <iostream>
using namespace std;

void print_number(int a, int b, int c, int d){
    cout << "a is " << a << endl;
    cout << "b is " << b << endl;
    cout << "c is " << c << endl;
    cout << "d is " << d << endl;
}

void increase_number(int num){
    
    num++;
}

void increase_number_pointer(int *num){
    (*num)++;
}

void increase_number_reference(int &num){
    num++;
}

bool is_str_len_equal(const string &str1, const string &str2){
    // 更好的參數寫法是傳參考，因為就不用在函數內部再複製一份
    // 再更好的寫法是使用const string &str1, const string &str2，這樣可以防止誤操作參數，也告訴使用者這個函數不會修改參數
    return str1.size() == str2.size();
}

int main(){
    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;

    print_number(a, b, c, d); // 值傳遞

    increase_number(a); // 值傳遞，參數其實是複製了一份
    cout << "a is " << a << endl;
    cout << "no change" << endl;

    increase_number_pointer(&b); // 地址傳遞，參數是地址，所以可以改變原本的值
    cout << "b is " << b << endl;
    cout << "changed" << endl;

    increase_number_reference(c); // 參考傳遞，參數是原本的變數，而在作用域內為原本變數的參考
    cout << "c is " << c << endl;
    cout << "changed" << endl;

    string str1 = "hello";
    string str2 = "world";
    cout << "str1 and str2 is equal: " << is_str_len_equal(str1, str2) << endl;

    return 0;
}