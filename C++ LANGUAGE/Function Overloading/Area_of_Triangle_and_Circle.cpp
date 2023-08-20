#include <iostream>
using namespace std;
void area(int);
void area(int, int);
int main()
{
    int r, b, h;
    cout << "Enter Radius of a circle : ";
    cin >> r;
    cout << "Enter Height of a Triangle : ";
    cin >> h;
    cout << "Enter Base of a circle : ";
    cin >> b;
    area(r);
    area(b, h);
    return 0;
}

void area(int R)
{
    float A;
    A = 3.14 * R * R;
    cout << "Area of Cicle : " << A << "\n";
}
void area(int B, int H)
{
    float A;
    A = 0.5 * B * H;
    cout << "Area of Triangle : " << A << "\n";
}