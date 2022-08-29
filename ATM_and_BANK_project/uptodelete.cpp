#include <iostream> 
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <windows.h>
using namespace std;
class bank
{
    private:
    string pin;
    float balance;
    string id,pass,name,fname,address,phone;
public:
    void menu();
    void bank_management();
    void atm_management();
    void new_user();
    void already_user();// if the Existing user asks for the id and password
    void deposit();
    void withdraw();
    void transfer();
    void payment();
    void search();
    void edit();
    void del(); //delete user record
    void show_all_records();
    void show_all_payments();
};
void bank::menu()
{
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
    cin >> choice; while (cin.fail()) { cin.clear();   cin.ignore();  }    // if the user enters the character, this will prevent program from crashing.
    switch (choice)
    {
    case 1:
        // system("cls");
        // cout << "\n\n \t\t Login Account";
        // cout << "\n\n E-mail  :";
        // email;
        // cout << "\n Pin     :";
        // for (int i = 1; i <= 5; i++)
        // {
            // ch = getch();
            // pin += ch;
            // cout << "*";
        // }
        // cout << "\n Password     : ";
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
        bank_management(); break;
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
    cin >> choice; while (cin.fail()) { cin.clear();   cin.ignore();  }     // if the user enters the character, this will prevent program from crashing.
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
            break;
        case 11:
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
    p:
    system("cls");
    int choice;
    cout << "\n\n\t\t ATM Management System";
    cout << "\n\n 1. User Login & Check Balance";
    cout << "\n 2. Withrdraw Amount";
    cout << "\n 3. Account Details";
    cout << "\n 4. Go Back.";
    cout << "\n\n Enter your Choice  : ";
    cin >> choice; while (cin.fail()) { cin.clear();   cin.ignore();  }     // if the user enters the character, this will prevent program from crashing.
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
        default:
            cout << "Invalid Choice !!!";
        }
        getch();
        goto p; 
}
void bank::new_user()
{
    p:
    system("cls");
    fstream file;
    string f_pin;
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
    cin >> pin;
    cout << "\n 6.Password         :";
    cin >> pass;
    cout << "\n 7.Phone No.        :";
    cin >> phone;
    cout << "\n 8.Current Balance  :";
    cin >> balance;
    file.open("bank.txt", ios::in);
     if (!file) // if there is no file
    {
        file.open("bank.txt", ios::app|ios::out);
        file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
        file.close();
    }
    else
    {
        file >> f_id >> f_name >> f_fname >> f_address >> f_pin >> f_pass >> f_phone >> f_balance;
        while ((!file.eof()))
        {
            if (f_id == id)
            {
                cout << "\n\nUser ID Already Exist...";
                getch();
                goto p;
            }
            file >> f_id >> f_name >> f_fname >> f_address >> f_pin >> f_pass >> f_phone >> f_balance;
        }
        file.close();
         file.open("bank.txt", ios::app|ios::out);
         file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
         file.close();
    }
    cout << "New User  Created Successfully...";
}
void bank::already_user()
{
    system("cls");
    fstream file;
    string test_id;
    int found = 0;
    cout << "\n\n\n \t\t Already User Account";
    file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<"\n\n\n\t\tFile Opening Error!!!!\n\n";
    }
    else
    {
        cout << "\n\n \t\t  User ID : ";
        cin >> test_id; /*file.open("bank.txt",ios::in);*/
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while (!file.eof())
        {
            if (test_id == id)
            {
                system("cls");
                cout << "\n\n\n \t\t Already User Account\n\n";
                cout << "\n\n\tPin Code : "<<pin<<"\n\n\tPassword : " << pass ;
                found++; 
            }
             file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        if (found == 0)
        {            cout << "\n\n User ID Can't Found...";        }        
    }
}
void bank::deposit()
{
    fstream file,temp_file;
    string test_id;
    float amount;// amt to be deposited
    int found = 0;
    system("cls");
    cout<<"\n\n\n\t\t Deposit Amount Option";
    file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<"\n\n\n\t\t File Opening Error !!!";
    }
    else
    {
        cout << "\n\n \t\t  User ID : ";
        cin >> test_id;
        temp_file.open("temp_bank.txt",ios::app|ios::out);
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while (!file.eof())
        {
            if (test_id == id)
            {
                cout<<"Amount For Deposit  : ";
                cin>>amount;
                balance += amount;// updated amount
                temp_file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                found++; 
                cout << " Amount Rs."<<amount<<"|- Deposit Successful!!";
            }
            else
            {
                temp_file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
            }
             file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        temp_file.close();
        remove("bank.txt");
        rename("temp_bank.txt","bank.txt");
        if (found == 0)
        { cout << "\n\n User ID Can't Found...";  }  
    }
}
void bank::withdraw()
{
    fstream file,temp_file;
    string test_id;
    float amount;// amt to be withdrawn
    int found = 0;
    system("cls");
    cout<<"\n\n\n\t\t Withdraw Amount Option";
    file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<"\n\n\n\t\t File Opening Error !!!";
    }
    else
    {
        cout << "\n\n \t\t  User ID : ";
        cin >> test_id;
        temp_file.open("temp_bank.txt",ios::app|ios::out);
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while (!file.eof())
        {
            if (test_id == id)
            {
                cout<<"Amount For Withdraw  : ";
                cin>>amount;    // CHECKING IF THE WITHDRAW AMOUNT IS LESS THAN THE ACCOUNT BALANCE ↓↓↓↓↓↓↓↓↓
                if (amount <= balance )
                {
                balance -= amount;// updated amount
                temp_file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                cout << " Amount Rs."<<amount<<"|- Withdraw Successful!!";
                }
                else
                {               //////    ERROR IN THE PROGRAMMER CODE /// I HAVE ADDDED if withdraw balance error, then also write to the file
                    cout << "\n\n\n\t\t Your Current Balance is :Rs."<<balance<<"|-..\n\n\t\t Withdraw Balance Error!!! "  ;
                    temp_file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                }
                found ++;
            }
            else
            {
                temp_file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
            }
             file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        temp_file.close();
        remove("bank.txt");
        rename("temp_bank.txt","bank.txt");
        if (found == 0){
             cout << "\n\n User ID Can't Found...";  }  
    }
}
void bank::transfer()
{   
    fstream file,temp_file;
    system("cls");
    string sender_id,receiver_id;
    int found = 0,sender_found= 0,receiver_found= 0;
    float transfer_amount;
    cout<<"\n\n\n\t\t\t Payment Transfer Option";
    file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<"\n\n\n\t\t File Opening Error !!!";
    }
    else
    {
        cout<< "\n\n Sender User ID   : ";          /// TRY TO UTILIZE THE DEPOSIT AND WITHDRAWL FUNCTIONS MAKES MORE COMPLEX
        cin>>sender_id;
        cout<< "\n\n Receiver User ID : ";
        cin>>receiver_id;
        cout<< "\n\n Transfer Amount  : ";
        cin>>transfer_amount;        /// OPENING THE FILE AS READING MODE  12 lines above//////////////////////////////////////////////////////////
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;  
        while (!file.eof()) // Checking if both sender and receiver exists or not and if the sender has the sufficient balance or not 
        { /*if(sender_id == id && transfer_amount > balance){ cout << "Insufficient Balnce In Sender's Account"; getch(); goto beginning;}*/
            if(sender_id == id && transfer_amount <= balance )
             found++,sender_found++;
            else if(receiver_id == id)
             found++,receiver_found++; 
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;  
        }
        file.close();
        if (found == 2 )   //if(found == 2 )
        {
            file.open("bank.txt",ios::in);
            temp_file.open("temp_bank.txt",ios::app|ios::out);
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;  
            while(!file.eof())
            {
            if (sender_id == id )
            {
                balance -= transfer_amount;
                temp_file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
            }
            else if ( receiver_id == id)
            {
                balance += transfer_amount;
                temp_file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
            }
            else
            {
                temp_file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
            }
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;  
            }  
            file.close();
            temp_file.close();
            remove("bank.txt");
            rename("temp_bank.txt","bank.txt");
             cout << "\n\n\n Transaction Successful!!"; getch();
        }
        else if(found == 0){cout << "Sender and Receiver ID Invalid!!!";getch();}
        if(found == 1 ) {
                            if (sender_found = 1){cout<< " Sender ID Invalid!!";}if (receiver_found = 1){cout<< " Receiver ID Invalid!!";}
                        }
    }
}
void bank::payment()
{
    system("cls");
    fstream file,temp_file,bill_file;
    int found =0, insufficient_balance = 0;
    string bill_id, bill_name;
    float bill_amount;
    SYSTEMTIME x;
    cout<< "\n\n\t\t Bills Payment Option.";
     file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<"\n\n\n\t\t File Opening Error!!!!\n\n";}
    else
    // again:
    {  cout << "\n\n   User ID : ";
        cin >> bill_id; // /* Checking if the file ID exists or not */file.open("bank.txt",ios::in);file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;    while (!file.eof())   {  if (test_id == id)  { found++; } }file.close();  if(!(found == 1))   {   cout << "\n\n User ID Invalid..."; }      
        ///*checking if the ID exists or not*/ file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;    while (!file.eof()){  if (bill_id == id){ goto found_continue; } file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance; }file.close(); cout << "\n\n User ID Invalid..."; found =0 ;goto again; // found_continue: file.open("bank.txt",ios::in);
        cout<< "\n\n Bill Name : ";
        cin >> bill_name;
        cout << "\n\n Bill Amount : ";
        cin >> bill_amount;
        temp_file.open("temp_bank.txt",ios::app|ios::out);
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while (!file.eof())
        {   
            if (bill_id == id && bill_amount > balance) { insufficient_balance = 1;  temp_file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";}
            else if (bill_id == id && bill_amount <= balance) 
            {   balance -= bill_amount;
                temp_file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                found++;  
            }
            else
            {
                temp_file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
            }
             file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
            file.close();
            temp_file.close();
            remove("bank.txt");
            rename("temp_bank.txt","bank.txt");
        if (found == 1)
        {
            GetSystemTime(&x);
            bill_file.open("Bills.txt", ios::app|ios::out);
            bill_file << bill_id <<" "<< bill_name<<" "<< bill_amount << " " <<x.wDay<<"/"<<x.wMonth<<"/"<<x.wYear<<"\n";
            bill_file.close();
            cout<<" \n\n \t\t"<<bill_name<< "  Bill Pay Successfully ";
        }
        else if( found == 0 && insufficient_balance == 0) 
            { cout << " \n\n User ID Invalid !!!";}
        else if ( insufficient_balance == 1 ) 
        { cout << "\n\n Insufficient Balance in "<< name <<"'s Account";}
    }
}
void bank::search()
{
    system("cls");
    fstream file;
    string search_id;
    int found=0;
    cout<< " \n\n\t\t Search User Record ";
    file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<"File Opening Error !!!";
    }
    else
    {
        cout << "\n\n \t\t  User ID : ";
        cin >> search_id; /*file.open("bank.txt",ios::in);*/
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while (!file.eof())
        {
            if (search_id == id)
            {
                system("cls");
                cout<< " 'n\n\n\t\t Search User Record ";
                cout <<"\n User ID       : "<<id       ;
                cout <<"\n Name          : "<<name     ;
                cout <<"\n Father's Name : "<<fname    ;cout <<"\n Address       : "<<address   ;cout <<"\n Phone         : "<<phone    ;cout <<"\n Balance       : "<<balance  ;cout <<"\n PIN           : "<<pin      ;
                cout <<"\n Password      : "<<pass     ;
                found++;
            }
             file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        if (found == 0)
        {  cout << "\n\n User ID Can't Found...";  }        
    }   
}
 void bank::edit()
 {
    system("cls");
    fstream file,temp_file;
    string test_id,new_name, new_fname, new_pass, new_address, new_phone/*,id*/;
    string new_pin; int found = 0;
    cout<<"\n\n\t\t Edit User Record.";
    file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<"File Opening Error!!";
    }
    else
    {
     cout << "User ID : "   ;
     cin >> test_id;
     temp_file.open("temp_bank.txt",ios::app|ios::out);
     file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
     while (!file.eof())
        {
            if (test_id == id)
            {   system("cls");
                cout << "\n 1.**NEW** Name             :";
                cin >> new_name;
                cout << "\n 2.**NEW** Father Name      :";
                cin >> new_fname;
                cout << "\n 3.**NEW** Address          :";
                cin >> new_address;
                cout << "\n 4.**NEW** PIN              :";
                cin >> new_pin;
                cout << "\n 5.**NEW** Password         :";
                cin >> new_pass;
                cout << "\n 6.**NEW** Phone No.        :";
                cin >> new_phone; 
                temp_file<<" "<<id<<" "<<new_name<<" "<<new_fname<<" "<<new_address<<" "<<new_pin<<" "<<new_pass<<" "<<new_phone<<" "<<balance<<"\n";
                cout<<"Record Successfully Updated!!!";
                found++;
                }
            else
            {
                temp_file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
            }
             file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        temp_file.close();
        remove("bank.txt");
        rename("temp_bank.txt","bank.txt");
        if (found == 0)
        {            cout << "\n\n User ID Can't Found...";        } 
    }   
 }
 void bank::del()   //// MAKE LIST OF THE FILE THAT IS DELETED
 {
     system("cls");
    fstream file,temp_file;
    string test_id ;
    int found = 0;
    cout<<"\n\n\t\t Delete User Record.\n\n\n";
    file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<"File Opening Error!!";
    }
    else
    {
     cout << "User ID : "   ;
     cin >> test_id;
     temp_file.open("temp_bank.txt",ios::app|ios::out);
     file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
     while (!file.eof())
        {
            if (test_id == id)
            {   system("cls");
                //we are deleting the record so no need the write the file// temp_file<<" "<<id<<" "<<new_name<<" "<<new_fname<<" "<<new_address<<" "<<new_pin<<" "<<new_pass<<" "<<new_phone<<" "<<balance<<"\n";
                cout<<"Record Deleted  Successfully!!!";            
                found++;
                }
            else
            {
                temp_file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
            }
             file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        temp_file.close();
        remove("bank.txt");
        rename("temp_bank.txt","bank.txt");
        if (found == 0)
        {            cout << "\n\n User ID Can't Found...";        } 
    }
 }
main()
{
    bank obj; 
    obj.menu();
    // obj.already_user();
}
