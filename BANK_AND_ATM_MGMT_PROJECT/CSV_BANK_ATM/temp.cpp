
void bank::already_user()
{
    system("cls");
    fstream file;
    string test_id;
    int found = 0;
    cout << "\n\n\n \t\t Already User Account";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n\n\t\tFile Opening Error!!!!\n\n";
    }
    else
    {
        cout << "\n\n \t\t  User ID : ";
        cin >> test_id; /*file.open("bank.txt",ios::in);*/
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof())
        {
            if (test_id == id)
            {
                system("cls");
                cout << "\n\n\n \t\t Already User Account\n\n";
                cout << "\n\n\tPin Code : " << pin << "\n\n\tPassword : " << pass;
                found++;
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        if (found == 0)
        {
            cout << "\n\n User ID Can't Found...";
        }
    }
}
void bank::deposit()
{
    fstream file, temp_file;
    string test_id;
    float amount; // amt to be deposited
    int found = 0;
    system("cls");
    cout << "\n\n\n\t\t Deposit Amount Option";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n\n\t\t File Opening Error !!!";
    }
    else
    {
        cout << "\n\n \t\t  User ID : ";
        cin >> test_id;
        temp_file.open("temp_bank.txt", ios::app | ios::out);
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof())
        {
            if (test_id == id)
            {
                cout << "Amount For Deposit  : ";
                cin >> amount;
                balance += amount; // updated amount
                temp_file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                found++;
                cout << " Amount Rs." << amount << "|- Deposit Successful!!";
            }
            else
            {
                temp_file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        temp_file.close();
        remove("bank.txt");
        rename("temp_bank.txt", "bank.txt");
        if (found == 0)
        {
            cout << "\n\n User ID Can't Found...";
        }
    }
}
void bank::withdraw()
{
    fstream file, temp_file;
    string test_id;
    float amount; // amt to be withdrawn
    int found = 0;
    system("cls");
    cout << "\n\n\n\t\t Withdraw Amount Option";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n\n\t\t File Opening Error !!!";
    }
    else
    {
        cout << "\n\n \t\t  User ID : ";
        cin >> test_id;
        temp_file.open("temp_bank.txt", ios::app | ios::out);
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof())
        {
            if (test_id == id)
            {
                cout << "Amount For Withdraw  : ";
                cin >> amount; // CHECKING IF THE WITHDRAW AMOUNT IS LESS THAN THE ACCOUNT BALANCE ↓↓↓↓↓↓↓↓↓
                if (amount <= balance)
                {
                    balance -= amount; // updated amount
                    temp_file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                    cout << " Amount Rs." << amount << "|- Withdraw Successful!!";
                }
                else
                { //////    ERROR IN THE PROGRAMMER CODE /// I HAVE ADDDED if withdraw balance error, then also write to the file
                    cout << "\n\n\n\t\t Your Current Balance is :Rs." << balance << "|-..\n\n\t\t Withdraw Balance Error!!! ";
                    temp_file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                }
                found++;
            }
            else
            {
                temp_file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        temp_file.close();
        remove("bank.txt");
        rename("temp_bank.txt", "bank.txt");
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
    float transfer_amount;
    cout << "\n\n\n\t\t\t Payment Transfer Option";
    file.open("bank.txt", ios::in);
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
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof()) // Checking if both sender and receiver exists or not and if the sender has the sufficient balance or not
        {                   /*if(sender_id == id && transfer_amount > balance){ cout << "Insufficient Balnce In Sender's Account"; getch(); goto beginning;}*/
            if (sender_id == id && transfer_amount <= balance)
                found++, sender_found++;
            else if (receiver_id == id)
                found++, receiver_found++;
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        if (found == 2) // if(found == 2 )
        {
            file.open("bank.txt", ios::in);
            temp_file.open("temp_bank.txt", ios::app | ios::out);
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
            while (!file.eof())
            {
                if (sender_id == id)
                {
                    balance -= transfer_amount;
                    temp_file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                }
                else if (receiver_id == id)
                {
                    balance += transfer_amount;
                    temp_file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                }
                else
                {
                    temp_file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                }
                file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
            }
            file.close();
            temp_file.close();
            remove("bank.txt");
            rename("temp_bank.txt", "bank.txt");
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
void bank::payment()
{
    system("cls");
    fstream file, temp_file, bill_file;
    int found = 0, insufficient_balance = 0;
    string bill_id, bill_name;
    float bill_amount;
    SYSTEMTIME x;
    cout << "\n\n\t\t Bills Payment Option.";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n\n\t\t File Opening Error!!!!\n\n";
    }
    else
    // again:
    {
        cout << "\n\n   User ID : ";
        cin >> bill_id; // /* Checking if the file ID exists or not */file.open("bank.txt",ios::in);file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;    while (!file.eof())   {  if (test_id == id)  { found++; } }file.close();  if(!(found == 1))   {   cout << "\n\n User ID Invalid..."; }
        ///*checking if the ID exists or not*/ file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;    while (!file.eof()){  if (bill_id == id){ goto found_continue; } file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance; }file.close(); cout << "\n\n User ID Invalid..."; found =0 ;goto again; // found_continue: file.open("bank.txt",ios::in);
        cout << "\n\n Bill Name : ";
        cin >> bill_name;
        cout << "\n\n Bill Amount : ";
        cin >> bill_amount;
        temp_file.open("temp_bank.txt", ios::app | ios::out);
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof())
        {
            if (bill_id == id && bill_amount > balance)
            {
                insufficient_balance = 1;
                temp_file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
            }
            else if (bill_id == id && bill_amount <= balance)
            {
                balance -= bill_amount;
                temp_file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                found++;
            }
            else
            {
                temp_file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        temp_file.close();
        remove("bank.txt");
        rename("temp_bank.txt", "bank.txt");
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
            cout << " \n\n User ID Invalid !!!";
        }
        else if (insufficient_balance == 1)
        {
            cout << "\n\n Insufficient Balance in " << name << "'s Account";
        }
    }
}
void bank::search()
{
    system("cls");
    fstream file;
    string search_id;
    int found = 0;
    cout << " \n\n\t\t Search User Record ";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "File Opening Error !!!";
    }
    else
    {
        cout << "\n\n \t\t  User ID : ";
        cin >> search_id; /*file.open("bank.txt",ios::in);*/
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof())
        {
            if (search_id == id)
            {
                system("cls");
                cout << " 'n\n\n\t\t Search User Record ";
                cout << "\n User ID       : " << id;
                cout << "\n Name          : " << name;
                cout << "\n Father's Name : " << fname;
                cout << "\n Address       : " << address;
                cout << "\n Phone         : " << phone;
                cout << "\n Balance       : " << balance;
                cout << "\n PIN           : " << pin;
                cout << "\n Password      : " << pass;
                found++;
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        if (found == 0)
        {
            cout << "\n\n User ID Can't Found...";
        }
    }
}
void bank::edit()
{
    system("cls");
    fstream file, temp_file;
    string test_id, new_name, new_fname, new_pass, new_address, new_phone /*,id*/;
    string new_pin;
    int found = 0;
    cout << "\n\n\t\t Edit User Record.";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "File Opening Error!!";
    }
    else
    {
        cout << "User ID : ";
        cin >> test_id;
        temp_file.open("temp_bank.txt", ios::app | ios::out);
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof())
        {
            if (test_id == id)
            {
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
                temp_file << " " << id << " " << new_name << " " << new_fname << " " << new_address << " " << new_pin << " " << new_pass << " " << new_phone << " " << balance << "\n";
                cout << "Record Successfully Updated!!!";
                found++;
            }
            else
            {
                temp_file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        temp_file.close();
        remove("bank.txt");
        rename("temp_bank.txt", "bank.txt");
        if (found == 0)
        {
            cout << "\n\n User ID Can't Found...";
        }
    }
}
void bank::del() //// MAKE LIST OF THE FILE THAT IS DELETED
{
    system("cls");
    fstream file, temp_file;
    string test_id;
    int found = 0;
    cout << "\n\n\t\t Delete User Record.\n\n\n";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "File Opening Error!!";
    }
    else
    {
        cout << "User ID : ";
        cin >> test_id;
        temp_file.open("temp_bank.txt", ios::app | ios::out);
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof())
        {
            if (test_id == id)
            { // we are deleting the record so no need the write the file// temp_file<<" "<<id<<" "<<new_name<<" "<<new_fname<<" "<<new_address<<" "<<new_pin<<" "<<new_pass<<" "<<new_phone<<" "<<balance<<"\n";
                cout << "Record Deleted  Successfully!!!";
                found++;
            }
            else
            {
                temp_file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        temp_file.close();
        remove("bank.txt");
        rename("temp_bank.txt", "bank.txt");
        if (found == 0)
        {
            cout << "\n\n User ID Can't Found...";
        }
    }
}
void bank::show_all_records()
{
    system("cls");
    fstream file;
    int found = 0;
    cout << "\n\n\t\t Show All User's Records";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n  File Opening Error!!!";
    }
    else
    {
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof())
        {
            cout << "\n User ID       : " << id;
            cout << "\n Name          : " << name;
            cout << "\n Father's Name : " << fname;
            cout << "\n Address       : " << address;
            cout << "\n Phone         : " << phone;
            cout << "\n Balance       : " << balance;
            cout << "\n PIN           : " << pin;
            cout << "\n Password      : " << pass;
            cout << "\n\n ************************************************** \n";
            cout << " ************************************************** \n\n";
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
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
void bank::show_all_payments()
{
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
void bank::user_balance()
{
    system("cls");
    fstream file;
    string test_id, test_pin, test_pass;
    char ch;
    int found = 0;
    cout << "\n\n\t\t\t User Login ";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << " File Opening Error !!!!";
    }
    else
    {
        cout << "\n\n User ID : ";
        cin >> test_id;
        cout << "\n\n PIN Code :";
        for (int i = 1; i <= 5; i++)
        {
            ch = getch();
            test_pin += ch;
            cout << "*";
        }
        cout << "\n\n Password : ";
        for (int i = 1; i <= 5; i++)
        {
            ch = getch();
            test_pass += ch;
            cout << "*";
        }
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof())
        {
            if (test_id == id && test_pin == pin && test_pass == pass)
            {
                cout << " \n\n\t\t Your Current Balance is " << balance;
                found++;
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        if (found == 0)
        {
            cout << "\n\n\t\t User ID, PIN & Password Invalid !!!";
        }
    }
}
void bank::withdraw_atm()
{
    user_balance(); // asks for password and pin.
    withdraw();     // allows user to withdraw the amount from the atm
}
void bank::atm_chek_details()
{
    user_balance(); // login
    search();
}
