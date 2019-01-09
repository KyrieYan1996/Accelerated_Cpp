#include <iostream>
#include <algorithm>
#include <vector>

using std::cout; using std::cin;
using std::endl; using std::sort;
using std::vector;
int main(void)
{
    cout << "please input some integers,and followed by end-of-file:" << endl;
    vector<int> sets;
    int x=0;
    while (cin>>x)
    {
        sets.push_back(x);
    }
    if (sets.size()==0)
    {
        cout << "please sure u have entered some integers!";
        return 1;
    }
    sort(sets.begin(),sets.end());
    typedef vector<int>::size_type vec_sz;
    vec_sz size = sets.size();
    if (size%4==0)
    {
        int quar=size/4;
        for (int j=1;j<=4;j++)
        {
            cout << 5-j <<"-th part includes:" << endl;
            for (int i=quar*(j-1);i<quar*j;i++)
            {
                cout << sets[i] << endl;
            }
        }
    }
    else
    {
        cout << "the incorrect size of sets!";
        return 1;
    }
    return 0;
}