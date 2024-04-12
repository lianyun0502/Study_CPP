/*
friend 修飾子的使用

- 全局函數
- 類別
- 類別的成員函數

*/


#include <iostream>
#include <algorithm>
using namespace std;

// class Neightbor
// {
// public:
//     string name = "Neightbor";

//     void visit(House &h) 
//     {
//         cout << "Neightbor visit()" << endl;
//         cout << "living_room: " << h.living_room << endl;
//         // cout << "bedroom: " << h.bedroom << endl; // 錯誤,無法訪問私有成員
//     }
//     void visit_ok(House &h); // 類別成員函數 friend 修飾子,修飾後可以訪問私有成員

//     void visit_ok(House &h) 
//     {
//        cout << "Neightbor visit()" << endl;
//         cout << "living_room: " << h.living_room << endl;
//         cout << "bedroom: " << h.bedroom << endl;
//     }

    
// };

class House
{
    friend void visit(House&h); // 全局函數 friend 修飾子,修飾後可以訪問私有成員
    friend class Machi; // 類別 friend 修飾子,修飾後可以訪問私有成員
    // friend void Neightbor::visit_ok(House&h); // 類別成員函數 friend 修飾子,修飾後可以訪問私有成員
    
public:
    string living_room = "living room";
    

private:
    string bedroom = "bedroom";

}; 


void visit(House &h)
{
    cout << "visit()" << endl;
    cout << "living_room: " << h.living_room << endl;
    cout << "bedroom: " << h.bedroom << endl;
}

class Machi
{
public:
    string name = "Machi";

    void visit(House &h) // 類別成員函數 friend 修飾子,修飾後可以訪問私有成員
    {
        cout << "machi visit()" << endl;
        cout << "living_room: " << h.living_room << endl;
        cout << "bedroom: " << h.bedroom << endl;
    }

    
};






int main()
{
    House h;
    visit(h);
    Machi m;
    m.visit(h);

    // Neightbor n;
    // n.visit(h);
    // n.visit_ok(h);

    return 0;
}