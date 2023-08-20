#include <iostream>
using namespace std;
int main()
{
    int a, *ptr1, **ptr2;
    cout << "Enter the value of a : ";
    cin >> a;
    ptr1 = &a;
    ptr2 = &ptr1;
    cout << "The Address of a = " << ptr1 << "\n";
    cout << "The Address of ptr1 = " << ptr2 << "\n\n";
    cout << "After Incrementing the Adress values : \n";
    ptr1 += 2;
    cout << "The Address of a = " << ptr1 << "\n";
    ptr2 += 2;
    cout << "The Address of prt1 = " << ptr2 << "\n";
    return 0;
}