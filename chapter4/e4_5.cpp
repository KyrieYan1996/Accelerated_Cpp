#include <iostream>
#include <vector>
#include <map>
#include <string>

using std::cin; using std::cout;
using std::endl; using std::vector;
using std::string; using std::map;
typedef vector<string>::size_type size_type;
int main(void)
{
    cout << "please enter some words,and end with ctrl+z." << endl;
    vector<string> words;
    string wd;
    while (cin >> wd)
    {
        words.push_back(wd);
    }
    size_type size_len = words.size();
    map<string,int> w;
    for (size_type i=0;i<size_len;i++)
    {
        w[words[i]]++;
    }
    for (map<string,int>::const_iterator it = w.begin();it != w.end();it++)
    {
        cout << it->first << ":" << it->second << endl;
    }
    return 0;
}