#include <iostream>
using namespace std;
int main()
{
    int age;
    cout << "enter person age : ";
    cin >> age;
    if (age >= 18)
    {
        cout << "Eligable for voting";
    }
    else
    {
        cout << "Not Eligable for voting";
    }
    return 0;
}