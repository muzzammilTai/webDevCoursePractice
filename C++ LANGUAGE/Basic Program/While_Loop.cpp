#include <iostream>
using namespace std;
int main()
{
    int i, sum = 0;
    i = 1;
    while (i <= 10)
    {
        sum = sum + i;
        i++;
    }
    cout << "Sum of Numbers between 1 to 10 : " << sum;
    return 0;
}