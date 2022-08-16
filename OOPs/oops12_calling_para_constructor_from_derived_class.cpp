#include <iostream>
using namespace std;

class base
{
public :
base(){ cout << "default of base class " <<endl;}
base(int b_arg) { cout<< " Parameterized of base class" << b_arg << endl ;}
};

class derived:public base
{
public :
derived () : base()    	// this is how we call the constructor of base class
{ cout << "default of derived class "<< endl ;}

derived (int d_arg) : base (d_arg)
 { cout << " parameterized of derived class " << endl ; }
};

int main ()
{
derived d1;
                            cout << "\n\n\n";
derived d2(9); // first the parameterized constructor of base class will be called, then, parameterized constructor of derived class is called.

// OUTPUT 
/*
default of base class 
default of derived class

 Parameterized of base class9
 parameterized of derived class


*/
}
