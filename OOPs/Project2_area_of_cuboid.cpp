#include <iostream>
using namespace std;
class rectangle
{
    public:
    int length;
    int breadth;

    void show() // base class
    {  cout << length<< endl;
       cout << breadth<< endl;   }
    
    void area_rectangle()
    {
        cout << "Area of rectangle "<< length * breadth << endl;
    }
    
};

// CREATING THE DERIVED CLASS 
class cuboid:public rectangle // publicly inheriting the rectangle class
{
public :
int height;
void display()
{ cout << height << endl;}

void area_cuboid()
{    cout << " Area of cuboid : " << 2*((length*breadth)+(breadth* height) + (length * height)); }
};
int main()
{
    rectangle r;
    r.length= 10;
    r.breadth = 20;
    r.area_rectangle();
    // INHERITED CLASS 

    cuboid c;
    c.length = 10;
    c.breadth = 20;
    c.height = 30;
    c.area_cuboid();
}