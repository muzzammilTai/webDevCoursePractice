// Displaying strings with write() function
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char s1[100], s2[100];
    int len1, len2, i;
    cout << "Enter the value of s1 : ";
    cin >> s1;
    cout << "Enter the value of s2 : ";
    cin >> s2;

    len1 = strlen(s1);
    len2 = strlen(s2);
    for (i = 0; i <= len2; i++)
    {
        cout.write(s2, i);
        cout << "\n";
    }

    for (i = len2; i >= 0; i--)
    {
        cout.write(s2, i);
        cout << "\n";
    }

    // concatenating strings
    cout << "\nstring concatenating : ";
    cout.write(s1, len1).write(s2, len2);

    // concatenating strings
    strcat(s1, s2);
    cout << "\nstring concatenating : ";

    // crossing the boundary
    cout << "\nBoundary : ";
    cout.write(s1, 10);
    cout << "\n";

    return 0;
}