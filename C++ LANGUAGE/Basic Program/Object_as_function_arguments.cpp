/* Example : Object as Function Arguments. */
#include <iostream>
using namespace std;
class timeExample
{
    int hours, minutes;

public:
    void getTime()
    {
        cout << "Enter the hour : ";
        cin >> hours;
        cout << "Enter teh minute : ";
        cin >> minutes;
    }
    void putTime()
    {
        cout << hours << "hours and " << minutes << "minutes.\n";
    }
    // sum fumction to find the sum of hours and minutes.
    void sum(timeExample t1, timeExample t2)
    {
        minutes = t1.minutes + t2.minutes;
        hours = minutes / 60;
        minutes = minutes % 60;
        hours = hours + t1.hours + t2.hours;
    }
};

int main()
{
    timeExample object1, object2, object3; // declaring object.
    object1.getTime();                     // calling getTime() function using object 1.
    object2.getTime();                     // calling getTime() function using object 2.

    object3.sum(object1, object2); /* calling sum() fumction using T3 and passing object T1 amd T2 as arguments.*/
    object1.putTime();
    object2.putTime();
    cout << "TO show the sum of hours and minutes : ";
    object3.putTime();
    return 0;
}