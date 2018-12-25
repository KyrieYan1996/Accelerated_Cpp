#include <iostream>

int main(void)
{
    using std::cout; using std::cin;
    using std::endl; 
    cout << "please input one of the three rect/square/triangle:";
    std::string type;
    cin >> type;
    if(type=="rect")
    {
        cout << "please input the width:";
        int width;
        cin >> width;
        cout << "please input the height:";
        int height;
        cin >> height;
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
            {
                if(i==0 || i==width-1 || j==0 || j==height-1)
                {
                    cout << "*";
                }
                else
                    cout << " "; 
            }
            cout << endl;
        }
    }
    else if(type=="square")
    {
        cout << "please input the width:";
        int width;
        cin >> width;
        for(int i=0;i<width;i++)
        {
            for(int j=0;j<width;j++)
            {
                if(i==0 || i==width-1 || j==0 || j==width-1)
                {
                    cout << "*";
                }
                else
                    cout << " "; 
            }
            cout << endl;
        }
    }
    else if(type=="triangle")
    {
        cout << "please input the width:";
        int width;
        cin >> width;
        for(int i=0;i<width;i++)
        {
            for(int j=0;j<i+1;j++)
            {
                cout << "*";
            }
            cout << endl;
        } 
    }
    else
        cout <<"input error!"<<endl;
    return 0;
}
/*
please input one of the three rect/square/triangle:rect
please input the width:4
please input the height:3
***
* *
* *
***
PS D:\CV_DL_ML\Cpp> ./a.exe
please input one of the three rect/square/triangle:square
please input the width:4
****
*  *
*  *
****
PS D:\CV_DL_ML\Cpp> ./a.exe
please input one of the three rect/square/triangle:triangle
please input the width:5
*
**
***
****
*****
*/