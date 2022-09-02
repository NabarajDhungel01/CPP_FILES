#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <windows.h>
                            // REPLACE SPACE WITH _ write function to do this and return string value.
using namespace std;
class bank
{
private:
    string id, pass, name, fname, address, phone, pin, balance;

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
    void user_balance();
    void withdraw_atm();
    void atm_chek_details();
};
string convert_space_to_line(string input_string);
string convert_line_to_space(string input_string);

void bank::new_user()
{
p:
    system("cls");
    fstream file;
    /*  */ int repeat_id, repeat_name, repeat_fname, repeat_address, repeat_phone, repeat_balance, repeat_pin, repeat_pass;
    int comma_found, comma_found_id, comma_found_name, comma_found_fname, comma_found_address, comma_found_pin, comma_found_pass, comma_found_phone, comma_found_balance;
    int position = 1;
    int test_id_found;

    /*  */ string all;
    /*  */ string csv_id = "\0", csv_name = "\0", csv_fname = "\0", csv_address = "\0", csv_phone = "\0", csv_balance = "\0", csv_pin = "\0", csv_pass = "\0";
    string NEW_csv_id = "\0", NEW_csv_name = "\0", NEW_csv_fname = "\0", NEW_csv_address = "\0", NEW_csv_phone = "\0", NEW_csv_balance = "\0", NEW_csv_pin = "\0", NEW_csv_pass = "\0";
    cout << "\n\n\t\t Add New User\n";
    cout << "\n 1.User ID          :";
    getline(cin, id);
    cout << "\n 2.Name             :";
    getline(cin, name);
    cout << "\n 3.Father Name      :";
    getline(cin, fname);
    cout << "\n 4.Address          :";
    getline(cin, address);
    cout << "\n 5.PIN              :";
    getline(cin, pin);
    cout << "\n 6.Password         :";
    getline(cin, pass);
    cout << "\n 7.Phone No.        :";
    getline(cin, phone);
    cout << "\n 8.Current Balance  :";
    getline(cin, balance);

    file.open("bank.csv", ios::in);

    if (!file) // if there is no file
    {
        file.open("bank.csv", ios::app | ios::out);
        // WRITING HEADINGS TO THE FILE
        file << "ID"<< ","<< "NAME"<< ","<< "FATHER'S NAME"<< ","<< "ADDRESS"<< ","<< "PIN"<< ","<< "PASSWORD"<< ","<< "CONTACT"<< ","<< "BALANCE"<< "\n";
        file << id << "," << name << "," << fname << "," << address << "," << pin << "," << pass << "," << phone << "," << balance << "\n";
        file.close();
    }
    else
    {
        file >> all; // this parts ignores the first heading part
        cout << " first all is : "<< all ;
        file >> all ; // this will point after the space of FATHER's in FATHERS'S Name
        file >> all; // this will point towards the second line ,i.e., first , user record
        cout << " second all is : "<< all ;

        while ((!file.eof()))
        {
            repeat_id = 0, repeat_name = 0, repeat_fname = 0, repeat_address = 0, repeat_phone = 0, repeat_balance = 0, repeat_pin = 0, repeat_pass = 0;
            comma_found = 0, comma_found_id = 0, comma_found_name = 0, comma_found_fname = 0, comma_found_address = 0, comma_found_pin = 0, comma_found_pass = 0, comma_found_phone = 0, comma_found_balance = 0;
            position = 1;
            test_id_found = 0;

            /* CHECKING THE COMMA PRESENCE w.r.t srings  */
            for (int i = 0; i < all.length(); i++)
            {

                if (all[i] == ',')
                {
                    // cout <<  all[i]; // prints comma
                    i++;
                    comma_found++;
                    switch (comma_found)
                    {
                    case 1:
                        comma_found_id++;
                        break;
                    case 2:
                        comma_found_name++;
                        break;
                    case 3:
                        comma_found_fname++;
                        break;
                    case 4:
                        comma_found_address++;
                        break;
                    case 5:
                        comma_found_pin++;
                        break;
                    case 6:
                        comma_found_pass++;
                        break;
                    case 7:
                        comma_found_phone++;
                        break;
                    case 8:
                        comma_found_balance++;
                        break;
                    default:
                        cout << "\n\n CASE COMMA_FOUND_DEFAULT :: Case : " << comma_found << "\n\n";
                        break;
                    }
                    position++; // after one comma is found the position is increased by 1.
                }

                /* THE STRIGS VALUE WILL BE ADDED TO THE RESPECTIVE POSITIONS.  */
                switch (position)
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

                // ASSIGNING THE STRING COMMAS SEPARATED VALUSE TO THE NEW VALUE
                {
                    // if (comma_found_id == 1 && repeat_id == 0)
                    // {
                    // cout << " ID  : " << csv_id;
                    // repeat_id = 1;
                    // NEW_csv_id = csv_id;
                    // cout << " ID is : "<<id<<endl;
                    // cout << "CSV ID is : "<<csv_id<<endl;
                    // cout << "CSV NEW ID is : "<< NEW_csv_id <<endl;
                    //
                    //    /* CHECKING IF THE ID IN THE DATABASE MATCHES WITH THE PROVIDED INPUT */
                    //
                    // if
                    // {
                    //
                    // }
                    // }

                    if (id == csv_id)
                    {
                        if (comma_found_id == 1 && repeat_name == 0)
                        {
                            // cout << " ID : " << csv_id;
                            repeat_name = 1;
                            NEW_csv_id = csv_id;
                        }
                        if (comma_found_name == 1 && repeat_name == 0)
                        {
                            // cout << " Name : " << csv_name;
                            repeat_name = 1;
                            NEW_csv_name = csv_name;
                        }
                        if (comma_found_fname == 1 && repeat_fname == 0)
                        {
                            // cout << " F_Name  : " << csv_fname;
                            repeat_fname = 1;
                            NEW_csv_fname = csv_fname;
                        }
                        if (comma_found_address == 1 && repeat_address == 0)
                        {
                            // cout << " Address  : " << csv_address;
                            repeat_address = 1;
                            NEW_csv_address = csv_address;
                        }
                        if (comma_found_pin == 1 && repeat_pin == 0)
                        {
                            // cout << " PIN  : " << csv_pin;
                            repeat_pin = 1;
                            NEW_csv_pin = csv_pin;
                        }
                        if (comma_found_pass == 1 && repeat_pass == 0)
                        {
                            // cout << " Pass : " << csv_pass;
                            repeat_pass = 1;
                            NEW_csv_pass = csv_pass;
                        }
                        if (comma_found_phone == 1 && repeat_phone == 0)
                        {
                            // cout << " Phone : " << csv_phone;
                            repeat_phone = 1;
                            NEW_csv_phone = csv_phone;
                        }
                        if (comma_found_balance == 1 && repeat_balance == 0)
                        {
                            // cout << " Balance : " << csv_balance;
                            repeat_balance = 1;
                            NEW_csv_balance = csv_balance;
                        }
                    }
                }

                if (id == csv_id)
                {
                    cout << "\n\nUser ID Already Exist...";
                    getch();
                    /* IF ID MATCHES */
                    goto p;
                    /* else */
                    /* IF the ID matches then it will go to p  */
                }
                /* else{ */

                file << NEW_csv_id << "," << NEW_csv_name << "," << NEW_csv_fname << "," << NEW_csv_address << "," << NEW_csv_pin << "," << NEW_csv_pass << "," << NEW_csv_phone << "," << NEW_csv_balance << "\n";
                file >> all;
                /* } */
            }
        }
        file.close();
    }
    cout << "New User  Created Successfully...";
}
























