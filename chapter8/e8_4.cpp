#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

template<class T>
void _swap(T& a, T& b)
{
    T c(a);
    a = b;
    b = c;
}

template<class Bi>
void _reverse(Bi begin,Bi end)
{
    while (begin != end)
    {
        --end; //!!iterator.end() 指向最后一个元素之后的地址，所以是[begin,end)的情况
        if (begin != end)
            _swap(*begin++,*end);
    }
}

int main(void)
{
    cout << "please enter some numbers." << endl;
    vector<int> nums;
    int n=0;
    while (cin>>n)
        nums.push_back(n);
   
    _reverse_(nums.begin(),nums.end());
    cout << "outputs:" << endl;
    for (vector<int>::const_iterator i = nums.begin();i!=nums.end();i++)
        cout << *i << endl;
    
    return 0;
}
