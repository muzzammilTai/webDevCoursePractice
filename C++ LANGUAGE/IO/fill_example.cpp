// Padding with fill()
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n, i;
    cout << "Enter the value of n : ";
    cin >> n;
    cout.precision(5);
    for (i = 1; i < n; i++)
    {                         
        cout.width(10);
        if (i == 3)
        {
            cout.fill('*');
        }
        else
        {
            cout.fill('#');
        }
        cout << " " << i << " ";
        cout.width(10);
        cout << " " << sqrt(i) << " ";
        cout << "\n";
    }
    return 0;
}