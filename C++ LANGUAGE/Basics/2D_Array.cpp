#include <iostream>
using namespace std;
int main()
{
    int a[100][100], i, j, n, m, sum = 0;
    cout << "Enter the size of an array : ";
    cin >> m >> n;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << "a[" << i << "] [" << j << "] : ";
            cin >> a[i][j];
        }
    }

    cout << "Elements of an array :\n";
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << "a[" << i << "] [" << j << "] : ", a[i][j];
            cout << "\n";
        }
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            sum = sum + a[i][j];
        }
    }
    cout << "Sum of All Elemenets = " << sum << "\n";
    return 0;
}