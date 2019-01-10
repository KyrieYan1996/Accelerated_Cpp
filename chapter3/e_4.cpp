#include <iostream>
#include <algorithm>

using std::cout; using std::cin;
using std::string; using std::endl;

int main(void)
{
    cout << "please enter some words,and end with ctrl+z." << endl;
    string word;
    int max_len = 0;
    int min_len = 100;
    while (cin >> word)
    {
        max_len = word.size()>max_len?word.size():max_len;
        min_len = word.size()<min_len?word.size():min_len;
    }
    cout << "the max len is " << max_len << endl;
    cout << "the min len is " << min_len << endl;
    return 0;
}