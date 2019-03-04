#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>

using namespace std;

int main(void)
{
    cout << "enter some integer." << endl;
    vector<int> vec;

    copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(vec));
    cout << "output:" << endl;
    for (vector<int>::const_iterator i=vec.begin();i!=vec.end();i++)
        cout << *i << endl;

    cout << "ostream_iterator outputs:" << endl;
    copy(vec.begin(),vec.end(),ostream_iterator<int>(cout," "));
    
    //两个元素之间没有分隔符
    copy(vec.begin(),vec.end(),ostream_iterator<int>(cout));
    return 0;
}