/*
快速排序的想法概念是選擇一個數字當anchor分成比他大比她小的兩邊

*/
#include<iostream>
using namespace std;

void quickSort(int (&arr)[10], int start, int end){
    if (start >= end){
        return ;
    }
    int anchr = start;
    int small_ptr = start + 1;
    int big_ptr = end;

    do{
        cout << "anchr: " << anchr << " small_ptr: " << small_ptr << " big_ptr: " << big_ptr << endl;
        while (arr[small_ptr] <= arr[anchr] && small_ptr < big_ptr){
            small_ptr++;
        }
        while (arr[big_ptr] >= arr[anchr] && big_ptr > small_ptr){
            big_ptr--;
        }
        int temp;
        temp = arr[small_ptr];
        arr[small_ptr] = arr[big_ptr];
        arr[big_ptr] = temp;

    }while(arr[small_ptr] < arr[big_ptr]);
    cout << "*" << "anchr: " << anchr << " small_ptr: " << small_ptr << " big_ptr: " << big_ptr << endl;

    if (arr[small_ptr] < arr[anchr]){
        int temp = arr[anchr];
        arr[anchr] = arr[small_ptr];
        arr[small_ptr] = temp;
    }

    anchr = small_ptr;
    cout << "*" << "anchr: " << anchr << " small_ptr: " << small_ptr << " big_ptr: " << big_ptr << endl;

    quickSort(arr, start, anchr-1);
    quickSort(arr, anchr+1, end);
    return ;
}

void printArray(int (&arr)[10]){
    for (int num : arr){
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    int arr[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    printArray(arr);
    quickSort(arr, 0, 9);
    printArray(arr);
}