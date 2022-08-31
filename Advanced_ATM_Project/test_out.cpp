#include <iostream>
#include <fstream>
using namespace std;

int main()
{

    fstream fptr1;
    fptr1.open("Hello.csv", ios::out);

    fptr1 << "\"Hello\""
          << ","
          << "\"Hi\"";

    fptr1.close();

    return 0;
}