// void bank::already_user()
// {
//     system("cls");
//     fstream file;
//     string test_id;
//     int found = 0;
//     cout << "\n\n\n \t\t Already User Account";
//     file.open("bank.txt", ios::in);
//     if (!file)
//     {
//         cout << "\n\n\n\t\tFile Opening Error!!!!\n\n";
//     }
//     else
//     {
//         cout << "\n\n \t\t  User ID : ";
//         cin >> test_id; /*file.open("bank.txt",ios::in);*/
//         file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
//         while (!file.eof())
//         {
//             if (test_id == id)
//             {
//                 system("cls");
//                 cout << "\n\n\n \t\t Already User Account\n\n";
//                 cout << "\n\n\tPin Code : " << pin << "\n\n\tPassword : " << pass;
//                 found++;
//             }
//             file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
//         }
//         file.close();
//         if (found == 0)
//         {
//             cout << "\n\n User ID Can't Found...";
//         }
//     }
// }

// void bank::deposit()
// {
//     fstream file, temp_file;
//     string test_id;
//     float amount; // amt to be deposited
//     int found = 0;
//     system("cls");
//     cout << "\n\n\n\t\t Deposit Amount Option";
//     file.open("bank.txt", ios::in);
//     if (!file)
//     {
//         cout << "\n\n\n\t\t File Opening Error !!!";
//     }
//     else
//     {
//         cout << "\n\n \t\t  User ID : ";
//         cin >> test_id;
//         temp_file.open("temp_bank.txt", ios::app | ios::out);
//         file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
//         while (!file.eof())
//         {
//             if (test_id == id)
//             {
//                 cout << "Amount For Deposit  : ";
//                 cin >> amount;
//                 balance += amount; // updated amount
//                 temp_file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
//                 found++;
//                 cout << " Amount Rs." << amount << "|- Deposit Successful!!";
//             }
//             else
//             {
//                 temp_file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
//             }
//             file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
//         }
//         file.close();
//         temp_file.close();
//         remove("bank.txt");
//         rename("temp_bank.txt", "bank.txt");
//         if (found == 0)
//         {
//             cout << "\n\n User ID Can't Found...";
//         }
//     }
// }

