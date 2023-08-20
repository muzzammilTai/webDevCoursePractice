#include <iostream>
using namespace std;
int main()
{
    int count = 0;
    char c;
    cout << "Input Text : ";
    // gets a string value from keyboard and assigns it to c.
    cin.get(c);
    cout << "Output text using put() funtion.\n";
    while (c != '\n')
    {
        // display a line of text character by character.
        cout << "\nCharacter : ";
        cout.put(c);

        // to count the number of characters
        count = count + 1;

        // get another character
        cin.get(c);
    }
    cout << "\nNo. of Characters : " << count << "\n";
    return 0;
}