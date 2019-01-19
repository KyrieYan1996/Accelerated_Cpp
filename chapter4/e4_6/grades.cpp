#include "grades.h"
#include "students_info.h"
#include <algorithm>
#include <stdexcept>

using std::vector; using std::sort;
using std::domain_error;

double median(vector<double> homework)
{
    typedef vector<double>::size_type vec_sz;
    vec_sz size = homework.size();
    if (size==0)
    {
        throw domain_error("median if an empty vector");
        return 1;
    }
    sort(homework.begin(),homework.end());
    return size%2?homework[size/2]:(homework[size/2-1]+homework[size/2])/2;

}

double grade(double midterm,double final_grade,double median)
{
    return 0.2*midterm + 0.4*final_grade + 0.4*median;
}
