#include <iostream>
#include <string.h>
using namespace std;
class Record
{
protected:
    char n[100][100];
    int rnk[100], num, i, count;

public:
    Record() {}
    void readvalues()
    {
        count = 0;
        cout << "Enter No of Students : ";
        cin >> num;
        for (i = 0; i < num; i++)
        {
            cout << "Enter Student Name : ";
            cin >> n[count];
            cout << "Enter Rank : ";
            cin >> rnk[count];
            count++;
        }
    }
    void display()
    {
        for (i = 0; i < count; i++)
        {
            cout << "\nName : " << n[i] << "\tRank : " << rnk[i];
        }
    }
};

class Rank : public Record
{
    int index, h = 0;

public:
    Rank() : Record()
    {
        index = 0;
    }
    void higest()
    {
        h = rnk[0];
        readvalues();
        display();
        for (i = 0; i < count; i++)
        {
            if (rnk[i] < h)
            {
                h = rnk[i];
                index = i;
            }
        }
        cout << "\nHighest Rank : \nName : " << n[index] << "\nRank : " << rnk[index] << "\n";
    }
};

int main()
{
    Rank r;
    r.higest();
    return 0;
}