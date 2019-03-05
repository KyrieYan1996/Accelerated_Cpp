#include "grades.h"
#include "students_info.h"
#include <algorithm>
#include <stdexcept>

using std::vector; using std::sort;
using std::domain_error;

//更改形参类型，由传入向量改为传入迭代器
double median(vector<double>::const_iterator begin, vector<double>::const_iterator end)  
{
    int size = end-begin;
    if (size==0)
    {
        throw domain_error("median if an empty vector");
        return 1;
    }
    sort(begin,end);
    return size%2?*(begin+size/2):*(begin+size/2)+*(begin+size/2-1);

}

double grade(double midterm,double final_grade,double median)
{
    return 0.2*midterm + 0.4*final_grade + 0.4*median;
}

double grade(const Student_info& s)
{
    vector<double>::const_iterator b = s.homework.begin();
    vector<double>::const_iterator e = s.homework.end();
    grade(s.midterm,s.finals,median(b,e));
}