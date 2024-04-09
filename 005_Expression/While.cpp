#include<iostream>
using namespace std;


void while_loop()
{
    cout << "entry while_loop !" << endl;
    int x = 0;
    cout << "enter a number:" << endl;
    cin >> x;
    while (x < 5)
    {
        cout << "x is " << x << endl;
        cout << "enter a number:" << endl;
        cin >> x;
    }
}

void do_while_loop()
{
    cout << "entry do_while_loop !" << endl;
    int x = 0;
    do
    {
        cout << "x is " << x << endl;
        cout << "enter a number:" << endl;
        cin >> x;
    } while (x < 5);
}


int main()
{
    while_loop();
    do_while_loop();
    return 0;
}