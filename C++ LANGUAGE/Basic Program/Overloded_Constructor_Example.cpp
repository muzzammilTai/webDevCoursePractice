#include <iostream>
using namespace std;
class complex
{
    int x, y;

public:
    complex() {}
    complex(float a)
    {
        x = y = a;
    }
    complex(float real, float imag)
    {
        x = real;
        y = imag;
    }
    friend complex sum(complex c1, complex c2);
    friend void show(complex);
};

complex sum(complex c1, complex c2)
{
    complex c3;
    c3.x = c1.x + c2.x;
    c3.y = c3.y + c3.y;
    return c3;
}

void show(complex c)
{
    cout << c.x << "+j" << c.y << "\n";
}
int main()
{
    complex ce1(20);
    complex ce2(10, 20);

    complex c3;
    c3 = sum(ce1, ce2);

    cout << "Object ce1 : ";
    show(ce1);
    cout << "Object ce2 : ";
    show(ce2);
    cout << "Final Sum : ";
    show(c3);
    return 0;
}