#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <iomanip>
#include <ios>
#include <string>
#include "grades.h"
#include "students_info.h"

using std::string; using std::vector;
using std::istream; using std::domain_error;
using std::cin; using std::cout;
using std::endl; using std::max;
using std::setw;


int main(void)
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen=0;

    while (read(cin,record))
    {
        maxlen = max(maxlen,record.name.size());
        students.push_back(record);
    }

    sort(students.begin(),students.end(),compare);

    for (vector<Student_info>::size_type i=0; i!= students.size();i++)
    {
        cout << setw(maxlen+1) << students[i].name ;

        try 
        {
            double finals_grade = grade(students[i]);
            cout << " ";
            cout << students[i].midterm <<" "<< students[i].finals <<" "<<students[i].homework[0] <<" " 
            <<students[i].homework[1] <<" "<< students[i].homework[2];
            cout << " ";
            cout << finals_grade << endl;
        } 
        catch (domain_error e)
        {
            cout << e.what();
        }
        cout << endl;

    }
    return 0;
}
