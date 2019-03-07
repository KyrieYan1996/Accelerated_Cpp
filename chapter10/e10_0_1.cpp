#include <iostream>
#include <algorithm>
#include <vector>
#include <cstddef>

using namespace std;

int add_one(int n)
{
    return n+1;
}

int main()
{
    //point
    int (*fp)(int);
    fp = &add_one;
    cout << fp(2) << endl;

    int i = 4;
    i = (*fp)(i);
    cout << "i+=1:" << i << endl;
    //array
    int arr[3] = {3,4,5};
    const size_t Ndim=3;
    int arr1[Ndim] = {7,8,9};
    int ac = 10;
    int* ptr = &ac;
    cout << "***" << ptr[0] << endl;
    int* pt = arr1;
    int x = *(pt+2); //*(p+3)超出内存空间范围，该地址是有效的，但x无法预测
    cout << x << endl;

    vector<int> v;
    copy(arr1,arr1+Ndim,back_inserter(v));
    vector<int> vec(arr1,arr1+Ndim);
    for (vector<int>::const_iterator it = vec.begin();it != vec.end(); it++)
        cout << *it << " ";

    system("pause");
    return 0;
}