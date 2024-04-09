/*

可變參數有三種寫法

* (...)省略符號
    - 這種寫法是C語言的寫法，C++也支援
    - 這種寫法的缺點是無法知道傳入的參數個數，所以無法進行參數的檢查
    - 只能寫再最後一個參數
* initializer_list
    - C++11新增的寫法
    - 可以知道傳入的參數個數
    - 可以寫在任何位置
    - 參數只能是常數，且必須是同一種資料型態

* 可變參數模板
    - 一種特殊函數寫法
*/

#include <iostream>
#include <cstdarg>
using namespace std;

// (...)省略符號
int sum(int count, ...){
    va_list args;
    va_start(args, count);
    int sum = 0;
    for(int i = 0; i < count; i++){
        sum += va_arg(args, int);
    }
    va_end(args);
    return sum;
}

// initializer_list
int sum(initializer_list<int> args){
    int sum = 0;
    for(int num: args){
        sum += num;
    }
    return sum;
}

// 可變參數模板
