#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int find_length(string line); // find length of the entire line including commas
int main()
{
    string csv_id = "\0", csv_name = "\0", csv_fname = "\0", csv_address = "\0", csv_phone = "\0", csv_balance = "\0", csv_pin = "\0", csv_pass = "\0";
    string all;
    fstream fp;
    fp.open("ok.csv", ios::in);
    fp >> all;

    while (!fp.eof())
    {
        int repeat_id = 0, repeat_name = 0, repeat_fname = 0, repeat_address = 0, repeat_phone = 0, repeat_balance = 0, repeat_pin = 0, repeat_pass = 0;
        int comma_found = 0;
        int position = 0;
        for (int i = 0; i < all.length(); i++)
        {
            if (all[i] == ',')
            {
                // cout << all[i]; // prints comma
                i++;
                // cout << ",";
                comma_found++;
                position ++;
                cout << " \t\t Position is :******"<<position<< "***** \t\t\n ";
            }

            switch (position)
            {
            case 0:
                csv_id += all[i];
                cout << "\t\t "<<csv_id<< "\t\t ";
                break;
            case 1:
                csv_name += all[i];
                break;
            case 2:
                csv_fname += all[i];
                break;
            case 3:
                csv_address += all[i];
                break;
            case 4:
                csv_pin += all[i];
                break;
            case 5:
                csv_pass += all[i];
                break;
            case 6:
                csv_phone += all[i];
                break;
            case 7:
                csv_balance += all[i];
                break;
            default:
                cout << "Default Printed";
                break;
            }
            cout <<"\n###"<< all[i]<<"###";


            if (comma_found != 0 && comma_found % 7 == 0 )
            {   
                csv_id = "\0", csv_name = "\0", csv_fname = "\0", csv_address = "\0", csv_phone = "\0", csv_balance = "\0", csv_pin = "\0", csv_pass = "\0";
                cout << "\n";
                cout << "=============================================================================";
            }
            
            if(comma_found == 1 && repeat_id == 0)
            {
                cout << " ID  : "<< csv_id;
                repeat_id = 1;
            }
            
        }
        // cout <<"\n";
        fp >> all;
    }

    return 0;
}
