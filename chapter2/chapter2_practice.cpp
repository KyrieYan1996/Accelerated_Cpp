#include <iostream>
#include <string>
/*
int main()
{
    std::cout << "please input ur name:" << std::endl;
    std::string name;
    std::cin >> name;
    std::string greeting = "Hello," + name + "!";

    const int pad = 1;
    const int rows = pad * 2 + 3;
    std::cout << std::endl;//把输出与输入隔开
    int row = 0;

    std::string::size_type cols = greeting.size() + pad * 4; //总列数

    while (row<rows)
    {
        std::string::size_type c = 0;
        while (c<cols)
        {
            if ((c==0) || (c==cols-1) || (row==0) || (row==rows-1))
            {
                std::cout << "*" ;
                ++c;
            }
            else if (row==pad+1 && c==pad+1)
            {
                std::cout  << greeting ;
                c+=greeting.size();
            }
            else
            {
                std::cout << " ";
                ++c;
            }
        }
        ++row;
        std::cout << std::endl;
    }
    return 0;
}*/
/*
please input ur name:
yankeli

******************
*                *
* Hello,yankeli! *
*                *
******************
*/
int main()
{
    std::cout << "please input ur name:" << std::endl;
    std::string name;
    std::cin >> name;
    std::string greeting = "Hello," + name + "!";
    const int pad = 1;
    const int rows = pad * 2 + 3;
    std::string::size_type cols = greeting.size() + pad * 4;
    for (int r=0;r < rows;r++)
    {
        for (int c=0;c<cols;c++)
        {
            if (r==0 || r==rows-1 || c==0 || c==cols-1)
            {
                std::cout << "*";
            }
            else if (r==pad+1 && c==pad+1)
            {
                std::cout << greeting ;
                c+=greeting.size()-1;
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
/*
please input ur name:
yankeli
******************
*                *
* Hello,yankeli! *
*                *
******************
*/