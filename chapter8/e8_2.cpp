#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cmath>

using namespace std;

template<class T>
bool _equal(T beg1, T end1, T beg2)
{
    while (beg1!=end1)
    {
        if (*beg1 != *beg2)
            return false;
        else
            beg1++,beg2++;
        
    }
    return true;
}

template<class T>
T _search(T b, T e, T b2, T e2)
{
    while (b != e)
    {
        if (_equal(b2,e2,b))
            return b;
        b++;
    }
    return e;
}

template<class In, class X>
In _find(In b, In e, const X& t)
{
    while (b != e)
    {
        if (*b == t)
            return b;
        else
            b++;
    }
    return e;
}

template<class In, class X>
bool _find_if(In b, In e, const X& t)
{
    while (b != e)
    {
        if (*b++ == t)
            return true;
    }
    return false;
}

template<class Out>
Out _copy(Out b, Out e, Out d)
{
    while (b != e)
        *d++ = *b++;
    return d;
}

template<class In, class Out, class X>
void _remove_copy(In b, In e, Out d, const X& x)
{
    while (b != e)
    {
        if (*b != x)
            *d++ = *b;
        b++;
    }
}

template<class In, class Out, class Function>
void _remove_copy_if(In b, In e, Out d, Function f)
{
    while (b != e)
    {
        if (!f(*b))
            *d++ = *b;
        b++;
    }
}

template<class In, class Out, class Function>
void _transform(In b, In e, Out d, Function f)
{
    while (b != e)
        *d++ = f(*b++);
}

template<class In, class Function>
void _partition(In b, In e, Function f)
{
    while (b != e)
    {
        if (f(*b)) 
            b++;
        else
            swap(*b,*(e--));
    }
}

template<class In, class T>
T _accumulate(In b, In e, T t)
{
    while (b!=e)
        t += *b++;
    return t;
}

int main(void)
{
    int n[5] = {2,4,6,8,10};
    int n2[] = {1,3,5,7,9};
    int n1[3] = {4,9,16};
    vector<int> vec1(n,n+5);
    vector<int> vec2(n2,n+5);
    vector<int> vec3(n1,n1+3);

    cout << "test _equal:" << endl;
    cout << "vec1 equals vec2?" << _equal(vec1.begin(),vec1.end(),vec2.begin()) << endl;

    cout << "test _search:" << endl;
    cout << "vec3 in vec1?" << *(_search(vec1.begin(),vec1.end(),vec3.begin(),vec3.end())-1) << endl;

    cout << "test _find:" << endl;
    cout << "0 in vec1?" << *(_find(vec1.begin(),vec1.end(),0)-1) << endl;

    cout << "test _find_if:" << endl;
    cout << "2 in vec1?" << _find_if(vec1.begin(),vec1.end(),2) << endl;

    cout << "test _copy:" << endl;
    vector<int>::const_iterator i = _copy(vec1.begin(),vec1.end(),vec2.begin());
    for (vector<int>::const_iterator it = vec2.begin();it!=i;it++)
        cout << *it << endl;

    cout << "test _remove_copy:" << endl;
    vector<int> vec4;
    _remove_copy(vec1.begin(),vec1.end(),back_inserter(vec4),4);
    for (vector<int>::const_iterator it = vec4.begin();it != vec4.end(); it++)
        cout << *it << endl;
    /*
    vector<int> vec5;
    _transform(vec3.begin(),vec3.end(),back_inserter(vec5), sqrt);
    for (vector<int>::const_iterator it = vec5.begin();it != vec5.end(); it++)
        cout << *it << endl;
    */
    cout << "test _accumulate:" << endl;
    cout << _accumulate(vec1.begin(),vec1.end(),0) << endl;

    

    return 0;
}