// void bank::withdraw()
// {
//     fstream file, temp_file;
//     string test_id;
//     float amount; // amt to be withdrawn
//     int found = 0;
//     system("cls");
//     cout << "\n\n\n\t\t Withdraw Amount Option";
//     file.open("bank.txt", ios::in);
//     if (!file)
//     {
//         cout << "\n\n\n\t\t File Opening Error !!!";
//     }
//     else
//     {
//         cout << "\n\n \t\t  User ID : ";
//         cin >> test_id;
//         temp_file.open("temp_bank.txt", ios::app | ios::out);
//         file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
//         while (!file.eof())
//         {
//             if (test_id == id)
//             {
//                 cout << "Amount For Withdraw  : ";
//                 cin >> amount; // CHECKING IF THE WITHDRAW AMOUNT IS LESS THAN THE ACCOUNT BALANCE ↓↓↓↓↓↓↓↓↓
//                 if (amount <= balance)
//                 {
//                     balance -= amount; // updated amount
//                     temp_file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
//                     cout << " Amount Rs." << amount << "|- Withdraw Successful!!";
//                 }
//                 else
//                 { //////    ERROR IN THE PROGRAMMER CODE /// I HAVE ADDDED if withdraw balance error, then also write to the file
//                     cout << "\n\n\n\t\t Your Current Balance is :Rs." << balance << "|-..\n\n\t\t Withdraw Balance Error!!! ";
//                     temp_file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
//                 }
//                 found++;
//             }
//             else
//             {
//                 temp_file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
//             }
//             file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
//         }
//         file.close();
//         temp_file.close();
//         remove("bank.txt");
//         rename("temp_bank.txt", "bank.txt");
//         if (found == 0)
//         {
//             cout << "\n\n User ID Can't Found...";
//         }
//     }
// }

