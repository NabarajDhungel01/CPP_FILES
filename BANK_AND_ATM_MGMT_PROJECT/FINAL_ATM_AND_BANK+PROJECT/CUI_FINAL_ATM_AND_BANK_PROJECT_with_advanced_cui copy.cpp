#include <iostream>
#include <stdio.h>  // for some C functions
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <windows.h>
#include <sstream> // for using stringstream
using namespace std;
class bank
{
private:
    string id = "\0", pass = "\0", name = "\0", fname = "\0", address = "\0", phone = "\0", pin = "\0", balance = "\0";

public:
    void menu();
    void bank_management();
    void atm_management();
    void new_user();
    void already_user(); // if the Existing user asks for the id and password
    void deposit();
    void withdraw();
    void transfer();
    void payment();
    void search();
    void edit();
    void del(); // delete user record
    void show_all_records();
    void show_all_payments();
    int user_balance();
    void withdraw_atm();
    void atm_check_details();
};
string convert_space_to_line(string input_string); // THIS FUNCTION CONVERTS THE SPACES TO UNDERSCORE for error handling and getting the name as NAME CAST and converting to NAME_CAST so that we can write to the file and when we fetch the data from the file space will cause error so,
string convert_line_to_space(string input_string); // CONVERTS UNDERSCORE TO SPACE // USED WHILE SHOWING OUTPUT
int is_space_present(string input_string);
// int is_length_correct(string input_string, int correct_length); // provide string to check if the correct number of length of string is entered.
int is_input_all_number(string input_string); // checks if all the input is the number
int is_comma_present_in_input_string(string input_string);
string Add_two_Strings(string a, string b);
string Subtract_two_Strings(string a, string b);
int convert_string_to_int(string a);
void login_screen();                     // function for login screen before accessing to the actual bank and atm management system
void introduction();                    // INTRODUCITON OF THE DEVELOPER AND .......



int main()
{
    fflush(stdin);
    // fstream file;
    // file.open("bank.csv",ios::app|ios::out);
    // cout << "Hello Test";
    // file << "Hello Test";
    // file.close();

    bank obj1;
    obj1.menu();
    // obj1.new_user();
    // obj1.deposit();
    // obj1.withdraw();
    // obj1.new_user();
    // obj1.deposit();
    // obj1.transfer();
    // obj1.payment();
    // obj1.edit();
    // obj1.new_user();
    obj1.user_balance();
}

void bank::menu()
{
    fflush(stdin);
p:
    system("cls");
    int choice;
    char ch;
    string pin, pass, email;
    cout << "\n\n\n\t\t\tControl Panel";
    cout << "\n\n 1. Bank  Management";
    cout << "\n 2. ATM Management";
    cout << "\n 3. Exit";
    cout << "\n\n Enter your choice  : ";
    cin >> choice;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
    } // if the user enters the character, this will prevent program from crashing.
    switch (choice)
    {
    case 1:
        // system("cls");
        // cout << "\n\n \t\t Login Account";
        // cout << "\n\n E-mail  :";
        // email;
        // cout << "\n Pin (5 digit)    :";
        // for (int i = 1; i <= 5; i++)
        // {
        // ch = getch();
        // pin += ch;
        // cout << "*";
        // }
        // cout << "\n Password (5 digit)    : ";
        // for (int i = 1; i <= 5; i++)
        // {
        // ch = getch();
        // pass += ch;
        // cout << "*";
        // }
        // if (email == "khizar@gmail.com" && pin == "13366" && pass == "14366")
        // {
        // bank_management();
        // }
        // else
        // {
        // cout << "\n\n Incorrect Credentials !!!";
        // }
        bank_management();
        break;
    case 2:
        atm_management();
        break;
    case 3:
        exit(0);
    default:
        cout << "Invalid Value.. Please try again";
    }
    getch();
    goto p;
}

void bank::bank_management()
{
    fflush(stdin);

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
    cout << "\n 9.  Delete User Records.";
    cout << "\n 10. Show All Records.";
    cout << "\n 11. All Payment Rec.";
    cout << "\n 12. Go Back";
    cout << "\n\n Enter your Choice  : ";
    cin >> choice;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
    } // if the user enters the character, this will prevent program from crashing.
    switch (choice)
    {
    case 1:
        new_user();
        break;
    case 2:
        already_user();
        break;
    case 3:
        deposit();
        break;
    case 4:
        withdraw();
        break;
    case 5:
        transfer();
        break;
    case 6:
        payment();
        break;
    case 7:
        search();
        break;
    case 8:
        edit();
        break;
    case 9:
        del();
        break;
    case 10:
        show_all_records();
        break;
    case 11:
        show_all_payments();
        break;
    case 12:
        menu();
    default:
        cout << "Invalid Choice !!!";
    }
    getch();
    goto p;
}

void bank::atm_management()
{
    fflush(stdin);

p:
    system("cls");
    int choice;
    cout << "\n\n\t\t ATM Management System";
    cout << "\n\n 1. User Login & Check Balance";
    cout << "\n 2. Withrdraw Amount";
    cout << "\n 3. Account Details";
    cout << "\n 4. Go Back.";
    cout << "\n\n Enter your Choice  : ";
    cin >> choice;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
    } // if the user enters the character, this will prevent program from crashing.
    switch (choice)
    {
    case 1:
        user_balance();
        break;
    case 2:
        withdraw_atm();
        break;
    case 3:
        atm_check_details();
        break;
    case 4:
        menu();
    default:
        cout << "Invalid Choice !!!";
    }
    getch();
    goto p;
}

