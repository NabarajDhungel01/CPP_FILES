#include <iostream>
using namespace std;

class Alpha
{
private:
    int a;
    int b;

public:
    Alpha()     // constructor
    {
        a = 5;
        b = 5;
    }                
    static int stat; // static member variable

    static int getStat()
    {
        stat++;
        return stat;
    } // static member function
};
int Alpha::stat=0;

int main()
{
    Alpha a1;
    cout << endl <<" Value using object       : " << a1.getStat()     << endl;
    cout << endl <<" Value using class name   : " << Alpha::getStat() << endl;

    return 0;
}