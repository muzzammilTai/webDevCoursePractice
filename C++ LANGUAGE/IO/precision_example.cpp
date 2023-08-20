// precision setting with precision().

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int i;
    cout << "Precision set to 3 digits\n";
    cout.precision(3);
    cout.width(7);
    cout << "VALUE";
    cout.width(20);
    cout << "SqRt of Value\n";
    for (i = 1; i < 10; i++)
    {
        cout.width(6);
        cout << i;
        cout.width(12);
        cout << sqrt(i) << "\n";
    }
    cout << "Precision set to 5 digits\n";
    cout.precision(5); // precision parameter changed
    cout << "sqrt(10) = " << sqrt(10) << "\n\n";
    cout.precision(0); // precision set to default
    cout << "sqrt(10) = " << sqrt(10) << "(Default Setting)";

    return 0;
}