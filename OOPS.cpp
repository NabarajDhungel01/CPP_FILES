#include <iostream>
using namespace std;

class FirstClass
{
private:
    int salary;
      void setSalary(int S);
    void getSalary(void);

public:
  

    string name;
    int age;

} ram, shyam ;

void FirstClass::getSalary(void)
{
    cout << "SALAEY OF RAM IS " << ram.salary <<endl;
}

void FirstClass ::setSalary(int ss)
{
    FirstClass hari;
    ram.salary = ss;
}

int main()
{
    ram.name = "RAM";
    ram.age = 12;
    // ram.salary = 1200;

    cout << endl
         << " Name is  " << ram.name << endl;
    cout << endl
         << " Age is   " << ram.age << endl
         << endl;

    ram.setSalary(1200);
    ram.getSalary();



    shyam.name = "SHYAM";
    shyam.age = 14;

    FirstClass hari;

    FirstClass *hariptr; // declaring class ptr;
    hariptr = &hari;     // pointing pointer to the object
    hariptr->name = "HARRY";

    cout << "NAME is:  " << hariptr->name << endl;

    return 0;
}