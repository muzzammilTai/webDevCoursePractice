#include <iostream>
using namespace std;
int main()
{
    int i, sum = 0;
    for (i = 1; i <= 10; i++)
    {
        sum = sum + i;
    }
    cout << "Sum of numbers between 1 to 10 : " << sum;
    return 0;
}