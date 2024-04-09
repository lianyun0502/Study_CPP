#include<iostream>
#include "Welcome.cpp"
using namespace std;


// function definition
void welcome_in_new_file();


void welcome()
{
    cout<<"Hello World"<<endl;
    cout<<"enter your name:"<<endl;
    string name;
    cin>>name;
    cout<<"Hello "<< name <<endl;
}


int main()
{
    welcome();
    welcome_in_new_file();
    return 0 ;
}