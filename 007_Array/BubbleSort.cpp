/*
冒泡排序

时间复杂度：
空间复杂度：

概念
1. 比較相鄰的元素。如果第一個比第二個大，就交換它們兩個。
2. 對每一對相鄰元素作同樣的工作，從開始第一對到結尾的最後一對。這步做完後，最後的元素會是最大的數。
3. 针对所有的元素重复以上的步骤，除了最後一个。

*/
#include<iostream>
using namespace std;

int main(){
    int arr[] = {64, 25, 12, 22, 11};
    int num  = sizeof(arr)/sizeof(arr[0])-1;
    for (int i=0; i < num; i++){
        for (int j=0; j < (num-i);j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for (int num: arr){
        cout <<num << ' ';
    }
    cout<<endl;
}