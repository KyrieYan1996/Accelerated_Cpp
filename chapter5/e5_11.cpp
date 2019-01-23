#include <iostream>
#include <vector>
#include <string>

using std::cin; using std::cout;
using std::vector; using std::string;
using std::endl;

bool up_or_down_letter(string w)
{
    char upletter[7] = {'b','d','f','h','k','l','t'};
    char downletter[5] = {'g','j','p','q','y'};
    for (int i=0;i<7;i++)
        if (w.find(upletter[i])>=0 && w.find(upletter[i])<w.size())
            return true;
    for (int j=0;j<5; j++)
        if (w.find(downletter[j])>=0 && w.find(downletter[j])<w.size())
            return true;
    return false;
}

int main(void)
{
    cout << "please input some words." << endl;
    string s,temp = "a";
    vector<string> wds;
    while (cin>>s)
        wds.push_back(s);
    for (vector<string>::iterator iter = wds.begin();iter!=wds.end();iter++)
    {
        if (!up_or_down_letter(*iter))
        {
            temp = (*iter).size()>temp.size()?(*iter):temp;
        }
    }
    cout << "result is :" << temp << endl;
    return 0;
}