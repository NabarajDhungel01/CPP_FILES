#include <iostream>
using namespace std;
int convert_to_int(string z);
int main()
{
string a = "1";
string b = "2";
string c;
c = a + b ;
cout << "C is  : "<< c; while (cin.fail()) { cin.clear();   cin.ignore();  }

return 0;
}

int convert_to_int(string z)
{
    string str;
    str = to_string(z);
    return str;
}