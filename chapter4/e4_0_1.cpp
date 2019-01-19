#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using std::vector; using std::istream;
using std::cin; using std::sort;
using std::cout; using std::endl;
using std::domain_error;using std::streamsize;

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

istream& read_hw(istream& in,vector<double>& hw)
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

int main(void)
{
    cout << "please enter ur midterm grade and ur final grade:";
    double midterm,final_grade;
    cin >> midterm >> final_grade;
    cout << "please input ur homework grade,and end with (ctrl+z)" << endl;
    vector<double> homework;
    read_hw(cin,homework);
    try {
        double finals = grade(midterm,final_grade,median(homework));
        cout << "finals is " << finals << endl;
    } catch (domain_error) {
        cout << "U must enter ur grades,and please try again" << endl;
        return 1;
    }
    return 0;
}