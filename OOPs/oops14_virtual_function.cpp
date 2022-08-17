#include <iostream>
using namespace std;


class base
{ public:
 virtual void show(){ cout << "base"; }
};

class Derv1:public base
{public:
void show(){ cout << "Derived1";}
};


class Derv2:public base
{public:
void show(){std::cout << "Derived2";}
};

int main() {
base *ptr;
ptr = new Derv1(); // creating new object of derived class
ptr->show();        // output base
cout << "\n\n";


// even if we are calling the show function of drv1 ,it is showing base's show function

ptr = new Derv2();
ptr->show();        // output base

// after adding virtual infront of show function in base class, it can now access the drv1 & drv2 show function 

}
