#include <iostream>
using namespace std;

class base
{
public:
 base() { cout << "this is default constructor"<< endl  ;} // non paramaterized / deafult constructor
 base(int b) { cout << "this is parameterized constructor"<< endl  ;} // paramaterized 
};
class derived: public base {  /*empty*/    };
int main()
{

derived d; // THIS CALLS THE DEFAULT CONSTRUCTOR
// lets modify this 
// derived d(12); // error occurs


}