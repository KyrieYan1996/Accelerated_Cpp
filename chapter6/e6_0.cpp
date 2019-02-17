#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using std::vector; using std::string;
using std::copy; using std::back_inserter;

int main(void)
{
    std::cout << "enter some words:" << std::endl;
    vector<string> vec;
    vector<string> v_add;
    string s,v;
    while (std::cin >> s >> v)
    {
        vec.push_back(s);
        v_add.push_back(v);
    }     
    copy(v_add.begin(),v_add.end(),std::back_inserter(vec));
    //copy(v_add.begin(),v_add.end(),vec.begin());
    std::cout << "the result is:" << std::endl;
    for (vector<string>::iterator it1 = vec.begin();it1!=vec.end();it1++)
    {
        std::cout << (*it1) << std::endl;
    }
    
    return 0;
}