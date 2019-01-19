#include <iostream>
#include <vector>
#include <iomanip>

using std::cin; using std::cout;
using std::endl; using std::vector;
using std::setw;

int main(void)
{
    vector<int> nums,squares;
    vector<int>::size_type vec_size;
    for (int i=1;i<=100;i++)
    {
        nums.push_back(i);
        squares.push_back(i*i);
    }
    vec_size = nums.size();
    for (vector<int>::size_type i=0;i<vec_size;i++)
    {
        cout << nums[i] << setw(5) << squares[i] << endl;
    }

    return 0;
}