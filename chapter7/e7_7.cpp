#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using std::cout; using std::endl;
using std::cin; using std::map;
using std::string; using std::vector;
using std::isspace; using std::istream;

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

map<string,vector<int> > xref(istream &in,vector<string> find_words(const string& str)=split)
{
    string line;
    int line_num = 0;
    map<string,vector<int> > ret;
    while (std::getline(in,line))
    {
        line_num++;
        vector<string> words = find_words(line);
        for (vector<string>::const_iterator it = words.begin(); it != words.end(); it++)
        {
            ret[*it].push_back(line_num);
        }
    }
    return ret;

}

int main(void)
{
    map<string, vector<int> > re = xref(cin);

    for (map<string,vector<int> >::const_iterator it=re.begin();it!=re.end();it++)
    {
        cout << it->first << "\t" << "occurs on ";
        cout << ((it->second.size()==1)? "line:" : "lines:");
        vector<int>::const_iterator line_n = (it->second).begin();
        while (line_n != it->second.end())
        {
            cout << *line_n << "\t";
            line_n++;
        }
        cout << endl;
    }
    return 0;
}