#include <iostream>
using namespace std;
int main()
{
    /*
        using cout instead of printf
        using cin instead of scanf,
    */

    int num1, num2, sum;
    cout << "Enter the values of num1 and num2 : ";
    cin >> num1 >> num2;
    sum = num1 + num2;
    cout << "Sum of numbers = " << sum;
    return 0;
}