void bank::new_user()
{
    fflush(stdin);
    int repeat = 0;
starting_of_new_user:
    system("cls");
    fflush(stdin);
    if (repeat > 0) // if the users want to add the id that is already taken
    {
        cout << "\n\n Enter Details AGAIN !!!";
        cout << "\n \"" << id << "\" ID is already taken";
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~... ASKING USER FOR THE DETAILS....~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    {
        cout << "\n\n\t\t Add New User\n";
    create_new_id: ///////////////////////////////////////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        cout << "\n 1.User ID  (max. 20 chars)        :";
        getline(cin, id);
        if (is_comma_present_in_input_string(id))
        {
            goto create_new_id;
        }
        // checking if the user has entered space in the input if the user have added the space display error message and ask for input again;
        if (is_space_present(id))
        {
            cout << "Invalid Input \t ||  Enter \"ID\"  without spaces \n ";
            goto create_new_id;
        }
        if (id.length() > 20)
        {
            cout << " Enter id length less than 20 ";
            goto create_new_id;
        }

        id = convert_space_to_line(id); // this is for error handling if the users is able to input the id with space by any chnace the space will be converted to the underscore
    create_new_name:                    ///////////////////////////////////////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        cout << "\n 2.Name             :";
        getline(cin, name);
        if (is_comma_present_in_input_string(name))
        {
            goto create_new_name;
        }
        name = convert_space_to_line(name);
    create_new_fname: ///////////////////////////////////////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        cout << "\n 3.Father Name      :";
        getline(cin, fname);
        if (is_comma_present_in_input_string(fname))
        {
            goto create_new_fname;
        }
        fname = convert_space_to_line(fname);
    create_new_address: ///////////////////////////////////////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        cout << "\n 4.Address          :";
        getline(cin, address);
        if (is_comma_present_in_input_string(address))
        {
            goto create_new_address;
        }
        address = convert_space_to_line(address);
    create_new_pin: ///////////////////////////////////////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        cout << "\n 5.PIN  (4- digits)            :";
        getline(cin, pin);
        if (is_comma_present_in_input_string(pin))
        {
            goto create_new_pin;
        }
        if (is_space_present(pin))
        {
            cout << "Invalid Input \t ||  Enter \"PIN\"  without spaces \n ";
            goto create_new_pin;
        }
        if (pin.length() != 4)
        {
            cout << "Please enter 4 digit pin \n";
            goto create_new_pin;
        }
        if (!is_input_all_number(pin))
        {
            cout << "Please enter all four numberic characters!! \n";
            goto create_new_pin;
        }

        pin = convert_space_to_line(pin);

    create_new_password: ///////////////////////////////////////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        cout << "\n 6.Password  ( 5 alphanumeric characters )       :";
        getline(cin, pass);
        if (is_comma_present_in_input_string(pass))
        {
            goto create_new_password;
        }
        if (is_space_present(pass))
        {
            cout << "Invalid Input \t ||  Enter 5 alphanumeric \"PASSWORD\"  without spaces \n ";
            goto create_new_password;
        }
        if (pass.length() != 5)
        {
            cout << "Please enter 5 digit alphanumeric  PASSOWORD \n";
            goto create_new_password;
        }
        pass = convert_space_to_line(pass);
    create_new_phone: ///////////////////////////////////////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        cout << "\n 7.Phone No.  (max.15 )      :";
        getline(cin, phone);
        if (is_comma_present_in_input_string(phone))
        {
            goto create_new_phone;
        }
        if (is_space_present(phone))
        {
            cout << "Invalid Input \t ||  Enter  \"PHONE NO. \"  without spaces \n ";
            goto create_new_phone;
        }
        if (phone.length() > 15)
        {
            cout << "Invalid Input \t ||  Enter  \"PHONE NO. \"  less than 15 numbers \n ";
            goto create_new_phone;
        }
        if (!(is_input_all_number(phone)))
        {
            cout << "Enter all numeric characters for phone number";
            goto create_new_phone;
        }
        phone = convert_space_to_line(phone);
    create_new_balance: ///////////////////////////////////////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        cout << "\n 8.Opening Balance  :";
        getline(cin, balance);
        if (is_comma_present_in_input_string(balance))
        {
            goto create_new_balance;
        }
        if (is_space_present(balance))
        {
            cout << "Invalid Input \t ||  Enter \" OPENING BALANCE\"   without spaces \n ";
            goto create_new_balance;
        }
        if (!is_input_all_number(balance))
        {
            cout << "Balance can't contain characters !! \n\t Enter balance again ... \n";
            goto create_new_balance;
        }

        if (balance.length() > 12)
        {
            cout << "Invalid Input \t ||  Enter  \"PHONE NO. \"  less than trillion ( 12 digits)  \n ";
            goto create_new_balance;
        }

        // balance = convert_space_to_line(balance);
    }

    fstream file;
    string all; // we  use this variable to get the whole line value at once ..
    file.open("bank.csv", ios::in);
    if (!file) // if there is no file simply write information to the file..
    {
        file.open("bank.csv", ios::app | ios::out);
        // printing heading  for the first time
        file << "ID"
             << ","
             << "NAME"
             << ","
             << "FATHER'S_NAME"
             << ","
             << "ADDRESS"
             << ","
             << "PIN"
             << ","
             << "PASSWORD"
             << ","
             << "CONTACT"
             << ","
             << "BALANCE"
             << ","
             << "\n";
        // priting details provided by the user
        file << id << "," << name << "," << fname << "," << address << "," << pin << "," << pass << "," << phone << "," << balance << ","
             << "\n";
        file.close();
        cout << "User Add Successful!";
    }
    else // if there is file already, we have to open the file and check if the id is repeated or not
    {

        // file.open("bank.csv",ios::out||ios::app ); we have already opened the file in input mode so no need to open again for this time
        // fetching the data from the bank.csv file
        file >> all; // this point towards the first line which is heading so lets move to the next line

        // CHECKING IF THE ID IS REPEATED OR NOT

        while (!file.eof())
        {
            // int comma_found = 0;
            int position = 1; // we are declaring this variable and setting the value to zero because,
            string csv_id = "\0", csv_name = "\0", csv_fname = "\0", csv_address = "\0", csv_phone = "\0", csv_balance = "\0", csv_pin = "\0", csv_pass = "\0";

            // storing the comma separated values to the new varibale.. for this we have to iterate through every string while the comma is found and we will incrase the position variable and comma found variable accordingly and
            // until the comma found is 0, we will store the characters to the ID variable and so on..
            for (int i = 0; i < all.length(); i++)
            {

                if (all[i] == ',')
                {
                    {
                        // cout <<  all[i]; // prints comma
                        i++;
                        // comma_found++;
                        position++; // after one comma is found the position is increased by 1.
                    }
                }
                /* THE STRIGS VALUE WILL BE ADDED TO THE RESPECTIVE POSITIONS.  */
                switch (position) //  the default value of position is 1 so while the 1st comma is not encountered the value will keep stacking on the csv_id string
                {
                case 1:
                    csv_id += all[i];
                    break;
                case 2:
                    csv_name += all[i];
                    break;
                case 3:
                    csv_fname += all[i];
                    break;
                case 4:
                    csv_address += all[i];
                    break;
                case 5:
                    csv_pin += all[i];
                    break;
                case 6:
                    csv_pass += all[i];
                    break;
                case 7:
                    csv_phone += all[i];
                    break;
                case 8:
                    csv_balance += all[i];
                    break;
                case 9: // displays the user fetched record
                        // cout<< " \n\n\n\t\t Search User Record ";
                        // cout <<"\n User ID       : "<<csv_id       ;
                        // cout <<"\n Name          : "<<csv_name     ;
                        // cout <<"\n Father's Name : "<<csv_fname    ;
                        // cout <<"\n Address       : "<<csv_address   ;
                        // cout <<"\n PIN           : "<<csv_pin      ;
                        // cout <<"\n Password      : "<<csv_pass     ;
                        // cout <<"\n Phone         : "<<csv_phone    ;
                        // cout <<"\n Balance       : "<<csv_balance  ;

                    break;
                default:
                    cout << "Default Printed : Case :: " << position; // IF SOMETHING ERROR HAPPENS.....
                    break;
                }

                if (id == csv_id && position == 9) // wait until the first comma, ie second position is encountered
                {
                    cout << "\n\nUser ID Already Exist...";
                    file.close();
                    repeat++;
                    getch();
                    /* IF ID MATCHES */ /* duplicate id found so */
                    goto starting_of_new_user;
                    /* else */
                    /* IF the ID matches then it will go to beginning */
                }
            }

            file >> all;
        }
        file.close();
        // writing the adata
        file.open("bank.csv", ios::app | ios::out);
        file << id << "," << name << "," << fname << "," << address << "," << pin << "," << pass << "," << phone << "," << balance << ","
             << "\n";
        file.close();
        cout << "User Add Successful!";
    }
}

void bank::search()
{
    fflush(stdin);
    string all;
    system("cls");
    fstream file;
    string search_id;
    int found = 0;
    cout << " \n\n\t\t Search User Record ";
    file.open("bank.csv", ios::in);
    if (!file)
    {
        cout << "File Opening Error !!!";
    }
    else
    {
    create_new_id: ///////////////////////////////////////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        cout << "\n 1.User ID    :";
        getline(cin, search_id);

        file >> all; // start from second line cz first line is heading
        while (!file.eof())
        {
            int position = 1; // we are declaring this variable and setting the value to zero because,
            string csv_id = "\0", csv_name = "\0", csv_fname = "\0", csv_address = "\0", csv_phone = "\0", csv_balance = "\0", csv_pin = "\0", csv_pass = "\0";

            // storing the comma separated values to the new varibale.. for this we have to iterate through every string while the comma is found and we will incrase the position variable and comma found variable accordingly and
            // until the comma found is 0, we will store the characters to the ID variable and so on..
            for (int i = 0; i < all.length(); i++)
            {

                if (all[i] == ',')
                {
                    {
                        // cout <<  all[i]; // prints comma
                        i++;
                        // comma_found++;
                        position++; // after one comma is found the position is increased by 1.
                    }
                }
                /* THE STRIGS VALUE WILL BE ADDED TO THE RESPECTIVE POSITIONS.  */
                switch (position) //  the default value of position is 1 so while the 1st comma is not encountered the value will keep stacking on the csv_id string
                {
                case 1:
                    csv_id += all[i];
                    break;
                case 2:
                    csv_name += all[i];
                    break;
                case 3:
                    csv_fname += all[i];
                    break;
                case 4:
                    csv_address += all[i];
                    break;
                case 5:
                    csv_pin += all[i];
                    break;
                case 6:
                    csv_pass += all[i];
                    break;
                case 7:
                    csv_phone += all[i];
                    break;
                case 8:
                    csv_balance += all[i];
                    break;
                case 9: // displays the user fetched record
                        // cout<< " \n\n\n\t\t Search User Record ";
                        // cout <<"\n User ID       : "<<csv_id       ;
                        // cout <<"\n Name          : "<<csv_name     ;
                        // cout <<"\n Father's Name : "<<csv_fname    ;
                        // cout <<"\n Address       : "<<csv_address   ;
                        // cout <<"\n PIN           : "<<csv_pin      ;
                        // cout <<"\n Password      : "<<csv_pass     ;
                        // cout <<"\n Phone         : "<<csv_phone    ;
                        // cout <<"\n Balance       : "<<csv_balance  ;

                    break;
                default:
                    cout << "Default Printed : Case :: " << position; // IF SOMETHING ERROR HAPPENS.....
                    break;
                }

                if (search_id == csv_id && position == 9) // wait until the first comma, ie second position is encountered
                {
                    system("cls");
                    cout << " \n\n\n\t\t Search User Record \n\n ";
                    cout << "\n User ID       : " << convert_line_to_space(csv_id);
                    cout << "\n Name          : " << convert_line_to_space(csv_name);
                    cout << "\n Father's Name : " << convert_line_to_space(csv_fname);
                    cout << "\n Address       : " << convert_line_to_space(csv_address);
                    cout << "\n Phone         : " << convert_line_to_space(csv_phone);
                    cout << "\n Balance       : " << convert_line_to_space(csv_balance);
                    cout << "\n PIN           : " << convert_line_to_space(csv_pin);
                    cout << "\n Password      : " << convert_line_to_space(csv_pass);
                    found++;
                }
            }

            file >> all;
        }
        // file >> all;
    }
    file.close();

    if (found == 0)
    {
        cout << "\n\n User ID Can't Found...";
    }
}

void bank::already_user() // if the Existing user asks for the id and password
{
    fflush(stdin);
    system("cls");
    string all;
    fstream file;
    string search_id;
    int found = 0;
    cout << "\n\n\n \t\t Already User Account";
    file.open("bank.csv", ios::in);
    if (!file)
    {
        cout << "\n\n\n\t\tFile Opening Error!!!!\n\n";
    }
    else
    {
        cout << "\n\n \t\t  User ID : ";

    create_new_id: ///////////////////////////////////////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        cout << "\n 1.User ID    :";
        getline(cin, search_id);

        file >> all; // start from second line cz first line is heading
        while (!file.eof())
        {
            int position = 1; // we are declaring this variable and setting the value to zero because,
            string csv_id = "\0", csv_name = "\0", csv_fname = "\0", csv_address = "\0", csv_phone = "\0", csv_balance = "\0", csv_pin = "\0", csv_pass = "\0";

            // storing the comma separated values to the new varibale.. for this we have to iterate through every string while the comma is found and we will incrase the position variable and comma found variable accordingly and
            // until the comma found is 0, we will store the characters to the ID variable and so on..
            for (int i = 0; i < all.length(); i++)
            {

                if (all[i] == ',')
                {
                    {
                        // cout <<  all[i]; // prints comma
                        i++;
                        // comma_found++;
                        position++; // after one comma is found the position is increased by 1.
                    }
                }
                /* THE STRIGS VALUE WILL BE ADDED TO THE RESPECTIVE POSITIONS.  */
                switch (position) //  the default value of position is 1 so while the 1st comma is not encountered the value will keep stacking on the csv_id string
                {
                case 1:
                    csv_id += all[i];
                    break;
                case 2:
                    csv_name += all[i];
                    break;
                case 3:
                    csv_fname += all[i];
                    break;
                case 4:
                    csv_address += all[i];
                    break;
                case 5:
                    csv_pin += all[i];
                    break;
                case 6:
                    csv_pass += all[i];
                    break;
                case 7:
                    csv_phone += all[i];
                    break;
                case 8:
                    csv_balance += all[i];
                    break;
                case 9: // displays the user fetched record
                        // cout<< " \n\n\n\t\t Search User Record ";
                        // cout <<"\n User ID       : "<<csv_id       ;
                        // cout <<"\n Name          : "<<csv_name     ;
                        // cout <<"\n Father's Name : "<<csv_fname    ;
                        // cout <<"\n Address       : "<<csv_address   ;
                        // cout <<"\n PIN           : "<<csv_pin      ;
                        // cout <<"\n Password      : "<<csv_pass     ;
                        // cout <<"\n Phone         : "<<csv_phone    ;
                        // cout <<"\n Balance       : "<<csv_balance  ;

                    break;
                default:
                    cout << "Default Printed : Case :: " << position; // IF SOMETHING ERROR HAPPENS.....
                    break;
                }

                if (search_id == csv_id && position == 9) // wait until the first comma, ie second position is encountered
                {
                    system("cls");
                    cout << "\n\n\n \t\t Already User Account\n\n";
                    cout << "\n\n\tPin Code : " << csv_pin << "\n\n\tPassword : " << csv_pass;
                    found++;
                }
            }

            file >> all;
        }
    } 

    if (found == 0)
    {
        cout << "\n\n User ID Can't Found...";
    }
}

void bank::deposit()
{
    fflush(stdin);
    string all;
    fstream file, temp_file;
    string test_id;
    string amount; // amt to be deposited
    int found = 0;
    system("cls");
    cout << "\n\n\n\t\t Deposit Amount Option";
    file.open("bank.csv", ios::in);
    if (!file)
    {
        cout << "\n\n\n\t\t File Opening Error !!!";
    }
    else
    {
        cout << "\n\n \t\t  User ID : ";
        // cin >> test_id;
        getline(cin, test_id);
        temp_file.open("temp_bank.csv", ios::app | ios::out);
        file >> all;
        while (!file.eof())
        {                     // int comma_found = 0;
            int position = 1; // we are declaring this variable and setting the value to zero because,
            string csv_id = "\0", csv_name = "\0", csv_fname = "\0", csv_address = "\0", csv_phone = "\0", csv_balance = "\0", csv_pin = "\0", csv_pass = "\0";

            // storing the comma separated values to the new varibale.. for this we have to iterate through every string while the comma is found and we will incrase the position variable and comma found variable accordingly and
            // until the comma found is 0, we will store the characters to the ID variable and so on..
            for (int i = 0; i < all.length(); i++)
            {

                if (all[i] == ',')
                {
                    {
                        // cout <<  all[i]; // prints comma
                        i++;
                        // comma_found++;
                        position++; // after one comma is found the position is increased by 1.
                    }
                }
                /* THE STRIGS VALUE WILL BE ADDED TO THE RESPECTIVE POSITIONS.  */
                switch (position) //  the default value of position is 1 so while the 1st comma is not encountered the value will keep stacking on the csv_id string
                {
                case 1:
                    csv_id += all[i];
                    break;
                case 2:
                    csv_name += all[i];
                    break;
                case 3:
                    csv_fname += all[i];
                    break;
                case 4:
                    csv_address += all[i];
                    break;
                case 5:
                    csv_pin += all[i];
                    break;
                case 6:
                    csv_pass += all[i];
                    break;
                case 7:
                    csv_phone += all[i];
                    break;
                case 8:
                    csv_balance += all[i];
                    break;
                case 9:

                    break;
                default:
                    cout << "Default Printed : Case :: " << position; // IF SOMETHING ERROR HAPPENS.....
                    break;
                }
                if (position == 9) // this checks if all the data are fetched and  stored into the right variable.
                {

                    if (test_id == csv_id)
                    {
                    create_new_amount:
                        cout << "Amount For Deposit  : ";
                        // cin >> amount;
                        getline(cin, amount);
                        if (is_comma_present_in_input_string(amount))
                        {
                            goto create_new_amount;
                        }
                        if (is_space_present(amount))
                        {
                            cout << "Invalid Input \t ||  Enter \" OPENING amount\"   without spaces \n ";
                            goto create_new_amount;
                        }

                        if (!is_input_all_number(amount))
                        {
                            cout << "amount can't contain characters !! \n\t Enter amount again ... \n";
                            goto create_new_amount;
                        }

                        if (amount.length() > 12)
                        {
                            cout << "Invalid Input \t ||  Enter  \"PHONE NO. \"  less than trillion ( 12 digits)  \n ";
                            goto create_new_amount;
                        }

                        // adding strings as integer
                        csv_balance = to_string(stoi(amount) + stoi(csv_balance));
                        // csv_balance += amount; // updated amount

                        temp_file << csv_id << "," << csv_name << "," << csv_fname << "," << csv_address << "," << csv_pin << "," << csv_pass << "," << csv_phone << "," << csv_balance << ","
                                  << "\n";
                        found++;
                        cout << " Amount Rs." << amount << "|- Deposit Successful!!";
                    }
                    else
                    {
                        temp_file << csv_id << "," << csv_name << "," << csv_fname << "," << csv_address << "," << csv_pin << "," << csv_pass << "," << csv_phone << "," << csv_balance << ","
                                  << "\n";
                    }
                }
            }
            file >> all;
        }
        file.close();
        temp_file.close();
        // getch();
        remove("bank.csv");
        rename("temp_bank.csv", "bank.csv");
        if (found == 0)
        {
            cout << "\n\n User ID Can't Found...";
        }
    }
}

void bank::withdraw()
{
    fflush(stdin);
    string all;
    fstream file, temp_file;
    string test_id;
    string amount; // amt to be deposited
    int found = 0;
    system("cls");
    cout << "\n\n\n\t\t Withdraw Amount Option";
    file.open("bank.csv", ios::in);
    if (!file)
    {
        cout << "\n\n\n\t\t File Opening Error !!!";
    }
    else
    {
        cout << "\n\n \t\t  User ID : ";
        // cin >> test_id;
        getline(cin, test_id);
        temp_file.open("temp_bank.csv", ios::app | ios::out);
        file >> all;
        while (!file.eof())
        {                     // int comma_found = 0;
            int position = 1; // we are declaring this variable and setting the value to zero because,
            string csv_id = "\0", csv_name = "\0", csv_fname = "\0", csv_address = "\0", csv_phone = "\0", csv_balance = "\0", csv_pin = "\0", csv_pass = "\0";

            // storing the comma separated values to the new varibale.. for this we have to iterate through every string while the comma is found and we will incrase the position variable and comma found variable accordingly and
            // until the comma found is 0, we will store the characters to the ID variable and so on..
            for (int i = 0; i < all.length(); i++)
            {
                if (all[i] == ',')
                {
                    {
                        // cout <<  all[i]; // prints comma
                        i++;
                        // comma_found++;
                        position++; // after one comma is found the position is increased by 1.
                    }
                }
                /* THE STRIGS VALUE WILL BE ADDED TO THE RESPECTIVE POSITIONS.  */
                switch (position) //  the default value of position is 1 so while the 1st comma is not encountered the value will keep stacking on the csv_id string
                {
                case 1:
                    csv_id += all[i];
                    break;
                case 2:
                    csv_name += all[i];
                    break;
                case 3:
                    csv_fname += all[i];
                    break;
                case 4:
                    csv_address += all[i];
                    break;
                case 5:
                    csv_pin += all[i];
                    break;
                case 6:
                    csv_pass += all[i];
                    break;
                case 7:
                    csv_phone += all[i];
                    break;
                case 8:
                    csv_balance += all[i];
                    break;
                case 9:

                    break;
                default:
                    cout << "Default Printed : Case :: " << position; // IF SOMETHING ERROR HAPPENS.....
                    break;
                }
                if (position == 9) // this checks if all the data are fetched and  stored into the right variable.
                {
                    if (test_id == csv_id)
                    {
                    create_new_amount:
                        cout << "Amount For Withdraw  : ";
                        // cin >> amount;
                        getline(cin, amount);
                        if (is_comma_present_in_input_string(amount))
                        {
                            goto create_new_amount;
                        }
                        if (is_space_present(amount))
                        {
                            cout << "Invalid Input \t ||  Enter \" OPENING amount\"   without spaces \n ";
                            goto create_new_amount;
                        }

                        if (!is_input_all_number(amount))
                        {
                            cout << "amount can't contain characters !! \n\t Enter amount again ... \n";
                            goto create_new_amount;
                        }

                        if (amount.length() > 12)
                        {
                            cout << "Invalid Input \t ||  Enter  \"PHONE NO. \"  less than trillion ( 12 digits)  \n ";
                            goto create_new_amount;
                        }
                        if (stoi(amount) < stoi(csv_balance)) // checks if the proper amt is present
                        {
                            // adding strings as integer
                            csv_balance = to_string(stoi(csv_balance) - stoi(amount));
                            // csv_balance += amount; // updated amount

                            temp_file << csv_id << "," << csv_name << "," << csv_fname << "," << csv_address << "," << csv_pin << "," << csv_pass << "," << csv_phone << "," << csv_balance << ","
                                      << "\n";
                            cout << " Amount Rs." << amount << "|- Withdraw Successful!!";
                        }
                        else
                        {
                            cout << "ERROR !!!!! Insufficient Balance !";
                            temp_file << csv_id << "," << csv_name << "," << csv_fname << "," << csv_address << "," << csv_pin << "," << csv_pass << "," << csv_phone << "," << csv_balance << ","
                                      << "\n";
                        }
                        found++;
                    }
                    else
                    {
                        temp_file << csv_id << "," << csv_name << "," << csv_fname << "," << csv_address << "," << csv_pin << "," << csv_pass << "," << csv_phone << "," << csv_balance << ","
                                  << "\n";
                    }
                }
            }
            file >> all;
        }
        file.close();
        temp_file.close();
        // getch();
        remove("bank.csv");
        rename("temp_bank.csv", "bank.csv");
        if (found == 0)
        {
            cout << "\n\n User ID Can't Found...";
        }
    }
}

void bank::transfer()
{
    fflush(stdin);
    fstream file, temp_file;
    system("cls");
    string sender_id, receiver_id;
    int found = 0, sender_found = 0, receiver_found = 0;
    string transfer_amount;
    cout << "\n\n\n\t\t\t Payment Transfer Option";
    file.open("bank.csv", ios::in);
    string all;
    if (!file)
    {
        cout << "\n\n\n\t\t File Opening Error !!!";
    }
    else
    {

        cout << "\n\n Sender User ID   : "; /// TRY TO UTILIZE THE DEPOSIT AND WITHDRAWL FUNCTIONS MAKES MORE COMPLEX
        cin >> sender_id;
        fflush(stdin);
        cout << "\n\n Receiver User ID : ";
        cin >> receiver_id;
        fflush(stdin);

    create_new_transfer_amount:
        cout << "\n\n Transfer Amount  : ";
        getline(cin, transfer_amount);
        fflush(stdin);
        if (is_comma_present_in_input_string(transfer_amount))
        {
            goto create_new_transfer_amount;
        }
        if (is_space_present(transfer_amount))
        {
            cout << "Invalid Input \t ||  Enter \" OPENING transfer_amount\"   without spaces \n ";
            goto create_new_transfer_amount;
        }

        if (!is_input_all_number(transfer_amount))
        {
            cout << "transfer_amount can't contain characters !! \n\t Enter transfer_amount again ... \n";
            goto create_new_transfer_amount;
        }

        if (transfer_amount.length() > 12)
        {
            cout << "Invalid Input \t ||  Enter  \"PHONE NO. \"  less than trillion ( 12 digits)  \n ";
            goto create_new_transfer_amount;
        }

        file >> all;
        while (!file.eof())   // Checking if both sender and receiver exists or not and if the sender has the sufficient balance or not
        {                     /*if(sender_id == id && transfer_amount > balance){ cout << "Insufficient Balnce In Sender's Account"; getch(); goto beginning;}*/
            int position = 1; // we are declaring this variable and setting the value to zero because,
            string csv_id = "\0", csv_name = "\0", csv_fname = "\0", csv_address = "\0", csv_phone = "\0", csv_balance = "\0", csv_pin = "\0", csv_pass = "\0";

            // storing the comma separated values to the new varibale.. for this we have to iterate through every string while the comma is found and we will incrase the position variable and comma found variable accordingly and
            // until the comma found is 0, we will store the characters to the ID variable and so on..
            for (int i = 0; i < all.length(); i++)
            {

                if (all[i] == ',')
                {
                    {
                        // cout <<  all[i]; // prints comma
                        i++;
                        // comma_found++;
                        position++; // after one comma is found the position is increased by 1.
                    }
                }
                /* THE STRIGS VALUE WILL BE ADDED TO THE RESPECTIVE POSITIONS.  */
                switch (position) //  the default value of position is 1 so while the 1st comma is not encountered the value will keep stacking on the csv_id string
                {
                case 1:
                    csv_id += all[i];
                    break;
                case 2:
                    csv_name += all[i];
                    break;
                case 3:
                    csv_fname += all[i];
                    break;
                case 4:
                    csv_address += all[i];
                    break;
                case 5:
                    csv_pin += all[i];
                    break;
                case 6:
                    csv_pass += all[i];
                    break;
                case 7:
                    csv_phone += all[i];
                    break;
                case 8:
                    csv_balance += all[i];
                    break;
                case 9:

                    break;
                default:
                    cout << "Default Printed : Case :: " << position; // IF SOMETHING ERROR HAPPENS.....
                    break;
                }
                if (position == 9)
                {
                    // Converting transfer_amount and csv_balance into integer value and then comparing
                    int temp_int_transfer_amount = 0;
                    int temp_int_csv_balance = 0;
                    temp_int_transfer_amount = convert_string_to_int(transfer_amount);
                    temp_int_csv_balance = convert_string_to_int(csv_balance);

                    // if (sender_id == csv_id && transfer_amount <= csv_balance)
                    if (sender_id == csv_id && temp_int_transfer_amount < temp_int_csv_balance)
                        found++, sender_found++;
                    else if (sender_id == csv_id && transfer_amount >= csv_balance) // if the user wants to transfer the same amount or higher than balance
                    {
                        cout << "\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!                    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
                        cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!INSUFFICIENT BALANCE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
                        cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!                    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n";
                    }
                    else if (receiver_id == csv_id)
                        found++, receiver_found++;

                    // if (sender_id == csv_id && temp_int_transfer_amount <= temp_int_csv_balance)
                    // found++, sender_found++;
                    // else if (receiver_id == csv_id)
                    // found++, receiver_found++;
                }
            }
            file >> all;
        }
        // cout << " Found = : " << found;
        cout << "\n\n\n 1- found\n 0- not found";
        cout << "\n Sender Validation state :  " << sender_found;
        cout << "\n Receiver Validation state : " << receiver_found << "\n\n";

        file.close();
        if (found == 2) // if(found == 2 )
        {
            file.open("bank.csv", ios::in);
            temp_file.open("temp_bank.csv", ios::app | ios::out);
            file >> all;
            while (!file.eof())
            {                     /*if(sender_id == id && transfer_amount > balance){ cout << "Insufficient Balnce In Sender's Account"; getch(); goto beginning;}*/
                int position = 1; // we are declaring this variable and setting the value to zero because,
                string csv_id = "\0", csv_name = "\0", csv_fname = "\0", csv_address = "\0", csv_phone = "\0", csv_balance = "\0", csv_pin = "\0", csv_pass = "\0";

                // storing the comma separated values to the new varibale.. for this we have to iterate through every string while the comma is found and we will incrase the position variable and comma found variable accordingly and
                // until the comma found is 0, we will store the characters to the ID variable and so on..
                for (int i = 0; i < all.length(); i++)
                {

                    if (all[i] == ',')
                    {
                        {
                            // cout <<  all[i]; // prints comma
                            i++;
                            // comma_found++;
                            position++; // after one comma is found the position is increased by 1.
                        }
                    }
                    /* THE STRIGS VALUE WILL BE ADDED TO THE RESPECTIVE POSITIONS.  */
                    switch (position) //  the default value of position is 1 so while the 1st comma is not encountered the value will keep stacking on the csv_id string
                    {
                    case 1:
                        csv_id += all[i];
                        break;
                    case 2:
                        csv_name += all[i];
                        break;
                    case 3:
                        csv_fname += all[i];
                        break;
                    case 4:
                        csv_address += all[i];
                        break;
                    case 5:
                        csv_pin += all[i];
                        break;
                    case 6:
                        csv_pass += all[i];
                        break;
                    case 7:
                        csv_phone += all[i];
                        break;
                    case 8:
                        csv_balance += all[i];
                        break;
                    case 9:

                        break;
                    default:
                        cout << "Default Printed : Case :: " << position; // IF SOMETHING ERROR HAPPENS.....
                        break;
                    }
                    if (position == 9)
                    {
                        if (sender_id == csv_id)
                        { /*  cout << "line 1012";                */
                            // csv_balance = to_string(stoi(csv_balance) - stoi(transfer_amount));
                            // csv_balance = to_string(stoi(csv_balance) - stoi(transfer_amount));
                            csv_balance = Subtract_two_Strings(csv_balance, transfer_amount);
                            temp_file << csv_id << "," << csv_name << "," << csv_fname << "," << csv_address << "," << csv_pin << "," << csv_pass << "," << csv_phone << "," << csv_balance << ","
                                      << "\n";
                        }
                        else if (receiver_id == csv_id)
                        { /* cout << "line 1017";     */
                            // csv_balance = to_string(stoi(csv_balance) + stoi(transfer_amount));
                            // csv_balance = to_string(stoi(transfer_amount) + stoi(csv_balance));
                            csv_balance = Add_two_Strings(csv_balance, transfer_amount);
                            temp_file << csv_id << "," << csv_name << "," << csv_fname << "," << csv_address << "," << csv_pin << "," << csv_pass << "," << csv_phone << "," << csv_balance << ","
                                      << "\n";
                        }
                        else
                        { /* cout << "line 10122"; */
                            temp_file << csv_id << "," << csv_name << "," << csv_fname << "," << csv_address << "," << csv_pin << "," << csv_pass << "," << csv_phone << "," << csv_balance << ","
                                      << "\n";
                        }
                    }
                }
                file >> all;
            }
            file.close();
            temp_file.close();
            remove("bank.csv");
            rename("temp_bank.csv", "bank.csv");
            cout << "\n\n\n Transaction Successful!!";
            getch();
        }
        else if (found == 0)
        {
            cout << "Sender and Receiver ID Invalid!!!";
            getch();
        }
        if (found == 1)
        {
            if (sender_found = 1)
            {
                cout << " Sender ID or AMOUNT Invalid!!";
            }
            else if (receiver_found = 1)
            {
                cout << " Receiver ID Invalid!!";
            }
        }
    }
}

void bank::payment()
{
    fflush(stdin);
    system("cls");
    fstream file, temp_file, bill_file;
    int found = 0, insufficient_balance = 0;
    string bill_id, bill_name;
    string bill_amount;
    SYSTEMTIME x;
    cout << "\n\n\t\t Bills Payment Option.";
    file.open("bank.csv", ios::in);
    string all;
    if (!file)
    {
        cout << "\n\n\n\t\t File Opening Error!!!!\n\n";
    }
    else
    // again:
    create_new_id:
        cout << "\n\n   User ID : ";
    getline(cin, bill_id);

create_new_billname:
    cout << "\n\n Bill Name : ";
    getline(cin, bill_name);
    if (is_comma_present_in_input_string(bill_name))
    {
        goto create_new_billname;
    }
    bill_name = convert_space_to_line(bill_name);
    cout << "\n\n Bill Amount : ";
    cin >> bill_amount;
    temp_file.open("temp_bank.csv", ios::app | ios::out);
    file >> all;
    while (!file.eof())
    {
        int position = 1; // we are declaring this variable and setting the value to zero because,
        string csv_id = "\0", csv_name = "\0", csv_fname = "\0", csv_address = "\0", csv_phone = "\0", csv_balance = "\0", csv_pin = "\0", csv_pass = "\0";

        // storing the comma separated values to the new varibale.. for this we have to iterate through every string while the comma is found and we will incrase the position variable and comma found variable accordingly and
        // until the comma found is 0, we will store the characters to the ID variable and so on..
        for (int i = 0; i < all.length(); i++)
        {
            if (all[i] == ',')
            {
                {
                    // cout <<  all[i]; // prints comma
                    i++;
                    // comma_found++;
                    position++; // after one comma is found the position is increased by 1.
                }
            }
            /* THE STRIGS VALUE WILL BE ADDED TO THE RESPECTIVE POSITIONS.  */
            switch (position) //  the default value of position is 1 so while the 1st comma is not encountered the value will keep stacking on the csv_id string
            {
            case 1:
                csv_id += all[i];
                break;
            case 2:
                csv_name += all[i];
                break;
            case 3:
                csv_fname += all[i];
                break;
            case 4:
                csv_address += all[i];
                break;
            case 5:
                csv_pin += all[i];
                break;
            case 6:
                csv_pass += all[i];
                break;
            case 7:
                csv_phone += all[i];
                break;
            case 8:
                csv_balance += all[i];
                break;
            case 9:

                break;
            default:
                cout << "Default Printed : Case :: " << position; // IF SOMETHING ERROR HAPPENS.....
                break;
            }
            if (position == 9) // this checks if all the data are fetched and  stored into the right variable.
            {
                // Converting transfer_amount and csv_balance into integer value and then comparing
                int temp_int_bill_amount = 0;
                int temp_int_csv_balance = 0;
                temp_int_bill_amount = convert_string_to_int(bill_amount);
                temp_int_csv_balance = convert_string_to_int(csv_balance);

                if (bill_id == csv_id && temp_int_bill_amount > temp_int_csv_balance)
                {
                    insufficient_balance = 1;
                    temp_file << csv_id << "," << csv_name << "," << csv_fname << "," << csv_address << "," << csv_pin << "," << csv_pass << "," << csv_phone << "," << csv_balance << ","
                              << "\n";
                }
                else if (bill_id == csv_id && temp_int_bill_amount < temp_int_csv_balance) // SUCCESSSFULLLLLL
                {

                    // adding strings as integer
                    csv_balance = to_string(stoi(csv_balance) - stoi(bill_amount));
                    // csv_balance += amount; // updated amount

                    temp_file << csv_id << "," << csv_name << "," << csv_fname << "," << csv_address << "," << csv_pin << "," << csv_pass << "," << csv_phone << "," << csv_balance << ","
                              << "\n";
                    found++;
                }
                else
                {
                    temp_file << csv_id << "," << csv_name << "," << csv_fname << "," << csv_address << "," << csv_pin << "," << csv_pass << "," << csv_phone << "," << csv_balance << ","
                              << "\n";
                }
            }
        }
        file >> all;
    }

    file.close();
    temp_file.close();
    remove("bank.csv");
    rename("temp_bank.csv", "bank.csv");
    if (found == 1)
    {
        GetSystemTime(&x);
        bill_file.open("Bills.txt", ios::app | ios::out);
        bill_file << bill_id << " " << bill_name << " " << bill_amount << " " << x.wDay << "/" << x.wMonth << "/" << x.wYear << "\n";
        bill_file.close();
        cout << " \n\n \t\t" << bill_name << "  Bill Pay Successfully ";
    }
    else if (found == 0 && insufficient_balance == 0)
    {
        cout << " \n\n User ID Invalid OR Insufficient Balance !!!";
    }
    else if (insufficient_balance == 1)
    {
        cout << "\n\n Insufficient Balance in " << name << "'s Account";
    }
}

void bank::edit()
{
    fflush(stdin);
    {
        system("cls");
        string all;
        fstream file, temp_file;
        string test_id, new_name, new_fname, new_pass, new_address, new_phone /*,id*/;
        string new_pin;
        int found = 0;
        cout << "\n\n\t\t Edit User Record.";
        file.open("bank.csv", ios::in);
        if (!file)
        {
            cout << "File Opening Error!!";
        }
        else
        {

            temp_file.open("temp_bank.csv", ios::app | ios::out);
            cout << "\n\nUser ID : ";
            cin >> test_id;
            fflush(stdin);
            file >> all;
            system("cls");
            while (!file.eof())
            {
                int position = 1; // we are declaring this variable and setting the value to zero because,
                string csv_id = "\0", csv_name = "\0", csv_fname = "\0", csv_address = "\0", csv_phone = "\0", csv_balance = "\0", csv_pin = "\0", csv_pass = "\0";

                // storing the comma separated values to the new varibale.. for this we have to iterate through every string while the comma is found and we will incrase the position variable and comma found variable accordingly and
                // until the comma found is 0, we will store the characters to the ID variable and so on..
                for (int i = 0; i < all.length(); i++)
                {

                    if (all[i] == ',')
                    {
                        {
                            // cout <<  all[i]; // prints comma
                            i++;
                            // comma_found++;
                            position++; // after one comma is found the position is increased by 1.
                        }
                    }
                    /* THE STRIGS VALUE WILL BE ADDED TO THE RESPECTIVE POSITIONS.  */
                    switch (position) //  the default value of position is 1 so while the 1st comma is not encountered the value will keep stacking on the csv_id string
                    {
                    case 1:
                        csv_id += all[i];
                        break;
                    case 2:
                        csv_name += all[i];
                        break;
                    case 3:
                        csv_fname += all[i];
                        break;
                    case 4:
                        csv_address += all[i];
                        break;
                    case 5:
                        csv_pin += all[i];
                        break;
                    case 6:
                        csv_pass += all[i];
                        break;
                    case 7:
                        csv_phone += all[i];
                        break;
                    case 8:
                        csv_balance += all[i];
                        break;
                    case 9: // displays the user fetched record
                            // cout<< " \n\n\n\t\t Search User Record ";
                            // cout <<"\n User ID       : "<<csv_id       ;
                            // cout <<"\n Name          : "<<csv_name     ;
                            // cout <<"\n Father's Name : "<<csv_fname    ;
                            // cout <<"\n Address       : "<<csv_address   ;
                            // cout <<"\n PIN           : "<<csv_pin      ;
                            // cout <<"\n Password      : "<<csv_pass     ;
                            // cout <<"\n Phone         : "<<csv_phone    ;
                            // cout <<"\n Balance       : "<<csv_balance  ;

                        break;
                    default:
                        cout << "Default Printed : Case :: " << position; // IF SOMETHING ERROR HAPPENS.....
                        break;
                    }

                    // ASKS FOR THE details to be edited
                    if (test_id == csv_id && position == 9) // wait until the first comma, ie second position is encountered
                    {
                        cout << "\n\t\t\t Edit User Details \n\n";

                        {
                            {
                            create_new_name: ///////////////////////////////////////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                                cout << "\n 2.Name             :";
                                getline(cin, name);
                                fflush(stdin);
                                if (is_comma_present_in_input_string(name))
                                {
                                    goto create_new_name;
                                }
                                name = convert_space_to_line(name);
                            create_new_fname: ///////////////////////////////////////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                                cout << "\n 3.Father Name      :";
                                getline(cin, fname);
                                fflush(stdin);
                                if (is_comma_present_in_input_string(fname))
                                {
                                    goto create_new_fname;
                                }
                                fname = convert_space_to_line(fname);
                            create_new_address: ///////////////////////////////////////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                                cout << "\n 4.Address          :";
                                getline(cin, address);
                                fflush(stdin);
                                if (is_comma_present_in_input_string(address))
                                {
                                    goto create_new_address;
                                }
                                address = convert_space_to_line(address);
                            create_new_pin: ///////////////////////////////////////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                                cout << "\n 5.PIN  (4- digits)            :";
                                getline(cin, pin);
                                fflush(stdin);
                                if (is_comma_present_in_input_string(pin))
                                {
                                    goto create_new_pin;
                                }
                                if (is_space_present(pin))
                                {
                                    cout << "Invalid Input \t ||  Enter \"PIN\"  without spaces \n ";
                                    goto create_new_pin;
                                }
                                if (pin.length() != 4)
                                {
                                    cout << "Please enter 4 digit pin \n";
                                    goto create_new_pin;
                                }
                                if (!is_input_all_number(pin))
                                {
                                    cout << "Please enter all four numberic characters!! \n";
                                    goto create_new_pin;
                                }

                                pin = convert_space_to_line(pin);

                            create_new_password: ///////////////////////////////////////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                                cout << "\n 6.Password  ( 5 alphanumeric characters )       :";
                                getline(cin, pass);
                                fflush(stdin);
                                if (is_comma_present_in_input_string(pass))
                                {
                                    goto create_new_password;
                                }
                                if (is_space_present(pass))
                                {
                                    cout << "Invalid Input \t ||  Enter 5 alphanumeric \"PASSWORD\"  without spaces \n ";
                                    goto create_new_password;
                                }
                                if (pass.length() != 5)
                                {
                                    cout << "Please enter 5 digit alphanumeric  PASSOWORD \n";
                                    goto create_new_password;
                                }
                                pass = convert_space_to_line(pass);
                            create_new_phone: ///////////////////////////////////////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                                cout << "\n 7.Phone No.  (max.15 )      :";
                                getline(cin, phone);
                                fflush(stdin);
                                if (is_comma_present_in_input_string(phone))
                                {
                                    goto create_new_phone;
                                }
                                if (is_space_present(phone))
                                {
                                    cout << "Invalid Input \t ||  Enter  \"PHONE NO. \"  without spaces \n ";
                                    goto create_new_phone;
                                }
                                if (phone.length() > 15)
                                {
                                    cout << "Invalid Input \t ||  Enter  \"PHONE NO. \"  less than 15 numbers \n ";
                                    goto create_new_phone;
                                }
                                if (!(is_input_all_number(phone)))
                                {
                                    cout << "Enter all numeric characters for phone number";
                                    goto create_new_phone;
                                }
                                phone = convert_space_to_line(phone);
                            }
                            fflush(stdin);
                        }

                        temp_file << csv_id << "," << name << "," << fname << "," << address << "," << pin << "," << pass << "," << phone << "," << csv_balance << ","
                                  << "\n";
                        found++;
                    }
                    else if (test_id != csv_id && position == 9) // if the user id doesnt match after the scan  then print like this;
                    {
                        temp_file << csv_id << "," << csv_name << "," << csv_fname << "," << csv_address << "," << csv_pin << "," << csv_pass << "," << csv_phone << "," << csv_balance << ","
                                  << "\n";
                    }
                }
                file >> all;
            }
            file.close();
            temp_file.close();
            remove("bank.csv");
            rename("temp_bank.csv", "bank.csv");
            if (found == 0)
            {
                cout << "\n\n User ID Can't Found...";
            }
        }
    }
}

void bank::del()
{

    fflush(stdin);
    {
        system("cls");
        string all;
        fstream file, temp_file;
        string test_id, new_name, new_fname, new_pass, new_address, new_phone /*,id*/;
        string new_pin;
        int found = 0;
        cout << "\n\n\t\t Delete User Record.";
        file.open("bank.csv", ios::in);
        if (!file)
        {
            cout << "File Opening Error!!";
        }
        else
        {

            temp_file.open("temp_bank.csv", ios::app | ios::out);
            cout << "\n\nUser ID : ";
            cin >> test_id;
            fflush(stdin);
            file >> all;
            system("cls");
            while (!file.eof())
            {
                int position = 1; // we are declaring this variable and setting the value to zero because,
                string csv_id = "\0", csv_name = "\0", csv_fname = "\0", csv_address = "\0", csv_phone = "\0", csv_balance = "\0", csv_pin = "\0", csv_pass = "\0";

                // storing the comma separated values to the new varibale.. for this we have to iterate through every string while the comma is found and we will incrase the position variable and comma found variable accordingly and
                // until the comma found is 0, we will store the characters to the ID variable and so on..
                for (int i = 0; i < all.length(); i++)
                {

                    if (all[i] == ',')
                    {
                        {
                            // cout <<  all[i]; // prints comma
                            i++;
                            // comma_found++;
                            position++; // after one comma is found the position is increased by 1.
                        }
                    }
                    /* THE STRIGS VALUE WILL BE ADDED TO THE RESPECTIVE POSITIONS.  */
                    switch (position) //  the default value of position is 1 so while the 1st comma is not encountered the value will keep stacking on the csv_id string
                    {
                    case 1:
                        csv_id += all[i];
                        break;
                    case 2:
                        csv_name += all[i];
                        break;
                    case 3:
                        csv_fname += all[i];
                        break;
                    case 4:
                        csv_address += all[i];
                        break;
                    case 5:
                        csv_pin += all[i];
                        break;
                    case 6:
                        csv_pass += all[i];
                        break;
                    case 7:
                        csv_phone += all[i];
                        break;
                    case 8:
                        csv_balance += all[i];
                        break;
                    case 9: // displays the user fetched record
                            // cout<< " \n\n\n\t\t Search User Record ";
                            // cout <<"\n User ID       : "<<csv_id       ;
                            // cout <<"\n Name          : "<<csv_name     ;
                            // cout <<"\n Father's Name : "<<csv_fname    ;
                            // cout <<"\n Address       : "<<csv_address   ;
                            // cout <<"\n PIN           : "<<csv_pin      ;
                            // cout <<"\n Password      : "<<csv_pass     ;
                            // cout <<"\n Phone         : "<<csv_phone    ;
                            // cout <<"\n Balance       : "<<csv_balance  ;

                        break;
                    default:
                        cout << "Default Printed : Case :: " << position; // IF SOMETHING ERROR HAPPENS.....
                        break;
                    }

                    // ASKS FOR THE details to be edited
                    if (test_id == csv_id && position == 9) // wait until the first comma, ie second position is encountered
                    {
                        char ch1;
                        cout << "\n\t\t\t Delete User Details \n\n";

                        char check;
                        cout << "Delete Record " << test_id << "named" << csv_name << "(Y/N) \t: ";
                        check = getche();
                        if (check == 'y' || check == 'Y')
                        {
                            // DO NOT WRITE
                            // NOT WRITING THE DETAILS OF THE ID TO BE DELETED........
                            // temp_file << csv_id << "," << name << "," << fname << "," << address << "," << pin << "," << pass << "," << phone << "," << csv_balance << ","  << "\n";
                            cout << "\n\n User ID : \"\" " << test_id << " \"\"named \"\"" << csv_name << "\"\" deleted successfully!!";
                        }
                        else
                        {
                            // WRITE THE INFORMATION TO THE FILE IF OHTER THAN Y or y is pressed............
                            temp_file << csv_id << "," << csv_name << "," << csv_fname << "," << csv_address << "," << csv_pin << "," << csv_pass << "," << csv_phone << "," << csv_balance << ","
                                      << "\n";
                        }

                        found++;
                    }
                    else if (test_id != csv_id && position == 9) // if the user id doesnt match after the scan  then print like this;
                    {
                        temp_file << csv_id << "," << csv_name << "," << csv_fname << "," << csv_address << "," << csv_pin << "," << csv_pass << "," << csv_phone << "," << csv_balance << ","
                                  << "\n";
                    }
                }
                file >> all;
            }
            file.close();
            temp_file.close();
            remove("bank.csv");
            rename("temp_bank.csv", "bank.csv");
            if (found == 0)
            {
                cout << "\n\n User ID Can't Found...";
            }
        }
    }
}

void bank::show_all_records()
{
    fflush(stdin);
    string all;
    system("cls");
    fstream file;
    string search_id;
    int found = 0;
    cout << " \n\n\t\t All User Record ";
    file.open("bank.csv", ios::in);
    if (!file)
    {
        cout << "File Opening Error !!!";
    }
    else
    {
        file >> all;
        file >> all; // start from second line cz first line is heading
        while (!file.eof())
        {
            int position = 1; // we are declaring this variable and setting the value to zero because,
            string csv_id = "\0", csv_name = "\0", csv_fname = "\0", csv_address = "\0", csv_phone = "\0", csv_balance = "\0", csv_pin = "\0", csv_pass = "\0";

            // storing the comma separated values to the new varibale.. for this we have to iterate through every string while the comma is found and we will incrase the position variable and comma found variable accordingly and
            // until the comma found is 0, we will store the characters to the ID variable and so on..
            for (int i = 0; i < all.length(); i++)
            {

                if (all[i] == ',')
                {
                    {
                        // cout <<  all[i]; // prints comma
                        i++;
                        // comma_found++;
                        position++; // after one comma is found the position is increased by 1.
                    }
                }
                /* THE STRIGS VALUE WILL BE ADDED TO THE RESPECTIVE POSITIONS.  */
                switch (position) //  the default value of position is 1 so while the 1st comma is not encountered the value will keep stacking on the csv_id string
                {
                case 1:
                    csv_id += all[i];
                    break;
                case 2:
                    csv_name += all[i];
                    break;
                case 3:
                    csv_fname += all[i];
                    break;
                case 4:
                    csv_address += all[i];
                    break;
                case 5:
                    csv_pin += all[i];
                    break;
                case 6:
                    csv_pass += all[i];
                    break;
                case 7:
                    csv_phone += all[i];
                    break;
                case 8:
                    csv_balance += all[i];
                    break;
                case 9: // displays the user fetched record
                        // cout<< " \n\n\n\t\t Search User Record ";
                        // cout <<"\n User ID       : "<<csv_id       ;
                        // cout <<"\n Name          : "<<csv_name     ;
                        // cout <<"\n Father's Name : "<<csv_fname    ;
                        // cout <<"\n Address       : "<<csv_address   ;
                        // cout <<"\n PIN           : "<<csv_pin      ;
                        // cout <<"\n Password      : "<<csv_pass     ;
                        // cout <<"\n Phone         : "<<csv_phone    ;
                        // cout <<"\n Balance       : "<<csv_balance  ;

                    break;
                default:
                    cout << "Default Printed : Case :: " << position; // IF SOMETHING ERROR HAPPENS.....
                    break;
                }

                if (position == 9) // after each line is finshed
                {

                    cout << " \n\n----------------------------------------------------------\n";
                    cout << "----------------------------------------------------------\n";
                    cout << "\n User ID       : " << convert_line_to_space(csv_id);
                    cout << "\n Name          : " << convert_line_to_space(csv_name);
                    cout << "\n Father's Name : " << convert_line_to_space(csv_fname);
                    cout << "\n Address       : " << convert_line_to_space(csv_address);
                    cout << "\n Phone         : " << convert_line_to_space(csv_phone);
                    cout << "\n Balance       : " << convert_line_to_space(csv_balance);
                    cout << "\n PIN           : " << convert_line_to_space(csv_pin);
                    cout << "\n Password      : " << convert_line_to_space(csv_pass);
                    cout << " \n\n----------------------------------------------------------\n";
                    cout << "----------------------------------------------------------\n\n";
                }
            }

            file >> all;
        }
        // file >> all;
    }
    file.close();
}

void bank::show_all_payments()
{
    fflush(stdin);
    system("cls");
    fstream file;
    int found = 0;
    float bill_amount;
    string c_date;
    cout << "\n\n\t\t Show All User's Records";
    file.open("Bills.txt", ios::in);
    if (!file)
    {
        cout << "\n\n  File Opening Error!!!";
    }
    else
    {
        file >> id >> name >> bill_amount >> c_date;
        while (!file.eof())
        {
            cout << "\n User ID       : " << id;
            cout << "\n Bill Name     : " << name;
            cout << "\n Bill Amount   : " << bill_amount;
            cout << "\n Date          : " << c_date;
            cout << "\n\n ************************************************** \n";
            cout << " ************************************************** \n\n";
            file >> id >> name >> bill_amount >> c_date;
            found++;
        }
        file.close();
        if (found == 0) // file exists but record is empty↓↓↓↓↓↓
        {
            cout << "\n\n DataBase is Empty!!";
        }
        cout << " \n\n Total " << found << ". Records shown!!";
    }
}

int bank::user_balance()
{
    fflush(stdin);
    string all;
    system("cls");
    fstream file;
    string test_id, test_pin, test_pass;
    char ch;
    int found = 0;
    cout << "\n\n\t\t\t User Login ";
    cout << "\n\n !!!DON'T PRESS ENTER after entering the pin.  ";
    cout << " The cursor will be automatically shifted to the password";
    file.open("bank.csv", ios::in);
    if (!file)
    {
        cout << " File Opening Error !!!!";
    }
    else
    {
        cout << "\n\n User ID : ";
        cin >> test_id;
        fflush(stdin);

        cout << "\n\n PIN Code :";
        for (int i = 1; i <= 4; i++) // checks for the 4 characters
        {
            ch = getch();
            test_pin += ch;
            cout << "*";
        }
        cout << "\n\n Password : ";
        for (int i = 1; i <= 5; i++) // checks for the 5 characters
        {
            ch = getch();
            test_pass += ch;
            cout << "*";
        }
        file >> all;
        while (!file.eof())
        {
            int position = 1; // we are declaring this variable and setting the value to zero because,
            string csv_id = "\0", csv_name = "\0", csv_fname = "\0", csv_address = "\0", csv_phone = "\0", csv_balance = "\0", csv_pin = "\0", csv_pass = "\0";

            // storing the comma separated values to the new varibale.. for this we have to iterate through every string while the comma is found and we will incrase the position variable and comma found variable accordingly and
            // until the comma found is 0, we will store the characters to the ID variable and so on..
            for (int i = 0; i < all.length(); i++)
            {

                if (all[i] == ',')
                {
                    {
                        // cout <<  all[i]; // prints comma
                        i++;
                        // comma_found++;
                        position++; // after one comma is found the position is increased by 1.
                    }
                }
                /* THE STRIGS VALUE WILL BE ADDED TO THE RESPECTIVE POSITIONS.  */
                switch (position) //  the default value of position is 1 so while the 1st comma is not encountered the value will keep stacking on the csv_id string
                {
                case 1:
                    csv_id += all[i];
                    break;
                case 2:
                    csv_name += all[i];
                    break;
                case 3:
                    csv_fname += all[i];
                    break;
                case 4:
                    csv_address += all[i];
                    break;
                case 5:
                    csv_pin += all[i];
                    break;
                case 6:
                    csv_pass += all[i];
                    break;
                case 7:
                    csv_phone += all[i];
                    break;
                case 8:
                    csv_balance += all[i];
                    break;
                case 9: // displays the user fetched record
                        // cout<< " \n\n\n\t\t Search User Record ";
                        // cout <<"\n User ID       : "<<csv_id       ;
                        // cout <<"\n Name          : "<<csv_name     ;
                        // cout <<"\n Father's Name : "<<csv_fname    ;
                        // cout <<"\n Address       : "<<csv_address   ;
                        // cout <<"\n PIN           : "<<csv_pin      ;
                        // cout <<"\n Password      : "<<csv_pass     ;
                        // cout <<"\n Phone         : "<<csv_phone    ;
                        // cout <<"\n Balance       : "<<csv_balance  ;

                    break;
                default:
                    cout << "Default Printed : Case :: " << position; // IF SOMETHING ERROR HAPPENS.....
                    break;
                }

                if (position == 9)
                {
                    if (test_id == csv_id && test_pin == csv_pin && test_pass == csv_pass)
                    {
                        // IF LOGIN SUCCESSFUL RETURN 1, ELSE RETURN 0;

                        cout << " LOGIN SUCCESSFUL!! \n\n";
                        cout << " \n\n\t\t Your Current Balance is " << csv_balance;
                        found++;
                        getch();
                    }
                }
            }
            file >> all;
        }
        file.close();
        if (found == 0)
        {
            cout << "\n\n\t\t User ID, PIN & Password Invalid !!!";
            return 0;
        }

        if (found == 1)
        {
            return 1;
        }
    }
}

void bank::atm_check_details()
{
    fflush(stdin);

    // FOR LOGIN
    // if user successful then , do this
    if (user_balance() == 1)
    {
        search(); // to search
    }
}

void bank::withdraw_atm()
{
    // FOR LOGIN
    // if user successful then , do this
    if (user_balance() == 1)
    {
        withdraw(); // to search
    }
}

string convert_space_to_line(string input_string)
{
    string output_string = "\0";
    for (int i = 0; i < input_string.length(); i++)
    {
        if (input_string[i] == ' ')
        {
            output_string += "_";
        }
        else
        {
            output_string += input_string[i];
        }
    }
    return output_string;
}

string convert_line_to_space(string input_string)
{
    string output_string = "\0";
    for (int i = 0; i < input_string.length(); i++)
    {
        if (input_string[i] == '_')
        {
            output_string += " ";
        }
        else
        {
            output_string += input_string[i];
        }
    }
    return output_string;
}

int is_space_present(string input_string)
{
    // string input_string = "\0";

    // cout << " Input the string  : ";
    // getline(cin,input_string);

    // // checking if the string contains space or not
    // cout << " space present returns  : "<< is_space_present(input_string);
    // if(is_space_present(input_string))
    // {
    //     cout << " Space Present";
    // }
    // else
    // {
    //     cout << " Space Absent";
    // }

    int space_found = 0;
    for (int i = 0; i < input_string.length(); i++)
    {
        if (input_string[i] == ' ')
            space_found++;
    }
    if (space_found == 0) // if space found = 0 , then return is_space+present is false
    {
        return 0; // if there is no space found, return ( IS SPACE PRESENT = FASLE )
    }
    else
    {
        return 1;
    }
}

int is_input_all_number(string input_string)
{

    //  string input_string = "\0";
    //
    // cout << " Input the string  : ";
    // getline(cin,input_string);
    //
    // checking if the string contains all number or not
    // cout << " space present returns  : "<< is_input_all_number(input_string);
    // if(is_input_all_number(input_string))
    // {
    // cout << " \n\nYes all number ";
    // }
    // else
    // {
    // cout << " \n\nNo some chars present";
    // }
    //
    int chars_present = 0;

    for (int i = 0; i < input_string.length(); i++)
    {

        if (!(input_string[i] == '0' || input_string[i] == '1' || input_string[i] == '2' || input_string[i] == '3' || input_string[i] == '4' || input_string[i] == '5' || input_string[i] == '6' || input_string[i] == '7' || input_string[i] == '8' || input_string[i] == '9')) // if the input string [i] character is not number then ↓↓↓
        {
            chars_present++; // if the input string [i] character is not number then ← ← ← ←
        }
    }

    if (chars_present == 0) // if there is no characters return is input all nmber is true
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_comma_present_in_input_string(string input_string)
{
    int comma_found = 0;
    for (int i = 0; i < input_string.length(); i++)
    {
        if (input_string[i] == ',')
        {
            comma_found++;
        }
    }
    if (comma_found == 0)
    {
        return 0; // if no comma found return zero i.e , is comma present in input string is false
    }
    else
    {
        cout << " You cannot input COMMA to any of the input fields. Please input again without comma";
        return 1; // if comma found is more than zero than means comma has been found but we cant enter the comma
        // so comma _found
    }
}

string Add_two_Strings(string a, string b) // for receivers id
{
    // cout << a << "  " << b;

    stringstream ss;
    stringstream geek(a);
    int x = 0;
    geek >> x;
    // cout << "Value of x : " << x;

    //

    stringstream geek2(b);
    int x2 = 0;
    geek2 >> x2;
    // cout << "Value of x2 : " << x2;

    int total_plus;
    // int total_minus;
    total_plus = x + x2;

    // cout
    // << " TOtal Plus : " << total_plus;
    // cout << " TOtal minus : " << total_minus ;
    // _2_int_to_string(x ,XX);
    return to_string(total_plus);
}

string Subtract_two_Strings(string a, string b) // for sender
{
    // cout << a << "  " << b;

    stringstream ss;
    stringstream geek(a);
    int x = 0;
    geek >> x;
    // cout << "Value of x : " << x;

    //

    stringstream geek2(b);
    int x2 = 0;
    geek2 >> x2;
    // cout << "Value of x2 : " << x2;

    // int total_plus;
    int total_minus;
    // total_plus = x2 + x;

    // FOR EXTRA SECURITY AND ERROR HANDLING
    // FOR EXTRA SECURITY AND ERROR HANDLING
    // FOR EXTRA SECURITY AND ERROR HANDLING

    if (x2 > x) // this means if the transfer amount is greater than the balance
    {
        cout << " \n\n Insufficient Balance \n\n  ";
        total_minus = x; // if there is insufficient blc the original value will be returned as it is
    }
    else
    {
        total_minus = x - x2;
    }
    // total_minus =  x - x2;

    // cout
    // << " TOtal Minus: " << total_minus;
    // cout << " TOtal minus : " << total_minus ;
    // _2_int_to_string(x ,XX);
    return to_string(total_minus);
}

int convert_string_to_int(string a)
{
    stringstream ss;
    stringstream geek(a);
    int x = 0;
    geek >> x;
    return x;
}


void login_screen() // Making Login Function
{
    int i = 0;
    int a = 0;         // we are declaring this variable so that we can check if the login details is incorrect more than 2 times, it will exit
    char c = ' ';      // for displaying as asterik
    char username[20]; // for taking input of username
    char password[20]; // to store the password
    do
    {
        cout <<"\n";
        cout <<"\n ================  LOGIN  ================ \n";
        cout <<"\n";
        cout <<"       Username :-  ";
        scanf("%s", &username);
        cout <<"\n       Password :-  "; // now asking for password
        // when we are entering the password, it should be taken as
        // character and display as asterik  ********
        // explanation on how the asterik is shown here,
        while (i < 20)
        {
            password[i] = getch(); // storing the value of getch,i.e. when you press some key in the console/keyboard in terminal, the getch will capture it and move forward, when you use getch to take the input, the character you pressed is not shownn in the screen.
            c = password[i];       //
            if (c == 13)           // if user inputs the password more than 13 character, it will exit
                break;             // will exit loop
            else                   // until the user enters the password less than 13 characers, it will take input and print asterik in output when one character is taken
                printf("*");       //
            i++;
        }
        password[i] = '\0';
        // char code = pword;
        i = 0;
        // use this to take login details whithout showing asterik             // scanf("%s",&password);
        if (strcmp(username, "mrnavy") == 0 && strcmp(password, "navy") == 0) // strcmp compares the two strings and if the two strings strcmp(username,"user") username value and "user" are same it returns the value of 0, so after that the login will be successful
        {
            system("cls");

            cout <<"!!! LOGIN IS SUCCESSFUl\n\n";

            cout <<"              =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
            cout <<"              ==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==";
            cout <<"\n              === WELCOME TO NAVY'S BANK AND ATM MANAGEMENT SYSTEM =-=\n";
            cout <<"              ===-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
            cout <<"              =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
            cout <<"\t\t\t\n\nPress any key to continue...";

            getch(); // this will hold the output
            break;   // this will exit the if and else loop and will go to while a<=2 and that will be incorrect too.
        }
        else
        {
            cout <<"\n";
            cout <<"\n";
            system("cls"); // clearing screen and asking for the login details again if the entered is wrong.
            cout <<"\n SORRY !!! THE CREDENTIALS YOU ENTERED ARE INCORRECT ";
            cout <<"\n\n Enter the login details again...";
            a++;

            // this will hold the output
        }
    } while (a <= 2);

    if (a > 2)
    {
        system("cls"); // clearing screen for showing below action..
        cout <<"\n You have entered the wrong for more than three times \n You will get exit from this program";
        getch(); // will hold the screen
    }
}

void introduction()
{   //1st page
    cout << "\n\n\n\n\n\t";
    for (int i = 0; i < 60; i++)
    { cout << "*";}
    cout << "\n\t  ";
        for (int i = 0; i < 58; i++)
    { cout << "*";}
    cout << "\n\t   ";
        for (int i = 0; i < 56; i++)
    { cout << "*";}
    cout<<"\n\n \t\t\t   Bank & ATM Management System\n\t\t\t\t  Project in C++\n\n\t   ";
    for (int i = 0; i < 56; i++)
    { cout << "*";}
    cout << " \n\t  ";
    for (int i = 0; i < 58; i++)
    { cout << "*";}
    cout << " \n\t ";
    for (int i = 0; i < 60; i++)
    { cout << "*";}
    getch();   //3rd page
    system("cls");
    cout << "\n\n\t";
    for (int i = 0; i < 60; i++)
    cout <<"*";
    cout << "\n\t";
    for (int i = 0; i < 60; i++)
    cout <<"*";
    cout <<"\n\t\t    Software Developer Introduction";
    cout <<"\n\n\t   Name:\t\t\t\tNabaraj Dhungel";
    cout <<"\n\t   Country:\t\t\t\tNepal";
    cout <<"\n\t   Facebook:\t\t\t\t@NabarajDhungel01";
    cout <<"\n\t   Instagram:\t\t\t\t@NabarajDhungel01";
    cout <<"\n\t   Twitter:\t\t\t\t@mrnavy01";
    cout <<"\n\t   Contact:\t\t\t\t+977-9808698123";

    cout << "\n\n\t";
    for (int i = 0; i < 60; i++)
    cout <<"*";
    cout << "\n\t";
    for (int i = 0; i < 60; i++)
    cout <<"*";
    getch();//2nd page
    system("cls");
    cout << "\n\n\n\n\n\t\t\t";
    for (int i = 0; i < 30; i++)
    { cout << "*";}
    cout << "\n\t\t\t";
    for (int i = 0; i < 30; i++)
    { cout << "*";}
    cout <<"\n\n\t\t\t        Credits to:";
    cout <<"\n\n\t\t\t 1. CodeWithHarry";
    cout <<"\n\n\t\t\t 2. Khizar Mehar Technical \n\n\t\t\t";
    for (int i = 0; i < 30; i++)
    { cout << "*";}
    cout << "\n\t\t\t";
    for (int i = 0; i < 30; i++)
    { cout << "*";}
}