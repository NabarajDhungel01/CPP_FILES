#include <iostream>
#include <string> // to take name
using namespace std;


class mobile
{   private:
    string name;
    int RAM;
    string processor;
    int battery;
    
    public:
    // CREATING THE PARAMETERIZED CONSTRUCTORS
    mobile( string name_a = "Null", int RAM_a=4, string processor_a ="Null", int battery_a=0)
    {
        name = name_a;
        RAM = RAM_a;
        processor = processor_a;
        battery = battery_a;

    }

    // CREATING COPY CONSTRUCTOR
    mobile(mobile &mob   )
    {
        name = mob.name;
        RAM = mob.RAM;
        processor = mob.processor;
        battery = mob.battery;
    }

    void getMobileData();
    

};

// creating the body outside the ckass
void mobile :: getMobileData()
{
cout << endl <<"Name " << name ;
cout << endl <<"RAM " << RAM ;
cout << endl <<"Processor " << processor ;
cout << endl << "Battery " << battery ;
}


int main()
{
mobile doko; 
doko.getMobileData();

cout << "\n\n\n" ;

mobile doko2("Doko123",4, "Snapdragon", 4000);
doko2.getMobileData();

cout << "\n\n\n" ;

mobile doko3(doko2);
doko3.getMobileData();

return 0;
}