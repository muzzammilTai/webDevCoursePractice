#include <iostream>
using namespace std;
void volume(int, int);
int main()
{
    int r, h;
    cout << "Enter the Radius of : ";
    cin >> r;
    cout << "Enter the Height of : ";
    cin >> h;
    volume(r, h);
    return 0;
}

void volume(int R, int H)
{
    float V;
    V = 3.14 * R * R * H;
    cout << "Volume of Cylinder = " << V << "\n";
}