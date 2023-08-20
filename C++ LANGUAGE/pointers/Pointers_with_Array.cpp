#include <iostream>
using namespace std;
int main()
{
    int num[100], *ptr, i, n, sum = 0;
    cout << "Enter the count : ";
    cin >> n;
    cout << "Enter Values one by one : \n";
    for (i = 0; i < n; i++)
    {
        cin >> num[i];
    }
 
    /*Assigning the base address of numbers to ptr */
    ptr = num;
    for (i = 0; i < n; i++)
    {
        if (*ptr % 2 == 0)
        {
            sum = sum + *ptr;
        }
        ptr++; // for incrementing the values in the array.
    }
    cout << "Sum of Even Numbers of an Array = " << sum << "\n";
}