// void bank::transfer()
// {
//     fstream file, temp_file;
//     system("cls");
//     string sender_id, receiver_id;
//     int found = 0, sender_found = 0, receiver_found = 0;
//     float transfer_amount;
//     cout << "\n\n\n\t\t\t Payment Transfer Option";
//     file.open("bank.txt", ios::in);
//     if (!file)
//     {
//         cout << "\n\n\n\t\t File Opening Error !!!";
//     }
//     else
//     {
//         cout << "\n\n Sender User ID   : "; /// TRY TO UTILIZE THE DEPOSIT AND WITHDRAWL FUNCTIONS MAKES MORE COMPLEX
//         cin >> sender_id;
//         cout << "\n\n Receiver User ID : ";
//         cin >> receiver_id;
//         cout << "\n\n Transfer Amount  : ";
//         cin >> transfer_amount; /// OPENING THE FILE AS READING MODE  12 lines above//////////////////////////////////////////////////////////
//         file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
//         while (!file.eof()) // Checking if both sender and receiver exists or not and if the sender has the sufficient balance or not
//         {                   /*if(sender_id == id && transfer_amount > balance){ cout << "Insufficient Balnce In Sender's Account"; getch(); goto beginning;}*/
//             if (sender_id == id && transfer_amount <= balance)
//                 found++, sender_found++;
//             else if (receiver_id == id)
//                 found++, receiver_found++;
//             file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
//         }
//         file.close();
//         if (found == 2) // if(found == 2 )
//         {
//             file.open("bank.txt", ios::in);
//             temp_file.open("temp_bank.txt", ios::app | ios::out);
//             file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
//             while (!file.eof())
//             {
//                 if (sender_id == id)
//                 {
//                     balance -= transfer_amount;
//                     temp_file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
//                 }
//                 else if (receiver_id == id)
//                 {
//                     balance += transfer_amount;
//                     temp_file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
//                 }
//                 else
//                 {
//                     temp_file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
//                 }
//                 file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
//             }
//             file.close();
//             temp_file.close();
//             remove("bank.txt");
//             rename("temp_bank.txt", "bank.txt");
//             cout << "\n\n\n Transaction Successful!!";
//             getch();
//         }
//         else if (found == 0)
//         {
//             cout << "Sender and Receiver ID Invalid!!!";
//             getch();
//         }
//         if (found == 1)
//         {
//             if (sender_found = 1)
//             {
//                 cout << " Sender ID Invalid!!";
//             }
//             if (receiver_found = 1)
//             {
//                 cout << " Receiver ID Invalid!!";
//             }
//         }
//     }
// }

// void bank::payment()
// {
//     system("cls");
//     fstream file, temp_file, bill_file;
//     int found = 0, insufficient_balance = 0;
//     string bill_id, bill_name;
//     float bill_amount;
//     SYSTEMTIME x;
//     cout << "\n\n\t\t Bills Payment Option.";
//     file.open("bank.txt", ios::in);
//     if (!file)
//     {
//         cout << "\n\n\n\t\t File Opening Error!!!!\n\n";
//     }
//     else
//     // again:
//     {
//         cout << "\n\n   User ID : ";
//         cin >> bill_id; // /* Checking if the file ID exists or not */file.open("bank.txt",ios::in);file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;    while (!file.eof())   {  if (test_id == id)  { found++; } }file.close();  if(!(found == 1))   {   cout << "\n\n User ID Invalid..."; }
//         ///*checking if the ID exists or not*/ file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;    while (!file.eof()){  if (bill_id == id){ goto found_continue; } file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance; }file.close(); cout << "\n\n User ID Invalid..."; found =0 ;goto again; // found_continue: file.open("bank.txt",ios::in);
//         cout << "\n\n Bill Name : ";
//         cin >> bill_name;
//         cout << "\n\n Bill Amount : ";
//         cin >> bill_amount;
//         temp_file.open("temp_bank.txt", ios::app | ios::out);
//         file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
//         while (!file.eof())
//         {
//             if (bill_id == id && bill_amount > balance)
//             {
//                 insufficient_balance = 1;
//                 temp_file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
//             }
//             else if (bill_id == id && bill_amount <= balance)
//             {
//                 balance -= bill_amount;
//                 temp_file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
//                 found++;
//             }
//             else
//             {
//                 temp_file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
//             }
//             file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
//         }
//         file.close();
//         temp_file.close();
//         remove("bank.txt");
//         rename("temp_bank.txt", "bank.txt");
//         if (found == 1)
//         {
//             GetSystemTime(&x);
//             bill_file.open("Bills.txt", ios::app | ios::out);
//             bill_file << bill_id << " " << bill_name << " " << bill_amount << " " << x.wDay << "/" << x.wMonth << "/" << x.wYear << "\n";
//             bill_file.close();
//             cout << " \n\n \t\t" << bill_name << "  Bill Pay Successfully ";
//         }
//         else if (found == 0 && insufficient_balance == 0)
//         {
//             cout << " \n\n User ID Invalid !!!";
//         }
//         else if (insufficient_balance == 1)
//         {
//             cout << "\n\n Insufficient Balance in " << name << "'s Account";
//         }
//     }
// }

