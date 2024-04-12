/*
多型(Polymorphism)

多型是指一個物件可以有多種型態，這是物件導向程式設計的一個重要特性。

多型有兩種形式：
    - 編譯時期多型(Compile-time Polymorphism): 透過函數重載(Overloading)和運算子重載(Operator Overloading)來實現。
    - 執行時期多型(Runtime Polymorphism): 透過虛擬函數(Virtual Function)和抽象類別(Abstract Class)來實現。

虛擬函數(Virtual Function)
    - 虛擬函數是一個在父類中聲明的函數，並在子類中重新定義的函數。
    - 虛擬函數可以實現執行時期多型。
    - 純虛擬函數(Pure Virtual Function)是一個在父類中聲明的虛擬函數，但沒有實現，必須在子類中實現。

!! 如果子類別中有成員的記憶體被儲存到stack區塊，那麼當子類別的物件被刪除時，會沒有辦法調用子類別的解析運算子，這樣就會造成記憶洩漏(Memory Leak)。
    - 解決方法是在父類別中加上虛擬析構函數(Virtual Destructor)。(釋放堆區塊的記憶體)

*/

#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void speak()
    {
        cout << "Animal speak" << endl;
    }

    void eat()
    {
        cout << "Animal eat" << endl;
    }
};

class Dog : public Animal
{
public:
    void speak()
    {
        cout << "Dog speak" << endl;
    }

    void eat()
    {
        cout << "Dog eat" << endl;
    }
};


void who_speak(Animal &animal)
{
    animal.speak();
}

void who_eat(Animal &animal)
{
    animal.eat();
}

void test()
{

    Dog dog;
    who_speak(dog); // 有用virtual修飾，所以會調用子類的speak函數
    who_eat(dog); // 沒有用virtual修飾，所以不會調用子類的eat函數
    dog.Animal::eat(); // 透過作用域解析運算符(::)來訪問父類的eat函數
}


int main()
{

    test();

    return 0;
}
