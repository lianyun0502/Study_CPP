/*
猜數字遊戲

1. 產生一個介於1~100的亂數
2. 讓使用者猜數字
3. 若猜錯，告訴使用者猜的數字太大或太小
4. 若猜對，告訴使用者猜對了
5. 重複2~4，直到使用者猜對

*/
#include<iostream>
#include<random>
using namespace std;


int main(){
    srand(time(0))
    int a = rand();
    int b;
    int up = 100;
    int low = 1;
    do{
        cout << "guess any number(1~100):"<<endl;
        cin >> b;
        if (b==a){
            cout << "answer is" << a <<endl;
            break;
        }else if (b>a){
            cout << "answer is between " << low << "~" << b << endl;
            up = b;
        }else{
            cout << "answer is between " << b << "~" << up << endl;
            low = b;
        }

    } while(true);

    cout << "You Win!" << endl;
}