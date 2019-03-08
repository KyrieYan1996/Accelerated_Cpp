#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

template<class T, class Iterator>
T median(Iterator beg, Iterator end)
{
    vector<T> vec;
    if (beg == end)
    {
        throw domain_error("median of an empty vector");
        return 1;
    }
    else
    {
        copy(beg,end,back_inserter(vec));
        size_t sz = vec.size();
        sort(vec.begin(),vec.end());
        return sz%2?vec[sz/2]:(vec[sz/2-1]+vec[sz/2])/2;   
    }
}