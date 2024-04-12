/*

運算子重載

- 加減乘除運算子重載
- 位移運算子重載
- 關係運算子重載
- 賦值運算子重載(有坑，需注意)
- 關係運算子重載
- 函數調用運算子重載

*/

#include <iostream>
using namespace std;


class Complex
{
public:
    int real;
    int imag;

    Complex(int real, int imag)
    {
        this->real = real;
        this->imag = imag;
    }

    Complex operator+(Complex &c)
    {
        Complex temp(real + c.real, imag + c.imag);
        return temp;
    }

    Complex operator-(Complex &c)
    {
        Complex temp(real - c.real, imag - c.imag);
        return temp;
    }

    Complex operator*(Complex &c)
    {
        Complex temp(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
        return temp;
    }

    Complex operator/(Complex &c)
    {
        Complex temp((real * c.real + imag * c.imag) / (c.real * c.real + c.imag * c.imag),
                     (imag * c.real - real * c.imag) / (c.real * c.real + c.imag * c.imag));
        return temp;
    }

    void display()
    {
        cout << real << " + " << imag << "i" << endl;
    }
};