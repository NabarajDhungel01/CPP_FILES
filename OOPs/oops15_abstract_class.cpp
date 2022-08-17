#include <iostream>
using namespace std;

class parent{       //Abstract class
public:
                    // virtual void give(){cout << "bun" ;} // virtual function
virtual void give()=0; // PURE VIRTUAL FUNCTION
};

class boy: public parent {
public:
void give(){ cout <<" brown bun";}};

class girl: public parent{
public:
void give(){cout <<"pink bun";}};


int main(){

parent *ptr;
ptr = new boy();
ptr->give();

ptr = new girl();
ptr->give();
}
