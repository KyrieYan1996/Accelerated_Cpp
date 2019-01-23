#include <iostream>
#include <vector>
#include <string>

using std::cin; using std::cout;
using std::endl; using std::vector;
using std::string;

bool isplalindrome(string word)
{
    string::size_type l = word.size();
    int i = 0;
    while ((word[i]==word[l-1-i]) && (i<int(l/2)))
        i++;
    if (i == int(l/2))
        return true;
    else
        return false;
}

int main(void)
{
    cout << "please input some words:" << endl;
    string s;
    string temp = "a";
    vector<string> wds;
    vector<string>::size_type maxlen = 0;
    while (cin >> s)
        wds.push_back(s);
    for (vector<string>::const_iterator iter = wds.begin();iter!=wds.end();iter++)
    {
        if (isplalindrome(*iter))
        {
            temp = (*iter).size()>temp.size()?(*iter):temp;
        }
    }
    cout << "the maxlen plalindrome is: " << temp << endl; 
    return 0;
}