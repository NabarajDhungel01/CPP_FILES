#include <iostream>
using namespace std;

class base
{
public:
void Msg() {cout <<  " IT IS  A BASE CLASS \n";};

};

class derived : public base
{
public:
void Msg() 
{
     cout << " IT IS  A DERIVED CLASS \n";
     base::Msg();// calls base class MSG FUNCTION
}


};

int  main()
{

derived d1;
d1.Msg(); //  output IT IS  A DERIVED CLASS 

                // d1.base::Msg();  // output IT IS  A BASE CLASS 
}