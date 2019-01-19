#ifndef GUARD_students_info
#define GUARD_students_info

#include <string>
#include <vector>
#include <iostream>

using std::vector; using std::string;
using std::istream;

struct Student_info{
    string name;
    double final_grade;
};

istream& read_hw(istream& in, vector<double>& hw);
istream& read(istream& in, Student_info& s);
bool compare(const Student_info& x,const Student_info& y);

#endif