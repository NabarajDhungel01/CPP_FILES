#include <iostream>
using namespace std;


class base{
public:
~base(){cout << " Base class destroyed";}};
	
class derived:public base{
public:
~derived(){cout << " derived class destroyed";}};

int main(){
base *b = new derived; // pointer of base class and obj of der class
delete b1;	// deleting the b1 object	// only base will be destroyed
// we are only deleting half of the object

}
