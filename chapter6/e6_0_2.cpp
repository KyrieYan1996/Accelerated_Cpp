#include <iostream>
#include <algorithm>
#include <string>

bool is_palindrome(const std::string &str)
{
    return std::equal(str.begin(),str.end(),str.rbegin());
}

int main(void)
{
    std::cout << "enter a word:" << std::endl;
    std::string s;
    while(std::cin >> s)
    {
        if (is_palindrome(s))
            std::cout << "this word is palindrome!" << std::endl;
        else
            std::cout << "this word isn't palindrome!" << std::endl;
    }
    return 0;
}