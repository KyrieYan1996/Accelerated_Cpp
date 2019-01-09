#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using std::cout; using std::cin;
using std::endl; using std::string;
using std::setprecision; using std::streamsize;
using std::sort; using std::vector;
int main(void)
{
    cout << "please input ur name:";
    string name;
    cin >> name;
    cout << "Hello,"+name+"!" << endl;
    cout << "please input ur midterm and final exam grades:";
    double midterm,final_ex;
    cin >> midterm >> final_ex;
    
    cout << "enter ur homework grades, " "followed by end-the-file:";
    int count=0;
    double x = 0;
    vector<double> homework;

    while(cin >> x)
    {
        ++count;
        homework.push_back(x);
    }
    typedef vector<double>::size_type vec_sz;
    vec_sz size = homework.size();
    if (size==0)
    {
        cout << endl << "u must enter ur grades." << endl;
        return 1;
    } 
    sort(homework.begin(), homework.end());
    vec_sz mid = size/2;
    double median=0;
    median = size%2==0? (homework[mid-1]+homework[mid])/2 : homework[mid];
    streamsize prec = cout.precision();
    cout << " ur final grade is " << setprecision(3) << 0.2*midterm+0.4*final_ex+0.4*median 
                                  << setprecision(prec) << endl;

    return 0;
}