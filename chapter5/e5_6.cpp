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

typedef vector<Student_info> container_type;
//typedef list<Student_info> container_type;

istream& read(istream& in, Student_info& s)
{
    in >> s.name >> s.grade;
    return in;
}

bool pass(const Student_info& st)
{
    return st.grade>=60;
}

void extract_pass(container_type& s)
{
    int cnt=0;
    // for (container_type::const_iterator iter=s.begin();iter!=s.end();iter++) //!!这里s.end()只在初始化时执行一次，后面不再执行，只用于判断！ 
    // {
    //     if (pass(*iter))
    //     {
    //         s.insert(s.begin(),*iter);
    //         cnt+=1;
    //         iter++;
    //     }
    // }
    container_type::const_iterator iter=s.begin();
    while (iter!=s.end())
    {
        if (pass(*iter))
        {
            s.insert(s.begin(),*iter);
            cnt+=1;
            iter++;
        }
        iter++;
    }
    s.resize(cnt);
}

int main(void)
{   
    container_type students;
    Student_info s;
    cout << "please input name and grade:" << endl;
    while (read(cin,s))
        students.push_back(s);

    extract_pass(students);

    cout << "the students who pass are :"<< endl;
    container_type::const_iterator it_pass = students.begin();
    while (it_pass!= students.end())
    {
        cout << it_pass->name << " :" << it_pass->grade << endl;
        it_pass++;
    }
    return 0;
}