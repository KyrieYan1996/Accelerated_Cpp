#include <vector>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>


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

int main(void)
{
    std::string urls = "https://github.com sajhaf:// ://skhdakh https://www.baidu.com" ;
    std::vector<std::string> vec;
    vec = find_urls(urls);

    for (std::vector<std::string>::const_iterator it = vec.begin();it != vec.end(); it++)
        std::cout << *it << std::endl;
    return 0;
}