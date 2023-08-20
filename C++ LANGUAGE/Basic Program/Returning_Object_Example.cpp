#include <iostream>
using namespace std;
class complexNumber
{
    float x, y;

public:
    void input(float real, float imaginary)
    {
        x = real;
        y = imaginary;
    }
    void showOutput()
    {
        cout << x << " + " << y << "\n";
    }
    friend complexNumber sum(complexNumber, complexNumber); // friend function declaration
};

complexNumber sum(complexNumber c1, complexNumber c2) // passing object as arguments
{
    complexNumber c3; // object of complexnumber class is created.
    c3.x = c1.x + c2.x;
    c3.y = c1.y + c2.y;
    return c3; // return object c3
}
int main()
{
    complexNumber A, B, C; // declaring objects for complexNumber complex.
    A.input(10, 20);
    B.input(30, 40);
    C = sum(A, B); // C=A+B.
    cout << "A = ";
    A.showOutput();
    cout << "B = ";
    B.showOutput();
    cout << "C = ";
    C.showOutput();
    return 0;
}