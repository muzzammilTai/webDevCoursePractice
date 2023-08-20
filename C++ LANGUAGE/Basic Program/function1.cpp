#include <iostream>
using namespace std;
void volume(void);
int main()
{
    volume();
    return 0;
}

void volume(void)
{
    float V;
    int r, h;
    cout << "Enter the Radius of : ";
    cin >> r;
    cout << "Enter the Height of : ";
    cin >> h;
    V = 3.14 * r * r * h;
    cout << "Volume of Cylinder = " << V << "\n";
}