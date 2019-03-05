#include "students_info.h"

using std::cout;

istream& read_hw(istream& in, vector<double>& hw)
{
    if (in)
    {
        hw.clear();
        double x;
        while (in >> x)
            hw.push_back(x);
        in.clear();
    }
    return in;
}

istream& read(istream& in, Student_info &s)
{
    cout << "please enter ur name and grades and homework:";
    in >> s.name >> s.midterm >> s.finals;
    
    read_hw(in,s.homework);
    return in;
}

bool compare(const Student_info& x,const Student_info& y)
{
    return x.name < y.name;
}