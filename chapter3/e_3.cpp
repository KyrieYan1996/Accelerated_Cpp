#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using std::cout; using std::cin;
using std::endl; using std::vector;
using std::string; using std::map;
int main(void)
{
    cout << "please enter some words,and end with ctrl+z." << endl;
    map<string,int> words;
    string word;
    while (cin >> word)
    {
        words[word]++;
    } 
    for (map<string,int>::const_iterator it= words.begin(); it!=words.end();it++)
    {
        cout << it->first << " :" << it->second << endl;
    }
    
    return 0;
}