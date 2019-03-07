#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// int main()
// {
//     ifstream infile("in.txt");
//     ofstream outfile("out.txt");

//     string s;
//     while (getline(infile,s))
//         outfile << s << endl;
//     return 0;
// }

int main(int argc, char** argv)
{
    int fail_count = 0;
    for (int i = 1; i < argc; i++)
    {
        ifstream fin(argv[i]);
        if (fin)
        {
            string s;
            while (getline(fin,s))
            {
                cout << s << endl;
            }
        }
        else
        {
            cerr << "cannot open file " << argv[i] << endl;
            ++fail_count;
        }
        
    }
    return fail_count;
}