/*
    Array of Objects Example.
*/

#include <iostream>
using namespace std;
class employee
{
    char name[50];
    int age;

public:
    void getdata()
    {
        cout << "\nEnter the name : ";
        cin >> name;
        cout << "Enter the age : ";
        cin >> age;
    }
    void display()
    {
        cout << "Name : " << name << "\nAge : " << age << "\n";
    }
};

int main()
{
    employee e[50]; // Creating object of array.
    int n, i;
    cout << "Enter the number of employee : ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "Enter details for employe : " << i + 1;
        e[i].getdata(); // calling getdata function.
    }
    cout << "\nDisplaying employee details\n\n";
    for (i = 0; i < n; i++)
    {
        cout << "employee : " << i + 1 << "\n\n";
        e[i].display(); // calling display function.
    }
    return 0;
}