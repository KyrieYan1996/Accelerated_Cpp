#include <iostream>
#include <vector>
#include <algorithm>

using std::cout; using std::cin;
using std::endl; using std::vector;
using std::string;
int main()
{
    vector<double> grades;
    vector<string> names;
    int grade1=0,grade2=0,grade3=0;
    while (true)
    {
        cout << "please input name:" ;
        string name;
        if (cin >> name);
        else
            break;
        cout << "input the three grades:";
        cin >> grade1 >> grade2 >> grade3;
        names.push_back(name);
        grades.push_back((grade1+grade2+grade3)/3);
    }
    if (names.size()!=grades.size())
        cout << "error!" << endl;
    for (int i=0;i<names.size();i++)
    {
        cout << names[i] << " final grade is:" << grades[i] << endl;
    }
    return 0;
}