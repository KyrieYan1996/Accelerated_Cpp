#include <iostream>
#include <vector>
#include <string>
#include <list>

using std::cout; using std::cin;
using std::endl; using std::vector;
using std::string; using std::istream;
using std::list;

struct Student_info{
    string name;
    double grade;
};

istream& read(istream& in, Student_info& s)
{
    in >> s.name >> s.grade;
    return in;
}

bool pass(const Student_info& st)
{
    return st.grade>=60;
}
//vector

int main(void)
{   
    vector<Student_info> students;
    Student_info s;
    cout << "please input name and grade:" << endl;
    while (read(cin,s))
        students.push_back(s);
    vector<Student_info> f_students;
    vector<Student_info>::iterator iter = students.begin();
    while (iter!=students.end())
    {
        if (!pass(*iter))
        {    
            f_students.push_back(*iter);
            iter = students.erase(iter);
        }
        else
            iter++;
    }

    cout << "the students who pass are :"<< endl;
    vector<Student_info>::const_iterator it_pass = students.begin();
    while (it_pass!= students.end())
    {
        cout << it_pass->name << " :" << it_pass->grade << endl;
        it_pass++;
    }

    cout << "the students who doesn't pass are :" << endl;
    vector<Student_info>::const_iterator iter1 = f_students.begin();
    while (iter1!=f_students.end())
    {
        cout << iter1->name << " :" << iter1->grade << endl;
        iter1++;
    } 
    return 0;
}

// list
// int main(void)
// {   
//     list<Student_info> students;
//     Student_info s;
//     cout << "please input name and grade:" << endl;
//     while (read(cin,s))
//         students.push_back(s);
//     list<Student_info> f_students;
//     list<Student_info>::iterator iter = students.begin();
//     while (iter!=students.end())
//     {
//         if (!pass(*iter))
//         {    
//             f_students.push_back(*iter);
//             iter = students.erase(iter);
//         }
//         else
//             iter++;
//     }

//     cout << "the students who pass are :"<< endl;
//     list<Student_info>::const_iterator it_pass = students.begin();
//     while (it_pass!= students.end())
//     {
//         cout << it_pass->name << " :" << it_pass->grade << endl;
//         it_pass++;
//     }

//     cout << "the students who doesn't pass are :" << endl;
//     list<Student_info>::const_iterator iter1 = f_students.begin();
//     while (iter1!=f_students.end())
//     {
//         cout << iter1->name << " :" << iter1->grade << endl;
//         iter1++;
//     } 
//     return 0;
// }

