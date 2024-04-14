/*
templete 是泛型在C++中的實現方式

何謂泛型？

- 類模板
- 函數模板

* 函數模板
    - 語法
        template <typename T>
        T add(T a, T b) {
            return a + b;
        }
    - 使用
        * 隱式調用
            cout << add(1, 2) << endl;
            cout << add(1.1, 2.2) << endl;
        * 顯式調用
            cout << add<int>(1, 2) << endl;
            cout << add<double>(1.1, 2.2) << endl;
* 注意事項
    - 自動類型推導
        * 編譯器會自動推導出模板實例化的類型，"注意類型要一致"
        * 顯示指定類型時，編譯器會優先使用顯示指定的類型(調用推薦)
        * 如果是隱式調用的話不會發生隱式類型轉換


*/
#include <iostream>
using namespace std;


void SwapInt(int &a, int &b){

    int temp = a;
    a = b;
    b = temp;

};

// lambda 題外話
auto SwapIntLambda = [](int &a, int &b)-> void
{
    int temp = a;
    a = b;
    b = temp;
};  

template<typename T> // 這裡的T是一個泛型
void SwapTemplate(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
};


template<class T>
void QuickSort(T arr[], int start_idx, int end_idx)
{
    cout << "QuickSort" << endl;
    int pivot = start_idx;
    int left = start_idx;
    int right = end_idx;

    while (left < right)
    {

        while ((arr[left] < arr[pivot]) && (left < right)){
            left++;
        }
        while ((arr[right] >= arr[pivot]) && (left < right)){
            right--;
        }
        if (right == left){
            T temp  = arr[pivot];
            arr[pivot] = arr[left];
            arr[left] = temp;
            QuickSort(arr, start_idx, left);
            QuickSort(arr, right+1, end_idx);
            return;
        }

        T temp = arr[right];
        arr[right] = arr[left];
        arr[left] = temp;

    }
}


int main(){
    int a = 10;
    int b = 20;
    cout << "a = " << a << ", b = " << b << endl;
    SwapInt(a, b);
    cout << "a = " << a << ", b = " << b << endl;
    SwapIntLambda(a, b);
    cout << "a = " << a << ", b = " << b << endl;

    double c = 10.5;
    double d = 20.5;
    cout << "c = " << c << ", d = " << d << endl;
    SwapTemplate(c, d); // 隱示調用
    cout << "c = " << c << ", d = " << d << endl;
    SwapTemplate<int>(a, b); // 顯示調用
    cout << "a = " << a << ", b = " << b << endl;


    int arr[5] = {2,5,15,1,6};

    QuickSort<int>(arr, 0, 4);

    for (auto num : arr){
        cout << num << " "; 
    }
    cout << endl;

    return 0;
}