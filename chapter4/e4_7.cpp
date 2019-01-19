#include <vector>
#include <iostream>
#include <algorithm>

using std::cin; using std::cout;
using std::endl; using std::vector;

int main(void)
{
    cout << "please enter some numbers with double-type,and end with ctrl+z." << endl;
    vector<double> vec;
    double n;
    while (cin >> n)
    {
        vec.push_back(n);
    }

    vector<double>::size_type size=vec.size();
    double sum=0,mean=0;
    for (vector<double>::size_type i=0;i<size;i++)
    {
        sum += vec[i];
    }
    mean = sum/size;
    cout << "the mean is " << mean << endl;

    return 0;
}