// void bank::search()
// {
//     system("cls");
//     fstream file;
//     string search_id;
//     int found = 0;
//     cout << " \n\n\t\t Search User Record ";
//     file.open("bank.txt", ios::in);
//     if (!file)
//     {
//         cout << "File Opening Error !!!";
//     }
//     else
//     {
//         cout << "\n\n \t\t  User ID : ";
//         cin >> search_id; /*file.open("bank.txt",ios::in);*/
//         file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
//         while (!file.eof())
//         {
//             if (search_id == id)
//             {
//                 system("cls");
//                 cout << " 'n\n\n\t\t Search User Record ";
//                 cout << "\n User ID       : " << id;
//                 cout << "\n Name          : " << name;
//                 cout << "\n Father's Name : " << fname;
//                 cout << "\n Address       : " << address;
//                 cout << "\n Phone         : " << phone;
//                 cout << "\n Balance       : " << balance;
//                 cout << "\n PIN           : " << pin;
//                 cout << "\n Password      : " << pass;
//                 found++;
//             }
//             file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
//         }
//         file.close();
//         if (found == 0)
//         {
//             cout << "\n\n User ID Can't Found...";
//         }
//     }
// }

// void bank::edit()
// {
//     system("cls");
//     fstream file, temp_file;
//     string test_id, new_name, new_fname, new_pass, new_address, new_phone /*,id*/;
//     string new_pin;
//     int found = 0;
//     cout << "\n\n\t\t Edit User Record.";
//     file.open("bank.txt", ios::in);
//     if (!file)
//     {
//         cout << "File Opening Error!!";
//     }
//     else
//     {
//         cout << "User ID : ";
//         cin >> test_id;
//         temp_file.open("temp_bank.txt", ios::app | ios::out);
//         file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
//         while (!file.eof())
//         {
//             if (test_id == id)
//             {
//                 cout << "\n 1.**NEW** Name             :";
//                 cin >> new_name;
//                 cout << "\n 2.**NEW** Father Name      :";
//                 cin >> new_fname;
//                 cout << "\n 3.**NEW** Address          :";
//                 cin >> new_address;
//                 cout << "\n 4.**NEW** PIN              :";
//                 cin >> new_pin;
//                 cout << "\n 5.**NEW** Password         :";
//                 cin >> new_pass;
//                 cout << "\n 6.**NEW** Phone No.        :";
//                 cin >> new_phone;
//                 temp_file << " " << id << " " << new_name << " " << new_fname << " " << new_address << " " << new_pin << " " << new_pass << " " << new_phone << " " << balance << "\n";
//                 cout << "Record Successfully Updated!!!";
//                 found++;
//             }
//             else
//             {
//                 temp_file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
//             }
//             file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
//         }
//         file.close();
//         temp_file.close();
//         remove("bank.txt");
//         rename("temp_bank.txt", "bank.txt");
//         if (found == 0)
//         {
//             cout << "\n\n User ID Can't Found...";
//         }
//     }
// }

