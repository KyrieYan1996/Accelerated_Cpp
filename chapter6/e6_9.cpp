#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector; using std::cout;
using std::cin; using std::endl;
using std::string; using std::for_each;

string re = "";

void concat(string s)
{
    re+=s;
}

int main(void)
{
    cout << "please enter some words:" << endl;
    vector<string> vec;
    string s;
    while (cin >> s)
        vec.push_back(s);
    for_each(vec.begin(),vec.end(),concat);
    cout << "the result is:" << endl;
    cout << re << endl;

    return 0;
}