#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <windows.h>
using namespace std;
class bank
{
private:
    string id = "\0", pass = "\0", name = "\0", fname = "\0", address = "\0", phone = "\0", pin = "\0", balance = "\0";

public:
    void menu() {}
    void bank_management() {}
    void atm_management() {}
    void new_user();
    void already_user(); // if the Existing user asks for the id and password
    void deposit();
    void withdraw();
    void transfer();
    void payment() {}
    void search();
    void edit() {}
    void del() {} // delete user record
    void show_all_records() {}
    void show_all_payments() {}
    void user_balance() {}
    void withdraw_atm() {}
    void atm_chek_details() {}
};
string convert_space_to_line(string input_string); // THIS FUNCTION CONVERTS THE SPACES TO UNDERSCORE for error handling and getting the name as NAME CAST and converting to NAME_CAST so that we can write to the file and when we fetch the data from the file space will cause error so,
string convert_line_to_space(string input_string); // CONVERTS UNDERSCORE TO SPACE // USED WHILE SHOWING OUTPUT
int is_space_present(string input_string);
// int is_length_correct(string input_string, int correct_length); // provide string to check if the correct number of length of string is entered.
int is_input_all_number(string input_string); // checks if all the input is the number
int is_comma_present_in_input_string(string input_string);

int main()
{
    // fstream file;
    // file.open("bank.csv",ios::app|ios::out);
    // cout << "Hello Test";
    // file << "Hello Test";
    // file.close();

    bank obj1;
    // obj1.new_user();
    // obj1.deposit();
    // obj1.withdraw();
    obj1.transfer();
    // obj1.deposit();
}

void bank::new_user()
{
    int repeat = 0;
starting_of_new_user:
    system("cls");
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
             << "NAME3"
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
        file >> all; // this point to the second line

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
                }
            }

            file >> all;
        }
        file >> all;
    }
    file.close();

    if (found == 0)
    {
        cout << "\n\n User ID Can't Found...";
    }
}

void bank::already_user() // if the Existing user asks for the id and password
{
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
}

void bank::deposit()
{
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

                    // displays the user fetched record
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

                    // displays the user fetched record
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
        cout << "\n\n Receiver User ID : ";
        cin >> receiver_id;
        cout << "\n\n Transfer Amount  : ";
        cin >> transfer_amount; /// OPENING THE FILE AS READING MODE  12 lines above//////////////////////////////////////////////////////////

        file >> all;
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

                    // displays the user fetched record
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
                    if (sender_id == id && transfer_amount <= balance)
                        found++, sender_found++;
                    else if (receiver_id == id)
                        found++, receiver_found++;
                    file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
                }
            }
            file >> all;
        }
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

                        // displays the user fetched record
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
                        if (sender_id == id)
                        {
                            csv_balance = to_string(stoi(csv_balance) - stoi(transfer_amount));
                            temp_file << csv_id << "," << csv_name << "," << csv_fname << "," << csv_address << "," << csv_pin << "," << csv_pass << "," << csv_phone << "," << csv_balance << "," << "\n";
                        }
                        else if (receiver_id == id)
                        {
                            csv_balance = to_string(stoi(csv_balance) + stoi(transfer_amount));
                           temp_file << csv_id << "," << csv_name << "," << csv_fname << "," << csv_address << "," << csv_pin << "," << csv_pass << "," << csv_phone << "," << csv_balance << "," << "\n";
                        }
                        else
                        {
                           temp_file << csv_id << "," << csv_name << "," << csv_fname << "," << csv_address << "," << csv_pin << "," << csv_pass << "," << csv_phone << "," << csv_balance << "," << "\n";
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
                cout << " Sender ID Invalid!!";
            }
            if (receiver_found = 1)
            {
                cout << " Receiver ID Invalid!!";
            }
        }
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