// void bank::del() //// MAKE LIST OF THE FILE THAT IS DELETED
// {
//     system("cls");
//     fstream file, temp_file;
//     string test_id;
//     int found = 0;
//     cout << "\n\n\t\t Delete User Record.\n\n\n";
//     file.open("bank.txt", ios::in);
//     if (!file)
//     {
//         cout << "File Opening Error!!";
//     }
//     else
//     {
//         cout << "User ID : ";
//         cin >> test_id;
//         temp_file.open("temp_bank.txt", ios::app | ios::out);
//         file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
//         while (!file.eof())
//         {
//             if (test_id == id)
//             { // we are deleting the record so no need the write the file// temp_file<<" "<<id<<" "<<new_name<<" "<<new_fname<<" "<<new_address<<" "<<new_pin<<" "<<new_pass<<" "<<new_phone<<" "<<balance<<"\n";
//                 cout << "Record Deleted  Successfully!!!";
//                 found++;
//             }
//             else
//             {
//                 temp_file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
//             }
//             file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
//         }
//         file.close();
//         temp_file.close();
//         remove("bank.txt");
//         rename("temp_bank.txt", "bank.txt");
//         if (found == 0)
//         {
//             cout << "\n\n User ID Can't Found...";
//         }
//     }
// }

// void bank::show_all_records()
// {
//     system("cls");
//     fstream file;
//     int found = 0;
//     cout << "\n\n\t\t Show All User's Records";
//     file.open("bank.txt", ios::in);
//     if (!file)
//     {
//         cout << "\n\n  File Opening Error!!!";
//     }
//     else
//     {
//         file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
//         while (!file.eof())
//         {
//             cout << "\n User ID       : " << id;
//             cout << "\n Name          : " << name;
//             cout << "\n Father's Name : " << fname;
//             cout << "\n Address       : " << address;
//             cout << "\n Phone         : " << phone;
//             cout << "\n Balance       : " << balance;
//             cout << "\n PIN           : " << pin;
//             cout << "\n Password      : " << pass;
//             cout << "\n\n ************************************************** \n";
//             cout << " ************************************************** \n\n";
//             file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
//             found++;
//         }
//         file.close();
//         if (found == 0) // file exists but record is empty↓↓↓↓↓↓
//         {
//             cout << "\n\n DataBase is Empty!!";
//         }
//         cout << " \n\n Total " << found << ". Records shown!!";
//     }
// }

// void bank::show_all_payments()
// {
//     system("cls");
//     fstream file;
//     int found = 0;
//     float bill_amount;
//     string c_date;
//     cout << "\n\n\t\t Show All User's Records";
//     file.open("Bills.txt", ios::in);
//     if (!file)
//     {
//         cout << "\n\n  File Opening Error!!!";
//     }
//     else
//     {
//         file >> id >> name >> bill_amount >> c_date;
//         while (!file.eof())
//         {
//             cout << "\n User ID       : " << id;
//             cout << "\n Bill Name     : " << name;
//             cout << "\n Bill Amount   : " << bill_amount;
//             cout << "\n Date          : " << c_date;
//             cout << "\n\n ************************************************** \n";
//             cout << " ************************************************** \n\n";
//             file >> id >> name >> bill_amount >> c_date;
//             found++;
//         }
//         file.close();
//         if (found == 0) // file exists but record is empty↓↓↓↓↓↓
//         {
//             cout << "\n\n DataBase is Empty!!";
//         }
//         cout << " \n\n Total " << found << ". Records shown!!";
//     }
// }

