#include <iostream>
#include <vector>
#include <cctype>
#include <string>

using std::cin; using std::cout;
using std::endl; using std::vector;
using std::isupper; using std::istream;
using std::string;

istream& read(istream& in, vector<string>& s)
{
    string word;
    in >> word;
    s.push_back(word);
    return in;
}


int main(void)
{
    cout << "Please input some upper and lower words." << endl;
    vector<string> vec,upper;

    while (read(cin,vec));
    vector<string>::iterator iter = vec.begin();
    while (iter!= vec.end())
    {
        if (isupper((*iter)[0]))
        {
            upper.push_back(*iter);
            iter = vec.erase(iter);
        }
        else    
            iter++;
    }
    
    cout << "lower words:" << endl;
    for (vector<string>::const_iterator it = vec.begin();it!=vec.end();it++)
        cout << *it << endl;

    cout << "upper words:" << endl;
    for (vector<string>::const_iterator it1 = upper.begin();it1!=upper.end();it1++)
        cout << *it1 << endl;

    return 0;
}