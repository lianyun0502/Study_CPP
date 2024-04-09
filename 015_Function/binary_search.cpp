#include<iostream>
using namespace std;


int binarySearch(int (&arr)[10], int num){
    int left = 0;
    int right = 9;
    while (left <= right){
        int mid = (left+right)/2;

        if (num > arr[mid]){
            left = mid+1;
        }else if (num < arr[mid])
        {
            right = mid-1;
        }
        else{
            return mid;
        }
    }
    return -1;
}


int main(){
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int num = 11;
    int index = binarySearch(arr, num);
    if (index == -1){
        cout << "Not found" << endl;
    }else{
        cout << "Found at index: " << index << endl;
    }
}