#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

template<class T>
T median(vector<T> v)
{
    typedef typename vector<T>::size_type vec_sz;
    vec_sz sz = v.size();
    if (sz==0)
    {
        throw domain_error("median of an empty vector");
        return 1;
    }
    sort(v.begin(),v.end());
    return sz%2?v[sz/2]:(v[sz/2-1]+v[sz/2])/2;
}

template <class T>  //_max(10,11.0)——"no matching function for call to '_max(int, double)'"

T _max(const T& left,const T& right)
{
    return left>right?left:right;
}


int main(void)
{
    cout << "enter some grades(double), and end with ctrl+z." << endl;
    vector<double> grades_double;
    double g=0;
    while (cin >> g)
        grades_double.push_back(g);
    cout << "the double median is "<< median(grades_double) << endl;

    cout << "enter some grades(int), and end with ctrl+z." << endl;
    vector<int> grades_int;
    int g=0;
    while (cin >> g)
        grades_int.push_back(g);
    cout << "the int median is "<< median(grades_int) << endl;

    return 0;
}