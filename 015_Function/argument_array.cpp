/*
把陣列作為參數傳遞

- 陣列不能拷貝
- 陣列名稱是指向陣列第一個元素的"指標"
*/

#include <iostream>
using namespace std;


void print_array(int * arr){

    // 以下寫法是錯誤的，因為 sizeof(arr) 會返回指標的大小，而不是陣列的大小
    // for (int i =0; i<(sizeof(arr)/sizeof(arr[0]));i++){
    //     cout << *arr[i] << " ";
    // }
    cout << endl;

}

// 解法一：傳入陣列的長度

void print_array_with_size(int arr[], int length){
    for (int i =0; i<length;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 解法二：傳入參考

void print_array_with_reference(int (&arr)){
    for (int num: arr){
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {1,2,3,4,5};
    print_array_with_size(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}