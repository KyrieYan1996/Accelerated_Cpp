#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>

using std::cout; using std::endl;
using std::cin; using std::map;
using std::string; using std::vector;
using std::isspace; using std::istream;
using std::stringstream;

#define LINE_LENGTH 5

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
            //**********add if condition************//
            if (find(ret[*it].begin(),ret[*it].end(),line_num)==ret[*it].end())
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
        stringstream ss;
        cout << it->first << "\t" << "occurs on lines:";
        vector<int>::const_iterator line_n = (it->second).begin();
        ss << *line_n;
        line_n++;
        while (line_n != it->second.end())
        {
            ss << "," << *line_n ;
            line_n++;
        }
        string output = ss.str();
        for (string::size_type i=0;i!=output.size();i++)
        {
            cout << output[i];
            if ((i+1)%LINE_LENGTH==0)
                cout << endl;
        }
        cout << endl;
    }
    return 0;
}