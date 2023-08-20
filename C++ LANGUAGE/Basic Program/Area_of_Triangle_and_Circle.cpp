/*
    WAP to find the area of Triangle and area of Circle using Overloading Function.
*/

#include <iostream>
using namespace std;
void area(int);
void area(int, int);
int main()
{
    int r, b, h;
    cout << "Enter the Radius of a Circle : ";
    cin >> r;
    cout << "Enter the Height of Triangle : ";
    cin >> h;
    cout << "Enter the Base of a Triangle : ";
    cin >> b;
    area(r);
    area(b, h);
    return 0;
}

void area(int radius)
{
    float Area;
    Area = 3.14 * radius * radius;
    cout << "Area of a Circle = " << Area << "\n";
}

void area(int base, int height)
{
    float Area;
    Area = 0.5 * base * height;
    cout << "Area of a Triangle = " << Area << "\n";
}