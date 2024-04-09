/*
選擇排序法

選擇排序法是一種簡單直觀的排序法，其基本概念是：
第一次從arr[0]~arr[n-1]中選擇最小值，與arr[0]交換，
第二次從arr[1]~arr[n-1]中選擇最小值，與arr[1]交換，
第三次從arr[2]~arr[n-1]中選擇最小值，與arr[2]交換，…，

Big O Notation: O(n^2)
*/
#include <iostream>
using namespace std;

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int num = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0 ; i<num; i++){
        for (int j = i+1 ; j<num ; j++){
            if (arr[j] < arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int num: arr){
        cout <<num << ' ';
    }
    cout<<endl;
    return 0;
}

