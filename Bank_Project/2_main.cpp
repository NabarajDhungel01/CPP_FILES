#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <windows.h>
using namespace std;

class bank
{
private:
    int pin;
    float balance;
    string id, pass, name, fname, address, phone; // fname = father name
public:
    void menu();
    void bank_management();
    void atm_management();
    void new_user();
};
void login();
int main()
{

    bank obj;

    // obj.menu();
    obj.new_user();
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
    switch (choice) // login
    {
    case 1:
        /*login*/ {
            system("cls");
            char ch;
            string pinn, pass, email;
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
            cout << "\n Password     : ";
            for (int i = 0; i < 4; i++)
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
                cout << endl
                     << endl
                     << "Incorrect Credentials !!!";
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
p: // goto loop
    int choice;
    system("cls");
    cout << "\n\n\t\t BANK Management System\n";
    cout << "\n 1.  New User";
    cout << "\n 2.  Already User";
    cout << "\n 3.  Deposit Option";
    cout << "\n 4.  Withdraw Option.";
    cout << "\n 5.  Transfer Option.";
    cout << "\n 6.  Payment Option.";
    cout << "\n 7.  Search User Record.";
    cout << "\n 8.  Edit User Record.";
    cout << "\n 9.  Delete User Record.";
    cout << "\n 10. Show All Records.";
    cout << "\n 11. Payment All Records.";
    cout << "\n 12. Go Back";
    cout << "\n\n Enter your Choice  : ";
    cin >> choice;
    /*Switch Choice*/ {
        switch (choice)
        {
        case 1:
            new_user();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            menu();
            break;
        default:
            cout << "Invalid Choice !!!";
            break;
        }
    }
    getch();
    goto p; // goto loop
}

void bank::atm_management()
{
p: // goto loop
    int choice;
    system("cls");
    cout << "\n\n\t\t ATM Management System";
    cout << "\n\n 1. User Login & Check Balance";
    cout << "\n 2. Withrdraw Amount";
    cout << "\n 3. Account Details";
    cout << "\n 4. Go Back.";
    cout << "\n\n Enter your Choice  : ";
    cin >> choice;
    /*Switch Choice*/ {
        switch (choice)
        {
        case 1:

            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            menu();
            break;
        default:
            cout << "Invalid Choice !!!";
            break;
        }
    }
    getch();
    goto p; // goto loop
}

void bank::new_user()
{
    system("cls");
    fstream file;
    int f_pin;                                                
    float f_balance;                                         
    string f_name, f_fname, f_pass, f_address, f_phone, f_id; 
    cout << "\n\n\t\t Add New User\n";
    cout << "\n 1.User ID          :";
    cin >> id;
    cout << "\n 2.Name             :";
    cin >> name;
    cout << "\n 3.Father Name      :";
    cin >> fname;
    cout << "\n 4.Address          :";
    cin >> address;
    cout << "\n 5.PIN              :";
    cin >> address;
    cout << "\n 6.Password         :";
    cin >> pin;
    cout << "\n 7.Phone No.        :";
    cin >> phone;
    cout << "\n 8.Current Balance  :";
    cin >> balance;

    file.open("benk.txt",ios::in);
    if(!file)// if there is no file
   {
    file.open("benk.txt",ios::app|ios::out);
    file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<""<<phone<<" "<<balance<<"\n";
    //NOT FOR USE WE ARE STORING THE VALUE TO non f chars// file<<" "<<f_id<<" "<<f_name<<" "<<f_fname<<" "<<f_address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
    file.close();
   }
//    else
//    {
//     //fetch data from file.
//     file>>
//    }
}







