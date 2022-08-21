#include <iostream>
using namespace std;

class Alpha
{

private:
int a;
int b;
public:
Alpha(int a_a =0, int b_b =0)
{
    // a= a_a;
    a = 5;
    // b_b = b;
    b = 5;
    stat++; // post increment operation
}

static int stat;

};

int Alpha::stat = 0;

int main()
{
Alpha a1;
Alpha a2;
Alpha a3;   // adding after running for first time
// now the output will be three
// everytime we are creating object , the constructor of this class is called and incrementing the value of this static variable.

cout << " Value using a1 obj is  : "<< a1.stat   << endl;
cout << " Value using a2 obj is  : "<< a2.stat   << endl;

cout << " Value using Alpha class is  : "<< Alpha::stat    << endl;


return 0;
}