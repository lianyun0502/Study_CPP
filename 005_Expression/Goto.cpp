#include <iostream>
using namespace std;

void do_while_loop()
{
begin:
    cout << "entry do_while_loop !" << endl;
    int x = 0;
    do
    {
        cout << "x is " << x << endl;
        cout << "enter a number:" << endl;
        cin >> x;
    } while (x < 5);

    if (x == 5)
    {
        goto begin;
    }
}

int main()
{
    do_while_loop();
    return 0;
}