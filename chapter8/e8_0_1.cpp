#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//顺序只读访问
template <class In,class X> 
In _find(In begin, In end, const X &x)
{
    while (begin!=end && *begin!=x)
        begin++;
    return begin;
}

//顺序只读访问
template <class In,class X>
In _find_(In begin,In end,const X& x)
{
    if (begin==end || (*begin) == x)
        return begin;
    begin++;
    return _find_(begin,end,x);
}

//顺序只写访问
template <class In, class Out>
Out _copy(In begin,In end, Out dest)
{
    while (begin!=end)
        *dest++ = *begin++;
    return dest;
}

//顺序读-写访问
template <class For, class X>
void _replace(For begin, For end, const X& x, const X& y)
{
    while (begin != end)
    {
        if (*begin==x)
            *begin = y;
        begin++;
    }
}

//可逆访问
template<class Bi>
void _reverse(Bi begin,Bi end)
{
    while (begin != end)
    {
        --end; //!!iterator.end() 指向最后一个元素之后的地址，所以是[begin,end)的情况
        if (begin != end)
            swap(*begin++,*end);
    }
}

//随机访问
template<class Ran, class X>
bool _binary_search(Ran begin, Ran end, const X& x)
{
    sort(begin,end);
    while (begin < end)
    {
        Ran mid = begin + (end-begin)/2;
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

    /*
    vector<int>::const_iterator it = nums.end();
    if (_find(nums.begin(),nums.end(),10) != it)
        cout << "find it,the value is " << *_find_(nums.begin(),nums.end(),10) << endl;
    else
        cout << "can't find it" << endl;
    */
   
    _reverse(nums.begin(),nums.end());
    for (vector<int>::const_iterator i = nums.begin();i<nums.end();i++)
        cout << *i << endl;
    
    /*
    if (_binary_search(nums.begin(),nums.end(),10))
        cout << "find it!" << endl;
    else
        cout << "can't find it!" << endl;
    */
    return 0;
}