// Reading strings with getline()
#include <iostream>
using namespace std;
int main()
{
    int size = 100;
    char city[100];

    cout << "Enter City Name 1 : ";
    cin >> city;
    cout << "City 1 : " << city << "\n\n";

    cout << "Enter City Name 2 : ";
    cin.getline(city, size);
    cout << "City 2 : " << city << "\n\n";

    cout << "Enter City Name 3 : ";
    cin.getline(city, size);
    cout << "City 3 : " << city << "\n\n";

    cout << "Enter City Name 4 : ";
    cin.getline(city, size);
    cout << "City 4 : " << city << "\n\n";

    return 0;
}