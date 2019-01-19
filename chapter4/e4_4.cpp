#include <iostream>
#include <vector>
#include <iomanip>

using std::cin; using std::cout;
using std::endl; using std::vector;
using std::setw;

int set_width(int size)
{
    int width=0;
    while (size!=0)
    {
        size /= 10;
        width++;
    }
    return 2*width+1;
}

int main(void)
{
    vector<double> nums,squares;
    vector<double>::size_type vec_size;
    for (double i=1;i<=100;i++)
    {
        nums.push_back(i);
        squares.push_back(i*i);
    }
    vec_size = nums.size();
    for (vector<double>::size_type i=0;i<vec_size;i++)
    {
        cout << nums[i] << setw(set_width(vec_size)) << squares[i] << endl;
    }

    return 0;
}