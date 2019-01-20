#include "students_info.h"
#include "grades.h"

using std::cout; using std::cin;

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
    static vector<double> hw1; //note static!
    static double midterm=0,finals=0;
    in >> s.name >> midterm >> finals;
    read_hw(in,hw1);
    s.final_grade = grade(midterm,finals,median(hw1));
    return in;
}

bool compare(const Student_info& x,const Student_info& y)
{
    return x.name < y.name;
}