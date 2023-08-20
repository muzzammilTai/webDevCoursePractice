/*
    Example of Static data member.
*/

#include <iostream>
using namespace std;
class item
{
    static int count_num;
    int number;

public:
    void getData(int a)
    {
        number = a;
        count_num++; // count_num = count_num + 1.
    }
    void getCount()
    {
        cout << "Count : " << count_num << "\n";
    }
};

int item ::count_num; // defination of static data number.
int main()
{
    item a, b;    // static variable is initialized to ZERO when object are created.
    a.getCount(); // Display count.
    b.getCount();

    a.getData(100); // getting data into object a.
    a.getCount();
    b.getData(200); // getting data into object b.
    cout << "After Reading Data \n ";

    b.getCount();
    return 0;
}