// void bank::user_balance()
// {
//     system("cls");
//     fstream file;
//     string test_id, test_pin, test_pass;
//     char ch;
//     int found = 0;
//     cout << "\n\n\t\t\t User Login ";
//     file.open("bank.txt", ios::in);
//     if (!file)
//     {
//         cout << " File Opening Error !!!!";
//     }
//     else
//     {
//         cout << "\n\n User ID : ";
//         cin >> test_id;
//         cout << "\n\n PIN Code :";
//         for (int i = 1; i <= 5; i++)
//         {
//             ch = getch();
//             test_pin += ch;
//             cout << "*";
//         }
//         cout << "\n\n Password : ";
//         for (int i = 1; i <= 5; i++)
//         {
//             ch = getch();
//             test_pass += ch;
//             cout << "*";
//         }
//         file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
//         while (!file.eof())
//         {
//             if (test_id == id && test_pin == pin && test_pass == pass)
//             {
//                 cout << " \n\n\t\t Your Current Balance is " << balance;
//                 found++;
//             }
//             file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
//         }
//         file.close();
//         if (found == 0)
//         {
//             cout << "\n\n\t\t User ID, PIN & Password Invalid !!!";
//         }
//     }
// }

// void bank::withdraw_atm()
// {
//     user_balance(); // asks for password and pin.
//     withdraw();     // allows user to withdraw the amount from the atm
// }

// void bank::atm_chek_details()
// {
//     user_balance(); // login
//     search();
// }
// void intrdoduction()
// { // 1st page
//     cout << "\n\n\n\n\n\t";
//     for (int i = 0; i < 60; i++)
//     {
//         cout << "*";
//     }
//     cout << "\n\t  ";
//     for (int i = 0; i < 58; i++)
//     {
//         cout << "*";
//     }
//     cout << "\n\t   ";
//     for (int i = 0; i < 56; i++)
//     {
//         cout << "*";
//     }
//     cout << "\n\n \t\t\t   Bank & ATM Management System\n\t\t\t\t  Project in C++\n\n\t   ";
//     for (int i = 0; i < 56; i++)
//     {
//         cout << "*";
//     }
//     cout << " \n\t  ";
//     for (int i = 0; i < 58; i++)
//     {
//         cout << "*";
//     }
//     cout << " \n\t ";
//     for (int i = 0; i < 60; i++)
//     {
//         cout << "*";
//     }
//     getch(); // 3rd page
//     system("cls");
//     cout << "\n\n\t";
//     for (int i = 0; i < 60; i++)
//         cout << "*";
//     cout << "\n\t";
//     for (int i = 0; i < 60; i++)
//         cout << "*";
//     cout << "\n\t\t    Software Developer Introduction";
//     cout << "\n\n\t   Name:\t\t\t\tNabaraj Dhungel";
//     cout << "\n\t   Country:\t\t\t\tNepal";
//     cout << "\n\t   Facebook:\t\t\t\t@NabarajDhungel01";
//     cout << "\n\t   Instagram:\t\t\t\t@NabarajDhungel01";
//     cout << "\n\t   Twitter:\t\t\t\t@mrnavy01";
//     cout << "\n\t   Contact:\t\t\t\t+977-9808698123";

//     cout << "\n\n\t";
//     for (int i = 0; i < 60; i++)
//         cout << "*";
//     cout << "\n\t";
//     for (int i = 0; i < 60; i++)
//         cout << "*";
//     getch(); // 2nd page
//     system("cls");
//     cout << "\n\n\n\n\n\t\t\t";
//     for (int i = 0; i < 30; i++)
//     {
//         cout << "*";
//     }
//     cout << "\n\t\t\t";
//     for (int i = 0; i < 30; i++)
//     {
//         cout << "*";
//     }
//     cout << "\n\n\t\t\t        Credits to:";
//     cout << "\n\n\t\t\t 1. CodeWithHarry";
//     cout << "\n\n\t\t\t 2. Khizar Mehar Technical \n\n\t\t\t";
//     for (int i = 0; i < 30; i++)
//     {
//         cout << "*";
//     }
//     cout << "\n\t\t\t";
//     for (int i = 0; i < 30; i++)
//     {
//         cout << "*";
//     }
// }

