#include <iostream>

int main(void)
{
    using std::cout; using std::cin;
    using std::endl; using std::string;

    cout << "please input ur name:" << endl;
    string name;
    cin >> name;
    cout << "please input the greeting words:" << endl;
    string greeting;
    cin >> greeting;
    greeting = name+","+greeting;
    cout << "please input the number of quad" << endl;
    int pad;
    cin >> pad;
    const int rows = pad*2+3;
    std::string::size_type cols = greeting.size()+pad*2+2;

    for(int row=0;row<rows;row++)
    {
        for(int col=0;col<cols;col++)
        {
            if(row==0 || row==rows-1 || col==0 || col == cols-1)
            {
                cout << "*" ;
            }
            else if(row == pad+1 && col==pad+1)
            {
                cout << greeting;
                col+=greeting.size()-1;
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
    
}
/*
please input ur name:
Yankeli
please input the greeting words:
Hello!
please input the number of quad
2
********************
*                  *
*                  *
*  Yankeli,Hello!  *
*                  *
*                  *
********************
PS D:\CV_DL_ML\Cpp> ./a.exe
please input ur name:
Yan
please input the greeting words:
HaHa!
please input the number of quad
3
*****************
*               *
*               *
*               *
*   Yan,HaHa!   *
*               *
*               *
*               *
*****************
*/