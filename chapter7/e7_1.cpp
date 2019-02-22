#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<string,int> PAIR;

bool cmp_pair_value(PAIR& p1,PAIR& p2)
{
    return p1.second < p2.second;
}

int main(void)
{
    map<string,int> words(cmp_pair_value);
    string s;
    while (cin >> s)
        words[s]++;
    vector<PAIR> counters(words.begin(),words.end());
    sort(counters.begin(),counters.end(),cmp_pair_value);
    for (vector<PAIR>::const_iterator it = counters.begin(); it != counters.end();it++)
        cout << it->first << "\t" << it->second << endl;
    return 0;
}