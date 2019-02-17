#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using std::string; using std::vector;
using std::isspace; using std::find_if;
using std::cin; using std::cout;
using std::endl;

bool space(char c)
{
    return isspace(c);
}

bool not_space(char c)
{
    return !isspace(c);
}

vector<string> split(const string &str)
{
    typedef string::const_iterator iter;
    vector<string> ret;
    
    iter i = str.begin();
    while (i!=str.end())
    {
        i = find_if(i,str.end(),not_space);
        iter j = find_if(i,str.end(),space);
        if (i!=str.end())
            ret.push_back(string(i,j));
        i=j;
    }
    return ret;

}

int main()
{
    string str = "yan keli liqing xia";
    vector<string> St;
    St = split(str);
    for (vector<string>::iterator it = St.begin();it!=St.end();it++)
    {
         cout<< *it << endl;
    }
    return 0;
}