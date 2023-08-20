#include <iostream>
#include <string.h>
using namespace std;
class MEDIA
{
protected:
    char title[100];
    float price;

public:
    MEDIA(char *s, float p)
    {
        strcpy(title, s);
        price = p;
    }
    virtual void display() {} // Empty virtual  function.
};

class BOOK : public MEDIA
{
    int numPages;

public:
    BOOK(char *s, float p, int pages) : MEDIA(s, p) // Constructor Overloading.
    {
        numPages = pages;
    }
    void display()
    {
        cout << "\nBOOK DETAILS\n";
        cout << "title : " << title << "\nno. of pages : " << numPages << "\nprice : " << price << "\n";
    }
};
class TAPE : public MEDIA
{
    float time;

public:
    TAPE(char *s, float p, int t) : MEDIA(s, p) // Constructor Overloading.
    {
        time = t;
    }
    void display()
    {
        cout << "\nTAPE DETAILS\n";
        cout << "title : " << title << "\nplay time : " << time << "\nprice : " << price << "\n";
    }
};

int main()
{
    char *title = new char[100];
    float price, time;
    int pages;

    // BOOK DETAILS
    cout << "\nEnter Book Details :\n";
    cout << "Enter the Title : ";
    cin >> title;
    cout << "Enter the Price : ";
    cin >> price;
    cout << "Enter the No. of Pages : ";
    cin >> pages;
    BOOK b(title, price, pages); // creating object for class Book.

    // TAPE DETAILS
    cout << "\nEnter Tape Details :\n";
    cout << "Enter the Title : ";
    cin >> title;
    cout << "Enter the Price : ";
    cin >> price;
    cout << "Enter the Play Time : ";
    cin >> time;
    TAPE t(title, price, time); // creating object for class Tape.

    MEDIA *list[2];
    list[0] = &b;
    list[1] = &t;

    cout << "\nMedia Details\n";
    cout << "\nBook Details\n";
    list[0]->display();
    cout << "\nTape Details\n";
    list[1]->display();
    return 0;
}