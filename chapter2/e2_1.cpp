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
    const int pad = 1;
    const int rows = 1+pad*2;
    std::string::size_type cols = greeting.size()+pad*2;

    for(int row=0;row<rows;row++)
    {
        for(int col=0;col<cols;col++)
        {
            if(row==0 || row==rows-1 || col==0 || col == cols-1)
            {
                cout << "*" ;
            }
            else if(row == pad && col==pad)
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
Merry_christmas!
**************************
*Yankeli,Merry_christmas!*
**************************
*/