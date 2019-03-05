#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

//随机访问
template<class Ran, class X>
bool _binary_search(Ran begin, Ran end, const X& x)
{
    sort(begin,end);
    while (begin < end)
    {
        Ran mid = begin + (end-begin)/2;
        //Ran mid1 = (end+begin)/2; 
        //error: no match for 'operator+' 
        //(operand types are '__gnu_cxx::__normal_iterator<int*, std::vector<int> >'
        // and '__gnu_cxx::__normal_iterator<int*, std::vector<int> >')
        if (x < *mid)
            end = mid;
        else if (x > *mid)
        {
            begin = mid + 1;
        }
        else 
            return true;
    }
    return false;
}

int main(void)
{
    cout << "please enter some numbers." << endl;
    vector<int> nums;
    int n=0;
    while (cin>>n)
        nums.push_back(n);

    if (_binary_search(nums.begin(),nums.end(),10))
        cout << "find it!" << endl;
    else
        cout << "can't find it!" << endl;
    
    return 0;
}