#include <iostream>
using namespace std;
int main()
{
    int a[20], i, sum = 0, num;
    cout << "Enter the size of an array : ";
    cin >> num;
    for (i = 0; i < num; i++)
    {
        cout << "a[" << i << "] : ";
        cin >> a[i];
    }

    cout << "Elements of an array :\n";
    for (i = 0; i < num; i++)
    {
        cout << "a[" << i << "] : " << a[i];
        cout << "Elements of an array :\n";
    }

    for (i = 0; i < num; i++)
    {
        sum = sum + a[i];
    }
    cout << "Sum of All Elemenets = " << sum "\n";
    return 0;
}