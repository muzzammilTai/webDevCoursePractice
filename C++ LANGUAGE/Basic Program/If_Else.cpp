#include <iostream>
using namespace std;
int main()
{
    int age;
    cout << "Enter the age of a Person : ";
    cin >> age;
    if (age >= 18)
    {
        cout << "Eligable to Vote.";
    }
    else
    {
        cout << " Not, Eligable to Vote.";
    }
    return 0;
}