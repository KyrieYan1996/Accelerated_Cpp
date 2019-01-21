#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::cout; using std::cin;
using std::endl; using std::vector;
using std::string; using std::isspace;
using std::getline;

vector<string> split(const string& sentence)
{
    vector<string> ret;
    string::size_type i = 0;
    while (i != sentence.size())
    {
        while (i != sentence.size() && isspace(sentence[i]))
            i++;
        
        string::size_type j=i;
        while (j != sentence.size() && !isspace(sentence[j]))
            j++;
        if (i!=j)
        {
            ret.push_back(sentence.substr(i,j-i));
            i=j;
        }
        
    }
    return ret;
}

int main(void)
{
    cout << "please type a sentence,and end with Enter!" << endl;
    string s;
    while (getline(cin,s))
    {
        vector<string> vec = split(s);
    
        for (vector<string>::size_type i=0;i!=vec.size();i++)
        {
            cout << vec[i] << endl;
        }
    }

    return 0;
}