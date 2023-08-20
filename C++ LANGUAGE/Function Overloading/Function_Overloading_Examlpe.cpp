/*
    Example of Function Overloading.
    Function Overloading : The Function name remains the same whereas the parameters/arguments will change/vary.
*/

#include <iostream>
using namespace std;

// Declaring Function.
int volume(int);
double volume(double, int);
long volume(long, int, int);

int main()
{
    int side;
    cout << "Enter the side of the Cube : ";
    cin >> side;
    cout << "Volume of Cube : " << volume(side) << "\n";             // Calling Function with one parameter.
    cout << "Volume of Cylinder : " << volume(2.5, 10) << "\n";      // Calling Function with two parameter.
    cout << "Volume of Rectangle : " << volume(100, 10, 10) << "\n"; // Calling Function with three parameter.
}

// Funciton Defination.
int volume(int side) // cube.
{
    return (side * side * side);
}
double volume(double r, int h) // cube.
{
    return (3.14 * r * r * h);
}
long volume(long l, int b, int h) // cube.
{
    return (l * b * h);
}