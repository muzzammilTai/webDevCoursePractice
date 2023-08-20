#include <iostream>
using namespace std;
int main()
{
    int t, m1, m2, m3, a;
    cout << "Enter Marks of English, Science, Maths : ";
    cin >> m1 >> m2 >> m3;

    t = m1 + m2 + m3;
    cout << "Total marks of Student." << t;

    a = t / 3;
    cout << "\nAverage marks of student : " << a;

    if (a >= 80 && a <= 100)
    {
        cout << "\nHonours";
    }
    else if (a >= 60 && a <= 79)
    {
        cout << "\nFirst Division";
    }
    else if (a >= 60 && a <= 79)
    {
        cout << "\nFirst Division";
    }
    else if (a >= 50 && a <= 59)
    {
        cout << "\nSecond Division";
    }
    else if (a >= 40 && a <= 49)
    {
        cout << "\nThird Division";
    }
    else if (a >= 0 && a <= 39)
    {
        cout << "\nFail";
    }
    return 0;
}