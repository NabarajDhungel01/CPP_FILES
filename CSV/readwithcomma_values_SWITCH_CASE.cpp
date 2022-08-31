#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int find_length(string line); // find length of the entire line including commas
int main()
{
    string csv_id, csv_name, csv_fname, csv_address, csv_phone, csv_balance, csv_pin, csv_pass;
    string all;
    fstream fp;
    fp.open("ok.csv", ios::in);
    fp >> all;
    while (!fp.eof())
    {
        int comma_found = 0;
        int position = 0;
        for (int i = 0; i < all.length(); i++)
        {
            if (all[i] == ',')
            {
                i++;
                // cout << ",";
                comma_found++;
                position++;
            }
            // cout << all[i];

            switch (position)
            {
            case 0:
                csv_id += all[i];
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

            if (comma_found != 0 && comma_found % 7 == 0 && comma_found % 6 != 0)
            {
                // cout << "\n";
            }

                cout <<"\n User ID       : "<<csv_id       ;
                cout <<"\n Name          : "<<csv_name     ;
                cout <<"\n Father's Name : "<<csv_fname    ;
                cout <<"\n Address       : "<<csv_address  ;
                cout <<"\n Phone         : "<<csv_phone    ;
                cout <<"\n Balance       : "<<csv_balance  ;
                cout <<"\n PIN           : "<<csv_pin      ;
                cout <<"\n Password      : "<<csv_pass     ;

                cout << "----------------------------------";
                }
        fp >> all;
    }

    return 0;
}
