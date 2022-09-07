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
    void already_user() {} // if the Existing user asks for the id and password
    void deposit() {}
    void withdraw() {}
    void transfer() {}
    void payment() {}
    void search() {}
    void edit() {}
    void del() {} // delete user record
    void show_all_records() {}
    void show_all_payments() {}
    void user_balance() {}
    void withdraw_atm() {}
    void atm_chek_details() {}

    // friend void main();
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
    obj1.new_user();
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
        cout << " PIN is : " << pin;
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
        file << "ID"<< ","<< "NAME3"<< ","<< "FATHER'S_NAME"<< ","<< "ADDRESS"<< ","<< "PIN"<< ","<< "PASSWORD"<< ","<< "CONTACT"<< ","<< "BALANCE"<< "\n";
        // priting details provided by the user
        file << id << "," << name << "," << fname << "," << address << "," << pin << "," << pass << "," << phone << "," << balance << "\n";
        file.close();
        cout <<"User Add Successful!";

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
                    int position = 1;// we are declaring this variable and setting the value to zero because,
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
                        default:
                            cout << "Default Printed : Case :: " << position; // IF SOMETHING ERROR HAPPENS.....
                            break;
                        }

                        if (id == csv_id && position == 2 ) // wait until the first comma, ie second position is encountered 
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
                file.open("bank.csv",ios::app|ios::out);
                cout << "\nfile opened line 205";
                file << id << "," << name << "," << fname << "," << address << "," << pin << "," << pass << "," << phone << "," << balance << "\n";
                file.close();
                cout <<"User Add Successful!";
            
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
