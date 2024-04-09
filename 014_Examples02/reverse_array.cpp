#include<iostream>
using namespace std;


int main(){

    int arry[6] = {1, 2, 3, 4, 5, 6};

    int *l = &arry[0];
    int *r = &arry[(sizeof(arry)/sizeof(arry[0])-1)];

    while(l != r && l < r){ // l < r is for odd number of elements
        int temp = *l;
        *l = *r;
        *r = temp;
        l++;
        r--;
    }

    for (int num: arry){
        cout << num << " ";
    }
    cout << endl;

}