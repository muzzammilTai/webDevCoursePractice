#include <iostream>
using namespace std;
void volume(double);
void volume(double, double);
void volume(double, double, double);
int main()
{
    int r1, r2, h1, h2, l, b;
    cout << "Enter the Radius of Sphere : ";
    cin >> r1;
    volume(r1);
    cout << "Enter the Radius of Cone : ";
    cin >> r2;
    cout << "Enter the Height of a Cone : ";
    cin >> h1;
    volume(r2, h1);
    cout << "Enter the Height of Cuboid : ";
    cin >> h2;
    cout << "Enter the Lenght of Cuboid : ";
    cin >> l;
    cout << "Enter the Base of Cuboid : ";
    cin >> b;
    volume(h2, l, b);
    return 0;
}

void volume(double radius)
{
    double v;
    v = 1.33 * 3.14 * radius * radius * radius;
    cout << "Volume of a Sphere = " << v << "\n\n";
}
void volume(double radius, double height)
{
    double v;
    v = 0.33 * 3.14 * radius * radius * height;
    cout << "Volume of a Cone = " << v << "\n\n";
}

void volume(double height, double lenght, double base)
{
    double v;
    v = lenght * base * height;
    cout << "Volume of a Cuboid = " << v << "\n";
}