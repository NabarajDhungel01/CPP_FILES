#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int find_length(string line); // find length of the entire line including commas
int main()
{
    string all;
    fstream fp;
    fp.open("ok.csv", ios::in);
    fp >> all;
    while (!fp.eof())
    {
        int comma_found = 0;
        for (int i = 0; i < all.length(); i++)
        {
            if (all[i] == ',')
            {
                i++;
                cout << ",";
                comma_found++;
            }
            cout << all[i];

            if (comma_found != 0 && comma_found % 7 == 0 && comma_found % 6 != 0 )
            {
                cout << "\n";
            }
        }
        fp >> all;
    }

    return 0;
}
