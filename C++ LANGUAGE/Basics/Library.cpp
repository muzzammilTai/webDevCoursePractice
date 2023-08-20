#include <iostream>
#include <string.h>
using namespace std;
class library
{
protected:
    char name[100], author[100];
    int price;

public:
    library(char n[], char a[], int p)
    {
        strcpy(name, n);
        strcpy(author, a);
        price = p;
    }
    void show()
    {
        cout << "\nBook Details : \nBook Name : " << name << "\nAuthor's Name : " << author << "\nPrice : " << price << "\n";
    }
};

class compute : public library
{
    int days, f;
    float charges, Total;

public:
    compute(char n[], char a[], int p, int d) : library(n, a, p)
    {
        days = d;
    }
    void fine()
    {
        charges = 0.02 * price;
        if (days >= 1 && days <= 5)
        {S
            f = 2 * days;
        }
        else if (days >= 6 && days <= 10)
        {
            f = 3 * days;
        }
        else if (days > 10)
        {
            f = 5 * days;
        }
        Total = (charges * days) + f;
    }

    void display()
    {
        show();
        fine();
        cout << "Total No. of Days to return Book : " << days << "\nFine : " << f << "\nTotal Amount to be Paid : " << Total << "\n";
    }
};

int main()
{
    char n[100], a[100];
    int d, p;
    cout << "Enter Book Name : ";
    cin >> n;
    cout << "Enter Author Name : ";
    cin >> a;
    cout << "Enter Book Price : ";
    cin >> p;
    cout << "Enter No. of Days Taken to Return Book : ";
    cin >> d;
    compute c(n, a, p, d);
    c.display();
    return 0;
}