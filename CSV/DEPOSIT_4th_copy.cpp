#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int find_length(string line); // find length of the entire line including commas
int main()
{
    string csv_id = "\0", csv_name = "\0", csv_fname = "\0", csv_address = "\0", csv_phone = "\0", csv_balance = "\0", csv_pin = "\0", csv_pass = "\0";
    string NEW_csv_id = "\0", NEW_csv_name = "\0", NEW_csv_fname = "\0", NEW_csv_address = "\0", NEW_csv_phone = "\0", NEW_csv_balance = "\0", NEW_csv_pin = "\0", NEW_csv_pass = "\0";
    string all;
    fstream fp,temp_fp;
    fp.open("ok.csv", ios::in);
    fp >> all;

    while (!fp.eof())
    {
        int repeat_id = 0, repeat_name = 0, repeat_fname = 0, repeat_address = 0, repeat_phone = 0, repeat_balance = 0, repeat_pin = 0, repeat_pass = 0;
        int comma_found = 0, comma_found_id = 0, comma_found_name = 0, comma_found_fname = 0, comma_found_address = 0, comma_found_pin = 0, comma_found_pass = 0, comma_found_phone = 0, comma_found_balance = 0;
        int position = 1;
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
                position++;
            }

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
                cout << "Default Printed : Case :: " << position;
                break;
            }
            // cout << "\n###" << all[i] << "###";

            if (comma_found_id == 1 && repeat_id == 0)
            {
                // cout << " ID  : " << csv_id;
                repeat_id = 1;
                // NEW_csv_id = csv_id;
            }
            if (comma_found_name == 1 && repeat_name == 0)
            {
                // cout << " Name : " << csv_name;
                repeat_name = 1;
                // NEW_csv_name = csv_name;
            }
            if (comma_found_fname == 1 && repeat_fname == 0)
            {
                // cout << " F_Name  : " << csv_fname;
                repeat_fname = 1;
                // NEW_csv_fname = csv_fname;
            }
            if (comma_found_address == 1 && repeat_address == 0)
            {
                // cout << " Address  : " << csv_address;
                repeat_address = 1;
                // NEW_csv_address = csv_address;
            }
            if (comma_found_pin == 1 && repeat_pin == 0)
            {
                // cout << " PIN  : " << csv_pin;
                repeat_pin = 1;
                // NEW_csv_pin = csv_pin;
            }
            if (comma_found_pass == 1 && repeat_pass == 0)
            {
                // cout << " Pass : " << csv_pass;
                repeat_pass = 1;
                // NEW_csv_pass = csv_pass;
            }
            if (comma_found_phone == 1 && repeat_phone == 0)
            {
                // cout << " Phone : " << csv_phone;
                repeat_phone = 1;
                // NEW_csv_phone = csv_phone;
            }
            if (comma_found_balance == 1 && repeat_balance == 0)
            {
                // cout << " Balance : " << csv_balance;
                repeat_balance = 1;
                // NEW_csv_balance = csv_balance;
            }
        }

        cout << "\n==========================================================================";

        cout << " \n ID  : " << csv_id;
        cout << " \n Name : " << csv_name;
        cout << " \n F_Name  : " << csv_fname;
        cout << " \n Address  : " << csv_address;
        cout << " \n PIN  : " << csv_pin;
        cout << " \n Pass : " << csv_pass;
        cout << " \n Phone : " << csv_phone;
        cout << " \n Balance : " << csv_balance;

        temp_fp.open("temp_ok.csv", ios::app | ios::out);
        temp_fp << " " << csv_id << "," << csv_name << "," << csv_fname << "," << csv_address << "," << csv_pin << "," << csv_pass << "," << csv_phone << "," << csv_balance << "\n";
        temp_fp.close();

        csv_id = "\0", csv_name = "\0", csv_fname = "\0", csv_address = "\0", csv_phone = "\0", csv_balance = "\0", csv_pin = "\0", csv_pass = "\0";

        comma_found_id = 0, comma_found_name = 0, comma_found_fname = 0, comma_found_address = 0, comma_found_pin = 0, comma_found_pass = 0, comma_found_phone = 0, comma_found_balance = 0,
        cout << "\n";
        cout << "\n=============================================================================";
        cout << "\n";

        fp >> all;
    }
    fp.close();

    return 0;
}
