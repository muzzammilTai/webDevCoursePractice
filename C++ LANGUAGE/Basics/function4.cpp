#include <iostream>
using namespace std;
float volume(void);
int main()
{
    float ans;
    ans = volume();
    cout << "Volume of Cylinder = " << ans << "\n";
    return 0;
}
float volume()
{
    int r, h;
    float V;
    cout << "Enter the Radius of : ";
    cin >> r;
    cout << "Enter the Height of : ";
    cin >> h;
    V = 3.14 * r * r * h;
    return V;
}