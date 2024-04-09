/*
結構(struct)是一種自定義的資料型態，可以將不同的資料型態組合在一起，形成一個新的資料型態。
結構的宣告方式如下：
struct 結構名稱
{
    資料型態1 成員名稱1;
    資料型態2 成員名稱2;
    ...
};

- 結構的宣告方式與變數宣告方式相同，只是在變數宣告時，要在結構名稱前加上 struct 關鍵字。(C++ 可以省略)
- 結構的成員可以是任何資料型態，包括結構本身。
- 若沒有給定初值，結構的成員會被初始化為 0。
*/
#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int age;
    float score;
};

int main()
{
    Student stu1;
    stu1.name = "John";
    stu1.age = 18;
    stu1.score = 90.5;

    cout << "Name: " << stu1.name << endl;
    cout << "Age: " << stu1.age << endl;
    cout << "Score: " << stu1.score << endl;

    struct Student stu2;
    stu2 = {"Mary", 17, 88.5};

    cout << "Name: " << stu2.name << endl;
    cout << "Age: " << stu2.age << endl;
    cout << "Score: " << stu2.score << endl;

    return 0;
}