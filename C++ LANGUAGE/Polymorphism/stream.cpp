#include <iostream>
#include <string.h>
using namespace std;
class student
{
    char name[100];
    int rn, t_marks;
    char stream[100];
    int i, avg, j, m[100];

public:
    void data()
    {
        cout << "Enter the Name of Student : ";
        cin >> name;
        cout << "Enter Roll No. of Student : ";
        cin >> rn;
        for (j = 1; j <= 5; j++)
        {
            cout << "Enter marks of " << name << " Student in " << j << " subject : ";
            cin >> m[j];
        }
        cout << "\n";
    }
    void display()
    {
        t_marks = 0;
        for (j = 1; j <= 5; j++)
        {
            t_marks = t_marks + m[j];
        }
        avg = t_marks / 5;
        if (avg >= 90)
        {
            strcpy(stream, "Science with Computers");
        }
        else if (avg >= 80 && avg <= 89)
        {
            strcpy(stream, "Science without Computers");
        }
        else if (avg >= 70 && avg <= 79)
        {
            strcpy(stream, "Commerece with Maths");
        }
        else if (avg >= 60 && avg <= 69)
        {
            strcpy(stream, "Commerece without Maths");
        }

        cout << name << "\t " << rn << "\t " << t_marks << "\t " << avg << "\t " << stream << "\n";
    }
};

int main()
{
    student user[100];
    int i;
    for (i = 1; i <= 2; i++)
    {
        user[i].data();
    }
    cout << "Name\t Roll No.\t Total Marks\t Average\t stream\n";
    for (i = 1; i <= 2; i++)
    {
        user[i].display();
    }
    return 0;
}