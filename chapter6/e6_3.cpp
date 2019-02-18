#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    std::vector<int> u(10,100);

    std::vector<int> v;
    std::copy(u.begin(),u.end(),v.begin()); 
    for (std::vector<int>::const_iterator it = v.begin(); it!=v.end();it++)
        std::cout << *it << std::endl;    
    
    return 0;
}

//result:
//  v is empty!