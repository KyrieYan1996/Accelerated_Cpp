#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <class In,class X> 
In _find(In begin, In end, const X &x)
{
    while (begin!=end && *begin!=x)
        begin++;
    return begin;
}

template <class In,class X>
In _find_(In begin,In end,const X& x)
{
    if (begin==end || (*begin) == x)
        return begin;
    begin++;
    return _find_(begin,end,x);
}

int main(void)
{
    cout << "please enter some numbers." << endl;
    vector<int> nums;
    int n=0;
    while (cin>>n)
        nums.push_back(n);
    
    vector<int>::const_iterator it = nums.end();
    if (_find(nums.begin(),nums.end(),10) != it)
        cout << "find it,the value is " << *_find_(nums.begin(),nums.end(),10) << endl;
    else
        cout << "can't find it" << endl;
    
    return 0;
}