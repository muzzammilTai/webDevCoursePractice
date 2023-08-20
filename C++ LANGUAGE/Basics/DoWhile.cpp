#include <iostream>
using namespace std;
int main()
{
    int i;
    cout << "list of Number which are not diviasble by 2, 3 and 5.\n";
    i = 1;
    do
    {
        if (i % 2 != 0 && i % 3 != 0 && i % 5 != 0)
        {
            cout << i << "\n";
        }
        i++;
    } while (i <= 50);
    return 0;
}