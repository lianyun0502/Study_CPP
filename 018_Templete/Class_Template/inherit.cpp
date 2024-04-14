/*

類別模板的繼承

- 當子類別繼承父類別時，父類別是類別模板，則子類別必須指定父類別的模板參數 (因為不指定的話，編譯器不知道要如何實體化父類別)
- 更靈活的方式是，子類別也寫成類別模板，並且可以指定不同的模板參數 (用囉嗦換靈活XD，但我會用這個)

*/
#include <iostream>
using namespace std;

template<class T>
class Base
{
public:
    T a_;
};


// class Child:public Base
// {
//     // 這裡會報錯，因為Base是類別模板，必須指定模板參數(C++ 繼承創建物件時，會先調用父類的構造函數)
// };

class Child2:public Base<int>
{
    // 這樣就不會報錯
public:

    Child2(int a){
        this->a_ = a;
    }

};

// 靈活的寫法

template<class T1>
class Child3:public Base<T1>
{
public:
    Child3(T1 a){
        this->a_ = a;
    }
};


int main(){
    Child2 c(10);
    cout << c.a_ << endl;


    Child2 c2(20);
    cout << c2.a_ << endl;


    Child3<string> c3("hello");
    cout << c3.a_ << endl;

    Child3<int> c4(100);
    cout << c4.a_ << endl;

    return 0;
}
