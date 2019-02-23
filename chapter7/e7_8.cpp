#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using std::cout; using std::endl;
using std::cin; using std::map;
using std::string; using std::vector;
using std::isspace; using std::istream;

bool not_url_char(const char c)
{
    static const std::string url_ch = "~;/?:@=&$-_.+!*'(),";
    return !(std::isalnum(c) || (std::find(url_ch.begin(),url_ch.end(),c) != url_ch.end()));
}

std::string::const_iterator url_end(std::string::const_iterator b,std::string::const_iterator e)
{
    return std::find_if(b,e,not_url_char);
}

std::string::const_iterator url_begin(std::string::const_iterator b,std::string::const_iterator e)
{
    static const std::string sep = "://" ;
    typedef std::string::const_iterator iter;
    iter i = b;
    while ((i = std::search(i,e,sep.begin(),sep.end()))!=e)
    {
        if ( i != b && i+sep.size()!=e)
        {
            iter beg = i;
            while (beg != b && std::isalpha(beg[-1]))
                --beg;
            if (beg != i && i+sep.size() != e && !not_url_char(i[sep.size()]))
                return beg;
        }
        if (i != e)
            i += sep.size();
    }
    return e;
}

std::vector<std::string> find_urls(const std::string& s)
{
    std::vector<std::string> ret;
    typedef std::string::const_iterator iter;
    iter b = s.begin();iter e = s.end();
    while(b!=e)
    {
        b = url_begin(b,e);
        if (b!=e)
        {
            iter after = url_end(b,e);
            ret.push_back(std::string(b,after));
            b = after;
        }

    }
    return ret;
}

map<string,vector<int> > xref(istream &in,vector<string> find_words(const string& str)=find_urls)
{
    string line;
    int line_num = 0;
    map<string,vector<int> > ret;
    while (std::getline(in,line))
    {
        line_num++;
        vector<string> urls = find_words(line);
        for (vector<string>::const_iterator it = urls.begin(); it != urls.end(); it++)
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
        cout << it->first << "\t" << "occurs on lines:";
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