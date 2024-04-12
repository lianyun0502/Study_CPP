#include<iostream>
using namespace std;


class Operator
{
public:
    virtual double calculate(double num1, double num2) = 0; // 純虛擬函數，子類必須實現
    virtual ~Operator(){} // 如果父類沒有此虛擬析構函數，delete 子類時 的析構函數將不會被調用
};

class Calculator
{
public:
    double num1;
    double num2;

    Calculator(double num1, double num2){
        this->num1 = num1;
        this->num2 = num2;
    }
    double get_result(Operator &op){
        return op.calculate(num1, num2);
    }
 
};



class Add:public Operator
{
public:
    double calculate(double num1, double num2){
        return num1 + num2;
    }
    ~Add(){
        cout << "Add destructor" << endl;
    }
};


class Sub:public Operator
{

public:
    double calculate(double num1, double num2){
        return num1 - num2;
    }
    ~Sub(){
        cout << "Sub destructor" << endl;
    }
};


class Mul:public Operator
{

public:
    double calculate(double num1, double num2){
        return num1 * num2;
    }
    ~Mul(){
        cout << "Mul destructor" << endl;
    }
};


class Div:public Operator
{

public:
    double calculate(double num1, double num2){
        return num1 / num2;
    }
    ~Div(){
        cout << "Div destructor" << endl;
    }
};


int main()
{
    Calculator cal(10, 20);
    Add add;
    Sub sub;
    Mul mul;
    Div div;
    cout << "Add: " << cal.get_result(add) << endl;
    cout << "Sub: " << cal.get_result(sub) << endl;
    cout << "Mul: " << cal.get_result(mul) << endl;
    cout << "Div: " << cal.get_result(div) << endl;

    // 這樣寫法可以減少記憶體的使用
    Operator *op = new Add;
    cout << "Add: " << cal.get_result(*op) << endl;
    delete op;
    op = new Sub;
    cout << "Sub: " << cal.get_result(*op) << endl;
    delete op;
    op = new Mul;
    cout << "Mul: " << cal.get_result(*op) << endl;
    delete op;
    op = new Div;
    cout << "Div: " << cal.get_result(*op) << endl;
    delete op;


    return 0;
}
