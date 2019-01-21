#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector; using std::max;
using std::getline;

string::size_type max_width(const vector<string>& v)
{
    int max_ = 0;
    for (vector<string>::size_type i=0;i<v.size();i++)
    {
        max_ = max_>v[i].size()?max_:v[i].size();
    }
    return max_;
}

vector<string> frame(const vector<string>& v)
{
    vector<string> ret;
    string::size_type maxlen = max_width(v);
    string border(maxlen+2,'*');
    ret.push_back(border);

    for (vector<string>::size_type i=0;i!=v.size();i++)
    {
        ret.push_back('*' + v[i]+string((maxlen-v[i].size()),' ')+'*');
    }
    ret.push_back(border);
    return ret;
}

int main(void)
{
    cout << "input some words,and end with ctrl+z!" << endl;
    string s;
    vector<string> vec,frames;
    while (getline(cin,s))
    {
        vec.push_back(s);
    }
    frames = frame(vec);
    for (vector<string>::size_type i=0;i<frames.size();i++)
    {
        cout << frames[i] << endl;
    }

    return 0;
}