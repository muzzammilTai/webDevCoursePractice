#include <iostream>
using namespace std;
int main()
{
    int m1, m2, m3;
    float A, T;
    cout << "Enter the marks of maths, english, and science : ";
    cin >> m1 >> m2 >> m3;
    T = m1 + m2 + m3;
    cout << "Total marks of a Student : " << T << "\n";

    A = T / 3;
    cout << "Average marls of a student : " << A << "\n";

    if (A >= 80 && A <= 100)
    {
        cout << "Honour Grade.";
    }
    else if (A >= 60 && A <= 79)
    {
        cout << "First Division Grade.";
    }
    else if (A >= 50 && A <= 59)
    {
        cout << "Second Division Grade.";
    }
    else if (A >= 40 && A <= 49)
    {
        cout << "Third Division Grade.";
    }
    else if (A >= 0 && A <= 39)
    {
        cout << "Fail.";
    }
    return 0;
}