#include <iostream>
using namespace std;


class base{
        public:
        virtual ~base(){cout << " Base class destroyed"<<endl;}};
            
        class derived:public base{
        public:
        ~derived(){cout << " derived class destroyed"<<endl;}};

        int main(){
        base *b = new derived; // pointer of base class and obj of der class
        delete b;	// deleting the b pointer	// only base will be destroyed
        // we are only deleting half of the object

// so to compeletely destroy the object we need to make the base virtual lets add the virtual keyword infront of the base destructor

// first the derived class destructor is called then the base class destructor is calld 

a
}
