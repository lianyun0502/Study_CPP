/*
Vector

C++擴展了陣列的功能，提供了一個更強大的容器類別，稱為向量（Vector）。

- 向量是一個動態陣列，可以自動調整大小，可以默認初始化，也就是初始可以是空向量。
- 向量是一個類別模板，可以存儲任何型別的元素。
- 向量提供了許多方法來操作元素，例如添加、刪除、查找等。
- 有安全的索引檢查，可以使用at()方法來訪問元素，如果索引超過向量的大小，會拋出一個out_of_range異常。

- 需引入<vector>標頭檔。

- 常用方法：
    - size()：取得向量的大小。
    - push_back()：添加一個元素在最後面。
    - pop_back()：刪除最後一個元素。

- 索引：
    - 向量的索引是從0開始的。
    - 可以使用[]或at()方法來訪問元素。
    - 如果索引超過向量的大小，會拋出一個out_of_range異常。

- 遍歷向量：
    - 可以使用for迴圈來遍歷向量。
    - 也可以使用C++11的範圍For Loop。
*/
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v1; // 空向量
    vector<char> v2 = {'a', 'b', 'c'}; // 列表初始化向量
    vector<int> v3{'a', 'b', 'c'}; // C++11 列表初始化向量的簡化寫法
    vector<int> v4(5); // 5個元素的向量，每個元素都是0
    vector<int> v5(5, 1); // 5個元素的向量，每個元素都是1

    // 索引
    cout <<"v2 first number:"<< v2[0] << endl;
    cout <<"v2 first number:"<< v2.at(0) << endl;
    //如果索引超過向量的大小，會發生甚麼事情？ Answer: Runtime會拋出一個out_of_range異常(terminate called after throwing an instance of 'std::out_of_range')
    // cout <<"v2 forth number:"<< v2.at(3) << endl;

    // 遍歷向量
    for (int i = 0; i < v5.size(); i++) // 有size()方法，可以取得向量的大小，return 是一個unsigned int
    {
        cout << v5[i] << " ";
    }
    cout << endl;

    // 添加元素
    cout << "push element" << endl;
    v5.push_back(6); // 添加一個元素在最後面
    for (int i = 0; i < v5.size(); i++)
    {
        cout << v5[i] << " ";
    }
    cout << endl;
    // 刪除元素
    cout << "pop element" << endl;
    v5.pop_back(); // 刪除最後一個元素
    for (int i = 0; i < v5.size(); i++)
    {
        cout << v5[i] << " ";
    }
}

