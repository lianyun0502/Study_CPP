#include<iostream>
using namespace std;


class Cube
{
    double length;
    double width;
    double height;

    public:
        void setCube(double l, double w, double h)
        {
            length = l;
            width = w;
            height = h;
        }
        double getlength()
        {
            return length;
        }

        double getwidth()
        {
            return width;
        }

        double getheight()
        {
            return height;
        }

        bool isSame(Cube &c){
            return length ==c.getlength() && width == c.getwidth() && height == c.getheight();
        }
        
};

bool is_same_cube(Cube &c1, Cube &c2)
{
    return c1.getlength() == c2.getlength() && c1.getwidth() == c2.getwidth() && c1.getheight() == c2.getheight();
}


int main()
{
    Cube c1, c2;
    c1.setCube(10, 20, 30);
    c2.setCube(10, 20, 30);

    if (c1.isSame(c2))
    {
        cout << "c1 and c2 are the same" << endl;
    }
    else
    {
        cout << "c1 and c2 are not the same" << endl;
    }

    if (is_same_cube(c1, c2))
    {
        cout << "c1 and c2 are the same" << endl;
    }
    else
    {
        cout << "c1 and c2 are not the same" << endl;
    }

    return 0;
}   