// void bank::menu()
// {
// p:
//     system("cls");
//     int choice;
//     char ch;
//     string pin, pass, email;
//     cout << "\n\n\n\t\t\tControl Panel";
//     cout << "\n\n 1. Bank  Management";
//     cout << "\n 2. ATM Management";
//     cout << "\n 3. Exit";
//     cout << "\n\n Enter your choice  : ";
//     cin >> choice;
//     while (cin.fail())
//     {
//         cin.clear();
//         cin.ignore();
//     } // if the user enters the character, this will prevent program from crashing.
//     switch (choice)
//     {
//     case 1:
//         // system("cls");
//         // cout << "\n\n \t\t Login Account";
//         // cout << "\n\n E-mail  :";
//         // email;
//         // cout << "\n Pin (5 digit)    :";
//         // for (int i = 1; i <= 5; i++)
//         // {
//         // ch = getch();
//         // pin += ch;
//         // cout << "*";
//         // }
//         // cout << "\n Password (5 digit)    : ";
//         // for (int i = 1; i <= 5; i++)
//         // {
//         // ch = getch();
//         // pass += ch;
//         // cout << "*";
//         // }
//         // if (email == "khizar@gmail.com" && pin == "13366" && pass == "14366")
//         // {
//         // bank_management();
//         // }
//         // else
//         // {
//         // cout << "\n\n Incorrect Credentials !!!";
//         // }
//         bank_management();
//         break;
//     case 2:
//         atm_management();
//         break;
//     case 3:
//         exit(0);
//     default:
//         cout << "Invalid Value.. Please try again";
//     }
//     getch();
//     goto p;
// }

// void bank::bank_management()
// {
// p: // goto loop
//     int choice;
//     system("cls");
//     cout << "\n\n\t\t BANK Management System\n";
//     cout << "\n 1.  New User";
//     cout << "\n 2.  Already User";
//     cout << "\n 3.  Deposit Option";
//     cout << "\n 4.  Withdraw Option.";
//     cout << "\n 5.  Transfer Option.";
//     cout << "\n 6.  Payment Option.";
//     cout << "\n 7.  Search User Record.";
//     cout << "\n 8.  Edit User Record.";
//     cout << "\n 9.  Delete User Record.";
//     cout << "\n 10. Show All Records.";
//     cout << "\n 11. Payment All Records.";
//     cout << "\n 12. Go Back";
//     cout << "\n\n Enter your Choice  : ";
//     cin >> choice;
//     while (cin.fail())
//     {
//         cin.clear();
//         cin.ignore();
//     } // if the user enters the character, this will prevent program from crashing.
//     switch (choice)
//     {
//     case 1:
//         new_user();
//         break;
//     case 2:
//         already_user();
//         break;
//     case 3:
//         deposit();
//         break;
//     case 4:
//         withdraw();
//         break;
//     case 5:
//         transfer();
//         break;
//     case 6:
//         payment();
//         break;
//     case 7:
//         search();
//         break;
//     case 8:
//         edit();
//         break;
//     case 9:
//         del();
//         break;
//     case 10:
//         show_all_records();
//         break;
//     case 11:
//         show_all_payments();
//         break;
//     case 12:
//         menu();
//     default:
//         cout << "Invalid Choice !!!";
//     }
//     getch();
//     goto p;
// }

// void bank::atm_management()
// {
// p:
//     system("cls");
//     int choice;
//     cout << "\n\n\t\t ATM Management System";
//     cout << "\n\n 1. User Login & Check Balance";
//     cout << "\n 2. Withrdraw Amount";
//     cout << "\n 3. Account Details";
//     cout << "\n 4. Go Back.";
//     cout << "\n\n Enter your Choice  : ";
//     cin >> choice;
//     while (cin.fail())
//     {
//         cin.clear();
//         cin.ignore();
//     } // if the user enters the character, this will prevent program from crashing.
//     switch (choice)
//     {
//     case 1:
//         user_balance();
//         break;
//     case 2:
//         withdraw_atm();
//         break;
//     case 3:
//         atm_chek_details();
//         break;
//     case 4:
//         menu();
//     default:
//         cout << "Invalid Choice !!!";
//     }
//     getch();
//     goto p;
// }

main()
{
    bank obj;
    // intrdoduction();
    obj.new_user();
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