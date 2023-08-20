// Specifying field size with width()
#include <iostream>
using namespace std;
int main()
{
    int i, n, item[20], cost[20], sum = 0;
    cout << "How many items you want to insert : ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "Enter item number and cost : ";
        cin >> item[i] >> cost[i];
    }

    cout << "\n";
    cout.width(5);
    cout << "ITEMS";
    cout.width(9);
    cout << "COST";

    cout.width(18);
    cout << "TOTAL AMOUNT"
         << "\n";

    for (i = 0; i < n; i++)
    {
        cout.width(3);
        cout << item[i];

        cout.width(12);
        cout << cost[i];

        int value = item[i] * cost[i];
        cout.width(12);
        cout << value << "\n";
        sum = sum + value;
    }
    cout << "\nGrand Total : ";
    cout.width(2);
    cout << sum << "\n";
    return 0;
}