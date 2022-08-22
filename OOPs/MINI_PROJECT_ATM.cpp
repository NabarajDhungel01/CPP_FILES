/* WAP showing ATM functionalities using OOOP's
1. Check Balance
2. Cash WithDraw
3. User Details
4. Update Mobile No.    */

#include <iostream> // for IO
#include <conio.h>  // for getch()
#include <string>   // for string
using namespace std;

class atm // class atm
{
private: // private member variables
    long int account_No;
    string name;
    int PIN;
    double balance;
    string mobile_No; // we have taken mobile_No as string to avoid unnecessary complexuties so that we can only implement the OOPs concepts.

public: // public member functions
    // using the setData function to set the Data into the private member variables
    void setData(long int account_No_a, string name_a, int PIN_a, double balance_a, string mobile_No_a) // setter function
    {
        account_No = account_No_a;
        name = name_a;
        PIN = PIN_a;
        balance = balance_a;
        mobile_No = mobile_No_a;
    }

    // getAccoutNo is returning the user's account no.
    long int getAccoutnNo() { return account_No; } // getter function

    // getName
    string getName() { return name; }

    // getPin() returns the user's PIN
    int getPin() { return PIN; }

    // getBalance() is retunning the user's Bank Balance
    int getBalance() { return balance; }

    // getMobileNo() is returning the user's Mobile Number.
    string getMobileNo() { return mobile_No; }

    // setMobile function is Updating the user Mobile no
    void setMobile(string mob_prev, string mob_new)
    {
        if (mob_prev == mobile_No) // checking the database old mobile no vs user input mobile input number
        {
            mobile_No = mob_new; // if matches replace with the new mob number
            cout << endl
                 << "Successfully Updated Mobile no.";
            getch(); // hold the screen until user press any key
        }
        else
        {
            cout << endl
                 << "Incorrect !!! Old Mobile no.";
            getch(); // hold the screen
        }
    }

    void cashWithDraw(int amount_a)
    {
        if (amount_a > 0 && amount_a < balance) // check amount validity
        {
            balance -= amount_a; // reduces the balance
            cout << endl
                 << "Please Collect your Cash";
            cout << endl
                 << "Available Balance       : " << balance;
            getch();
        }
        else
        {
            cout << endl
                 << "Invalid Input or Insufficient Balance !!!! ";
            getch();
        }
    }
};

int main()
{
    int choice = 0, enterPIN = 0;
    long int enterAccountNo;
    system("cls"); // clears the screen

    // created User (object)
    atm user1;
    // set User Details ( into object )
    user1.setData(1234567, "Tim", 1111, 4500.90, "9807654321");

    do
    {

        system("cls");

        cout << endl
             << "Welcome to ATM ****" << endl;
        cout << endl
             << "Enter your account no  : ";
        cin >> enterAccountNo;

        cout << endl
             << endl
             << "Enter PIN               : ";
        cin >> enterPIN;

        // Checking the user input vs database
        if (enterAccountNo == user1.getAccoutnNo() && (enterPIN == user1.getPin()))
        {
            do
            {
                int amount = 0;
                string OldMobileNo, newMobileNo;

                system("cls");

                // User Interface
                cout << endl
                     << "**** Welcome to ATM ****" << endl
                     << endl;
                cout << endl
                     << "Select Options" << endl;
                cout << endl
                     << "1. Check Balance";
                cout << endl
                     << "2. Cash Withdraw";
                cout << endl
                     << "3.Show User Details";
                cout << endl
                     << "4.Update Mobile no.";
                cout << endl
                     << "5. Exit" << endl;

                cout << endl << endl << endl << "   Choice  : ";
                cin >> choice; // taking user input for choice

                switch (choice)
                {
                case 1:
                    system ("cls");
                    cout << "Bank Balance : " << user1.getBalance();
                    getch();
                    break;
                case 2:
                    system("cls");
                    cout << "Amount to withdraw  : ";
                    cin >> amount;
                    user1.cashWithDraw(amount);
                    break;
                case 3:
                    system("cls");
                    cout << endl << endl << endl;
                    cout << "      USER DETAILS      "<< endl << endl << endl ;
                    cout << "Account No.  : "<< user1.getAccoutnNo() << endl;
                    cout << "Name         : "<< user1.getName() << endl;
                    cout << "PIN          : "<< user1.getPin() << endl;
                    cout << "Balance      : "<< user1.getBalance() << endl;
                    cout << "Mobile No    : "<< user1.getMobileNo() << endl;

                    getch();
                    break;
                case 4:
                    cout << "Enter Old mobile no : " ;
                    cin >> OldMobileNo;
                    cout << endl<< endl << "Enter New mobile no  : ";
                    cin >> newMobileNo;
                    user1.setMobile(OldMobileNo, newMobileNo);
                break;
                case 5:
                exit(0);
                    break;

                    default:
                    cout << "Invalid Choice or Input";
                    break;
                }
                

            } while (1);
        }

    } while (1);

    return 0;
}