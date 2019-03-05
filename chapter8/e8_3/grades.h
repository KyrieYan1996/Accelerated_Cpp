#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>
#include "students_info.h"
using std::vector;

double median(vector<double> homework);
double grade(double midterm,double final_grade,double median);
double grade(const Student_info& s);

#endif