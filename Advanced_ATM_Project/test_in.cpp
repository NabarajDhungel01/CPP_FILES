#include <iostream>
#include <fstream>
using namespace std;
class CSV
{
public:
    char name[20];
    int age;
};

int main()
{
    CSV ram;
    fstream fptr1;
    fptr1.open("Hello.csv", ios::in);
    fptr1 >> ram.name >> ram.age;
    cout << "Name : " << ram.name;
    cout << "\n\n Age : " << ram.age;
    fptr1.close();

}