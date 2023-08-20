#include <iostream>
using namespace std;
class ABC; // forward declaration-DECLARING CLASS BECAUSE IT IS USED IN FRIENDLY FUNCTION DECLARATION.

class XYZ
{
    int x;

public:
    void setvalue()
    {
        cout << "Enter the values of x : ";
        cin >> x;
    }
    friend void maxValue(XYZ m, ABC n); // declaring friend function.
};

class ABC
{
    int y;

public:
    void setValue()
    {
        cout << "Enter the Value of y : ";
        cin >> y;
    }
    friend void maxValue(XYZ m, ABC n); // declaring friend function.
};

void maxValue(XYZ m, ABC n) // defining the friend function.
{
    if (m.x > n.y)
    {
        cout << "Maximum Value : " << m.x;
    }
    else
    {
        cout << "Maximum Value : " << n.y;
    }
}

int main()
{
    ABC abc;
    abc.setValue();
    XYZ xyz;
    xyz.setvalue();
    maxValue(xyz, abc); // calling of friend function.
    return 0;
}