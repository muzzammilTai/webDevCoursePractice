#include <iostream>
using namespace std;
class sample
{
private: // access modifier
    int a, b;
    public :
    void setvalue()
    {
        cout << "Enter the values of a and b : ";
        cin >> a >> b;
    }
    friend float average(sample s); // friend function declaration.
};

float average(sample s) // defining the friend function - used to access the private member of the class.
{
    return (s.a + s.b) / 2;
}

int main()
{
    sample x;
    x.setvalue();
    cout << "The average value = " << average(x); // calling the friend function and passing object as argument.
    return 0;
}