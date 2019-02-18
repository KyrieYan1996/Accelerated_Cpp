#include <iostream>
#include <vector>
#include <algorithm>
//Method1
/*
int main(void)
{
    std::vector<int> u(10,100);

    std::vector<int> v(10,1);
    std::copy(u.begin(),u.end(),v.begin()); 
    for (std::vector<int>::const_iterator it = v.begin(); it!=v.end();it++)
        std::cout << *it << std::endl;    
    
    return 0;
}*/
//Method2
int main(void)
{
    std::vector<int> u(10,100);

    std::vector<int> v;
    std::copy(u.begin(),u.end(),std::back_inserter(v)); 
    for (std::vector<int>::const_iterator it = v.begin(); it!=v.end();it++)
        std::cout << *it << std::endl;    
    
    return 0;
}
