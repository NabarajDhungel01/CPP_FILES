#include <iostream>
using namespace std;

class base
{
public:
 base() { cout << "this is default constructor of BASE"<< endl  ;} 
 base(int b) { cout << "this is parameterized constructor of BASE"<< endl  ;}
};
class derived: public base 
  {  
    public:
    derived(){ cout << "this is default constructor of DERIVED"<< endl  ;}
    derived(int b) { cout << "this is parameterized constructor of DERIVED"<< endl  ;} 

   };
int main()
{

derived d;
// ↑↑↑ this will print base default constructor then derived default constructor


derived d2(9);

// ↑↑↑ this will print base default constructor then derived parameterized constructor

/* OUTPUT:

this is default constructor of BASE
this is default constructor of DERIVED

this is default constructor of BASE
this is parameterized constructor of DERIVED


*/
}