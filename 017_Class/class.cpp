/*

struct 和 class 的差異
- struct 預設為 public,class 預設為 private
- struct 可以繼承自 class,但 class 不可以繼承自 struct


類別的權限
- public: 公共權限 (可在類別外使用)
- protected: 保護權限 (只能在類別內或繼承的子類別使用)
- private: 私有權限 (只能在類別內使用)


封裝 (Encapsulation)
- 將資料與方法封裝在一個類別中,並將資料設為私有,透過公共方法來存取資料
- 透過封裝可以達到資料隱藏,提高程式碼的安全性與可維護性


如果創建的物件裡面有另一個類別的物件作為成員,則該成員的建構函數會在外部類別的建構函數中被調用
- 這種方式稱為組合 (Composition)
- 建構時,"先調用成員"的建構函數,再調用外部類別的建構函數
- 解構時,"先調用外部類別"的解構函數,再調用成員的解構函數

*/

#include<iostream>
using namespace std;

const double pi = 3.14159;

class Circle
{
    // 訪問權限
    public: // 公共權限
        // 類別屬性
        double radius;

        // 類別方法
        double getArea()
        {
            return pi * radius * radius;
        }

        double getPerimeter()
        {
            return 2 * pi * radius;
        }
};

class Student
{
    public:
    void showInfo(){
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
    }

    void setName(string n){
        name = n;
    }

    void setId(int i){
        id = i;
    }

    void setAge(int a){
        

        if(a < 0 || a > 150){
            cout << "Invalid age" << endl;
            return;
        }
        age = a;
    }


    private:
        int password = 1234;
        string name;

        int age;
        int id;
};

int main(){
    Circle c ;
    c.radius = 5.2;
    cout << "Area: " << c.getArea() << endl;
    cout << "Perimeter: " << c.getPerimeter() << endl;


    Student s;
    // s.name = "John"; // Error: 'std::string
    s.setName("John");
    s.setId(123456);
    s.showInfo();
    //cout << "PW: " << s.password << endl; // Error: 'int Student::password' is private within this context
    return 0;
}