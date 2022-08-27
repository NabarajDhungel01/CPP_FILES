#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    while (1)
    {
        int A;
        cout << "\n\nCase : ";
        cin >> A; while (cin.fail()) { cin.clear();   cin.ignore();  }
        
        
        switch (A)
        {
        case 1:
            cout << "Entered Num is : 1\n\n";
            break;
        case 2:
            cout << "Entered Num is : 2\n\n";
            break;
        case 3:
            cout << "Entered Num is : 3\n\n";
            break;
        default:
            cout << "Invalid Choice!!!";
            break;
        }
    }
}
