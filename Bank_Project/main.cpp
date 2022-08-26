#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <windows.h>
using namespace std;

class bank
{
private:
public:
    void menu();
    void bank_management();
    void atm_management();
};
void login();
int main()
{

    bank obj;

    obj.menu();
}

void bank::menu()
{
p: // goto loop
    int choice;
    system("cls");
    cout << "\n\n\n\t\t\tControl Panel";
    cout << "\n\n 1. Bank  Management";
    cout << "\n 2. ATM Management";
    cout << "\n 3. Exit";
    cout << "\n\n Enter your choice  : ";
    cin >> choice;
    switch (choice) //login
    {
    case 1:
    /*login*/{
    system("cls");
    char ch;
    string pinn,pass,email;
    cout << "\n\n \t\t Login Account";
    cout << "\n\n E-mail  :";
    cin >> email;
                                        // cout << " \t\t"<< email;        // checking output
    cout << "\n Pin     :";
    for (int i = 0; i < 4; i++)
    {
        ch = getch();
        pinn += ch;
        cout << "*";
    }
                                        // cout <<"\t\t "<< pinn;      // checking output
    getch(); // give chance to press enter to further continue to password // otherwise enter key will be registered in pass                                        
    cout << "\nPassword     : ";
    for (int i = 0; i < 5; i++)
    {

        ch = getch();
        pass += ch;
        cout << "*";
    }
                                        // cout << "\t\t"<< pass;      // checking output

    if (email == "nabaraj.dhungeel@gmail.com" && pinn == "1234" && pass == "4321")
    {
        bank_management();
    }
    else
    {
        cout<<endl <<endl << "Incorrect Credentials !!!";
    }
    }                                                    
        break;
    case 2:
        atm_management();
        break;
    case 3:
        exit(0);

    default:
        cout << "Invalid Value.. Please try again";
        break;
    }
    getch();
    goto p; // goto loop
}

void bank::bank_management()
{
}
void bank::atm_management()
{   p: // goto loop
    int choice;
    system("cls");
    cout << "\n\n\t\t ATM Management System";
    cout << "\n\n 1. User Login & Check Balance";
    cout << "\n 2. Withrdraw Amount";
    cout << "\n 3. Account Details";
    cout << "\n 4. Go Back.";
    cout << "\n\n Enter your Choice";
    cin >> choice;
    /*Switch Choice*/{
    switch (choice)
    {
    case 1:

        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    default:
    cout << "Invalid Choice !!!";
        break;
    }
    }
    getch();
    goto p; // goto loop
}


