#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
using namespace std;

int main()
{
    string id,pass,name,fname,address,phone,pin,balance;
    fstream fp1;
    string a; //= "20";
    string b; //= "10";

    cin >> a;
    cin >> b;

    int c = stoi(a);
    int d = stoi(b);

    cout << "\n \n \t\t Addition : " << c + d;
    cout << "\n \n \t\t Subtraction : " << c - d;
    cout << "\n \n \t\t Multplication : " << c * d;
    cout << "\n \n \t\t Divide : " << c / d;

    cout << "\n\n";

    if (stoi(a) == stoi(b))
    {
        cout << " stoi(a) = stoi(b)";
    }
    else if (stoi(a) > stoi(b))
        cout << " stoi(a) > stoi(b)";
    else
        cout << " stoi(a) < stoi(b) ";



    fp1.open("ok.csv");
    while (!fp1.eof())
    {
        fp1>>id;
        int i =0;
    while (id[i] != ',')
    {
        cout << id[i];
        i++;
    }
    i = i + 1;
        fp1>>name;
    cout << "\n";
    while (name[i] != ',')
    {
        cout <<name[i];
        i++;
    }


    }
    

    // if (c == d )
    // {
    //     cout << " c = d";
    // }
    // else if ( c>d)
    //     cout << " c > d";
    // else
    //     cout << " c < d ";

    // if( ((stoi("10") ==  stoi("2")))  )
    //         cout << " They are equal";
    // else if ( (to_string(stoi("1"))) > (to_string( stoi("2"))    ) )
    //         cout << " A is greater";
    // else
    //     cout << " A is smaller";
}