#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
using namespace std;

int main()
{
    string id, pass, name, fname, address, phone, pin, balance;
    fstream fp1;
    int comma_found = 0;

    fp1.open("ok.csv");
    while (!fp1.eof())
    {
        cout << "\n";

        fp1 >> id;
        int i = 0;

            if (id[i] == ',')
            {
                comma_found++;
            }
            if (comma_found % 8 == 0)
            {
                i++;
                cout << "\n";
            }
                fp1.open("ok.csv",ios::in)


                if_loop_start: ;

                i++;
                if (comma_found % 8 == 0)
                {
                    
                }
                
               cout << id[i];

               

            if (comma_found % 8 == 0)
            {
                i++;
                cout << "\n";
            }
            fp1 >> id;
            
            goto if_loop_start;



            fp1.close();
        // i = i + 1;

        //                                                 cout << "\n";

        // while (name[i] != ',')
        // {
        //     cout << name[i];
        //     i++;
        // }
    }
}