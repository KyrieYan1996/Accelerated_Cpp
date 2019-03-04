#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>

using namespace std;

bool space(char c)
{
    return isspace(c);
}

bool not_space(char c)
{
    return !isspace(c);
}

template<class Out>
void split(const string& st, Out os)
{
    typedef string::const_iterator iter;
    iter i = st.begin();
    while (i != st.end())
    {
        i = find_if(i,st.end(),not_space);
        iter j = find_if(i,st.end(),space);
        if (i!=st.end())
            *os++ = string(i,j);
        i = j;
    }
}

int main(void)
{
    //mode 1
    /*
    string s = "hello world of C plus plus";
    vector<string> vec;
    split(s,back_inserter(vec));
    cout << "outputs:" << endl;
    for (vector<string>::const_iterator it = vec.begin();it!=vec.end();it++)
        cout << *it << endl;
    */

   //mode 2
    string s;
    while (getline(cin,s))
        split(s,ostream_iterator<string>(cout ,"\n"));
    
    return 0;
}