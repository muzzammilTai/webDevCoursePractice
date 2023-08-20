#include <iostream>
using namespace std;
float volume(int, int);
int main()
{
    int r, h;
    float ans;
    cout << "Enter the Radius of : ";
    cin >> r;
    cout << "Enter the Height of : ";
    cin >> h;
    ans = volume(r, h);
    cout << "Volume of Cylinder = " << ans << "\n";
    return 0;
}

float volume(int R, int H)
{
    float V;
    V = 3.14 * R * R * H;
    return V;
}