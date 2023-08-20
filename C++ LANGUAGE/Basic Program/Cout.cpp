/*
    Example of c++ basics.
*/

#include <iostream>
using namespace std;
int main()
{
    /*
        Using cout instead of printf.
        Using cin instead of scanf.
    */

    int num1, num2, sum;
    cout << "Enter the value of num1 and num2 : ";
    cin >> num1 >> num2;
    sum = num1 + num2;
    cout << "Sum of Numbers = " << sum;
    return 0;
}