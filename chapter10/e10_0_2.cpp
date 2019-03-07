#include <iostream>
#include <iterator>
#include <string>
#include <cstring>

using namespace std;

size_t _strlen(const char* c)//形参类型为 char* ，要传入str[0]的地址而不能直接传入str的地址
{
    size_t i=0;
    while (*c++ != '\0')
        i++;
    return i;
}

int main()
{
    string str = "Hello";
    char* pc = &str[0];
    cout << *pc << endl;//H
    string* pt = &str;
    cout << *pt << endl; //H
    const char Hello[] = {'H','e','l','l','o','\0'};
    string s(Hello,Hello+_strlen(Hello));
    cout << s << endl; //Hello
    
    cout << _strlen(Hello) << endl; //5
    cout << _strlen(&str[0]) << endl;//5
    //string类的存储方式???
    return 0;
}