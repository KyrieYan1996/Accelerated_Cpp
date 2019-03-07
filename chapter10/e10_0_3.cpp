#include <iostream>
#include <string>

using namespace std;

string letter_grade(double grade)
{
    static const double numbers[] = {97,94,90,87,84,80,77,74,70,60,0};
    static const string letters[] = {"A+","A","A-","B+","B","B-","C+","C","C-","D","F"};
    static const char* const letters1[] = {"A+","A","A-","B+","B","B-","C+","C","C-","D","F"};
    cout << *letters1 << endl;
    cout << letters[0] << *letters << endl;

    static const size_t ngrades = sizeof(numbers)/sizeof(*numbers);
    for (int i = 0;i < ngrades;i++)
    {
        if (grade>=numbers[i])
            return letters[i];
    }

    return "?\?\?";

}

int main(int argc, char** argv)
{
    if (argc>1)
    {
        cout << "the value of argc is:" << argc << endl;
        int i;
        for (i=1;i<argc-1;i++)
            cout << argv[i] << "*";
        cout << argv[i] << endl;
    }
    /*
    D:\CV_DL_ML\Cpp>a Hello, world, Cplusplus !
    the value of argc is:5
    Hello,*world,*Cplusplus*!
    */

    string level = letter_grade(59);
    cout << level << endl;
    
    
    return 0;
}