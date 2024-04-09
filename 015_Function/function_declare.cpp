#include<iostream>
#include"utils.h"
using namespace std;

int square(int num){
    return num*num;
}


int main(){
    int num = 10;
    cout << "The square of " << num << " is " << square(num) << endl;

    cout << "The cube of " << num << " is " << cube(num) << endl;
    return 0;
}