#include <iostream>
#include <string>

int main()
{
    //std::cout << "Please input ur name:" << std::endl;
    std::cout << "Please input ur name:" ;//与第一句的区别在于是否会结束本行！
    std::string name;
    std::cin >> name;
    std::cout << "hello, " << name << "!" << std::endl;
    const std::string greeting = "hello, " + name + "!";
    std::cout << "len(greeting):" << greeting.size() << std::endl;
    const std::string spaces(greeting.size(),' ');
    const std::string first(greeting.size()+4,'*');
    const std::string second = "**" + spaces + "**";
    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << "* " + greeting + " *" << std::endl;
    std::cout << second << std::endl;
    std::cout << first << std::endl;
    return 0;
}
/*
Please input ur name:yankeli
hello, yankeli!
len(greeting):15
*******************
**               **
* hello, yankeli! *
**               **
*******************
*/
/*
int main()
{
    std::cout << "whats ur name?" ;
    std::string name;
    std::cin >> name;
    std::cout << "my name is " + name +"and ur name?";
    std::cin >> name;
    std::cout << "and my name is " + name << std::endl;
    return 0;
}*/

